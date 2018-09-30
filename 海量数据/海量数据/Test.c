#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <windows.h>

typedef struct TwoBitSet
{
	size_t* _bits;
	size_t _range;
}TwoBitSet;
void TWSInit(TwoBitSet* tbs, size_t range);
int GetStatae(TwoBitSet* tbs, size_t x);
int SetStatae(TwoBitSet* tbs, size_t x, size_t value);
void TWSDestory(TwoBitSet* tbs, int range);

///////////////////////////////////////////////////////////
//º¯Êý´úÂë

void TWSInit(TwoBitSet* tbs, size_t range)
{
	assert(tbs);
	tbs->_bits = (size_t *)malloc(sizeof(size_t)*((range >> 4) + 1));
	assert(tbs->_bits);
	memset(tbs->_bits, 0, sizeof(size_t)*((range >> 4) + 1));
	tbs->_range = range;	
}

int GetStatae(TwoBitSet* tbs, size_t x)
{
	assert(tbs);
	size_t index = x >> 4;
	size_t num = x % 16;
	num *= 2;

	int value = tbs->_bits[index];
	value >>= num;
	return value & 3;

}

int SetStatae(TwoBitSet* tbs, size_t x, size_t value)
{
	assert(tbs);
	size_t index = x >> 4;
	size_t num = x % 16;
	/*if (value > 3)
	{
		return -1;
	}
	tbs->_bits[index] &= ~(3 << num);
	tbs->_bits[index] |= (value<<num);*/

	if (0 == value)
	{
		tbs->_bits[index] &= ~(3 << num);
	}
	else if (1 == value)
	{
		tbs->_bits[index] |= (1 << num);
		tbs->_bits[index] &= ~(1 << (num + 1));
	}
	else if (2 == value)
	{
		tbs->_bits[index] &= ~(1 << num);
		tbs->_bits[index] |= (1 << (num + 1));
	}
	else if (3 == value)
	{
		tbs->_bits[index] |= (3 << num);
	}
	else
	{
		return -1;
	}
	return -1;
}
void TWSDestory(TwoBitSet* tbs, int range);

//////////////////////////////////////////////
//
void Test()
{
	TwoBitSet tbs;
	TWSInit(&tbs, 100);
}
int main()
{

	system("pause");
	return 0;
}