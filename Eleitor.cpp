//por Argéu Venturini e Arthur Scalon

#include <string.h>
#include <iostream>
#include <stdio.h>
using namespace std;

class Eleitor {
    static int total;
    static int analfabetos;
    char escolaridade; //A-Analfabeto, P-Primeiro Grau, S-Segundo Grau, U-Superior
    string nome;
 public :
    Eleitor();
    ~Eleitor();
    void Definicao(string, char);
    static void ResultadoGeral();

};

int Eleitor::total = 0;
int Eleitor::analfabetos = 0;

Eleitor::Eleitor(){
    nome = "Sem Registro";
    escolaridade = ' ';

}

Eleitor::~Eleitor(){
    cout << "Destruindo Eleitor: " << nome << endl;
}

void Eleitor::Definicao(string nome, char escolaridade){
    this->nome = nome;
    this->escolaridade = escolaridade;
    Eleitor::total++;
    if (escolaridade == 'A')
        Eleitor::analfabetos++;
        cout << Eleitor::analfabetos << endl;

}

void Eleitor::ResultadoGeral(){
    float Percent;
    Percent = (Eleitor::analfabetos * 100) /Eleitor::total;
    cout << "Total de eleitores cadastrados: " << Eleitor::total << endl;
    cout << "Porcentagem de analfabetismo: " << Percent << "%" << endl;

}


int main() {
    int quantidade;
    string nomeLido;
    char escLida;
    int i = 0;

    cout << "Digite quantos eleitores deseja cadastrar: " << endl;
    cin >> quantidade;
    Eleitor Eleitor[quantidade];

    do {
    cout << "Digite o nome do Eleitor " << i+1 << endl;
    cin >> nomeLido;
    cout << "Digite a escolaridade do Eleitor " << i+1 << " Digite: A-Analfabeto, P-Primeiro Grau, S-Segundo Grau, U-Superior" << endl;
    cin >> escLida;
    Eleitor[i].Definicao(nomeLido, escLida);
    i++;
    }while (i != quantidade);

    Eleitor[quantidade].ResultadoGeral();

 return 0;
}
