#ifndef USER_H
#define USER_H
#include "Repository.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <list>
using namespace std;

class Tweet;

class User{
    string username;
    list<User*> seguidores;
    list<User*> seguidos;
    list<Tweet*> myTweets;
    list<Tweet*> timeLine;
    int unreadCount{0};
    int nextTwId{0};

public:
    User(string _username = ""){
        this->username = _username;
    }
    string getUserName(){
        return this->username;
    }

    list<User*> getSeguidores(){
        return this->seguidores;
    }

    list<User*> getSeguidos(){
        return this->seguidos;
    }

    list<Tweet*> getMyTweets(){
        return this->myTweets;
    }

    list<Tweet*> getTimeLine(){
        return this->timeLine;
    }


    void seguir(User *other){
        for(auto elem : seguidos){
            if(elem->username == other->getUserName()) return;
        }

        seguidos.push_back(other);
        other->addSeguidor(this);
    }
    int getUnread(){
        return unreadCount;
    }
    void twittar(Tweet * tw){
        myTweets.push_front(tw);
        for(User * usr : seguidores){
            usr->plusUnreadCount();
            usr->timeLine.push_front(tw);
        }

    }

    list<Tweet*> unread(){
        cout << "Estou no getUnread!\n";
        list<Tweet*> naoLidos;

        int cont = 0;

        for(auto itw = getTimeLine().begin(); cont < unreadCount; cont++){
            cout << unreadCount << endl;
            cout << cont << endl;
            cout << cont << " n lido\n";
            naoLidos.push_back(*itw);
            itw++;
        }

        cout << "Peguei os Unread! \n";
        unreadCount = 0;
        return naoLidos;
    }
    void setUnread(int unread){
        this->unreadCount = unread;
    }
    void addSeguidor(User *value){
        seguidores.push_back(value);
    }
    void plusUnreadCount(){
        unreadCount += 1;
    }
};

#endif // USER_H
