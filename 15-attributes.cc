// https://zenn.dev/yaito3014/books/introduction-to-cpp23-language/viewer/attributes

#include <print>

[[nodiscard]]
int twice(int x)
{
    return x + x;
}

int main()
{
    {
        // warning: ignoring return value of function declared with 'nodiscard' attribute
        // twice(10);

        // ok
        auto ret = twice(10);
        std::println("{}", ret); // 20
    }

    {
        [[maybe_unused]] int debug_value = twice(10);
    }

    // 意図的なfallthrough
    {
        auto n{1};
        switch (n)
        {
            case 1:
                std::println("1");
                [[fallthrough]];
            case 2:
                std::println("2");
                break;
            default:
                std::unreachable();
        }
    }
}
