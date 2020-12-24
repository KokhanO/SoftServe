#ifndef _GTEST-PARAM-TEST_H
#define _GTEST-PARAM-TEST_H


// To write value-parameterized tests, first you should define a fixture
// class. It is usually derived from testing::TestWithParam<T> (see below for
// another inheritance scheme that's sometimes useful in more complicated
// class hierarchies), where the type of your parameter values.
// TestWithParam<T> is itself derived from testing::Test. T can be any
// copyable type. If it's a raw pointer, you are responsible for managing the
// lifespan of the pointed values.
class FooTest : public testing::TestWithParam<const char*> {
};
typedef ::testing::Test typedef1;
// The tests from the instantiation above will have these names:
//
//    * AnotherInstantiationName/FooTest.DoesBlah/0 for "cat"
//    * AnotherInstantiationName/FooTest.DoesBlah/1 for "dog"
//    * AnotherInstantiationName/FooTest.HasBlahBlah/0 for "cat"
//    * AnotherInstantiationName/FooTest.HasBlahBlah/1 for "dog"
//
// Please note that INSTANTIATE_TEST_CASE_P will instantiate all tests
// in the given test case, whether their definitions come before or
// AFTER the INSTANTIATE_TEST_CASE_P statement.
//
// Please also note that generator expressions (including parameters to the
// generators) are evaluated in InitGoogleTest(), after main() has started.
// This allows the user on one hand, to adjust generator parameters in order
// to dynamically determine a set of tests to run and on the other hand,
// give the user a chance to inspect the generated tests with Google Test
// reflection API before RUN_ALL_TESTS() is executed.
//
// You can see samples/sample7_unittest.cc and samples/sample8_unittest.cc
// for more examples.
//
// In the future, we plan to publish the API for defining new parameter
// generators. But for now this interface remains part of the internal
// implementation and is subject to change.
//
//
// A parameterized test fixture must be derived from testing::Test and from
// testing::WithParamInterface<T>, where T is the type of the parameter
// values. Inheriting from TestWithParam<T> satisfies that requirement because
// TestWithParam<T> inherits from both Test and WithParamInterface. In more
// complicated hierarchies, however, it is occasionally useful to inherit
// separately from Test and WithParamInterface. For example:
class BaseTest : public typedef1 {
};
// You can inherit all the usual members for a non-parameterized test
// fixture here.
class DerivedTest : public BaseTest, public testing::WithParamInterface<int> {
};
#endif
