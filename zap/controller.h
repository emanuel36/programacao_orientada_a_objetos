#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include <sstream>
#include "poo.h"

using namespace std;

class Controller{
    string process(string line){
        auto ui = split(line);
        auto cmd = ui[0];

        if(cmd == "help"){
            return "  ";
        }

        else if(cmd == ""){

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
