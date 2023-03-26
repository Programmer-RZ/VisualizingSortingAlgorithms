#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "global.h"
#include "bubble_sort.h"

BubbleSort::BubbleSort(int index, int sorted_indexes, std::string name)
	: index(index), sorted_indexes(sorted_indexes), Sort(name, false) 
{}

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