#include <iostream>
using namespace std;


void printInfo(int *a){

    cout << "array first address :" << a <<endl;

}

// 引用传递
void printInfo2(int (&b)[5]){

cout << "array first address :" << b <<endl;

}


int main(int argc, char const *argv[])
{
    // 数组默认传递的就是指针
    int a[5] = {1};
    printInfo(a);

    int b[10] = {2};
    printInfo2(a); // 需要函数声明的时候 把数组的长度声明，否则编译器报错
    // printInfo2(b); // 需要函数声明的时候 把数组的长度声明，否则编译器报错

    
    return 0;
}
