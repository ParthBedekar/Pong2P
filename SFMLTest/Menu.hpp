#pragma once
#include <SFML/Graphics.hpp>

class Menu
{
public:
    Menu(float width, float height);
    ~Menu();

    void draw(sf::RenderWindow& window);
    void moveUp();
    void moveDown();

    int getSelectedItemIndex() const;

private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[2];
};
