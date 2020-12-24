#ifndef _2DSHAPE_H
#define _2DSHAPE_H


class Shape_2D {
  public:
    Shape_2D() = delete;

    Shape_2D(const float length, const float height, const float width = 0);

    bool operator <=(const Shape_2D & shape);


  private:
    float length_;

    float height_;

    float width_;

};
#endif
