#include <header.h>

// функция запуска заставки
void ScreenSaver(sf::RenderWindow& window, sf::Event event, float deltaTime,
				 Art& startupBack, Art& startupFrame, float& timer, float& currentFrame){
	if(currentFrame != -1){
		// прокрутка основной части
		if(currentFrame < 18){
			currentFrame += 0.01 * deltaTime;
			startupFrame.sprite.setTextureRect(
				sf::IntRect(360 * (int(currentFrame) % 9),
							180 * (int(currentFrame) / 9), 360, 180));
		}
		// повторяющаяся часть
		else if(event.type != sf::Event::KeyPressed &&
				 event.type != sf::Event::TextEntered &&
				 event.type != sf::Event::MouseButtonPressed){
			timer += deltaTime;
			// задержка между повторами
			if(timer > 3000){
				currentFrame += 0.02* deltaTime;
				if(int (currentFrame) % 9 == 8){
					timer = 0;
					currentFrame -= 8;
				}
			}

			startupFrame.sprite.setTextureRect(
				sf::IntRect(360 * (int(currentFrame) % 9), 360, 360, 180));
		}

		else{
			currentFrame = -1;
		}
		window.clear();
		window.draw(startupBack.sprite);
		window.draw(startupFrame.sprite);
		window.display();
	}
}