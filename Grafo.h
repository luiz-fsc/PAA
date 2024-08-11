#ifndef GRAFO_H
#define GRAFO_H
#include <vector>
using namespace std;

class Grafo{
    private:
        int numVertices;
        std::vector<std::vector<int>> listaAdjacentes; //vetor de vetores inteiros que sera usado para fazer a lista de adjacencia
        std::vector<std::vector<int>> matrizAdjacentes; //Matriz de adjacencia(Em um grafo com n vertices, sua matriz eh n * n)
        std::vector<char> corVertice; //marcar cor do vertice
        std::vector<int> rotuloAresta; //utilizar o intervalo [0,3] para rotular a aresta 
        std::vector<int> excentricidade; //valor da excentricidade de cada vertice

    public:
        Grafo(int qntVertices);
        void definirArestaDirecionada(int saida, int entrada);
        void definirArestaNaoDirecionada(int saida, int entrada);
        void buscaProfundidade(int vertice);
        void buscaLargura(int vertice);
        void setCorBranca();
        void mostrarMatriz();
        void mostrarExcentricidade(int vertice);
};

#endif