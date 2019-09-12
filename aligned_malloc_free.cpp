/*
 *-------------------------
 *  aligned_malloc and free
 *  Sept 11th, 2019
 *-------------------------
 */

 #include <iostream>

 using namespace std;

 void *malloc_aligned(size_t size, size_t alignment)
 {
     void *ptr = NULL, **res_ptr = NULL;

     size_t offset = alignment - 1 + sizeof(void *);

     ptr = malloc(offset + size);

     if (ptr == NULL) return NULL;

     res_ptr = (void**)(((size_t)ptr + offset ) & ~(alignment - 1));

     res_ptr[-1] = ptr;

     return res_ptr;
 }

 void free_aligned (void * ptr)
 {
     if (ptr == NULL) return;
     void *res_ptr  = ((void **)ptr)[-1];
     free(res_ptr);
 }

 int main (void) 
 {

     void *ptr = NULL;
     ptr = malloc_aligned(1000, 256);
     printf("Pointer: %p \n", ptr);
     free_aligned(ptr);
     return 0;

 }
