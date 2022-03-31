#include <header.h>

// конструктор, создающий шкалу фракции
Faction::Faction(){
	bar.setFillColor(sf::Color(78, 66, 51));
}

// функция изменения шкалы фракции
void Faction::update(int sign){
	k = k - 5 * sign;
}

// функция отрисовки шкалы фракции
void Faction::drawBar(sf::RenderWindow& window, int x){
	bar.setSize(sf::Vector2f(36, k));
	bar.setPosition(x, 34); 
	window.draw(bar);
}

// функция определения, как решение короля повлияло на фракции
void UpDown(Faction& church, Faction& people, Faction& army, Faction& money, 
			int random1, int random2, int x, int count){

	int sing = -1;
	if(x > 475){
		sing = 1;
	}
	random1 = random1 % 4;
	random2 = (random1 + random2 + 1) % 4;

	if(count != 0){
		if(random1 == 0){
			church.update(sing);
		}
		else if(random1 == 1){
			people.update(sing);
		}
		else if(random1 == 2){
			army.update(sing);
		}
		else{
			money.update(sing);
		}
		
		if(random2 == 0){
			church.update(-sing);
		}
		else if(random2 == 1){
			people.update(-sing);
		}
		else if(random2 == 2){
			army.update(-sing);
		}
		else{
			money.update(-sing);
		}
	}
}

// проверка, не проиграл ли игрок
bool checkGameOver(Faction& church, Faction& people, Faction& army, Faction& money){
	if((church.k == church.min) || (church.k == church.max) ||
		(people.k == people.min) || (people.k == people.max) ||
		(army.k == army.min) || (army.k == army.max) ||
		(money.k == money.min) || (money.k == money.max)){
		return(true);
	}
	return(false);
}