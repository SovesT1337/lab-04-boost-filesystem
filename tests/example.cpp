// Copyright 2021 SovesT

#include <gtest/gtest.h>

#include <magic.hpp>
#include <stdexcept>

TEST(Example, EmptyTest) {
    EXPECT_THROW(example(), std::runtime_error);
}
