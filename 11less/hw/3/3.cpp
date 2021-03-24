#include <iostream>
#include <vector>
#include "Warrior.h"

using namespace std;

int main () {

    WarriorFactory *knight_factory = new KnightFactory;
    WarriorFactory *mage_factory = new MageFactory;
    WarriorFactory *archer_factory = new ArcherFactory;



    vector <Warrior*> warriors;

    warriors.push_back(knight_factory -> create(12,34));
    warriors.push_back(mage_factory -> create(342, 65));
    warriors.push_back(archer_factory -> create());

     Warrior *m_1 = warriors[1];
    // (*m_1).set_hp(250);

    // Warrior *w_1 = warriors[0];
     Warrior *w_2 = warriors[1];

    cout << "Mage: " << endl << "hp: " << (*w_2).get_hp() << endl << "damage: " << (*w_2).get_damage() << endl;
    
    // (*w_1).strike(*w_2);

    // cout << "After fight with a knight" << endl << "Mage: " << endl << "hp: " << (*w_2).get_hp() 
    // << endl << "damage: " << (*w_2).get_damage() << endl;

    //Knight k(350, 50);

    //cout << "Knight: " << endl << "hp: " << k.get_hp() << endl << "damage: " << k.get_damage() << endl;

    //Mage m(100, 0);

    // m.set_spell(new Fireball);

    // m.strike(k);
    // cout << "Knight after fight with mage: " << endl << "hp: " << k.get_hp() << endl << "damage: " << k.get_damage() << endl;

   // Mage m_2(100, 0);
    // m_2.set_spell(new LightingBolt);

    // m_2.strike(k);
    // cout << "Knight after fight with mage: " << endl << "hp: " << k.get_hp() << endl << "damage: " << k.get_damage() << endl;

    return 0;
}