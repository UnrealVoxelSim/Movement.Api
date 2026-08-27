#pragma once

namespace UnrealVoxelSim::Movement::Api
{
	enum class CommandError
	{
		InvalidEntity,
		UnknownProfile,
		AlreadyRegistered,
		NotRegistered,
		LocationBlocked,
	};
}
