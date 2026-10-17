// https://zenn.dev/yaito3014/books/introduction-to-cpp23-basic/viewer/const

int main()
{
    {
        int a{};
        a = 10; // 書き換える事が出来る
    }
    {
        const int a{};
        // error
        // a = 10;
    }

    // "const int" と "int const" は同じ意味。
    {
        int const a{};
        // error
        // a = 10;
    }
}
