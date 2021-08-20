#include "node.h"

using namespace std;

Node::Node() {}

EmptyNode::EmptyNode() {}

DateComparisonNode::DateComparisonNode(const Comparison& cmp, const Date& date) 
	: compare(cmp), date_compare(date) {}

EventComparisonNode::EventComparisonNode(const Comparison& cmp, const string& Event) 
	: compare(cmp), event_compare(Event) {}

LogicalOperationNode::LogicalOperationNode(const LogicalOperation& log_op, const shared_ptr<Node>& first, const shared_ptr<Node>& second) 
	: log_oper(log_op), lhs(first), rhs(second) {}

bool EmptyNode::Evaluate(const Date& date, const string& Event) const {
	return true;
}

bool DateComparisonNode::Evaluate(const Date& date, const string& Event) const {
	if (compare == Comparison::Less) {
		if (date < date_compare)
			return true;
	}
	else if (compare == Comparison::LessOrEqual) {
		if (date <= date_compare)
			return true;
	}
	else if (compare == Comparison::Greater) {
		if (date > date_compare)
			return true;
	}
	else if (compare == Comparison::GreaterOrEqual) {
		if (date >= date_compare)
			return true;
	}
	else if (compare == Comparison::Equal) {
		if (date == date_compare)
			return true;
	}
	else if (compare == Comparison::NotEqual) {
		if (date != date_compare)
			return true;
	}
	return false;
}

bool EventComparisonNode::Evaluate(const Date& date, const string& Event) const {
	if (compare == Comparison::Equal) {
		if (Event == event_compare)
			return true;
	}
	else if (compare == Comparison::NotEqual) {
		if (Event != event_compare)
			return true;
	}
	else if (compare == Comparison::Greater) {
		if (Event > event_compare)
			return true;
	}
	else if (compare == Comparison::GreaterOrEqual) {
		if (Event >= event_compare)
			return true;
	}
	else if (compare == Comparison::Less) {
		if (Event < event_compare)
			return true;
	}
	else if (compare == Comparison::LessOrEqual) {
		if (Event <= event_compare)
			return true;
	}
	return false;
}

bool LogicalOperationNode::Evaluate(const Date& date, const string& Event) const {
	if (log_oper == LogicalOperation::And) {
		if (lhs->Evaluate(date, Event) && rhs->Evaluate(date, Event))
			return true;
	}
	else if (log_oper == LogicalOperation::Or) {
		if (lhs->Evaluate(date, Event) || rhs->Evaluate(date, Event))
			return true;
	}
	return false;
}