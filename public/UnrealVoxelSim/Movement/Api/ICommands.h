#pragma once

#include "UnrealVoxelSim/Ecs/Api/EntityId.h"
#include "UnrealVoxelSim/Movement/Api/CommandError.h"
#include "UnrealVoxelSim/Movement/Api/Register.h"

#include <expected>

namespace UnrealVoxelSim::Movement::Api
{

class ICommands
{
  public:
    virtual ~ICommands() = default;
    [[nodiscard]] virtual std::expected<void, CommandError> Add(Register registration) = 0;
    [[nodiscard]] virtual std::expected<void, CommandError> Remove(Ecs::Api::EntityId entity) = 0;
};

} // namespace UnrealVoxelSim::Movement::Api
