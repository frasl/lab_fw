#ifndef _MEM_H_
#define _MEM_H_

#include "types.h"

void* operator new(size_t count);
void* operator new[](size_t count);

void operator delete(void* ptr);
void operator delete[](void* ptr);

#endif