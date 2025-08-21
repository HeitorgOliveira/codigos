// O enunciado informa o uso de uma "priority queue" (fila de prioridades)
// ENTRADA:
// [numero de jogadroes (n)]
// [coordenada x do ponto correto] [coordenada y do ponto correto]
// n vezes:
// [nome do jogador] [coordenada x do palpite] [coordenada y do palpite]

// SAIDA:
// A saida deve informar a ordem dos jogadores em relação à distância do gabarito

// A necessidade de exibir o nome dos jogadores em conjunto com a distância do gabarito
// sugere que deve ser usado uma estrutura de dados que permita a ordenação dos conteúdos
// além disso devemos usar uma estrutura que armazena o nome e a distância do palpite do jogador
// com seu respectivo nome

// Uma estrutura que possa fazer isso seria uma priority queue e uma tupla com 2 valores

#include <iostream>
#include <cmath>
#include <list>
#include <queue>

using namespace std;

void converte_rad(float *graus){
    *graus = *graus * 3.14 / 180;
    return;
}

int main(void){
    int n;
    const int R = 6371;

    cin >> n;
    float x_true, y_true;
    cin >> x_true >> y_true;
    converte_rad(&x_true);
    converte_rad(&y_true);
    priority_queue<pair<float, string>, vector<pair<float, string>>, greater<pair<float, string>>> pq;
    for(int i = 0; i < n; i++){
        float x_pred, y_pred;
        string nome;
        cin >> nome >> x_pred >> y_pred;
        // x_pred é a latitude
        // y_pred é a longitude
        converte_rad(&x_pred);
        converte_rad(&y_pred);
        float dif_lat = x_pred - x_true;
        float dif_long = y_pred - y_true;
        //printf("y_pred: %f\ny_true: %f\nx_pred: %f\nx_true: %f\ndif_lat: %f\ndif_long: %f\n", y_pred, y_true, x_pred, x_true, dif_long, dif_lat);
        float d = sin(dif_long / 2) * sin(dif_long / 2);
        float c = cos(y_true) * cos(y_pred);
        //printf("c: %f\n d: %f", c, d);
        float b = sin(dif_lat / 2) * sin(dif_lat * 2);
        float a = b + c * d;
        float tot = 2 * R * asin(sqrt(a));
        // printf("Total: %f", tot);
        pair<float, string>palpite = pair(tot, nome);
        pq.push(palpite);
        
        cout << "> [AVISO] MELHOR PALPITE: " << pq.top().first << "km" << endl;
    }
    cout << "RANKING\n-------\n";
    int cont = 1;
    while(!pq.empty()){
        pair<float, string>no = pq.top();
        pq.pop();
        cout << cont << ". " << no.second << " " << ": " << " " << no.first << " km" << (no.first < 0.05 ? " [FANTASTICO]\n" : "\n");
        cont++;
    }
}