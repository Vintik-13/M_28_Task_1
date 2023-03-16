#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <mutex>
#include <regex>
#include <thread>
#include <chrono>

class Swimmer;

const int NUMBERTRACKS{ 6 };
const int DISTANCE{ 100 };

extern std::mutex acc;
extern std::vector<Swimmer*> finish;

class Swimmer {

	std::string name;
	int speed;

public:
	Swimmer() : name{ "" }, speed{ 0 } {}

	Swimmer(std::string name, int speed) : name(name), speed(speed) {}

	void SetName(std::string name);

	void SetSpeed(int speed);

	std::string GetNameSwimmer();

	int GetSpeedSwwimmer(); 

	~Swimmer() {}
}; 

void Start(Swimmer* s); 

bool IsSpeed(std::string speed); 

Swimmer InputSwimmer(); 


