#include "Range.h"

bool Range::trySetTopBorder(const long long& top_border)
{	
	return top_border > 0 ? (top_border_ = pow(top_border,0.5)) : false;
}

long long Range::getTopBorder_() const
{
	return top_border_;
}
