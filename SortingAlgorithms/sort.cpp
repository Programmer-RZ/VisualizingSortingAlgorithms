#include "sort.h"

Sort::Sort(std::string name, bool finished, int id)
	: name(name), finished(finished), id(id)
{
	this->bar.setFillColor(sf::Color(255, 255, 255));
}

void Sort::resetParams(int len) 
{
	
} 


bool Sort::isFinished()
{
	return this->finished;
}

std::string Sort::getName()
{
	return this->name;
}

int Sort::getID()
{
	return this->id;
}

void Sort::resetArray(std::vector<int>& vec)
{
}

void Sort::update(std::vector<int>& vec)
{
}

void Sort::draw(sf::RenderWindow& window, std::vector<int>& vec)
{
}

void Sort::sort(std::vector<int>& vec)
{
}

