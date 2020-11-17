#include <iostream>
using namespace std;

// 计算 1000 以内的水仙花数
// 153   ,1^3 + 5 ^3 + 3^3 = 153
// 各位的3次方相加之后等于这个数 

int main(int argc, char const *argv[])
{
    /* code */
    int num = 100;
    // 

    do {
        // 用来记录 各位的数值
        int a;
        int b;
        int c;
        a = num % 10; 
        b = num /10 % 10 ;
        c = num /100 ;

        if (a*a*a + b*b*b + c*c*c == num)
            cout << "find result:"<< num <<endl;
        num ++;
    } while (num < 1000);
    
    return 0;
}
