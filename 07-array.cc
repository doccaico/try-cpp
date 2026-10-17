// https://zenn.dev/yaito3014/books/introduction-to-cpp23-basic/viewer/array

#include <print>

int main()
{
    // 普通の配列
    {
        int a[3] = {0, 1, 2};
        std::println("{}", a[1]); // 1
        // warning: array index 3 is past the end of the array
        // std::println("{}", a[3]);
        int b[] = {0, 1, 2};
        std::println("{}", a[1]); // 1
        // warning: array index 3 is past the end of the array
        // std::println("{}", a[3]);
    }
    // 動的な配列
    {
        int* a = new int[3];
        a[1] = 1;
        std::println("{}", a[1]); // 1
        // 不定な値が出力される
        // std::println("{}", a[3]);
        delete[] a;
    }
}
