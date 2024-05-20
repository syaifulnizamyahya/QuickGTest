#include <iostream>
#include <tuple>
#include <gtest/gtest.h>

// Clone googletest in googletest folder.
// Open in VSCode.
// In VSCode, "Clear All Results" first. Then run the tests.
int main(int argc, char *argv[])
{
    std::cout << "Hello, from QuickGTest!\n";
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

int FirstFactorial(int num)
{
    auto result = 1;
    for (size_t i = 1; i <= num; i++)
    {
        result *= i;
    }
    return result;
}

class MyUnitTest : public ::testing::TestWithParam<std::tuple<int, int>>
{
};

// INSTANTIATE_TEST_CASE_P( // old gtest
INSTANTIATE_TEST_SUITE_P(// new gtest
    MyInstantiation,
    MyUnitTest,
    ::testing::Values(
        // (Input, Expected)
        std::make_tuple(4, 24)));

TEST_P(MyUnitTest, PositiveFactorialTests)
{
    // Arrange
    auto expected = std::get<1>(GetParam());

    // Act
    auto actual = FirstFactorial(std::get<0>(GetParam()));

    // Assert
    EXPECT_EQ(expected, actual);
    EXPECT_TRUE(true);
}

TEST(TestCaseName, TestName)
{
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}
