#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include <string>
#include <iostream>

#include "global.h"
#include "app.h"
#include "bubble_sort.h"

#include "selection_sort.h"


void App::run() {

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Sorting Algorithms");

<<<<<<< HEAD
    std::vector<int> vec = {};

    std::random_device rd;
    std::uniform_int_distribution<int> dist(1, 250);

    for (int i = 0; i < 250; i++) {
        vec.push_back(dist(rd));
    }

    BubbleSort* bubble_sort = new BubbleSort(0, 0, "Bubble Sort");


=======
    // create random vector
    std::vector<int> vec = {};

    std::random_device rd;
    std::uniform_int_distribution<int> dist(1, 100);

    for (int i = 0; i < 100; i++) {
        vec.push_back(dist(rd));
    }

    std::vector<int> unsorted_vec = vec;

    // bubble sort
    Sort* sort = new BubbleSort(0, 0, "Bubble Sort");

    std::string currrent_sort_name = sort->getName();


    // timer, font, text
>>>>>>> development
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


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
            case (sf::Event::Closed):
                window.close();

            case (sf::Event::MouseButtonPressed):
                if (sort->isFinished()) {
                    int id = sort->getID();
                    delete sort;

                    if (id == 0) {
                        sort = new SelectionSort(0, 0, 0, "Selection Sort");
                    }

                    else if (id == 1) {
                        sort = new BubbleSort(0, 0, "Bubble Sort");
                    }

                    currrent_sort_name = sort->getName();
                    name.setString(currrent_sort_name);

                    vec = unsorted_vec;

                    timer.restart();
                }
            }
        }

        window.clear();


        if (!sort->isFinished()) {
            sort->update(vec);
            sort->sort(vec);
            int seconds = timer.getElapsedTime().asMilliseconds() / 1000;
            int milliseconds = timer.getElapsedTime().asMilliseconds() - seconds * 1000;
            time.setString("Time: " + std::to_string(seconds) + "." + std::to_string(milliseconds));
        }

        sort->draw(window, vec);
        window.draw(name);
        window.draw(time);

        window.display();

    }
    delete sort;
}