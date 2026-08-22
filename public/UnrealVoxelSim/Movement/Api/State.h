#pragma once

#include "UnrealVoxelSim/Movement/Api/Position.h"
#include "UnrealVoxelSim/Movement/Api/ProfileId.h"
#include "UnrealVoxelSim/Movement/Api/Vector.h"

namespace UnrealVoxelSim::Movement::Api
{

struct State final
{
    Position Location;
    Vector Velocity;
    ProfileId Profile;
    bool Grounded{};
};

} // namespace UnrealVoxelSim::Movement::Api
