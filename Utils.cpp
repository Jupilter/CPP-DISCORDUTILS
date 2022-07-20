#include <iostream>
#include <cpr/cpr.h>
#include <string>



int destroy_webhook(std::string webhook)
{
	cpr::Response r = cpr::Delete(cpr::Url(webhook));
	std::cout << "\n STATUS CODE: ";
	std::cout << r.status_code;
	if (r.status_code == 204) 
	{
		std::cout << "\nWebhook Deleted Succcesfully";
	}
	else if (r.status_code == 404)
	{
		std::cout << "\nWebhook Destroyer Failed!";
	}
	return r.status_code;
}

int send_webhook_message(std::string webhook, std::string msg)
{



	cpr::Response r = cpr::Post(cpr::Url{ webhook },
		cpr::Payload{ {"content", msg} });

	if (r.status_code == 204)
	{
		std::cout << "Successfully Sent Message!\r\n";
	}
	if (r.status_code == 429)
	{
		std::cout << "Failed To send message because of overflow waiting 10 seconds\r\n";
		Sleep(10000);
	}
	if (r.status_code == 404)
	{
		std::cout << "Webhook Deleted\r\n";
	}




	return r.status_code;
}
int check_token(std::string token)
{

	cpr::Response r = cpr::Get(cpr::Url{ "https://discord.com/api/v9/users/@me" }, cpr::Header{ {"Content-Type", "application/json"} }, cpr::Header{ {"Authorization", token} });

	

	//

	//cpr::Header{ {"token", token} };

	
if (r.status_code == 200)
{
	std::cout << "TOKEN VALID: " << std::endl;

	
}
else {
	std::cout << "Token Invalid " << std::endl;
}




	return r.status_code;
}

