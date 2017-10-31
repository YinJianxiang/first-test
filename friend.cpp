/*************************************************************************
    > File Name: friend.cpp
    > Author: YinJianxiang
    > Mail: YinJianxiang123@gmail.com
    > Created Time: 2017年10月21日 星期六 21时38分41秒
 ************************************************************************/

#include<iostream>
#include<cmath>

using namespace std;

class Point {
	double friend GetDistance(const Point &point_1,const Point &point_2);
public:
	Point(int x,int y);
private:
	int x_;
	int y_;
};

Point::Point(int x,int y) : x_(x) , y_(y) {

}

double GetDistance(const Point &point_1,const Point &point_2) {
	double d_x = point_1.x_ - point_2.x_;
	double d_y = point_2.x_ - point_2.y_;

	return sqrt(d_x * d_x + d_y * d_y);
}

int main() {
	Point point_one(1,0);
	Point point_two(0,1);

	cout << GetDistance(point_one,point_two) << endl;

	return 0;
}

