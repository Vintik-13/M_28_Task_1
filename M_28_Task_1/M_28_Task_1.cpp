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

std::mutex acc;
std::vector<Swimmer*> finish;

int main()
{
	std::vector<Swimmer> start;

	for (int i = 0; i < NUMBERTRACKS; i++) {

		std::cout << "Inter the data of " << i + 1 << " swimmer" << std::endl;

		start.push_back(InputSwimmer());
	}	

	std::vector<std::thread> swimming;

	for (int i = 0; i < NUMBERTRACKS; i++) {

		swimming.emplace_back(Start, &start[i]);
	}

	for (int i = 0; i < NUMBERTRACKS; i++) {

		swimming[i].join();
	}	

	acc.lock();

	int r{ 1 };

	for (std::vector<Swimmer*>::iterator it = finish.begin(); it != finish.end(); it++) {		

		std::cout << r << " place " << (*it)->GetNameSwimmer() << std::endl;

		r++;
	}

	acc.unlock();
}

