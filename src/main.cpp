#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include "CityExplorer.h"

const std::string DEFAULT_DATA_PATH = "C:\\Users\\tamar\\excellenteam\\CPP\\Task05\\Task05\\Task05\\resources\\data.txt";

void initExplorer(CityExplorer& ce);

int main() {

	try
	{
		std::string command = "";		
		float radius = 0;
		int norm = 0;	
		CityExplorer explorer;
		initExplorer(explorer);
		std::map<Coordinate, std::string> closeCities = {};
		
		std::cout << "Please enter selected city name (with line break after it):\n";
		std::cin >> command;

		while (command != "0") {
			std::cout << "Please enter the wanted radius\n";
			std::cin >> radius;
			std::cout << "Please enter the wanted norm (0 – L2, Euclidean distance, 1 – Linf, Chebyshev distance, 2 – L1, Manhattan distance):\n";
			std::cin >> norm;
			closeCities = explorer.explore(command, radius, norm);
		}
	}
	catch (const std::logic_error& e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << "Bye\n";
	return 0;
}

void initExplorer(CityExplorer& ce)
{
	std::ifstream file(DEFAULT_DATA_PATH);

	std::string line;
	while (std::getline(file, line)) {
		std::string cityName;
		double latitude, longitude;

		// Read city name from the current line
		cityName = line;

		// Read coordinates from the next line
		if (std::getline(file, line)) {
			std::stringstream ss(line);
			std::string latitudeStr, longitudeStr;

			// Extract latitude and longitude from the line separated by '-'
			if (std::getline(ss, latitudeStr, '-') && std::getline(ss, longitudeStr)) {
				latitude = std::stod(latitudeStr);
				longitude = std::stod(longitudeStr);

				// Add the city and its coordinates to the vector
				ce.addCity(cityName, Coordinate(latitude, longitude));
			}
		}
	}
	std::cout << "hi\n";
}
