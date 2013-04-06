
#include "UnluckyNumbers.cc"

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <sys/time.h>
#include <vector>

using namespace std;


const static double __EPSILON = 1e-9;
static double __time = 0.0;

static void __timer_start()
{
	struct timeval tv;
	if (gettimeofday(&tv, NULL) == 0)
	{
		__time = double(tv.tv_sec) + double(tv.tv_usec) * 0.000001;
	}
}

static double __timer_stop()
{
	double start = __time;
	__timer_start();
	return __time - start;
}


static void __eat_whitespace(std::istream& in)
{
	while (in.good() && std::isspace(in.peek())) in.get();
}


std::ostream& operator << (std::ostream& out, const std::string& str)
{
	out << '"' << str.c_str() << '"';
	return out;
}

template <class T>
std::ostream& operator << (std::ostream& out, const std::vector<T>& vec)
{
	out << '{';
	if (0 < vec.size())
	{
		out << vec[0];
		for (size_t i = 1; i < vec.size(); ++i) out << ", " << vec[i];
	}
	out << '}';
	return out;
}

std::istream& operator >> (std::istream& in, std::string& str)
{
	__eat_whitespace(in);

	int c;
	if (in.good() && (c = in.get()) == '"')
	{
		std::ostringstream s;
		while (in.good() && (c = in.get()) != '"')
		{
			s.put(char(c));
		}
		str = s.str();
	}

	return in;
}

template <class T>
std::istream& operator >> (std::istream& in, std::vector<T>& vec)
{
	__eat_whitespace(in);

	int c;
	if (in.good() && (c = in.get()) == '{')
	{
		__eat_whitespace(in);
		vec.clear();
		while (in.good() && (c = in.get()) != '}')
		{
			if (c != ',') in.putback(c);

			T t;
			in >> t;
			__eat_whitespace(in);

			vec.push_back(t);
		}
	}

	return in;
}


template <class T>
bool __equals(const T& actual, const T& expected)
{
	return actual == expected;
}

bool __equals(double actual, double expected)
{
	if (std::abs(actual - expected) < __EPSILON)
	{
		return true;
	}
	else
	{
		double minimum = std::min(expected * (1.0 - __EPSILON), expected * (1.0 + __EPSILON));
		double maximum = std::max(expected * (1.0 - __EPSILON), expected * (1.0 + __EPSILON));
		return actual > minimum && actual < maximum;
	}
}

bool __equals(const std::vector<double>& actual, const std::vector<double>& expected)
{
	if (actual.size() != expected.size())
		return false;

	for (size_t i = 0; i < actual.size(); ++i)
		if (!__equals(actual[i], expected[i]))
			return false;

	return true;
}


int main(int argc, char* argv[])
{
	bool	__abort_on_fail = false;
	int	__pass = 0;
	int	__fail = 0;

	if (1 < argc) __abort_on_fail = true;

	std::ifstream __in("testcases.txt");
	for(;;)
	{
		int	__expected;
		vector <int>	luckySet;
int	n;

		__in >> __expected >> luckySet >> n;
		if (!__in.good()) break;

		std::cout << "----------------------------------------" << std::endl
			  << "Test " << (__pass + __fail) << ": ";
		std::cout.flush();

		__timer_start();

		UnluckyNumbers object;
		int __actual = object.getCount(luckySet, n);

		double __t = __timer_stop();

		if (__equals(__actual, __expected))
		{
			std::cout << "[PASS] in " << __t << " seconds." << std::endl;
			++__pass;
		}
		else
		{
			std::cout << "[FAIL] in " << __t << " seconds." << std::endl
				  << "->  Input: " << luckySet << ", " << n << std::endl
				  << "   Actual: " << __actual << std::endl
				  << " Expected: " << __expected << std::endl;
			++__fail;
			if (__abort_on_fail) std::abort();
		}
	}

	std::cout << "========================================" << std::endl
		  << " Total Pass: " << __pass << std::endl
		  << " Total Fail: " << __fail << std::endl;

	if (__fail == 0)
	{
		std::cout << std::endl << "Nice!  "
			  << "Don't forget to compile remotely before submitting."
			  << std::endl;
	}

	return __fail;
}

