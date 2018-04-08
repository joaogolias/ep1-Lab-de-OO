#ifndef PROFESSOR_H
#define PROFESSOR_H
#include "./Perfil.h"
#include <iostream>

using namespace std;

class Professor: public Perfil{
    public:
        Professor(int numeroUSP, string nome, string email, string departamento);
        virtual ~Professor();
        string getDepartamento();
    
    protected:
        string departamento;
};
#endif 




