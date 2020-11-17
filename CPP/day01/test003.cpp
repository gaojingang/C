#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    // 数组初始化方法：
    //1  利用下表初始化值
    //int arr[5] 

    /* code */
    // 指定数组长度，并赋值
    int arr2[5] = {1,2,4,5};

    cout << arr2[0] <<endl;
    cout << arr2[1] <<endl;
    cout << arr2[2] <<endl;
    cout << arr2[3] <<endl;
    cout << arr2[4] <<endl;


    cout << "for arr2  siezeof:" << sizeof(arr2) << " addr:" << arr2 <<endl;

    for (size_t i = 0; i < 5; i++)
    {
        /* code */

        cout << arr2[i] <<endl;
    }
    
    // 赋值方式，不指定数组长度，直接通过 {} 赋值内容的长度来指定
    int arrs3[] = {10,20,30,50,60,70,80,90,91,100};
    cout << "for arr3  siezeof:" << sizeof(arrs3) << " addr:" << arrs3 <<endl;

    for (size_t i = 0; i < 10; i++)
    {
        /* code */

        cout << arrs3[i] <<endl;
    }



    return 0;
}

