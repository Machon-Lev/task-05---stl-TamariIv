#pragma once
#include <map>
#include <string>
#include "Coordinate.h"

//struct City {
//	std::string _name;
//	Coordinate coord;
//};

// Distance function type
using DistanceFunction = int (*)(const Coordinate&, const Coordinate&);

std::map<int, DistanceFunction> distanceMap = {
    {0, &euclideanDistance},
    {1, &chebyshevDistance},
    {2, &manhattanDistance}
};

class CityExplorer {
private:
	std::multimap<std::string, Coordinate> _cities;
	std::map<Coordinate, std::string> _cities_reversed;

	void addCity(std::string name, Coordinate coord);
    void explore(std::string name, float radius, DistanceFunction dfunc);

    // Distance calculation
    double euclideanDistance(const Coordinate& coord1, const Coordinate& coord2) const;
    int chebyshevDistance(const Coordinate& coord1, const Coordinate& coord2) const;
    int manhattanDistance(const Coordinate& coord1, const Coordinate& coord2) const;


};