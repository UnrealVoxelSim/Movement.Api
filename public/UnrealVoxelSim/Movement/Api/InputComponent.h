#pragma once

#include "UnrealVoxelSim/Simulation/Api/TickIndex.h"
#include "UnrealVoxelSim/Spatial/Api/LinearVelocity.h"

namespace UnrealVoxelSim::Movement::Api
{
	// Public read contract for one resolved controller sample. Movement is its sole writer and structural owner.
	// A sample is consumed only for its matching simulation tick; a stale sample is equivalent to neutral input.
	struct InputComponent final
	{
		Simulation::Api::TickIndex Tick;
		Spatial::Api::LinearVelocity DesiredVelocity;
		bool JumpRequested{};
	};
}
