#pragma once

#include <compare>
#include <cstdint>

namespace UnrealVoxelSim::Movement::Api
{
	// TODO Scalar is very generic concept, it should not be defined inside Movement.Api. Either rename it into something Movement-specific, or move it to separate dedicated module.
	class Scalar final
	{
	public:
		static constexpr unsigned FractionBits = 32;
		static constexpr std::int64_t OneRaw = std::int64_t{1} << FractionBits;

		constexpr Scalar() noexcept = default;

		[[nodiscard]] static constexpr Scalar FromRaw(const std::int64_t raw) noexcept
		{
			return Scalar{raw};
		}

		[[nodiscard]] static constexpr Scalar FromWhole(const std::int32_t whole) noexcept
		{
			return Scalar{static_cast<std::int64_t>(whole) * OneRaw};
		}

		[[nodiscard]] constexpr std::int64_t Raw() const noexcept
		{
			return m_Raw;
		}

		[[nodiscard]] double ToDouble() const noexcept
		{
			return static_cast<double>(m_Raw) / static_cast<double>(OneRaw);
		}

		constexpr Scalar& operator+=(const Scalar right) noexcept
		{
			m_Raw += right.m_Raw;
			return *this;
		}

		constexpr Scalar& operator-=(const Scalar right) noexcept
		{
			m_Raw -= right.m_Raw;
			return *this;
		}

		auto operator<=>(const Scalar&) const = default;

	private:
		explicit constexpr Scalar(const std::int64_t raw) noexcept : m_Raw(raw)
		{
		}

		std::int64_t m_Raw{};
	};

	[[nodiscard]] constexpr Scalar operator+(Scalar left, const Scalar right) noexcept
	{
		left += right;
		return left;
	}

	[[nodiscard]] constexpr Scalar operator-(Scalar left, const Scalar right) noexcept
	{
		left -= right;
		return left;
	}

	[[nodiscard]] constexpr Scalar operator-(const Scalar value) noexcept
	{
		return Scalar::FromRaw(-value.Raw());
	}
}
