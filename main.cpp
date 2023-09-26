// in my_gtest_demo_1.cc
#include <gtest/gtest.h>

//class TestUnit : public testing::Environment {
//};

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);

//    testing::AddGlobalTestEnvironment(new TestUnit);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
