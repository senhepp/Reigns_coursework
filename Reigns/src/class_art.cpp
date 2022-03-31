#include <header.h>

// конструкторы, создающие спрайты картинки
Art::Art(std::string F){
	filename = F; x = 0; y = 0; w = 1280; h = 720;
	image.loadFromFile("images/" + filename);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
}

Art::Art(std::string F, float X, float Y, float W, float H){
	filename = F; x = X; y = Y; w = W; h = H;
	image.loadFromFile("images/" + filename);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, w, h));
	sprite.setPosition(x, y);
}

Art::Art(std::string F, int r, int g, int b){
	filename = F; x = 0; y = 0; w = 1280; h = 720;
	image.loadFromFile("images/" + filename);
	image.createMaskFromColor(sf::Color(r, g, b));
	texture.loadFromImage(image);
	sprite.setTexture(texture);
}

// функция перемещения спрайта
void Art::moveSprite(float dx, float dy){
	sprite.move(dx, dy);
	x += dx;
	y += dy;
}

// гетеры и сеттеры
float Art::getX(){
	return(x);
}

float Art::getY(){
	return(y);
}

void Art::setX(float X){
	x = X;
}

void Art::setY(float Y){
	y = Y;
}
