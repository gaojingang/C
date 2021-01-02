#include <iostream>
using namespace std;

//  初始化列表

class Person {
    public:
        int mA;
        int mB;
        int mC;
        // 传统的初始化方式
        // Person(int a ,int b ,int c){
        //     mA = a ;
        //     mB = b;
        //     mC = c;
        // }
        // 初始化列表的使用
        // 语法:   
        /* 构造函数():属性1(值1),属性2(值2),属性3(值3){
             函数体
          };
        */

        Person():mA(11),mB(12),mC(13){

        };
        //  灵活的一种方式
        Person(int a,int b,int c ):mA(a),mB(b),mC(c){

        };
};


void test01(){
    // 传统方式初始化
    // Person p1(10,20,30); 

    // 初始化列表
    // Person p1;
    // p1.mA:11
    // p1.mC:12
    // p1.mB:13

    Person p1(33,22,11); 
    // p1.mA:33
    // p1.mC:22
    // p1.mB:11

    cout << "p1.mA:" <<p1.mA <<endl;
    cout << "p1.mC:" <<p1.mB <<endl;
    cout << "p1.mB:" <<p1.mC <<endl;
};

int main(int argc, char const *argv[])
{
    /* code */
    test01();
    return 0;
}
