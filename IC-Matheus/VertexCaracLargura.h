#pragma once
#include "VertexCaract.h"
class VertexCaracLargura :	public Vertex
{
private:
	float largura;
public:
	float getlargura();
    void setLargura();
	bool operator>(VertexCaracLargura a);
    bool operator==(VertexCaracLargura a);
	VertexCaracLargura();
	~VertexCaracLargura();
};

