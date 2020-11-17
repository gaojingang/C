#include <iostream>
using namespace std;
// 数组逆置

int main(int argc, char const *argv[])
{
    /* code */
    int arr[] = {1,2,3,4,5,6};
    int start = 0;
    // 数组长度获取 ,计算 数组 末尾下标
    int length = sizeof(arr) / sizeof(arr[0]);
    int end  = length -1 ;

    for (int i = 0; i < length; i++)
    {
        
        cout << arr[i] ;

    }
    cout << endl;

    while (start <= end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        
        start ++ ;
        end --;
    }


    for (int i = 0; i < length; i++)
    {
        
        cout << arr[i] ;

    }
    cout << endl;
    



    return 0;
}
