#pragma once
#include <string>
#include <iostream>

class Error
{
public:
	virtual void what() {};
protected:
	std::string msg;
};

class IndexError :public Error
{
protected:
	std::string msg_;
public:
	IndexError() { msg = "Index Error\n"; }
	virtual void what() { std::cout << msg; }
};
class SizeError :public Error 
{
protected:
	std::string msg_;
public:
	SizeError() { msg = "Size error\n"; }
	virtual void what() { std::cout << msg; }
};

class EmptySizeError :public SizeError 
{
public:
	EmptySizeError() { SizeError(); msg_ = "List is empty\n"; }
	virtual void what() { std::cout << msg << msg_; }
};
class IndexError1 :public IndexError 
{
public:
	IndexError1() { IndexError(); msg_ = "Index < 0\n"; }
	virtual void what() { std::cout << msg << msg_; }
};
class IndexError2 :public IndexError 
{
public:
	IndexError2() { IndexError(); msg_ = "Index > size\n"; }
	virtual void what() { std::cout << msg << msg_; }
};