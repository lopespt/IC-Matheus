#pragma once
#include <iostream>                  // for std::cout

#define PERSON 0
#define ALT 1
#define LARG 2
#define PESO 3
#define EDGE -1
using namespace std;
class Vertex
{
    private:
        int Vtype;

    public:
        int getVtype();
        void setVtype(int);
        Vertex();

};

