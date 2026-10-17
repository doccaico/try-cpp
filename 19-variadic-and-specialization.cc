// https://zenn.dev/yaito3014/books/introduction-to-cpp23-language/viewer/variadic-and-specialization

#include <print>

//// 可変長テンプレート: 受け取った値をすべて足す(sum)

template <typename... Ts>
auto sum(Ts... args)
{
    // (args + ...) は、パックの各引数を + でつないだ式に展開される
    // sum(1, 2, 3) なら 1 + 2 + 3
    // パックを一つの演算子でつなぐこの式を畳み込み式(fold expression)と呼ぶ
    // 畳み込み式 (args + ...) 自体は、引数が1つ以上あって初めて成り立つ
    return (args + ...);
}

template <typename... Ts>
auto sum2(Ts... args)
{
    // 空のパックでも成り立たせるには、足し合わせの初項を与える
    // (0 + ... + args) は、初項 0 から各引数を + でつなぐ畳み込み式である
    return (0 + ... + args);
}

// 畳み込み式には、つなぐ向きがある
// (args + ...) は右から
// (0 + ... + args) は左からつなぐ
// sum(1, 2, 3) なら、前者は 1 + (2 + 3)、後者は ((0 + 1) + 2) + 3 になる

//// 特殊化

// template <> で始め、TypeName<int> と型を名指しする。これが TypeName の int に対する特殊化である

template <typename T>
struct TypeName
{
    static char const* get() { return "unknown"; }
};

template <>
struct TypeName<int>
{
    static char const* get() { return "int"; }
};

//// 部分特殊化

template <typename T>
struct TypeName<T*>
{
    static char const* get() { return "pointer"; }
};

int main()
{
    {
        sum(1, 2, 3);  // 1 + 2 + 3 で 6
        sum(1.5, 2.0); // 1.5 + 2.0 で 3.5
        // error: unary fold expression has empty expansion for operator '+' with no fallback value
        // sum();
    }

    {
        sum2(1, 2, 3);  // 1 + 2 + 3 で 6
        sum2(1.5, 2.0); // 1.5 + 2.0 で 3.5
        // ok
        sum2(); // 0
    }

    {
        TypeName<int>::get();    // "int"
        TypeName<double>::get(); // "unknown"
    }

    {
        TypeName<int*>::get();    // "pointer"
        TypeName<double*>::get(); // "pointer"
    }
}
