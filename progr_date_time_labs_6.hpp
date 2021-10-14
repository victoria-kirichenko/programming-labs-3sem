#ifndef PROGR_DATE_TIME_LABS_6_HPP_INCLUDED
#define PROGR_DATE_TIME_LABS_6_HPP_INCLUDED
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cstring>
using namespace std;

class MyException {
	public:
		MyException(const char *msg) : message(msg) {};
		const char *GetError() {
			return message;
		}
	private:
		const char *message;
};

class DateTime {

public:
	DateTime();

	DateTime(int day_1, int month_1, int year_1, int hours_1, int minutes_1, int seconds_1);

	DateTime(const DateTime& date) : // конструктор копирования
		day(date.day), month(date.month), year(date.year), hours(date.hours), minutes(date.minutes), seconds(date.seconds) {
		date_time = new char[20];
		strcpy(date_time, date.date_time);
	}

	DateTime operator= (const DateTime date);
	DateTime operator+ (const DateTime &date);
	DateTime operator- (const DateTime &date);
	operator char*();
	friend DateTime operator+ (const DateTime date, int year);
	friend DateTime operator- (const DateTime date, int year);


	void CheckingDay(int day);
	void CheckingMonth(int month);
	void CheckingYear(int year);
	void CheckingHours(int hours);
	void CheckingMinutes(int minutes);
	void CheckingSeconds(int seconds);

	bool CheckingDate();
	int GetDay();
	void SetDay(int valueDay);
	int GetMonth();
	void SetMonth(int valueMonth);
	int GetYear();
	void SetYear(int valueYear);
	int GetHours();
	void SetHours(int valueHours);
	int GetMinutes();
	void SetMinutes(int valueMinutes);
	int GetSeconds();
	void SetSeconds(int valueSeconds);
	char* GetDateTime();
	char* ToString();
	void PlusHours();
	void MinusHours();
	void PlusMinutes();
	void MinusMinutes();
	void PlusSeconds();
	void MinusSeconds();
	void PlusDay();
	void MinusDay();
	void PlusMonth();
	void MinusMonth();
	void PlusYear();
	void MinusYear();
	void CreateString();
	~DateTime();

private:
	int day, month, year, hours, minutes, seconds;
	char* date_time = new char[20];
};

#endif // PROGR_DATE_TIME_LABS_6_HPP_INCLUDED