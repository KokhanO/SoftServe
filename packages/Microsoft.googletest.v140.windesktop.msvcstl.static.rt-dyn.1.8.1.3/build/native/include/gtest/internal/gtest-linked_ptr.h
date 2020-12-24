#ifndef TESTING_INTERNAL_GTEST-LINKED_PTR_H
#define TESTING_INTERNAL_GTEST-LINKED_PTR_H


namespace testing {

namespace internal {

// This is used internally by all instances of linked_ptr<>.  It needs to be
// a non-template class because different types of linked_ptr<> can refer to
// the same object (linked_ptr<Superclass>(obj) vs linked_ptr<Subclass>(obj)).
// So, it needs to be possible for different types of linked_ptr to participate
// in the same circular linked list, so we need a single class type here.
//
// DO NOT USE THIS CLASS DIRECTLY YOURSELF.  Use linked_ptr<T>.
class linked_ptr_internal {
  public:
    // Create a new circle that includes only this instance.
    inline void join_new() {
        next_ = this;
      };

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
    void join();

    // Leave whatever circle we're part of.  Returns true if we were the
    // last member of the circle.  Once this is done, you can join() another.
    bool depart();


  private:
    mutable const linked_ptr_internal * next_;

};
template<typename T>
class linked_ptr {
  public:
    typedef T element_type;

    // Take over ownership of a raw pointer.  This should happen as soon as
    // possible after the object is created.
    inline explicit linked_ptr(T * ptr = NULL) { capture(ptr); };

    inline ~linked_ptr() { depart(); };

    // Copy an existing linked_ptr<>, adding ourselves to the list of references.
    template<typename U>
    inline linked_ptr(const linked_ptr<U> & ptr) { copy(&ptr); };

    inline linked_ptr(const linked_ptr<T> & ptr) {  // NOLINT
        assert(&ptr != this);
        copy(&ptr);
      };

    // Assignment releases the old value and acquires the new.
    template<typename U>
    inline linked_ptr<T> & operator =(const linked_ptr<U> & ptr) {
        depart();
        copy(&ptr);
        return *this;
      };

    inline linked_ptr<T> & operator =(const linked_ptr<T> & ptr) {
        if (&ptr != this) {
          depart();
          copy(&ptr);
        }
        return *this;
      };

    // Smart pointer members.
    inline void reset(T * ptr = NULL) {
        depart();
        capture(ptr);
      };

    inline T * get() const { return value_; };

    inline T * operator ->() const { return value_; };

    inline T & operator *() const { return *value_; };

    inline bool operator ==(T * p) const { return value_ == p; };

    inline bool operator !=(T * p) const { return value_ != p; };

    template<typename U>
    inline bool operator ==(const linked_ptr<U> & ptr) const {
        return value_ == ptr.get();
      };

    template<typename U>
    inline bool operator !=(const linked_ptr<U> & ptr) const {
        return value_ != ptr.get();
      };

  template <typename T> friend class linked_ptr;

  private:
    T * value_;

    linked_ptr_internal link_;

    inline void depart() {
        if (link_.depart()) delete value_;
      };

    inline void capture(T * ptr) {
        value_ = ptr;
        link_.join_new();
      };

    template<typename U>
    inline void copy(const linked_ptr<U> * ptr) {
        value_ = ptr->get();
        if (value_)
          link_.join(&ptr->link_);
        else
          link_.join_new();
      };

};

} // namespace testing::internal

} // namespace testing
#endif
