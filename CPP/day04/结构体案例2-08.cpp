#include <iostream>
using namespace std;


struct hero {
    string name;
    string sex;
    int age;

};

void printInfo(struct hero heroArray[],int len)
{

    
    for (int i = 0; i < len; i++)
    {

        cout << "name:" <<heroArray[i].name 
        << " age:" << heroArray[i].age  << " sex:" <<heroArray[i].sex <<  endl;
    }

     


}

void bubblesort(struct hero arrays[],int len ){

    // 冒泡排序
    for (int i = 0; i < len -1; i++)
    {
        for (int j = 0; j < len -i -1; j++)
        {
            if (arrays[j].age > arrays[j+1].age){
                struct hero temp = arrays[j];
                arrays[j] = arrays[j + 1];
                arrays[j +1] = temp;
                
            }

        }
        
    }
    

}


int main(int argc, char const *argv[])
{

    // 初始化数组
    struct hero heroArray[5] = {
        {"刘备","男",18},
        {"关羽","男",21},
        {"张飞","男",26},
        {"赵云","男",28},
        {"貂蝉","女",27},
    };
    
    int len = sizeof(heroArray) / sizeof(heroArray[0]);




    // 打印数组数据
    printInfo(heroArray,len);
    
    bubblesort(heroArray,len);
    
// 打印数组数据
    printInfo(heroArray,len);

    return 0;
}
