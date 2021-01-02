#include <iostream>
using namespace std;

// 函数的浅拷贝与深拷贝
// 默认编译器提供的即为浅拷贝，
// 如果属性有通过new出来 在堆区开辟的内存，浅拷贝只会把指针指向过去，在回收的时候就会有问题。
// 如果属性有堆区开辟的，一定要自己提供拷贝函数，防止浅拷贝带来的问题。

class Person{

    public:
        int mAge;
        int* mHeight;
        Person(){
            cout <<"默认的构造函数" <<endl;
        };

        Person(int age,int height){
            mAge = age;
            mHeight = new int(height);
            cout <<"带参数的构造函数" <<endl;
        };

        Person(const Person &p){
            mAge = p.mAge;
            // 针对指向了堆区的属性，在拷贝函数中重新neww下即可解决此问题。
            mHeight = new int (*p.mHeight);

        }

        ~Person(){
            //  释放掉申请的内存
            if (mHeight != NULL){
                delete mHeight;
                mHeight = NULL;
            }
            cout <<"默认的析构函数" <<endl;
        };
};


void test01(){

    Person p1(18,180);
    Person p2(p1);

    cout << "P1 age" <<p1.mAge << " height:" << p1.mHeight <<endl;
    cout << "P2 age" <<p2.mAge << " height:" << p2.mHeight <<endl;
    // 使用编译器默认的 拷贝函数，会将 Person中的属性 height 的指针复制过去。
    
    /*
    带参数的构造函数
    P1 age18 height:0x701940
    P2 age18 height:0x701940
    默认的析构函数
    默认的析构函数
    PS D:\dev\WORKSPACE\C_C++\2018.08\project2> 
    **/

   //  栈区的内存 遵循 先进后出的原则，会先释放 p2 ，再P2释放完之后，再去调用P1的析构函数，由于 P2、P1指向同一个内存地址 P2已经释放了，P1再释放讲究会抛异常
   
//    如果有属性申请了堆区的内存，需要字自己实现拷贝函数。

// 带参数的构造函数
// P1 age18 height:0x7d1940
// P2 age18 height:0x7d1980
// 默认的析构函数
// 默认的析构函数

};




int main(int argc, char const *argv[])
{
    /* code */
    test01();
    return 0;
}
