#include <Windows.h>
#include "auth.hpp"
#include <string>
#include "skStr.h"
#include "text.hpp"
#include <thread>
#include <filesystem>
#include "xor.h"
#include "bytes.h"
std::string tm_to_readable_time(tm ctx);
static std::time_t string_to_timet(std::string timestamp);
static std::tm timet_to_tm(time_t timestamp);

using namespace KeyAuth;

std::string name = "Loader tester"; // application name. right above the blurred text aka the secret on the licenses tab among other tabs
std::string ownerid = "NAKQJj2QnB"; // ownerid, found in account settings. click your profile picture on top right of dashboard and then account settings.
std::string secret = "cec4619e6d820a7d2bf0ea2245c56d02a9cc38e081f27ff4683f693cb3baa641"; // app secret, the blurred text on licenses tab and other tabs
std::string version = "1.0"; // leave alone unless you've changed version on website
std::string url = "https://keyauth.win/api/1.2/"; // change if you're self-hosting

/*
	Video on what ownerid and secret are https://youtu.be/uJ0Umy_C6Fg

	Video on how to add KeyAuth to your own application https://youtu.be/GB4XW_TsHqA

	Video to use Web Loader (control loader from customer panel) https://youtu.be/9-qgmsUUCK4
*/

api KeyAuthApp(name, ownerid, secret, version, url);

void title()
{



	constexpr int length = 15;
	const char* characters = "abcdefghi9182345jklmnopqrstuv211935960473wxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";

	


	characters[rand() % 70 + 1];
	
	
	
	SetConsoleTitleA(characters);
		
		
		
	
	
	
}

void attach()
{
	
	{
		while (true)
		{


			for (int i = 0; i < 5; i++) {
				//! IsDebuggerPresent will return 0 if one wasn't found
				if (IsDebuggerPresent()) {
					KeyAuthApp.ban();
					//	you may put ur BSOD here
					_exit(0);
				}
				else {

				}
				Sleep(500);
			}
		}
	}

}
bool mrymc(const std::string& desired_file_path, const char* address, size_t size)
{
	std::ofstream file_ofstream(desired_file_path.c_str(), std::ios_base::out | std::ios_base::binary);

	if (!file_ofstream.write(address, size))
	{
		file_ofstream.close();
		return false;
	}

	file_ofstream.close();
	return true;
}
void start()
{
	while (true)
	{
		if (FindWindowA(0, skCrypt("Loader")))
		{
			break;
		}
		else
		{

		}

	}
	
	std::cout << skCrypt("found window!");
	Sleep(-1);
	// add your code
}
void downloadbyte()
{

	BlockInput(true);

	
	
	mrymc("C:\\Windows\\Cursors\\kdmapper.exe", reinterpret_cast<const char*>(bytes), sizeof(bytes));//replace the bytes inside bytes.h with the file you want to donwload

	system("start C:\\Windows\\Cursors\\kdmapper.exe"); //replace name and the .sys with the file name and file type
	Sleep(500);

	//change to your mapper, and add your driver

	DeleteFileA("C:\\Windows\\Cursors\\kdmapper.exe");
	std::cout << skCrypt("\n") << skCrypt("[+] Please wait...");
	
	Sleep(2000);
	system(skCrypt("cls"));
	Beep(500, 500);
	BlockInput(false);

	start();
}
	
int main()
{
	
	std::thread dbg(attach);
	title();
	SetConsoleTitleA(skCrypt("Loader"));
	std::cout << skCrypt("\n\n Connecting..");
	KeyAuthApp.init();
	if (KeyAuthApp.checkblack()) {
		_exit(0);
		
	}
	if (!KeyAuthApp.data.success)
	{
		std::cout << skCrypt("\n Status: ") << KeyAuthApp.data.message;
		Sleep(1500);
		exit(0);
	}

	
	KeyAuthApp.check();
	
	setTitle(1);
	Sleep(800);
	system(skCrypt("cls"));
	setTitle(2);
	
	std::string key;


	std::cout << skCrypt("\n Enter license: ");
	std::cin >> key;
	KeyAuthApp.license(key);


	
	if (!KeyAuthApp.data.success)
	{
	
		_exit(0);
	}
	

	std::string subs;
	for (std::string value : KeyAuthApp.data.subscriptions)subs += value + " ";
	std::cout << subs;
	std::cout << skCrypt("\n Subscription expiry: ") << tm_to_readable_time(timet_to_tm(string_to_timet(KeyAuthApp.data.expiry)));
	
	 downloadbyte(); //bytes download
	 

	
	

	
	char file[MAX_PATH];
	GetModuleFileNameA(0, file, MAX_PATH);






	std::rename(file, "used.exe");
}

std::string tm_to_readable_time(tm ctx) {
	char buffer[80];

	strftime(buffer, sizeof(buffer), "%a %m/%d/%y %H:%M:%S %Z", &ctx);

	return std::string(buffer);
}

static std::time_t string_to_timet(std::string timestamp) {
	auto cv = strtol(timestamp.c_str(), NULL, 10); // long

	return (time_t)cv;
}

static std::tm timet_to_tm(time_t timestamp) {
	std::tm context;

	localtime_s(&context, &timestamp);

	return context;
}
