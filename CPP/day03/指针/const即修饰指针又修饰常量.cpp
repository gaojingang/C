#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */

    // const 即修饰指针，又修饰常量
    // 指针的指向 以及 指针内存中的值都不可以修改

    int a = 10;
    int b = 20;
    const int * const p = &a;    
    cout << "p addr:" << p << " value:" << *p << endl;
    //p addr:0x61fe0c value:10

    //p = &b;
    //cpp:17:10: error: assignment of read-only variable 'p'
    //*p = 30;
    //cpp:19:10: error: assignment of read-only location '*(const int*)p'


    return 0;
}
