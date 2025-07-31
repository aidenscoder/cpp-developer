#include <iostream>
#include <vector>
#include <any>
using namespace std;


template<typename T>
class property{
    private:
        T value;
    public:
        property(T value){
            this->value = value;
        }

        //standard operators
        T operator+(T value){
            return this->value+value;
        }
        T operator-(T value){
            return this->value-value;
        }
        T operator*(T value){
            return this->value*value;
        }
        T operator/(T value){
            return this->value/value;
        }
        property& operator+=(T value){
            this->value += value;
            return *this;
        }
        property& operator-=(T value){
            this->value -= value;
            return *this;
        }
        property& operator*=(T value){
            this->value *= value;
            return *this;
        }
        property& operator/=(T value){
            this->value /= value;
            return *this;
        }
        //standard operators

        //comparisons
        bool operator==(T value){
            return this->value == value;
        }
        bool operator>=(T value){
            return this->value >= value;
        }
        bool operator<=(T value){
            return this->value <= value;
        }
        bool operator!=(T value){
            return this->value != value;
        }
        bool operator>(T value){
            return this->value > value;
        }
        bool operator<(T value){
            return this->value < value;
        }
        bool operator!(){
            return !this->value;
        }
        //comparisons

        //bitwise operators
        property operator&(T value){
            return this->value & value;
        }
        property operator|(T value){
            return this->value | value;
        }
        property operator^(T value){
            return this->value ^ value;
        }
        property operator<<(T value){
            return this->value << value;
        }
        property operator>>(T value){
            return this->value >> value;
        }
        property& operator&=(T value){
            this->value &= value;
            return *this;
        }
        property& operator|=(T value){
            this->value |= value;
            return *this;
        }
        property& operator^=(T value){
            this->value ^= value;
            return *this;
        }
        property& operator<<=(T value){
            this->value <<= value;
            return *this;
        }
        property& operator>>=(T value){
            this->value >>= value;
            return *this;
        }
        //bitwise operators

        //other operators
        operator T() const {
            return value;
        }
        property& operator++(){
            ++value;
            return *this;
        }
        property& operator--(){
            --value;
            return *this;
        }
        property operator=(T value){
            this->value = value;
            return *this;
        }
    };


template<typename T>
bool an_instance_of(const any& a) {
    if (a.type() == typeid(T)) {
        return true;
    } else if (a.type() == typeid(property<T>)) {
        return true;
    } else {
        return false;
    }
}


int main(){
    class point {
        public:
            property<int> x;
            property<int> y;
            point(int x, int y): x(x),y(y) {}
            void repr(){
                cout << "(" << x << "," << y << ")";
            }
    };
    return 0;
}