#include <iostream>
#include <vector>

using namespace std;

bool idadeRep(vector<int> idades){
    int tam = idades.size();
    int menor = 200;
    int pos = 0;
    
    for(int i = 0; i < tam; i++){
        if (idades[i] < menor){
            menor = idades[i];
            pos = i;
        }
    }

    for(int i = 0; i < tam; i++){
        if (idades[i] == menor && i != pos){
            return true;
        }
    }
        return false;
}

int main(){

    return 0;
}