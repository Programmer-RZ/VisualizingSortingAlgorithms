#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "global.h"
#include "selection_sort.h"

SelectionSort::SelectionSort(int index, int min_index, int test_index, std::string name)
	: index(index), min_index(min_index), test_index(test_index), Sort(name, false, 1)
{}

void SelectionSort::update(std::vector<int>& vec) {
	if (this->test_index >= int(vec.size())) {
		this->index += 1;
		this->min_index = this->index;
		this->test_index = index;
	}

	if (this->index >= int(vec.size())) {
		this->finished = true;
	}
}

void SelectionSort::draw(sf::RenderWindow& window, std::vector<int>& vec)
{
	for (int i = 0; i < int(vec.size()); i++) {
		float height = float(vec[i] * (HEIGHT - 100) / vec.size());
		float width = float(WIDTH / vec.size());
		bar.setSize(sf::Vector2f(width, height));
		bar.setPosition(sf::Vector2f(float(width * i), float(HEIGHT - height)));
		window.draw(bar);
	}
}

void SelectionSort::sort(std::vector<int>& vec) {
	this->test_index += 1;
	
	if (vec[min_index] > vec[this->test_index]) {
		min_index = this->test_index;
	}
	
	if (this->test_index >= int(vec.size())) {
		std::swap(vec[this->index], vec[min_index]);
	}
}