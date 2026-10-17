// https://zenn.dev/yaito3014/books/introduction-to-cpp23-language/viewer/odr-and-inline

// 1. 関数の宣言は何度でも書けるが、定義は1つだけ書く (One Definition Rule, ODR)
// 2. ヘッダに定義を書くと、そのヘッダを取り込む翻訳単位ごとに同じ定義が現れ、定義の重複になる (ODR違反)
// 3. ヘッダの定義にinlineをつけると、同一の定義が複数の翻訳単位に現れてよくなる
//   注. ただしどの翻訳単位に現れる定義も同一でなければならない
// 4. クラスの中で定義したメンバ関数は、暗黙に inline として扱われる
// 5. inline は、関数だけでなく変数にも付けられる

int main() { }
