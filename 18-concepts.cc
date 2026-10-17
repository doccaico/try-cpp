// https://zenn.dev/yaito3014/books/introduction-to-cpp23-language/viewer/concepts

#include <print>

struct Point
{
    int x;
    int y;
};

template <typename T>
concept Addable = requires (T x)
{
    x + x;
};

template <Addable T>
T twice(T x)
{
    return x + x;
}

// 制約は、パラメータに直接書くほかに、requires を続けて書くこともできる
template <typename T>
concept Addable2 = requires (T x)
{
    x + x;
};

template <typename T> requires Addable2 <T>
T twice2(T x)
{
    return x + x;
}

int main()
{
    {
        twice(5);     // int は Addable を満たす
        twice(2.5);   // double も満たす
        // error: no matching function for call to 'twice'
        // twice({.x = 1, .y = 2});
    }
    {
        twice2(5);     // int は Addable を満たす
        twice2(2.5);   // double も満たす
        // error: no matching function for call to 'twice'
        // twice2({.x = 1, .y = 2});
    }
}
