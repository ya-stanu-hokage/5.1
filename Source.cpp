#define _CRT_SECURE_NO_WARNINGS
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS

#include <iostream>
#include <bitset>
#include <chrono>
#include <codecvt>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <fstream>
#include <iostream>
#include <iterator>
#include <locale>
#include <stdexcept>
#include <string>
#include <iomanip>

#include <boost/locale.hpp>

#include <Windows.h>

long double EU_to_RU(long double& a)
{
	return a * 80;
}

int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	long double money_eu;
	long double money_ru;

	std::cin.imbue(std::locale("en_US.UTF-8"));
	std::cout << "Enter the amount of money in the format xxx,xxx,xxx.xx (EU)" << std::endl;
	std::cin >> std::get_money(money_eu);

	money_ru = EU_to_RU(money_eu);

	std::cout.imbue(std::locale("en_US.UTF-8"));
	std::cout << std::showbase << std::put_money(money_eu, true) << std::endl;

	std::cout.imbue(std::locale("ru_RU.utf8"));
	std::cout << std::showbase << std::put_money(money_ru, true) << std::endl;

	return 0;
}