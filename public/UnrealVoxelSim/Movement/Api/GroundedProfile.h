#pragma once

#include "UnrealVoxelSim/Math/Api/FixedPointScalar.h"
#include "UnrealVoxelSim/Movement/Api/ProfileId.h"

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
		Math::Api::FixedPointScalar MaximumSpeed{Math::Api::FixedPointScalar::FromWhole(4)};
		Math::Api::FixedPointScalar JumpSpeed{Math::Api::FixedPointScalar::FromWhole(7)};
		Math::Api::FixedPointScalar Gravity{Math::Api::FixedPointScalar::FromWhole(-20)};
		Math::Api::FixedPointScalar CollisionSkin{
			Math::Api::FixedPointScalar::FromRaw(Math::Api::FixedPointScalar::OneRaw / 16)
		};

		[[nodiscard]] constexpr bool IsValid() const noexcept
		{
			return Id.IsValid() && Width != 0 && Length != 0 && Height != 0 && MaximumSpeed.Raw() > 0 &&
				JumpSpeed.Raw() > 0 && Gravity.Raw() < 0 && CollisionSkin.Raw() >= 0 &&
				CollisionSkin.Raw() < static_cast<std::int64_t>(Width) * Math::Api::FixedPointScalar::OneRaw / 2 &&
				CollisionSkin.Raw() < static_cast<std::int64_t>(Length) * Math::Api::FixedPointScalar::OneRaw / 2;
		}
	};
}
