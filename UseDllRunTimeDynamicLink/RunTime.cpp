#include <Windows.h>
#include <iostream>
#include <string>

// �֐��|�C���^
// DLL���񋟂���֐��̌^��IMPFUNC�Ƃ����ʖ���t���Ă���
typedef int (*IMPFUNC) (int n);

int failed(std::string reason)
{
    std::cerr << "failed to " << reason << ". Press enter key to exit." << std::endl;
    char dummy = getchar();
    return -1;
}

int main(void)
{
    // DLL�����[�h����
    HMODULE hMod = LoadLibrary("BasicMath.dll");

    // DLL��������Ȃ��ꍇ�͏�����؂�ւ��邱�Ƃ��ł���
    if (!hMod)
    {
        return failed("load dll");
    }

    // DLL���񋟂���"SumToN"�Ƃ������O�̊֐���T��
    IMPFUNC pFunc = (IMPFUNC)GetProcAddress(hMod, "SumToN");

    // �֐���������Ȃ��ꍇ�͏�����؂�ւ��邱�Ƃ��ł���
    if (!pFunc)
    {
        return failed("get an address of the function");
    }

    std::cout << pFunc(100) << std::endl;

    return 0;
}
