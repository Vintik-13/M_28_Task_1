#include "Swimmer.h"

void Swimmer::SetName(std::string name) { this->name = name; }

void Swimmer::SetSpeed(int speed) {	this->speed = speed; }

std::string Swimmer::GetNameSwimmer() {	return name; }

int Swimmer::GetSpeedSwwimmer() { return speed; }

void Start(Swimmer* s) {

	int d{ 0 };
	while (((DISTANCE - d) - s->GetSpeedSwwimmer()) > 0) {

		acc.lock();

		acc.unlock();

		d += s->GetSpeedSwwimmer();

		acc.lock();

		std::cout << "Swimmer - " << s->GetNameSwimmer() << " swam by " << d << " meters distance" << std::endl;

		acc.unlock();

		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	acc.lock();

	std::cout << s->GetNameSwimmer() << " - FINISH!!!" << std::endl;

	finish.push_back(s);

	acc.unlock();
}

bool IsSpeed(std::string speed) {
	
	std::regex pattern("\\d*");

	return std::regex_match(speed.c_str(), pattern) ? true : false;
}

Swimmer InputSwimmer() {

	Swimmer tmp;

	std::cout << "Input name swimmer: ";

	std::string name;

	std::getline(std::cin, name);

	tmp.SetName(name);

	std::cout << "Input speed swimmer: ";

	std::string speed;

	std::getline(std::cin, speed);

	while (!IsSpeed(speed)) {

		std::cout << "Inter a positive integer: ";

		std::getline(std::cin, speed);
	}

	tmp.SetSpeed(std::stoi(speed));

	return tmp;
}
