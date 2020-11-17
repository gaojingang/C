#include <iostream>
using namespace std;


struct Student{
    string name; // 姓名
    int age; //年齡
    int score; //分数
    
};

// 结构体指针可以通过 ->  来访问结构体中的成员属性 
int main(int argc, char const *argv[])
{
    /* code */
    // 创建数组结构体
    struct Student stu = {"李四",13,81};
    struct Student *p = &stu;
    // 通过指针访问结构体变量中的数据 需要利用 ->  来访问
    
    cout << p->name << endl;
        
    cout << "姓名:" << p->name << " 年龄:" << p->age << ", 分数：" << p->score <<endl;

 

    return 0;

}
