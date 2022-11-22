#include <vector>
#include <thread>
#include <iostream>
#include <clocale>
#include <numeric> // std::accumulate

constexpr auto MAX_THRS = 1000;

void frange(uint64_t &sum, uint64_t start, uint64_t end) {
	sum = 0;
	for (uint64_t i = start; i < end; sum += i, i++);
}

void PrintVector(std::vector<uint64_t> &s) {
	unsigned int i = 0; uint64_t ts = 0;
	for (unsigned int i = 0; i < MAX_THRS; i++) {
		std::cout << "S[" << i << "]: " << s[i] << std::endl;
		ts += s[i];
	}
	std::cout << "total somado das parciais: " << ts << std::endl;
}

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "");

	const uint64_t n_threads = MAX_THRS, n_elem = 1000000000, step = n_elem/n_threads;
	std::vector<std::thread> th;
	std::vector<uint64_t> p_sum(n_threads);

	//cria, inicializa e insere no vetor
	for (uint64_t i = 0; i < n_threads; i++) {
		th.push_back(std::thread(frange, std::ref(p_sum[i]), i * step, (i + 1) * step));
	}//push_back exige que se defina o objeto 'frange' junto ao seu tipo 'std::thread'

	//espera pela finalização das threads
	for (std::thread& t : th) {
		if (t.joinable()) t.join();
	}

	//accumulate(vetor.inicio, vetor.fim, começando em posição [zero])
	uint64_t total = std::accumulate(p_sum.begin(), p_sum.end(), uint64_t(0));

	PrintVector(p_sum);

		std::cout << "Total: " << total << std::endl;

	return 0;
}