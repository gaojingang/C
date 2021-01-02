#include <iostream>
using namespace std;

class Person{
    public:
        // 静态函数声明，函数前面加上static 即可
        static void func1(){
            a = 100;  // 静态函数中值能访问静态变量
            // b = 300;  // 非静态变量无法访问  非静态成员引用必须与特定对象相对C/C++(245)
            cout <<"static func1"<<endl;
        };

        static int a;
        int b ;
    private:
        // 静态函数也是有作用域的，如果声明在了 private 下面 ，类外则无法访问
        static void func2(){
            cout <<"static func2"<<endl;
        };

};

void test01(){
    //  静态函数方法方式
    // 1 通过对象.来调用
    Person p ;
    p.func1();
    // p.func2();  //错误，类外无法访问
    // 2.通过类名. 来调用

    Person::func1();

};


int main(int argc, char const *argv[])
{
    /* code */
    test01();
    return 0;
}
