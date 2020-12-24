#ifndef TESTING_INTERNAL_GTEST-DEATH-TEST-INTERNAL_H
#define TESTING_INTERNAL_GTEST-DEATH-TEST-INTERNAL_H


namespace testing {

namespace internal {

typedef DeathTestFactory typedef3;
// A concrete DeathTestFactory implementation for normal use.
class DefaultDeathTestFactory : public typedef3 {
  public:
    virtual bool Create(const char * statement, const RE * regex, const char * file, int line, DeathTest * * test);

};

} // namespace testing::internal

} // namespace testing
#endif
