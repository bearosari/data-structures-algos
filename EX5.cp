#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

class Point {
private:
    int mX,mY, id;
    static int numPoint;
public:
    Point(int x, int y);
    ~Point();
    Point();
    float distance(Point other);
    //void getCoordinates();
    int getX(){return mX; };
    int getY(){return mY; };
    void getCoor();
    void getCoor1();
    void setX(int x) {mX=x; };
    void setY(int y) {mY=y; };
};

int Point::numPoint =0;
Point::Point (int x, int y){
    mX= x;
    mY= y;
    this->id = ++numPoint;
}

Point::~Point(){
   // cout << "DESTROYING " << mX << " and " << mY << endl;
}

Point::Point(): id(++numPoint), mX(0), mY(0){}


void Point::getCoor(){

    cout << "Pt" << this->id << '=' << '(' << this->mX << ","  << this->mY << ')' << endl;
}

void Point::getCoor1(){

    cout << '(' << this->mX << ","  << this->mY << ')' << endl;
}

float Point::distance(Point other) {
    float distance =sqrt((pow(mX-other.getX(),2)) + (pow(mY-other.getY(),2)));
    return distance;
}


class Polygon {
private:
    string mName;
    vector <Point> PP;
public: 
    Polygon(string name, vector <Point> pp);
    Polygon();
    ~Polygon();
    void getName();
    void getVert();
    void getCoordinates();
    void getPerimeter();
};

Polygon::Polygon (string name, vector <Point> pp){
    mName= name;
    PP= pp;
}

Polygon::~Polygon(){
    cout << "DESTROYING " << mName << endl;
}

Polygon::Polygon(){
    mName= "";
    PP= {};
}

void Polygon::getName(){
    cout << mName << ":" << endl;
}

void Polygon::getVert(){
    cout<<endl <<PP.size()<<" vertices" <<endl;
}

void Polygon::getCoordinates(){
   for(int i=0; i < PP.size();i++)
    {
    	Point a = PP.at(i);
    	a.getCoor1();
	}
}

void Polygon::getPerimeter()
{
	float result = 0;
    for(int i=0; i<PP.size() ;i++)
    {
    	Point b;
    	Point a = PP.at(i);
    	if(i == PP.size()-1)
    	{
    		Point b = PP.front();
    		result += a.distance(b);
		}
		else
		{
			Point b = PP.at(i+1);
			result += a.distance(b);
		}
    		
	}
	cout<<"Perimeter of "<< mName <<" is : " << result << endl;
}

int main(){
    double result;
    Point pt1 = {1,4};
    Point pt2;
    Point pointA= {0,0};
    Point pointB= {1,0};
    Point pointC= {0,1};
    pt2.setX(2);
    pt2.setY(3);

    pt1.getCoor();
    pt2.getCoor();
    vector<Point> yo;
    yo.push_back(pointA);
    yo.push_back(pointB);
    yo.push_back(pointC);
    result = pt1.distance(pt2);
    cout<< result <<endl;
    Polygon pol1("Triangle", yo);
    pol1.getName();
    pol1.getCoordinates();
    pol1.getVert();
    pol1.getPerimeter();


}
