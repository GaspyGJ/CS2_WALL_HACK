#pragma once
#include <Windows.h>
#include <string>

namespace Offset
{
	// DWORD represent a data type to storage 32 bits without sign ( from <Windows.h> )
	 DWORD EntityList;
	 DWORD LocalPlayerController;
	 DWORD LocalPlayerPawn;

	// https://github.com/sezzyaep/CS2-OFFSETS/client.dll.py
	struct
	{
		DWORD Health = 0x334; //int32_t --> m_iHealth
		DWORD TeamId = 0x3CB; //uint8_t --> m_iTeamNum
		DWORD PlayerPawn = 0x604; // CHandle<C_BasePlayerPawn> --> m_hPawn
		DWORD EnemySensor = 0x1440; // GameTime_t --> m_flDetectedByEnemySensorTime
	} Entity;

	struct
	{
		DWORD CurrentHealth = 0x334; // int32_t --> m_iHealth
		DWORD pClippingWeapon = 0x1308; // C_CSWeaponBase* --> m_pClippingWeapon
		DWORD iIDEntIndex = 0x15A4; // m_iIDEntIndex--> CEntityIndex
		DWORD iTeamNum = 0x3CB; //uint8_t --> m_iTeamNum
		DWORD bSpottedByMask = 0x1698; // EntitySpottedState_t --> m_entitySpottedState
		// DWORD bSpottedByMask = 0x1698 + 0xC; 	
	} Player; //Pawn

	// https://github.com/a2x/cs2-dumper/blob/main/config.json
	namespace Signatures
	{
		const std::string EntityList = "48 8B 0D ?? ?? ?? ?? 48 89 7C 24 ?? 8B FA C1 EB";
		const std::string LocalPlayerController = "48 8B 05 ?? ?? ?? ?? 48 85 C0 74 4F";
		const std::string LocalPlayerPawn = "48 8D 05 ?? ?? ?? ?? C3 CC CC CC CC CC CC CC CC 48 83 EC ?? 8B 0D";
	}
}
