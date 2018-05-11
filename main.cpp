#include <string>
#include <iostream>
#include "./RedeSocial.h"
#include "./Perfil.h"
#include "./Professor.h"
#include "./Disciplina.h"
#include "./Evento.h"

using namespace std;

int getTamanhoDaRede();
int imprimirEscolhaUmaOpcao();
int imprimirPerfil(Perfil *perfil);


string imprimirGetDepartamento();

void imprimirSeguirPerfil(Perfil *perfil, int quantidadeDePerfis, RedeSocial *rede);
void imprimirFazerPublicacao(Perfil *perfil);
void imprimirVerPublicacoes(Perfil *perfil);
bool adicionarPerfilNaRede(RedeSocial *rede, Perfil *perfil, 
    int quantidadeDePerfis, int tamanhoDaRede);


Perfil* imprimePerfis(int quantidadeDePerfis, RedeSocial *rede);
Perfil * imprimirEscolhaUmPerfil(int quantidadeDePerfis, RedeSocial *rede); 
Perfil* imprimirInformaOsDadosDoPerfil();

Disciplina* imprimirInformeOsDadosDaDisciplina(int quantidadeDePerfis, RedeSocial *rede);


int main(){
    Perfil *perfilGenerico;
    int tamanhoDaRede, escolhaUmaOpcao, quantidadeDePerfis = 0, escolhaPerfil;
    bool adicionado;
    tamanhoDaRede = getTamanhoDaRede();
    RedeSocial *rede = new RedeSocial(tamanhoDaRede);
    escolhaUmaOpcao = imprimirEscolhaUmaOpcao();
    while(escolhaUmaOpcao != 0){
        if(escolhaUmaOpcao == 1){
            if(quantidadeDePerfis >= 0){
                perfilGenerico = imprimirInformaOsDadosDoPerfil();
                adicionado = adicionarPerfilNaRede(rede, perfilGenerico, quantidadeDePerfis, tamanhoDaRede);
                if(adicionado) quantidadeDePerfis ++;
            } else{
                cout << "\n\n\n"; 
                cout << "Nenhum perfil foi encontrado."<<endl;
            }
        }
        if(escolhaUmaOpcao == 2){
            if(quantidadeDePerfis <= 0){
                cout << "Nao e possivel cadastrar uma disciplina sem nenhum outro perfil cadastrado" << endl;
            }
            else{
                Disciplina* disciplina = imprimirInformeOsDadosDaDisciplina(quantidadeDePerfis, rede);
                if(disciplina!=NULL){
                    adicionado = adicionarPerfilNaRede(rede, disciplina, quantidadeDePerfis, tamanhoDaRede);
                    if(adicionado) quantidadeDePerfis ++;
                }
            }
        }
        if(escolhaUmaOpcao == 3){
            escolhaPerfil = 4;
                perfilGenerico = imprimirEscolhaUmPerfil(quantidadeDePerfis, rede);            
            while(escolhaPerfil != 0){
                if(escolhaPerfil == 1){
                    imprimirVerPublicacoes(perfilGenerico);
                }
                if(escolhaPerfil == 2){
                    imprimirFazerPublicacao(perfilGenerico);
                }
                if(escolhaPerfil == 3){
                    Disciplina *disciplinaPerfil = dynamic_cast<Disciplina*>(perfilGenerico);
                    if(disciplinaPerfil != NULL){
                        cout << "Escolha um número válido" << endl;
                    } else {
                        imprimirSeguirPerfil(perfilGenerico, quantidadeDePerfis, rede);
                    }
                }
                if(escolhaPerfil > 3){
                    cout << "Escolha um número válido" << endl;
                }
                if(perfilGenerico != NULL){
                    escolhaPerfil = imprimirPerfil(perfilGenerico);
                }
                else{
                    escolhaPerfil = 0;
                }
            }
        }
        if(escolhaUmaOpcao != 0) escolhaUmaOpcao = imprimirEscolhaUmaOpcao();
    }
    delete rede;
    return 0;
}

int getTamanhoDaRede(){
    int tamanhoDaRede;
    cout << "Tamanho da Rede: ";
    cin >> tamanhoDaRede;
    return tamanhoDaRede;
}

int imprimirEscolhaUmaOpcao(){
    cout << "\n\n\n";
    int opcao;
    cout << "Escolha uma opcao:" << endl <<
        "1) Cadastrar Perfil" << endl <<
        "2) Cadastrar Disciplina" << endl <<
        "3) Logar" << endl <<
        "0) Terminar" << endl;
    cin >> opcao;
    return opcao;
}


Perfil* imprimirInformaOsDadosDoPerfil(){
    cout << "\n\n\n";
    Perfil *perfilACadastrar;
    int nusp;
    string nome, email, ehProfessor, departamento;
    cout << "Informe os dados do perfil" << endl;
    cout << "Número USP: ";
    cin >> nusp;
    cout << "Nome: ";
    cin.ignore(100,'\n');   
    getline(cin, nome);
    cout << "Email: ";
    getline(cin, email);
    cout <<"Professor (s/n): ";
    getline(cin, ehProfessor);
    if(ehProfessor == "s"){
        departamento = imprimirGetDepartamento();
        perfilACadastrar = new Professor(nusp, nome, email, departamento);
    }
    else perfilACadastrar = new Perfil(nusp, nome, email);

    return perfilACadastrar;
}


Perfil * imprimirEscolhaUmPerfil(int quantidadeDePerfis, RedeSocial *rede){
    cout << "\n\n\n";
    int escolha;
    Perfil **perfis;
    cout << "Escolha um perfil: " <<endl;
    return imprimePerfis(quantidadeDePerfis, rede);
}

