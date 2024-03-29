#include "./Perfil.h"
#include <iostream>

#include "./Publicacao.h"
#include "./Evento.h"

using namespace std;

Perfil::Perfil(int numeroUSP, string nome, string email):
    numeroUSP(numeroUSP), nome(nome), email(email){
        cout << "Perfil criado: " <<endl;
        cout<< "    NUSP: " << this->numeroUSP << endl;
        cout<< "    Nome: " << this->nome<<endl;
        cout<< "    Email: " << this->email<<endl;
    }

Perfil::~Perfil(){
    cout<< "Destruindo perfil de " << this->nome << endl;
    for (int i=0; i<this->quantidaDePublicacoes;i++){
        Publicacao *p = publicacoes[i];
        if(p != NULL){
            Perfil *autor = p->getAutor();
            if(autor -> getNumeroUSP() == this->numeroUSP &&
                autor -> getEmail() == this-> email &&
                 autor -> getNome() == this->nome){
                    p == NULL;
                    delete p;
            }
        }
    } 
}

string Perfil::getNome(){
    return this->nome;
}

string Perfil::getEmail(){
    return this->email;
}

bool Perfil::adicionarSeguidor(Perfil *seguidor){
    
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
    string nome = seguidor -> getNome();
    string textoDaPublicacao = "Novo seguidor: ";
    if(this->quantidaDePublicacoes < MAXIMO_PUBLICACOES){
        textoDaPublicacao += nome;
        Publicacao *p = new Publicacao(textoDaPublicacao, this);
        this->publicacoes[this->quantidaDePublicacoes] = p;
        this->quantidaDePublicacoes++;
    }
    return true;
}

bool Perfil::publicar(string texto){
    if(this->quantidaDePublicacoes>=MAXIMO_PUBLICACOES){
        return false;
    }
    Publicacao *p1 = new Publicacao(texto, this);
    this->publicacoes[this->quantidaDePublicacoes] = p1;
    this->quantidaDePublicacoes++;
    for(int i = 0; i<this->quanitdadeDeSeguidores;i++){
       this->seguidores[i]->receberPublicacao(p1);
    }
    return true;
}

bool Perfil::publicar(string texto, string data){
    if(this->quantidaDePublicacoes>=MAXIMO_PUBLICACOES){
        return false;
    }
    Evento *evento = new Evento(texto, this, data);
    this->publicacoes[this->quantidaDePublicacoes] = evento;
    this->quantidaDePublicacoes++;
    for(int i = 0; i<this->quanitdadeDeSeguidores;i++){
       Perfil *seguidor = this->seguidores[i];
       seguidor->receberPublicacao(evento);
    }
    return true;
}

void Perfil::receberPublicacao(Publicacao *p){
    if(this->quantidaDePublicacoes < MAXIMO_PUBLICACOES){
        this->publicacoes[this->quantidaDePublicacoes] = p;
    }
    this->quantidaDePublicacoes++;
}

Publicacao** Perfil::getPublicacoes(){
    return this->publicacoes;
}

int Perfil::getQuantidaDePublicacoes(){
    return this->quantidaDePublicacoes;
}

Perfil** Perfil::getSeguidores(){
    return this->seguidores;
}

int Perfil::getQuanitdadeDeSeguidores(){
    return this->quanitdadeDeSeguidores;
}

int Perfil::getNumeroUSP(){
    return this->numeroUSP;
}



