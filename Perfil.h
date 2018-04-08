#ifndef PERFIL_H
#define PERFIL_H

#define MAXIMO_PUBLICACOES 10
#define MAXIMO_SEGUIDORES 10
#include <string>
#include <iostream>

using namespace std;

#include "./Publicacao.h"
class Publicacao;

class Perfil{
    public:
        Perfil(int numeroUSP, string nome, string email);
        virtual ~Perfil();

        int getNumeroUSP();
        string getNome();
        string getEmail();

        virtual bool adicionarSeguidor(Perfil *seguidor);
        virtual bool publicar(string texto);
        virtual bool publicar(string texto, string data);
        
        virtual void receberPublicacao(Publicacao *p);

        virtual Publicacao** getPublicacoes();
        virtual int getQuantidaDePublicacoes();

        virtual Perfil** getSeguidores();
        virtual int getQuanitdadeDeSeguidores();
        Publicacao *publicacoes[MAXIMO_PUBLICACOES];



    protected:
        int numeroUSP;
        string nome;
        string email;
        Perfil *seguidores[MAXIMO_SEGUIDORES];
        //Publicacao *publicacoes[MAXIMO_PUBLICACOES];
        int quantidaDePublicacoes;
        int quanitdadeDeSeguidores;


};

#endif
