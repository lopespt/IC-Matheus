#include <iostream>
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

void addPerson(Graph *g, int *total){
    Graph temp;
    Graph::vertex_descriptor v0 = add_vertex(temp);
    (temp)[v0] = new VertexPerson;
    ((VertexPerson*)((temp)[v0]))->setname();
    for(int i = 0; i < *total; i++){
        if(((temp)[v0])->getVtype() == ((*g)[i])->getVtype() && ((VertexPerson*)((temp)[v0]))->getname() == ((VertexPerson*)((*g)[i]))->getname() ){
            system("cls");
            cout<<"Pessoa já existente!Tente um nome diferente...\n";
            addPerson(g,total);
            return;
        }
    }
    Graph::vertex_descriptor v = add_vertex(*g);
    ((*g)[v]) = (temp)[v0];
    (*total)++;

    cout<<"Tipo: "<<((*g)[v])->getVtype()<<endl;
    cout<<"Nome: "<<((VertexPerson*)((*g)[v]))->getname()<<endl;
    //addLargura();
    //addPeso();
    //addAltura();
    system("pause");
}
Vertex* addLargura(Graph *g, int *total){

    Graph temp;
    cout<<*total<<endl;
    Graph::vertex_descriptor v0 = add_vertex(temp);
    (temp)[v0] = new VertexCaracLargura;
    ((VertexCaracLargura*)((temp)[v0]))->setLargura();
    for(int i = 0; i < *total; i++){
        if(((temp)[v0])->getVtype() == ((*g)[i])->getVtype() && ((VertexCaracLargura*)((temp)[v0]))->getlargura() == ((VertexCaracLargura*)((*g)[i]))->getlargura() ){
            return ((*g)[i]);
        }
    }
    Graph::vertex_descriptor v = add_vertex(*g);
    ((*g)[v]) = (temp)[v0];
    (*total)++;


    return ((*g)[v]);
}

int main(int argc, char *argv[])
{
    Graph g;
    int total = 0;

    int j = 1;

  /*  Graph::vertex_descriptor v = add_vertex(g);
    Graph::vertex_descriptor v0 = add_vertex(g);
    g[v] = new VertexPerson;
    g[v0] = new VertexPerson;
    VertexPerson *a = (VertexPerson*)g[v];
    a->setname();
    cout<< a->getname();
    system("pause");*/

    while (j != 0) {
        cout << "0-adc pessoa.\n1-Buscar pessoas por caracteristicas\n2-Buscar Pessoas\n3-Sair\n";

        int i = 5;
        cin >> i;

        switch (i)
        {
        case 0:
            //addPerson(&g, &total);
            addLargura(&g, &total);


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

