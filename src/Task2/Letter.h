#ifndef _LETTER_H
#define _LETTER_H


#include "2DShape.h"

class Letter : public Shape_2D {
  public:
    Letter() = delete;

    Letter(const float width, const float length);

    ~Letter() = default;

};
#endif
