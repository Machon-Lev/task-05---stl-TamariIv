#include "..\include\CityExplorer.h"

std::map<int, std::function<double(const Coordinate&, const Coordinate&)>> CityExplorer::distanceFunctions = {
   {0, &euclideanDistance},
   {1, &chebyshevDistance},
   {2, &manhattanDistance}
};

CityExplorer::CityExplorer()
{
    cityCount = 0;
}

void CityExplorer::addCity(std::string name, Coordinate coord)
{
    _cities_reversed.emplace(coord, name);
    _cities.emplace(name, coord);
    cityCount++;
}

std::multimap<Coordinate, std::string> CityExplorer::explore(std::string name, float radius, int funcChoice)
{    
    std::multimap<Coordinate, std::string> filtered;
    auto cityCoord = _cities.equal_range(name).first->second;
    std::copy_if(_cities_reversed.begin(), _cities_reversed.end(), std::inserter(filtered, filtered.end()), 
        [funcChoice, cityCoord, name, radius](const auto& pair) {
            return distanceFunctions[funcChoice](cityCoord, pair.first) < radius;
        });
    return filtered;
}

int CityExplorer::northernCities(std::string name)
{
    std::map<Coordinate, std::string> filtered;
    auto cityCoord = _cities.equal_range(name).first->second;
    std::copy_if(_cities_reversed.begin(), _cities_reversed.end(), std::inserter(filtered, filtered.end()),
        [cityCoord](const auto& pair) {
            return pair.first._y > cityCoord._y;
        });
    return filtered.size();
}

int CityExplorer::getCityCount()
{
    return this->cityCount;
}

bool CityExplorer::cityExists(std::string name)
{
    return _cities.find(name) != _cities.end();
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