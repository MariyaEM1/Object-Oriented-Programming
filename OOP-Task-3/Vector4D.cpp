#include"Vector4D.hpp"
#include<iostream>

double Vector4D::getA() const {
	return coordinates[0];
}
double Vector4D::getB() const {
	return coordinates[1];
}
double Vector4D::getC() const {
	return coordinates[2];
}
double Vector4D::getD() const {
	return coordinates[3];
}


Vector4D::Vector4D() {
	for (int i = 0; i < 4; i++) {
		coordinates[i] = 0;
	}
}

Vector4D::Vector4D(double a, double b, double c, double d) {
	coordinates[0] = a;
	coordinates[1] = b;
	coordinates[2] = c;
	coordinates[3] = d;
}

double& Vector4D::operator[](unsigned int index){
	return this->coordinates[index];
}
Vector4D Vector4D::operator+(const Vector4D& v) const {
	Vector4D sum;
	for (int i = 0; i < 4; i++) {
		sum.coordinates[i] = coordinates[i] + v.coordinates[i];
	}
	return sum;
}
Vector4D& Vector4D::operator+=(const Vector4D& v) {
	for (int i = 0; i < 4; i++) {
		coordinates[i] += v.coordinates[i];
	}
	return *this;
}
Vector4D Vector4D::operator-(const Vector4D& v) const {
	Vector4D diff;
	for (int i = 0; i < 4; i++) {
		diff.coordinates[i] = coordinates[i] - v.coordinates[i];
	}
	return diff;
}
Vector4D& Vector4D::operator-=(const Vector4D& v) {
	for (int i = 0; i < 4; i++) {
		coordinates[i] -= v.coordinates[i];
	}
	return *this;
}
Vector4D Vector4D::operator*(const Vector4D& v) const {
	Vector4D multiplication;
	for (int i = 0; i < 4; i++) {
		multiplication.coordinates[i] = coordinates[i] * v.coordinates[i];
	}
	return multiplication;
}
Vector4D Vector4D::operator*(double x) const {
	Vector4D multiplication;
	for (int i = 0; i < 4; i++) {
		multiplication.coordinates[i] = coordinates[i] * x;
	}
	return multiplication;
}
Vector4D& Vector4D::operator*=(const Vector4D& v) {
	for (int i = 0; i < 4; i++) {
		coordinates[i] *= v.coordinates[i];
	}
	return *this;
}
Vector4D& Vector4D::operator*=(double v) {
	for (int i = 0; i < 4; i++) {
		coordinates[i] *= v;
	}
	return *this;
}
Vector4D Vector4D::operator/(const Vector4D& v) const {
	Vector4D divide;
	for (int i = 0; i < 4; i++) {
		divide.coordinates[i] = coordinates[i] / v.coordinates[i];
	}
	return divide;
}
Vector4D& Vector4D::operator/=(const Vector4D& v) {
	for (int i = 0; i < 4; i++) {
		coordinates[i] /= v.coordinates[i];
	}
	return *this;
}
Vector4D Vector4D::operator-()const {
	Vector4D opposite;
	for (int i = 0; i < 4; i++) {
		opposite.coordinates[i] = -coordinates[i];
	}
	return opposite;
}

bool Vector4D::operator==(const Vector4D& v)const {
	for (int i = 0; i < 4; i++) {
		if (coordinates[i] != v.coordinates[i]) return 0;
	}
	return 1;
}
bool Vector4D::operator!=(const Vector4D& v)const {
	for (int i = 0; i < 4; i++) {
		if (coordinates[i] != v.coordinates[i]) return 1;
	}
	return 0;
}
bool Vector4D::operator<(const Vector4D& v)const {
	for (int i = 0; i < 4; i++) {
		if (coordinates[i] < v.coordinates[i])return 1;
		else if (coordinates[i] > v.coordinates[i])return 0;
	}
	return 0;
}
bool Vector4D::operator>(const Vector4D& v)const {
	for (int i = 0; i < 4; i++) {
		if (coordinates[i] > v.coordinates[i])return 1;
		else if (coordinates[i] < v.coordinates[i])return 0;
	}
	return 0;
}
bool Vector4D::operator>=(const Vector4D& v)const {
	for (int i = 0; i < 4; i++) {
		if (coordinates[i] > v.coordinates[i]) return 1;
		else if (coordinates[i] < v.coordinates[i]) return 0;
	}
	return 1;
}
bool Vector4D::operator<=(const Vector4D& v)const {
	for (int i = 0; i < 4; i++) {
		if (coordinates[i] < v.coordinates[i]) return 1;
		else if (coordinates[i] > v.coordinates[i]) return 0;
	}
	return 1;
}

bool Vector4D::operator!()const {
	if (coordinates[0] == 0 && coordinates[1]==0 && coordinates[2]==0 && coordinates[3]==0) return true;
	else return false;
}

