#include <gtest/gtest.h>

TEST(basic_dijikstra, a_first_test)
{
  std::cout << "Got to test";
  ASSERT_EQ(4, 2 + 2);
}

int main(int argc, char ** argv)
{
  testing::InitGoogleTest(&argc, argv);
  std::cout << "Got to main";
  return RUN_ALL_TESTS();
}
