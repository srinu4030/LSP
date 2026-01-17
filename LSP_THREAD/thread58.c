//Implement a multithreaded file copy program in C. Create multiple threads to read from one file and write to another file concurrently?


#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define CHUNK 1024

typedef struct {
    FILE *src;
    FILE *dest;
    long offset;
    size_t size;
} ThreadData;

void *copyChunk(void *arg)
{
    ThreadData *data = (ThreadData *)arg;
    fseek(data->src, data->offset, SEEK_SET);
    fseek(data->dest, data->offset, SEEK_SET);

    char buffer[CHUNK];
    size_t toRead = data->size;
    while (toRead > 0)
    {
        size_t n = (toRead > CHUNK) ? CHUNK : toRead;
        fread(buffer, 1, n, data->src);
        fwrite(buffer, 1, n, data->dest);
        toRead -= n;
    }

    return NULL;
}

int main()
{
    FILE *src = fopen("source.txt", "rb");
    FILE *dest = fopen("dest.txt", "wb");
    if (!src || !dest)
    {
        printf("File open error\n");
        return 1;
    }

    fseek(src, 0, SEEK_END);
    long filesize = ftell(src);
    fseek(src, 0, SEEK_SET);

    int numThreads = 2;
    pthread_t threads[numThreads];
    ThreadData data[numThreads];

    long chunkSize = filesize / numThreads;

    for (int i = 0; i < numThreads; i++)
    {
        data[i].src = src;
        data[i].dest = dest;
        data[i].offset = i * chunkSize;
        data[i].size = (i == numThreads - 1) ? filesize - i * chunkSize : chunkSize;
        pthread_create(&threads[i], NULL, copyChunk, &data[i]);
    }

    for (int i = 0; i < numThreads; i++)
        pthread_join(threads[i], NULL);

    fclose(src);
    fclose(dest);

    printf("File copied successfully.\n");
    return 0;
}

