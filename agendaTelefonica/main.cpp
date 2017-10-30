#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

template <class T>
T read(){
    T t;
    cin >> t;
    return t;
}


class Fone {
public:
    string foneId;
    string numero;

    Fone(string id = "Celular", string numero = ""){
        foneId = id;
        this->numero = numero;
    }

    static bool validate(string numero) {
        string data = "1234567890()- ";
        for(auto c : numero)
            if(data.find(c) == string::npos)
                return false;
        return true;
    }
};

class Contato {
public:
    string nome;
    vector<Fone> fones;
    bool favorited{false};

    Contato(string nome = ""){
        this->nome = nome;
    }

    string getNome(){
        return this->nome;
    }

    bool addFone(Fone fone){
        if(!fone.validate(fone.numero)){
            return false;
        }
        this->fones.push_back(fone);
        return true;
    }

    bool rmFone(string foneId){
        for(int i = 0; i < fones.size(); i++){
            if(fones[i].foneId == foneId){
                fones.erase(fones.begin() + i);
                return true;
            }
        }
        return false;
    }

    vector<Fone> getAllFones(){
        return this->fones;
    }

    bool isFavorited(){
        return this->favorited;
    }

    void setFavorited(bool value){
        this->favorited = value;
    }

    string toString(){
        stringstream ss;
        ss << "Nome: " << this->nome << endl;

        for(auto temp : fones){
            ss << temp.foneId << ": " << temp.numero << endl;
        }
        return ss.str();
    }
};

class Agenda {
public:
    map<string, Contato> contatos;
    map<string, Contato*> favoritos;

    Agenda(){

    }
    bool addContato(Contato cont){
        return contatos.insert(make_pair(cont.getNome(), cont)).second;
    }

    bool rmContato(string nome) {
        if(contatos.erase(nome)){
            favoritos.erase(nome);
            return true;
        }
        return false;
    }

    Contato * getContato(string nome){
        auto it = contatos.find(nome);
        return (it != contatos.end()) ? (&it->second) : nullptr;
    }

    bool favoritar(string nome) {
        Contato * contato = getContato(nome);
        if(!contato || contato->isFavorited())
            return false;
        contato->setFavorited(true);
        favoritos[nome] = contato;
        return true;
    }

    bool desfavoritar(string nome){
        auto contato = getContato(nome);
        if(contato && contato->isFavorited()){
            contato->setFavorited(false);
            favoritos.erase(nome);
            return true;
        }
        return false;
    }

    vector<Contato> getFavoritos(){
        vector<Contato> resp;
        for(auto par : favoritos)
            resp.push_back(*par.second);
        return resp;
    }

    vector<Contato> patternSearch(string pattern){
        vector<Contato> resp;
        for(auto par : contatos)
            if(par.second.toString().find(pattern) != string::npos)
                resp.push_back(par.second);
        return resp;
    }
};

class Controller {
    Agenda agenda;
public:
    void commandLine(){
        string op;
        cout << "Agenda: ";
        cin >> op;

        if(op == "addContato"){
            cout << "Nome: ";
            if(!(agenda.addContato(Contato(read<string>())))){
                cout << "Contato já existe!" << endl;
            }else{
                cout << "Contato adicionado" << endl;
            }
        }

        else if(op == "addFone"){
            Fone newFone;
            cout << "Nome: ";
            string nome = read<string>();

            auto it = agenda.contatos.find(nome);
            if(it != agenda.contatos.end()){
                string fone;
                string foneId;
                cout << "Fone: ";
                cin >> fone;
                cout << "FoneID: ";
                cin >> foneId;
                newFone.numero = fone;
                newFone.foneId = foneId;
                if(!it->second.addFone(newFone)){
                    cout << "Fone inválido!" << endl;
                }else{
                    cout << "Fone adicionado!" << endl;
                }
            }else{
                cout << "Contato não existe" << endl;
            }
        }

        //erro
        else if(op == "showAllfav"){
            vector<Contato> fav;
            fav = agenda.getFavoritos();
            for(int i = 0; i < fav.size(); i++){
                cout << fav[i].toString();
            }

        }

        else if(op == "rmFone"){
            cout << "Nome: ";
            auto it = agenda.contatos.find(read<string>());
            if(it != agenda.contatos.end()){
                cout << "FoneId: ";
                if(!it->second.rmFone(read<string>())){
                    cout << "Fone não existe!" << endl;
                }else{
                    cout << "Fone removido!" << endl;
                }
            }else{
                cout << "Contato não existe" << endl;
            }
        }

        else if(op == "rmContato"){
            cout << "Nome: ";
            if(agenda.rmContato(read<string>())){
                cout << "Contato removido!" << endl;
            }else{
                cout << "Contato não existe!" << endl;
            }
        }

        else if(op == "buscarContato"){
            cout << "Busca: ";
            vector <Contato> resultado;
            resultado = agenda.patternSearch(read<string>());
            for(auto temp : resultado){
                cout << temp.toString();
            }
        }

        else if(op == "favoritarContato"){
            cout << "Nome: ";
            if(agenda.favoritar(read<string>())){
                cout << "Contado favoritado!" << endl;
            }else{
                cout << "Contato não existe ou já é favorito!" << endl;
            }
        }

        else if(op == "desfavoritarContato"){
            cout << "Nome: ";
            if(agenda.desfavoritar(read<string>())){
                cout << "Contato desfavoritado!" << endl;
            }else{
                cout << "Contato não existe ou não é favorito!" << endl;
            }
        }
        else{
            cout << "Comandos" << endl
                 << "   addContato $nome" << endl
                 << "   addFone $nome $numero $numeroId" << endl
                 << "   rmFone $nome" << endl
                 << "   rmContato $nome" << endl
                 << "   buscarContato $nome" << endl
                 << "   favoritarContato $nome" << endl
                 << "   desfavoritarContato $nome" << endl
                 << "   showAllfav" << endl;
        }
    }
};

int main(){
    Controller control;
    cout << "Comandos" << endl
         << "   addContato $nome" << endl
         << "   addFone $nome $numero $numeroId" << endl
         << "   rmFone $nome" << endl
         << "   rmContato $nome" << endl
         << "   buscarContato $nome" << endl
         << "   favoritarContato $nome" << endl
         << "   desfavoritarContato $nome" << endl
         << "   showAllfav" << endl;
    do{
        control.commandLine();
    }
    while(true);
}
