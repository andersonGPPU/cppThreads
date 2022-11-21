#include <vector>
#include <thread>
#include <iostream>
#include <clocale>

void diga_ola(uint64_t id) {
	std::cout << "Diga olá para a thread: " << id << std::endl;
}

void conta(uint64_t c, char ch) {
	std::cout << "valor contado: " << c << std::endl;
	std::cout << "Caractere: " << ch << std::endl;
}

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "");

	const uint64_t n_threads = 4;
	std::vector<std::thread> mthreads;

	//para todas as threads
	for (uint64_t id = 0; id < n_threads; id++) mthreads.emplace_back(conta, id, 'a');

	//junta each thread ao fim
	for (uint64_t id = 0; id < n_threads; id++) {
		mthreads[id].join(); //realinha todas as threads dentro da principal
	}

	return 0;
}