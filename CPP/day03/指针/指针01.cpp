#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
    /* code */

    // 定义指针
    int a = 10;
    int *p ;  // 数据类型 * 变量名称 定义指针
    // 让指针记录 变量 a 的 内存地址  通过 取地址符号  &  来获取
    p = &a;
    cout << "a 的地址 &a " << &a << endl;
    cout << " P 的值为   " << p << endl;

    // 使用指针
    // 可以通过解引用的方式来找到指针的内存
    // 指针前面加* 表示解引用 ，找到内存地址的数据
    *p = 1000;

    cout << "a 的值为  " << a << endl;
    cout << "*P 的值为 " << *p << endl;
    

    return 0;
}
