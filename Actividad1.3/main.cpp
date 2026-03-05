#include <bits/stdc++.h>
using namespace std;

void resolverCambioDP(const vector<int>& denominador, int P, int Q) {
    if (Q == P) 
    {
        cout << "No hay cambio por dar\n";
        return;
    }

    if (Q < P) 
    {
        cout << "Falta dinero para pagar ese producto\n";
        return;
    }

    int cambio = Q - P;
    const int infinito = 1e9;
    vector<int> dp(cambio + 1, infinito);
    vector<int> parent(cambio + 1, -1);
    dp[0] = 0;

    for (int x = 1; x <= cambio; x++) 
    {
        for (int c : denominador) {
            if (c > x) {
                continue;
            }

            int previo = x - c;

            if (dp[previo] == infinito) {
                continue;
            }

            int monedasUsadas = dp[previo] + 1;

            if (monedasUsadas < dp[x]) {
                dp[x] = monedasUsadas;
                parent[x] = c;
            }
        }
    }


    if (dp[cambio] == infinito) {
        cout << "No es posible dar cambio exacto con las denominaciones dadas\n";
        return;
    }

    unordered_map<int, int> used;
    int cur = cambio;
    while (cur > 0) {
        int c = parent[cur];
        if (c == -1) {
            break;
        }
        used[c]++;
        cur -= c;
    }

    vector<int> desc = denominador;
    sort(desc.begin(), desc.end(), greater<int>());

    for (int d : desc) {
        int cnt = used.count(d) ? used[d] : 0;
        cout << cnt << " moneda(s) de " << d << "\n";
    }
}

int main() {
    int N;
    cin >> N;

    vector<int> denominador(N);
    for (int i = 0; i < N; i++) {
        cin >> denominador[i];
    }

    int P, Q;
    cin >> P >> Q;

    resolverCambioDP(denominador, P, Q);
    return 0;
}
