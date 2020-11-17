#include <iostream>
using namespace std;


void showMenu(){
    
    cout << "**********************" << endl;
    cout << "*****1、添加联系人*****" << endl;
    cout << "*****2、显示联系人*****" << endl;
    cout << "*****3、删除联系人*****" << endl;
    cout << "*****4、查找联系人*****" << endl;
    cout << "*****5、清空联系人*****" << endl;
    cout << "*****0、退出通讯录*****" << endl;
    cout << "**********************" << endl;

}


int main(int argc, char const *argv[])
{
    int select = 0;
    while (true)
    {   
        showMenu();    
        cin >>select;
        switch (select)
        {
        case 1:
            
            break;

        case 0:
            system("pause");
            return 0;
            break;
        
        default:
            break;
        }

    }
    
    


    return 0;
}
