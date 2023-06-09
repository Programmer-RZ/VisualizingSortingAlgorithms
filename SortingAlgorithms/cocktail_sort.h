#pragma once

#include "sort.h"

class CocktailSort : public Sort {
private:
	bool swapped;
	bool looping;

	int start, end;

	std::string direction;

	int index;

public:
	CocktailSort(std::string name, int len);

	virtual void update(std::vector<int>& vec) override;

	virtual void draw(sf::RenderWindow& window, std::vector<int>& vec) override;

	virtual void sort(std::vector<int>& vec) override;
};
