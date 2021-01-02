#include <iostream>
using namespace std;
//  类对象 作为成员变量时的

class Phone{
public:
    string mPhoneName;

    Phone(){
         cout << "Phone 默认构造函数" <<endl;
    }

    Phone(string pName){
        mPhoneName = pName;
        cout << "Phone 有参数构造函数" <<endl;
    }

    ~Phone(){
        cout << "Phone 析构函数" <<endl;
    }

};


class Person{
    public:
        string mName;
        Phone mPhone;

        //  采用初始化列表的方式
        // mPhone(pName)  ==>  Phone mPhone = pName: 隐式转换法
        Person(string name,string pName):mName(name),mPhone(pName) {
            cout << "Person 有参数构造函数" <<endl;
        };

        ~Person(){
            cout << "Person 析构函数" <<endl;
        };

};


void test01(){

    Person p("zhangsan","huawei");
    cout << "pname:" << p.mName <<"  Phone Name:" << p.mPhone.mPhoneName <<endl;

// 创建顺序：  首先创建 类对象的构造函数， 析构的顺序恰好相反

// Phone 有参数构造函数
// Person 有参数构造函数
// pname:zhangsan  Phone Name:huawei
// Person 析构函数
// Phone 析构函数

};



int main(int argc, char const *argv[])
{
    /* code */
    test01();
    return 0;
}
