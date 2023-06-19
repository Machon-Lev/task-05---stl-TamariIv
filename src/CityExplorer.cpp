#include "..\include\CityExplorer.h"


std::map<int, DistanceFunction> CityExplorer::distanceFunctions = {
   {0, &euclideanDistance},
   {1, &chebyshevDistance},
   {2, &manhattanDistance}
};

void CityExplorer::addCity(std::string name, Coordinate coord)
{
    //auto it = _cities.find(name);
    //if (it != _cities.end())
    //    throw std::logic_error("City already exists: " + name);
    _cities_reversed.emplace(coord, name);
    _cities.emplace(name, coord);
}

std::map<Coordinate, std::string> CityExplorer::explore(std::string name, float radius, int funcChoice)
{    
    std::map<Coordinate, std::string> filtered;
    auto cityCoord = _cities.equal_range(name).first->second;
    std::copy_if(_cities_reversed.begin(), _cities_reversed.end(), std::inserter(filtered, filtered.end()), 
        [funcChoice, cityCoord, name, radius](const auto& pair) {
            return distanceFunctions[funcChoice](cityCoord, pair.first) < radius;
        });
    return filtered;
}

// Calculate Euclidean distance between two coordinates
double CityExplorer::euclideanDistance(const Coordinate& coord1, const Coordinate& coord2)
{
    double dx = coord1._x - coord2._x;
    double dy = coord1._y - coord2._y;
    return std::sqrt(dx * dx + dy * dy);
}

// Calculate Chebyshev distance between two coordinates
double CityExplorer::chebyshevDistance(const Coordinate& coord1, const Coordinate& coord2)
{
    double dx = std::abs(coord1._x - coord2._x);
    double dy = std::abs(coord1._y - coord2._y);
    return std::max(dx, dy);
}

// Calculate Manhattan distance between two coordinates
double CityExplorer::manhattanDistance(const Coordinate& coord1, const Coordinate& coord2)
{
    double dx = std::abs(coord1._x - coord2._x);
    double dy = std::abs(coord1._y - coord2._y);
    return dx + dy;
}