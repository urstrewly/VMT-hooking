#include "Includes.h"

using std::cout;
using std::endl;

VMTHOOKS * hooker = new VMTHOOKS;

class shitgame
{
public:

	virtual void CreateMove(void);
};

void shitgame::CreateMove(void)
{
	cout << "CreateMove called" << endl;
}

// we use this to store and call our function
typedef void(__thiscall *oVFunction)(void* thisptr);
oVFunction oFunctionBase;


void __fastcall hook(void* thisptr, int edx) {
	oFunctionBase(thisptr);
	cout << "ultra hacking aimbot" << endl;
	while(1)
		std::cout << "getting aim aingles" << endl;

}

int main()
{
	shitgame* sum = new shitgame();
	sum->CreateMove();
	oFunctionBase = (oVFunction)hooker->Hook((LPVOID)sum, hook, NULL);

	while (1) {
		sum->CreateMove();

	}


}
