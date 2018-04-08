#include <string>
#include <iostream>
#include "./Perfil.h"

using namespace std;


class RedeSocial{
    public:
        RedeSocial(int numeroMaximoDePerfis);
        virtual ~RedeSocial();
        Perfil** getPerfis();
        bool adicionar(Perfil *p);
    
    private:
        Perfil** perfis;
        int quantidadeDePerfis;
        int numeroMaximoDePerfis;

};
