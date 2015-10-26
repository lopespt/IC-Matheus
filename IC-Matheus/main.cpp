#include <iostream>
#include <stdio.h>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/graph/undirected_graph.hpp>
#include "Vertex.h"
#include "Edge.h"
#include "VertexPerson.h"
#include "VertexCaracPeso.h"
#include "VertexCaracLargura.h"
#include "VertexCaracAltura.h"

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS, Vertex*, Edge > Graph;
using namespace boost;
using namespace std;

/*
 * terminar o addPerson();
 * -fazer a ligação com o retorno das outras functions;
 * -limapa os prints lokos que tem;
 */
void searchperson(Graph *g, int *total){
    string name;
    cout<<"\nDigite o Nome da pessoa que deseja achar: ";
    cin>>name;

    for(int i = 0; i < (*total); i++){
        try{
            ((*g)[i])->getVtype();
        }catch(int i){
            i++;
        }
            if (((VertexPerson*)((*g)[i]))->getname() == name){

                typedef boost::property_map<Graph, boost::vertex_index_t>::type IndexMap;
                IndexMap index = get(boost::vertex_index, g);

                typedef boost::graph_traits < Graph >::adjacency_iterator adjacency_iterator;

                std::pair<adjacency_iterator, adjacency_iterator> neighbors = boost::adjacent_vertices(i, g);

                for(; neighbors.first != neighbors.second; ++neighbors.first)
                  {

                      switch (index[*neighbors.first].Vtype()){
                        case PESO:
                        std::cout <<"PESO DE "<<name<<": "<< ((VertexCaracPeso*)index[*neighbors.first])->getPeso() <<endl;
                        break;

                        case ALT:
                        std::cout <<"ALTURA DE "<<name<<": "<< ((VertexCaracAltura*)index[*neighbors.first])->getAltura() <<endl;
                        break;

                        case LARG:
                        std::cout <<"LARGURA DOS OMBROS DE "<<name<<": "<< ((VertexCaracLargura*)index[*neighbors.first])->getlargura(); <<endl;
                        break;
                      }
                  }
                return;
            }
    }
    fflush(stdin);
    cout<<"\n Nao existe essa pessoa!\n";
    getchar();
    fflush(stdin);

}

int addLargura(Graph *g, int *total){

    Graph temp;
    Graph::vertex_descriptor v0 = add_vertex(temp);
    (temp)[v0] = new VertexCaracLargura;
    ((VertexCaracLargura*)((temp)[v0]))->setLargura();
    fflush(stdin);

     for(int i = 0; i < (*total); i++){

        try{
            ((*g)[i])->getVtype();
        }catch(int i){
            i++;
        }

        if(((temp)[v0])->getVtype() == ((*g)[i])->getVtype()){

                if(((VertexCaracLargura*)((temp)[v0]))->getlargura() == ((VertexCaracLargura*)((*g)[i]))->getlargura() ){
                    return i;

            }
        }
    }

    Graph::vertex_descriptor v = add_vertex(*g);
    ((*g)[v]) = (temp)[v0];
    (*total)++;
    cout<<"\n4\n";
    return (*total);
}

int addPeso(Graph *g, int *total){

    Graph temp;
    Graph::vertex_descriptor v0 = add_vertex(temp);
    (temp)[v0] = new VertexCaracPeso;
    ((VertexCaracPeso*)((temp)[v0]))->setPeso();
    fflush(stdin);

     for(int i = 0; i < (*total); i++){

        try{
            ((*g)[i])->getVtype();
        }catch(int i){
            i++;
        }

        if(((temp)[v0])->getVtype() == ((*g)[i])->getVtype()){

                if(((VertexCaracPeso*)((temp)[v0]))->getPeso() == ((VertexCaracPeso*)((*g)[i]))->getPeso() ){
                    return i;

            }
        }
    }

    Graph::vertex_descriptor v = add_vertex(*g);
    ((*g)[v]) = (temp)[v0];
    (*total)++;
    cout<<"\n4\n";
    return (*total);
}

int addAltura(Graph *g, int *total){

    Graph temp;
    Graph::vertex_descriptor v0 = add_vertex(temp);
    (temp)[v0] = new VertexCaracAltura;
    ((VertexCaracAltura*)((temp)[v0]))->setAltura();
    fflush(stdin);

     for(int i = 0; i < (*total); i++){

        try{
            ((*g)[i])->getVtype();
        }catch(int i){
            i++;
        }

        if(((temp)[v0])->getVtype() == ((*g)[i])->getVtype()){

                if(((VertexCaracAltura*)((temp)[v0]))->getAltura() == ((VertexCaracAltura*)((*g)[i]))->getAltura() ){
                    return i;

            }
        }
    }

    Graph::vertex_descriptor v = add_vertex(*g);
    ((*g)[v]) = (temp)[v0];
    (*total)++;
    cout<<"\n4\n";
    return (*total);
}



void addPerson(Graph *g, int *total){
    Graph temp;
    Graph::vertex_descriptor v0 = add_vertex(temp);
    (temp)[v0] = new VertexPerson;
    ((VertexPerson*)((temp)[v0]))->setname();
     fflush(stdin);
    for(int i = 0; i < (*total); i++){
        try{
            ((*g)[i])->getVtype();
        }catch(int i){
            i++;
        }

        if(((temp)[v0])->getVtype() == ((*g)[i])->getVtype()){
            if (((VertexPerson*)((temp)[v0]))->getname() == ((VertexPerson*)((*g)[i]))->getname() ){
                system("cls");
                cout<<"Pessoa já existente!Tente um nome diferente...\n";
                addPerson(g,total);
                return;
            }
        }
    }
    Graph::vertex_descriptor v = add_vertex(*g);
    ((*g)[v]) = (temp)[v0];
    (*total)++;

    cout<<"Tipo: "<<((*g)[v])->getVtype()<<endl;
    cout<<"Nome: "<<((VertexPerson*)((*g)[v]))->getname()<<endl;
    Edge e0;
    int ind = addLargura(g,total);
    boost::add_edge(ind, v, e0, *g);
    ind = addPeso(g,total);
    boost::add_edge(ind, v, e0, *g);
    ind = addAltura(g,total);
    boost::add_edge(ind, v, e0, *g);
}

int main()
{
    Graph g;
    int total = 0;

    int j = 1;
    while (j != 0) {
        cout << "0-adc pessoa.\n1-Buscar pessoas por caracteristicas\n2-Buscar Pessoas\n3-Sair\n";

        int i = 5;
        cin >> i;

        switch (i)
        {
        case 0:
            addPerson(&g, &total);
            break;
        case 1:

            break;
        case 2:
            searchperson(&g, &total);
            break;

        case 3:
            j = 0;
            break;

        default:
            break;
        }
        system("cls");
    }
   // destroi(&vedges, &vpessoa, &valtura, &vlargura, &vpeso);
    return 0;
}

