#pragma once
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <filesystem>
#include "../Numbonedify/Libs/IL2CppWrapper/il2cpp.hpp"
#include "../Numbonedify/Libs/DEVOUR_FUNC/SetRank.hpp"
using namespace std;
namespace file = std::filesystem;


bool INIT_IL2CPP() {
	HWND hwnd_devour;
	hwnd_devour = FindWindowA(0, "DEVOUR");
	if (!hwnd_devour) {
		return false;
	}
	IL2CPP::Init();
	return true;
}