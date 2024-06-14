#ifndef VECTOR_H
#define VECTOR_H

class Vector{
public:
    Vector(double x = 0, double y = 0, double z = 0);
    double coords[3];
    //needed for svg, didnt want to compile
    double operator[](int i) const; 
    double &operator[](int i); 
    //standard operators
    Vector operator+(const Vector &vector) const;
    Vector operator-(const Vector &vector) const;
    bool operator==(const Vector &vector) const;
    Vector operator/(const double &num) const;
    Vector operator*(const double &num) const;
    //dot product
    double dot(const Vector &vector) const;
};
#endif