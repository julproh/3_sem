#ifndef WARRIOR_H
#define WARRIOR_H
#include <iostream>

class Warrior {
    private:
        int hp;
        int damage;
    public:
        void set_hp (int);
        int get_hp ();
        int get_damage();
        Warrior();
        Warrior (int, int);
        virtual ~Warrior(){};
        virtual void strike(Warrior& target);
};

class WarriorFactory {
    public:
        template<typename ...T>
    Warrior* create(T&& ...arg) 
    {
        return new Warrior{std::forward<T>(arg)...};
    }
        Warrior* create() const;
        ~WarriorFactory() = default; 
};

class Knight : public Warrior {
    public:
        Knight(): Warrior(){};
        Knight(int,  int);
        virtual ~Knight() {};
};

class KnightFactory : public WarriorFactory {
    public:
    ~KnightFactory() = default;
    Warrior* create() const;
    // template<typename ...T>
    // Warrior* create(T&& ...arg) 
    // {
    //     return new Knight{std::forward<T>(arg)...};
    // }
};


class Spell {
    public:
        virtual ~Spell() = default;
        virtual int get_Damage(Warrior& target) = 0;

};

class Fireball: public Spell {
    public:
        const int fireball_damage = 80;
        virtual int get_Damage(Warrior& target) override;
};

class LightingBolt: public Spell {
    public:
        const int lightingbolt_damage = 60;
        virtual int get_Damage(Warrior& target) override;
};


class Mage : public Warrior {
    private:
        Spell *spell;
    public:
        Mage() : Warrior (){};
        Mage(int, int);
        void set_spell(Spell* _spell);
        void delete_spell ();
        virtual ~Mage() {};
        virtual void strike(Warrior& target) override;

};

class MageFactory : public WarriorFactory {
    public:
    ~MageFactory() = default;
    Warrior* create() const;
    // template<typename ...T>
    // Warrior* create(T&& ...arg) 
    // {
    //     return new Mage{std::forward<T>(arg)...};
    // }
}; 



class Archer : public Warrior {
    public:
        Archer(): Warrior(){};
        Archer(int, int);
        virtual ~Archer() {};
};

class ArcherFactory : public WarriorFactory {
    public:
    ~ArcherFactory() = default;
    Warrior* create() const;
    // template<typename ...T>
    // Warrior* create(T&& ...arg) 
    // {
    //     return new Archer{std::forward<T>(arg)...};
    // }
};





#endif //WARRIOR