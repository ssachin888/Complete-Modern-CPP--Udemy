#include <stdio.h>
#include <stdlib.h>
int main(){
    int *p = malloc(sizeof(int));
    *p = 5;
    printf("%d", *p);
    free(p); // p is a dangling pointer after this
    p = NULL;
    free(p);
}
