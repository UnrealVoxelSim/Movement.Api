#include "UnrealVoxelSim/Movement/Api/GroundedProfile.h"
#include <gtest/gtest.h>

namespace UnrealVoxelSim::Movement::Api
{
TEST(ProfileTest, StandardHumanShapeAndCapabilitiesAreConfigurable)
{
    constexpr GroundedProfile profile{ProfileId{1}};
    static_assert(profile.IsValid());
    EXPECT_EQ(profile.Width, 1);
    EXPECT_EQ(profile.Length, 1);
    EXPECT_EQ(profile.Height, 2);
    EXPECT_EQ(profile.MaximumRise, 1);
    EXPECT_EQ(profile.MaximumDrop, 4);
}
}
