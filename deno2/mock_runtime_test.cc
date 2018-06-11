// Copyright 2018 Ryan Dahl <ry@tinyclouds.org>
// All rights reserved. MIT License.
#include "testing/gtest/include/gtest/gtest.h"

#include "include/deno.h"

TEST(MockRuntimeTest, InitializesCorrectly) {
  Deno* d = deno_new(NULL, NULL);
  EXPECT_TRUE(deno_load(d, "a.js", "1 + 2"));
}

TEST(MockRuntimeTest, CanCallFoo) {
  Deno* d = deno_new(NULL, NULL);
  EXPECT_TRUE(deno_load(d, "a.js", "if (foo() != 'foo') throw Error();"));
}

TEST(MockRuntimeTest, ErrorsCorrectly) {
  Deno* d = deno_new(NULL, NULL);
  EXPECT_FALSE(deno_load(d, "a.js", "throw Error()"));
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  deno_init();
  return RUN_ALL_TESTS();
}
