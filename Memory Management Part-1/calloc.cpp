#include <stdio.h>
#include <stdlib.h>
int main(){
    int *p = (int*)calloc(1, sizeof(int));
    if(p == NULL){
        printf("Fail to allocate memory\n");
        return -1;
    }
    *p = 5;
    printf("%d", *p);
    free(p);
    p = NULL;
    free(p);
}
