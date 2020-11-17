#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */

    // const 修饰指针
    // 1 常量指针 ， 指针的指向可以修改，但是指针指向的值不可以修改
    int a = 10 ;
    int b = 20;
    int *p = &a;

    cout << "*p=" << *p  << " addr:" << p << endl;
    p = &b;
    *p = 30;
    cout << "*p=" << *p  << " addr:" << p << endl;
    
    // *p=10 addr:0x61fe14
    // *p=100 addr:0x61fe10

    const int *p1 = &a;

    cout << "*p1=" << *p1  << " addr:" << p1 << endl;
    // *p1 = 30;  // error: assignment of read-only location '* p1'
    // *p1 的额值不能改下，但是可以修改p1 的指向
    p1 = &b;
    cout << "*p1=" << *p1  << " addr:" << p1 << endl;
    
    // *p1=10 addr:0x61fe0c
    // *p1=20 addr:0x61fe08

    return 0;
}
