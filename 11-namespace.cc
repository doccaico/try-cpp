// https://zenn.dev/yaito3014/books/introduction-to-cpp23-language/viewer/namespace

#include <print>

namespace geo
{
    struct Point
    {
        int x;
        int y;
    };

    int sum(Point p)
    {
        return p.x + p.y;
    }
}

int main()
{
    {
        geo::Point p = {.x = 3, .y = 4};
        std::println("{}", geo::sum(p)); // 7
    }

    // usingを使って、geo::Pointを取り込んでgeo::抜きで書けるようにする
    {
        using geo::Point;
        Point p = {.x = 3, .y = 4};
        std::println("{}", geo::sum(p)); // 7
    }

    // 引数依存の名前探索(argument-dependent lookup、ADL)
    // 関数を非修飾で呼び出すとき、実引数の型が属する名前空間も探索される
    {
        geo::Point p = {.x = 3, .y = 4};
        std::println("{}", sum(p)); // 7 (呼び出せる)
    }
}
