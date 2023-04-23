#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Sort {
protected:
	std::string name;

	int id;

	bool finished;

	sf::RectangleShape bar;

public:
	Sort(std::string name, bool finished, int id);

	bool isFinished();

	std::string getName();

	int getID();
	
	virtual void resetParams(int len);

	virtual void resetArray(std::vector<int>& vec);

	virtual void update(std::vector<int>& vec);

	virtual void draw(sf::RenderWindow& window, std::vector<int>& vec);

	virtual void sort(std::vector<int>& vec);
};
