#include <iostream>
using namespace std;
#include <fstream>
#include <string>

void readFile(){
    // 1 头文件导入 

    // 2 声明
    ifstream ifs;

    // 3 打开文件，判断文件打开成功

    ifs.open("test1.txt",ios::in);
    
    if (!ifs.is_open()){
        cout << "文件打开失败!" << endl;
    }

    // 4 读取文件

    //  第一张读取方式

    // char buff[1024] = {0};
    // while (ifs >> buff)
    // {
    //     cout << buff <<endl;
    // }
    

    //  第二张读取方式
    // // 让字符数组 初始化下，首地址指向0 ，数组默认的 buff* 也是指向数组中的第一个元素
    // char buff[1024] = {0};
    // // 使用getline 的方式 读取一行信息，需要将读取到的内容存放到char* 中，还需要传入指定的长度
    // while (ifs.getline(buff,sizeof(buff)))
    // {
    //    cout << buff <<endl;
    // }

    // 第三种
    // 使用 string 对象中的 getline方法来读取
    // string buf ;

    // while (getline(ifs,buf))
    // {
    //     cout << buf << endl;
    // }

    // 第四种 （不推荐使用)
    
    char c ;
    while (  (c = ifs.get()) != EOF)  // EOF  end of file 文件结尾标记
    {
        cout << c << endl;
    }
    
    

    

    // 5 关闭文件
    ifs.close();

}


int main(int argc, char const *argv[])
{

    readFile();
    /* code */
    return 0;
}
