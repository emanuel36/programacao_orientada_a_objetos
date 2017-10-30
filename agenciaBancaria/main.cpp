#include <iostream>
#include <vector>

#define MAX_CONTAS 3

using namespace std;

template <class T>
T read(){
    T t;
    cin >> t;
    return t;
}

int contador = 0;

struct Operacao{
    string operacao;
    float valor;
    float saldoParcial;

    Operacao(string operacao = "", float valor = 0, float saldoParcial = 0){
        this->operacao = operacao;
        this->valor = valor;
        this->saldoParcial = saldoParcial;
    }
};

class Agencia{
public:
    vector<Cliente> clientes;

    Agencia(){
    }

    bool addCliente(string cpf){
        for(auto temp : clientes){
            if(cpf == temp.cpf){
                return false;
            }
        }
        clientes.push_back(Cliente(cpf));
        return true;
    }

    bool abrirConta(string cpf){
        for(auto &temp : clientes){
            if(temp.cpf == cpf){
                temp.addConta();
                return true;
            }
        }
        return false;
    }
};

class Cliente{
public:
    string cpf;
    vector<Conta> contas;

    Cliente(string cpf = " "){
        this->cpf = cpf;
    }

    bool addConta(){
        if(contas.size() > MAX_CONTAS){
            return false;
        }
        Conta conta;
        conta.id = contador++;
        conta.ativa = true;
        contas.push_back(conta);
        return true;

    }

    bool encerrarConta(int id){
        int i = 0;
        for(auto temp : contas){
            if(temp.id == id){
                contas.erase(contas.begin() + i);
                return true;
            }
            i++;
        }
        return false;
    }
};

class Conta{
public:
    int id{0};
    float saldo{0};
    vector<Operacao> extrato;
    bool ativa{0};

    Conta(){
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
        return true;
    }

    bool deposito(int valor){
        if(valor <= 0){
            return false;
        }
        this->saldo = valor;
        return true;
    }

    bool transferencia(int id){

    }
};

int main(){

    return 0;
}
