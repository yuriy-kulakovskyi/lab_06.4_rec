#include <gtest/gtest.h>
#include "../include/main.h"

TEST(FindTheLargest, PositiveNumbers) {
  int a[] = {1, 2, 3, 4, 5};
  int n = 5;

  EXPECT_EQ(5, FindTheLargest(a, n, 0));
}

TEST(Sum, PositiveNumbers) {
  const int n = 5;
  int a[n] = {-1, 2, -4, -9, 5};

  EXPECT_EQ(-13, Sum(a, n, 0, 0));
}

TEST(Sort, PositiveNumbers) {
  const int n = 5;
  int a[n] = {1, 0, 2, 0, 3};

  Sort(a, n);

  EXPECT_EQ(1, a[0]);
  EXPECT_EQ(2, a[1]);
  EXPECT_EQ(3, a[2]);
  EXPECT_EQ(0, a[3]);
  EXPECT_EQ(0, a[4]);
}