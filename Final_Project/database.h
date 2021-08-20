#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <stdexcept>
#include <functional>
#include "date.h"

using namespace std;

class Database
{
public:
	Database();
	void Add(const Date&, const string&);
	void Print(ostream&) const;
	int RemoveIf(const function<bool(const Date& date, const string& Event)> f);
	vector<string> FindIf(const function<bool(const Date& date, const string& Event)> f) const;
	string Last(const Date&) const;

private:
	map<Date, set<string>> database1;
	map<Date, vector<string>> database2;
};
