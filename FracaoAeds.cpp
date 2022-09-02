//por Argéu Venturini e Arthur Scalon

#include <iostream>
using namespace std;


class Fracao {
    private:
        int numerador;
        int denominador;
    public:
        Fracao();
        Fracao(int, int);
        int pegaNum();
        int pegaDenom();
        friend Fracao operator + (Fracao&, Fracao&);
        friend Fracao operator - (Fracao&, Fracao&);
        void mostra();
};

//construtores
Fracao::Fracao(){
    this->numerador = 0;
    this->denominador = 1;
}

Fracao::Fracao(int n, int d){
    this->numerador = n;
    this->denominador = d;
}

//Outras funções

int Fracao::pegaNum(){
    return this->numerador;
}

int Fracao::pegaDenom(){
    return this->denominador;
}

Fracao operator + (Fracao& operando1, Fracao& operando2){
Fracao aux;
int newDenom = operando1.pegaDenom() * operando2.pegaDenom();
int newNumer = (newDenom/operando1.pegaDenom() * operando1.pegaNum()) + (newDenom/operando2.pegaDenom() * operando2.pegaNum());
aux.numerador = newNumer;
aux.denominador = newDenom;

return aux;
}

Fracao operator - (Fracao& operando1, Fracao& operando2){
Fracao aux;
int newDenom = operando1.pegaDenom() * operando2.pegaDenom();
int newNumer = (newDenom/operando1.pegaDenom() * operando1.pegaNum()) - (newDenom/operando2.pegaDenom() * operando2.pegaNum());
aux.numerador = newNumer;
aux.denominador = newDenom;
return aux;
}

void Fracao::mostra(){
    cout << this->numerador << "/" << this->denominador << endl;
}

int main () {
    int lerNumerador, lerDenominador;

    Fracao A(1,2);

    cout << "Digite o numerador da fracao: ";
    cin >> lerNumerador;

    cout << "Digite o denominador da fracao: ";
    cin >> lerDenominador;

    Fracao B(lerNumerador, lerDenominador);
    Fracao C;

    cout << A.pegaNum() << endl;
    cout << A.pegaDenom() << endl;
    cout << "A primeira fracao vale: ";
    A.mostra();
    cout << "A segunda fracao vale: ";
    B.mostra();
    cout << "Somando as duas: ";
    C = A + B;
    C.mostra();
    cout << "Subtraindo as duas: ";
    C = A - B;
    C.mostra();


  return 0;
}
