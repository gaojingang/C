#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
    /* code */

    // 指针常量   const 修饰的是变量名称，当前的变量即为常量
    // 指针指向不可以修改，指针指向的值可以修改
    // int *p const p = &a 

    int a =10;
    int b = 20;
    int * const p = &a;

    cout << " 指针常量P :" << p << " 值: " << *p << endl;
    // 指针常量P :0x61fe0c 值: 10

    //p = &b; 
    // cpp:19:10: error: assignment of read-only variable 'p'cpp:19:10: error: assignment of read-only variable 'p'
    //指针的内存指向不允许修改，但是当前指向的内存地址中的值是可以修改的

    *p = 30;
    cout << " 指针常量P :" << p << " 值: " << *p << endl;
    //指针常量P :0x61fe0c 值: 30


    return 0;
}
