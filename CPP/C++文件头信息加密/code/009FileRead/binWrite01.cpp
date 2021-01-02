#include <iostream>
using namespace std;
#include <fstream>

class Person{

public:
    char c_Name[64];
    int age;
};

void test01(){
    // 1 导入头文件
    // 2 创建文件流
    ofstream ofs("person.txt",ios::out | ios::binary);
    // 3 打开文件
    // ofs.open("person.txt",ios::out | ios::binary);
    // 4 读取文件
    Person p ={"张三",21};
    ofs.write( (char *) &p,sizeof(p));

    // 5 关闭文件
    ofs.close();

}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
