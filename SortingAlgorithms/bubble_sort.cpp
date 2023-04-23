#include "global.h"
#include "bubble_sort.h"

BubbleSort::BubbleSort(std::string name)
	: index(0), sorted_indexes(0), Sort(name, false, 0) 
{}

void BubbleSort::resetParams(int len) {
	this->index = 0;
	this->sorted_indexes = 0;
	this->finished = false;
}

void BubbleSort::resetArray(std::vector<int>& vec) {
    vec.clear();
    for (int i = 0; i < 150; i++) {
        vec.push_back(i);
    }
}

void BubbleSort::update(std::vector<int>& vec) {
    this->index += 1;
    if (this->index >= int(vec.size() - 1 - this->sorted_indexes)) {
        this->index = 0;
        this->sorted_indexes += 1;
    }

    if (this->sorted_indexes >= int(vec.size())) {
        this->finished = true;
    }
}

void BubbleSort::draw(sf::RenderWindow& window, std::vector<int>& vec)
{
    for (int i = 0; i < int(vec.size()); i++) {
        if (i - 1 == index) {
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



void BubbleSort::sort(std::vector<int>& vec) {
    if (vec[index] > vec[index + 1]) {
        std::swap(vec[index], vec[index + 1]);
    }
}