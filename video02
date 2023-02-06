#include <iostream>
#include <vector>
#include <locale>
#include <thread>
#include <algorithm>

void pares(long long y) {
	if(y % 2 == 0) std::cout << "número par: " << y << std::endl;
	else std::cout << "número ímpar: " << y << std::endl;
}

int main()
{
	setlocale(LC_ALL, "Portuguese_Brasil.1252"); system("chcp 1252 > nul");
	
	std::vector<std::thread> wk;
	for (int i = 0; i < 8; ++i) {
		std::thread th(&pares, i);
		wk.push_back(std::move(th));
	}
	std::cout << "Programa PRINCIPAL." << std::endl;

	std::for_each(wk.begin(), wk.end(), [](std::thread& t) { if (t.joinable()) t.join(); });

	return 0;
} 
