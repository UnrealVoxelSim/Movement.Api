#pragma once

#include "UnrealVoxelSim/Movement/Api/ProfileId.h"
#include "UnrealVoxelSim/Movement/Api/Scalar.h"

#include <cstdint>

namespace UnrealVoxelSim::Movement::Api
{
	struct GroundedProfile final
	{
		ProfileId Id;
		std::uint16_t Width{1};
		std::uint16_t Length{1};
		std::uint16_t Height{2};
		std::uint16_t MaximumRise{1};
		std::uint16_t MaximumDrop{4};
		Scalar MaximumSpeed{Scalar::FromWhole(4)};
		Scalar JumpSpeed{Scalar::FromWhole(7)};
		Scalar Gravity{Scalar::FromWhole(-20)};
		Scalar CollisionSkin{Scalar::FromRaw(Scalar::OneRaw / 16)};

		[[nodiscard]] constexpr bool IsValid() const noexcept
		{
			return Id.IsValid() && Width != 0 && Length != 0 && Height != 0 && MaximumSpeed.Raw() > 0 &&
				JumpSpeed.Raw() > 0 && Gravity.Raw() < 0 && CollisionSkin.Raw() >= 0 &&
				CollisionSkin.Raw() < static_cast<std::int64_t>(Width) * Scalar::OneRaw / 2 &&
				CollisionSkin.Raw() < static_cast<std::int64_t>(Length) * Scalar::OneRaw / 2;
		}
	};
}
