/*Задание 1. Заплыв на 100 метров

Что нужно сделать
Реализуйте симуляцию состязаний по заплыву на 100 метров.
Всего шесть дорожек и шесть пловцов. Имена пловцов указываются вначале из
стандартного ввода. Каждый из них плывёт с разной скоростью, которая также
задаётся пользователем при старте, через стандартный ввод в метрах в секунду.
Каждую секунду в стандартный вывод выдаётся информация о том, сколько
проплыл тот или иной пловец.
Как только все пловцы коснулись 100-метровой отметки, заплыв заканчивается и
выводится таблица с итоговыми результатами, отсортированная по возрастанию
итогового времени заплыва.*/

#include "Swimmer.h"

int main()
{
	std::vector<Swimmer> start;

	for (int i = 0; i < NUMBERTRACKS; i++) {

		std::cout << "Inter the data of " << i + 1 << " swimmer" << std::endl;

		start.push_back(InputSwimmer());
	}

	std::thread track1(Start, &start[0]);

	std::thread track2(Start, &start[1]);

	std::thread track3(Start, &start[2]);

	std::thread track4(Start, &start[3]);

	std::thread track5(Start, &start[4]);

	std::thread track6(Start, &start[5]);

	track1.join();

	track2.join();

	track3.join();

	track4.join();

	track5.join();

	track6.join();

	acc.lock();

	for (std::vector<Swimmer*>::iterator it = finish.begin(); it != finish.end(); it++) {

		int r{ 1 };

		std::cout << r << " place " << (*it)->GetNameSwimmer() << std::endl;
	}

	acc.unlock();
}

