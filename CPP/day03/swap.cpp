#include <iostream>
#include "swap.h"

using namespace std;

/*
    1.创建.h 头文件
    2.创建cpp源代码文件
    3.在头文件中声明函数
    4.在源代码文件中定义函数
**/

int main(int argc, char const *argv[])
{
    /* code */
    int a = 10;
    int b = 20;
    swap(a,b);
    return 0;
}

void swap(int a,int b ) {

    cout << a << endl;
    cout << b << endl;

    int temp = a ;
    a = b ;
    b = temp;

    cout << a << endl;
    cout << b << endl;

}


