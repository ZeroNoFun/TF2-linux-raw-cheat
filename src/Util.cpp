#include "sdk.hpp"

int Utils::ScreenSizeW = NULL;
int Utils::ScreenSizeH = NULL;

Offsets offsets;

void Utils::GrabOffsets()
{
	offsets.m_iHealth = Netvars::GetNetvar("DT_BasePlayer", "m_iHealth");
	offsets.m_vecOrigin = Netvars::GetNetvar("DT_BaseEntity", "m_vecOrigin");
	offsets.m_iTeamNum = Netvars::GetNetvar("DT_BaseEntity", "m_iTeamNum");
	offsets.m_lifeState = Netvars::GetNetvar("DT_BasePlayer", "m_lifeState");
}

bool Utils::WorldToScreen(Vector &vOrigin, Vector &vScreen)
{
	const matrix3x4& worldToScreen = Interfaces::engine->WorldToScreenMatrix();
	float w = worldToScreen[3][0] * vOrigin[0] + worldToScreen[3][1] * vOrigin[1] + worldToScreen[3][2] * vOrigin[2] + worldToScreen[3][3];
	vScreen.z = 0;

	if(w > 0.01)
	{
		float inverseWidth = 1 / w;

		vScreen.x = (ScreenSizeW / 2) + (0.5 * ((worldToScreen[0][0] * vOrigin[0] + worldToScreen[0][1] * vOrigin[1] + worldToScreen[0][2] * vOrigin[2] + worldToScreen[0][3]) * inverseWidth) * ScreenSizeW + 0.5);
		vScreen.y = (ScreenSizeH / 2) - (0.5 * ((worldToScreen[1][0] * vOrigin[0] + worldToScreen[1][1] * vOrigin[1] + worldToScreen[1][2] * vOrigin[2] + worldToScreen[1][3]) * inverseWidth) * ScreenSizeH + 0.5);

		return true;
	}

	return false;
}

void Utils::Init()
{
	Interfaces::engine->GetScreenSize(ScreenSizeW, ScreenSizeH);
}
