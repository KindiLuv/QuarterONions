//
// Created by Pocky on 5/24/2022.
//

#ifndef QUARTERONIONS_VECTOR3_H
#define QUARTERONIONS_VECTOR3_H

#include <stdio.h>
#include <cmath>
#include <iostream>

class Vector3 {
private:

public:

    /*!
     *  @brief  x vector component
     */
    float x;

    /*!
     *  @brief  y vector component
     */

    float y;

    /*!
     *  @brief  z vector component
     */

    float z;

#pragma mark-constructors
    /**
     * @brief constructor
     */
    Vector3();

    /**
     * @brief constructor with vars
     */
    Vector3(float x, float y, float z);

    /**
     * @brief copy constructor
     */
    Vector3(const Vector3 & value);

    Vector3& operator=(const Vector3 & value);

#pragma mark-add

    void operator+=(const Vector3 & value);

    Vector3 operator+(const Vector3 & value)const;

#pragma mark-substract

    void operator-=(const Vector3 & value);

    Vector3 operator-(const Vector3 & value)const;

#pragma mark-multiplication

    void operator*=(const float s);

    Vector3 operator*(const float s)const;

#pragma mark-division

    void operator/=(const float s);

    Vector3 operator/(const float s)const;

#pragma mark-dot product

    float operator*(const Vector3 & value)const;

    float dot(const Vector3 & value)const;

    float angle(const Vector3 & value);


    float magnitude();

    void normalize();

    Vector3 rotateVector(float angle, Vector3 & input);

    Vector3 cross(const Vector3 & value)const;

    void display();


#pragma mark-destructors
    /**
     @brief  3D vector desctructor
     */
    ~Vector3();
};


#endif //QUARTERONIONS_VECTOR3_H
