//
// Created by KindiLuv on 5/15/2022.
//

#ifndef QUARTERONIONS_QUATERONION_H
#define QUARTERONIONS_QUATERONION_H
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>
#include "Vector3.h"

#include "./common/GLShader.h"

class Quateronion {
private:

public:

#pragma variables
    float scalar;

    Vector3 vector;

#pragma Constructors destructors

    Quateronion();

    ~Quateronion();

    Quateronion(float uS, Vector3 & uV);

    Quateronion(const Quateronion & value);

    Quateronion& operator=(const Quateronion & value);

#pragma operators sum

    void operator+=(const Quateronion & value);

    Quateronion operator+(const Quateronion & value);

#pragma operators substract

    void operator-=(const Quateronion & value);

    Quateronion operator-(const Quateronion & value);

#pragma operators mutliply
    void operator*=(const Quateronion & value);

    Quateronion operator*(const Quateronion & value)const;

#pragma operators scalar multiply
    Quateronion multiply(const Quateronion & value) const;

    float operator*=(const float value);

    Quateronion operator*(const float value)const;

#pragma misc

    float norm();

    void convertToUnitNorm();

    void normalize();

    Quateronion conjugate();

    Quateronion inverse();
};


#endif //QUARTERONIONS_QUATERONION_H
