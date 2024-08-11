#include "Grafo.h"
#include <iostream>
#include <vector>

using namespace std;

//Construtor
Grafo::Grafo(int qntVertices): numVertices(qntVertices){
    corVertice.resize(qntVertices);
    setCorBranca();
    listaAdjacentes.resize(qntVertices);
    matrizAdjacentes.resize(qntVertices, vector<int>(qntVertices, 0)); //Matriz numvertice x numvertice, inicializada com 0
    excentricidade.resize(qntVertices, 0);
}

//Definir todos os vertices como branco, ou seja nenhum vertice foi visitado ainda
void Grafo::setCorBranca(){
    for(int i = 0 ; i < numVertices; i++){
        corVertice[i] = 'b';
    }
}

/*Criar as arestas direcionadas usando lista de adjacencia, ou seja tem uma aresta de A para B
mas nao necessariamente existe uma de B para A*/
void Grafo::definirArestaDirecionada(int saida, int entrada){
    listaAdjacentes[saida].push_back(entrada);
}

/*Criar as arestas nao direcionadas, ou seja se tem uma aresta de A para B
entao necessariamente tem uma aresta de B para A*/
void Grafo::definirArestaNaoDirecionada(int saida, int entrada){
    matrizAdjacentes[saida][entrada] = 1;
    matrizAdjacentes[entrada][saida] = 1;
}

void Grafo::mostrarMatriz(){
    for(int i = 0; i < numVertices; i++){
        for(int j = 0; j < numVertices; j++){
            std::cout << matrizAdjacentes[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void Grafo::mostrarExcentricidade(int vertice){
    std::cout << "A excentricidade do vertice " << vertice << " eh: " << excentricidade[vertice] << "\n";
}

/*durante a busca em largura definimos o valor da excentircidade do vertice
utilizando a variavel excentricidade, como a busca em largura fornece o menor caminho,
a excentricidade do vertice em questao sera "a maior das menores distancias".
*/
void Grafo::buscaLargura(int vertice){
    std::vector<int> filaDeBusca;
    int atual;
    std::vector<int> distancia(numVertices, 0);
    filaDeBusca.push_back(vertice);
    //vou repetir ate que minha lista fique vazia
    while(filaDeBusca.empty() == false){
        atual = filaDeBusca[0];
        std::cout << "o vertice atual eh: " << filaDeBusca[0] << "\n";
        corVertice[atual] = 'a';//visitei o vertice entao ele fica azul
        for(int i = 0; i < numVertices; i++){
            /* se na linha da minha matriz de adjacencia o numero eh 1
            entao tem uma aresta do meu vertice atual para o vertice i,
            porem so podemos adicionar o proximo vertice a lista caso
            ele esteja branco(ou seja, ainda nao visitado)*/
            if(matrizAdjacentes[atual][i] == 1 && corVertice[i] == 'b'){
                filaDeBusca.push_back(i);
                std::cout << "inserido o vertice: " << i << " na fila\n";
                corVertice[i] = 'a';
                distancia[i] = distancia[atual] + 1;
            }
        }
        std::cout << "Deletando o vertice: " << filaDeBusca[0] << " da fila\n";  
        filaDeBusca.erase(filaDeBusca.begin());       
    }
    for(int i = 0; i < numVertices; i++){
        if(excentricidade[vertice] < distancia[i]){
            excentricidade[vertice] = distancia[i];
        }
    }

    mostrarExcentricidade(vertice);
    
}

