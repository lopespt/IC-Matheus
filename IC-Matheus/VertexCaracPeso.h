#pragma once
#include "VertexCaract.h"
class VertexCaracPeso :	public Vertex
{
private:
	float Peso;
public:
	float getPeso();
    void setPeso();
	bool operator>(VertexCaracPeso a);
    bool operator<(VertexCaracPeso a);
	VertexCaracPeso();
	~VertexCaracPeso();
};

