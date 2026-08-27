#pragma once

#include <compare>
#include <cstdint>

namespace UnrealVoxelSim::Movement::Api
{

class ProfileId final
{
  public:
    constexpr ProfileId() noexcept = default;
    explicit constexpr ProfileId(const std::uint32_t value) noexcept : m_Value(value)
    {
    }

    [[nodiscard]] constexpr bool IsValid() const noexcept { return m_Value != 0; }
    [[nodiscard]] constexpr std::uint32_t Value() const noexcept { return m_Value; }
    auto operator<=>(const ProfileId &) const = default;

  private:
    std::uint32_t m_Value{};
};

} // namespace UnrealVoxelSim::Movement::Api
