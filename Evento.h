#define MAXIMO_CURTIDORES 10
#include <string>
#include <iostream>


#include "Publicacao.h"
using namespace std;


class Evento: public Publicacao{
    public:
        Evento(string texto, Perfil *autor, string data);
        ~Evento();
        string getData();

    private:
        string data;
};
