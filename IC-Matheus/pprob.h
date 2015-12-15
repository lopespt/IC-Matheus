#ifndef PPROB_H
#define PPROB_H
#include <string>

class PProb
{

private:
    std::string nome;
    float pAlt;
    float pLarg;
    float pPeso;
public:
    std::string getName();
    float getpAlt();
    float getpLarg();
    float getpPeso();

    void setName(std::string n);
    void setpAlt(float);
    void setpLarg(float);
    void setpPeso(float);
    PProb();

};

#endif // PPROB_H
