#include "Paddle.hpp"
#include <iostream>
Paddle::Paddle(float x, float y,
	sf::Keyboard::Key left,
	sf::Keyboard::Key right,sf::Color color)
	: lKey(left), rKey(right) {
	shape.setSize(sf::Vector2f(120.f,20.f));
	shape.setOrigin(shape.getSize()/2.f);



	shape.setFillColor(color);
	shape.setPosition(x,y);

	speed=300.f;
}

void Paddle::update(float dt, float windowWidth) {
	if (sf::Keyboard::isKeyPressed(lKey)) {
		shape.move(-speed * dt, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(rKey)) {
		
		shape.move(speed * dt, 0.f);
	}
	
	sf::FloatRect bounds=shape.getGlobalBounds();

	if (bounds.left < 0) {
		shape.setPosition(bounds.width/2.f,shape.getPosition().y);
	}
	if (bounds.left + bounds.width > windowWidth) {
		shape.setPosition(
			windowWidth - bounds.width / 2.f,
			shape.getPosition().y
		);
	}
}

void Paddle::draw(sf::RenderWindow& window) const{ 
	window.draw(shape);
}
sf::FloatRect Paddle:: getBounds()const{
	return shape.getGlobalBounds();
}