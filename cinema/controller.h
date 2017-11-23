#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include <sstream>
#include "split.h"
#include "cinema.h"
#include "registro.h"

using namespace std;

class Controller{
    Cinema cinema;
    Registro registro;
public:
    string process(string line){
        auto ui = split(line);
        auto cmd = ui[0];

        if(cmd == "help"){
            return "  # Comandos - Cadastro                      \n"
                   "  getCadastro                                \n"
                   "  cadastrar _cpf                           \n\n"
                   "  # Comandos - Cinema                        \n"
                   "  addSala _filme _hora                       \n"
                   "  finalizar _sala                            \n"
                   "  comprar _cpf _sala                         \n"
                   "  searchFilme _filme                         \n"
                   "  searchSecao _hora                        \n\n"
                   "  # default                                  \n"
                   "  fim                                        \n"
                   "  help                                       \n";
        }
        else if(cmd == "cadastrar"){
            if(ui.size() != 2){
                return "erro | comando inválido!";
            }
            if(registro.cadastrar(Cliente(ui[1]))){
                return "done";
            }
            throw string("erro | usuário já cadastrado!");
        }

        else if(cmd == "getCadastro"){
            if(ui.size() != 1){
                return "erro | comando inválido!";
            }
            return registro.getCadastro();
        }

        else if(cmd == "addSala"){
            if(ui.size() != 3){
                return "erro | comando inválido!";
            }
            cinema.addSala(Sala(ui[1], ui[2]));
            return "done";
        }

        else if(cmd == "finalizar"){
            if(ui.size() != 2){
                return "erro | comando inválido!";
            }
            cinema.finalizarSecao(stoi(ui[1]));
            return "done";
        }

        else if(cmd == "searchSecao"){
            if(ui.size() != 2){
                return "erro | comando inválido!";
            }
            return cinema.searchSecao(ui[1]);
        }

        else if(cmd == "searchFilme"){
            if(ui.size() != 2){
                return "erro | comando inválido!";
            }
            return cinema.searchFilme(ui[1]);
        }

        else if(cmd == "comprar"){
            if(ui.size() != 3){
                return "erro | comando inválido!";
            }
            Cliente* cli = registro.search(ui[1]);
            if(cli != nullptr){
                cinema.comprar(cli, stoi(ui[2]));
                return "done";
            }
            throw string("erro | cliente não cadastrado");
        }

        else if(cmd == "show"){
            if(ui.size() != 1){
                return "erro | comando inválido!";
            }
            return cinema.toString();
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