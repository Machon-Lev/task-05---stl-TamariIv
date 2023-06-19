#include "..\include\Coordinate.h"

bool Coordinate::operator==(const Coordinate& other) const
{
    return _x == other._x && _y == other._y;
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


Coordinate& Coordinate::operator=(const Coordinate& other) {
    if (this != &other) {
        _x = other._x;
        _y = other._y;
    }
    return *this;
}