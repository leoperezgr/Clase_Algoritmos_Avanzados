#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> monedas(N);
    for(int i = 0; i < N; i++){
        cin >> monedas[i];
    }

    int P, Q;
    cin >> P >> Q;

    if(Q == P){
        cout << "No hay cambio por dar\n";
        return 0;
    }

    if(Q < P){
        cout << "Falta dinero para pagar ese producto\n";
        return 0;
    }

    int cambio = Q - P;

    sort(monedas.begin(), monedas.end(), greater<int>());

    for(int m : monedas){
        int cnt = cambio / m;
        cout << cnt << " moneda(s) de " << m << "\n";
        cambio %= m;
    }

    return 0;
}