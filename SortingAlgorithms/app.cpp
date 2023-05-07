#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include <string>
#include <iostream>

#include "global.h"
#include "app.h"

#include "bubble_sort.h"
#include "selection_sort.h"
#include "cocktail_sort.h"
#include "comb_sort.h"
#include "insertion_sort.h"

// shuffle animation functions
void shuffleAnimation(std::vector<int>& vec) {
    // randomize
    std::random_device rd;
    std::uniform_int_distribution<int> dist(0, (vec.size() - 1));
    std::swap(vec[dist(rd)], vec[dist(rd)]);
}

void drawVec(std::vector<int>& vec, sf::RenderWindow& window) {
    sf::RectangleShape bar;
    bar.setFillColor(sf::Color(255, 255, 255));
    for (int i = 0; i < vec.size(); i++) {

        float height = static_cast<float>(vec[i] * (HEIGHT - 100) / vec.size());
        float width = static_cast<float>(WIDTH / vec.size());
        bar.setSize(sf::Vector2f(width, height));
        bar.setPosition(sf::Vector2f(static_cast<float>(width * i), static_cast<float>(HEIGHT - height)));
        window.draw(bar);
    }
}

void App::run() {

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Sorting Algorithms");
    sf::View view = window.getDefaultView();

    // create vector
    std::vector<int> vec = {};

    // bool for shuffle animation
    bool shuffle = true;
    int shuffleCount = 0;
	sf::Clock shuffleDelay;
	shuffleDelay.restart();

    // sorts
    BubbleSort bubblesort("Bubble Sort");
    SelectionSort selectionsort("Selection Sort");
    CocktailSort cocktailsort("Cocktail Sort", vec.size());
    CombSort combsort("Comb Sort", vec.size());
    InsertionSort insertionsort("Insertion Sort");
    Sort* sortPtr = &combsort;
    std::string currrent_sort_name = sortPtr->getName();

    // set vector length based on current algorithm
    sortPtr->resetArray(vec);
    sortPtr->resetParams(vec.size());

    // font, text
    sf::Font font;
    font.loadFromFile("res\\Montserrat-Regular.ttf");
	
	/*
    sf::Text time;
    time.setFont(font);
    time.setFillColor(sf::Color(255, 255, 255));
    time.setCharacterSize(25);
    time.setPosition(sf::Vector2f(50, 100));
	*/

    sf::Text name;
    name.setFont(font);
    name.setFillColor(sf::Color(255, 255, 255));
    name.setCharacterSize(40);
    name.setPosition(sf::Vector2f(50, 25));
    name.setString(currrent_sort_name);

    // reuse the same text for the stats
    sf::Text ui;
    ui.setFont(font);
    ui.setFillColor(sf::Color(255, 255, 255));

    sf::Clock delay;
    delay.restart();
	
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
            case (sf::Event::Closed):
                window.close();

                break;

            case (sf::Event::Resized):
                view.setSize({
                static_cast<float>(event.size.width),
                static_cast<float>(event.size.height)
                    });
                window.setView(view);

                break;

            case (sf::Event::MouseButtonPressed):
                if (sortPtr->isFinished()) {
                    int id = sortPtr->getID();

                    if (id == 0) {
                        sortPtr = &insertionsort;
                    }
                    else if (id == 1) {
                        sortPtr = &selectionsort;
                    }
                    else if (id == 2) {
                        sortPtr = &cocktailsort;
                    }
                    else if (id == 3) {
                        sortPtr = &combsort;
                    }
                    else {
                        sortPtr = &bubblesort;
                    }

                    // reset
                    sortPtr->resetArray(vec);
                    sortPtr->resetParams(vec.size());

                    currrent_sort_name = sortPtr->getName();
                    name.setString(currrent_sort_name);

                    shuffle = true;
					shuffleCount = 0;

                    break;
                }
            }
        }

        window.clear();

        if (shuffle) {
            ui.setString("Shuffling");
			ui.setCharacterSize(40);
			ui.setPosition(sf::Vector2f(50, 25));
			
			if (shuffleDelay.getElapsedTime().asMilliseconds() >= 5) {
				shuffleAnimation(vec);
				shuffleCount += 1;
				shuffleDelay.restart();
			}

            if (shuffleCount >= (vec.size() * 2)) {
                shuffle = false;
            }
			
			drawVec(vec, window);

            window.draw(ui);

            window.display();

            continue;
        }

        if (!sortPtr->isFinished()) {
            sortPtr->update(vec);
            sortPtr->sort(vec);
        }

        else {
            ui.setCharacterSize(30);
            ui.setString("Click to continue");
            ui.setPosition(sf::Vector2f(50, 175));
            window.draw(ui);
        }

        sortPtr->draw(window, vec);
        window.draw(name);

        // delay
        int d = int(delay.getElapsedTime().asMicroseconds());

        int milliseconds = int(d / 1000);
        int microseconds = int((d - milliseconds * 1000) / 100);

        ui.setCharacterSize(25);
        ui.setString("Render Delay: " + std::to_string(milliseconds) + "." + std::to_string(microseconds) + " ms");
        ui.setPosition(sf::Vector2f(WIDTH - 250, 25));
        window.draw(ui);

        window.display();

        // start delay timer at end of each frame
        delay.restart();
    }
}
