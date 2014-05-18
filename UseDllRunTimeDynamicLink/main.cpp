#include "BasicMath.h"
#include <iostream>
#include <string>

//#pragma comment(lib, "BasicMath.lib")

typedef int (*IMPFUNC) (int n);

int failed(std::string reason)
{
    std::cerr << "failed to " << reason << ". Press enter key to exit." << std::endl;
    char dummy = getchar();
    return -1;
}

int main(void)
{
    HMODULE hMod = LoadLibrary("BasicMath.dll");

    if (!hMod)
    {
        return failed("load dll");
    }

    IMPFUNC pFunc = (IMPFUNC)GetProcAddress(hMod, "SumToN");

    if (!pFunc)
    {
        return failed("get an address of the function");
    }

    std::cout << pFunc(100) << std::endl;

    return 0;
}
