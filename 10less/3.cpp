//дерево
// есть узел в нем что-то полезное и указатели на левого и правого сыновей

#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* left_;
    Node* right_;

    Node (int v = 0) : value(v), left_(nullptr), right_(nullptr) {}
};
template <typename T, typename ...Others>
Node* traverse (T root, Others ... path) {
    return (root ->* ... ->* path);
}; 

int main () {

    Node* root = new Node(0);
    root -> left_ = new Node(1);
    root -> left_ -> right_ = new Node(2);

    auto left = &Node::left_;
    auto right = &Node::right_;

    root->*left ;

    Node* node = traverse(root, left, right);
    cout << node->value << endl;
    
    return 0;
}