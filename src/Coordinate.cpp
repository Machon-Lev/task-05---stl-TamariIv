#include "..\include\Coordinate.h"

bool Coordinate::operator==(const Coordinate& other) const
{
    return _x == other._x && _x == other._x;
}

bool Coordinate::operator!=(const Coordinate& other) const
{
    return !(*this == other);
}

bool Coordinate::operator<(const Coordinate& other) const
{
    if (_x < other._x) {
        return true;
    }
    else if (_x == other._x) {
        return _x < other._x;
    }
    return false;
}
