/*
* @file BinOperations.h
* @brief Містить реалізації функцій для завдань по темі "Бітові операції"
* @autor Кайдрович Юрій
*/

typedef unsigned long int ULI;
typedef signed long int SLI;

/** 
*@brief Ця функція виводить двійковий код
		беззнакового довгого цілого числа
*@param number -  заданe беззнаковe довгe цілe число
*@return void
*/
void OutBinary(const ULI& number)
{
	char *buf=new char[33];

	cout<<ultoa(number,buf,2)<<endl;

	delete [] buf;
}


/** Task 1.22
*@brief Ця функцію  повертає беззнакове довге ціле число, 
		у якому встановлений в 1 лише один біт - у позиції найстаршого встановленого 
		в 1 біта заданого беззнакового довгого цілого числа
*@param number -  заданe беззнаковe довгe цілe число
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
*@brief Ця функція  повертає беззнакове довге ціле число, у якому встановлений 
		в 1 лише один біт - у позиції наймолодшого очищеного (встановленого в 0)
		біта заданого беззнакового довгого цілого числа 
*@param [in] number -  заданe беззнаковe довгe цілe число
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
*@brief Ця функція  міняє місцями сусідні групи з 8-и бітів
		у заданому беззнаковому довгому цілому числі
*@param [in] number -  заданe беззнаковe довгe цілe число
*@return unsigned long int
*/
ULI ExchangeBytes(const ULI &number)
{
	ULI result=((number&0x000000FF)<<8)|((number&0x0000FF00)>>8)|
			   ((number&0x00FF0000)<<8)|((number&0xFF000000)>>8);
	return result;
}


/** Task 1.25
*@brief Ця функція очищує (встановлює в 0) наймолодший 
		установлений в 1 біт у заданому беззнаковому довгому цілому числі
*@param [in] number -  заданe беззнаковe довгe цілe число
*@return unsigned long int
*/
ULI ClearLastOneBit(const ULI &number)
{
	ULI bitMask=LastZeroBit(~number);
	return number^bitMask;
}

/** Task 1.26
*@brief Ця функція  встановлює в 1 найстарший очищений (установлений в 0) біт
		у заданому беззнаковому довгому цілому числі
*@param [in] number -  заданe беззнаковe довгe цілe число
*@return unsigned long int
*/
ULI SetFirstZeroBit(const ULI &number)
{
	ULI bitMask= MostSignBit(~number);
	return number^bitMask;
}


