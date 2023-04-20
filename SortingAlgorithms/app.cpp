#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include <string>

#include "global.h"
#include "app.h"

#include "bubble_sort.h"
#include "selection_sort.h"
#include "cocktail_sort.h"
#include "comb_sort.h"


void App::run() {

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Sorting Algorithms");
	
    // create vector
    std::vector<int> vec = {};

    for (int i = 0; i < 200; i++) {
        vec.push_back(i);
    }

    // randomize
    std::random_device rd;
    std::uniform_int_distribution<int> dist(0, 199);
    for (int i = 0; i < 400; i++) {
        std::swap(vec[dist(rd)], vec[dist(rd)]);
    }

    std::vector<int> unsorted_vec = vec;

    // sorts
    BubbleSort bubblesort = BubbleSort("Bubble Sort");
    SelectionSort selectionsort = SelectionSort("Selection Sort");
    CocktailSort cocktailsort = CocktailSort("Cocktail Sort", vec.size());
    CombSort combsort = CombSort("Comb Sort", vec.size());

    Sort* sortPtr = &combsort;

    std::string currrent_sort_name = sortPtr->getName();


    // timer, font, text
    sf::Clock timer;
    timer.restart();

    sf::Font font;
    font.loadFromFile("Montserrat-Regular.ttf");

    sf::Text time;
    time.setFont(font);
    time.setFillColor(sf::Color(255, 255, 255));
    time.setCharacterSize(30);
    time.setPosition(sf::Vector2f(50, 100));

    sf::Text name;
    name.setFont(font);
    name.setFillColor(sf::Color(255, 255, 255));
    name.setCharacterSize(40);
    name.setPosition(sf::Vector2f(50, 25));
    name.setString(currrent_sort_name);

    sf::Text ui;
    ui.setFont(font);
    ui.setFillColor(sf::Color(255, 255, 255));


    sf::Clock clock;
    float fps;

    while (window.isOpen())
    {
        float currentTime = clock.restart().asSeconds();
        fps = 1.0f / (currentTime);

        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
            case (sf::Event::Closed):
                window.close();

            case (sf::Event::MouseButtonPressed):
                if (sortPtr->isFinished()) {
                    int id = sortPtr->getID();

                    if (id == 0) {
                        // reset
                        selectionsort = SelectionSort("Selection Sort");

                        sortPtr = &selectionsort;
                    }

                    else if (id == 1) {
                        // reset
                        cocktailsort = CocktailSort("Cocktail Sort", vec.size());

                        sortPtr = &cocktailsort;
                    }

                    else if (id == 2) {
                        // reset
                        combsort = CombSort("Comb Sort", vec.size());

                        sortPtr = &combsort;
                    }

                    else {
                        // reset
                        bubblesort = BubbleSort("Bubble Sort");

                        sortPtr = &bubblesort;

                    }

                    currrent_sort_name = sortPtr->getName();
                    name.setString(currrent_sort_name);

                    vec = unsorted_vec;

                    timer.restart();
                }
            }
        }

        window.clear();


        if (!sortPtr->isFinished()) {
            sortPtr->update(vec);
            sortPtr->sort(vec);
            int seconds = timer.getElapsedTime().asMilliseconds() / 1000;
            int milliseconds = timer.getElapsedTime().asMilliseconds() - seconds * 1000;
            time.setString("Time: " + std::to_string(seconds) + "." + std::to_string(milliseconds));

        }

        else {
            ui.setCharacterSize(30);
            ui.setString("Click to continue");
            ui.setPosition(sf::Vector2f(50, 175));
            window.draw(ui);
        }

        sortPtr->draw(window, vec);
        window.draw(name);
        window.draw(time);

        // delay
        float delay = float(fps / 60000);

        // round delay
        delay = ((int)(delay * 1000 + .5) / 1000.0f);

        ui.setCharacterSize(25);
        ui.setString("Delay: " + std::to_string(delay).erase(4, 4));
        ui.setPosition(sf::Vector2f(800, 25));
        window.draw(ui);

        window.display();

    }
}
