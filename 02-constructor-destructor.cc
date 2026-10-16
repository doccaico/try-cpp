// https://zenn.dev/yaito3014/books/introduction-to-cpp23-basic/viewer/constructor-destructor

#include <print>

struct Counter_Struct
{
private:
    int m_count = 0;
public:
    Counter_Struct() { }
    Counter_Struct(int start) : m_count(start) { }
    ~Counter_Struct()
    {
        std::println(":: destructor");
    }
    void increment() { m_count = m_count + 1; }
    int value() const { return m_count; }
};

class Counter_Class
{
    int m_count = 0;
public:
    Counter_Class() { }
    Counter_Class(int start) : m_count(start) { }
    ~Counter_Class()
    {
        std::println(":: destructor");
    }
    void increment() { m_count = m_count + 1; }
    int value() const { return m_count; }
};

int main()
{
    // struct
    {
        Counter_Struct c;
        c.increment();
        std::println("{}", c.value());
    }
    {
        Counter_Struct c(10);
        c.increment();
        std::println("{}", c.value());
    }

    // class
    {
        Counter_Class c;
        c.increment();
        std::println("{}", c.value());
    }
    {
        Counter_Class c(10);
        c.increment();
        std::println("{}", c.value());
    }
}
