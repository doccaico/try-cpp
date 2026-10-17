#include <string>

int main()
{
    // 整数リテラルのサフィックス
    {
        // u, U
        // 符号なし (unsigned int, unsigned long, unsigned long long)
        { auto a{5U}; }

        // l, L
        // long int または long long int
        { auto a{5L}; }

        // ll, LL
        // long long int
        { auto a{5LL}; }

        // uz, UZ
        // 符号なし size_t 型
        { auto a{5UZ}; }

        // z, Z
        // 符号付き size_t に対応する型
        { auto a{5Z}; }
    }

    // 浮動小数点数リテラルのサフィックス
    {
        // f, F
        // float
        { auto a{0.5F}; }

        // l, L
        // long double
        { auto a{0.5L}; }
    }

    // 文字列・文字リテラルのプレフィックス(接頭辞) / サフィックス
    {
        // u8"..."
        // UTF-8 エンコード文字列 (const char8_t[] : C++20以降)
        { auto s{u8"abc"}; }

        // u"..."
        // UTF-16 文字列 (const char16_t[])
        { auto s{u"abc"}; }

        // U"..."
        // UTF-32 文字列 (const char32_t[])
        { auto s{U"abc"}; }

        // L"..."
        // ワイド文字列 (const wchar_t[])
        { auto s{L"abc"}; }

        // "abc"s
        {
            using namespace std::string_literals;
            { auto s{"abc"s}; }
        }

        // "abc"sv
        {
            using namespace std::string_view_literals;
            { auto s{"abc"sv}; }
        }

        // h, min, s, ms, us, ns
        // 時間リテラル (例: 30s, 5ms：std::chrono)
    }
}
