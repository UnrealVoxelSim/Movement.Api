#pragma once

#include <cstddef>

namespace UnrealVoxelSim::Movement::Api
{
	enum class IntentErrorType
	{
		EntityNotRegistered,
		DuplicateEntity,
		InvalidVelocity,
	};

	struct IntentError final
	{
		IntentErrorType Error;
		std::size_t IntentIndex{};
	};
} // namespace UnrealVoxelSim::Movement::Api
