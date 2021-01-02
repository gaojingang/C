#include <iostream>
using namespace std;
#include "Circel.h"
#include "Point.h"

//  设计一个点、圆 类，计算点是否在圆内

// class Point{
// private:
//     int m_x;
//     int m_y;
// public:
//     void setX(int x){
//         m_x = x;
//     };

//     void setY(int y){
//         m_y = y;

//     };

//     int getX(){
//         return m_x;
//     }
//     int getY(){
//         return m_y;
//     }

// };


// class Circel
// {
// private:
//     int m_R; // 半径

//     Point m_Center; // 圆心

// public:
//     // 设置半径
//     void setR(int r){
//         m_R = r;
//     };
//     // 获取半径
//     int getR(){
//         return m_R;
//     };
//     // 设置圆心
//     void setCenter(Point p){
//         m_Center = p ;
//     };
//     // 获取圆心
//     Point getCenter(){
//         return m_Center;
//     };
    
// };


// 判断一个点是否在一个圆上
void isInCircle(Circel c , Point p){
//  使用到的公式就是 勾股定理 ，计算两点之间距离 A(x1,y1)  B (x2,y2)  距离 d^2 = (x2 - x1)^2 + (y2 - y1) ^2

    // 获取圆心;
    
    // int r = c.getR();
    // Point center = c.getCenter();
    // int x = center.getX();
    // int y = center.getY();
    

    // //  获取点的坐标
    // int px = p.getX();
    // int py = p.getY();

    // 计算两点之间的距离平方

    int distance =  (c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) 
         + (c.getCenter().getY() - p.getY() ) * (c.getCenter().getY() - p.getY() );

    //计算半径到圆心之间的距离平方
    int rDistance = c.getR() * c.getR();

    // 判断 p点是否在圆上

    if (distance == rDistance){
        cout <<"点在圆上" << endl;
    } else if(distance > rDistance ){
        cout <<"点在圆外" << endl;
    }  else if(distance < rDistance ){
        cout <<"点在圆内" << endl;
    }


}


int main(int argc, char const *argv[])
{
    // 验证 
    Circel c ;
    c.setR(10);

    cout <<c.getR() <<endl;
    Point center ;
    center.setX(10);
    center.setY(0);
    c.setCenter(center);

    // 创建一个点

    Point p ;
    p.setX(10);
    p.setY(11);

    isInCircle(c,p);


    return 0;
}
