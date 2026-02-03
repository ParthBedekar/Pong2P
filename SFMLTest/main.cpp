#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ball.hpp"
#include "Paddle.hpp"
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML RenderWindow Test");
    window.setFramerateLimit(60);
    
    Paddle bottomPaddle(
        400.f, 560.f,
        sf::Keyboard::Key::Left, sf::Keyboard::Key::Right,sf::Color::Red
    );

    Paddle topPaddle(
        400.f, 40.f,
        sf::Keyboard::Key::A, sf::Keyboard::Key::D,sf::Color::Green
    );

    Ball ball(400.f,400.f);
    sf::Clock clock;
    bool isPaused=false;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float dt = clock.restart().asSeconds();

        if (!isPaused) {
            BallResult result = ball.update(
                dt,
                window.getSize().x,
                window.getSize().y,
                topPaddle.getBounds(),
                bottomPaddle.getBounds()
            );
            topPaddle.update(dt, window.getSize().x);
            bottomPaddle.update(dt, window.getSize().x);
            if (result == BallResult::HitBottomWall) {
                std::cout << "Green Wins\n";
                isPaused = true;
            }
            else if (result == BallResult::HitTopWall) {
                std::cout << "Red Wins\n";
                isPaused = true;
            }

        }
        
        window.clear();
        topPaddle.draw(window);
        bottomPaddle.draw(window);
        ball.draw(window);
        window.display();
    }

    return 0;
}
