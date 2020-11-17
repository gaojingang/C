#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    
    int arrs[] = {11,2,3,4,5,6,7,8,9,10};

    cout << "数组对象默认为内存中的首地址:" << arrs << endl;
    // 数组对象默认为内存中的首地址:0x61fde0
    int *p = arrs;
    cout << "指针访问数组首元素内容:" << *p <<  ", 数组获取第一个元素内容:" << arrs[0] << endl;
    //指针访问数组首元素内容:11, 数组获取第一个元素内容:11

    // for 传统方式遍历数据内容
    for (int i = 0; i < 10; i++)
    {

        cout << "下标获取value:" <<  arrs[i]   << ",addr:" << &arrs[i] << endl;

        cout << "指针获取value:" <<  *p   << ",addr:" << p << endl;
        // 指针对象为 int类型，数组类型也是int 类型，数组中的元素内存地址都是连续的，可以通过++ 的方式来切换到下一个地址中
        p ++ ;
    }
    
    /*
    下标获取value:11,addr:0x61fde0
    指针获取value:11,addr:0x61fde0
    下标获取value:2,addr:0x61fde4
    指针获取value:2,addr:0x61fde4
    下标获取value:3,addr:0x61fde8
    指针获取value:3,addr:0x61fde8
    下标获取value:4,addr:0x61fdec
    指针获取value:4,addr:0x61fdec
    下标获取value:5,addr:0x61fdf0
    指针获取value:5,addr:0x61fdf0
    下标获取value:6,addr:0x61fdf4
    指针获取value:6,addr:0x61fdf4
    下标获取value:7,addr:0x61fdf8
    指针获取value:7,addr:0x61fdf8
    下标获取value:8,addr:0x61fdfc
    指针获取value:8,addr:0x61fdfc
    下标获取value:9,addr:0x61fe00
    指针获取value:9,addr:0x61fe00
    下标获取value:10,addr:0x61fe04
    指针获取value:10,addr:0x61fe04
    */
    


    return 0;
}
