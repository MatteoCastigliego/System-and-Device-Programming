#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main (){
    int h, n;

    printf("Inserire h: ");
    scanf("%d", &h);
    printf("Inserire n: ");
    scanf("%d", &n);

    for(int i = 0; i < h; i++){
        for(int j = 0; j < n; j++){
            fork();
        }
    }

}

