#ifndef TESTING_INTERNAL_GTEST-INTERNAL_H
#define TESTING_INTERNAL_GTEST-INTERNAL_H


namespace testing {

namespace internal {

// This template class represents an IEEE floating-point number
// (either single-precision or double-precision, depending on the
// template parameters).
//
// The purpose of this class is to do more sophisticated number
// comparison.  (Due to round-off error, etc, it's very unlikely that
// two floating-points will be equal exactly.  Hence a naive
// comparison by the == operation often doesn't work.)
//
// Format of IEEE floating-point:
//
//   The most-significant bit being the leftmost, an IEEE
//   floating-point looks like
//
//     sign_bit exponent_bits fraction_bits
//
//   Here, sign_bit is a single bit that designates the sign of the
//   number.
//
//   For float, there are 8 exponent bits and 23 fraction bits.
//
//   For double, there are 11 exponent bits and 52 fraction bits.
//
//   More details can be found at
//   http://en.wikipedia.org/wiki/IEEE_floating-point_standard.
//
// Template parameter:
//
//   RawType: the raw floating-point type (either float or double)
template<typename RawType>
class FloatingPoint {
  public:
    typedef  typename TypeWithSize<sizeof(RawType)>::UInt Bits;

    // Constants.
    // # of bits in a number.
    
    static const size_t kBitCount=  8*sizeof(RawType);

    // # of fraction bits in a number.
    
    static const size_t kFractionBitCount= 
    std::numeric_limits<RawType>::digits - 1;

    // # of exponent bits in a number.
    
    static const size_t kExponentBitCount=  kBitCount - 1 - kFractionBitCount;

    // The mask for the sign bit.
    
    static const Bits kSignBitMask=  static_cast<Bits>(1) << (kBitCount - 1);

    // The mask for the fraction bits.
    
    static const Bits kFractionBitMask= 
    ~static_cast<Bits>(0) >> (kExponentBitCount + 1);

    // The mask for the exponent bits.
    
    static const Bits kExponentBitMask=  ~(kSignBitMask | kFractionBitMask);

    // How many ULP's (Units in the Last Place) we want to tolerate when
    // comparing two numbers.  The larger the value, the more error we
    // allow.  A 0 value means that two numbers must be exactly the same
    // to be considered equal.
    //
    // The maximum error of a single floating-point operation is 0.5
    // units in the last place.  On Intel CPU's, all floating-point
    // calculations are done with 80-bit precision, while double has 64
    // bits.  Therefore, 4 should be enough for ordinary use.
    //
    // See the following article for more details on ULP:
    // http://randomascii.wordpress.com/2012/02/25/comparing-floating-point-numbers-2012-edition/
    
    static const size_t kMaxUlps=  4;

    // Constructs a FloatingPoint from a raw floating-point number.
    //
    // On an Intel CPU, passing a non-normalized NAN (Not a Number)
    // around may change its bits, although the new value is guaranteed
    // to be also a NAN.  Therefore, don't expect this constructor to
    // preserve the bits in x when x is a NAN.
    inline explicit FloatingPoint(const RawType & x) { u_.value_ = x; };

    // Static methods
    // Reinterprets a bit pattern as a floating-point number.
    //
    // This function is needed to test the AlmostEquals() method.
    static inline RawType ReinterpretBits(const Bits bits) {
        FloatingPoint fp(0);
        fp.u_.bits_ = bits;
        return fp.u_.value_;
      };

    // Returns the floating-point number that represent positive infinity.
    static inline RawType Infinity() {
        return ReinterpretBits(kExponentBitMask);
      };

    // Returns the maximum representable finite floating-point number.
    static RawType Max();

    // Non-static methods
    // Returns the bits that represents this number.
    inline const Bits & bits() const { return u_.bits_; };

    // Returns the exponent bits of this number.
    inline Bits exponent_bits() const { return kExponentBitMask & u_.bits_; };

    // Returns the fraction bits of this number.
    inline Bits fraction_bits() const { return kFractionBitMask & u_.bits_; };

    // Returns the sign bit of this number.
    inline Bits sign_bit() const { return kSignBitMask & u_.bits_; };

    // Returns true iff this is NAN (not a number).
    inline bool is_nan() const {
        // It's a NAN if the exponent bits are all ones and the fraction
        // bits are not entirely zeros.
        return (exponent_bits() == kExponentBitMask) && (fraction_bits() != 0);
      };

    // Returns true iff this number is at most kMaxUlps ULP's away from
    // rhs.  In particular, this function:
    //
    //   - returns false if either number is (or both are) NAN.
    //   - treats really large numbers as almost equal to infinity.
    //   - thinks +0.0 and -0.0 are 0 DLP's apart.
    inline bool AlmostEquals(const FloatingPoint<RawType> & rhs) const {
        // The IEEE standard says that any comparison operation involving
        // a NAN must return false.
        if (is_nan() || rhs.is_nan()) return false;
    
        return DistanceBetweenSignAndMagnitudeNumbers(u_.bits_, rhs.u_.bits_)
            <= kMaxUlps;
      };

