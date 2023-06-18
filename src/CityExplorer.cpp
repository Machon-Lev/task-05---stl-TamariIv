#include "..\include\CityExplorer.h"

void CityExplorer::addCity(std::string name, Coordinate coord)
{
    try {
        auto it = _cities_reversed.find(key);
        if (it != _cities_reversed.end())
            throw std::logic_error("Location is taken");
        _cities_reversed.emplace(coord, name);
        _cities.emplace(name, coord);
    }
}

void CityExplorer::explore(std::string name, float radius, DistanceFunction dfunc)
{
    std::map<int, std::string> filtered;
    std::copy_if(_cities_reversed.begin(), _cities_reversed.end(), std::inserter(filtered, filtered.end()), 
        [](const auto& pair) {
            return dfunc(_cities[name], pair.first) < radius;
        });
}



// Calculate Euclidean distance between two coordinates
double CityExplorer::euclideanDistance(const Coordinate& coord1, const Coordinate& coord2) const
{
    int dx = coord1._x - coord2._x;
    int dy = coord1._y - coord2._y;
    return std::sqrt(dx * dx + dy * dy);
}

// Calculate Chebyshev distance between two coordinates
int CityExplorer::chebyshevDistance(const Coordinate& coord1, const Coordinate& coord2) const
{
    int dx = std::abs(coord1._x - coord2._x);
    int dy = std::abs(coord1._y - coord2._y);
    return std::max(dx, dy);
}

// Calculate Manhattan distance between two coordinates
int CityExplorer::manhattanDistance(const Coordinate& coord1, const Coordinate& coord2) const
{
    int dx = std::abs(coord1._x - coord2._x);
    int dy = std::abs(coord1._y - coord2._y);
    return dx + dy;
}