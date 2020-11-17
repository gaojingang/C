#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int arr[10] =  {1,2,3,4,5,6,7,8,9,10};

    cout << "数组占用内存的大小:"  << sizeof(arr) <<endl;

    cout << "数组每个元素占用内存的大小:"  << sizeof(arr[0]) <<endl;

    cout << "数组元素个数或者长度为:"  << sizeof(arr) /sizeof(arr[0]) <<endl;


    cout << "数组首地址为:"  <<  arr <<endl;
    cout << "数组第一个元素的地址为:"  <<  &arr[0] <<endl;
    
    for (size_t i = 0; i < 10; i++)
    {
        /* code */
        cout << "数组第" << i <<"个元素的地址为:"  <<  &arr[i] <<endl;
    }
    



    return 0;
}
