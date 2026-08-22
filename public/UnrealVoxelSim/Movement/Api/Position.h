#pragma once

#include "UnrealVoxelSim/Movement/Api/Scalar.h"

namespace UnrealVoxelSim::Movement::Api
{

struct Position final
{
    Scalar X;
    Scalar Y;
    Scalar Z;

    auto operator<=>(const Position &) const = default;
};

} // namespace UnrealVoxelSim::Movement::Api
