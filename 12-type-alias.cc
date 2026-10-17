// https://zenn.dev/yaito3014/books/introduction-to-cpp23-language/viewer/type-alias

#include <print>

// 長い名前や繰り返しに名前を与える
using Coord = int;

struct Point
{
    Coord x;
    Coord y;
};

int main()
{
    {
        using Coord = int;

        // これで Coord は int の別名になる。Coord と書いた場所は、int と書いたのと同じである
        // Coord の x を、int の y にそのまま渡せる
        Coord x = 3;
        int y = x;
    }

}
