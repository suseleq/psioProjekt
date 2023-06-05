#include "CrystalBowl.h"

void CrystalBowl::initStats()
{
	//initialize circle
	this->circle = std::make_unique<Circle>(*this, this->getGlobalBounds().width, this->getGlobalBounds().height, 110);
	this->circle->setFillColor(sf::Color(195, 255, 200, 50));
}

void CrystalBowl::initTexture()
{
	//initialize texture and setting on sprite
	this->texture = std::make_unique<sf::Texture>();
	this->texture->loadFromFile("./Textures/magicBowl.png");
	this->setTexture(*this->texture);
	this->setTextureRect(sf::IntRect(0, 0, 32, 32));
	this->scale(1.3f, 1.3f);
}

void CrystalBowl::initAnimations()
{
	//initialize animation
	this->animations["IDLE"] = std::make_unique<Animations>(*this, *this->texture, 4, 50.f, sf::IntRect(0, 0, 32, 32), 0, 32);
}

//Constructors / Destructors

CrystalBowl::CrystalBowl()
{
	//initiliaze variables
	this->initTexture();
	this->initAnimations();
	this->initStats();
}

CrystalBowl::~CrystalBowl()
{
}

void CrystalBowl::update(const float& dt)
{
	//updating animation and circle
	this->animations["IDLE"]->makeAnimation(dt);
	this->circle->uptade();
}
