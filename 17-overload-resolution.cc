// https://zenn.dev/yaito3014/books/introduction-to-cpp23-language/viewer/overload-resolution

#include <print>

struct Point
{
    int x;
    int y;
};

void f(int x)    { std::println("int: {}", x); }
void f(double x) { std::println("double: {:f}", x); }

void k(int x)    { std::println("int: {}", x); }
void k(double x) { std::println("double: {:f}", x); }
// void k(Point obj) { std::println("Point: {}", obj.x * obj.y); }

void g(long x)   { std::println("long: {}", x); }
void g(double x) { std::println("double: {:f}", x); }

template <typename T>
void h(T x)   { std::println("template: {}", x); }
void h(int x) { std::println("non-template: {}", x); }

int main()
{
    {
        f(5);   // int: 5
        f(2.5); // double: 2.500000
    }

    {
        // error: no matching function for call to 'k'
        // k({.x = 2, .y = 3});
    }

    {
        // error: call to 'g' is ambiguous
        // g(5);
        g(static_cast<long>(5));   // 5
        g(static_cast<double>(5)); // 5.000000
    }

    {
        h(5);   // non-template: 5
        h(2.5); // template: 2.5
    }
}
