#pragma once

#include <compare>
#include <cstdint>

namespace UnrealVoxelSim::Movement::Api
{

class ProfileId final
{
  public:
    constexpr ProfileId() noexcept = default;
    explicit constexpr ProfileId(const std::uint32_t value) noexcept : Value_(value)
    {
    }

    [[nodiscard]] constexpr bool IsValid() const noexcept { return Value_ != 0; }
    [[nodiscard]] constexpr std::uint32_t Value() const noexcept { return Value_; }
    auto operator<=>(const ProfileId &) const = default;

  private:
    std::uint32_t Value_{};
};

} // namespace UnrealVoxelSim::Movement::Api
