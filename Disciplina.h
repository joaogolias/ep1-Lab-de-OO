#include "./Perfil.h"
#include "./Professor.h"
#include <iostream>

using namespace std;

class Disciplina: public Perfil{
    public:
        Disciplina(string sigla, string nome,Professor *responsavel);
        virtual ~Disciplina();
        Professor *getResponsavel();
        string getSigla();
        bool adicionarSeguidor(Perfil *seguidor);
        void receberPublicacao(Publicacao *p);
    
    protected:
        string sigla;
        Professor *responsavel;
};

