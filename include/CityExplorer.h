#pragma once
#include <map>
#include <string>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <stdexcept>
#include "Coordinate.h"

// Distance function type
using DistanceFunction = double (*)(const Coordinate&, const Coordinate&);


class CityExplorer {
private:
	std::multimap<std::string, Coordinate> _cities;
	std::multimap<Coordinate, std::string> _cities_reversed;
    int cityCount;
    static std::map<int, DistanceFunction> distanceFunctions;

public:
	void addCity(std::string name, Coordinate coord);
    std::map<Coordinate, std::string> explore(std::string name, float radius, int funcChoice);
    int northernCities(std::string name);
    int getCityCount();

    // Distance calculation
    static double euclideanDistance(const Coordinate& coord1, const Coordinate& coord2);
    static double chebyshevDistance(const Coordinate& coord1, const Coordinate& coord2);
    static double manhattanDistance(const Coordinate& coord1, const Coordinate& coord2);


};