#ifndef TESTING_GTEST-PARAM-UTIL_H
#define TESTING_GTEST-PARAM-UTIL_H


namespace testing {

// Input to a parameterized test name generator, describing a test parameter.
// Consists of the parameter value and the integer parameter index.
template<class ParamType>
struct TestParamInfo {
    inline TestParamInfo(const ParamType & a_param, size_t an_index) :
        param(a_param),
        index(an_index) {};

    ParamType param;

    size_t index;

};
// A builtin parameterized test name generator which returns the result of
// testing::PrintToString.
struct PrintToStringParamName {
    template<class ParamType>
    inline std::string operator ()(const TestParamInfo<ParamType> & info) const {
        return PrintToString(info.param);
      };

};

} // namespace testing
#endif
