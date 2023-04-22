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
    for (int i = 0; i < int(vec.size()); i++) {

        float height = float(vec[i] * (HEIGHT - 100) / vec.size());
        float width = float(WIDTH / vec.size());
        bar.setSize(sf::Vector2f(width, height));
        bar.setPosition(sf::Vector2f(float(width * i), float(HEIGHT - height)));
        window.draw(bar);
    }
}

void App::run() {

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Sorting Algorithms");
    sf::View view = window.getDefaultView();
	
    // create vector
    std::vector<int> vec = {};
	vec.clear();
	for (int i = 0; i < 150; i++) {
		vec.push_back(i);
	}

    // bool for shuffle animation
    bool shuffle = true;
    int shuffleCount = 0;
	sf::Clock shuffleDelay;
	shuffleDelay.restart();

    // sorts
    BubbleSort bubblesort = BubbleSort("Bubble Sort");
    SelectionSort selectionsort = SelectionSort("Selection Sort");
    CocktailSort cocktailsort = CocktailSort("Cocktail Sort", vec.size());
    CombSort combsort = CombSort("Comb Sort", vec.size());
    InsertionSort insertionsort = InsertionSort("Insertion Sort");
    Sort* sortPtr = &bubblesort;
    std::string currrent_sort_name = sortPtr->getName();


    // font, text
    sf::Font font;
    font.loadFromFile("Montserrat-Regular.ttf");
	
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

    sf::Text ui;
    ui.setFont(font);
    ui.setFillColor(sf::Color(255, 255, 255));


    sf::Clock delay;
	
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
						vec.clear();
						for (int i = 0; i < 250; i++) {
							vec.push_back(i);
						}
						
                        // reset
                        insertionsort = InsertionSort("Insertion Sort");
                        sortPtr = &insertionsort;
                    }

                    else if (id == 1) {
						vec.clear();
						for (int i = 0; i < 150; i++) {
							vec.push_back(i);
						}
						
                        // reset
                        selectionsort = SelectionSort("Selection Sort");
                        sortPtr = &selectionsort;
						
                    }

                    else if (id == 2) {
						vec.clear();
						for (int i = 0; i < 150; i++) {
							vec.push_back(i);
						}
						
                        // reset
                        cocktailsort = CocktailSort("Cocktail Sort", vec.size());
                        sortPtr = &cocktailsort;
						
                    }

                    else if (id == 3) {
						vec.clear();
						for (int i = 0; i < 300; i++) {
							vec.push_back(i);
						}
						
                        // reset
                        combsort = CombSort("Comb Sort", vec.size());
                        sortPtr = &combsort;
                    }

                    else {
                        // reset
						vec.clear();
						for (int i = 0; i < 150; i++) {
							vec.push_back(i);
						}
						
                        bubblesort = BubbleSort("Bubble Sort");
                        sortPtr = &bubblesort;

                    }

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
			if (shuffleDelay.getElapsedTime().asMilliseconds() >= 5) {
				shuffleAnimation(vec);
				shuffleCount += 1;
				shuffleDelay.restart();
			}

            if (shuffleCount >= (vec.size() * 2)) {
                shuffle = false;
            }
			
			drawVec(vec, window);
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
        ui.setString("Delay: " + std::to_string(milliseconds) + "." + std::to_string(microseconds) + " ms");
        ui.setPosition(sf::Vector2f(WIDTH - 200, 25));
        window.draw(ui);

        window.display();

        // start delay timer at end of each frame
        delay.restart();
    }
}
