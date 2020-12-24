#pragma once

class Shape2D {
  public:
    Shape2D() = delete;

    Shape2D(double perimeter = 0, double square = 0);

    ~Shape2D() = default;

    double getPerimeter() const;

    double getArea() const;

    bool operator <(const Shape2D & right) const;


  protected:
    double perimeter_;

    double area_;

};
