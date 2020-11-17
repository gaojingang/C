#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    int arr[] = {200,320,120,500,230};

    int max = 0;
    for (size_t i = 0; i < 5; i++)
    {
        /* code */
        if (arr[i]  > max ){
            max = arr[i];
        }
    }
    cout << "max :" << max <<endl;
    



    return 0;
}
