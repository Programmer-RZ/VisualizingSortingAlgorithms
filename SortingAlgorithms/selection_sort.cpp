#include "global.h"
#include "selection_sort.h"

SelectionSort::SelectionSort(std::string name)
	: index(-1), min_index(0), test_index(0), Sort(name, false, 2)
{}

void SelectionSort::resetParams(int len) {
	this->index = -1;
	this->min_index = 0;
	this->test_index = 0;
	this->finished = false;
}

void SelectionSort::resetArray(std::vector<int>& vec) {
	vec.clear();
	for (int i = 0; i < 150; i++) {
		vec.push_back(i);
	}
}

void SelectionSort::update(std::vector<int>& vec) {
	if (this->test_index >= vec.size()) {
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
	for (int i = 0; i < vec.size(); i++) {
		float height = static_cast<float>(vec[i] * (HEIGHT - 100) / vec.size());
		float width = static_cast<float>(WIDTH / vec.size());
		bar.setSize(sf::Vector2f(width, height));
		bar.setPosition(sf::Vector2f(static_cast<float>(width * i), static_cast<float>(HEIGHT - height)));
		bar.setFillColor(sf::Color(255, 255, 255));
		window.draw(bar);
	}

	float height, width;
	bar.setFillColor(sf::Color(0, 0, 255));

	// draw test_index bar
	height = static_cast<float>(vec[this->test_index] * (HEIGHT - 100) / vec.size());
	width = static_cast<float>(WIDTH / vec.size());
	bar.setSize(sf::Vector2f(width, height));
	bar.setPosition(sf::Vector2f(static_cast<float>(width * this->test_index), static_cast<float>(HEIGHT - height)));
	window.draw(bar);

	// draw min_index bar
	height = static_cast<float>(vec[this->min_index] * (HEIGHT - 100) / vec.size());
	width = static_cast<float>(WIDTH / vec.size());
	bar.setSize(sf::Vector2f(width, height));
	bar.setPosition(sf::Vector2f(static_cast<float>(width * this->min_index), static_cast<float>(HEIGHT - height)));
	window.draw(bar);

	// draw index bar
	height = static_cast<float>(vec[this->index] * (HEIGHT - 100) / vec.size());
	width = static_cast<float>(WIDTH / vec.size());
	bar.setSize(sf::Vector2f(width, height));
	bar.setPosition(sf::Vector2f(static_cast<float>(width * this->index), static_cast<float>(HEIGHT - height)));
	window.draw(bar);


}

void SelectionSort::sort(std::vector<int>& vec) {
	this->test_index += 1;
	
	if (vec[min_index] > vec[this->test_index]) {
		min_index = this->test_index;
	}
	
	if (this->test_index >= vec.size()) {
		std::swap(vec[this->index], vec[min_index]);
	}
}

