#include <iostream>
using namespace std;


struct Student{
    string name; // 姓名
    int age; //年齡
    int score; //分数
    
} s3; // 3. 结构体变量创建方式3


int main(int argc, char const *argv[])
{
    /* code */
    // 1. 结构体变量创建方式1 
    struct Student s1 ;  // struct 可省略
    // 赋值
    s1.name = "张三";
    s1.age = 15;
    s1.score = 94;
    
    cout << "姓名:" << s1.name << " 年龄:" << s1.age << ", 分数：" << s1.score <<endl;


    //2. 结构体变量创建方式2

    struct Student s2 = {"李四",16,82};
    cout << "姓名:" << s2.name << " 年龄:" << s2.age << ", 分数：" << s2.score <<endl;

    //3. 结构体变量创建方式3 ,在声明结构体的时候，最后括号外面带上一个变量名称
    // 赋值
    s3.name = "王五";
    s3.age = 14;
    s3.score = 68;
    
    cout << "姓名:" << s3.name << " 年龄:" << s3.age << ", 分数：" << s3.score <<endl;


    return 0;

}
