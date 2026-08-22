#pragma once

#include "UnrealVoxelSim/Ecs/Api/EntityId.h"
#include "UnrealVoxelSim/Movement/Api/Vector.h"

namespace UnrealVoxelSim::Movement::Api
{

struct Intent final
{
    Ecs::Api::EntityId Entity;
    Vector DesiredVelocity;
    bool Jump{};
};

} // namespace UnrealVoxelSim::Movement::Api
