#include "database.h"
#include <algorithm>
#include <sstream>
#include <iterator>

using namespace std;

Database::Database() {}

void Database::Add(const Date& date, const string& Event) {
	if (database1[date].insert(Event).second)
		database2[date].push_back(Event);
}

void Database::Print(ostream& os) const {
	for (const auto& item : database2) {
		for (const auto& Event : item.second)
			os << item.first << " " << Event << endl;
	}
}

int Database::RemoveIf(const function <bool(const Date& date, const string& Event)> pred) {
	int counter = 0;
	vector<Date> empty_dates;
	for (auto& item : database2) {
		auto it = stable_partition(item.second.begin(), item.second.end(), [pred, item](const string& Event) { return !pred(item.first, Event); });
		if (item.second.end() - it > 0) {
			counter += item.second.end() - it;
			item.second.erase(it, item.second.end());
			if (item.second.empty()) {
				database1.erase(item.first);
				empty_dates.push_back(item.first);
			}
			else
			{
				database1.erase(item.first);
				copy(item.second.begin(), item.second.end(), inserter(database1[item.first], database1[item.first].end()));
			}		
		}
	}
	for (const auto& date : empty_dates) {
		database2.erase(date);
	}
	return counter;
}

vector<string> Database::FindIf(const function <bool(const Date& date, const string& Event)> pred) const {
	vector<string> result;
	for (const auto& item : database2) {
		for (auto it = find_if(item.second.begin(), item.second.end(), [pred, item](const string& Event) { return pred(item.first, Event); });
			it != item.second.end(); it = find_if(next(it), item.second.end(), [pred, item](const string& Event) { return pred(item.first, Event); })) {
			ostringstream os;
			os << item.first << " " << it->c_str();
			result.push_back(os.str());
		}
	}
	return result;
}

string Database::Last(const Date& date) const {
	if (database2.empty())
		throw invalid_argument("");
	else
	{
		if (date < database2.begin()->first)
			throw invalid_argument("");
		else {
			auto it = --(database2.upper_bound(date));
			ostringstream os;
			os << it->first << " " << it->second.back();
			return os.str();
		}
	}
}
