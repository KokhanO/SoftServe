#ifndef TESTING_GTEST-TYPE-UTIL_H
#define TESTING_GTEST-TYPE-UTIL_H


#include "gtest-type-util.h"

namespace testing {

// namespace internal
// We don't want to require the users to write TypesN<...> directly,
// as that would require them to count the length.  Types<...> is much
// easier to write, but generates horrible messages when there is a
// compiler error, as gcc insists on printing out each template
// argument, even if it has the default value (this means Types<int>
// will appear as Types<int, None, None, ..., None> in the compiler
// errors).
//
// Our solution is to combine the best part of the two approaches: a
// user would write Types<T1, ..., TN>, and Google Test will translate
// that to TypesN<T1, ..., TN> internally to make error messages
// readable.  The translation is done by the 'type' member of the
// Types template.
template<typename T1 = internal::None, typename T2 = internal::None, typename T3 = internal::None, typename T4 = internal::None, typename T5 = internal::None, typename T6 = internal::None, typename T7 = internal::None, typename T8 = internal::None, typename T9 = internal::None, typename T10 = internal::None, typename T11 = internal::None, typename T12 = internal::None, typename T13 = internal::None, typename T14 = internal::None, typename T15 = internal::None, typename T16 = internal::None, typename T17 = internal::None, typename T18 = internal::None, typename T19 = internal::None, typename T20 = internal::None, typename T21 = internal::None, typename T22 = internal::None, typename T23 = internal::None, typename T24 = internal::None, typename T25 = internal::None, typename T26 = internal::None, typename T27 = internal::None, typename T28 = internal::None, typename T29 = internal::None, typename T30 = internal::None, typename T31 = internal::None, typename T32 = internal::None, typename T33 = internal::None, typename T34 = internal::None, typename T35 = internal::None, typename T36 = internal::None, typename T37 = internal::None, typename T38 = internal::None, typename T39 = internal::None, typename T40 = internal::None, typename T41 = internal::None, typename T42 = internal::None, typename T43 = internal::None, typename T44 = internal::None, typename T45 = internal::None, typename T46 = internal::None, typename T47 = internal::None, typename T48 = internal::None, typename T49 = internal::None, typename T50 = internal::None>
struct Types {
    typedef internal::Types50<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12,
      T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26,
      T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40,
      T41, T42, T43, T44, T45, T46, T47, T48, T49, T50> type;

};
template<>
struct Types<internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None> {
    typedef testing::internal::Types0 type;

};
template<typename T1>
struct Types<T1,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None> {
    typedef internal::Types1<T1> type;

};
template<typename T1, typename T2>
struct Types<T1,T2,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None> {
    typedef internal::Types2<T1, T2> type;

};
template<typename T1, typename T2, typename T3>
struct Types<T1,T2,T3,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None> {
    typedef internal::Types3<T1, T2, T3> type;

};
template<typename T1, typename T2, typename T3, typename T4>
struct Types<T1,T2,T3,T4,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None> {
    typedef internal::Types4<T1, T2, T3, T4> type;

};
template<typename T1, typename T2, typename T3, typename T4, typename T5>
struct Types<T1,T2,T3,T4,T5,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None> {
    typedef internal::Types5<T1, T2, T3, T4, T5> type;

};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
struct Types<T1,T2,T3,T4,T5,T6,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None> {
    typedef internal::Types6<T1, T2, T3, T4, T5, T6> type;

};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
struct Types<T1,T2,T3,T4,T5,T6,T7,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None> {
    typedef internal::Types7<T1, T2, T3, T4, T5, T6, T7> type;

};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
struct Types<T1,T2,T3,T4,T5,T6,T7,T8,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None> {
    typedef internal::Types8<T1, T2, T3, T4, T5, T6, T7, T8> type;

};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
struct Types<T1,T2,T3,T4,T5,T6,T7,T8,T9,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None> {
    typedef internal::Types9<T1, T2, T3, T4, T5, T6, T7, T8, T9> type;

};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10>
struct Types<T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None> {
    typedef internal::Types10<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10> type;

};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11>
struct Types<T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None> {
    typedef internal::Types11<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11> type;

};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12>
struct Types<T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None> {
    typedef internal::Types12<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11,
      T12> type;

};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13>
struct Types<T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None> {
    typedef internal::Types13<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12,
      T13> type;

};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14>
struct Types<T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None> {
    typedef internal::Types14<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12,
      T13, T14> type;

};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15>
struct Types<T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None> {
    typedef internal::Types15<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12,
      T13, T14, T15> type;

};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16>
struct Types<T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None> {
    typedef internal::Types16<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12,
      T13, T14, T15, T16> type;

};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17>
struct Types<T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None> {
    typedef internal::Types17<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12,
      T13, T14, T15, T16, T17> type;

};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18>
struct Types<T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None> {
    typedef internal::Types18<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12,
      T13, T14, T15, T16, T17, T18> type;

};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19>
struct Types<T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None> {
    typedef internal::Types19<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12,
      T13, T14, T15, T16, T17, T18, T19> type;

};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20>
struct Types<T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None> {
    typedef internal::Types20<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12,
      T13, T14, T15, T16, T17, T18, T19, T20> type;

};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21>
struct Types<T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None> {
    typedef internal::Types21<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12,
      T13, T14, T15, T16, T17, T18, T19, T20, T21> type;

};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22>
struct Types<T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None> {
    typedef internal::Types22<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12,
      T13, T14, T15, T16, T17, T18, T19, T20, T21, T22> type;

};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23>
struct Types<T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None> {
    typedef internal::Types23<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12,
      T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23> type;

};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24>
struct Types<T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None> {
    typedef internal::Types24<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12,
      T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24> type;

};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25>
struct Types<T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None> {
    typedef internal::Types25<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12,
      T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25> type;

};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26>
struct Types<T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None> {
    typedef internal::Types26<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12,
      T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25,
      T26> type;

};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27>
struct Types<T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None> {
    typedef internal::Types27<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12,
      T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26,
      T27> type;

};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28>
struct Types<T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None> {
    typedef internal::Types28<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12,
      T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26,
      T27, T28> type;

};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28, typename T29>
struct Types<T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None> {
    typedef internal::Types29<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12,
      T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26,
      T27, T28, T29> type;

};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28, typename T29, typename T30>
struct Types<T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None> {
    typedef internal::Types30<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12,
      T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26,
      T27, T28, T29, T30> type;

};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28, typename T29, typename T30, typename T31>
struct Types<T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None> {
    typedef internal::Types31<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12,
      T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26,
      T27, T28, T29, T30, T31> type;

};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28, typename T29, typename T30, typename T31, typename T32>
struct Types<T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None> {
    typedef internal::Types32<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12,
      T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26,
      T27, T28, T29, T30, T31, T32> type;

};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28, typename T29, typename T30, typename T31, typename T32, typename T33>
struct Types<T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None> {
    typedef internal::Types33<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12,
      T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26,
      T27, T28, T29, T30, T31, T32, T33> type;

};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28, typename T29, typename T30, typename T31, typename T32, typename T33, typename T34>
struct Types<T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,T34,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None> {
    typedef internal::Types34<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12,
      T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26,
      T27, T28, T29, T30, T31, T32, T33, T34> type;

};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28, typename T29, typename T30, typename T31, typename T32, typename T33, typename T34, typename T35>
struct Types<T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,T34,T35,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None> {
    typedef internal::Types35<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12,
      T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26,
      T27, T28, T29, T30, T31, T32, T33, T34, T35> type;

};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28, typename T29, typename T30, typename T31, typename T32, typename T33, typename T34, typename T35, typename T36>
struct Types<T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,T34,T35,T36,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None> {
    typedef internal::Types36<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12,
      T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26,
      T27, T28, T29, T30, T31, T32, T33, T34, T35, T36> type;

};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28, typename T29, typename T30, typename T31, typename T32, typename T33, typename T34, typename T35, typename T36, typename T37>
struct Types<T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,T34,T35,T36,T37,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None> {
    typedef internal::Types37<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12,
      T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26,
      T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37> type;

};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28, typename T29, typename T30, typename T31, typename T32, typename T33, typename T34, typename T35, typename T36, typename T37, typename T38>
struct Types<T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,T34,T35,T36,T37,T38,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None> {
    typedef internal::Types38<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12,
      T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26,
      T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38> type;

};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28, typename T29, typename T30, typename T31, typename T32, typename T33, typename T34, typename T35, typename T36, typename T37, typename T38, typename T39>
struct Types<T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,T34,T35,T36,T37,T38,T39,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None> {
    typedef internal::Types39<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12,
      T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26,
      T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39> type;

};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28, typename T29, typename T30, typename T31, typename T32, typename T33, typename T34, typename T35, typename T36, typename T37, typename T38, typename T39, typename T40>
struct Types<T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,T34,T35,T36,T37,T38,T39,T40,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None> {
    typedef internal::Types40<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12,
      T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26,
      T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39,
      T40> type;

};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28, typename T29, typename T30, typename T31, typename T32, typename T33, typename T34, typename T35, typename T36, typename T37, typename T38, typename T39, typename T40, typename T41>
struct Types<T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,T34,T35,T36,T37,T38,T39,T40,T41,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None> {
    typedef internal::Types41<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12,
      T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26,
      T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40,
      T41> type;

};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28, typename T29, typename T30, typename T31, typename T32, typename T33, typename T34, typename T35, typename T36, typename T37, typename T38, typename T39, typename T40, typename T41, typename T42>
struct Types<T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,T34,T35,T36,T37,T38,T39,T40,T41,T42,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None> {
    typedef internal::Types42<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12,
      T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26,
      T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40,
      T41, T42> type;

};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28, typename T29, typename T30, typename T31, typename T32, typename T33, typename T34, typename T35, typename T36, typename T37, typename T38, typename T39, typename T40, typename T41, typename T42, typename T43>
struct Types<T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,T34,T35,T36,T37,T38,T39,T40,T41,T42,T43,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None> {
    typedef internal::Types43<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12,
      T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26,
      T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40,
      T41, T42, T43> type;

};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28, typename T29, typename T30, typename T31, typename T32, typename T33, typename T34, typename T35, typename T36, typename T37, typename T38, typename T39, typename T40, typename T41, typename T42, typename T43, typename T44>
struct Types<T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,T34,T35,T36,T37,T38,T39,T40,T41,T42,T43,T44,internal::None,internal::None,internal::None,internal::None,internal::None,internal::None> {
    typedef internal::Types44<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12,
      T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26,
      T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40,
      T41, T42, T43, T44> type;

};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28, typename T29, typename T30, typename T31, typename T32, typename T33, typename T34, typename T35, typename T36, typename T37, typename T38, typename T39, typename T40, typename T41, typename T42, typename T43, typename T44, typename T45>
struct Types<T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,T34,T35,T36,T37,T38,T39,T40,T41,T42,T43,T44,T45,internal::None,internal::None,internal::None,internal::None,internal::None> {
    typedef internal::Types45<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12,
      T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26,
      T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40,
      T41, T42, T43, T44, T45> type;

};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28, typename T29, typename T30, typename T31, typename T32, typename T33, typename T34, typename T35, typename T36, typename T37, typename T38, typename T39, typename T40, typename T41, typename T42, typename T43, typename T44, typename T45, typename T46>
struct Types<T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,T34,T35,T36,T37,T38,T39,T40,T41,T42,T43,T44,T45,T46,internal::None,internal::None,internal::None,internal::None> {
    typedef internal::Types46<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12,
      T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26,
      T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40,
      T41, T42, T43, T44, T45, T46> type;

};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28, typename T29, typename T30, typename T31, typename T32, typename T33, typename T34, typename T35, typename T36, typename T37, typename T38, typename T39, typename T40, typename T41, typename T42, typename T43, typename T44, typename T45, typename T46, typename T47>
struct Types<T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,T34,T35,T36,T37,T38,T39,T40,T41,T42,T43,T44,T45,T46,T47,internal::None,internal::None,internal::None> {
    typedef internal::Types47<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12,
      T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26,
      T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40,
      T41, T42, T43, T44, T45, T46, T47> type;

};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28, typename T29, typename T30, typename T31, typename T32, typename T33, typename T34, typename T35, typename T36, typename T37, typename T38, typename T39, typename T40, typename T41, typename T42, typename T43, typename T44, typename T45, typename T46, typename T47, typename T48>
struct Types<T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,T34,T35,T36,T37,T38,T39,T40,T41,T42,T43,T44,T45,T46,T47,T48,internal::None,internal::None> {
    typedef internal::Types48<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12,
      T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26,
      T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40,
      T41, T42, T43, T44, T45, T46, T47, T48> type;

};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28, typename T29, typename T30, typename T31, typename T32, typename T33, typename T34, typename T35, typename T36, typename T37, typename T38, typename T39, typename T40, typename T41, typename T42, typename T43, typename T44, typename T45, typename T46, typename T47, typename T48, typename T49>
struct Types<T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20,T21,T22,T23,T24,T25,T26,T27,T28,T29,T30,T31,T32,T33,T34,T35,T36,T37,T38,T39,T40,T41,T42,T43,T44,T45,T46,T47,T48,T49,internal::None> {
    typedef internal::Types49<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12,
      T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26,
      T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38, T39, T40,
      T41, T42, T43, T44, T45, T46, T47, T48, T49> type;

};

} // namespace testing
#endif
