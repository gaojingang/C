#include <iostream>
using namespace std;

// 老师辅导学生，记录辅导的学生信息

struct student {
    string name;
    int age ;
    int score;

};

struct teacher {
    int id;
    string name;
    int age;
    struct student stu;


};

/**
 *  student 的结构体需要定义到 teacher 上面，否则会抛出如下异常。
 * 
�ṹ��Ƕ�׽ṹ��04.cpp:11:20: error: field 'stu' has incomplete type 'student'
     struct student stu;
                    ^~~
�ṹ��Ƕ�׽ṹ��04.cpp:11:12: note: forward declaration of 'struct student'
     struct student stu;
            ^~~~~~~

 * 
*/



int main(int argc, char const *argv[])
{
    /* code */
    // 初始化老师信息

    struct teacher t;
    t.id = 1001;
    t.name = "老王";
    t.age = 56;
    // 在老师的信息中初始化学生的信息
    t.stu.age =  18;
    t.stu.name = "王三";
    t.stu.score = 58;

    cout <<"teache name:" << t.name << ",id:" <<t.id << ",age:"  <<t.age <<
        "student name:" <<t.stu.name <<", student age :" <<t.stu.age << ", score :" << t.stu.score << endl;

    return 0;
}
