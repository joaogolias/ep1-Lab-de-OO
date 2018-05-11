#include "./Publicacao.h"
#include <iostream>

using namespace std;

Publicacao::Publicacao(string texto, Perfil *autor): 
    texto(texto), autor(autor){}

Publicacao::~Publicacao(){
    cout<<"Destruindo a publicacão " << this->texto << " do autor " <<
    this->autor->getNome() << endl;
}

Perfil* Publicacao::getAutor(){
    return this->autor;
}

string Publicacao::getTexto(){
    return this->texto;
}

void Publicacao::curtir(Perfil *quemCurtiu){
    if(this->quantidadeDeCurtidas < MAXIMO_CURTIDORES){
        this->curtidores[this->quantidadeDeCurtidas] = quemCurtiu;
        this->quantidadeDeCurtidas++;
    }
}

int Publicacao::getCurtidas(){
    return this->quantidadeDeCurtidas;
}




