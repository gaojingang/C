#include <iostream>
using namespace std;

struct student
{
    string name;
    int age ;
    int score;
};

void printInfo1(struct student s){
    s.age = 56;
    cout <<"printInfo1 name:" << s.name <<", age :" <<s.age << ", score:" << s.score << endl;
    
}

void printInfo2(struct student *p){
    p->age = 80;
    cout <<"printInfo1 name:" <<  p->name <<", age :" << p->age << ", score:" <<  p->score << endl;
    
}


int main(int argc, char const *argv[])
{

    struct student s ;
    s.name = "张三";
    s.age = 18;
    s.score = 28;
    // 如果不想修改主函数中的数据，就使用值传递，想修改主函数中的数据就使用地址传递！

    // 值传递
    printInfo1(s);
    cout <<"main       name:" << s.name <<", age :" <<s.age << ", score:" << s.score << endl;
    // 地址传递

    printInfo2(&s);
    cout <<"main       name:" << s.name <<", age :" <<s.age << ", score:" << s.score << endl;
    
    
    return 0;
}

/**
 * 运行结果 ，值传递作用域在自己的函数范围
 * 地址传递，作用域为全局
printInfo1 name:张三, age :56, score:28
main       name:张三, age :18, score:28
printInfo1 name:张三, age :80, score:28
main       name:张三, age :80, score:28

 * **/