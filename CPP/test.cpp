#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    cout<<"Hello World!"<<endl;

    cout << "short 内存占用:"<< sizeof(short) <<endl;
    cout << "long 内存占用: "<< sizeof(long) <<endl;
    cout << "longlong 内存占用: "<< sizeof(long long) <<endl;

    cout << "float 内存占用: "<< sizeof(float) <<endl;
    cout << "double 内存占用: "<< sizeof(double) <<endl;
    cout << "char 内存占用: "<< sizeof(char) <<endl;
    cout << "char16_t 内存占用: "<< sizeof(char16_t) <<endl;
    cout << "char32_t 内存占用: "<< sizeof(char32_t) <<endl;
    cout << "char32_t 内存占用: "<< sizeof(int8_t) <<endl;

    cout <<endl;
    cout << "int 内存占用: "<< sizeof(int) <<endl;
    cout << "int16_t 内存占用: "<< sizeof(int16_t) <<endl;
    cout << "int32_t 内存占用: "<< sizeof(int32_t) <<endl;
    cout << "int64_t 内存占用: "<< sizeof(int64_t) <<endl;

    cout <<endl;

    cout << "bool 内存占用: "<< sizeof(bool) <<endl;

    cout << "String 内存占用: "<< sizeof(string) <<endl;
    



    return 0;
}
