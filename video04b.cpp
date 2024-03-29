#include <iostream>
#include <locale>
#include <thread>
#include <string>
#include <future>

void func(std::promise<std::string> & prms) {
	std::string str("Mensagem enviado ao futuro.");
	//std::cout << "Ponteiro na função: " << (void*)str.data() << std::endl;
	prms.set_value(str);
}

int main()
{
	setlocale(LC_ALL, "Portuguese_Brasil.1252"); system("chcp 1252 > nul");
	
	std::promise<std::string> prms; //cria a promessa
	std::thread t(&func, std::ref(prms));
	std::cout << "Aqui é parte do programa principal." << std::endl;
	std::future<std::string> ftr = prms.get_future(); //pega do futuro
	std::string rstr = ftr.get(); //recupera o que foi prometido
	std::cout << rstr << std::endl;
	//std::cout << "Ponteiro recuperado: " << (void*)rstr.data() << std::endl;
	t.join();
	
	return 0;
}
