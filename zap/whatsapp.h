#ifndef WHATSAPP_H
#define WHATSAPP_H

#include <iostream>
#include <map>
#include <list>

using namespace std;

struct Zap{
    string userId;
    string msg;
};

class User{
public:
    string id;
    map<string, Chat*> lista_chat;

    string getChats(){
        stringstream ss;
        ss << "### CHATS ###" << endl;
        for(auto par: lista_chat){
            ss << "[" << par.second->chatId << "]" << endl;
        }
        return ss.str();
    }

};

class Registro{
public:
    User * user;
};

class Chat{
    string chatId;
    list<Zap*> lista_zap;
    map<string, Registro> lista_reg;


};



#endif // WHATSAPP_H
