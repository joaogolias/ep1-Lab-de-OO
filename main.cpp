#include <string>
#include <iostream>
#include "./RedeSocial.h"
#include "./Perfil.h"
#include "./Professor.h"
#include "./Disciplina.h"

using namespace std;

int getTamanhoDaRede();
int imprimirEscolhaUmaOpcao();
string imprimirGetDepartamento();
Disciplina* imprimirInformeOsDadosDaDisciplina();
Perfil* imprimirInformaOsDadosDoPerfil();

int main(){
    int tamanhoDaRede, escolhaUmaOpcao;
    //tamanhoDaRede = getTamanhoDaRede();
    //escolhaUmaOpcao = imprimirEscolhaUmaOpcao()

    Perfil *p = imprimirInformaOsDadosDoPerfil();
    cout << p->getNome() << endl;
    p = imprimirInformaOsDadosDoPerfil();
    cout << p->getNome() << endl;
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

string imprimirGetDepartamento(){
    string departamento;
    cout << "Departamento: ";
    getline(cin, departamento);
    return departamento;
}