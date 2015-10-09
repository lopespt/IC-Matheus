#include <iostream>                  // for std::cout
#include <utility>                   // for std::pair
#include <algorithm>                 // for std::for_each
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/graph/undirected_graph.hpp>

using namespace boost;
using namespace std;
class VertCostm
{
	private:
		string name;
		undirected_graph<>::vertex_descriptor u;
		short int tipo;
	public:
		VertCostm(undirected_graph<>g);
		int adcedge(undirected_graph<>::vertex_descriptor a, undirected_graph<>g);
		undirected_graph<>::vertex_descriptor getu();
		~VertCostm();
};

