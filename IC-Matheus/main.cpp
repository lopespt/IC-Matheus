
#define PERSON 0
#define ALT 1
#define LARG 2
#define PESO 3

#include <iostream>
#include <stdio.h>
#include <vector>
#include "pprob.h"
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/lookup_edge.hpp>
#include <boost/graph/adjacency_iterator.hpp>
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
        if(((*g)[i])->getVtype()== PERSON){
            if (((VertexPerson*)((*g)[i]))->getname() == name){

                typedef boost::property_map<Graph, boost::vertex_index_t>::type IndexMap;
                 IndexMap index = get(boost::vertex_index, *g);

                 typedef boost::graph_traits < Graph >::adjacency_iterator adjacency_iterator;

                 std::pair<adjacency_iterator, adjacency_iterator> neighbors = boost::adjacent_vertices(vertex(i,*g), *g);

                for(; neighbors.first != neighbors.second; neighbors.first++)
                    {
                      int ind = index[*neighbors.first];
                     int temp = ((*g)[ind])->getVtype();
                     cout<<temp <<"  lalalal\n\n";
                      switch (temp){
                        case PESO:
                        std::cout <<"PESO DE "<<name<<": "<< ((VertexCaracPeso*)((*g)[ind]))->getPeso() <<endl;
                        break;

                        case ALT:
                        std::cout <<"ALTURA DE "<<name<<": "<< ((VertexCaracAltura*)((*g)[ind]))->getAltura() <<endl;
                        break;

                        case LARG:
                        std::cout <<"LARGURA DOS OMBROS DE "<<name<<": "<< ((VertexCaracLargura*)((*g)[ind]))->getlargura() <<endl;
                        break;
                      }
                }
                system("pause");
                return;
            }
            }
    }

    cout<<"\n Nao existe essa pessoa!\n";
    getchar();
    system("pause");

}

