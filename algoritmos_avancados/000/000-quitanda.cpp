// De acordo com uma análise do enunciado, uma estrutura de dados que pode
// resolver esse problema de forma eficiente é o dicionário (map)
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(void){
    int n = 0;
    cin >> n;
    map<string, float> mapa;
    for (int i = 0; i < n; i++){
        string codigo;
        float valor;
        cin >> codigo >> valor;
        if (mapa.find(codigo) == mapa.end()){
            mapa.insert({codigo, valor});
        }
        else{
            cout << "Produto com código " << codigo << " já cadastrado." << endl;
        }
    }
    while (n >= 0){
        string codigo;
        float valor;
        float tot = 0;
        cin >> n;
        if (n < 0) break;
        for (int i = 0; i < n; i++){
            cin >> codigo >> valor;
            if (mapa.find(codigo) != mapa.end())
            {
                tot += mapa[codigo] * valor;
            } else{
                cout << "Produto com código " << codigo << " não cadastrado." << endl;
            }
        }
        printf("R$%.2f\n", tot);
    }
}
