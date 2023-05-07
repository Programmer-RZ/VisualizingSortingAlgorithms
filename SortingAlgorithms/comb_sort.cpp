#include "comb_sort.h"
#include "global.h"

CombSort::CombSort(std::string name, int len) 
	: 
	gap(len),
	index(0),
	loop(false),
	swapped(true),
	Sort(name, false, 4)
{}

void CombSort::resetParams(int len) {
	this->gap = len;
	this->index = 0;
	this->loop = false;
	this->swapped = true;
	this->finished = false;
}

void CombSort::resetArray(std::vector<int>& vec) {
	vec.clear();
    for (int i = 0; i < 500; i++) {
        vec.push_back(i);
    }
}

void CombSort::getNextGap() {
	this->gap = static_cast<int>((this->gap * 10) / 13);

	if (this->gap < 1) {
		this->gap = 1;
	}
}

void CombSort::update(std::vector<int>& vec) {
	if (!this->loop) {
		if (this->gap != 1 || this->swapped) {
			this->getNextGap();
			this->swapped = false;
			this->loop = true;
		}

		else {
			this->finished = true;
		}
	}
	else {
		this->index += 1;

		if (this->index >= vec.size() - this->gap) {
			this->index = 0;
			this->loop = false;
		}
	}
}

void CombSort::draw(sf::RenderWindow& window, std::vector<int>& vec)
{
	for (int i = 0; i < static_cast<int>(vec.size()); i++) {
		if (i - 1 == this->index || i - 1 == this->index + this->gap) {
			bar.setFillColor(sf::Color(0, 0, 255));
		}

		else {
			bar.setFillColor(sf::Color(255, 255, 255));
		}

		float height = static_cast<float>(vec[i] * (HEIGHT - 100) / vec.size());
		float width = static_cast<float>(WIDTH / vec.size());
		bar.setSize(sf::Vector2f(width, height));
		bar.setPosition(sf::Vector2f(static_cast<float>(width * i), static_cast<float>(HEIGHT - height)));
		window.draw(bar);
	}
}

void CombSort::sort(std::vector<int>& vec) {
	if (this->loop) {
		if (vec[this->index] > vec[this->index + this->gap]) {
			std::swap(vec[this->index], vec[this->index + this->gap]);
			this->swapped = true;
		}
	}
}