#pragma once
#include "Animations.h"

class Hitbox : sf::RectangleShape
{
private:

	sf::Sprite& sprite;

	float offsetX;
	float offsetY;

public:
	Hitbox(sf::Sprite& sprite, float offsetX_, float offsetY_, float width, float height);

	~Hitbox();

	void uptade();
	void render(sf::RenderTarget& target);


};

