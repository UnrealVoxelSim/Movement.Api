#pragma once

#include "UnrealVoxelSim/Spatial/Api/LinearVelocity.h"

namespace UnrealVoxelSim::Movement::Api
{
	struct Intent final
	{
		Spatial::Api::LinearVelocity DesiredVelocity;
		bool JumpRequested{};
	};
}
