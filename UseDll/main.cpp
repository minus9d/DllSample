#include "BasicMath.h"
#include <iostream>

#pragma comment(lib, "BasicMath.lib")

int main(void)
{
    // DLLが提供する関数 SumToN() を呼び出す
    std::cout << SumToN(10) << std::endl;

    return 0;
}
