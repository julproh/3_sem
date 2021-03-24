//Аббревиатуры

/*
RAII
SFINAE
CRTP

*********************

UB underfined behavior
int arr[5];
std::cout<< arr[5];

int f(int n) {
    return n < n + 1;
}

int n = 5;
n = n++ + n++;// 14
n+= ++n + n++; //

*********************

DRY
Don't repeat yourself;
arr[1] = 1;
arr[2] = 1;
arr[3] = 4;

class Warrior {
    public:
        virtual void strike() = 0;
        virtual ~Warrior() = defeault;
}

class Archer: public Warrior {vitrual void strike() override{};};
class Swordman: public Warrior {vitrual void strike() override{};};

class AbstructWarriorConsructor {
    public:
        virtual Warrior* create() = 0;
        virtual ~AbstructWarriorConstructor() = default;
}

template <typename WarriorType>
class ConcreteConstructor : public AbstructWarriorConstructor {
    virtual WarriorType* create()override {return new WarriorType;} }

int main () {

    ConcreteConstructor<Archer> ArcherFactory;
    Warrior* war = ArcherFactory.create();
    return 0;
}
// class AbstructWarriorArcher {
//     public:
//         virtual Warrior* create() {return new Archer;};
// }
// class AbstructWarriorSwordman{
//     public:
//         virtual Warrior* create() {return new Swordman;}
// }

*********************

KISS
keep it simple, stupid

*********************

RTFM
Read these fine manuals

*********************

SOLID
1 SR(P) - Single responsibility (prinple)
class Document {
    std::string text;
    void toHTML();
    void toPDF();
    void toXLS();
}

std::vector<>; //хорошо соответствует
std::string; // плохо

2 OC(P) Open-closed principle

3 LS(P) - Liskov substitution principle

4 IS(P) - Interface segregation priciple

    class Animal{};
    class Dog: public Animal;
    class Human : public Animal;

    // class FlyingAnimal : public Animal {public: virtual fly()= 0;
    // virtual ~FlyingAnimal() = default;}

    // class SwimmingAnimal : public Animal {public: virtual swim()= 0;
    // virtual ~SwimmingAnimal() = default;}

    // class WalkingAnimal : public Animal {public: virtual walk()= 0;
    // virtual ~WalkingAnimal() = default;}


    class IFlyer : {public: virtual fly()= 0;
    ~IFlyer() = default;}

    class Duck : public Animal, virtual public IFlyer{};

5 DIP Dependency inversion principle

    

*/