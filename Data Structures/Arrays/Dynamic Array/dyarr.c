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

    //Trying to double the capacity when limit reached.
    if(arr->size == arr->capacity){
        Array *new_arr;
        initArr(&new_arr, (arr->capacity)*2, sizeof(arr->elm_size));
        for(int i = 0; i<(arr->capacity); i++){
            memcpy((char*)new_arr->data + (new_arr->size * new_arr->elm_size), value, arr->elm_size);
        }
    }
}
//Initially, the append method wasn't working. I passsed the variables to value, but it needs to be a pointer, so I switched x with &x to pass to value.
//A void pointer can point to anything. 

void* elmAtIndex(Array *arr, int index){
    return (char*)arr->data + index * arr->elm_size;
} // This returns the adress of the element. It is a void pointer so we need to typecast it later.

//int mergedArray(Array *arr1, Array *arr2){
//    Array *result;
//    for(int a=0; a<(arr1->capacity); a++){
//        append(result, arr1->data[a]);
//   }
//
//    for(int a=(arr1->capacity); a<(arr2->capacity); a++){
//        append(result, arr2->data[a]);
//    }
//    return result;
//}

int main(){
    Array arr1;
    initArr(&arr1, 4, sizeof(char));

    char x = 'f', y='i', z='s', w='h';
    append(&arr1, &x); append(&arr1, &y); append(&arr1, &z); append(&arr1, &w);
    printf("%c %c %c %c", *(char*)elmAtIndex(&arr1, 0), *(char*)elmAtIndex(&arr1, 1), *(char*)elmAtIndex(&arr1, 2), *(char*)elmAtIndex(&arr1, 3)); // Typecasting to char* pointer

    //Array *array1, *array2;
    //initArr(array1, 1, sizeof(char));
    //char m = "a";
    //append(array1, &m);
    //printf("%c", elmAtIndex(array1, 0));
    return 0;
}