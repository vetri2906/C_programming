
typedef struct
{
    int number;
    int status;
    int count;
} num_t;

int hash(int* nums, int numsSize)
{
    int hash = 0;
    hash = (int)((long long)*nums *31);
    hash %= numsSize;
    if(hash<0)
    {
        hash += numsSize;
    }
    return hash;
}

int hash_insert(num_t *a, int* nums, long long numsSize)
{
    int hash_val = hash(nums, numsSize);
    long long try = 0;
    int ret = 1;
    for (long long i = 0; i< numsSize; i++)
    {
        try = (hash_val+i) % numsSize;
        if(((a[try].number == 0) && (a[try].count == 0))
        || ((a[try].number == *nums) && (a[try].count > 0)))
        {
            a[try].number = *nums;
            a[try].count++;
            break;
        }
    }
    if(a[try].count > (numsSize/4))
    {
        ret = 0;
    }
    return ret;
}

int majorityElement(int* nums, int numsSize) {

    long long table_size = 2*numsSize;
    int ret = 0;
    num_t *a = calloc(table_size, sizeof(num_t));
    for (int i = 0; i< numsSize; i++)
    {
        if(0 == hash_insert(a, &nums[i], table_size))
        {
            ret = nums[i];
            break;
        }  
    }
    return ret;
}