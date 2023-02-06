#include <iostream>
#include <vector>
#include <locale>
#include <thread>
#include <algorithm>
#include <list>

void func(std::list<double>& lis) {
	std::for_each(lis.begin(), lis.end(), [](double& dp) {
		dp = sin(dp);
		});
}

int main()
{
	setlocale(LC_ALL, "Portuguese_Brasil.1252"); system("chcp 1252 > nul");
	
	std::list<double> ll;

	const double pi = 3.141592;
	const double eps = 0.0000001;

	for (double x = 0.0; x < 2 * pi + eps; x += pi / 16) ll.push_back(x);
	//threads
	std::thread w(&func, std::ref(ll));
	//unindo threads
	w.join();
	//fora da thread
	std::for_each(ll.begin(), ll.end(), [](double& d) {
		int c = static_cast<int>(10 * d + 10.5);
		for (int i = 0; i < c; ++i) std::cout.put('*'); //imprime asterisco
		std::cout << std::endl;
		});

	return 0;
} 
