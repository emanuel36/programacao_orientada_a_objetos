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
                   "  addSala  _capacidade _3d?                  \n"
                   "  addFilme _nome _duração(min) _3d?          \n"
                   "  addSessao _filme _hora _sala               \n"
                   "  showSessoes                                \n"
                   "  showFilmes                                 \n"
                   "  showSalas                                  \n"
                   "  vender _cpf _sessao                        \n"
                   "  search _filme                              \n"
                   "  search _hora                               \n"
                   "  finalizar _sessao                        \n\n"

                   "  showSessao _sessao                         \n"
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
            cinema.addSala(Sala(stoi(ui[1]), stoi(ui[2])));
            return "done";
        }

        else if(cmd == "addFilme"){
            if(ui.size() != 4){
                return "erro | comando inválido!";
            }
            cinema.addFilme(Filme(ui[1], stoi(ui[2]), stoi(ui[3])));
            return "done";
        }

        else if(cmd == "addSessao"){
            if(ui.size() != 4){
                return "erro | comando inválido!";
            }
            cinema.addSessao(ui[1], Sessao(ui[2]), stoi(ui[3]));
            return "done";
        }

        else if(cmd == "finalizar"){
            if(ui.size() != 2){
                return "erro | comando inválido!";
            }
            cinema.finalizarSessao(stoi(ui[1]));
            return "done";
        }

        else if(cmd == "showSessao"){
            if(ui.size() != 2){
                return "erro | comando inválido!";
            }
            return cinema.showSessao(stoi(ui[1]));
        }

        else if(cmd == "showFilmes"){
            if(ui.size() != 1){
                return "erro | comando inválido!";
            }
            return cinema.showFilmes();
        }

        else if(cmd == "showSalas"){
            if(ui.size() != 1){
                return "erro | comando inválido!";
            }
            return cinema.showSalas();
        }

        else if(cmd == "search"){
            if(ui.size() != 2){
                return "erro | comando inválido!";
            }
            return cinema.search(ui[1]);
        }

        else if(cmd == "vender"){
            if(ui.size() != 3){
                return "erro | comando inválido!";
            }
            Cliente* cli = registro.search(ui[1]);
            if(cli != nullptr){
                cinema.vender(cli, stoi(ui[2]));
                return "done";
            }
            throw string("erro | cliente não cadastrado");
        }

        else if(cmd == "showSessoes"){
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
