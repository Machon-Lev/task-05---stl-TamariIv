#pragma once
#include <map>
#include <string>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <stdexcept>
#include <functional>
#include "Coordinate.h"



class CityExplorer {
private:
	std::multimap<std::string, Coordinate> _cities;
	std::multimap<Coordinate, std::string> _cities_reversed;
    int cityCount;

    // A dictionary that will hold the distance functions according to their representing number
    static std::map<int, std::function<double(const Coordinate&, const Coordinate&)>> distanceFunctions;

public:
    CityExplorer();
	void addCity(std::string name, Coordinate coord);
    std::multimap<Coordinate, std::string> explore(std::string name, float radius, int funcChoice);
    int northernCities(std::string name);
    int getCityCount();
    bool cityExists(std::string name);

private:
    // Distance calculation
    static double euclideanDistance(const Coordinate& coord1, const Coordinate& coord2);
    static double chebyshevDistance(const Coordinate& coord1, const Coordinate& coord2);
    static double manhattanDistance(const Coordinate& coord1, const Coordinate& coord2);


};