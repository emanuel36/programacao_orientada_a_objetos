#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

enum Movimentacao{
    pagar,
    solicitar
};

template <class T>
T read(){
    T t;
    cin >> t;
    return t;
}

struct Transacao{
    Movimentacao mov;
    float valor;
    int id;
    string nome;
};

class Sistema{
public:
    int nextId{1};
    vector<Transacao> transacoes;
    float balanco{0};
    vector<string> clientes;
    Sistema(float balanco = 0.0f){
        this->balanco = balanco;
    }

    void addTran(string nome, float valor){
        bool aux = false;
        for(auto temp : clientes){
            if(temp == nome) aux = true;
        }
        if(aux == false) clientes.push_back(nome);
        if((valor*-1) > this->balanco){
            cout << "Dinheiro insuficiente !!!" << endl;
            return;
        }
        //Empréstimo
        if(valor < 0){
            Transacao tran;
            tran.nome = nome;
            tran.valor = valor;
            tran.id = this->nextId;
            tran.mov = solicitar;

            transacoes.push_back(tran);
            balanco += valor;

        //Pagamento
        }else if(valor >= 0){
            balanco += valor;

            Transacao tran;
            tran.nome = nome;
            tran.valor = valor;
            tran.id = this->nextId;
            tran.mov = pagar;
            transacoes.push_back(tran);
        }
        nextId++;
    }

    bool rmTran(int id){
        int i = 0;
        for(auto temp : transacoes){
            if(id == temp.id){
                transacoes.erase(transacoes.begin() + i);
                return true;
            }
            i++;
        }
        return false;
    }

    string mostrarTran(){
        stringstream ss;
        for(auto temp : transacoes){
            ss << "[" <<temp.id << "]" << " " << temp.nome << " " << temp.valor << endl;
        }
        return ss.str();
    }

    string mostrarClientes(string nome){
        bool aux = false;
        for(auto temp : clientes){
            if(temp == nome) aux = true;
        }

        stringstream ss;
        if(aux == true){
            for(auto temp : transacoes){
                if(nome == temp.nome){
                    ss << "[" <<temp.id << "]" << " " << temp.nome << " " << temp.valor << endl;            }
            }
            return ss.str();
        }
        return "Cliente nao encontrado.";

    }

    int contarClientes(){
        return clientes.size();
    }

    float getBalanco(){
        return this->balanco;
    }

};
void interacaoUsuario(Sistema &sistema){
    string op;

    while(op != "fim"){
        cout << "Digite o comando ou help: ";
        cin >> op;

        if(op == "help"){
            cout << "iniciar $valor" << endl
                 << "balanco" << endl
                 << "addTran $nome $valor" << endl
                 << "showCli $nome" << endl
                 << "contarCli" << endl
                 << "rmTran $id" << endl
                 << "showTran" << endl;
        }
        else if(op == "iniciar"){
            sistema = Sistema(read<float>());
        }
        else if(op == "balanco") cout << "O sistema tem R$" << sistema.getBalanco() << endl;

        else if(op == "addTran"){
            string nome;
            cin >> nome;
                sistema.addTran(nome, read<float>());
            }
        else if(op == "showCli"){
            cout << sistema.mostrarClientes(read<string>()) << endl;
        }
        else if(op == "contarCli") cout << "O sistema tem "<< sistema.contarClientes() << " clientes" << endl;
        else if(op == "rmTran") cout << (sistema.rmTran(read<int>())? "Transacao removida" : "Id nao existente") << endl;
        else if(op == "showTran") cout << sistema.mostrarTran();
        else cout << "Comando invalido" << endl;
    }

}
int main(){
    Sistema sistema;

    interacaoUsuario(sistema);
    return 0;
}
