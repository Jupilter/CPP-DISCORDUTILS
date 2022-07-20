#include <iostream>
#include <cpr/cpr.h>

#include "Utils.h"

int main()
{
	std::cout << R"(
__________  ___ ___    _____    __________________________      _____   
\______   \/   |   \  /  _  \   \      \__    ___/\_____  \    /     \  
 |     ___/    ~    \/  /_\  \  /   |   \|    |    /   |   \  /  \ /  \ 
 |    |   \    Y    /    |    \/    |    \    |   /    |    \/    Y    \
 |____|    \___|_  /\____|__  /\____|__  /____|   \_______  /\____|__  /
                 \/         \/         \/                 \/         \/ 

)";


	int option;
	std::cout << "\n\n\n";
	std::cout << "[1] Webhook Destroyer\n[2] Webhook Spammer\n[3] Check Token\n";
	std::cout << ">>> ";
	std::cin >> std::ws >> option;
	if (option == 1)
	{
		std::cout << "Enter Webhook \r\n";
		std::cout << ">>> ";
		std::string hook;
		std::getline(std::cin >> std::ws, hook);

		destroy_webhook(hook);
	}
	if (option == 2)
	{
		std::cout << "Enter Webhook [NO ASYNC]\r\n";
		std::cout << ">>> ";
		std::string hook;
		std::string msg;
		std::getline(std::cin >> std::ws, hook);
		std::cout << "Enter Message \r\n";
		std::cout << ">>> ";
		std::getline(std::cin >> std::ws, msg);

		while (true) 
		{
			send_webhook_message(hook, msg);
		}
	}
	if (option == 3)
	{
		std::string token;
		std::cout << "Enter Token \r\n";
		std::cout << ">>> ";
		getline(std::cin >> std::ws, token);
		check_token(token);


	}
	
	

	return 0;
}