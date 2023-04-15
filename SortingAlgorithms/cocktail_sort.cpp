#include "global.h"
#include "cocktail_sort.h"

CocktailSort::CocktailSort(std::string name, int len)
	: swapped(true),
    looping(false),
    start(0),
    end(len - 1),
    index(0),
    direction(""),
    Sort(name, false, 2)
{}

void CocktailSort::update(std::vector<int>& vec) {
    if (this->swapped && !this->looping) {
        this->swapped = false;
        this->looping = true;
        if (this->direction != "left") {
            this->direction = "left";
            this->index = this->end + 2;
        }

        else if (this->direction != "right") {
            this->direction = "right";
            this->index = this->start - 2;
        }
    }
    else {
        if (!this->swapped && !this->looping) {
            this->finished = true;
        }
    }

    if (this->direction == "right") {
        this->index += 1;
        if (this->index >= this->end) {
            this->looping = false;
            this->end -= 1;
        }
    }

    else if (this->direction == "left") {
        this->index -= 1;
        if (this->index < this->start) {
            this->looping = false;
            this->start += 1;
        }
    }
}

void CocktailSort::sort(std::vector<int>& vec) {
    if (vec[this->index] > vec[this->index + 1]) {
        std::swap(vec[this->index], vec[this->index + 1]);
        this->swapped = true;
    }
}

void CocktailSort::draw(sf::RenderWindow& window, std::vector<int>& vec) {
    for (int i = 0; i < int(vec.size()); i++) {
        if (i - 1 == this->index) {
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