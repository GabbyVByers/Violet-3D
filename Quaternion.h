
#pragma once

#include "Violet.h"
#include "Vector.h"
#include "Error.h"

class Violet::Quaternion {
public:
    void normalize();
    static Quaternion buildRotationQuaternion(Vector3d axis, double theta);
    Quaternion operator * (const Quaternion& b) const;

    double w = 0.0;
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
};

