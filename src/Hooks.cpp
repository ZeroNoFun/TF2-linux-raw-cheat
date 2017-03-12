#include "sdk.hpp"

#include <dlfcn.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <iostream>

/*Typedefs*/
typedef void (*PaintTraverseFn) (void*, unsigned int, bool, bool);
/*Typedefs*/

/*VMT's*/
AltVMT* panelVmt;
/*VMT's*/

void Hooks::hooked_paint_traverse(void* thisptr, unsigned int vgui_panel, bool force_repaint, bool allow_force)
{
	((PaintTraverseFn)panelVmt->real[42])(thisptr, vgui_panel, force_repaint, allow_force);

 	static unsigned int drawPanel = 0;

	 if(!drawPanel)
	 {
	 	std::string szPanelName = Interfaces::panel->GetName(vgui_panel);
	 	if(szPanelName.find("FocusOverlayPanel") != std::string::npos)
			drawPanel = vgui_panel;
	 }

	 if(drawPanel && vgui_panel == drawPanel)
	 {

	 	CPlayer *localPlayer = (CPlayer*)Interfaces::entitylist->GetClientEntity(LocalPlayerIndex);

	 	if(!localPlayer)
	 		return;

	 	for(int i = 1; i <= Interfaces::engine->GetMaxClients(); i++)
	 	{
	 		CPlayer *player = (CPlayer*)Interfaces::entitylist->GetClientEntity(i);

	 		if(!player)
	 			continue;

	 		if(player->GetTeam() == localPlayer->GetTeam())
	 			continue;

	 		if(player->GetHealth() < 1)
	 			continue;

	 		if(player->GetLifeState() != 0)
	 			continue;

	 		Vector screen;

	 		Vector vecPos = player->GetAbsOrigin();

	 		if(Utils::WorldToScreen(vecPos, screen))
	 		{
	 			Drawings::DrawOutlinedRect(screen.x-10,screen.y-10-50,20,20,Color(10,10,255,255));
	 		}
	 	}
	}	

}

void Hooks::Init()
{
	/*PaintTraverse*/
	panelVmt = new AltVMT(Interfaces::panel);

	panelVmt->fake[42] = (void*)hooked_paint_traverse;
	/*PaintTraverse*/
}