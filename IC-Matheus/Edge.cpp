#include "Edge.h"

void Edge::plus()
{
	nivel++;
}

int Edge::getnivel()
{
	return nivel;
}
int Edge::getVtype(){
    return Vtype;
}

Edge::Edge()
{
	nivel = 1;
    Vtype = -1;
}


Edge::~Edge()
{
}
