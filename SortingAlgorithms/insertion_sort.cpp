#include "insertion_sort.h"
#include "global.h"

InsertionSort::InsertionSort(std::string name)
	: index(0),
	j(0),
	key(0),
	loop(false),
	Sort(name, false, 1)
{}

void InsertionSort::resetParams(int len) {
	this->index = 0;
	this->j = 0;
	this->key = 0;
	this->loop = false;
	this->finished = false;
}

void InsertionSort::resetArray(std::vector<int>& vec) {
	vec.clear();
	for (int i = 0; i < 250; i++) {
		vec.push_back(i);
	}
}

void InsertionSort::update(std::vector<int>&vec)
{
	if (!this->loop) {
		this->index += 1;

		if (this->index < vec.size()) {
			this->j = this->index - 1;
			this->key = vec[this->index];
			this->loop = true;
		}
		else {
			this->finished = true;
		}
	}
}

void InsertionSort::draw(sf::RenderWindow& window, std::vector<int>& vec)
{
	for (int i = 0; i < vec.size(); i++) {
		if (i == this->index || i - 1 == this->j) {
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

void InsertionSort::sort(std::vector<int>& vec)
{
	if (this->loop) {
		if (this->j >= 0 && this->key < vec[this->j]) {
			vec[this->j + 1] = vec[j];
			this->j -= 1;
		}

		else {
			this->loop = false;
			vec[this->j + 1] = this->key;
		}
	}
}
