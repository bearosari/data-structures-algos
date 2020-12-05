#include <iostream>
#include <string>


// Function overloading
int max(int x, int y) {
    return (x > y ? x : y);
}
double max(double x, double y) {
    return (x > y ? x : y);
}
char max(char x, char y) {
    return (x > y ? x : y);
}


// Function Template
template <typename T>
T min(T x, T y) {
    return (x < y ? x : y);
}

template <typename T1, typename T2>
T1 min(T1 x, T2 y) {
    return (x < y ? x : y);
}


// Class template
template <class T>
class Point2d {
private:
    T x_, y_;
public:
    Point2d(T x, T y);
    T x() { return x_; };
    T y() { return y_; };
};

template <typename T>
Point2d<T>::Point2d(T x, T y) {
    x_ = x;
    y_ = y;
}


// Operator overloading
class Point2i {
private:
    int x_, y_;
public:
    Point2i(int x, int y);
    int x() const { return x_; };
    int y() { return y_; };
    Point2i operator+(const Point2i &p);
    friend std::ostream& operator<<(std::ostream &out, const Point2i &p);     // overload operator for another class
};

Point2i::Point2i(int x, int y) {
    x_ = x;
    y_ = y;
}

Point2i Point2i::operator+(const Point2i &p) {
    return {this->x_+p.x_, this->y_+p.y_};
}

std::ostream& operator<<(std::ostream &out, const Point2i &p) {
    out << '(' << p.x() << ',' << p.y_ << ')';
    return out;
}



// Class template with operator overloading
template <typename T>
class Point {
private:
    T x_, y_;
public:
    Point(T x, T y);
    T x() { return x_; };
    T y() { return y_; };
    Point<T> operator + (const Point &p);

//    template <typename T2>
//    friend std::ostream& operator << (std::ostream &out, const Point<T2> &p);     // overload operator for another class

    // Just define the friend function inside for simplicity
    friend std::ostream& operator << (std::ostream &out, const Point<T> &p) {
        out << '(' << p.x_ << ',' << p.y_ << ')';
        return out;    
    }
};

template <typename T>
Point<T>::Point(T x, T y) {
    x_ = x;
    y_ = y;
}

template <typename T>
Point<T> Point<T>::operator +(const Point<T> &p) {
    return {this->x_+p.x_, this->y_+p.y_};    
}

/*
template <typename T>
std::ostream& operator << (std::ostream &out, const Point<T> &p) {
    out << '(' << p.x_ << ',' << p.y_ << ')';
    return out;    
}
*/

//using namesapce std;

int main() {

    // Function overloading
    std::cout << max(3, 1) << std::endl;
    std::cout << max(3.3, 11.1) << std::endl;
    std::cout << max('f', 'A') << std::endl;

    // Function template
    std::cout << min<int>(3, 1) << std::endl;
    std::cout << min(3.3, 11.1) << std::endl;
    std::cout << min(100, 'A') << std::endl;

    // Class template
    Point2d<float> p {1.4, 3.2};
    std::cout << '(' << p.x() << ',' << p.y() << ')' << std::endl;

    // Operator overloading
    Point2i A{1,3};
    Point2i B{2,4};
    std::cout << "Point A: " << A << std::endl;
    std::cout << "Point B: " << B << std::endl;
    std::cout << "Point A+B: " << (A+B) << std::endl;

    // Class template with operator overloading
    Point<int> X{3,6};
    Point<int> Y{-3,-6};
    std::cout << "Point X+Y: " << (X+Y) << std::endl;
}