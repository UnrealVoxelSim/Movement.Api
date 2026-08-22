#pragma once

#include "UnrealVoxelSim/Simulation/Api/StepContext.h"

namespace UnrealVoxelSim::Movement::Api
{

class IUpdater
{
  public:
    virtual ~IUpdater() = default;
    virtual void Update(Simulation::Api::StepContext context) = 0;
};

} // namespace UnrealVoxelSim::Movement::Api
