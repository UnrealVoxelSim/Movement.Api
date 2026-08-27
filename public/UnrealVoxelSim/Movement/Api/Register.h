#pragma once

#include "UnrealVoxelSim/Ecs/Api/EntityId.h"
#include "UnrealVoxelSim/Movement/Api/Position.h"
#include "UnrealVoxelSim/Movement/Api/ProfileId.h"

namespace UnrealVoxelSim::Movement::Api
{
	// TODO It is not clear what word "Register" means here. It seems like this struct is only used in ICommands::Add() method. If so, remove it and use exploded method arguments.
	struct Register final
	{
		Ecs::Api::EntityId Entity;
		ProfileId Profile;
		Position Location;
	};
}
