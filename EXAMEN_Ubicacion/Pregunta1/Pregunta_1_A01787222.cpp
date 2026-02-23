//Jesús Leonardo Pérez Guerrero A01787222
//Dada una matriz m x n, devuelve todos los elementos de la matriz en orden espiral.

#include <iostream>
#include <vector>
using namespace std;

vector<int> espiral(vector<vector<int>> matrix)
{
    vector<int> res;
    int arriba = 0;
    int abajo = matrix.size() - 1;
    int izq = 0;
    int der = matrix[0].size()-1;
    int i = 0;

    while(arriba <= abajo && izq <= der)
    {
        for(i = izq; i <= der; i++)
        {
            res.push_back(matrix[arriba][i]);
        }
        arriba++;
        for(i = arriba; i <= abajo; i++  )
        {
            res.push_back(matrix[i][der]);
        }
        der--;
        if(arriba <= abajo)
        {
            for(i = der; i >= izq; i--)
            {
                res.push_back(matrix[abajo][i]);
            }
            abajo--;
        }
        if(izq<= der)
        {
            for(i = abajo; i>= arriba;i--)
            {
                res.push_back(matrix[i][izq]);
            }
            izq++;
        }
    }
    return res;
}

int main()
{
    //Ejemplo1
    vector<vector<int>> ej1 = 
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}  
    };
    vector<int> resultado1 = espiral(ej1);
    cout<<"Ejemplo 1: ";
    for(int x : resultado1)
    {
        cout << x<<" ";
    }
    
    vector<vector<int>> ej2 =
    {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    vector<int> resultado2 = espiral(ej2);
    cout<<"\nEjemplo 2: ";
    for(int x : resultado2)
    {
        cout << x<<" ";
    }



    return 0;
}
