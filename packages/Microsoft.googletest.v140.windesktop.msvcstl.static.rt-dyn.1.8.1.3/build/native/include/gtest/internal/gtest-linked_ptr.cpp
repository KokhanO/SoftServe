
#include "gtest-linked_ptr.h"

namespace testing {

namespace internal {

// Many linked_ptr operations may change p.link_ for some linked_ptr
// variable p in the same circle as this object.  Therefore we need
// to prevent two such operations from occurring concurrently.
//
// Note that different types of linked_ptr objects can coexist in a
// circle (e.g. linked_ptr<Base>, linked_ptr<Derived1>, and
// linked_ptr<Derived2>).  Therefore we must use a single mutex to
// protect all linked_ptr objects.  This can create serious
// contention in production code, but is acceptable in a testing
// framework.
// Join an existing circle.
void linked_ptr_internal::join() {
}

// Leave whatever circle we're part of.  Returns true if we were the
// last member of the circle.  Once this is done, you can join() another.
bool linked_ptr_internal::depart() {
}


} // namespace testing::internal

} // namespace testing
