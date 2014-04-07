#include "Python.h"


int main()
{
	//Initializing Python Scripting Binding
	Py_Initialize();//Creates Modules __builtin__, __main__ and sys, and initializes the module search path
	//Py_Initialize doesn't set the current directory to the path lookup for python imports

	//Adding current directory to the path lookup for python imports
	PySys_SetArgv(argc, argv);

	//This allows us to path to subfolders within' our project so that everything isn't just in one icky pile in one place
	//To do this we make a new PyObject called sysPath and clone our current path:
	PyObject* sysPath = PySys_GetObject((char*)"path");

	//Then we need to append a new "level" / "Node" / "Step" / "Branch" to the end of this path. In this case we are creating a path to a "Scripts" folder.
	PyList_Append(sysPath, PyString_FromString("./scripts"));


	return 0;
}