#include <string>
#include <iostream>
#include "./RedeSocial.h"

using namespace std;


RedeSocial::RedeSocial(int numeroMaximoDePerfis){
    cout<<"Construindo a Rede Social"<<endl;
    this->perfis = new Perfil*[numeroMaximoDePerfis];
    this->numeroMaximoDePerfis = numeroMaximoDePerfis;
    this->quantidadeDePerfis = 0;
}

RedeSocial::~RedeSocial(){
    cout<<"Destruindo a Rede Social"<<endl;
    for(int i = 0; i<this->quantidadeDePerfis;i++){
        delete this->perfis[i];
    }
}
Perfil** RedeSocial::getPerfis(){
    return this->perfis;
}

bool RedeSocial::adicionar(Perfil *p){
    if(this->quantidadeDePerfis>=this->numeroMaximoDePerfis){
        return false;
    }
    this->perfis[this->quantidadeDePerfis] = p;
    this->quantidadeDePerfis++;
    cout << "***APAGAR*** Perfil adicionado" << endl;
    return true;
}

