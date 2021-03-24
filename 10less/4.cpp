//патерн странного рекурсивного шаблона

#include <iostream>

using namespace std;

template <typename D>
struct base{};

struct derived : base <derived> {};

template <typename D>
struct base_worker
{
    void prepare (){
        static_cast<D*>(this)-> prepare_impl();
    };
    void work () {
        static_cast<D*>(this) -> work_impl();
    };
};

struct factory_worker : base_worker<factory_worker>
{
    void prepare_impl() {
        cout << "Cleaning work place" << endl;
    }
    void work_impl () {
        cout << "Working" << endl;
    }
};

struct developer : base_worker<developer>
{
    void prepare_impl() {
        cout << "Turn computer on" << endl;
    }
    void work_impl () {
        cout << "Working - coding" << endl;
    }
};

template <typename worker>
void some_work (worker& w) {
    w.prepare();
    w.work();
}


int main() {

    factory_worker w1;
    developer w2;

    some_work(w1);
    some_work(w2);

    return 0;
}