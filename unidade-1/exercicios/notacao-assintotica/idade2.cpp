#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool idadeRep2(vector<int> idades){
    sort(idades.begin(), idades.end());
    return idades[0] == idades[1];
}

int main(){
    return 0;
}