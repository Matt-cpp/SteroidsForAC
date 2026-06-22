#include "utilities/memory.h"
#include "utilities/offsets.h"
#include <string>
#include <iostream>
#include <vector>
#include <thread>

// Menu Colors
const std::string red = "\033[31m";
const std::string green = "\033[32m";
const std::string yellow = "\033[33m";
const std::string blue = "\033[34m";
const std::string magenta = "\033[35m";
const std::string cyan = "\033[36m";
const std::string white = "\033[37m";
const std::string reset = "\033[0m";

// Logo
std::vector<std::string> logo{
	"           _____      _____ _______ ______ _____   ____ _____ _____   _____ ",
	"     /\\   / ____|    / ____|__   __|  ____|  __ \\ / __ \\_   _|  __ \\ / ____|",
	"    /  \\ | |        | (___    | |  | |__  | |__) | |  | || | | |  | | (___  ",
	"   / /\\ \\| |         \\___ \\   | |  |  __| |  _  /| |  | || | | |  | |\\___ \\ ",
	"  / ____ \\ |____     ____) |  | |  | |____| | \\ \\| |__| || |_| |__| |____) |",
	" /_/    \\_\\_____|   |_____/   |_|  |______|_|  \\_\\\\____/_____|_____/|_____/ "
};

int main() {
	Memory memory{ "ac_client.exe" };
	const auto ModuleBaseAddress = memory.GetModuleAddress("ac_client.exe");

	// Dereference the pointer
	const auto localPlayerAddress = memory.Read<std::uintptr_t>(ModuleBaseAddress + localPlayer);
	const auto healthAddress = localPlayerAddress + health;
	const auto armorAddress = localPlayerAddress + armor;
	const auto ARammoAddress = localPlayerAddress + ARammo;
	const auto nameAddress = localPlayerAddress + nameOffsetWithinPadding;

	std::string name = memory.Read<NamePadding>(nameAddress).preNamePadding;

	std::cout << std::endl;
	for (const auto& line : logo) {
		std::cout << magenta << line << std::endl;
	}

	std::cout << std::endl << green << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << reset << std::endl;

	std::cout << std::endl;
	std::cout << "Welcome to AC STEROIDS, " << cyan << name << "\n" << std::endl;
	std::cout << green << "F1: Health Hack" << std::endl;
	std::cout << "F2: Armor Hack" << std::endl;
	std::cout << "F3: AR Ammo Hack" << std::endl;

	while (true) {
		if (GetAsyncKeyState(VK_F1) & 0x8000) {// 0x8000 checks if the key is pressed down
			memory.Write<int>(healthAddress, 1000);
			std::cout << "Health hacked" << std::endl;
		}
		else if (GetAsyncKeyState(VK_F2) & 0x8000) {
			memory.Write<int>(armorAddress, 1000);
			std::cout << "Armor hacked" << std::endl;
		}
		else if (GetAsyncKeyState(VK_F3) & 0x8000) {
			memory.Write<int>(ARammoAddress, 1000);
			std::cout << "AR ammo hacked" << std::endl;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}