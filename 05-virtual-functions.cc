// https://zenn.dev/yaito3014/books/introduction-to-cpp23-basic/viewer/virtual-functions

#include <print>

struct Counter
{
// protectedなので派生クラス(ResettableCounter)から触れられる
protected:
    int m_count = 0;
public:
    Counter() { }
    // 仮想関数
    virtual void increment() { m_count = m_count + 1; }
    int value() { return m_count; }

};

struct StepCounter : public Counter
{
private:
    int m_step = 1;
public:
    explicit StepCounter(int step) : m_step(step) { }
    // 関数の後ろに付けたoverrideは、これが基底クラスの仮想関数をオーバーライドすることを示す
    void increment() override { m_count = m_count + m_step; }
};

void count_up(Counter& c)
{
    c.increment();
    c.increment();
}

int main()
{
    {
        Counter a;
        count_up(a);
        std::println("{}", a.value()); // 2

        StepCounter b(10);
        count_up(b);
        std::println("{}", b.value()); // 20
    }

    // スライシング
    // https://zenn.dev/yaito3014/books/introduction-to-cpp23-basic/viewer/virtual-functions#%E5%80%A4%E3%81%A7%E5%8F%97%E3%81%91%E5%8F%96%E3%82%8B%E3%81%A8%E3%82%B9%E3%83%A9%E3%82%A4%E3%82%B7%E3%83%B3%E3%82%B0%E3%81%8C%E8%B5%B7%E3%81%8D%E3%82%8B
    {
        StepCounter b(10);
        Counter c = b;
        c.increment();
        std::println("{}", c.value()); // 1
    }
}
