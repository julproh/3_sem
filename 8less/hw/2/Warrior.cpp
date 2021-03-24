#include "Warrior.h"

Warrior::Warrior():hp(100), damage(100){};

Warrior::Warrior(int _hp, int _damage): hp(_hp), damage(_damage){};

int Warrior::get_hp() {
    return hp;
}

int Warrior::get_damage() {
    return damage;
}

void Warrior::set_hp (int _hp) {
    hp = _hp;
}

void Warrior::strike(Warrior& target) {
    target.set_hp(target.get_hp() - get_damage()); 
};

Knight::Knight(int _hp, int _damage): Warrior(_hp, _damage) {};

Warrior*  KnightFactory::create() const {
        return new Knight;
    }

Mage::Mage(int _hp, int _damage): Warrior(_hp, _damage) {};


Warrior*  MageFactory::create() const {
        return new Mage;
    }

Archer::Archer(int _hp, int _damage): Warrior(_hp, _damage) {};

Warrior*  ArcherFactory::create() const {
        return new Archer;
    }
