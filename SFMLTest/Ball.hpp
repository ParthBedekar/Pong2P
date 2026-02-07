#include <SFML/Graphics.hpp>
enum class BallResult {
	None,
	HitTopWall,
	HitBottomWall
};

class Ball {
	public:
	Ball(float x,float y);
	
	void draw(sf::RenderWindow& window) const;
	BallResult update(float dt,float windowWidth,float windowHeight, const sf::FloatRect& topBounds,const sf::FloatRect& bottomBounds);

	private:
	float speed;
	sf::Vector2f velocity;
	sf::CircleShape shape;

};

