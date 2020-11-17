#include <iostream>
using namespace std;

// 乘法口诀表格

int main(int argc, char const *argv[])
{
    /* code */

    for (int i = 1; i <= 9 ; i++) {
        //cout << i <<endl;
        for (int j = 1; j <= i; j++)
        {
            /* code */
            cout << j << "*"<< i  << "=" << i * j << "\t";
        }
        cout << endl;
    }





    return 0;
}
