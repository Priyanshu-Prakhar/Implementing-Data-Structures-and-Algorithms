#include <stdio.h>
#include <string.h>
#include <array.c>

int main(){
    Array stack;
    initArr(&stack, 4, sizeof(int));
    
    int a=1, b=2, c=3, d=4;

    append(&stack, &a); append(&stack, &b);append(&stack, &c);append(&stack, &d);

    int x = *(int*)elmAtIndex(&stack, 3);
    printf("%d", x);

    return 0;
}