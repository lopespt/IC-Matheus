#include "Vertex.h"

int Vertex::getVtype(){
    return Vtype;
}

Vertex::Vertex(){
    Vtype = -1;
}
void Vertex::setVtype(int type){
    Vtype = type;
}