int searchbycarac(Graph *g, int *total){
    vector<PProb> probs;
    int totalCarac = 0;
    int controle = 0;
    float Carac = 0;

    cout<<"\nDigite o Altura";
    cin>>Carac;

    for(int i = 0; i < (*total); i++){
        try{
            ((*g)[i])->getVtype();
        }catch(int i){
            i++;
        }
        if(((*g)[i])->getVtype()== ALT){
            if (((VertexCaracAltura*)((*g)[i]))->getAltura() == Carac){

                typedef boost::property_map<Graph, boost::vertex_index_t>::type IndexMap;
                 IndexMap index = get(boost::vertex_index, *g);

                 typedef boost::graph_traits < Graph >::adjacency_iterator adjacency_iterator;

                 std::pair<adjacency_iterator, adjacency_iterator> neighbors = boost::adjacent_vertices(vertex(i,*g), *g);

                    for(; neighbors.first != neighbors.second; neighbors.first++)
                    {
                         int ind = index[*neighbors.first];

                         PProb x;
                         x.setName(((VertexPerson*)((*g)[ind]))->getname());
                         Graph::edge_descriptor edgeA;
                         edgeA = boost::edge(*((Graph::vertex_descriptor*)((*g)[i])), *((Graph::vertex_descriptor*)((*g)[ind])), (*g)).first;
                         x.setpAlt(((*g)[edgeA]).getnivel());
                         totalCarac += x.getpAlt();
                         probs.push_back(x);
                }
            }
            }

    }

    for(std::vector<PProb>::iterator it = probs.begin() ; it != probs.end(); ++it){
         if(it->getpAlt()!= 0){
            float probabilidade = it->getpAlt();
           probabilidade = probabilidade/totalCarac;
           it->setpAlt(probabilidade);
         }
    }
    Carac = 0;
    totalCarac = 0;
    cout<<"\nDigite o Largura";
    cin>>Carac;

    for(int i = 0; i < (*total); i++){
        try{
            ((*g)[i])->getVtype();
        }catch(int i){
            i++;
        }
        if(((*g)[i])->getVtype()== LARG){
            if (((VertexCaracLargura*)((*g)[i]))->getlargura() == Carac){
                typedef boost::property_map<Graph, boost::vertex_index_t>::type IndexMap;
                 IndexMap index = get(boost::vertex_index, *g);

                 typedef boost::graph_traits < Graph >::adjacency_iterator adjacency_iterator;

                 std::pair<adjacency_iterator, adjacency_iterator> neighbors = boost::adjacent_vertices(vertex(i,*g), *g);

                    for(; neighbors.first != neighbors.second; neighbors.first++)
                    {
                         int ind = index[*neighbors.first];
                         std::vector<PProb>::iterator it;
                         for( it = probs.begin() ; it != probs.end(); ++it){
                            if( it->getName() == ((VertexPerson*)((*g)[ind]))->getname()){
                                break;
                            }
                            if( it + 1 == probs.end() ){
                            PProb x;
                            x.setName(((VertexPerson*)((*g)[ind]))->getname());
                            Graph::edge_descriptor edgeA;
                            edgeA = boost::edge(*((Graph::vertex_descriptor*)((*g)[i])), *((Graph::vertex_descriptor*)((*g)[ind])), (*g)).first;
                            x.setpLarg(((*g)[edgeA]).getnivel());
                            totalCarac += x.getpLarg();
                            probs.push_back(x);
                            controle = 1;
                            break;
                            }
                     }
                     if(controle!=1){
                         Graph::edge_descriptor edgeA;
                         edgeA = boost::edge(*((Graph::vertex_descriptor*)((*g)[i])), *((Graph::vertex_descriptor*)((*g)[ind])), (*g)).first;
                         it->setpLarg(((*g)[edgeA]).getnivel());
                         totalCarac += it->getpLarg();
                     }
                     controle = 0;


                }
            }
            }

    }
    for(std::vector<PProb>::iterator it = probs.begin() ; it != probs.end(); ++it){
        if(it->getpLarg()!= 0){
            float probabilidade = it->getpLarg();
           probabilidade = probabilidade/totalCarac;
           it->setpLarg(probabilidade);
        }
    }

    Carac = 0;
    totalCarac = 0;
    cout<<"\nDigite o Peso";
    cin>>Carac;

    for(int i = 0; i < (*total); i++){
        try{
            ((*g)[i])->getVtype();
        }catch(int i){
            i++;
        }
        if(((*g)[i])->getVtype()== PESO ){
            if (((VertexCaracPeso*)((*g)[i]))->getPeso() == Carac){

                typedef boost::property_map<Graph, boost::vertex_index_t>::type IndexMap;
                 IndexMap index = get(boost::vertex_index, *g);

                 typedef boost::graph_traits < Graph >::adjacency_iterator adjacency_iterator;

                 std::pair<adjacency_iterator, adjacency_iterator> neighbors = boost::adjacent_vertices(vertex(i,*g), *g);

                    for(; neighbors.first != neighbors.second; neighbors.first++)
                    {
                         int ind = index[*neighbors.first];
                         std::vector<PProb>::iterator it;
                         for( it = probs.begin() ; it != probs.end(); ++it){
                            if( it->getName() == ((VertexPerson*)((*g)[ind]))->getname()){
                                break;
                            }
                            if( it + 1 == probs.end() ){
                            PProb x;
                            x.setName(((VertexPerson*)((*g)[ind]))->getname());
                            Graph::edge_descriptor edgeA;
                            edgeA = boost::edge(*((Graph::vertex_descriptor*)((*g)[i])), *((Graph::vertex_descriptor*)((*g)[ind])), (*g)).first;
                            x.setpPeso(((*g)[edgeA]).getnivel());
                            totalCarac += x.getpPeso();
                            probs.push_back(x);
                            controle = 1;
                            break;
                            }
                     }
                     if(controle != 1 ){
                     Graph::edge_descriptor edgeA;
                     edgeA = boost::edge(*((Graph::vertex_descriptor*)((*g)[i])), *((Graph::vertex_descriptor*)((*g)[ind])), (*g)).first;
                     it->setpPeso(((*g)[edgeA]).getnivel());
                     totalCarac += it->getpPeso();
                     }
                     controle = 0;

                }
            }
            }

            }
    for(std::vector<PProb>::iterator it = probs.begin() ; it != probs.end(); ++it){
        if(it->getpPeso()!= 0){
           float probabilidade = it->getpPeso();
           probabilidade = probabilidade/totalCarac;
           it->setpPeso(probabilidade);
        }
    }
    float pgeraltotal = 0;
    for(std::vector<PProb>::iterator it = probs.begin() ; it != probs.end(); ++it){

        pgeraltotal += 1 - ( (1 - it->getpAlt() )*(1 - it->getpLarg())*(1 - it->getpPeso()) );

    }

    for(std::vector<PProb>::iterator it = probs.begin() ; it != probs.end(); ++it){

        cout<<"Nome: "<<it->getName()<<endl;
        cout<<"Probabilidade da Altura: "<<it->getpAlt()<<endl;
        cout<<"Probabilidade da Largura: "<<it->getpLarg()<<endl;
        cout<<"Probabilidade da Peso: "<<it->getpPeso()<<endl;
        float pgeral = 0;
        pgeral = (1 - ( (1 - it->getpAlt() )*(1 - it->getpLarg())*(1 - it->getpPeso()) ))/pgeraltotal;
        cout<<"Probabilidade Geral: "<<pgeral<<endl<<endl;

    }

    system("pause");
    return 0;
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
    return ((*total)-1);
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
                    system("pause");
                    return i;

            }
        }
    }

    Graph::vertex_descriptor v = add_vertex(*g);
    ((*g)[v]) = (temp)[v0];
    (*total)++;
    return ((*total)-1);
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
    return ((*total)-1);
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

    Edge e0, e1, e2;
    int ind = addAltura(g,total);
    boost::add_edge(ind, v, e0, *g);
    ind = addLargura(g,total);
    boost::add_edge(ind, v, e2, *g);
    ind = addPeso(g,total);
    boost::add_edge(ind, v, e1, *g);


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

        case 4:
            searchbycarac(&g, &total);

        default:
            break;
        }
        system("cls");
    }
   // destroi(&vedges, &vpessoa, &valtura, &vlargura, &vpeso);
    return 0;
}

