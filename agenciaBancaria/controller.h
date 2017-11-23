#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include <sstream>
#include "agencia.h"
#include "split.h"

using namespace std;

Agencia agencia;

class Controller{

public:
    string process(string line){
        Cliente* cliente;
        auto ui = split(line);
        auto cmd = ui[0];

        if(cmd == "help"){
            return  "addCliente    _idCliente\n"
                    "showClientes\n"
                    "abrirConta    _idCliente\n"
                    "encerrarConta _idCliente _idConta\n"

                    "# Login e logout\n"
                    "login    _idCliente\n"
                    "logout\n"

                    "# Exige login\n"
                    "show\n"
                    "saldo    _idConta\n"
                    "extrato  _idConta\n"
                    "saque    _idConta _valor\n"
                    "deposito _idConta _valor\n"
                    "transf   _idConta _idContaDestino _valor\n";
        }
        else if(cmd == "addCliente"){
            agencia.addCliente(ui[1]);
            return "Done";
        }

        else if(cmd == "showAll"){
            return agencia.getClientes();
        }

        else if(cmd == "abrirConta"){
            agencia.abrirConta(ui[1]);
            return "Done";
        }

        else if(cmd == "login"){
            cliente = agencia.getCliente(ui[1]);
            if(cliente == nullptr){
                throw string("erro | cliente não exixte");
            }
        }

        else if(cmd == "logout"){
            if(cliente == nullptr){
                throw string ("erro | nenhum cliente logado");
            }
            cliente = nullptr;
            return "Done";
        }

        else if(cmd == "show"){
            if(cliente != nullptr){
                return cliente->getCliente();
            }
            throw string ("erro | nenhum cliente logado");
        }

        else if(cmd == "saldo"){
            if(cliente == nullptr){
                throw string ("erro | nenhum cliente logado");
            }
            Conta * conta;
            conta = cliente->buscaConta(stoi(ui[1]));
            cout << conta->saldo;
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
