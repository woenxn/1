#include "figure.h"

std::ostream& operator<<(std::ostream& os, const Figure& fig)
{
    os << fig.ToString();
    return os;
}
