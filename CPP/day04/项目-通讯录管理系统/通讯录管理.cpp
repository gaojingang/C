#include <iostream>
using namespace std;

#define MAX 1000

struct Person {
    string name;
    int sex; // 1 -男 2 女
    string phoneNumber; // 
    string address;
};

struct ContactBooks{
    struct Person arrys[MAX]; // 联系人数组，
    int m_Size ;
};


void showMenu(){
    
    cout << "**********************" << endl;
    cout << "*****1、添加联系人*****" << endl;
    cout << "*****2、显示联系人*****" << endl;
    cout << "*****3、查找联系人*****" << endl;
    cout << "*****4、修改联系人*****" << endl;
    cout << "*****5、删除联系人*****" << endl;
    cout << "*****6、清空联系人*****" << endl;
    cout << "*****0、退出通讯录*****" << endl;
    cout << "**********************" << endl;

}

// 添加联系人
void addPerson(struct ContactBooks *book){

    int size = book->m_Size;
    cout << "请输入姓名:"<< endl;
    string name ;
    cin >> name;
    book->arrys[book->m_Size].name = name;


    cout << "请输入性别(1-男性,2-女性):"<< endl;
    int sex;
    cin >> sex;
    book->arrys[book->m_Size].sex = sex;


    cout << "请输入电话号码:"<< endl;
    string phonenum ;
    cin >> phonenum;
    book->arrys[book->m_Size].phoneNumber = phonenum;


    cout << "请输入地址:"<< endl;
    string address ;
    cin >> address;
    book->arrys[book->m_Size].address = address;


    // 数组中的size＋1
    book->m_Size++;
    system("pause");
    system("cls");


}


void displayBooks(struct ContactBooks *book){

    int len = book->m_Size;

    if (len > 0){
        for (int i = 0; i < len; i++)
        {
            cout << "姓名:" <<book->arrys[i].name 
                << "\t性别:" <<book->arrys[i].sex
                << "\t电话号码:" <<book->arrys[i].phoneNumber
                << "\t地址:" <<book->arrys[i].address
            << endl;
        }
        

    } else
    {
        cout <<"联系人列表为空。"<<endl; 
    }

    system("pause");
    system("cls");
    

}

int searchPersonIndexByName(struct ContactBooks *book,string name){
   int len = book->m_Size;
    int index = -1;
    
    if (len > 0){
        for (int i = 0; i < len; i++)
        {
            if (name == book->arrys[i].name ){
                index = i;
            }
        } 
    }

    return index;
}


void searchPersonByName(struct ContactBooks *book){

   int len = book->m_Size;

    if (len > 0){
        string name ;
        cout << "请输入要查询的联系人姓名:" <<endl;
        cin >> name;

        int index = searchPersonIndexByName(book,name);
 
        if (index == -1){
            cout << "通讯录中不存在此人:" << name  <<endl;
        } else  {
            
            cout << "姓名:" <<book->arrys[index].name 
                << "\t性别:" <<book->arrys[index].sex
                << "\t电话号码:" <<book->arrys[index].phoneNumber
                << "\t地址:" <<book->arrys[index].address
            << endl;
        }

    } else
    {
        cout <<"联系人列表为空。"<<endl;
    }
    
    system("pause");
    system("cls");
    
            
}

void modifyPersonByName(struct ContactBooks *book){

   int len = book->m_Size;

    if (len > 0){
        string name ;
        cout << "请输入要修改的联系人姓名:" <<endl;
        cin >> name;

        int index = searchPersonIndexByName(book,name);
 
        if (index == -1){
            cout << "通讯录中不存在此人:" << name  <<endl;
        } else  {
            // 讲当前的用户信息做修改
                    
            cout << "请输入姓名:"<< endl;
            string name ;
            cin >> name;
            book->arrys[index].name = name;


            cout << "请输入性别(1-男性,2-女性):"<< endl;
            int sex;
            cin >> sex;
            book->arrys[index].sex = sex;


            cout << "请输入电话号码:"<< endl;
            string phonenum ;
            cin >> phonenum;
            book->arrys[index].phoneNumber = phonenum;


            cout << "请输入地址:"<< endl;
            string address ;
            cin >> address;
            book->arrys[index].address = address;

        }

    } else
    {
        cout <<"联系人列表为空。"<<endl;
    }
    
    system("pause");
    system("cls");


}



void deletePersonByName(struct ContactBooks *book){

    int len = book->m_Size;

    if (len > 0){
        string name ;
        cout << "请输入要删除的联系人姓名:" <<endl;
        cin >> name;

        int index = searchPersonIndexByName(book,name);
        
    if (index == -1){
            cout << "通讯录中不存在此人:" << name  <<endl;
    } else
        {
            // 根据上面查找到的下标 来讲该下标之后的所有元素数据前移，达到删除的目的

            for (int i = index; i < MAX -1 ; i++)
            {
                book->arrys[i] = book->arrys[i +1];
            }
             

            cout << "[" << name <<"]删除成功!"  <<endl;
            
        
            // 删除联系人之后，数组中的size-1
            book->m_Size--;  
        }
    } else
    {
        cout <<"联系人列表为空。"<<endl;
    }

    system("pause");
    system("cls");
    
}


void deleteAllPerson(struct ContactBooks *book){
   int len = book->m_Size;

    if (len > 0){
        book->m_Size = 0;

        cout <<"联系人已经清空!"<<endl;
   
    } else
    {
        cout <<"联系人列表为空。"<<endl;
    }

    system("pause");
    system("cls");
    
}



int main(int argc, char const *argv[])
{
    // 解决乱码问题
    system("chcp 65001"); 

    // 
    struct ContactBooks book ;
    book.m_Size = 0;


    int select = 0;
    while (true)
    {   
        showMenu();    
        cin >>select;
        switch (select)
        {
        case 1:
            addPerson(&book);
            break;
        case 2:
            displayBooks(&book);
            break;
        case 3:
            searchPersonByName(&book);
            break;
        case 4:
            modifyPersonByName(&book);
        case 5:
            deletePersonByName(&book);
            break;
        case 6:
            deleteAllPerson(&book);
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
