
#pragma once

#include "Core.h"
#include "Vector.double3.h"
#include "Error.h"

class Quaternion {
public:
    void normalize();
    static Quaternion buildRotationQuaternion(double3 axis, double theta);
    Quaternion operator * (const Quaternion& b) const;

    double w = 0.0;
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
};

