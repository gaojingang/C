#include <iostream>
using namespace std;
#include <fstream>
#include <string>


string byte2Hex(const char* bytes, int size , bool upper_case)
{
  char const hex[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B','C','D','E','F'};

  string str;
  for (int i = 0; i < size; ++i) {
    const char ch = bytes[i];
    str.append(&hex[(ch & 0xF0) >> 4], 1);
    str.append(&hex[ch & 0xF], 1);
  }
  cout << "hex:" << str <<endl;
  return str;
}


void modifyHexFile(string hexStr){

    cout <<"修改二进制文件!" << hexStr <<endl;
    // 1 导入头文件
    // 2 创建文件流
    ofstream fout("test1.txt",ios::out | ios::binary);

    // 3 打开文件
    // ifs.open("test1.txt",ios::in | ios::binary);
    if (!fout.is_open()){
        cout <<"文件打开失败!" << endl;
        return ;
    }
    // 4 写入文件

    int length = 8;
    char bytes[8] = {00,00,00,00,00,00,00,00};

    fout.seekp(0,ios::beg);
    fout.write(bytes,length);

    // 5 关闭文件
    fout.close();
    cout <<"文件写入成功!" <<endl;
}


void test01(){
    // 1 导入头文件
    // 2 创建文件流
    ifstream fin("test1.txt",ios::in | ios::binary);

    // 3 打开文件
    // ifs.open("test1.txt",ios::in | ios::binary);
    if (!fin.is_open()){
        cout <<"文件打开失败!" << endl;
        return ;
    }
    // 4 读取文件

    int length = 8;
    char *bytes = new char[8];
    fin.seekg(0,ios::beg);;
    fin.read(bytes,length);

    cout << bytes <<endl;
    string hexStr = byte2Hex(bytes,length,true);
    modifyHexFile(hexStr);

    // 5 关闭文件
    fin.close();

}





int main(int argc, char const *argv[])
{
    cout << "binRead02 run:" <<endl;
    test01();
    return 0;
}
