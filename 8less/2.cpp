/*
Гарантии безопасности исключений
- базовые гарантии
- инвариант классов
- утечки ресурсов

Строгая гарантия
- транзакционное поведение 

Отсутствие исключений




Паттерное проектирование
1 - порождающие - как создавать объекты со связями
    1.1 - одиночка
    1.2 - фабрика
2 - структурные - взять готовый и подстроить под себя
    2.1 - адаптер
3 - поведенческие - все остальное, последовательность работы и тд
    стратегия

 */

#include <iostream>
#include <vector>
using namespace std;
//одиночка
class Singleton
{
private:
    //static Singleton * instance;
    //bool isCreated = false;
    Singleton() {};
    Singleton(const Singleton&) = delete;
    Singleton operator = (const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton operator = (Singleton&&) = delete;


        // if (instance == nullptr)
        //     instance = new Singleton;
        // return *instance;
public:
    static Singleton& getInstance () {
        static Singleton Instance;
        return Instance;
    }
};

//static Singleton * instance = nullptr;
//фабрика

class Employee {
    public:
        virtual void print() const {};
        virtual ~Employee() = default;

    private:
};

class Developer : public Employee {
    public:
    virtual void print() const override {
        cout << "" << endl;
    };
};

class EmployeeFactory {
    public:
        virtual Employee* create() const = 0 ;
        virtual ~EmployeeFactory() = default; 
};

class DevelopersFactory : public EmployeeFactory {
    public:
    virtual Employee* create() const {
        return new Developer;
    }
};

// структурные 
// адаптер

class Sensor {
    public:
        virtual double get_temp()= 0;
        virtual ~Sensor(){};
};

class Fahrengeit {
    public:
         double get_temp() {return 100;};
};

class Adapter : public Sensor{
    Fahrengeit fs;
    public:
        virtual double get_temp() override {
            return (fs.get_temp()-32.0)*5.0/9.0;
        }
 };

// стратегия

class Document{
    private:
        Saver* sv;
    public:
        void set_saver(Saver* saver) { sv = saver;};
        void delete_saver (Saver* saver) {delete sv;};
        void save() {sv -> save();};
};

class Saver {
    private:
    public:
        virtual void save();
        virtual ~Saver() = default;
};

class Saver_txt : public Saver{
    public: 
        virtual void save() override {
            cout << "txt" << endl;
        }
};

class Saver_doc : public Saver{
    public: 
        virtual void save() override {
            cout << "doc" << endl;
        }
};

int main () {

    Singleton::getInstance();

    DevelopersFactory *dev_factory = new DevelopersFactory;

    vector <Employee*> employees;
    employees.push_back(dev_factory -> create());


    Sensor * s = new Adapter;
    cout << s-> get_temp();

    Document doc;
    doc.set_saver(new Saver_txt);
    doc.save();


    doc.set_saver(new Saver_doc);
    doc.save();
    return 0;
}