#pragma once

#include "sort.h"

class BubbleSort : public Sort {
private:
	int index;
	
	int sorted_indexes;

public:

	BubbleSort(std::string name);

	virtual void update(std::vector<int>& vec) override;

	virtual void draw(sf::RenderWindow& window, std::vector<int>& vec) override;

	virtual void sort(std::vector<int>& vec) override;
};
