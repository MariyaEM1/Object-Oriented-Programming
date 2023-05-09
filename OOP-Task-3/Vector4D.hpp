#pragma once

// Add all other required methods and fields of the class.

class Vector4D {
    double coordinates[4];

public:
    double getA() const;
    double getB() const;
    double getC() const;
    double getD() const;

    Vector4D();
    Vector4D(double, double, double, double);
    
    double& operator[](unsigned int);
    Vector4D operator+(const Vector4D&) const;
    Vector4D& operator+=(const Vector4D&);
    Vector4D operator-(const Vector4D&) const;
    Vector4D& operator-=(const Vector4D&);
    Vector4D operator*(const Vector4D&) const;
    Vector4D operator*(double x) const;
    Vector4D& operator*=(const Vector4D&);
    Vector4D& operator*=(double);
    Vector4D operator/(const Vector4D&) const;
    Vector4D& operator/=(const Vector4D&);
    Vector4D operator-()const;

    bool operator==(const Vector4D&)const;
    bool operator!=(const Vector4D&)const;
    bool operator<(const Vector4D&)const;
    bool operator>(const Vector4D&)const;
    bool operator>=(const Vector4D&)const;
    bool operator<=(const Vector4D &)const;
    bool operator!()const;
};