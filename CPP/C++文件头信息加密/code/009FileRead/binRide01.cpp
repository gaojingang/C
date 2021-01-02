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
    ifstream ifs;

    // 3 打开文件
    ifs.open("person.txt",ios::in | ios::binary);
    // 4 读取文件
    Person p;
    
    ifs.read( (char *) &p,sizeof(p));

    cout << p.c_Name << endl;
    cout <<p.age<< endl;


    // 5 关闭文件
    ifs.close();

}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
