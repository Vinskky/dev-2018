#ifndef  _MYSTRING_H_
#define	 _MYSTRING_H_
#include <string>
#include <iostream>

class MyString
{
private:
	char* str;
	unsigned int size;

public:

	MyString()
	{
		Alloc(1);
		str[0] = '\0';
	}

	MyString(const char* string)
	{
		if (string != nullptr)
		{
			int string_size;
			for (int i = 0; string[i] != '\0'; i++)
			{
				string_size++;
			}
			Alloc(string_size);
			strcpy_s(str, string_size, string);
		}else
		{
			std::cout << "Constructor char* has a nullptr as atribute" << std::endl;
		}
	}

	MyString(const MyString& string)
	{
		Alloc(string.size);
		strcpy_s(str, size, string.str);
	}

	~MyString()
	{
		if (str != NULL)
			delete[] str;
	}

	//operators
	MyString operator = (const char* string)const
	{

	}

private:
	void Alloc(unsigned int needed_memory)
	{
		size = needed_memory;
		str = new char[size];
	}
};


#endif // ! _MYSTRING_H_

