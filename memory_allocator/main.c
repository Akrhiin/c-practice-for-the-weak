// file: memory_allocator/main.c
// author: Michael Pace
// created: 07.17.2025
// updated: 07.17.2025

// Using sbrk because requirements aren't too steep, and implementation is simple.
//
// sbrk(0) => gives current address of program break
// sbrk(x) =(+)=> increments brk by x bytes (allocate memory)
// sbrk(-x) =(-)=> decrements brk by x bytes (release memory)

// MALLOC
void *malloc(size_t size)
{

}
