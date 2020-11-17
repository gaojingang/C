#include <iostream>
using namespace std;
#include <string>
#include <time.h>


struct student {
    string name ;
    int score;

};


struct teacher {
    string name;
    struct student sarrays[5];

};

void allocateSpace(struct teacher tArray[] ,int len){
    string nameSeed = "ABCDE";

    for (int i = 0; i < len; i++)
    {   
        string name =  "Teacher_";
        name += nameSeed[i];
        tArray[i].name = name;
        // cout <<"tname:" << name <<endl;

        for (int j = 0; j < 5; j++)
        {
            /* code */
            string sname =  "Student_";
            sname += nameSeed[j];
            tArray[i].sarrays[j].name = sname;
            // 随机分数  rand 为伪随机，以65536 为周期，需要设置随机数种子 让其生产的数字更随机一些
            int score = rand() % 61 + 40 ;  // 40~60 
            tArray[i].sarrays[j].score = score;
            // cout <<"sname:" << sname <<endl;

        }
    }
}

void printallInfo(struct teacher tArray[] ,int len) {
        for (int i = 0; i < len; i++)
        {
            
            cout << "老师name：" << tArray[i].name << endl;

            for (int j = 0; j < len; j++)
            {
                cout <<"\t学生name:" << tArray[i].sarrays[j].name
                    << " 分数：" << tArray[i].sarrays[j].score <<endl;
                
            }
            

        }
        

 }
    

int main(int argc, char const *argv[])
{


    /* code */
    // 设置随机数种子，以当前系统时间
    srand((unsigned)time(NULL));


    // 1.创建3名老师 辅导5名学生
    struct teacher tArray[3] ;

    int len = sizeof(tArray) /  sizeof (tArray[0]);
    // 2 .通过函数给3名老师的信息赋值，并给出老师的学生信息
    allocateSpace(tArray,len);

    // 3 打印所有老师学生的信息

    printallInfo(tArray,len);


    return 0;
}
