#include "Includes.h"

using std::cout;
using std::endl;

VMTHOOKS * hooker = new VMTHOOKS;

class VirtualTable
{
public:

	virtual void VirtualFunction01(void);
};

void VirtualTable::VirtualFunction01(void)
{
	cout << "VirtualFunction01 called" << endl;
}

// we use this to store and call our function
typedef void(__thiscall *oVFunction)(void* thisptr);
oVFunction oFunctionBase;


void __fastcall hook(void* thisptr, int edx) {

	std::cout << "hacked" << std::endl;
	oFunctionBase(thisptr);
}

int main()
{
	VirtualTable* sum = new VirtualTable();
	sum->VirtualFunction01();
	oFunctionBase = (oVFunction)hooker->Hook((LPVOID)sum, hook, NULL);
	sum->VirtualFunction01();
	system("PAUSE");


}