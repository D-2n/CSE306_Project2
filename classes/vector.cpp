#include "vector.h"

Vector::Vector(double x, double y, double w) {
    coords[0] = x;
    coords[1] = y;
    weight = w;
}

double Vector::dot(const Vector &vector) const {
    double result;
    for (int i = 0; i < 3; i++){
        result += (coords[i] * vector.coords[i]);
    }
    return result;
}
double Vector::norm2() const {
    double result;
    for (int i = 0; i < 3; i++){
        result += (coords[i] * coords[i]);
    }
    return result;
}

//Operators ---------------------------------------------------------------------------------------
Vector Vector::operator-(const Vector &vector) const {
    return Vector(coords[0] - vector[0], coords[1] - vector[1], coords[2] - vector[2]);
}
Vector Vector::operator+(const Vector &vector) const {
    return Vector(coords[0] + vector[0], coords[1] + vector[1], coords[2] + vector[2]);
}
Vector Vector::operator*(const double &num) const {
    return Vector(coords[0] * num, coords[1] * num, coords[2] * num);
}
Vector Vector::operator/(const double &num) const {
    return Vector(coords[0] / num, coords[1] / num, coords[2] / num);
}
bool Vector::operator==(const Vector &vector) const {
    return (coords[0] == vector[0]) && (coords[1] == vector[1]) &&  (coords[2] == vector[2]);
}
//save_svg didnt work without the following two
double Vector::operator[](int i) const { 
     return coords[i]; 
}

double &Vector::operator[](int i) {
     return coords[i]; 
}