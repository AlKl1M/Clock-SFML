#include "Clock.h"
//В конструкторе сразу создаем окно 900х900, стрелки часов, минут и секунд и циферблат
mt::Clock::Clock() : m_Window(sf::VideoMode(900, 900), "Clock", sf::Style::Close), hours(sf::Vector2f(200, 8)),
minutes(sf::Vector2f(260, 8)), seconds(sf::Vector2f(300, 4)), clockFace(), background()
{
	// отрисовываем картинку с циферблатом
	clockFace.loadFromFile("img/clockface.png");
	background.setTexture(clockFace);
	background.setPosition(0, 0);
	// Настраиваем вид стрелки часов
	hours.setFillColor(sf::Color::Black);
	hours.setOrigin(0, 2);
	hours.setPosition(450, 450);
	// Настраиваем вид стрелки минут
	minutes.setFillColor(sf::Color::Black);
	minutes.setOrigin(0, 2);
	minutes.setPosition(450, 450);
	// Настраиваем вид стрелки секунд
	seconds.setFillColor(sf::Color::Red);
	seconds.setOrigin(0, 2);
	seconds.setPosition(450, 450);
}
// метод, который свяжет все процессы и запустит программу
void mt::Clock::run()
{
	while (m_Window.isOpen())
	{
		GetLocalTime(&time); //Получаем время ОС
		eventsHandler(); // Обрабатываем события
		update(time.wHour, time.wMinute, time.wSecond); // Отправляем время
		render(); // Отрисовываем
	}
}

void mt::Clock::update(int h, int m, int s) // Изменяет положение стрелок
{

	float hms = (h % 12) * 30 - 90 + ((m / 12) * 5); // время, через которое должна повернуться стрелка часов

	hours.setRotation(hms); // устанавливаем время, упомянутое выше
	minutes.setRotation(m * 6 - 90); // время, когда должна прокрутиться стрелка минут
	seconds.setRotation(s * 6 - 90); // то же самое, что и выше, но для секунд
}

void mt::Clock::render()
{
	// отрисовываем циферблат, часы, минуты и секунды
	m_Window.clear();
	m_Window.draw(background);
	m_Window.draw(hours);
	m_Window.draw(minutes);
	m_Window.draw(seconds);

	m_Window.display();
}

void mt::Clock::eventsHandler()
{
	sf::Event event;
	while (m_Window.pollEvent(event)) // пока поступают события
	{
		// закрыть при закрытии окна или при нажании на Esc
		if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
			m_Window.close();
	}
}

// деконструктор
mt::Clock::~Clock()
{

}