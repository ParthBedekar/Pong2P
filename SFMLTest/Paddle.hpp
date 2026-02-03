#include <SFML/Graphics.hpp>

class Paddle {
	public:
	Paddle(float x,float y,sf::Keyboard::Key left, sf::Keyboard::Key right,sf::Color color);

	void update(float dt,float windowWidth);
	void draw(sf::RenderWindow& window) const;
	sf::FloatRect getBounds() const;

	private:
	sf::RectangleShape shape;
	float speed;
	sf::Keyboard::Key lKey;
	sf::Keyboard::Key rKey;
	sf::Texture texture;
};