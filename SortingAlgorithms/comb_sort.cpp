#include "comb_sort.h"
#include "global.h"

CombSort::CombSort(std::string name, int len) 
	: 
	gap(len),
	index(0),
	loop(false),
	swapped(true),
	Sort(name, false, 3)
{}


void CombSort::getNextGap() {
	this->gap = int((this->gap * 10) / 13);

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
}

void CombSort::draw(sf::RenderWindow& window, std::vector<int>& vec)
{
	for (int i = 0; i < int(vec.size()); i++) {
		if (i - 1 == this->index || i - 1 == this->gap) {
			bar.setFillColor(sf::Color(0, 0, 255));
		}

		else {
			bar.setFillColor(sf::Color(255, 255, 255));
		}

		float height = float(vec[i] * (HEIGHT - 100) / vec.size());
		float width = float(WIDTH / vec.size());
		bar.setSize(sf::Vector2f(width, height));
		bar.setPosition(sf::Vector2f(float(width * i), float(HEIGHT - height)));
		window.draw(bar);
	}
}

void CombSort::sort(std::vector<int>& vec) {
	if (this->loop) {
		if (vec[this->index] > vec[this->index + this->gap]) {
			std::swap(vec[this->index], vec[this->index + this->gap]);
			this->swapped = true;
		}

		this->index += 1;

		if (this->index >= vec.size() - this->gap) {
			this->index = 0;
			this->loop = false;
		}
	}
}