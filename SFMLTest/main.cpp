#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ball.hpp"
#include "Paddle.hpp"
#include "Menu.hpp"

enum class GameState
{
    Menu,
    Playing
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Pong");
    window.setFramerateLimit(60);

    Menu menu(window.getSize().x, window.getSize().y);
    GameState gameState = GameState::Menu;

    Paddle bottomPaddle(
        window.getSize().x / 2.f, window.getSize().y - 100.f,
        sf::Keyboard::Left, sf::Keyboard::Right, sf::Color::Red
    );

    Paddle topPaddle(
        window.getSize().x / 2.f, 100.f,
        sf::Keyboard::A, sf::Keyboard::D, sf::Color::Green
    );

    Ball ball(400.f, 400.f);

    sf::Clock clock;
    bool isPaused = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            // ===== MENU INPUT =====
            if (gameState == GameState::Menu && event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Up)
                    menu.moveUp();

                else if (event.key.code == sf::Keyboard::Down)
                    menu.moveDown();

                else if (event.key.code == sf::Keyboard::Enter)
                {
                    if (menu.getSelectedItemIndex() == 0)
                    {
                        // START GAME
                        gameState = GameState::Playing;
                        isPaused = false;
                        clock.restart();
                    }
                    else
                    {
                        window.close();
                    }
                }
            }

            // ESC to return to menu
            if (gameState == GameState::Playing &&
                event.type == sf::Event::KeyPressed &&
                event.key.code == sf::Keyboard::Escape)
            {
                gameState = GameState::Menu;
            }
        }

        float dt = clock.restart().asSeconds();

        // ===== GAME UPDATE =====
        if (gameState == GameState::Playing && !isPaused)
        {
            BallResult result = ball.update(
                dt,
                window.getSize().x,
                window.getSize().y,
                topPaddle.getBounds(),
                bottomPaddle.getBounds()
            );

            topPaddle.update(dt, window.getSize().x);
            bottomPaddle.update(dt, window.getSize().x);

            if (result == BallResult::HitBottomWall)
            {
                std::cout << "Green Wins\n";
                isPaused = true;
            }
            else if (result == BallResult::HitTopWall)
            {
                std::cout << "Red Wins\n";
                isPaused = true;
            }
        }

        // ===== DRAW =====
        window.clear();

        if (gameState == GameState::Menu)
        {
            menu.draw(window);
        }
        else
        {
            topPaddle.draw(window);
            bottomPaddle.draw(window);
            ball.draw(window);
        }

        window.display();
    }

    return 0;
}
