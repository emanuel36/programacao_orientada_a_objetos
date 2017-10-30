#include <iostream>
#include <vector>
using namespace std;

template <class T>
T read(){
    T t;
    cin >> t;
    return t;
}

struct Operacao{
    string operacao;
    float valor;

    Operacao(string operacao = "", float valor = 0){
        this->operacao = operacao;
        this->valor = valor;
    }
};

class Conta{
private:
    int id;
    float saldo{0};
    vector<Operacao> extrato;

public:
    Conta(int id = 0){
        this->id = id;
    }

    float getSaldo(){
        return this->saldo;
    }

    vector<Operacao> getExtrato(){
        return this->extrato;
    }

    bool saque(int valor){
        if(valor <= 0){
            return false;
        }
        this->saldo -= valor;
    }

    bool deposito(int valor){
        if(valor <= 0){
            return false;
        }
        this->saldo = valor;
        return true;
    }
};

int main(){
    Conta contaEmanuel;
    string op;
    while(op != "sair"){
        cin >> op;

        if(op == "saldo"){
            cout << contaEmanuel.getSaldo() << endl;

        }else if(op == "extrato"){
            for(auto aux : contaEmanuel.getExtrato()){
                cout << aux.operacao << " " << aux.valor << endl;
            }

        }else if(op == "saque"){
            cout << (contaEmanuel.saque(read<int>()) ? "Feito" : "Saldo Insuficiente");

        }else if(op == "deposito"){
            cout << (contaEmanuel.deposito(read<int>()) ? "Feito" : "Valor Inválido");
        }
    }

    return 0;
}
