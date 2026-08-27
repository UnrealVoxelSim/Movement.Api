#pragma once

#include "UnrealVoxelSim/Movement/Api/Scalar.h"

namespace UnrealVoxelSim::Movement::Api
{
	// TODO Vector is very generic concept, it should not be defined inside Movement.Api. Either rename it into something Movement-specific, or move it to separate dedicated module.
	struct Vector final
	{
		Scalar X;
		Scalar Y;
		Scalar Z;

		auto operator<=>(const Vector&) const = default;
	};
}
