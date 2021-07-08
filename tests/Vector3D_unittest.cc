#include "gtest/gtest.h"
#include "vector3D.h"
#include <cmath>
#include <vector>


namespace csci3081 {
class Vector3DTest : public ::testing::Test {
 public:
  void SetUp() { 

	vec2 = Vector3D(25.4f, 32.5f, 0.f);
    vec3 = Vector3D(4.3f, 10.f, 7.4f);
  }
 protected:
  Vector3D vec2;       
  Vector3D vec3;           
};



TEST_F(Vector3DTest, MagnitudeTest) {
  Vector3D ZeroVec(0.f, 0.f, 0.f);
  
  EXPECT_LT(fabs(vec3.GetMagnitude()) - 13.162447f, 0.001f);
  EXPECT_LT(fabs(vec2.GetMagnitude() - 41.24815f), 0.001f);
  EXPECT_EQ(ZeroVec.GetMagnitude(), 0.f);
}

TEST_F(Vector3DTest, NormalizedVectorTest) {
  Vector3D testVec(1.f, 10.f, 7.4f);
  float testVecMag = testVec.GetMagnitude();

  std::vector<float> normTest;
  normTest.push_back(testVec.GetVector().at(0) / testVecMag);
  normTest.push_back(testVec.GetVector().at(1) / testVecMag);
  normTest.push_back(testVec.GetVector().at(2) / testVecMag);
  Vector3D normvec = testVec.GetNormalizedVector();
  
  EXPECT_EQ(normvec.GetVector()[0], normTest[0]);
  EXPECT_EQ(normvec.GetVector()[1], normTest[1]);
  EXPECT_EQ(normvec.GetVector()[2], normTest[2]);
}

TEST_F(Vector3DTest, ConstructorTest) {
  Vector3D vec_1(24.f, -1.2f, 0.f);
  Vector3D vec_2(0.f, 0.f, 0.f);

  std::vector<float> test_1{24.f, -1.2f, 0.f};
  std::vector<float> test_2{0.f, 0.f, 0.f};

  EXPECT_EQ(vec_1.GetVector()[0], test_1[0]);
  EXPECT_EQ(vec_1.GetVector()[1], test_1[1]);
  EXPECT_EQ(vec_1.GetVector()[2], test_1[2]);
  EXPECT_EQ(vec_2.GetVector()[0], test_2[0]);
  EXPECT_EQ(vec_2.GetVector()[1], test_2[1]);
  EXPECT_EQ(vec_2.GetVector()[2], test_2[2]);

}

}


