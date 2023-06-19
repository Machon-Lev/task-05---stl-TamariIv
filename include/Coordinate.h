#pragma once

class Coordinate {
public:
    double _x;
    double _y;

    Coordinate(double x = 0, double y = 0) : _x(x), _y(y) {}

    // Comparison operators
    bool operator==(const Coordinate& other) const;
    bool operator!=(const Coordinate& other) const;
    bool operator<(const Coordinate& other) const;

    // Assignment operator
    Coordinate& operator=(const Coordinate& other);
};
