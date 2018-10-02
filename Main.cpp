#include "Includes.h"

int a = 10;
int b = 10;

using std::cout;
using std::cin;
using std::endl;

VMTHOOKS * hooker = new VMTHOOKS;

class process
{
public:

	virtual void movement(int, int);
};

void process::movement(int x, int y)
{
	std::cout << x << "  :  "<< y << std::endl;
}

// we use this to store and call our function

using oVFunction = void(__stdcall*)(int, int);
oVFunction oFunctionBase;

void __stdcall hook(int x, int y) {

	x = x * x;
	y = y * y;
	std::cout << "ultra" << std::endl;


	for(int i = 0; i < 10; i++)
		oFunctionBase(x, y);

	

}

int main()
{

		process* sum = new process();
		sum->movement(a, b);

		
		oFunctionBase = (oVFunction)hooker->Hook((LPVOID)sum, hook, NULL);
		sum->movement(a, b);

	// unhooking breaks sum->movement
		oFunctionBase  = (oVFunction)hooker->UnHook((LPVOID)sum, NULL);

		for (int i = 0; i < 10; i++)
			oFunctionBase(a, b);

		system("PAUSE");


}
