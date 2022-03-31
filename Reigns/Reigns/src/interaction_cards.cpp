#include <header.h>

void InteractionCards(sf::RenderWindow& window, float deltaTime, int& count,
					  Art& startupCard, Art& sayText, Art& nickname,
					  Faction& church, Faction& people, Faction& army, Faction& money){	

	static int random1; // случайный выбор персонажа
	static int random2; // случайный выбор произнесенной фразы

	// движение карточек по горизонтали
	if((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && (startupCard.getX() > 325)){
			startupCard.moveSprite(-deltaTime, 0);
	}
	if((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && (startupCard.getX() < 625)){
		startupCard.moveSprite(deltaTime, 0);
	}

	// проверка, отклонилась ли карточка максимально влево или вправо
	if((sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) &&
		((startupCard.getX() >= 625) || (startupCard.getX() <= 325))){
		int x = startupCard.getX();
		UpDown(church, people, army, money, random1, random2, x, count);
		random1 = (std::rand() % 8);
		random2 = (std::rand() % 3);

		if(random1 < 4){
			startupCard.sprite.setTextureRect
				(sf::IntRect((random1 + 1) * 330, 0, 330, 330));
			nickname.sprite.setTextureRect
				(sf::IntRect((random1 + 1)* 420, 0, 420, 63));
			sayText.sprite.setTextureRect(sf::IntRect
				((random1 + 1) * 420, 63 + random2 * 122, 420, 122));
		}

		else{
			startupCard.sprite.setTextureRect
				(sf::IntRect((random1 - 3) * 330, 330, 330, 330));
			nickname.sprite.setTextureRect
				(sf::IntRect((random1 - 3) * 420, 429, 420, 63));
			sayText.sprite.setTextureRect(sf::IntRect
				((random1 - 3) * 420, 492 + random2 * 122, 420, 122));
		}

		// выставление следующей карточки в центр поля после слистывания предыдущей
		startupCard.setX(475);
		startupCard.sprite.setPosition(475, 240);
		count += 1;
	}
	window.draw(startupCard.sprite);
	window.draw(nickname.sprite);
	window.draw(sayText.sprite);
}