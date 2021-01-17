#include "gmock/gmock.h"    

#include "common.hh"
#include "vec.hh"
using namespace raytracer;
using testing::Eq;
class TupleTest: public testing::Test {
public:
   Vector vec;
};


TEST_F(TupleTest, RetainsSoleLetterOfOneLetterWord) {
   ASSERT_THAT(soundex.encode("A"), Eq("A000")); 
}

TEST_F(TupleTest, PadsWithZerosToEnsureThreeDigits) {
   ASSERT_THAT(soundex.encode("I"), Eq("I000"));
}

TEST_F(TupleTest, ReplacesConsonantsWithAppropriateDigits) {
   ASSERT_THAT(soundex.encode("Ab"), Eq("A100"));
}