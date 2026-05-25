#include<stdio.h>
#include<stdlib.h>
typedef  struct{
    int *data;
    int size;
    int capacity;
} Array;

void initArr(Array *arr, int capacity){
    arr->data = malloc(sizeof(int) *capacity);
    arr->size=0;
    arr->capacity = capacity;
}

void append(Array *arr, int value){
    arr->data[arr->size] = value; //Gives the last index arr->size a value
    arr->size++;
}

int getArrayElm(Array *arr, int index){
    return arr->data[index];
}

int main(){
    Array *arr1;
    initArr(arr1, 3);
    append(arr1, 0); append(arr1, 1); append(arr1, 2);
    printf("%d %d %d", getArrayElm(arr1, 0), getArrayElm(arr1, 1), getArrayElm(arr1, 2));
    return 0;
}