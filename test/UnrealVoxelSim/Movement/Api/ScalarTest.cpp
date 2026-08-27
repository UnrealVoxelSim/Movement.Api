#include "UnrealVoxelSim/Movement/Api/Scalar.h"
#include <gtest/gtest.h>

namespace UnrealVoxelSim::Movement::Api
{
TEST(ScalarTest, RepresentsWholeVoxelExactly)
{
    constexpr auto value = Scalar::FromWhole(-3);
    static_assert(value.Raw() == -3 * Scalar::OneRaw);
    EXPECT_DOUBLE_EQ(value.ToDouble(), -3.0);
}
}
