// https://zenn.dev/yaito3014/books/introduction-to-cpp23-basic/viewer/conversion

#include <print>

struct Counter
{
private:
    int m_count = 0;
public:
    Counter() { }
    explicit Counter(int start) : m_count(start) { }
};

int main()
{
    // 通る
    {
        int a = 3;
        int b = static_cast<int>(3.9);
    }

    // 通るけどwarningが出る
    // {
    //     int b = 3.9;
    // }

    // 通らない
    // {
    //     int a = {3.9};
    // }

    // 通らない (explicitがついているから)
    // {
    //     Counter_Struct c = 5;
    // }

    // 通る
    {
        Counter c(5);
    }
}
