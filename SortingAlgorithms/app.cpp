#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include <string>

#include "global.h"
#include "app.h"
#include "bubble_sort.h"

void App::run() {

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Sorting Algorithms");

    // create random vector
    std::vector<int> vec = {};

    std::random_device rd;
    std::uniform_int_distribution<int> dist(1, 250);

    for (int i = 0; i < 250; i++) {
        vec.push_back(dist(rd));
    }

    // bubble sort
    BubbleSort* bubble_sort = new BubbleSort(0, 0, "Bubble Sort");


    std::string currrent_sort_name = bubble_sort->getName();


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


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
            case (sf::Event::Closed):
                window.close();
            }
        }

        window.clear();


        if (!bubble_sort->isFinished()) {
            bubble_sort->update(vec);
            bubble_sort->sort(vec);

            int seconds = timer.getElapsedTime().asMilliseconds() / 1000;
            int milliseconds = timer.getElapsedTime().asMilliseconds() - seconds * 1000;
            time.setString("Time: " + std::to_string(seconds) + "." + std::to_string(milliseconds));
        }

        bubble_sort->draw(window, vec);
        window.draw(name);
        window.draw(time);

        window.display();

    }
    delete bubble_sort;
}