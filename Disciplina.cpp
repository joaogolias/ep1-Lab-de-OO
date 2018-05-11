#include "./Disciplina.h"
#include <iostream>

using namespace std;

Disciplina::Disciplina(string sigla, string nome,Professor *responsavel):
    Perfil(0,nome,""){
    cout << "Construindo a disciplina " << nome
        << "(" << sigla << ")";
    this->sigla = sigla;
    this->nome = nome;
    this->responsavel = responsavel;
    this->adicionarSeguidor(responsavel);
}

bool Disciplina::adicionarSeguidor(Perfil *seguidor){
    
    if(this->quanitdadeDeSeguidores>=MAXIMO_SEGUIDORES){
        return false;
    }

    if(seguidor->getNome() == this->nome &&
        seguidor->getEmail() == this->email &&
            seguidor->getNumeroUSP() == this->numeroUSP){
                return false;
            }

    for(int i = 0; i<this->quanitdadeDeSeguidores; i++){
        Perfil *seguidos = this->seguidores[i];
        if(seguidor->getNome() == seguidos->getNome() &&
            seguidor->getEmail() == seguidos->getEmail() &&
                seguidor->getNumeroUSP() == seguidos->getNumeroUSP()){
                    return false;
                }
    }
    
    this->seguidores[this->quanitdadeDeSeguidores] = seguidor;
    this->quanitdadeDeSeguidores++;
    return true;
}


void Disciplina::receberPublicacao(Publicacao *p){}

Disciplina::~Disciplina(){
    cout << "Destruindo a disciplina " << this-> nome
        << "(" << this->sigla << ")";
}
Professor *Disciplina::getResponsavel(){
    return this->responsavel;
}
string Disciplina::getSigla(){
    return this->sigla;
}
    
