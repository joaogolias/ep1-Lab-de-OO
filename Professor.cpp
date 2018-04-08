#include "./Professor.h"
#include <iostream>

using namespace std;

Professor::Professor(int numeroUSP, string nome, string email, string departamento):
    Perfil(numeroUSP, nome, email), departamento(departamento){
        cout<<"Construindo o professor "<< this->nome << endl;
        cout<< "    NUSP: " << this->numeroUSP << endl;
        cout<< "    Nome: " << this->nome<<endl;
        cout<< "    Email: " << this->email<<endl;
        cout<< "    Departamento: "<< this->departamento<<endl; 
}

Professor::~Professor(){
    cout<<"Destruindo o professor " << this->nome <<endl;
}

string Professor::getDepartamento(){
    return this->departamento;
}
