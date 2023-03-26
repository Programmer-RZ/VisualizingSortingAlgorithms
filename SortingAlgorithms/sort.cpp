#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "sort.h"

Sort::Sort(std::string name, bool finished)
	: name(name), finished(finished)
{
	this->bar.setFillColor(sf::Color(255, 255, 255));
}

bool Sort::isFinished()
{
	return this->finished;
}

std::string Sort::getName()
{
	return this->name;
}

void Sort::draw(sf::RenderWindow& window, std::vector<int>& vec)
{
}

void Sort::sort(std::vector<int>& vec)
{
}
