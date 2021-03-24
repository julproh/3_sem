#ifndef WARRIOR_H
#define WARRIOR_H

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
        virtual Warrior* create() const = 0 ;
        virtual ~WarriorFactory() = default; 
};

class Knight : public Warrior {
    public:
        Knight(): Warrior(){};
        Knight(int,  int);
        virtual ~Knight() {};
};

class KnightFactory : public WarriorFactory {
    public:
    virtual Warrior* create() const;
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
    virtual Warrior* create() const;
}; 



class Archer : public Warrior {
    public:
        Archer(): Warrior(){};
        Archer(int, int);
        virtual ~Archer() {};
};

class ArcherFactory : public WarriorFactory {
    public:
    virtual Warrior* create() const;
};

#endif //WARRIOR