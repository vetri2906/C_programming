#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

#define SAMPLE_RATE 44100   // Sample rate (Hz)
#define DURATION    5       // Duration of the tone (seconds)
#define AMPLITUDE   32767   // Amplitude of the tone (maximum 32767 for 16-bit PCM)

typedef struct {
    char   chunkID[4];       // "RIFF" for little-endian
    uint32_t chunkSize;      // Total file size - 8 bytes
    char   format[4];        // "WAVE"
    char   subChunk1ID[4];   // "fmt "
    uint32_t subChunk1Size;  // Size of the fmt sub-chunk (16 for PCM)
    uint16_t audioFormat;    // PCM = 1
    uint16_t numChannels;    // Number of channels (e.g., 1 for mono, 2 for stereo)
    uint32_t sampleRate;     // Sample rate (e.g., 44100)
    uint32_t byteRate;       // Sample rate * numChannels * bitsPerSample / 8
    uint16_t blockAlign;     // numChannels * bitsPerSample / 8
    uint16_t bitsPerSample;  // Bits per sample (e.g., 16)
    char   subChunk2ID[4];   // "data"
    uint32_t subChunk2Size;  // Size of the audio data (fileSize - 44 bytes)
} PCMHeader;

int main() {
    uint32_t numSamples = SAMPLE_RATE * DURATION;

    // Frequency of the sine wave (440 Hz in this case)
    double increment = 2.0 * M_PI * 440.0 / SAMPLE_RATE;
    double phase = 0.0;

    PCMHeader header;

    memcpy(header.chunkID, "RIFF", 4);
    memcpy(header.format, "WAVE", 4);
    memcpy(header.subChunk1ID, "fmt ", 4);

    header.subChunk1Size = 16; // PCM format size
    header.audioFormat = 1;    // PCM = 1
    header.numChannels = 1;    // Mono audio
    header.sampleRate = SAMPLE_RATE;
    header.bitsPerSample = 16;
    header.byteRate = header.sampleRate * header.numChannels * header.bitsPerSample / 8;
    header.blockAlign = header.numChannels * header.bitsPerSample / 8;
    memcpy(header.subChunk2ID, "data", 4);
    header.subChunk2Size = numSamples * header.numChannels * header.bitsPerSample / 8;
    header.chunkSize = 36 + header.subChunk2Size;

    FILE* file = fopen("sine_wave.pcm", "wb");
    if (!file) {
        printf("Failed to create file.");
        return 1;
    }

    // Write the header to the file
    fwrite(&header, sizeof(PCMHeader), 1, file);

    // Generate and write PCM samples
    for (uint32_t i = 0; i < numSamples; ++i) {
        int16_t sample = (int16_t)(AMPLITUDE * sin(phase));
        phase += increment;
        fwrite(&sample, sizeof(int16_t), 1

, file);
    }

    fclose(file);

    printf("PCM file created successfully.\n");

    return 0;
}
