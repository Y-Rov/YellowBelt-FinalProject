#pragma once
#include "date.h"
#include <string>
#include <memory>
using namespace std;

enum class Comparison {
	Less,
	LessOrEqual,
	Greater,
	GreaterOrEqual,
	Equal,
	NotEqual
};

enum class LogicalOperation {
	Or,
	And
};

class Node {
public:
	Node();
	virtual bool Evaluate(const Date&, const string&) const = 0;
};

class EmptyNode : public Node {
public:
	EmptyNode();
	bool Evaluate(const Date&, const string&) const;
};

class DateComparisonNode : public Node {
public:
	DateComparisonNode(const Comparison&, const Date&);
	bool Evaluate(const Date&, const string&) const;
private:
	const Comparison compare;
	const Date date_compare;
};

class EventComparisonNode : public Node {
public:
	EventComparisonNode(const Comparison&, const string&);
	bool Evaluate(const Date&, const string&) const;
private:
	const Comparison compare;
	const string event_compare;
};

class LogicalOperationNode : public Node {
public:
	LogicalOperationNode(const LogicalOperation&, const shared_ptr<Node>&, const shared_ptr<Node>&);
	bool Evaluate(const Date&, const string&) const;
private:
	const LogicalOperation log_oper;
	const shared_ptr<Node> lhs;
	const shared_ptr<Node> rhs;
};