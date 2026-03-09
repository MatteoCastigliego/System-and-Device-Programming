#include "functions.h"


float *define_vector(int n){
    float *vet = (float*)malloc(n*sizeof(float));
    if (vet == NULL){
        cout<<"Errore nell'allocazione dle vettore!";
        return nullptr;
    }
    
    for(int i = 0; i < n; i++){
        cout<<"Inserire valore "<<i<<": ";
        cin>>vet[i];
    }

    return vet;
}