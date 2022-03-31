#include <header.h>

int main(){
	// создание окна 1280 на 720, в котором будет игра
	sf::RenderWindow window (sf::VideoMode(1280, 720), "Reings");
	sf::Clock	clock;
	sf::Event	event;

	// создание иконки
	sf::Image icon;
	icon.loadFromFile("images/icon.png");
	window.setIcon(1024, 1024, icon.getPixelsPtr());

	// подключение музыкальной дорожки
	sf::Music music;
	music.openFromFile("music/Deskant_The_King_s_Carpet.ogg");
	music.setVolume(50);
	music.play();
	music.setLoop(true);

	// подключение рандома для дальнейшего случайного выбора карточек
	std::srand(std::time(NULL));

	// подключение всех необходимых медиафайлов - см. "Reigns\src\class_art.cpp"
	Art startupBack	("startup_back.png");
	Art startupFrame("startup_frame.png", 460, 270, 360, 180);
	Art backFaction	("faction.png", 430, 0, 420, 117);
	Art background	("background.png", 78, 66, 51);
	Art gameOver	("game_over.png");
	Art sayText		("text.png", 430, 118, 420, 122);
	Art nickname	("text.png", 430, 571, 420, 63);
	Art startupCard	("event_cards.png", 475, 240, 330, 330);
	Art backCard	("event_cards.png", 475, 240, 330, 330);

	backCard.sprite.setTextureRect(sf::IntRect(0, 330, 330, 330));

	// введение 4 фракций - см. "Reigns\src\faction.cpp"
	Faction church;
	Faction people;
	Faction army;
	Faction money;

	// объявление счетчиков
	float	timer = 0;
	float	currentFrame = 0;
	int		count = 0;

	// основной цикл, задающий время жизни игры
	while(window.isOpen()){
		while(window.pollEvent(event)){
			// условия закрытия основного окна игры
			if(event.type == sf::Event::Closed ||
				sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
				window.close();
			}
		}

		float deltaTime = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		deltaTime = deltaTime / 800;

		if(currentFrame != -1){
			// функция, запускающая заставку - см. "Reigns\src\screen_saver.cpp"
			ScreenSaver(window, event, deltaTime, startupBack, startupFrame, timer, currentFrame);
		}

		// проверка на обнуление/переполнение фракций - см. "Reigns\src\faction.cpp"
		else if(checkGameOver(church, people, army, money)){
			window.clear();
			window.draw(gameOver.sprite);
			window.display();
		}

		else{
			window.clear();
			window.draw(backFaction.sprite);

			// отрисовка изменения фракций в результате решения короля
			church	.drawBar(window, 479);
			people	.drawBar(window, 573);
			army	.drawBar(window, 677);
			money	.drawBar(window, 772);

			window.draw(background.sprite);
			window.draw(backCard.sprite);

			// функция работы с фракциями - см. "Reigns\src\interaction_cards.cpp"
			InteractionCards(window, deltaTime, count, startupCard, sayText, nickname,
							 church, people, army, money);

			window.display();
		}
	}
	return(0);
}