    union FloatingPointUnion {
        // The raw floating-point number.
        RawType value_;

        // The bits that represent the number.
        Bits bits_;

    };
    

  private:
    // Converts an integer from the sign-and-magnitude representation to
    // the biased representation.  More precisely, let N be 2 to the
    // power of (kBitCount - 1), an integer x is represented by the
    // unsigned number x + N.
    //
    // For instance,
    //
    //   -N + 1 (the most negative number representable using
    //          sign-and-magnitude) is represented by 1;
    //   0      is represented by N; and
    //   N - 1  (the biggest number representable using
    //          sign-and-magnitude) is represented by 2N - 1.
    //
    // Read http://en.wikipedia.org/wiki/Signed_number_representations
    // for more details on signed number representations.
    static inline Bits SignAndMagnitudeToBiased(const Bits & sam) {
        if (kSignBitMask & sam) {
          // sam represents a negative number.
          return ~sam + 1;
        } else {
          // sam represents a positive number.
          return kSignBitMask | sam;
        }
      };

    // Given two numbers in the sign-and-magnitude representation,
    // returns the distance between them as an unsigned number.
    static inline Bits DistanceBetweenSignAndMagnitudeNumbers(const Bits & sam1, const Bits & sam2) {
        const Bits biased1 = SignAndMagnitudeToBiased(sam1);
        const Bits biased2 = SignAndMagnitudeToBiased(sam2);
        return (biased1 >= biased2) ? (biased1 - biased2) : (biased2 - biased1);
      };

    FloatingPointUnion u_;

};
// Constants.
// # of bits in a number.

template<typename RawType>
const size_t FloatingPoint<RawType>::kBitCount;

// # of fraction bits in a number.

template<typename RawType>
const size_t FloatingPoint<RawType>::kFractionBitCount;

// # of exponent bits in a number.

template<typename RawType>
const size_t FloatingPoint<RawType>::kExponentBitCount;

// The mask for the sign bit.

template<typename RawType>
const FloatingPoint::Bits FloatingPoint<RawType>::kSignBitMask;

// The mask for the fraction bits.

template<typename RawType>
const FloatingPoint::Bits FloatingPoint<RawType>::kFractionBitMask;

// The mask for the exponent bits.

template<typename RawType>
const FloatingPoint::Bits FloatingPoint<RawType>::kExponentBitMask;

// How many ULP's (Units in the Last Place) we want to tolerate when
// comparing two numbers.  The larger the value, the more error we
// allow.  A 0 value means that two numbers must be exactly the same
// to be considered equal.
//
// The maximum error of a single floating-point operation is 0.5
// units in the last place.  On Intel CPU's, all floating-point
// calculations are done with 80-bit precision, while double has 64
// bits.  Therefore, 4 should be enough for ordinary use.
//
// See the following article for more details on ULP:
// http://randomascii.wordpress.com/2012/02/25/comparing-floating-point-numbers-2012-edition/

template<typename RawType>
const size_t FloatingPoint<RawType>::kMaxUlps;

// We cannot use std::numeric_limits<T>::max() as it clashes with the max()
// macro defined by <windows.h>.

template<>
inline RawType FloatingPoint<float>::Max() {
 return FLT_MAX;
}

template<>
inline RawType FloatingPoint<double>::Max() {
 return DBL_MAX;
}

// Typedefs the instances of the FloatingPoint template class that we
// care to use.
typedef FloatingPoint<float> Float;
typedef FloatingPoint<double> Double;
// In order to catch the mistake of putting tests that use different
// test fixture classes in the same test case, we need to assign
// unique IDs to fixture classes and compare them.  The TypeId type is
// used to hold such IDs.  The user should treat TypeId as an opaque
// type: the only operation allowed on TypeId values is to compare
// them for equality using the == operator.
typedef  const void*  TypeId;
template<typename T>
class TypeIdHelper {
  public:
    // dummy_ must not have a const type.  Otherwise an overly eager
    // compiler (e.g. MSVC 7.1 & 8.0) may try to merge
    // TypeIdHelper<T>::dummy_ for different Ts as an "optimization".
    
    static bool dummy_;

};
// dummy_ must not have a const type.  Otherwise an overly eager
// compiler (e.g. MSVC 7.1 & 8.0) may try to merge
// TypeIdHelper<T>::dummy_ for different Ts as an "optimization".

template<typename T>
bool TypeIdHelper<T>::dummy_= false;

// Defines the abstract factory interface that creates instances
// of a Test object.
class TestFactoryBase {
  public:
    inline virtual ~TestFactoryBase() {};

    // Creates a test instance to run. The instance is both created and destroyed
    // within TestInfoImpl::Run()
    virtual Test * CreateTest() = 0;


  protected:
    inline TestFactoryBase() {};

};
// This class provides implementation of TeastFactoryBase interface.
// It is used in TEST and TEST_F macros.
template<class TestClass>
class TestFactoryImpl : public TestFactoryBase {
  public:
    inline virtual Test * CreateTest() { return new TestClass; };

};
// Types of SetUpTestCase() and TearDownTestCase() functions.
typedef void(* SetUpTestCaseFunc)();
typedef void(* TearDownTestCaseFunc)();
struct CodeLocation {
    inline CodeLocation(const std::string & a_file, int a_line) : file(a_file), line(a_line) {};

