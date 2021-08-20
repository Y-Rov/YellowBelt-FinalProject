#pragma once
#include <iostream>

using namespace std;

class Date {
public:
    Date(const uint16_t&, const uint16_t&, const uint16_t&);
    uint16_t GetYear() const;
    uint16_t GetMonth() const;
    uint16_t GetDay() const;

private:
    const uint16_t Year = 0;
    const uint16_t Month = 0;
    const uint16_t Day = 0;
};

bool operator<(const Date&, const Date&);
bool operator<=(const Date&, const Date&);
bool operator>(const Date&, const Date&);
bool operator>=(const Date&, const Date&);
bool operator==(const Date&, const Date&);
bool operator!=(const Date&, const Date&);
ostream& operator<<(ostream& os, const Date& date);
Date ParseDate(istream& is);

