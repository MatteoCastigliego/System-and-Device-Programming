#include <iostream>
using namespace std;

float *define_vector(int n);
void order_vector(float *vett, int n);
void print_vector(float *vett, int n);

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

void print_vector(float *vett, int n){
    for(int i = 0; i < n; i++){
        cout<<vett[i]<<" ";
    }
}
