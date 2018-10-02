
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
	 oOriginalFunc = *((uintptr_t*)oFunction); // before we change vfTable pointer to our function cheat
	 
	 ::VirtualProtect((LPVOID)oFunction, sizeof(uintptr_t), PAGE_EXECUTE_READWRITE, &dwOldProtection);
	 // begin


	 // CreateMove = hkCreateMove
	 *((uintptr_t*)oFunction) = (uintptr_t)hFunction;


	 std::cout << "objects VMT table :\t"			 << virtualTable		  << " @\t"  << &virtualTable  << std::endl;
	 std::cout << "desired function in VMT table :\t" << oFunction			  << " @\t"  << &oFunction     << std::endl;

	 std::cout << "changing interface vtable pointers to cheat functions !DONE\n" << oOriginalFunc << " = " << hFunction << std::endl;

	 // end
	 ::VirtualProtect((LPVOID)oFunction, sizeof(uintptr_t), dwOldProtection, &dwOldProtection);



	return (LPVOID) oOriginalFunc;
}

LPVOID VMTHOOKS::UnHook(LPVOID obj, uintptr_t index)
{


	try	{
		if (oOriginalFunc != 0) {
			std::cout << "Found original Function" << oOriginalFunc << std::endl;
			std::cout << *((uintptr_t *)obj + index) << " = " << oOriginalFunc << std::endl;
			*((uintptr_t *)obj + index) = oOriginalFunc;
			oOriginalFunc = 0;
			return (LPVOID)*((uintptr_t *)obj + index);
		}
	}
	catch (...){
	}
}