    std::string file;

    int line;

};
// The default argument to the template below for the case when the user does
// not provide a name generator.
struct DefaultNameGenerator {
    template<typename T>
    static inline std::string GetName(int i) {
        return StreamableToString(i);
      };

};
template<typename Provided = DefaultNameGenerator>
struct NameGeneratorSelector {
    typedef Provided type;

};
// TypeParameterizedTest<Fixture, TestSel, Types>::Register()
// registers a list of type-parameterized tests with Google Test.  The
// return value is insignificant - we just need to return something
// such that we can call this function in a namespace scope.
//
// Implementation note: The GTEST_TEMPLATE_ macro declares a template
// template parameter.  It's defined in gtest-type-util.h.
template<GTEST_TEMPLATE_ Fixture, class TestSel, typename Types>
class TypeParameterizedTest {
  public:
    // 'index' is the index of the test in the type list 'Types'
    // specified in INSTANTIATE_TYPED_TEST_CASE_P(Prefix, TestCase,
    // Types).  Valid values for 'index' are [0, N - 1] where N is the
    // length of Types.
    static inline bool Register(const char * prefix, const CodeLocation & code_location, const char * case_name, const char * test_names, int index, const std::vector<std::string> & type_names = 
                           GenerateNames<DefaultNameGenerator, Types>()) {
        typedef typename Types::Head Type;
        typedef Fixture<Type> FixtureClass;
        typedef typename GTEST_BIND_(TestSel, Type) TestClass;
    
        // First, registers the first type-parameterized test in the type
        // list.
        MakeAndRegisterTestInfo(
            (std::string(prefix) + (prefix[0] == '\0' ? "" : "/") + case_name +
             "/" + type_names[index])
                .c_str(),
            StripTrailingSpaces(GetPrefixUntilComma(test_names)).c_str(),
            GetTypeName<Type>().c_str(),
            NULL,  // No value parameter.
            code_location, GetTypeId<FixtureClass>(), TestClass::SetUpTestCase,
            TestClass::TearDownTestCase, new TestFactoryImpl<TestClass>);
    
        // Next, recurses (at compile time) with the tail of the type list.
        return TypeParameterizedTest<Fixture, TestSel,
                                     typename Types::Tail>::Register(prefix,
                                                                     code_location,
                                                                     case_name,
                                                                     test_names,
                                                                     index + 1,
                                                                     type_names);
      };

};
// The base case for the compile time recursion.
template<GTEST_TEMPLATE_ Fixture, class TestSel>
class TypeParameterizedTest<Fixture,TestSel,Types0> {
  public:
    static inline bool Register(const char * , const CodeLocation & , const char * , const char * , int , const std::vector<std::string> &  = 
                           std::vector<std::string>() /*type_names*/) {
        return true;
      };

};
// TypeParameterizedTestCase<Fixture, Tests, Types>::Register()
// registers *all combinations* of 'Tests' and 'Types' with Google
// Test.  The return value is insignificant - we just need to return
// something such that we can call this function in a namespace scope.
template<GTEST_TEMPLATE_ Fixture, typename Tests, typename Types>
class TypeParameterizedTestCase {
  public:
    static inline bool Register(const char * prefix, CodeLocation code_location, const TypedTestCasePState * state, const char * case_name, const char * test_names, const std::vector<std::string> & type_names = 
                           GenerateNames<DefaultNameGenerator, Types>()) {
        std::string test_name = StripTrailingSpaces(
            GetPrefixUntilComma(test_names));
        if (!state->TestExists(test_name)) {
          fprintf(stderr, "Failed to get code location for test %s.%s at %s.",
                  case_name, test_name.c_str(),
                  FormatFileLocation(code_location.file.c_str(),
                                     code_location.line).c_str());
          fflush(stderr);
          posix::Abort();
        }
        const CodeLocation& test_location = state->GetCodeLocation(test_name);
    
        typedef typename Tests::Head Head;
    
        // First, register the first test in 'Test' for each type in 'Types'.
        TypeParameterizedTest<Fixture, Head, Types>::Register(
            prefix, test_location, case_name, test_names, 0, type_names);
    
        // Next, recurses (at compile time) with the tail of the test list.
        return TypeParameterizedTestCase<Fixture, typename Tests::Tail,
                                         Types>::Register(prefix, code_location,
                                                          state, case_name,
                                                          SkipComma(test_names),
                                                          type_names);
      };

};
// The base case for the compile time recursion.
template<GTEST_TEMPLATE_ Fixture, typename Types>
class TypeParameterizedTestCase<Fixture,Templates0,Types> {
  public:
    static inline bool Register(const char * , const CodeLocation & , const TypedTestCasePState * , const char * , const char * , const std::vector<std::string> &  = 
                           std::vector<std::string>() /*type_names*/) {
        return true;
      };

};

} // namespace testing::internal

} // namespace testing
#endif
