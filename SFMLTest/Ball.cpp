#include <SFML/Graphics.hpp>
#include "Ball.hpp"
#include <random>
#include "Paddle.hpp"
Ball::Ball(float x, float y) {
    shape.setRadius(15.f);
    shape.setOrigin(shape.getRadius(), shape.getRadius());
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color::White);

    speed = 260.f;

    // initialize velocity ONCE
    velocity.x = (rand() % 2 == 0 ? -1.f : 1.f) * speed;
    velocity.y = -speed;
}

BallResult Ball::update(
    float dt,
    float windowWidth,
    float windowHeight,
    const sf::FloatRect& topPaddle,
    const sf::FloatRect& bottomPaddle
) {
    shape.move(velocity * dt);

    auto bounds = shape.getGlobalBounds();

    // Left / Right wall
    if (bounds.left < 0 || bounds.left + bounds.width > windowWidth)
        velocity.x *= -1.f;

    // Paddle collisions
    if (bounds.intersects(bottomPaddle) && velocity.y > 0)
        velocity.y *= -1.f;

    if (bounds.intersects(topPaddle) && velocity.y < 0)
        velocity.y *= -1.f;

    // Bottom wall = top player wins
    if (bounds.top + bounds.height >= windowHeight)
        return BallResult::HitBottomWall;

    // Top wall = bottom player wins
    if (bounds.top <= 0)
        return BallResult::HitTopWall;

    return BallResult::None;
}



void Ball::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}