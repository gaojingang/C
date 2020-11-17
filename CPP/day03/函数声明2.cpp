#include <iostream>
using namespace std;

void swap(int a,int b );


int main(int argc, char const *argv[])
{
    /* code */
    int a = 10;
    int b = 20;
    swap(a,b);
    return 0;
}

void swap(int a,int b ) {

    cout << a << endl;
    cout << b << endl;

    int temp = a ;
    a = b ;
    b = temp;

    cout << a << endl;
    cout << b << endl;

}