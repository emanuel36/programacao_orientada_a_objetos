#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include <sstream>
#include "split.h"

using namespace std;

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
                   "  cadastrar _cpf                       \n\n"
                   "  # Comandos - Trem                          \n"
                   "  addVagao _capacidade                       \n"
                   "  embarcar _cpf                              \n"
                   "  desembarcar _cpf                           \n"
                   "  search _cpf                              \n\n"
                   "  # default                                  \n"
                   "  fim                                        \n"
                   "  help                                       \n";
        }
        else if(cmd == "cadastrar"){
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


#endif // CONTROLLER_H
