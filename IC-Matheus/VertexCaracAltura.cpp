#include "VertexCaracAltura.h"
int tipo(){
    return ALT;
}

float VertexCaracAltura::getAltura()
{
	return altura;
}

bool VertexCaracAltura::operator>(VertexCaracAltura a)
{
	if (altura > a.altura)
		return true;
	else
		return false;
}

bool VertexCaracAltura::operator==(VertexCaracAltura a)
{
    if (altura == a.altura)
		return true;
	else
		return false;
}


VertexCaracAltura::VertexCaracAltura()
{
    setVtype(ALT);
}

void VertexCaracAltura::setAltura(){
    float a;
	cout << "Escreva a altura (float): ";
	cin >> a;
	altura = a;

}


VertexCaracAltura::~VertexCaracAltura()
{
}
