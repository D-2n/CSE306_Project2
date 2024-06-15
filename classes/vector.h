#ifndef VECTOR_H
#define VECTOR_H

class Vector{
public:
    Vector(double x = 0, double y = 0, double w2 = 1);
    double coords[2];
    double weight = 1;
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
    double norm2() const;
};
#endif