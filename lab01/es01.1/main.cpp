#include "functions.h"

int main(){
    int n;
    float *vet = nullptr;

    cout<<"Inserire il numero di elementi dell'array: ";
    cin>>n;

    vet = define_vector(n);
    cout<<"Vettore non ordinato:"<<endl;
    print_vector(vet, n);
    cout<<endl;

    cout<<"Vettore ordinato:"<<endl;
    order_vector(vet, n);
    print_vector(vet, n);
    return 0;

}
