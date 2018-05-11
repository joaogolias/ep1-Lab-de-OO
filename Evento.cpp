#ifndef EVENTO_H
#define EVENTO_H

#include <string>
#include <iostream>
#include "./Evento.h"


using namespace std;


Evento::Evento(string texto, Perfil* autor, string data): 
    Publicacao::Publicacao(texto,autor), data(data){
        cout << "Construindo o evento do autor " << this->autor->getNome() <<
            " no dia " << this->data << endl;
}

Evento::~Evento(){
    cout << "Destruindo o evento de " << this->autor->getNome()<<
        "do dia " << this->data<<endl;
}

string Evento::getData(){
    return this->data;
}

#endif