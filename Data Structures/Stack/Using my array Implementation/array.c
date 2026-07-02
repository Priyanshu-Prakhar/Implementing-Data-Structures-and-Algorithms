#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef  struct{
    void *data;
    size_t elm_size; //To tell what type the elements are.
    int size; // Current number of elements
    int capacity; // Max number of elements
} Array;

void initArr(Array *arr, int capacity, size_t elm_size){
    arr->data = malloc(elm_size*capacity); // Multiply by capacity, not pointer.
    arr->size=0; // Initially zero elements
    arr->capacity = capacity;
    arr->elm_size = elm_size;
}

void append(Array *arr, void *value){
    memcpy((char*)arr->data + (arr->size * arr->elm_size), value, arr->elm_size); //copying data from value to data in struct.
    arr->size++;
}
//Initially, the append method wasn't working. I passsed the variables to value, but it needs to be a pointer, so I switched x with &x to pass to value.
//A void pointer can point to anything. 

void* elmAtIndex(Array *arr, int index){
    return (char*)arr->data + index * arr->elm_size;
} // This returns the adress of the element. It is a void pointer so we need to typecast it later.
