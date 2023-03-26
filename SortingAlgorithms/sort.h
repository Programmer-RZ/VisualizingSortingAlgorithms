#pragma once

class Sort {
protected:
	std::string name;

	bool finished;

	sf::RectangleShape bar;

public:
	Sort(std::string name, bool finished);

	bool isFinished();

	std::string getName();

	virtual void draw(sf::RenderWindow& window, std::vector<int>& vec);

	virtual void sort(std::vector<int>& vec);
};
