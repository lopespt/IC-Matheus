#include "pprob.h"

PProb::PProb()
{
    nome = "0";
    pAlt = 0;
    pLarg = 0;
    pPeso = 0;
}
std::string PProb::getName(){
    return nome;
}

float PProb::getpAlt(){
    return pAlt;
}

float PProb::getpLarg(){
    return pLarg;
}

float PProb::getpPeso(){
    return pPeso;
}

void PProb::setName(std::string n){
    nome = n;
}

void PProb::setpAlt(float a){
    pAlt = a;
}

void PProb::setpLarg(float l){
    pLarg = l;
}

void PProb::setpPeso(float p){
    pPeso = p;
}