Perfil* imprimePerfis(int quantidadeDePerfis, RedeSocial *rede){
    int numero = 0;
    Perfil **perfis = rede -> getPerfis();
    do{
        if(numero != 0) cout << "Digite um número válido." << endl;
        for(int i = 0; i < quantidadeDePerfis; i++){
            Perfil *perfil = perfis[i];
            cout << i+1 << ") " << perfil -> getNome() << endl;
        }
        cout << "Digite o número ou 0 para cancelar:";
        cin >> numero;
    } while(numero > quantidadeDePerfis);

    if(numero != 0 && numero <= quantidadeDePerfis) {
        Perfil *responsavel = perfis[numero-1];
        return responsavel;
    }
    return NULL;
}

int imprimirPerfil(Perfil *perfil){
    cout << "\n\n\n";
    int escolha;
    cout << perfil -> getNumeroUSP() << " - " << perfil -> getNome() << endl;
    Professor *isProfessor = dynamic_cast<Professor*>(perfil);
    if(isProfessor != NULL)cout << "Departamento "<< isProfessor -> getDepartamento() << endl;
    cout << "Seguidores: " << perfil -> getQuanitdadeDeSeguidores() << endl;
    cout << "---" << endl;
    cout << "Escolha uma opção: " << endl;
    cout << "1) Ver publicacoes" << endl;
    cout << "2) Fazer publicacao" << endl;
    Disciplina *disciplina = dynamic_cast<Disciplina*>(perfil);
    if(disciplina == NULL) cout << "3) Seguir perfil" << endl;
    cout << "0) Deslogar" << endl;
    cin >> escolha;
    return escolha;
}

Disciplina* imprimirInformeOsDadosDaDisciplina(int quantidadeDePerfis, RedeSocial *rede){
    cout << "\n\n\n";
    string nome, sigla;
    int numero = 0;
    cout << "Informe os dados da disciplina" << endl;
    cout << "Sigla: ";
    ws(cin);        
    getline(cin, sigla);
    cout << "Nome: ";
    getline(cin, nome);
    cout << "Responsável: " << endl;
    Perfil *responsavel = imprimePerfis(quantidadeDePerfis, rede);
    Professor *isProfessor = dynamic_cast<Professor*>(responsavel);
    if(isProfessor != NULL){
        Disciplina *disciplina = new Disciplina(sigla, nome, isProfessor);
        return disciplina;
    }
    cout << "Somente professores podem ser responsáveos por disciplinas";
    return NULL;                
}

void imprimirFazerPublicacao(Perfil *perfil){
    cout << "\n\n\n";
    string evento, texto, data;
    cout << "Evento (s/n):" << endl;
    ws(cin);
    getline(cin, evento); 
    if(evento == "s"){
        cout << "Data: " << endl;
        getline(cin, data);
        cout << "Texto: " << endl;
        getline(cin, texto);
        bool teste = perfil -> publicar(texto,data);
    }
    else{
        cout << "Texto: " << endl;
        getline(cin, texto);
        bool teste2 = perfil -> publicar(texto);
    }
    
}
void imprimirVerPublicacoes(Perfil *perfil){
    cout << "\n\n\n";
    if(perfil -> getQuantidaDePublicacoes() !=0){
        int curtida;
        cout << "Publicacoes"<<endl;
        Publicacao *publicacao;
        Publicacao **publicacoes = perfil -> getPublicacoes();
        for(int i = 0; i < perfil->getQuantidaDePublicacoes(); i++){
            publicacao = publicacoes[i];
            Evento* evento = dynamic_cast<Evento*>(publicacao);
            if(evento == NULL){
                Perfil *autor = publicacao -> getAutor();
                cout << i+1 << ") " << publicacao -> getTexto() << 
                    "(" << autor -> getNome() << ")" << "[" << 
                        publicacao -> getCurtidas() << "]"<<endl;
            } else {
                Perfil *autor = evento -> getAutor();
                cout << i+1 << ") " << evento -> getData() << " - " << evento -> getTexto() << 
                    "(" << autor -> getNome() << ")" << "[" << 
                        evento -> getCurtidas() << "]"<<endl;
            }
           
        }
        cout<<"Digite o numero da mensagem para curtir ou 0 para voltar: "<<endl;
        cin>>curtida;
        if(curtida!=0){
            publicacao = publicacoes[curtida-1];
            publicacao->curtir(perfil);
        }
    }
}
void imprimirSeguirPerfil(Perfil *perfil, int quantidadeDePerfis, RedeSocial *rede){
    cout << "Perfil: " << endl; 
    Perfil *perfilASeguir = imprimePerfis(quantidadeDePerfis, rede);
    bool seguidoSucesso =  perfilASeguir -> adicionarSeguidor(perfil);
    if(!seguidoSucesso){
        cout << "Não foi possível seguir este perfil" << endl;
    }
}

bool adicionarPerfilNaRede(RedeSocial *rede, Perfil *perfil, 
    int quantidadeDePerfis, int tamanhoDaRede){
        if(quantidadeDePerfis >= tamanhoDaRede){
            cout << "Não foi possível adicionar esse perfil. Tamanho da rede atingido" << endl;
            return false;
        }
        bool adicionado = rede -> adicionar(perfil);
        return adicionado;
}

string imprimirGetDepartamento(){
    cout << "\n\n\n";
    string departamento;
    cout << "Departamento: ";
    getline(cin, departamento);
    return departamento;
}