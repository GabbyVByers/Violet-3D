
#pragma once

#include "Core.h"
#include "Vec3.h"

class Quaternion {
public:
    double w = 0.0;
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;

    Quaternion operator * (const Quaternion& b) const {
        return {
            (w * b.w) - (x * b.x) - (y * b.y) - (z * b.z),
            (w * b.x) + (x * b.w) + (y * b.z) - (z * b.y),
            (w * b.y) - (x * b.z) + (y * b.w) + (z * b.x),
            (w * b.z) + (x * b.y) - (y * b.x) + (z * b.w)
        };
    }
};

