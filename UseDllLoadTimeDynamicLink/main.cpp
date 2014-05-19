#include "BasicMath.h"
#include <iostream>

// ビルド時にライブラリファイルの名前をリンカに教える必要がある
// プロジェクトのプロパティの「リンカー」→「入力」→「追加の依存ファイル」に書いてもよい
#pragma comment(lib, "BasicMath.lib")

int main(void)
{
    // DLLが提供する関数 SumToN() を呼び出す
    std::cout << SumToN(10) << std::endl;

    return 0;
}
