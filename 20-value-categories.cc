// https://zenn.dev/yaito3014/books/introduction-to-cpp23-language/viewer/value-categories

#include <print>

void f(int& x)  { std::println("lvalue: {}", x); }
void f(int&& x) { std::println("rvalue: {}", x); }

int main()
{
    //// lvalue と rvalue
    {
        [[maybe_unused]] int a = 5;
        // a という式は、オブジェクトを指す
        // アドレスを取れ、式が終わったあとも残り、続けて使える。このような式を lvalue と呼ぶ

        // 5 や a + 1 という式は、その場かぎりの値で、続けては使わない
        // 値を取り出して使うだけである。このような式を rvalue と呼ぶ

        // a;     // lvalue: 続けて使えるオブジェクト
        // 5;     // rvalue: 取り出して使う値
        // a + 1; // rvalue: 計算の結果の値
    }

    //// lvalue 参照
    {
        // int& の参照は、lvalue にしか束縛できない。これを lvalue 参照 と呼ぶ
        int a = 5;
        [[maybe_unused]] int& r = a; // lvalue の a に束縛できる

        // error
        // int& r = 5;
        // 5 は rvalue である。int& は lvalue にしか束縛できないので、ビルドに失敗する
    }

    //// rvalue 参照
    {
        // rvalue に束縛するには、int&& と書く。これを rvalue 参照 と呼ぶ
        [[maybe_unused]] int&& r = 5;   // rvalue の 5 に束縛できる

        // r 自体は名前のついた式なので、r と書けばそれは lvalue である
        // int&& という型と、r という式の値カテゴリは別のものである
    }

    // 注: int const& は例外で、lvalue にも rvalue にも束縛できる
    // rvalue に束縛すると、その一時的な値は参照が使える間は保たれる
    // 基本編で、コピーの重い型を const 参照で受け取ってコピーを避けたのは、この性質による

    {
        int a = 5;
        f(a);       // lvalue: 5
        f(5);       // rvalue: 5
        f(a + 1);   // rvalue: 6
    }

    //// decltype
    {
        // 式の型を取り出すのが decltype である。名前をそのまま書くと、その名前の宣言された型になる
        int x = 5;
        [[maybe_unused]] decltype(x) a = 10;   // a は int

        // 名前ではない式に使うと、decltype はその式の値カテゴリを型に反映する
        // lvalue の式なら、lvalue 参照(T&)の型になる
        // x を括弧で囲んだ (x) は lvalue の式なので、decltype((x)) は int& になる
        decltype((x)) r = x; // r は int&
        r = 20;
        std::println("{}", x); // 20
    }

    {
        // 参照を付けずに書く auto は、参照や const を落として値の型にする
        // 値カテゴリを保ったまま型を決めたいときは、decltype(auto) を使う
        // decltype(auto) は、decltype と同じ規則で型を決める
        int x = 5;
        auto p = (x);                // p は int(参照は落ちる)
        decltype(auto) q = (x);      // q は int&((x) の値カテゴリを保つ)
        q = 20;
        std::println("{} {}", p, x); // 5 20
    }
}
