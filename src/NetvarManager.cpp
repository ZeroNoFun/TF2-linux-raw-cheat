#pragma once
#include "sdk.hpp"
#include <string.h>

#define RECV_SIZE 8192 

RecvTable *recvTables[RECV_SIZE];

void Netvars::Init()
{
	ClientClass* clientClass = Interfaces::client->GetAllClasses();

	if(!clientClass)
		return;

	int x = 0;

	while (clientClass)
	{
		if(!clientClass)
			continue;

		RecvTable *recvTable = clientClass->m_pRecvTable;
		recvTables[x] = recvTable;

		clientClass = clientClass->m_pNext;
		x++;
	}
}

int Netvars::GetNetvar(const char* dt, const char* m)
{
	for (int i = 0; i < sizeof(recvTables)/sizeof(*recvTables); i++)
	{
		if(recvTables[i] != NULL)
		{
			if(!strcmp(recvTables[i]->m_pNetTableName, dt))
			{
				for(int x = 0; x < recvTables[i]->m_nProps; x++)
				{
					if(!strcmp(recvTables[i]->m_pProps[x].m_pVarName, m))
					{
						return recvTables[i]->m_pProps[x].m_Offset;
					}
				}
			}
		}
	}
}
