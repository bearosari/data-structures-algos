#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

template <typename T>
class Vec {
private:
    T x_, y_, z_;
public: 
    Vec(T x, T y, T z);
    ~Vec();
    Vec();
    T x() { return x_; };
    T y() { return y_; };
    T z() { return z_; };
    void setX(T x) {x_=x; };
    void setY(T y) {y_=y; };
    void setZ(T z) {z_=z; };
    Vec<T> operator + (const Vec &p);
    Vec<T> operator - (const Vec &p);
    Vec<T> operator * (const int &p); //vector times 2
    int operator * (const Vec &p); //vector times vector
    
    friend std::ostream& operator << (std::ostream &out, const Vec<T> &p) {
        out << '(' << p.x_ << ',' << p.y_ << ',' << p.z_ << ')';
        return out;    
    }

    //2*vector

    friend  Vec<T> operator * (T out, const Vec<T> &p) {
    return {out*p.x_ , out*p.y_ , out*p.z_ };     
    }


};


template <typename T>
Vec<T>::Vec(T x, T y, T z){
    x_=x;
    y_=y;
    z_=z;
}

template <typename T>
Vec<T>::~Vec(){
    //decontructor
}

template <typename T>
Vec<T> Vec<T>::operator +(const Vec<T> &p) {
    return {this->x_+p.x_, this->y_+p.y_, this->z_+p.z_};    
}
template <typename T>
Vec<T> Vec<T>::operator -(const Vec<T> &p) {
    return {this->x_-p.x_, this->y_-p.y_, this->z_-p.z_};    
}

template <typename T>
Vec<T> Vec<T>::operator *(const int &p) {
    return {this->x_*p, this->y_*p, this->z_*p};
}

//vector times vector
template <typename T>
int Vec<T>::operator *(const Vec<T> &p) {
    return (this->x_*p.x_ + this->y_*p.y_ + this->z_*p.z_);
} 


//default contructor

template <typename T>
Vec<T>::Vec(): x_(0), y_(0), z_(0) {}

int main() {
    Vec <int> v1 {1 ,2 ,3};
    Vec <int> v2;
    v2.setX( -3);
    v2.setY(1);
    v2.setZ(2);
   // Vec<int> X{3,6};
    //Vec<int> Y{-3,-6};
    std::cout << v1 << endl;
    std::cout << v2 << endl;
    std::cout << v1+v2 << std::endl;
    std::cout << v1-v2 << std::endl;
    std::cout << v1*2 << std::endl;


    std::cout << 2*v1 << std::endl;
    std::cout << v1*v2 << std::endl;
}

