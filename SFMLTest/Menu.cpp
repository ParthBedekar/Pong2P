#include "Menu.hpp"
#include <filesystem>
#include <iostream>
Menu::Menu(float width, float height)
{
    std::cout << std::filesystem::current_path() << std::endl;

    if (!font.loadFromFile("Roboto-Regular.ttf")){
        // handle error
    }

    menu[0].setFont(font);
    menu[0].setString("Start");
    menu[0].setCharacterSize(40);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setPosition(width / 2 - 50, height / 2 - 50);

    menu[1].setFont(font);
    menu[1].setString("Quit");
    menu[1].setCharacterSize(40);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setPosition(width / 2 - 50, height / 2 + 10);

    selectedItemIndex = 0;
}

Menu::~Menu() {}

void Menu::draw(sf::RenderWindow& window)
{
    for (int i = 0; i < 2; i++)
        window.draw(menu[i]);
}

void Menu::moveUp()
{
    if (selectedItemIndex > 0)
    {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void Menu::moveDown()
{
    if (selectedItemIndex < 1)
    {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

int Menu::getSelectedItemIndex() const
{
    return selectedItemIndex;
}
