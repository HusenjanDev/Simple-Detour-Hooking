# Simple-Detour-Hooking

The following GitHub repository uses detour hooking method to replace **functionOne()** with **hookedFunctionOne()**. When the f1 key has been pressed the hookedFunctionOne() attaches to **functionOne()** and when the f2 key has been pressed the **hookedFunctionOne()** detatches itself.

**Important:** The DWORD Address needs to be assigned the address of functionOne() *”You should be able to get the address once you ran the executable program”*
