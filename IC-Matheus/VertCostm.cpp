#include "VertCostm.h"


VertCostm::VertCostm (undirected_graph<>g)
{
	u = g.add_vertex();
	cout << "Digite o tipo de graph: 1-Pessoa 2-Altura 3-Peso 4-Largura do Ombro ";
	cin >> tipo;
	string temp;
	switch (tipo) {
	case 1:
		temp= "o Nome";
		break;
	case 2:
		temp = "a Altura";
		break;
	case 3:
		temp = "o Peso";
		break;
	case 4:
		temp = "a Largura do Ombro";
		break;
	}
	cout << "Digite " << temp << " da Pessoa: ";
	cin >> name;

}

int VertCostm::adcedge(undirected_graph<>::vertex_descriptor a, undirected_graph<>g)
{
	add_edge(u,a, g);

	return 0;
}

undirected_graph<>::vertex_descriptor VertCostm::getu()
{
	return u;
}


VertCostm::~VertCostm()
{
}
