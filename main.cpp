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
string imprimirGetDepartamento();
Perfil * imprimirEscolhaUmPerfil(int quantidadeDePerfis, RedeSocial *rede);
Disciplina* imprimirInformeOsDadosDaDisciplina();
Perfil* imprimirInformaOsDadosDoPerfil();
void imprimirFazerPublicacao(Perfil *perfil);
void imprimirVerPublicacoes(Perfil *perfil);
int imprimirPerfil(Perfil *perfil);

int main(){
    Perfil *perfilGenerico;
    int tamanhoDaRede, escolhaUmaOpcao, quantidadeDePerfis = 0, escolhaPerfil;
    tamanhoDaRede = getTamanhoDaRede();
    RedeSocial *rede = new RedeSocial(tamanhoDaRede);
    escolhaUmaOpcao = imprimirEscolhaUmaOpcao();
    //tamanhoDaRede = getTamanhoDaRede();
    //escolhaUmaOpcao = imprimirEscolhaUmaOpcao()
    while(escolhaUmaOpcao != 0){
        if(escolhaUmaOpcao == 1){
            perfilGenerico = imprimirInformaOsDadosDoPerfil();
            rede -> adicionar(perfilGenerico);
            quantidadeDePerfis ++;
        }
        if(escolhaUmaOpcao == 3){
            escolhaPerfil = 4;
            cout << "oi" << endl;
            while(escolhaPerfil != 0){
                cout << "oi2" << endl;
                if(escolhaPerfil == 1){
                    imprimirVerPublicacoes(perfilGenerico);
                }
                if(escolhaPerfil == 2){
                    imprimirFazerPublicacao(perfilGenerico);
                }
                cout << "oi3" << endl;
                perfilGenerico = imprimirEscolhaUmPerfil(quantidadeDePerfis, rede);
                escolhaPerfil = imprimirPerfil(perfilGenerico);
            }
        }
        if(escolhaUmaOpcao != 0) escolhaUmaOpcao = imprimirEscolhaUmaOpcao();
    }
    // Professor* aptr = dynamic_cast<Professor*>(p);
    // Perfil *a = dynamic_cast<Perfil*>(p);
    // if(aptr == 0) cout << "P is not a professor" <<endl;
    // if(a == 0) cout << "P is not a perfil" <<endl;


    // while(escolhaUmaOpcao != 0){
        
    // }


    /*

    USANDO GET LINE PARA PEGAR STRING


    string nome;
    cout << "Qual seu nome? " << endl;
    //cin.ignore(100, '\n');
    getline(cin, nome);
    cout<<"nome: "<< nome <<endl;

    */




    /*

    VERIFICAÇÃO DA CLASSE COM dynamic_cast ===> PODE USAR!!


    Perfil *prof1 = new Professor(8992902, "Levy", "joaovgolias@gmail.com", "PCS");
    Professor* aptr = dynamic_cast<Professor*>(prof1);
    if(aptr == 0) cout << "Prof1 is not a professor" <<endl;
    else cout << "Prof1 is a professor" <<endl;
    */

    
    
    /*

    EXEMPLOS DE ITERAÇÕES




    Professor *prof1 = new Professor(8992902, "Levy", "joaovgolias@gmail.com", "PCS");
    Perfil *disciplina = new Disciplina("PCS3111", "Lab de OO", prof1);
    Perfil *p3 = new Perfil(7654321, "Victor", "joaovgolias@gmail.com");
    RedeSocial *redeSocial = new RedeSocial(3);

    prof1 -> adicionarSeguidor(p3);

    prof1 -> publicar("Sou um professor");
    disciplina ->publicar ("Sou uma disciplina");
    p3 -> publicar("Sou P3");

    bool a = redeSocial->adicionar(prof1);
    bool b = redeSocial->adicionar(disciplina);
    bool c = redeSocial->adicionar(p3);

    if(a == true) cout << "A = true" << endl;
    if(b == true) cout << "B = true" << endl;
    if(c == true) cout << "C = true" << endl;

    Perfil** perfis = redeSocial -> getPerfis();
    Perfil* p1 = perfis[0];
    Perfil *p2 = perfis[1];
    Publicacao ** publicacoes1 = p1->publicacoes;
    Publicacao ** publicacoes2 = p2->publicacoes;
    Publicacao ** publicacoes3 = p3->publicacoes;

    cout<<"Publicacao 1 do prof: "<<publicacoes1[0] ->getTexto() << endl;
    cout<<"Publicacao 2 do prof: "<<publicacoes1[1] ->getTexto() << endl;
    cout<<"\n\n"<<endl;
    cout<<"Publicacao 2: "<<publicacoes2[0] ->getTexto() << endl;
    cout<<"\n\n"<<endl;
    cout<<"Publicacao 1 do p3: "<<publicacoes3[0] ->getTexto() << endl;
    cout<<"Publicacao 2 do p3: "<<publicacoes3[1] ->getTexto() << endl;
    delete redeSocial;
    */
    return 0;
}

