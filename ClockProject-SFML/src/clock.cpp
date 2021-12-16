#include "Clock.h"
//� ������������ ����� ������� ���� 900�900, ������� �����, ����� � ������ � ���������
mt::Clock::Clock() : m_Window(sf::VideoMode(900, 900), "Clock", sf::Style::Close), hours(sf::Vector2f(200, 8)),
minutes(sf::Vector2f(260, 8)), seconds(sf::Vector2f(300, 4)), clockFace(), background()
{
	// ������������ �������� � �����������
	clockFace.loadFromFile("img/clockface.png");
	background.setTexture(clockFace);
	background.setPosition(0, 0);
	// ����������� ��� ������� �����
	hours.setFillColor(sf::Color::Black);
	hours.setOrigin(0, 2);
	hours.setPosition(450, 450);
	// ����������� ��� ������� �����
	minutes.setFillColor(sf::Color::Black);
	minutes.setOrigin(0, 2);
	minutes.setPosition(450, 450);
	// ����������� ��� ������� ������
	seconds.setFillColor(sf::Color::Red);
	seconds.setOrigin(0, 2);
	seconds.setPosition(450, 450);
}
// �����, ������� ������ ��� �������� � �������� ���������
void mt::Clock::run()
{
	while (m_Window.isOpen())
	{
		GetLocalTime(&time); //�������� ����� ��
		eventsHandler(); // ������������ �������
		update(time.wHour, time.wMinute, time.wSecond); // ���������� �����
		render(); // ������������
	}
}

void mt::Clock::update(int h, int m, int s) // �������� ��������� �������
{

	float hms = (h % 12) * 30 - 90 + ((m / 12) * 5); // �����, ����� ������� ������ ����������� ������� �����

	hours.setRotation(hms); // ������������� �����, ���������� ����
	minutes.setRotation(m * 6 - 90); // �����, ����� ������ ������������ ������� �����
	seconds.setRotation(s * 6 - 90); // �� �� �����, ��� � ����, �� ��� ������
}

void mt::Clock::render()
{
	// ������������ ���������, ����, ������ � �������
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
	while (m_Window.pollEvent(event)) // ���� ��������� �������
	{
		// ������� ��� �������� ���� ��� ��� ������� �� Esc
		if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
			m_Window.close();
	}
}

// �������������
mt::Clock::~Clock()
{

}