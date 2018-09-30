
#include "Includes.h"


VMTHOOKS::VMTHOOKS()
{
}

VMTHOOKS::~VMTHOOKS()
{
}

LPVOID VMTHOOKS::Hook(LPVOID obj, PVOID hFunction, uintptr_t index)
{
	
	 virtualTable = *((uintptr_t *)obj); // the VMT table to located at the start of the object in memory
	 oFunction = virtualTable + index;
	 oOriginalFunc = *((uintptr_t*)oFunction);
	 
	 ::VirtualProtect((LPVOID)oFunction, sizeof(uintptr_t), PAGE_EXECUTE_READWRITE, &dwOldProtection);
	 // begin

	 *((uintptr_t*)oFunction) = (uintptr_t)hFunction;

	 // end
	 ::VirtualProtect((LPVOID)oFunction, sizeof(uintptr_t), dwOldProtection, &dwOldProtection);



	return (LPVOID) oOriginalFunc;
}
