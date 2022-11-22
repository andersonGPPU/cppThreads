#include <vector>
#include <thread>
#include <iostream>
#include <clocale>
#include <numeric> // std::accumulate

void frange(uint64_t &sum, uint64_t start, uint64_t end) {
	sum = 0;
	for (uint64_t i = start; i < end; sum += i, i++);
}

void PrintVector(std::vector<uint64_t> &s) {
	std::cout << "S[0]: " << s[0] << std::endl;
	std::cout << "S[1]: " << s[1] << std::endl;
	std::cout << "S[2]: " << s[2] << std::endl;
	std::cout << "S[3]: " << s[3] << std::endl;
}

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "");

	const uint64_t n_threads = 4, n_elem = 1000000000, step = n_elem/n_threads;
	std::vector<uint64_t> p_sum(n_threads);

	//instancia e inicializa cada thread
	std::thread t1(frange, std::ref(p_sum[0]), 0, step);
	std::thread t2(frange, std::ref(p_sum[1]), step, 2 * step);
	std::thread t3(frange, std::ref(p_sum[2]), 2 * step, 3 * step);
	std::thread t4(frange, std::ref(p_sum[3]), 3 * step, 4 * step);

	//espera pela finalização das threads
	t1.join(); t2.join(); t3.join(); t4.join();

	//accumulate(vetor.inicio, vetor.fim, começando em posição [zero])
	uint64_t total = std::accumulate(p_sum.begin(), p_sum.end(), uint64_t(0));

	PrintVector(p_sum);

		std::cout << "Total: " << total << std::endl;

	return 0;
}