#include <iostream>
using namespace std;
#include "swap.h"


int main(int argc, char const *argv[])
{
    /* code */
    int vala = 10;
    int valb = 20;


    cout << "---------before swap----------" << endl;
    cout <<"vala:" << vala <<endl;
    cout <<"valb:" << valb <<endl;
    sawp(vala,valb);
    cout << "---------after swap----------" << endl;
    cout <<"vala:" << vala <<endl;
    cout <<"valb:" << valb <<endl;


    return 0;
}
