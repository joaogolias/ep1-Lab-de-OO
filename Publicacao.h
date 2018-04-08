#ifndef PUBLICACAO_H
#define PUBLICACAO_H

#define MAXIMO_CURTIDORES 10
#include <string>
#include <iostream>

using namespace std;

#include "./Perfil.h"

class Perfil;


class Publicacao{
    public:
        Publicacao(string texto, Perfil *autor);
        virtual ~Publicacao();
        Perfil *getAutor();
        string getTexto();
        virtual void curtir(Perfil *quemCurtiu);
        virtual int getCurtidas();
    
    protected:
        Perfil *autor;
        string texto;
        int quantidadeDeCurtidas = 0;
        Perfil *curtidores[MAXIMO_CURTIDORES];

};
#endif 
