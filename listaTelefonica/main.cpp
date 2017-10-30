#include <iostream>
#include <vector>

using namespace std;

template <class T>
T read(){
    T t;
    cin >> t;
    return t;
}

struct Telefone{
    string descricao;
    string numero;

    Telefone(string descricao = "Celular", string numero = "XXXX-XXXX"){
        this->descricao = descricao;
        this->numero = numero;
    }
};

class Contato{
public:
    string nome;
    string email;
    vector<Telefone> fones;

    Contato(string nome = "Sem nome", string email = "Vazio"){
        this->nome = nome;
        this->email = email;
    }

    void initContato(){

    }

    void setNome(string nome){
        this->nome = nome;
    }

    void setEmail(string email){
        this->email = email;
    }

    bool addFone(Telefone tel){
        for(auto fone : this->fones){
            if(fone.numero == tel.numero){
                return false;
            }
        }
        this->fones.push_back(tel);
        return true;
    }

    bool rmFone(string numero){
        int i = 0;
        for(auto aux : this->fones){
            if(aux.numero == numero){
                this->fones.erase(fones.begin() + i);
                return true;
            }
            i++;
        }
        return false;
    }

    void showContato(){
        cout << "Nome: " << this->nome << endl;
        cout << "Email: " << this->email << endl;
        for(auto fone : this->fones){
            cout << fone.descricao << ": " << fone.numero << endl;
        }
    }
};

int main(){
    Contato contato;
    string op;

    while(op != "sair"){
        cin >> op;

        if(op == "add"){
            cout << endl << "Descrição: ";
            string descricao = read<string>();
            cout << endl << "Numero: ";
            string numero = read<string>();
            if(contato.addFone(Telefone(descricao, numero))){
                cout << "Telefone Adicionado!" << endl;
            }else{
                cout << "Telefone já está salvo!";
            }

        }else if(op == "rm"){
            cout << endl << "Número: ";
            if(contato.rmFone(read<string>())){
                cout << "Número Removido!" << endl;
            }else{
                cout << "Número inexistente!" << endl;
            }

        }else if(op == "setNome"){
            cout << "Nome: " << endl;
            contato.setNome(read<string>());

        }else if(op == "setEmail"){
            cout << "Email: " << endl;
            contato.setEmail(read<string>());

        }else if(op == "show"){
            contato.showContato();
        }
    }
    return 0;
}
