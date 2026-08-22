#pragma once

#include "UnrealVoxelSim/Ecs/Api/EntityId.h"
#include "UnrealVoxelSim/Movement/Api/Position.h"
#include "UnrealVoxelSim/Movement/Api/ProfileId.h"

namespace UnrealVoxelSim::Movement::Api
{

struct Register final
{
    Ecs::Api::EntityId Entity;
    ProfileId Profile;
    Position Location;
};

} // namespace UnrealVoxelSim::Movement::Api
