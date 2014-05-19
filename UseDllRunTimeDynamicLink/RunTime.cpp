#include <Windows.h>
#include <iostream>
#include <string>

// 関数ポインタ
// DLLが提供する関数の型にIMPFUNCという別名を付けておく
typedef int (*IMPFUNC) (int n);

int failed(std::string reason)
{
    std::cerr << "failed to " << reason << ". Press enter key to exit." << std::endl;
    char dummy = getchar();
    return -1;
}

int main(void)
{
    // DLLをロードする
    HMODULE hMod = LoadLibrary("BasicMath.dll");

    // DLLが見つからない場合は処理を切り替えることもできる
    if (!hMod)
    {
        return failed("load dll");
    }

    // DLLが提供する"SumToN"という名前の関数を探す
    IMPFUNC pFunc = (IMPFUNC)GetProcAddress(hMod, "SumToN");

    // 関数が見つからない場合は処理を切り替えることもできる
    if (!pFunc)
    {
        return failed("get an address of the function");
    }

    std::cout << pFunc(100) << std::endl;

    return 0;
}
