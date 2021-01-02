#include <iostream>
using namespace std;
// 拷贝函数的使用时机
// 1、使用一个已经创建的完毕的对象来初始化一个新对象
// 2、值传递的方式给函数传值
// 3、以值方式返回 局部变量

class Person{

    public:
        int mAge;
        Person(){
            cout <<"默认构造函数" <<endl;
        }
        Person(int a ){
            mAge = a;
            cout <<"有参数构造函数" <<endl;
        }
        
        Person(const Person &p){
            mAge = p.mAge;
            cout <<"拷贝构造函数" <<endl;
        }
        
        ~Person(){
            cout <<"析构造函数" <<endl;
        }

};


void dowork(Person p){


};


void test01(){
    // Person p1(10);
    // Person p2(p1);

};
// 值传递的方式给参数传值
void test02(){
    Person p;
    dowork(p);

// 默认构造函数
// 拷贝构造函数
// 析构造函数
// 析构造函数

}

Person doWork2(){
    cout <<"doWork2 start" <<endl;
    Person p1;
    cout <<  &p1 <<endl;
    cout <<"doWork2 end" <<endl;
    return p1;
    
}
/**
 * 运行结果： 预期应该是dowork2 返回的时候回调用拷贝函数，重新拷贝一份出来，结果未调用。
test03 start
doWork2 start
默认构造函数
0x61fddc
doWork2 end
0x61fddc
test03 end
析构造函数
**/
void test03(){
    cout <<"test03 start" <<endl;
    Person p = doWork2();
    cout <<  &p <<endl;
    cout <<"test03 end" <<endl;
};




int main(int argc, char const *argv[])
{
    /* code */
    // test02();
    test03();
    return 0;
}
