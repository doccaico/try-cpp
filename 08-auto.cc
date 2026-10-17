// https://zenn.dev/yaito3014/books/introduction-to-cpp23-basic/viewer/auto

#include <cxxabi.h> // Clang/GCC用デマングルヘッダ
#include <limits>
#include <memory>
#include <print>
#include <typeinfo>

// 型名を人間に読める形式に変換する関数
std::string demangle(const char* name) {
    int status = 0;
    // メモリ管理を安全にするため unique_ptr を使用
    std::unique_ptr<char, void(*)(void*)> res {
        abi::__cxa_demangle(name, nullptr, nullptr, &status),
        std::free
    };
    return (status == 0) ? res.get() : name;
}

int main()
{
    {
        // int
        auto a{5};
        // double
        auto b{3.16};
    }

    // intの範囲を超えた場合
    {
        auto a{222222222222222222};
        std::println("{}", demangle(typeid(a).name())); // long long

        std::println("intの最大値: {}",
                std::numeric_limits<int>::max()); // intの最大値: 2147483647
        std::println("longの最大値: {}",
                std::numeric_limits<long>::max()); // longの最大値: 2147483647
        std::println("long longの最大値: {}",
                std::numeric_limits<long long>::max()); // long longの最大値: 9223372036854775807

        // auto a{222222222222222222}; がintではなくlong longに推論される訳は、
        // int(およびWindows環境だとlong)の最大値を超えているからlong longになる
        auto b{2147483647};
        std::println("{}", demangle(typeid(b).name())); // int
        auto c{2147483648};
        std::println("{}", demangle(typeid(c).name())); // long long
    }
}
