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
}
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
    
