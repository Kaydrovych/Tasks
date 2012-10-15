/*
* @file BinOperations.h
* @brief ̳����� ��������� ������� ��� ������� �� ��� "����� ��������"
* @autor ��������� ���
*/

typedef unsigned long int ULI;
typedef signed long int SLI;

/** 
*@brief �� ������� �������� �������� ���
		������������ ������� ������ �����
*@param number -  �����e ���������e ����e ���e �����
*@return void
*/
void OutBinary(const ULI& number)
{
	char *buf=new char[33];

	cout<<ultoa(number,buf,2)<<endl;

	delete [] buf;
}


/** Task 1.22
*@brief �� �������  ������� ���������� ����� ���� �����, 
		� ����� ������������ � 1 ���� ���� �� - � ������� ����������� ������������� 
		� 1 ��� �������� ������������ ������� ������ �����
*@param number -  �����e ���������e ����e ���e �����
*@return unsigned long int
*/
ULI MostSignBit(const ULI &number)
{
	ULI result=number;

	result=result|(result>>1);
	result=result|(result>>2);
	result=result|(result>>4);
	result=result|(result>>8);
	result=result|(result>>16);

	return (result>>1)^(result);
}


/** Task 1.23
*@brief �� �������  ������� ���������� ����� ���� �����, � ����� ������������ 
		� 1 ���� ���� �� - � ������� ������������ ��������� (������������� � 0)
		��� �������� ������������ ������� ������ ����� 
*@param [in] number -  �����e ���������e ����e ���e �����
*@return unsigned long int
*/
ULI LastZeroBit(const ULI &number)
{
	ULI result=~number;

	result=result|(result<<1);
	result=result|(result<<2);
	result=result|(result<<4);
	result=result|(result<<8);
	result=result|(result<<16);

	return (result<<1)^(result);
}

/** Task 1.24
*@brief �� �������  ���� ������ ����� ����� � 8-� ���
		� �������� ������������ ������� ������ ����
*@param [in] number -  �����e ���������e ����e ���e �����
*@return unsigned long int
*/
ULI ExchangeBytes(const ULI &number)
{
	ULI result=((number&0x000000FF)<<8)|((number&0x0000FF00)>>8)|
			   ((number&0x00FF0000)<<8)|((number&0xFF000000)>>8);
	return result;
}


/** Task 1.25
*@brief �� ������� ����� (���������� � 0) ����������� 
		������������ � 1 �� � �������� ������������ ������� ������ ����
*@param [in] number -  �����e ���������e ����e ���e �����
*@return unsigned long int
*/
ULI ClearLastOneBit(const ULI &number)
{
	ULI bitMask=LastZeroBit(~number);
	return number^bitMask;
}

/** Task 1.26
*@brief �� �������  ���������� � 1 ���������� �������� (������������ � 0) ��
		� �������� ������������ ������� ������ ����
*@param [in] number -  �����e ���������e ����e ���e �����
*@return unsigned long int
*/
ULI SetFirstZeroBit(const ULI &number)
{
	ULI bitMask= MostSignBit(~number);
	return number^bitMask;
}


