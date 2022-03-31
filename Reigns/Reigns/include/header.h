#ifndef HEADER_H
#define HEADER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Art{
	private:
		std::string	filename;

		float		x = 0;
		float		y = 0;
		float		w = 0;
		float		h = 0;

	public:
		sf::Image	image;
		sf::Texture	texture;
		sf::Sprite	sprite;

		Art(std::string F);
		Art(std::string F, float X, float Y, float W, float H);
		Art(std::string F, int r, int g, int b);

		void	maskFromColor (int r, int g, int b);
		void	moveSprite(float dx, float dy);
		float	getX();
		float	getY();
		void	setX(float X);
		void	setY(float Y);
};

class Faction{

	public:
		int k = 25;
		int min = 0;
		int max = 50;
		sf::RectangleShape bar;
		Faction();

		void	update(int sign);
		void	drawBar(sf::RenderWindow& window, int x);
};

void ScreenSaver(sf::RenderWindow& window, sf::Event event,
				 float deltaTime, Art& startupBack, Art& startupFrame,
				 float& timer, float& currentFrame);

void InteractionCards(sf::RenderWindow& window, float deltaTime, int& count,
					  Art& startupCard, Art& sayText, Art& nickname,
					  Faction& church, Faction& people, Faction& army, Faction& money);

void UpDown(Faction& church, Faction& people, Faction& army, Faction& money,
			int random1, int random2, int x, int count);

bool checkGameOver(Faction& church, Faction& people, Faction& army, Faction& money);

#endif /* HEADER_H */