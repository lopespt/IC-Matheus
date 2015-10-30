#pragma once
#include "Vertex.h"

class Edge
{
private:
	int nivel;
    int Vtype;
public:
    int getVtype();
    void plus();
	int getnivel();
	Edge();
	~Edge();
};

