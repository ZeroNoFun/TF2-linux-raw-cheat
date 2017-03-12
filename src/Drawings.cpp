#include "sdk.hpp"

void Drawings::DrawFilledRect(int x, int y, int w, int h, Color col)
{
		Interfaces::surface->DrawSetColor(col);
		Interfaces::surface->DrawFilledRect(x, y, x + w, y + h);
}

void Drawings::DrawOutlinedRect(int x, int y, int w, int h, Color col)
{
		Interfaces::surface->DrawSetColor(col);
		Interfaces::surface->DrawOutlinedRect(x, y, x + w, y + h);
}