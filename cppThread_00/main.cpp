#include <iostream>
#include <thread>
#include <clocale>
#include "Contar.h"

void f1() {
	std::cout << "\nf1 - começou." << std::endl;
	for (unsigned long long x = 0; x <= 20000000000; x++);
	std::cout << "\nf1 - terminou." << std::endl;
}

void f2(unsigned short v) {
	std::cout << "\nf2 - começou." << std::endl;
	for (unsigned long long y = v; y <= 20000000000; y++);
	std::cout << "\nf2 - terminou." << std::endl;
}

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "");

	Conte teste1_cpp;
	std::thread wclasse1(&Conte::teste1, teste1_cpp);
	std::thread wclasse2(&Conte::teste2, teste1_cpp, 0);

	std::thread w1(f1);
	std::thread w2(f2, 0);

	/*joinable verifica se a thread está em andamento. Ela retorna 1 se estive e 0 se não. */
	if (w1.joinable()) std::cout << "A thread w1 está em execução!" << std::endl;
	else std::cout << "A thread w1 NÃO está em execução!" << std::endl;
	if (w2.joinable()) std::cout << "A thread w2 está em execução!" << std::endl;
	else std::cout << "A thread w2 NÃO está em execução!" << std::endl;

	if (wclasse1.joinable()) std::cout << "A thread wClasse1 está em execução!" << std::endl;
	else std::cout << "A thread wClasse1 NÃO está em execução!" << std::endl;
	if (wclasse2.joinable()) std::cout << "A thread wClasse2 está em execução!" << std::endl;
	else std::cout << "A thread wClasse2 NÃO está em execução!" << std::endl;

	std::cout << "função 1 e 2 estão executando corretamente...\n" << std::endl << std::endl;
	std::cout << "ID da função principal: " << std::this_thread::get_id() << std::endl; //identificação da thread da 'main'
	std::cout << "ID da thread w1: " << w1.get_id() << std::endl;
	std::cout << "ID da thread w2: " << w2.get_id() << std::endl << std::endl;
	std::cout << "ID da thread wClasse1: " << wclasse1.get_id() << std::endl;
	std::cout << "ID da thread wClasse2: " << wclasse2.get_id() << std::endl << std::endl;

	std::cout << "Chamando o método swap para a troca de ID entre w1 e w2..." << std::endl << std::endl;
	w1.swap(w2); //swap(w1,w2); //outra forma de se permutar os ID's das threads

	std::cout << "Novo ID da thread w1: " << w1.get_id() << std::endl;
	std::cout << "Novo ID da thread w2: " << w2.get_id() << std::endl << std::endl;

	w1.join(); //join() garante que a Thread complete corretamente sem que este seja feito pela finalização do 'main'
	w2.join(); //w1 e w2 não estão em sincronia
	wclasse1.join();
	wclasse2.join();

	std::cout << "Método join foi chamado...\n" << std::endl;
	//ao encerrar, a thread automaticamente libera os recursos alocados, por meio do método 'Terminate'

	if (w1.joinable()) std::cout << "A thread w1 está em execução!" << std::endl << std::endl;
	else std::cout << "A thread w1 NÃO está em execução!" << std::endl << std::endl;
	if (w2.joinable()) std::cout << "A thread w2 está em execução!" << std::endl << std::endl;
	else std::cout << "A thread w2 NÃO está em execução!" << std::endl << std::endl;

	if (wclasse1.joinable()) std::cout << "A thread wClasse1 está em execução!" << std::endl << std::endl;
	else std::cout << "A thread wClasse1 NÃO está em execução!" << std::endl << std::endl;
	if (wclasse2.joinable()) std::cout << "A thread wClasse2 está em execução!" << std::endl << std::endl;
	else std::cout << "A thread wClasse2 NÃO está em execução!" << std::endl << std::endl;

	return 0;
}