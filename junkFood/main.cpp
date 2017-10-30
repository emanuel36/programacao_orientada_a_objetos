#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

template <class T>
T read(){
    T t;
    cin >> t;
    return t;
}

struct Espiral{
    string nome;
    int qtd;
    float valor;

    Espiral(string nome = "", int qtd = 0, float valor = 0){
        this->nome = nome;
        this->qtd = qtd;
        this->valor = valor;
    }
};

class Maquina{
public:
    vector<Espiral> espirais;
    float saldoCliente{0};
    float lucro{0};

    Maquina(int qtd, int tam){
        for(int i = 0; i < qtd; i++){
            espirais.push_back(Espiral());
            espirais[i].qtd = tam;
        }
    }

    void recebeDinheiro(float valor){
        this->saldoCliente += valor;
    }

    float getSaldo(){
        return this->saldoCliente;
    }

    void devolverTroco(){
        saldoCliente = 0;
    }

    bool alterarEspiral(int indice, string nome, int valor){
        if(indice >= espirais.size())   return false;
        espirais[indice].nome = nome;;
        espirais[indice].valor = valor;
        return true;
    }

    int vender(int indice){
        if(indice >= espirais.size())                return 3;
        if(espirais[indice].qtd <= 0)               return 1;
        if(saldoCliente < espirais[indice].valor)  return 2;
        saldoCliente -= espirais[indice].valor;
        lucro += espirais[indice].valor;
        espirais[indice].qtd--;
        return 4;
    }

    string mostrarStatus(){
        stringstream ss;
        for(auto espira : this->espirais){
            ss << "Nome: " << espira.nome << endl
               << "Valor: " << espira.valor << endl
               << "Quantidade: " << espira.qtd << endl << endl;
        }
        ss << "Lucro: " << lucro << endl << endl;
        return ss.str();
    }
};

void iniciarEspirais(Maquina& maquina){
    maquina.alterarEspiral(0, "batata", 3);
    maquina.alterarEspiral(1, "refrigerante", 1.5);
    maquina.alterarEspiral(2, "chocolate", 4);
}

void interacaoUser(Maquina& maquina){
    string op;

    iniciarEspirais(maquina);

    while(op != "sair"){
        cin >> op;
        if(op == "ajuda"){
            cout << "inserir _valor" << endl
                 << "saldo" << endl
                 << "troco" << endl
                 << "alterar _indice _nome _valor" << endl
                 << "comprar _indice" << endl
                 << "status" << endl << endl;
        }
        else if(op == "inserir"){
            maquina.recebeDinheiro(read<int>());
            cout << "Dinheiro adicionado!" << endl << endl;
        }
        else if(op == "saldo"){
            cout << "Saldo: " << maquina.saldoCliente << endl << endl;
        }
        else if(op == "troco"){
            cout << "Você retirou: " << maquina.getSaldo() << endl << endl;
            maquina.devolverTroco();
        }
        else if(op == "alterar"){
            int indice;
            float valor;
            string nome;

            cin >> indice;
            cin >> valor;
            getline(cin, nome);

            if(maquina.alterarEspiral(indice, nome, valor)){
                cout << "Espiral alterada";
            }else{
                cout << "Espira não existe";
            }
        }
        else if(op == "comprar"){
            int ret = maquina.vender(read<int>());
            if(ret == 4){
                cout << "Produto comprado" << endl << endl;
            }else if(ret == 3){
                cout << "Produto não existe!" << endl << endl;
            }else if(ret == 2){
                cout << "Saldo insuficiente!" << endl << endl;
            }else{
                cout << "Produto esgotado!" << endl << endl;
            }
        }
        else if(op == "status"){
            cout << maquina.mostrarStatus();
        }
        else{
            cout << "comando inválido" << endl << endl;
        }
    }
}

int main(){
    Maquina maquina(10, 5);
    interacaoUser(maquina);
    return 0;
}
