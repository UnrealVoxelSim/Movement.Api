#pragma once

#include "UnrealVoxelSim/Ecs/Api/EntityId.h"
#include "UnrealVoxelSim/Movement/Api/ReadError.h"
#include "UnrealVoxelSim/Movement/Api/State.h"

#include <expected>

namespace UnrealVoxelSim::Movement::Api
{

class IReader
{
  public:
    virtual ~IReader() = default;
    [[nodiscard]] virtual std::expected<State, ReadError> Read(Ecs::Api::EntityId entity) const noexcept = 0;
};

} // namespace UnrealVoxelSim::Movement::Api
