#pragma once

#include "sort.h"

class CombSort : public Sort {
private:
	int gap;
	int index;

	bool loop;

	bool swapped;

private:
	void getNextGap();

public:
	CombSort(std::string name, int len);

	virtual void resetArray(std::vector<int>& vec) override;

	virtual void update(std::vector<int>& vec) override;

	virtual void draw(sf::RenderWindow& window, std::vector<int>& vec) override;

	virtual void sort(std::vector<int>& vec) override;
};
