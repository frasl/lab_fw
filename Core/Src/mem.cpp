#include "mem.h"
#include "errors.h"

#define HEAP_SIZE   2048

static unsigned char   Heap[HEAP_SIZE];
static size_t          UsedHeap = 0;

void* operator new(size_t count)
{
    assert(HEAP_SIZE - UsedHeap > count, "Out of memory");

    void *block = Heap + UsedHeap;
    UsedHeap += count;

    return block; 
}

void* operator new[](size_t count)
{
    assert(HEAP_SIZE - UsedHeap > count, "Out of memory");

    void *block = Heap + UsedHeap;
    UsedHeap += count;

    return block; 
}

void operator delete(void* ptr)
{
    assert(0, "There's no turning back!");
}

void operator delete[](void* ptr)
{
    assert(0, "There's no turning back!");
}