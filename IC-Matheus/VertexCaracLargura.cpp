#include "VertexCaracLargura.h"


float VertexCaracLargura::getlargura()
{
	return largura;
}

bool VertexCaracLargura::operator>(VertexCaracLargura a)
{
	if (largura > a.largura)
		return true;
	else
		return false;
}

bool VertexCaracLargura::operator<(VertexCaracLargura a)
{
	if (largura < a.largura)
		return true;
	else
		return false;
}

VertexCaracLargura::VertexCaracLargura()
{
    setVtype(LARG);
}
void VertexCaracLargura::setLargura(){
    cout << "Digite a Largura: ";
	cin >> largura;
}


VertexCaracLargura::~VertexCaracLargura()
{
}
