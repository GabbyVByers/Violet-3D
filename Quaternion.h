
#pragma once

#include "Violet.h"
#include "Vector.h"

class Violet::Quaternion {
public:
    // Quaternion.cpp
    void normalize();
    static Quaternion buildRotationQuaternion(Vector3d axis, double theta);
    static Quaternion Identity();
    Quaternion operator * (const Quaternion& b) const;

    double w = 1.0;
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
};

