#include <iostream>
using namespace std;
/**
// 函数定义，代码是逐行解析，需要先告诉编码器，我有一个函数需要先声明下，后面会使用到，
// 具体的实现会在下面部分实现。
//  当前编辑器 未声明的时候，也可以执行到,未抛异常，但是打印的结果不正确，
 [Running] cd "d:\dev\WORKSPACE\C_C++\2018.08\project1\day03\" && g++ 函数声明.cpp -o 函数声明 && "d:\dev\WORKSPACE\C_C++\2018.08\project1\day03\"函数声明
    20

重新定义之后，可以获得正确的计算结果
[Running] cd "d:\dev\WORKSPACE\C_C++\2018.08\project1\day03\" && g++ 函数声明.cpp -o 函数声明 && "d:\dev\WORKSPACE\C_C++\2018.08\project1\day03\"函数声明
30
*/

// int max(int a,int b);


int main(int argc, char const *argv[])
{
    /* code */

    int a = 10;
    int b = 20;

    int result = max (a,b);
    cout << result << endl;

    return 0;


}

//  函数定义
int max(int a ,int b){
    return a + b ;
}


