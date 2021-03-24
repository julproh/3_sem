#include <iostream>
#include <vector>
#include "Warrior.h"

using namespace std;

int main () {

    WarriorFactory *knight_factory = new KnightFactory;
    WarriorFactory *mage_factory = new MageFactory;
    WarriorFactory *archer_factory = new ArcherFactory;



    vector <Warrior*> warriors;

    warriors.push_back(knight_factory -> create());
    warriors.push_back(mage_factory -> create());
    warriors.push_back(archer_factory -> create());

    Warrior *m_1 = warriors[1];
    (*m_1).set_hp(250);

    Warrior *w_1 = warriors[0];
    Warrior *w_2 = warriors[1];

    cout << "Mage: " << endl << "hp: " << (*w_2).get_hp() << endl << "damage: " << (*w_2).get_damage() << endl;
    
    (*w_1).strike(*w_2);

    cout << "After fight with a knight" << endl << "Mage: " << endl << "hp: " << (*w_2).get_hp() 
    << endl << "damage: " << (*w_2).get_damage() << endl;

    return 0;
}