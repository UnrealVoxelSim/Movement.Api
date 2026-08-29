#pragma once

#include "UnrealVoxelSim/Simulation/Api/TickIndex.h"
#include "UnrealVoxelSim/Spatial/Api/LinearVelocity.h"

namespace UnrealVoxelSim::Movement::Api
{
	// One resolved controller sample for one simulation tick. A stale sample is equivalent to zero input.
	struct MovementInputComponent final
	{
		Simulation::Api::TickIndex Tick;
		Spatial::Api::LinearVelocity DesiredVelocity;
		bool JumpRequested{};
	};
} // namespace UnrealVoxelSim::Movement::Api
