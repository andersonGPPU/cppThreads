#include "Contar.h"
#include <thread>
#include <iostream>

Conte::Conte() {
	this->ch = nullptr;
}
Conte::~Conte() {

}

void Conte::teste1(void) {
	std::cout << "\nClasse::Conte { teste1 } INICIANDO" << std::endl;
	for (unsigned long long x = 0; x <= 20000000000; x++);
	std::cout << "\nClasse::Conte { teste1 } CONCLUÍDO" << std::endl;
}

void Conte::teste2(unsigned short v) {
	std::cout << "\nClasse::Conte { teste2 } INICIANDO" << std::endl;
	for (unsigned long long y = v; y <= 20000000000; y++);
	std::cout << "\nClasse::Conte { teste2 } CONCLUÍDO" << std::endl;
}
