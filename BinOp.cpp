// BinOp.cpp: определяет точку входа для консольного приложения.

#include "stdafx.h"
#include "BinOperations.h"



int _tmain(int argc, _TCHAR* argv[])
{
	ULI number=0;
	cout<<"Input number------------>";
	cin>>number;
	cout<<"Number-->"; OutBinary(number);
	cout<<"MostSignBit-->"; OutBinary(MostSignBit(number));
	cout<<"LastZeroBit-->";	OutBinary(LastZeroBit(number));
	cout<<"ExchangeBytes-->";	OutBinary(ExchangeBytes(number));
	cout<<"ClearLastOneBit-->";	OutBinary(ClearLastOneBit(number));
	cout<<"SetFirstZeroBit-->";	OutBinary(SetFirstZeroBit(number));
	
	system("pause");
	return 0;
}

