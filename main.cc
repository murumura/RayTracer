#include "gmock/gmock.h"  // Brings in Google Mock.
int main(int argc, char **argv){
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}