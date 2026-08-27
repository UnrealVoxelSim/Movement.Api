#pragma once

#include "UnrealVoxelSim/Movement/Api/Position.h"
#include "UnrealVoxelSim/Movement/Api/ProfileId.h"
#include "UnrealVoxelSim/Movement/Api/Vector.h"

namespace UnrealVoxelSim::Movement::Api
{
	// TODO I already mentioned this struct in another TODO. This struct likely requires separation in multiple independent ECS components. And potentially even moved into separate modules like Position.
	struct State final
	{
		Position Location;
		Vector Velocity;
		ProfileId Profile;
		bool Grounded{};
	};
} // namespace UnrealVoxelSim::Movement::Api
