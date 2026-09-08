#pragma once
#include<iostream>
#include"clsDate.h"
#include"clsUtil.h"
#include<string>

class clsInputValidate
{
public:

	static bool IsNumberBetween(short Num, short From, short To)
	{
		return (Num >= From && Num <= To) ? 1 : 0;
	}

	static bool IsNumberBetween(int Num, int From, int To)
	{
		return (Num >= From && Num <= To) ? 1 : 0;
	}

	static bool IsNumberBetween(float Num, float From, float To)
	{
		return (Num >= From && Num <= To) ? 1 : 0;
	}

	static bool IsNumberBetween(double Num, double From, double To)
	{
		return (Num >= From && Num <= To) ? 1 : 0;
	}

	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	{
		if (clsDate::IsDate1BeforeDate2(To, From)) { clsDate::SwapDates(From, To); }

		if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			&&
			(clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)))
		{
			return 1;
		}
		return 0;
	}

	static int ReadIntNumber(string Message = "Invalid Number, Enter again\n")
	{
		int Num;
		while (!(cin >> Num))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << Message;
		}
		return Num;
	}

	static double ReadDblNumber(string Message = "Invalid Number, Enter again\n")
	{
		double Num;
		while (!(cin >> Num))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << Message;
		}
		return Num;
	}

	static int ReadIntNumberBetween(int From, int To, string Message = "Number is not within range,enter again:\n")
	{
		int Num;
		Num = ReadIntNumber();
		if (Num<From || Num>To)
		{

			cout << Message;
			Num = ReadIntNumberBetween(From, To, Message);
		}
		return Num;
	}

	static double ReadDblNumberBetween(double From, double To, string Message = "Number is not within range,enter again")
	{
		double Num;
		Num = ReadDblNumber();
		if (Num<From || Num>To)
		{
			cout << Message;
			Num = ReadDblNumberBetween(From, To, Message);
		}
		return Num;
	}

	static bool IsValidDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}
};

