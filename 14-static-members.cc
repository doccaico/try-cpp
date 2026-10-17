// https://zenn.dev/yaito3014/books/introduction-to-cpp23-language/viewer/static-members

// 1. クラスのデータメンバには、オブジェクトごとに持つものと、クラスに1つだけ持つものがある
// 2. 後者には static を付ける
// 3. static メンバ関数はオブジェクト引数を取らない

#include <print>

struct Widget
{
    static inline int count = 0;
    int id;

    Widget() : id(count)
    {
        count = count + 1;
    }

    static int how_many()
    {
        return count;
    }

    // これは駄目
    // static int how_many()
    // {
    //     return id;
    // }
};

int main()
{
    // static データメンバ
    {
        Widget a;
        Widget b;
        // count はオブジェクトに属さず、クラスに属するので、Widget::count とクラス名で指す
        std::println("{} {} {}", a.id, b.id, Widget::count); // 0 1 2
    }

    // static メンバ関数
    {
        Widget a;
        Widget b;
        // count はオブジェクトに属さず、クラスに属するので、Widget::count とクラス名で指す
        std::println("{}", Widget::how_many()); // 2
    }
}
