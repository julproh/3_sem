#include <iostream>

template <typename T>
struct add_const
{
    using type = const T;

};

template <typename T>
struct add_const <T&>
{
    using type = const T;

};

template <typename T>
struct add_const <T&&>
{
    using type = const T;

};

template <typename T>
struct remove_const
{
    using type = T;

};

template <typename T>
struct remove_const <const T>
{
    using type = T;

};

template <typename T>
struct remove_const <const T&>
{
    using type = T&;

};

template <typename T>
struct remove_const <const T&&>
{
    using type = T&&;

};

int main() {
    int r;
    const int m = 1; 
    int& p = r;
    remove_const<const int&>::type n = p; // int& n;
    add_const<int>::type w = 3; // const int w;
    return 0;
}