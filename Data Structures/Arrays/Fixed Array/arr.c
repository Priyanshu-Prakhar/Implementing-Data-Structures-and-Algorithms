#include<stdio.h>
#include<stdlib.h>
typedef  struct{
    int *data;
    int size; // Current number of elements
    int capacity; // Max number of elements
} Array;

void initArr(Array *arr, int capacity){
    arr->data = malloc(sizeof(int)*capacity); // Multiply by capacity, not pointer.
    arr->size=0; // Initially zero elements
    arr->capacity = capacity; 
}

void append(Array *arr, int value){
    arr->data[arr->size] = value; //Gives the last index (arr->size) a value
    arr->size++;
}

int getArrayIndex(Array *arr, int index){
    return arr->data[index];
}

int main(){
    Array *arr1;
    initArr(arr1, 3);
    append(arr1, 0); append(arr1, 1); append(arr1, 2);
    printf("%d %d %d", getArrayIndex(arr1, 0), getArrayIndex(arr1, 1), getArrayIndex(arr1, 2));
    return 0;
}