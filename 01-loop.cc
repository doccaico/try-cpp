#include <print>
#include <ranges>
#include <string>
#include <vector>

using namespace std::string_literals;

int main()
{
    // range : std::ranges::iota_view<int, int>
    {
        for (int i : std::views::iota(0, 5)) {
            std::print("{}", i);
        }
        std::println();
    }

    {
        for (int i : std::views::iota(0, 5) | std::views::reverse) {
            std::print("{}", i);
        }
        std::println();
    }

    // vector : std::vector<int>
    {
        auto nums = std::vector{0, 1, 2, 3, 4};
        for (const auto n : nums) {
            std::print("{}", n);
        }
        std::println();
    }

    {
        auto nums = std::vector{0, 1, 2, 3, 4};
        for (const auto n : nums | std::views::reverse) {
            std::print("{}", n);
        }
        std::println();
    }

    // initializer_list : std::initializer_list<int>
    {
        auto nums = {0, 1, 2, 3, 4};
        for (const auto n : nums) {
            std::print("{}", n);
        }
        std::println();
    }

    {
        auto nums = {0, 1, 2, 3, 4};
        for (const auto n : nums | std::views::reverse) {
            std::print("{}", n);
        }
        std::println();
    }

    // string
    {
        auto strs = {"A"s, "B"s, "C"s, "D"s, "E"s};
        for (const auto s : strs) {
            std::print("{}", s);
        }
        std::println();
    }

    {
        auto strs = {"A"s, "B"s, "C"s, "D"s, "E"s};
        for (const auto s : strs | std::views::reverse) {
            std::print("{}", s);
        }
        std::println();
    }
}
