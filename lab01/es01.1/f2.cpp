#include "functions.h"


void order_vector(float *vett, int n){
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(vett[i] > vett[j]){
                float temp = vett[i];
                vett[i] = vett[j];
                vett[j] = temp;
            }
        }
    }
}