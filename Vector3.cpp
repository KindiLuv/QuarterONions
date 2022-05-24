//
// Created by Pocky on 5/24/2022.
//

#include <valarray>
#include "Vector3.h"
#include "Quateronion.h"

#pragma mark-constructors
Vector3::Vector3():x(0.0),y(0.0),z(0.0) {};

Vector3::Vector3(float x, float y, float z):x(x),y(y),z(z){};

Vector3::Vector3(const Vector3 & value):x(value.x),y(value.y),z(value.z){};

Vector3& Vector3::operator=(const Vector3 & value){
    x=value.x;
    y=value.y;
    z=value.z;

    return *this;
};

#pragma mark-add

void Vector3::operator+=(const Vector3 & value){
    x+=value.x;
    y+=value.y;
    z+=value.z;
};

Vector3 Vector3::operator+(const Vector3 & value)const{
    return Vector3(x+value.x,y+value.y,z+value.z);
};

#pragma mark-substract

void Vector3::operator-=(const Vector3 & value){
    x-=value.x;
    y-=value.y;
    z-=value.z;
};

Vector3 Vector3::operator-(const Vector3 & value)const{
    return Vector3(x-value.x,y-value.y,z-value.z);
};

#pragma mark-multiplication

void Vector3::operator*=(const float s){
    x*=s;
    y*=s;
    z*=s;
};

Vector3 Vector3::operator*(const float s)const{
    return Vector3(x*s,y*s,z*s);
};

#pragma mark-division

void Vector3::operator/=(const float s){
    x=x/s;
    y=y/s;
    z=z/s;
};

Vector3 Vector3::operator/(const float s)const{
    return Vector3(x/s,y/s,z/s);
};

#pragma mark-dot product

float Vector3::operator*(const Vector3 & value)const{
    return x*value.x+y*value.y+z*value.z;
};

float Vector3::dot(const Vector3 & value)const{
    return x*value.x+y*value.y+z*value.z;
};

float Vector3::angle(const Vector3 & value){
    float theta;

    Vector3 u = value;
    Vector3 m =*this;

    theta=dot(u)/(m.magnitude()*u.magnitude());

    theta=acos(theta)*180/M_PI;

    return theta;
};

float Vector3::magnitude() {
    float magnitude=std::sqrt(x*x+y*y+z*z);
    return magnitude;
}

void Vector3::normalize(){
    float mag = this->magnitude();

    if(mag > 0.0f) {
        float invMag=1.0/mag;

        x *= invMag;
        y *= invMag;
        z *= invMag;
    }

}

Vector3 Vector3::cross(const Vector3 & value)const{
    return {y * value.z  - z * value.y,
            z * value.x - x * value.z,
            x * value.y - y * value.x};
};

Vector3 Vector3::rotateVector(float angle, Vector3 & input){
    Quateronion p(0,(*this));

    p.normalize();

    Quateronion q(angle,input);

    q.convertToUnitNorm();

    Quateronion qInverse=q.conjugate();

    Quateronion rotatedVector = q*p*qInverse;

    return rotatedVector.vector;
}

void Vector3::display(){
    std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;
};

#pragma mark-destructors
Vector3::~Vector3(){};
