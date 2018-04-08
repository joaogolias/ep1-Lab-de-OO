#ifndef EVENTO_H
#define EVENTO_H

#include <string>
#include <iostream>
#include "./Evento.h"


using namespace std;


Evento::Evento(string texto, Perfil* autor, string data): 
    Publicacao::Publicacao(texto,autor), data(data){
        cout << "Construindo o evento do autor " << this->autor <<
            " no dia " << this->data << endl;
}

Evento::~Evento(){
    cout << "Destruindo o evento de " << this->autor<<
        "do dia " << this->data<<endl;
}

string Evento::getData(){
    return this->data;
}

#endif