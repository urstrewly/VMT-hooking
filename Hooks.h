#ifndef  _HOOK_SHIT_
#define	 _HOOK_SHIT_	

class VMTHOOKS
{
public:
	VMTHOOKS();
	~VMTHOOKS();

	LPVOID Hook(LPVOID, PVOID, uintptr_t);

private:
	DWORD dwOldProtection;
	uintptr_t virtualTable, oFunction, oOriginalFunc;
};



extern VMTHOOKS* hooker;

#endif // !1
