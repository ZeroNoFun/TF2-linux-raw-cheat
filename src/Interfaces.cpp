#pragma once
#include "sdk.hpp"

#include <dlfcn.h>
#include <stdio.h>
#include <stdint.h>
#include "sdk.hpp"
#include <string.h>
#include <iostream>

typedef void *(*create_interface_t)(const char*, int*);

IBaseClientDLL *Interfaces::client = nullptr;
IVEngineClient *Interfaces::engine = nullptr;
IVPanel *Interfaces::panel = nullptr;
ISurface *Interfaces::surface = nullptr;
IEntityList *Interfaces::entitylist = nullptr;

void Interfaces::Init()
{
	void *client_so = dlopen("./tf/bin/client.so", RTLD_LAZY);
	void *engine_so = dlopen("./bin/engine.so", RTLD_LAZY);
	void *vgui_so = dlopen("./bin/vgui2.so", RTLD_LAZY);
	void *materialsurface_so = dlopen("./bin/vguimatsurface.so", RTLD_LAZY);


	client = (IBaseClientDLL*)((create_interface_t) dlsym(client_so, "CreateInterface"))("VClient017", NULL);
	entitylist = (IEntityList*)((create_interface_t) dlsym(client_so, "CreateInterface"))("VClientEntityList003", NULL);
	engine = (IVEngineClient*)((create_interface_t) dlsym(engine_so, "CreateInterface"))("VEngineClient013", NULL);
	panel = (IVPanel*)((create_interface_t) dlsym(vgui_so, "CreateInterface"))("VGUI_Panel009", NULL);
	surface = (ISurface*)((create_interface_t) dlsym(materialsurface_so, "CreateInterface"))("VGUI_Surface030", NULL);
}