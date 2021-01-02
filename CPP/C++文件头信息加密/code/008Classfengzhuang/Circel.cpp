#include "Circel.h"
#include "Point.h"


// 设置半径
void Circel::setR(int r){
    m_R = r;
};
// 获取半径
int Circel::getR(){
    return m_R;
};
// 设置圆心
void Circel::setCenter(Point p){
    m_Center = p ;
};
// // 获取圆心
Point Circel::getCenter(){
    return m_Center;
};
