#include "sample.h"
#include <iostream>

#pragma comment(lib, "MakeDll.lib")

int main(void)
{
    // MakeDll.dllが提供する関数 SumToN() を呼び出す
    std::cout << SumToN(10) << std::endl;
}
