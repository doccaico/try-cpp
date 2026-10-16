// https://zenn.dev/yaito3014/books/introduction-to-cpp23-basic/viewer/new-delete

#include <print>

struct Counter
{
protected:
    int m_count = 0;
public:
    Counter() { }
    // 本体では何もしないデストラクタだが、virtualを付けてあることに意味がある
    virtual ~Counter() { }
    virtual void increment() { m_count = m_count + 1; }
    int value() { return m_count; }

};

struct StepCounter : public Counter
{
private:
    int m_step = 1;
public:
    explicit StepCounter(int step) : m_step(step) { }
    void increment() override { m_count = m_count + m_step; }
};

void count_up(Counter& c)
{
    c.increment();
    c.increment();
}

int main()
{
    // newで作ったオブジェクトは、ブロックを抜けても自動では破棄されない
    // delete を書いたときに破棄される(寿命を自分で管理)
    {
        Counter* p = new Counter();
        p->increment();
        p->increment();
        std::println("{}", p->value()); // 2
        delete p;
    }

    // pはCounter*だが、指しているのはStepCounterのオブジェクトである
    // Counterのデストラクタがvirtualなので、delete p;は動的な型StepCounterのデストラクタを呼ぶ

    // クラスの継承関係がある場合、C++では「派生クラス（子）へのポインタや参照は、
    // 基本クラス（親）のポインタや参照へ暗黙的に変換できる」というルールがあります。
    // これをアップキャスト（Upcasting）と呼びます
    {
        Counter* p = new StepCounter(10);
        count_up(*p);
        std::println("{}", p->value()); // 20
        delete p;
    }
    {
        StepCounter* p = new StepCounter(10);
        count_up(*p);
        std::println("{}", p->value()); // 20
        delete p;
    }
}
