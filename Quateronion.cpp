//
// Created by Pocky on 5/23/2022.
//

#include "Quateronion.h"

#define DegToRad(angle) angle*M_PI/180

/**
 * Constructor
 * @param uS
 * @param uV
 */
Quateronion::Quateronion(float uS, Vector3 & uV) : scalar(uS), vector(uV) {};

Quateronion::~Quateronion() {};

/**
 * Constructor by copy
 * @param value
 */
Quateronion::Quateronion(const Quateronion & value) {
    scalar = value.scalar;
    vector = value.vector;
};

/**
 * Equal Operator
 * @param value
 * @return
 */
Quateronion& Quateronion::operator=(const Quateronion & value) {
    scalar = value.scalar;
    vector = value.vector;

    return *this;
}

/**
 * Plus Equals Operator
 * @param q
 */
void Quateronion::operator+=(const Quateronion & q) {
    scalar+=q.scalar;
    vector.x+=q.vector.x;
    vector.y+=q.vector.y;
    vector.z+=q.vector.z;
}

/**
 * Plus Operator
 * @param value
 * @return
 */
Quateronion Quateronion::operator+(const Quateronion & value) {
    float scalar = this->scalar + value.scalar;
    Vector3 vect = Vector3(this->vector.x + value.vector.x,
                           this->vector.y + value.vector.y,
                           this->vector.z + value.vector.z);

    return Quateronion(scalar, vect);
}

/**
 * Minus Equals Operator
 * @param value
 */
void Quateronion::operator-=(const Quateronion & value) {
    scalar-=value.scalar;
    vector.x-=value.vector.x;
    vector.y-=value.vector.y;
    vector.z-=value.vector.z;
}

/**
 * Minus operator
 * @param value
 * @return
 */
Quateronion Quateronion::operator-(const Quateronion &value) {
    float scalar= this->scalar - value.scalar;
    Vector3 vect = Vector3(this->vector.x - value.vector.x,
                         this->vector.y - value.vector.y,
                         this->vector.z - value.vector.z);

    return Quateronion(scalar, vect);
}

void Quateronion::operator*=(const Quateronion & value){
    (*this)=multiply(value);
}

Quateronion Quateronion::operator*(const Quateronion & value)const {
    float scalar= scalar * value.scalar - vector.dot(value.vector);
    Vector3 imaginary = value.vector * scalar + vector * value.scalar + vector.cross(value.vector);
    return Quateronion(scalar, imaginary);
}

Quateronion Quateronion::multiply(const Quateronion &value) const {
    float scalar = scalar * value.scalar - vector.dot(value.vector);
    Vector3 imaginary = value.vector * scalar + vector * value.scalar + vector.cross(value.vector);
    return Quateronion(scalar, imaginary);
}

void Quateronion::operator*=(const float value){
    scalar*= value;
    vector *= value;
}

Quateronion Quateronion::operator*(const float value)const{
    float scalar = scalar * value;
    Vector3 imaginary = vector * value;

    return Quateronion(scalar,imaginary);
}

float Quateronion::norm(){
    float scalar = scalar * scalar;
    float imaginary = vector * vector;

    return sqrt(scalar * imaginary);
}

void Quateronion::convertToUnitNorm(){
    float angle = DegToRad(scalar);
    vector.normalize();
    scalar=cosf(angle*0.5);
    vector=vector * sinf(angle*0.5);
}

void Quateronion::normalize(){
    if(norm() == 0) return;
    float normValue= 1/norm();

    scalar *= normValue;
    vector *= normValue;
}

Quateronion Quateronion::conjugate() {
    float scalar = scalar;
    Vector3 imaginary = vector * (-1);

    return Quateronion(scalar, imaginary);
}

Quateronion Quateronion::inverse(){
    float absoluteValue=norm();
    absoluteValue *= absoluteValue;
    absoluteValue = 1/absoluteValue;

    Quateronion conjugateValue = conjugate();

    float scalar=conjugateValue.scalar * absoluteValue;
    Vector3 imaginary = conjugateValue.vector * absoluteValue;

    return Quateronion(scalar, imaginary);
}
