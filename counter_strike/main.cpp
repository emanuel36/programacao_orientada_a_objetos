#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum Team{Police,
          Terrorist};

enum Body{Head,
          Chest,
          Leg};

struct Gun{
    string name;
    int damage;

    Gun(string name = "", int damage = 0){
        this->name = name;
        this->damage = damage;
    }
};

struct Player{
    string name;
    int life;
    Team team;
    Gun gun;

    Player(string name, Team team, Gun gun){
        this->name = name;
        this->life = 100;
        this->team = team;
        this->gun = gun;
    }

    void shoot(Player &target){
        Body body;
        int num = rand();
        if(num % 100 < 15){
            body = Head;
        }else if(num % 100 < 60){
            body = Chest;
        }else{
            body = Leg;
        }

        switch(body){
            case Head:
                target.life -= (5 * this->gun.damage);
                cout << this->name << " shoot on head of " << target.name << endl
                     << "Caused damage: " << (5 * this->gun.damage) << endl << endl;
            break;

            case Chest:
                target.life -= (2 * this->gun.damage);
                cout << this->name << " shoot on chest of " << target.name << endl
                     << "Caused damage: " << (2 * this->gun.damage) << endl << endl;
            break;

            case Leg:
                target.life -= gun.damage;
                cout << this->name << " shoot on leg of " << target.name << endl
                     << "Caused damage: " << this->gun.damage << endl << endl;
            break;
        }
    }

    void showPlayer(){
        cout << "NOME: " << this->name
             << endl
             << "ARMA: " << this->gun.name
             << endl
             << "VIDA: " << this->life
             << endl << endl;
    }

};

int main(){
    srand(time(NULL));

    Gun *M4A4  = new Gun("M4A4", 22);
    Gun *AK47  = new Gun("AK47", 20);
    Gun *USP   = new Gun("USP", 10);
    Gun *GLOCK = new Gun("GLOCK", 12);

    Player *Emanuel = new Player("emanuel_ap", Police, *M4A4);
    Player *Assis = new Player("skepys", Terrorist, *GLOCK);

    Emanuel->showPlayer();
    Assis->showPlayer();

    while(Emanuel->life > 0 && Assis->life > 0){
        getchar();
        int num = rand();
        if(num % 2){
            Emanuel->shoot(*Assis);
            Assis->showPlayer();
        }else{
            Assis->shoot(*Emanuel);
            Emanuel->showPlayer();
        }
    }

    if(Emanuel->life > 0){
        cout << "Gamer over, " << Emanuel->name << " won!!!" << endl << endl;
    }else{
        cout << "Gamer over, " << Assis->name << " won!!!" << endl << endl;
    }

    return 0;
}
