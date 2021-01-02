#include <iostream>
using namespace std;
//  导入fsstrem头文件
#include <fstream>  

void test01(){
// 1 包含头文件

// 2 创建文件流
    ofstream ofs;

//3 指定打开方式

    ofs.open("test1.txt",ios::out);
// 4 写入内容
    ofs << "姓名:张三" <<endl;
    ofs << "性别:男" <<endl;
    ofs << "年龄:23" <<endl;
// 5 关闭文件
    ofs.close();

}


int main(int argc, char const *argv[])
{
    /* code */
    test01();
    return 0;
}

