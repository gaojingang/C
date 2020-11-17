#include <iostream>
using namespace std;

struct student {
    string name;
    int age ;
    int score;

};

void printInfo(const struct student *s){

    // s->age = 100;   //表达式必须是可修改的左值C/C++(137)
    cout << "printInfo name:" <<s->name <<",age :" << s->age <<"score:" << s->score << endl;
}

/*
const 用来防止误操作
函数参数中加入 const参数用来声明当前的 形参不可修改性，只读属性，

对于只需要访问属性的方法中，可以添加 const关键字，用来保护当前函数中误操作修改。


�ṹ���е�constʹ��06.cpp: In function 'void printInfo(const student*)':
�ṹ���е�constʹ��06.cpp:13:14: error: assignment of member 'student::age' in read-only object
     s->age = 100;


*/


int main(int argc, char const *argv[])
{

    struct student s = {"张三",28,98};
    printInfo(&s);
    cout << "name:" <<s.name <<",age :" << s.age <<"score:" << s.score << endl;


    return 0;
}
