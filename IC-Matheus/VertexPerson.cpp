#include "VertexPerson.h"
#include <string>

void VertexPerson::setname() 
{
	std::string temp;
	cout << "Nome da Pessoa: ";
	std::cin >> temp;
	name = temp;
}

std::string VertexPerson::getname() const
{
	return name;
}

bool VertexPerson::operator>(VertexPerson a)
{
	if (name > a.getname())
		return true;
	else
		return false;
}

bool VertexPerson::operator<(VertexPerson a) const
{
	if (name < a.getname())
		return true;
	else
		return false;
}



VertexPerson::VertexPerson()
{
    setVtype(PERSON);
}


VertexPerson::~VertexPerson()
{
}
