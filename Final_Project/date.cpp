#include "date.h"
#include <iomanip>
#include <tuple>

using namespace std;

Date::Date(const uint16_t& year, const uint16_t& month, const uint16_t& day)
	: Year(year), Month(month), Day(day) {}

uint16_t Date::GetYear() const { return Year; }
uint16_t Date::GetMonth() const { return Month; }
uint16_t Date::GetDay() const { return Day; }

bool operator<(const Date& lhs, const Date& rhs) {
	return tuple<uint16_t, uint16_t, uint16_t> {lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <
		tuple<uint16_t, uint16_t, uint16_t> {rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator<=(const Date& lhs, const Date& rhs) {
	return tuple<uint16_t, uint16_t, uint16_t> {lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <=
		tuple<uint16_t, uint16_t, uint16_t> {rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator>(const Date& lhs, const Date& rhs) {
	return tuple<uint16_t, uint16_t, uint16_t> {lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} >
		tuple<uint16_t, uint16_t, uint16_t> {rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator>=(const Date& lhs, const Date& rhs) {
	return tuple<uint16_t, uint16_t, uint16_t> {lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} >=
		tuple<uint16_t, uint16_t, uint16_t> {rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator==(const Date& lhs, const Date& rhs) {
	return tuple<uint16_t, uint16_t, uint16_t> {lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} ==
		tuple<uint16_t, uint16_t, uint16_t> {rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator!=(const Date& lhs, const Date& rhs) {
	return tuple<uint16_t, uint16_t, uint16_t> {lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} !=
		tuple<uint16_t, uint16_t, uint16_t> {rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

Date ParseDate(istream& is) {
	uint16_t year = 0;
	is >> year;
	is.ignore(1);
	uint16_t month = 0;
	is >> month;
	is.ignore(1);
	uint16_t day = 0;
	is >> day;
	return Date(year, month, day);
}

ostream& operator<<(ostream& os, const Date& date) {
	os << setw(4) << setfill('0') << date.GetYear() <<
		"-" << setw(2) << setfill('0') << date.GetMonth() <<
		"-" << setw(2) << setfill('0') << date.GetDay();
	return os;
}