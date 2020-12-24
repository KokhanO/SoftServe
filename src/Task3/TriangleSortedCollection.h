#ifndef _TRIANGLESORTEDCOLLECTION_H
#define _TRIANGLESORTEDCOLLECTION_H
#include <set>

class Triangle;

class TriangleCollection {
  public:
    TriangleCollection() = default;

    ~TriangleCollection() = default;

    void AddTriangle();

    void PrintTrianglesInDecresingOrder();


  private:
    std::multiset<Triangle> triangle_collection_;

};
#endif