int getTamanhoDaRede(){
    int tamanhoDaRede;
    cout << "Tamanho da Rede: ";
    cin >> tamanhoDaRede;
    return tamanhoDaRede;
}

int imprimirEscolhaUmaOpcao(){
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
    int escolha;
    Perfil **perfis;
    cout << "Escolha um perfil: " <<endl;
    for(int i = 0; i < quantidadeDePerfis; i++){
        perfis = rede -> getPerfis();
        Perfil *perfil = perfis[i];
        cout << i+1 << ") " << perfil -> getNome() << endl;
    }
    cout << "Digite o número ou 0 para cancelar: "<<endl;
    cin >> escolha;
    if(escolha != 0 && escolha<=quantidadeDePerfis) return perfis[escolha-1];
    return NULL;
}

int imprimirPerfil(Perfil *perfil){
    int escolha;
    cout << perfil -> getNumeroUSP() << " - " << perfil -> getNome() << endl;
    Professor *isProfessor = dynamic_cast<Professor*>(perfil);
    if(isProfessor != 0)cout << "Departamento "<< isProfessor -> getDepartamento() << endl;
    cout << "Seguidores: " << perfil -> getQuanitdadeDeSeguidores() << endl;
    cout << "---" << endl;
    cout << "Escolha uma opção: " << endl;
    cout << "1) Ver publicacoes" << endl;
    cout << "2) Fazer publicacao" << endl;
    Disciplina *disciplina = dynamic_cast<Disciplina*>(perfil);
    if(disciplina == 0) cout << "3) Seguir perfil" << endl;
    cout << "0) Deslogar" << endl;
    cin >> escolha;
    return escolha;
}

void imprimirFazerPublicacao(Perfil *perfil){
    string evento, texto, data;
    cout << "Evento (s/n): " << endl;
    getline(cin, evento);
    cin.ignore(100,"\n");    
    if(evento == "s"){
        cout << "Data: " << endl;
        getline(cin, data);
        cout << "Texto: " << endl;
        getline(cin, texto);
        perfil -> publicar(texto,data);
    }
    else{
        cout << "Texto: " << endl;
        getline(cin, texto);
        perfil -> publicar(texto);
    }
    
}
void imprimirVerPublicacoes(Perfil *perfil){
    int curtida;
    cout << "Publicacoes"<<endl;
    Publicacao *publicacao;
    Publicacao **publicacoes = perfil -> getPublicacoes();
    for(int i = 0; i < perfil->getQuantidaDePublicacoes(); i++){
        publicacao = publicacoes[i];
        cout << i+1 << ") " << publicacao -> getTexto() << 
         "(" << publicacao -> getAutor() << ")" << "[" << 
            publicacao -> getCurtidas() << "]"<<endl;
    }
    cout<<"Digite o numero da mensagem para curtir ou 0 para voltar: "<<endl;
    cin>>curtida;
    if(curtida!=0){
        publicacao = publicacoes[curtida-1];
        publicacao->curtir(perfil);
    }
}

string imprimirGetDepartamento(){
    string departamento;
    cout << "Departamento: ";
    getline(cin, departamento);
    return departamento;
}