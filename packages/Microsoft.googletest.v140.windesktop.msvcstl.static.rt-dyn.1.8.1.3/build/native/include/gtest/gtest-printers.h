#ifndef TESTING_INTERNAL_GTEST-PRINTERS_H
#define TESTING_INTERNAL_GTEST-PRINTERS_H


namespace testing {

namespace internal {

// namespace testing_internal
// FormatForComparison<ToPrint, OtherOperand>::Format(value) formats a
// value of type ToPrint that is an operand of a comparison assertion
// (e.g. ASSERT_EQ).  OtherOperand is the type of the other operand in
// the comparison, and is used to help determine the best way to
// format the value.  In particular, when the value is a C string
// (char pointer) and the other operand is an STL string object, we
// want to format the C string as a string, since we know it is
// compared by value with the string object.  If the value is a char
// pointer but the other operand is not an STL string object, we don't
// know whether the pointer is supposed to point to a NUL-terminated
// string, and thus want to print it as a pointer to be safe.
//
// INTERNAL IMPLEMENTATION - DO NOT USE IN A USER PROGRAM.
// The default case.
template<typename ToPrint, typename OtherOperand>
class FormatForComparison {
  public:
    static inline ::std::string Format(const ToPrint & value) {
        return ::testing::PrintToString(value);
      };

};
// Array.
template<typename ToPrint,  size_t N, typename OtherOperand>
class FormatForComparison<ToPrint[N],OtherOperand> {
  public:
    static inline ::std::string Format(const ToPrint * value) {
        return FormatForComparison<const ToPrint*, OtherOperand>::Format(value);
      };

};
enum DefaultPrinterType {
  kPrintContainer,
  kPrintPointer,
  kPrintFunctionPointer,
  kPrintOther
};
template<DefaultPrinterType type>
struct WrapPrinterType {
};
// Implements printing a non-reference type T by letting the compiler
// pick the right overload of PrintTo() for T.
template<typename T>
class UniversalPrinter {
};
// Implements printing an array type T[N].
template<typename T,  size_t N>
class UniversalPrinter<T[N]> {
  public:
    // Prints the given array, omitting some elements when there are too
    // many.
    static void Print();

};
// Prints the given array, omitting some elements when there are too
// many.
template<typename T,  size_t N>
void UniversalPrinter<T[N]><T, N>::Print()
{
}

// Implements printing a reference type T&.
template<typename T>
class UniversalPrinter<T&> {
};
template<typename T>
class UniversalTersePrinter<T&> {
  public:
    static inline void Print(const T & value, ::std::ostream * os) {
        UniversalPrint(value, os);
      };

};
template<typename T,  size_t N>
class UniversalTersePrinter<T[N]> {
  public:
    static void Print();

};
template<typename T,  size_t N>
void UniversalTersePrinter<T[N]><T, N>::Print()
{
}

template<>
class UniversalTersePrinter<const char*> {
  public:
    static inline void Print(const char * str, ::std::ostream * os) {
        if (str == NULL) {
          *os << "NULL";
        } else {
          UniversalPrint(std::string(str), os);
        }
      };

};
template<>
class UniversalTersePrinter<char*> {
  public:
    static inline void Print(char * str, ::std::ostream * os) {
        UniversalTersePrinter<const char*>::Print(str, os);
      };

};
template<>
class UniversalTersePrinter<const wchar_t*> {
  public:
    static inline void Print(const wchar_t * str, ::std::ostream * os) {
        if (str == NULL) {
          *os << "NULL";
        } else {
          UniversalPrint(::std::wstring(str), os);
        }
      };

};
template<>
class UniversalTersePrinter<wchar_t*> {
  public:
    static inline void Print(wchar_t * str, ::std::ostream * os) {
        UniversalTersePrinter<const wchar_t*>::Print(str, os);
      };

};
typedef ::std::vector< ::std::string> Strings;
template<typename TupleT>
struct TuplePolicy {
    typedef TupleT Tuple;

    static const size_t tuple_size=  ::std::tr1::tuple_size<Tuple>::value;

    template<size_t I>
    struct tuple_element : private typedef2 {
    };
    
    typedef ::std::tr1::tuple_element<static_cast<int>(I), Tuple> typedef2;

    template<size_t I>
    static inline typename AddReference<const typename ::std::tr1::tuple_element<
      static_cast<int>(I), Tuple>::type>::type get(const Tuple & tuple) {
        return ::std::tr1::get<I>(tuple);
      };

};
template<typename TupleT>
const size_t TuplePolicy<TupleT>::tuple_size;

// This helper template allows PrintTo() for tuples and
// UniversalTersePrintTupleFieldsToStrings() to be defined by
// induction on the number of tuple fields.  The idea is that
// TuplePrefixPrinter<N>::PrintPrefixTo(t, os) prints the first N
// fields in tuple t, and can be defined in terms of
// TuplePrefixPrinter<N - 1>.
//
// The inductive case.
template<size_t N>
struct TuplePrefixPrinter {
    // Prints the first N fields of a tuple.
    template<typename Tuple>
    static inline void PrintPrefixTo(const Tuple & t, ::std::ostream * os) {
        TuplePrefixPrinter<N - 1>::PrintPrefixTo(t, os);
        GTEST_INTENTIONAL_CONST_COND_PUSH_()
        if (N > 1) {
        GTEST_INTENTIONAL_CONST_COND_POP_()
          *os << ", ";
        }
        UniversalPrinter<
            typename TuplePolicy<Tuple>::template tuple_element<N - 1>::type>
            ::Print(TuplePolicy<Tuple>::template get<N - 1>(t), os);
      };

    // Tersely prints the first N fields of a tuple to a string vector,
    // one element for each field.
    template<typename Tuple>
    static inline void TersePrintPrefixToStrings(const Tuple & t, Strings * strings) {
        TuplePrefixPrinter<N - 1>::TersePrintPrefixToStrings(t, strings);
        ::std::stringstream ss;
        UniversalTersePrint(TuplePolicy<Tuple>::template get<N - 1>(t), &ss);
        strings->push_back(ss.str());
      };

};
// Base case.
template<>
struct TuplePrefixPrinter<0> {
    template<typename Tuple>
    static inline void PrintPrefixTo(const Tuple & , ::std::ostream * ) {};

    template<typename Tuple>
    static inline void TersePrintPrefixToStrings(const Tuple & , Strings * ) {};

};

} // namespace testing::internal

} // namespace testing
#endif
