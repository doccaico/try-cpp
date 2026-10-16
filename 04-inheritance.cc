// https://zenn.dev/yaito3014/books/introduction-to-cpp23-basic/viewer/inheritance

#include <print>

struct Counter
{
// protectedなので派生クラス(ResettableCounter)から触れられる
protected:
    int m_count = 0;
public:
    Counter() { }
    void increment() { m_count = m_count + 1; }
    int value() { return m_count; }
};

// : public Counter public継承(基底クラスのpublicメンバ関数を使える)
// : private Counter private継承(基底クラスのpublicメンバ関数は使えない)
// : Counter 省略した場合は派生側がclassならprivateになり、structならprivateとなる
// [大事] 派生側がclassであろうとstructであろうと、常にpublic(またはprivate)を明示的に記述すること
struct ResettableCounter : public Counter
{
public:
    void reset() { m_count = 0; }
};

int main()
{
    {
        ResettableCounter c;
        c.increment(); // 1
        c.increment(); // 2
        std::println("{}", c.value());
        c.reset(); // 0
        std::println("{}", c.value());
    }
}
