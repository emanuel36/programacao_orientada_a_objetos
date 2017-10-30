#include <iostream>
#include <vector>
#include <iostream>
#include <sstream>
#include "split.h"

using namespace std;

class Passageiro{
public:
    string cpf;

    Passageiro(string cpf){
        this->cpf = cpf;
    }
};

class Registro{
public:
    vector<Passageiro> cadastro;

    Registro(){

    }

    Passageiro* search(string cpf){
        for(auto &elem: cadastro){
            if(elem.cpf == cpf){
                return &elem;
            }
        }
        return nullptr;
    }

    bool cadastrar(Passageiro pass){
        for(auto elem: cadastro){
            if(elem.cpf == pass.cpf){
                return false;
            }
        }
        cadastro.push_back(pass);
        return true;
    }

    string getCadastro(){
        stringstream ss;
        for(auto elem: cadastro){
            ss << "[" << elem.cpf << "]" << endl;
        }
        return ss.str();
    }
};

class Vagao{
public:
    vector<Passageiro*> cadeiras;
    int capacidade;

    Vagao(int capacidade = 20){
        this->capacidade = capacidade;

        for(int i = 0; i < capacidade; i++){
            cadeiras.push_back(nullptr);
        }
    }

    bool embarcar(Passageiro* pass){
        for(auto elem: cadeiras){
            if(elem != nullptr){
                if(elem->cpf == pass->cpf){
                    throw string("erro | passageiro já embarcado");
                }
            }
        }
        for(int i = 0; i < capacidade; i++){
            if(cadeiras[i] == nullptr){
                cadeiras[i] = pass;
                return true;
            }
        }
        return false;
    }

    bool desembarcar(string cpf){
        for(auto &elem: cadeiras){
            if(elem != nullptr){
                if(elem->cpf == cpf){
                    elem = nullptr;
                    return true;
                }
            }
        }
        return false;
    }

    string search(string cpf){
        stringstream ss;
        int i = 0;
        for(auto elem: cadeiras){
            if(elem != nullptr){
                if(elem->cpf == cpf){
                    ss << "[Cadeira " << i << "]: " << elem->cpf << endl;
                    return ss.str();
                }
            }
            i++;
        }
        return "404";
    }

    string toString(){
        stringstream ss;
        int i = 0;
        for(auto elem: cadeiras){
            if(elem != nullptr){
                ss << "[Cadeira " << i++ << "]: " << elem->cpf << endl;
            }else{
                ss << "[Cadeira " << i++ << "]: " << "Vazio" << endl;
            }
        }
        return ss.str();
    }
};

class Trem{
public:
    int maxVagoes;
    vector<Vagao> vagoes;

    Trem(int maxVagoes = 5){
        this->maxVagoes = maxVagoes;
    }

    void addVagao(Vagao vagao){
        if(vagoes.size() == maxVagoes){
            throw string("erro | capacidade de vagões excedida");
        }
        vagoes.push_back(vagao);
    }

    void embarcar(Passageiro *pass){
        for(auto &elem: vagoes){
            if(elem.embarcar(pass)){
                return;
            }
        }
        throw string("erro | trem lotado até a tampa");
    }

    void desembarcar(string cpf){
        for(auto &elem: vagoes){
            if(elem.desembarcar(cpf)){
                return;
            }
        }
        throw string("erro | passageiro não embarcado");
    }

    string search(string cpf){
        stringstream ss;
        int i = 0;
        for(auto elem: vagoes){
            string temp = elem.search(cpf);
            if(temp != "404"){
                ss << "### Vagão " << i << " ###" << endl;
                ss << temp;
                return ss.str();
            }
            i++;
        }
        return "erro | passageiro não embarcado";
    }

    string toString(){
        stringstream ss;
        int i = 0;
        for(auto &elem: vagoes){
            ss << endl << "### Vagão " << i++ << " ###" << endl;
            ss << elem.toString();
        }
        return ss.str();
    }

};

class Controller{
    Trem trem;
    Registro registro;
public:
    string process(string line){
        auto ui = split(line);
        auto cmd = ui[0];

        if(cmd == "help"){
            return "  # Comandos - Cadastro                      \n"
                   "  getCadastro                                \n"
                   "  cadastrarPass _cpf                       \n\n"
                   "  # Comandos - Trem                          \n"
                   "  addVagao _capacidade                       \n"
                   "  embarcar _cpf                              \n"
                   "  desembarcar _cpf                           \n"
                   "  search _cpf                              \n\n"
                   "  # default                                  \n"
                   "  fim                                        \n"
                   "  help                                       \n";
        }
        else if(cmd == "cadastrar"){    //OK
            if(registro.cadastrar(Passageiro(ui[1]))){
                return "done";
            }
            throw string("erro | usuário já cadastrado!");
        }

        else if(cmd == "getCadastro"){
            return registro.getCadastro();
        }

        else if(cmd == "addVagao"){
            trem.addVagao(Vagao(stoi(ui[1])));
            return "done";
        }

        else if(cmd == "embarcar"){
            Passageiro* pass = registro.search(ui[1]);
            if(pass != nullptr){
                trem.embarcar(pass);
                return "done";
            }
            throw string("erro | pasageiro não cadastrado");
        }

        else if(cmd == "desembarcar"){
            trem.desembarcar(ui[1]);
            return "done";
        }

        else if(cmd == "search"){
            return trem.search(ui[1]);
        }

        else if(cmd == "show"){
            return trem.toString();
        }

        else{
            return "erro | comando inválido!";
        }

    }

    void commandLine() {
        string line = "";
        while(line != "fim"){
            cout << "(help): ";
            getline(cin, line);
            if(line == "")
                continue;
            cout << ">> " << line << endl;
            try {
                cout << process(line) << endl;
            } catch(const string& e) {
                cout << e << endl;
            }
        }
    }
};

int main(){
    Controller c;
    c.commandLine();
    return 0;
}
