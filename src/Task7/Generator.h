#pragma once

class Generator
{
public:
	Generator(long long current_num);
	long long operator ++();
	bool operator <(const long long& boudary);
	long long getCurrentNum() const;
private:

	long long current_num_;
};