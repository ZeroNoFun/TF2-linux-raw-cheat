#include "sdk.hpp"
#include <stdio.h>

int __attribute__((constructor)) main()
{
	freopen("/tmp/log.txt", "w", stdout);

	Interfaces::Init();
	Netvars::Init();
	Hooks::Init();
	Utils::Init();
	Utils::GrabOffsets();
}	
