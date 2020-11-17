#include <iostream>
using namespace std;


struct Student{
    string name; // 姓名
    int age; //年齡
    int score; //分数
    
};


int main(int argc, char const *argv[])
{
    /* code */
    // 创建数组结构体
    struct Student stuArrays [3] = {
         {"李四",13,81},
         {"王武",14,68},
         {"赵琦",19,96}

    };

    // 赋值
    for (size_t i = 0; i < 3; i++)
    {
        /* code */
        
        cout << "姓名:" << stuArrays[i].name << " 年龄:" << stuArrays[i].age << ", 分数：" << stuArrays[i].score <<endl;

    }
    

    
    

 

    return 0;

}
