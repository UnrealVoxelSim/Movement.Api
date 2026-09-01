#pragma once

#include "UnrealVoxelSim/Ecs/Api/EntityId.h"
#include "UnrealVoxelSim/Movement/Api/Intent.h"
#include "UnrealVoxelSim/Movement/Api/IntentError.h"
#include "UnrealVoxelSim/Simulation/Api/TickIndex.h"

#include <expected>

namespace UnrealVoxelSim::Movement::Api
{
	class IIntentReceiver
	{
	public:
		virtual ~IIntentReceiver() = default;

		[[nodiscard]] virtual std::expected<void, IntentError> SetIntent(Ecs::Api::EntityId entity, Simulation::Api::TickIndex tick, Intent intent) = 0;
	};
}
