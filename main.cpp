/*Trabalho em grupo de até 4 pessoas. Todos os membros do grupo devem postar o trabalho.

Implemente em C++:

1) Grafo direcionado usando lista de adjacência

2) Grafo não-direcionado usando matriz de adjacência

 

Aplicação:

a) Realizar uma busca em profundidade no grafo direcionado rotulando a aresta como "de árvore", "de retorno", "de avanço" e "de cruzamento"

b) Realizar uma busca em largura no grafo não-direcionado encontrando a excentricidade de um determinado vértice.

 

Entregar o código fonte e uma documentação, em .tex, explicando o que foi feito.*/

#include <iostream>
#include "Grafo.h"

using namespace std;

int main(){
    int numVertices = 5;
    Grafo g(numVertices);
    /*g.definirArestaNaoDirecionada(0,1);
    g.definirArestaNaoDirecionada(2,0);
    g.definirArestaNaoDirecionada(3,2);*/
    g.definirArestaNaoDirecionada(1,2);
    g.definirArestaNaoDirecionada(0,2);
    g.definirArestaNaoDirecionada(0,4);
    g.definirArestaNaoDirecionada(3,1);
    g.mostrarMatriz();
    g.buscaLargura(1);

}