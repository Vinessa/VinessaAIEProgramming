// BigoNoteAlgEff.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{

bool IsFirstElementNull(int *items, int nItems)
{
printf(“testing first element of %i items\n”, items);

	if (items[0] == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//	int iTotal = 0; 
//int iNumIterations = 100000; 
//for(int i = 0;i < iNumIterations;++i) 
//{ 
//for(int j = 0;j < iNumIterations;++j) 
// { 
// iTotal++; 
// }
//} 
	return 0;
}

