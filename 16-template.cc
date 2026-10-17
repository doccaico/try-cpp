// https://zenn.dev/yaito3014/books/introduction-to-cpp23-language/viewer/template

#include <print>

// 関数テンプレート
template <typename T>
T twice(T x)
{
    return x + x;
}

// クラステンプレート
template <typename T>
struct Box
{
    T value;

    T twice(T x)
    {
        return x + x;
    }
};

// エイリアステンプレート
template <typename T>
using Ptr = T*;

int main()
{
    // :.2f
    // https://codezine.jp/article/detail/24479
    {
        std::println("{}", twice(12)); // 20
        std::println("{:.2f}", twice(10.2f)); // 20.40
    }

    {
        Box<int> a = {.value = 12};
        Box<double> b = {.value = 10.2};
        std::println("{}", a.twice(12)); // 20
        std::println("{:.2f}", b.twice(10.2f)); // 20.40
    }

    {
        auto i{0};
        Ptr<int> pi = &i;
        *pi = 20;
        std::println("{}", i); // 20

        auto d{0.0};
        Ptr<double> di = &d;
        *di = 20.45;
        std::println("{}", d); // 20.45
    }
}
