#pragma once

#include "UnrealVoxelSim/Movement/Api/Scalar.h"

namespace UnrealVoxelSim::Movement::Api
{

struct Vector final
{
    Scalar X;
    Scalar Y;
    Scalar Z;

    auto operator<=>(const Vector &) const = default;
};

} // namespace UnrealVoxelSim::Movement::Api
