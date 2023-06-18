#pragma once

class Coordinate {
public:
    int _x;
    int _y;

    Coordinate(int x, int y) : _x(x), _y(y) {}

    // Comparison operators
    bool operator==(const Coordinate& other) const;
    bool operator!=(const Coordinate& other) const;
    bool operator<(const Coordinate& other) const;

};
