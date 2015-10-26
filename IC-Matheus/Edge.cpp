#include "Edge.h"

void Edge::plus()
{
	nivel++;
}

int Edge::getnivel()
{
	return nivel;
}

Edge::Edge()
{
	nivel = 1;
}


Edge::~Edge()
{
}
