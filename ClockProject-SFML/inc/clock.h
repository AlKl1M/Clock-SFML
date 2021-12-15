#pragma once
#include "SFML/Graphics.hpp" // библиотека для отрисовки графики
#include <Windows.h> // для работы с системным временем
namespace mt
{
	class Clock
	{
	public:
		Clock(); // конструктор
		void run(); // запуск
		void update(int h, int m, int s); // вращение стрелок
		void render(); // отрисовка
		void eventsHandler(); // обработка событий
		~Clock(); //  деструктор

	private:
		sf::RenderWindow m_Window; // окно
		sf::Texture clockFace; // циферблат
		sf::Sprite background;

		sf::RectangleShape hours; // стрелка часов
		sf::RectangleShape minutes; // стрелка минут
		sf::RectangleShape seconds; // стрелка секунд
		SYSTEMTIME time; // переменная для хранения времени системы
	};
}