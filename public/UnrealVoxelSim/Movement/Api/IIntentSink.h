#pragma once

#include "UnrealVoxelSim/Movement/Api/Intent.h"
#include "UnrealVoxelSim/Movement/Api/IntentError.h"

#include <expected>
#include <span>

namespace UnrealVoxelSim::Movement::Api
{

class IIntentSink
{
  public:
    virtual ~IIntentSink() = default;
    [[nodiscard]] virtual std::expected<void, IntentError> Submit(std::span<const Intent> intents) = 0;
};

} // namespace UnrealVoxelSim::Movement::Api
