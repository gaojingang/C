#include <iostream>
using namespace std;

// 构造函数按照类型分为  无参构造、有参构造 
// 按照类型分为  普通构造函数、拷贝构造函数

class Person{

    public:
        int age;

        Person(){
            cout <<"默认构造函数" << endl;
        }
        Person(int a){
            age = a;
            cout <<"int 类型有参数构造函数" << endl;
        }
        // 拷贝构造函数
        Person(const Person &p){
            age = p.age;
            cout <<"拷贝构造函数" << endl;
        }
        ~Person(){
            cout << "析构函数" <<endl;
        }

};

void Test01(){
    // 括号法
    // Person p1; // 默认构造函数
    // Person p2(20);  // 有参数构造函数
    // Person p3(p2);  // 拷贝数构造函数

    // cout << "p2 age:" <<p2.age << endl;
    // cout << "p3 age:" <<p3.age << endl;

    // 注意事项  Person p1; // 默认构造函数  p1 声明的时候未添加()  ,千万不要添加() ,
    // CPP中允许在一个函数中 做一个函数的声明，如果添加了效果如下   
    //  Person p1();   ==  void function();  
    //  会被编译器认为是 一个函数的声明，而不是 创建一个对象了。

    // Person p1();  
    //   执行结果中未调用到 Person的构造函数、析构函数
    // PS D:\dev\WORKSPACE\C_C++\2018.08\project2>  & 'c:\Users\kk\.vscode\extensions\ms-vscode.cpptools-1.1.2\debugAdapters\bin\WindowsDebugLauncher.exe' '--stdin=Microsoft-MIEngine-In-3zznraf2.bf1' '--stdout=Microsoft-MIEngine-Out-upwd0jbu.f52' '--stderr=Microsoft-MIEngine-Error-yxdv1bop.bsu' '--pid=Microsoft-MIEngine-Pid-2q0xyff5.vbx' '--dbgExe=D:\dev\mingw64\bin\gdb.exe' '--interpreter=mi' 
    // PS D:\dev\WORKSPACE\C_C++\2018.08\project2> 

    // 显式法
    // Person p1;   // 默认构造函数
    // Person p2 = Person(10);  // 有惨构造函数
    // Person P3 = Person(p2);   // 拷贝构造函数

    // 注意事项  Person(10) 为匿名对象，在当前代码行执行结束会后，立即回收
        //  Person(10);
        //  int 类型有参数构造函数
        // 析构函数
        // test01 002
        // cout << "test01 002" << endl;
    // 注意2 不要使用拷贝函数 初始化匿名函数,
    // Person(p3) == Person p3;
    // Person(p3);
    // cout << "test01 002" << endl;


    
    
    // 隐式转换法
    //Person p4 = Person(10);  有参数构造
    Person p4 = 10;  
    Person p5 = p4;     // 拷贝构造




}


int main(int argc, char const *argv[])
{
    Test01();
    return 0;
}
