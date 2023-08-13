#include <iostream>
using namespace std;

template <typename T>

class Pair{
    T x;
    T y;
    public:
    //create getter and setter functions
    void setX(T x){
        this->x = x;
    }
    T getX(){
        return x;
    }
    void setY(T y){
        this->y = y;
    }
    T getY(){
        return y;
    }
};
int main(){
    Pair<int> p1;
    Pair<double> p2;
    //suppose we want to create a pair of int and double
    // Pair<int,double> p1;
    //but we have to change template class to template <typename T, typename V>

}