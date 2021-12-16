#pragma once
#include "SFML/Graphics.hpp" // ���������� ��� ��������� �������
#include <Windows.h> // ��� ������ � ��������� ��������
namespace mt
{
	class Clock
	{
	public:
		Clock(); // �����������
		void run(); // ������
		void update(int h, int m, int s); // �������� �������
		void render(); // ���������
		void eventsHandler(); // ��������� �������
		~Clock(); //  ����������

	private:
		sf::RenderWindow m_Window; // ����
		sf::Texture clockFace; // ���������
		sf::Sprite background;

		sf::RectangleShape hours; // ������� �����
		sf::RectangleShape minutes; // ������� �����
		sf::RectangleShape seconds; // ������� ������
		SYSTEMTIME time; // ���������� ��� �������� ������� �������
	};
}