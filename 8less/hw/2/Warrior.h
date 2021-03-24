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

class Mage : public Warrior {
    public:
        Mage() : Warrior (){};
        Mage(int, int);
        virtual ~Mage() {};
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