#pragma once
#include <iostream>
using namespace std;

#include "Point.h"

class Circel
{
private:
    int m_R; // 半径

    Point m_Center; // 圆心

public:
    // 设置半径
    void setR(int r);
    // 获取半径
    int getR();
    // 设置圆心
    void setCenter(Point p);
    // 获取圆心
    Point getCenter();
    
};
