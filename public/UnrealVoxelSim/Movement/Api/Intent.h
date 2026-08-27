#pragma once

#include "UnrealVoxelSim/Ecs/Api/EntityId.h"
#include "UnrealVoxelSim/Movement/Api/Vector.h"

namespace UnrealVoxelSim::Movement::Api
{
	/* TODO This struct and IIntentSink are good overall, but I don't like the fuse between Velocity and Jump.
	 * While Velocity is a generic concept, applicable to everything that can move, this is not true for Jump.
	 * First, not all entities can Jump.
	 * Second, Jump is an instantaneous action, while Velocity is continuous. It give the Intent struct an unclear time continuity semantics: is it long-term intent or single-simulation-step intent?
	 */
	struct Intent final
	{
		Ecs::Api::EntityId Entity;
		Vector DesiredVelocity;
		bool Jump{};
	};
} // namespace UnrealVoxelSim::Movement::Api
