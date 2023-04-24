#pragma once

#include "sort.h"

class SelectionSort : public Sort {
private:
	int index;

	int min_index;

	int test_index;

public:
	SelectionSort(std::string name);
	
	virtual void resetParams(int len) override;

	virtual void resetArray(std::vector<int>& vec) override;

	virtual void update(std::vector<int>& vec) override;

	virtual void draw(sf::RenderWindow& window, std::vector<int>& vec) override;

	virtual void sort(std::vector<int>& vec) override;
};
