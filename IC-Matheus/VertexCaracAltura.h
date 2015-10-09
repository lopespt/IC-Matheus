#pragma once
#include "VertexCaract.h"
class VertexCaracAltura : public Vertex
{
private:
	float altura;
public:
	float getAltura();
    void setAltura();
	bool operator>(VertexCaracAltura a);
    bool operator<(VertexCaracAltura a);
	VertexCaracAltura();
	~VertexCaracAltura();
};

