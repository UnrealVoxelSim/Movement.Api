#pragma once

#include "UnrealVoxelSim/Movement/Api/Scalar.h"

namespace UnrealVoxelSim::Movement::Api
{
	// TODO Position is generic concept that does not belong exclusively to movement. Immovable objects may also have positions. Move Position concept into a separate module like Position.Api or Transform.Api
	struct Position final
	{
		Scalar X;
		Scalar Y;
		Scalar Z;

		auto operator<=>(const Position&) const = default;
	};
} // namespace UnrealVoxelSim::Movement::Api
