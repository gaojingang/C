#include <iostream>
using namespace std;

class Person
{
private:
    /* data */
public:
    Person(/* args */);   // 构造函数
    ~Person();           // 析构函数
};

Person::Person(/* args */)
{
    cout <<"构造函数" << endl;
}

Person::~Person()
{
    cout <<"析构函数" << endl;
}


void test(){
    Person p;
}

int main(int argc, char const *argv[])
{
    /* code */
    test();
    return 0;
}
