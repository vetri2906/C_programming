#include <stdio.h>

#define INSERTED 1

typedef struct 
{
    int number;
    int status;
} num_t;

// uint8_t hash(int nums, int numsSize) {
//     long ret = 0;
//     ret = ((long)nums * 234567);
//     ret %= numsSize;
//     return (uint8_t)ret;
// }

int hash(int nums, long long tableSize) {
    long ret = (long)nums * 31; // Lighter multiplier to avoid heavy clustering
    ret %= tableSize;
    if (ret < 0) {
        ret += tableSize;
    }
    return (int)ret;
}

int hash_insert(num_t * a, int *nums, long long numsSize)
{
    int hash_val = 0;
    long long try = 0;
    int i = 0;
    hash_val = hash(*nums, numsSize);
    for (; i < numsSize; i++)
    {
        try = (hash_val + i) % numsSize;
        if((a[try].number == 0) && (a[try].status != INSERTED))
        {
            a[try].number = *nums;
            a[try].status = INSERTED;
            return 0;
        }
        else if ((a[try].number == *nums) && (a[try].status == INSERTED))
        {
            printf("false because %d  %d", a[try].number, *nums);
            return 1;
        }
        else
        {
        }
    }
    printf("false because current %d  num %d status %d i value %d\n", a[try].number, *nums, a[try].status, i );
    return 0;
}

bool containsDuplicate(int* nums, int numsSize) {
    bool ret = false;
    long long tableSize = (long long)numsSize * 2;
    num_t *a = calloc(tableSize, sizeof(num_t)); // Use calloc to initialize hash table to 0
    for (int i = 0; i < numsSize; i++)
    {
        if(1 == hash_insert(&a[0], &nums[i], tableSize))
        {
            ret = true; 
            break;
        }
    }
    return ret; 

    // for (int i = 0; i<numsSize-1; i++)
    // {
    //     for (int j = i+1; j < numsSize; j++)
    //     {
    //         if(nums[i] == nums[j])
    //         {
    //             ret = true;
    //             break;
    //         }
    //     }
    // }
    // return ret;
}
