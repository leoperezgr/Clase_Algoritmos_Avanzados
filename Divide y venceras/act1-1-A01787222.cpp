#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int busquedaBinariaRecursiva(const vector<int>& arr, int l, int r, int x)
{
    if(l > r)
    {
        return -1;
    }
    
    int medio = l + (r - l) /2 ;
    if (arr[medio] == x) {
        return medio;
    }
    else if (x < arr[medio]) {
        return busquedaBinariaRecursiva(arr, l, medio - 1, x);
    }
    else {
        return busquedaBinariaRecursiva(arr, medio + 1, r, x);
    }
}

int main()
{
    //caso 1
    vector<int> caso1 = {8, 3, 10, -1, 6, 14, 4};
    sort(caso1.begin(), caso1.end());
    int x;
    cout << "Ingresa el valor a buscar en caso 1: ";;
    cin>>x;
    int resultado1 = busquedaBinariaRecursiva(caso1, 0, caso1.size() - 1, x);
    cout << "Caso 1 resultado: " << resultado1 << endl;

    //caso 2
    vector<int> caso2 = {2, 4, 6, 8, 10};
    sort(caso2.begin(), caso2.end());
    cout << "Ingresa el valor a buscar en caso 2: ";
    cin >> x;
    int resultado2 = busquedaBinariaRecursiva(caso2, 0, caso2.size() - 1, x);
    cout << "Caso 2 resultado: " << resultado2 << endl;

    //caso 3
    vector<int> caso3 = {42};
    sort(caso3.begin(), caso3.end());
    cout << "Ingresa el valor a buscar en caso 3: ";
    cin >> x;
    int resultado3 = busquedaBinariaRecursiva(caso3, 0, caso3.size() - 1, x);
    cout << "Caso 3 resultado: " << resultado3 << endl;


    //caso 4
    vector<int> caso4 = {5, 3, 7, 3, 9, 3, 1};
    sort(caso4.begin(), caso4.end());
    cout << "Ingresa el valor a buscar en caso 4: ";
    cin >> x;
    int resultado4 = busquedaBinariaRecursiva(caso4, 0, caso4.size() - 1, x);
    cout << "Caso 4 resultado: " << resultado4 << endl;



    return 0;
}
