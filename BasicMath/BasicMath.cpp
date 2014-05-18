#include <Windows.h>
#include "BasicMath.h"

extern "C"

_declspec(dllexport) int SumToN(int n){
    return n * (n + 1) / 2;
}
