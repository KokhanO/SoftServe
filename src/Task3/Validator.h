#pragma once
#include <climits>
#include <string>
namespace Validator {
	bool TryParseToUShort(const std::string data, unsigned short& outNum)
	{
		try {
			size_t pos;
			unsigned long tmp = std::stoul(data, &pos);
			if (data.size() != pos)
			{
				throw false;
			}
			outNum = (unsigned short)(tmp <= USHRT_MAX ? tmp : throw false);
		}
		catch (...)
		{
			outNum = 0;
			return false;
		}

		return true;
	}

	bool TryParseToFloat(const std::string data, float& outNum)
	{
		try
		{
			size_t pos;
			outNum = stof(data, &pos);
			if (data.size() != pos)
			{
				throw false;
			}
		}
		catch (...)
		{
			outNum = 0;
			return false;
		}

		return true;
	}

	bool TryParseToLongLong(const std::string data, long long& outNum)
	{
		try
		{
			size_t pos;
			outNum = stoll(data, &pos);
			if (data.size() != pos)
			{
				throw false;
			}
		}
		catch (...)
		{
			outNum = 0;
		
			return false;
		}

		return true;
	}

	bool TryParseToDouble(const std::string data, double& outNum)
	{
		try
		{
			size_t pos;
			outNum = stod(data, &pos);
			if (data.size() != pos)
			{
				throw false;
			}
		}
		catch (...)
		{
			outNum = 0;
			return false;
		}

		return true;
	}
};
