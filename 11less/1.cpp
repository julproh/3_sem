#include <iostream>
#include <vector>

using namespace std;

// template <typename T>
// decltype(-T::value) nagate(T arg) {
//     return -T.value;
// }

template <typename T>
auto nagate(T arg) -> decltype(-T::value) {
    return -arg.value;
}

struct MyStruct {
    using IntVector = vector <int>;
    class Myclass {
        public:
            enum class MyEnumClass { //nested class
                A
            };
    };
};

class BinaryTree {
    public :
    private:
        class Node
        {
        public:
            Node(/* args */);
            ~Node();
        };
        
};

int main (int argc, char** argv) {

    int n = 90;
    decltype(n+45.78) m; // смотрит тип выражения в скобоках

    cout << typeid(m).name() << endl; // выводи имя типа

    MyStruct::Myclass obj;;
    MyStruct::Myclass::MyEnumClass en;

   // BinaryTree::Node node;
   vector <char> v;
   // итератор - псевдоуказатель, который умеет работать с элементами контейнера
   auto it = v.begin;
   vector<char>::iterator it2 = v.end;
    return 0;
}