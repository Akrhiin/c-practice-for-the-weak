// file: memory_allocator/main.c
// author: Michael Pace
// created: 07.17.2025
// updated: 07.17.2025

// This code is based off an excellent blog post [https://arjunsreedharan.org/post/148675821737/memory-allocators-101-write-a-simple-memory]. I considered following their example and using sbrk, but decided on mmap for the sake of modernity.

#include <sys/mman.h>
#include <pthread.h>

#include <stdio.h>

// ----------------------------------------------

// +--------+------------+      +--------+------------+
// | header | mem block  | =*=> | header | mem block  |
// +--------+------------+      +--------+------------+

typedef char ALIGN[16]; // Define "ALIGN" as buffer w/ length 16 bytes.
union header {
    struct header_t
    {
        size_t size;
        unsigned is_free;
        struct header_t *next;
    } s;
    ALIGN stub; // Make sure header ends up on memory address aligned to 16 bytes.
                 // ^^ (union sets size based on largest child)
};
typedef union header header_t; // Define block header from union definition.

header_t *head, *tail; // Create head and tail pointer for list of blocks.

pthread_mutex_t global_malloc_lock; // Global lock must be acquired before any action on memory.
                                    //  | On item action => acquire lock
                                    //  | On action completion => release lock

// ----------------------------------------------

// MALLOC
void *malloc(size_t size)
{
    void *block = mmap(NULL,size,PROT_READ|PROT_WRITE,MAP_ANONYMOUS|MAP_PRIVATE,-1,0);
      // ^^^^ anonymous mapping, so file descriptor set to -1 and offset to 0
    return block; // if creation of memory block failed, will return NULL pointer
}

// CALLOC
// REALLOC
// FREE

int main()
{
    printf("test\n");
}
