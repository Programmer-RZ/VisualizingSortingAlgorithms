#pragma once

#include "sort.h"

class InsertionSort : public Sort {
private:
	int index;
	int j;
	int key;

	bool loop;

public:
	InsertionSort(std::string name);

	virtual void update(std::vector<int>& vec) override;

	virtual void draw(sf::RenderWindow& window, std::vector<int>& vec) override;

	virtual void sort(std::vector<int>& vec) override;
};