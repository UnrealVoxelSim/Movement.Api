#pragma once

#include "UnrealVoxelSim/Ecs/Api/EntityId.h"
#include "UnrealVoxelSim/Movement/Api/CommandError.h"
#include "UnrealVoxelSim/Movement/Api/Register.h"

#include <expected>

namespace UnrealVoxelSim::Movement::Api
{
	/* TODO interface called ICommands is poorly designed.
	 * First, word "Command" is very vague. Command what to whome?
	 * Second, the only methods of this interface do not sound like commands. The purpose of this interface and its methods is unclear. The interface needs a redesign.
	 */
	class ICommands
	{
	public:
		virtual ~ICommands() = default;

		// TODO Add what and where? It is not clear what this method does.
		[[nodiscard]] virtual std::expected<void, CommandError> Add(Register registration) = 0;

		// TODO Remove what and from where? It is not clear what this method does.
		[[nodiscard]] virtual std::expected<void, CommandError> Remove(Ecs::Api::EntityId entity) = 0;
	};
} // namespace UnrealVoxelSim::Movement::Api
