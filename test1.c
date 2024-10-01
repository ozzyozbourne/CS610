#include <stdlib.h>

void try_seq(int);
void try_par(int);
void print(void);

int seq[101];
int par[101];


 int main(void){
    int i; 
    for(i = 0; i < 101; i++) try_seq(i);
    
    forall i = 0 to 100 grouping 100 do  
        try_par(i);

    print();
    return 0;
}

void try_seq(const int val){
    seq[val] = val * val;    
}

void try_par(const int val){
    par[val] = val * val;    
}

void print(){

    int i; 
    for(i = 0; i < 101; i++)     
        cout << seq[i] << " ";

    cout << "\n";
    
    for(i = 0; i < 101; i++) 
    cout << par[i] << " ";

}

