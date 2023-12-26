#pragma once
#include "../../Libs/IL2CppWrapper/il2cpp.hpp"
#include <iostream>
using namespace std;
MethodInfo* setrankfunc; //This is Function About My Rank :D
Il2CppException* exc;
bool ishacked;
void AllocateConsole() {
    FILE* fp;
    freopen_s(&fp, "CONOUT$", "w", stdout);
    AllocConsole();
    SetConsoleTitleA("Numbonedify by RiritoNinigaya");
}
void IL2CPP_INIT() {
    IL2CPP::Init();
}
void SetRank(int rank_number) 
{
	void* args[1] = { &rank_number };
	il2cpp_runtime_invoke(setrankfunc, nullptr, args, &exc);
	std::cout << "Successfully Hacked Rank Function!!! :>" << std::endl;
}
void keyH() {
    for (;;)
    {
        if (GetAsyncKeyState(VK_F5) & 1) {
            ishacked = !ishacked;
            int thirtyrank = 300;
            int ranked = ishacked ? thirtyrank : 300;
            SetRank(ranked);
        }
        Sleep(0.5);
    }
}

void MainFunc()
{
    IL2CPP_INIT();
    Sleep(2000);
    Il2CppDomain* domain = il2cpp_domain_get();
    if (!domain) {
        cout << "This Is Not IL2Cpp Game or This Game Is Not Supported IL2Cpp!!!" << endl;
    }
    il2cpp_thread_attach(domain);
    AllocateConsole();
    std::cout << "IL2Cpp Initializated" << std::endl;
    std::cout << "DOMAIN ID: " << domain->domain_id << std::endl;
    Il2CppImage* image_assembly = il2cpp_domain_assembly_open(domain, "Assembly-CSharp.dll")->image;
    Il2CppClass* setrankclass = il2cpp_class_from_name(image_assembly, "", "NolanRankController");
    setrankfunc = (MethodInfo*)il2cpp_class_get_method_from_name(setrankclass, "SetRank", 1);
    keyH();
}