#pragma once

#include "UnrealVoxelSim/Ecs/Api/EntityId.h"
#include "UnrealVoxelSim/Movement/Api/ReadError.h"
#include "UnrealVoxelSim/Movement/Api/State.h"

#include <expected>

namespace UnrealVoxelSim::Movement::Api
{
	/* TODO Reader sounds very generic. Reader of what exactly?
	 * If we really need to allow external domains read the whole State, rename it into IStateReader (but even in this case "State" is a very vague term)
	 * However if not, I suggest splitting it into specialized movement-data getters like IVelocityReader, IProfileReader
	 * Forcing external domains to read the whole state at once violates Interface Separation Principle.
	 * If we truly need external domains to read the whole state (for performance reasons for example), we need to discuss it.
	 */
	class IReader
	{
	public:
		virtual ~IReader() = default;
		[[nodiscard]] virtual std::expected<State, ReadError> Read(Ecs::Api::EntityId entity) const noexcept = 0;
	};
} // namespace UnrealVoxelSim::Movement::Api
