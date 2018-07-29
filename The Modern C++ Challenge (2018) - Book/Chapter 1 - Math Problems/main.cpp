#include <vector>
#include <algorithm>
#include <numeric> 
#include <iostream>
#include <utility>

class utils
{
public:
	static bool is_prime(int num)
	{
		bool is_prime = true;
		for (int i = 2; i < num; ++i)
			if (num % i == 0)
			{
				is_prime = false;
				break;
			}
		return is_prime;
	}
};

//Chapter-1 -> problem 1  (sum of divisble numbers on 3 or 5) 
void problem1(void)
{
	unsigned int limit;
	std::vector<int> vec;

	std::cout << "Enter the limit, please.\nNote: The limit is included\n";
	std::cin >> limit;

	for (int i = 3; i <= limit; ++i)
		if (i % 3 == 0 || i % 5 == 0)
			vec.push_back(i);

	std::cout << "sum: " << std::accumulate(vec.begin(), vec.end(), 0) << '\n';
}

//chapter-1 -> problem 2 (greatest common multiple)
void problem2()
{
	unsigned int num1{ 0 }, num2{ 0 };
	std::cout << "GCD calculation:\n";
	std::cout << "Enter first number \n";
	std::cin >> num1;
	std::cout << "Enter second numer \n";
	std::cin >> num2;

	//for C++17 
#if (_MSC_VER >= 1910)
	std::cout << std::gcd(num1, num2) << '\n';
#endif

	//for C++15 or earlier 
	while (num2 != 0)
	{
		unsigned int t = num1 % num2;
		num1 = num2;
		num2 = t;
	}
	std::cout << "GCD: " << num1 << '\n';
}

//chapter-1 -> problem 3 (least common multiple)
void problem3()
{
	unsigned int num1{ 0 }, num2{ 0 };
	std::cout << "LCM calculation:\n";
	std::cout << "Enter first number\n";
	std::cin >> num1;
	std::cout << "Enter second number\n";
	std::cin >> num2;

	//for C++17 
#if (_MSC_VER >= 1910) 
	std::cout << std::lcm(num1, num2) << '\n';
#endif 

	//for C++15 or earlier 
	int max = (num1 > num2) ? num1 : num2;
	do
	{
		if (max % num1 == 0 && max % num2 == 0)
		{
			std::cout << "LCM = \n" << max;
			break;
		}
		else
			++max;
	} while (true);
}

//chapter-1 -> problem4 (largest prime smaller than given number)
void problem4()
{
	unsigned int limit, prime;
	std::cout << "Enter the number\n";
	std::cin >> limit;

	for (int i = 2; i < limit; ++i)
	{
		for (int j = 0; j <= i; ++j)
			if (j % i == 0)
				prime = i;
	}
	std::cout << "largest prime number before the given limit " << limit << " is :" << prime << '\n';
}

//chapter-1 -> problem5 (sexy prime numbers)
void problem5()
{
	unsigned int limit, prime;
	std::vector<int> prime_nums, sexy_primes;
	std::cout << "Enter the limit number\n";
	std::cin >> limit;

	for (int i = 2; i <= limit; ++i)
		if (utils::is_prime(i))
			prime_nums.push_back(i);

	for (int i = 2; i < prime_nums.size(); ++i)
	{
		for (int j = 2; j < i; ++j)
		{
			if ((prime_nums.at(i) - prime_nums.at(j)) == 6)
			{
				sexy_primes.push_back(prime_nums.at(j));
				sexy_primes.push_back(prime_nums.at(i));
			}
		}

	}

	std::sort(sexy_primes.begin(), sexy_primes.end());
	sexy_primes.erase(std::unique(sexy_primes.begin(), sexy_primes.end()), sexy_primes.end());


	std::vector<std::pair<int, int> > sexy_pairs;
	for (const auto& sexy_num : sexy_primes)
		for (int i = 2; i < sexy_num; ++i)
			if (sexy_num - i == 6 && std::find(sexy_primes.begin(), sexy_primes.end(), i) != sexy_primes.end())
				sexy_pairs.push_back(std::make_pair(i, sexy_num));

	std::cout << "===================================\n" <<
		"sexy primes for given limit of " << limit << " is:\n";
	for (const auto& pair : sexy_pairs)
		std::cout << '(' << pair.first << ", " << pair.second << ')' << '\n';
}

void problem6()
{
	unsigned int limit;
	std::cout << "Enter the limit \n";
	std::cin >> limit;

	std::vector<unsigned int> divisors;
	std::vector<std::pair<int, int> > nums;
	for (int i = 1; i < limit; ++i)
	{
		for (int j = 1; j < i; ++j)
		{
			if (i % j == 0)
				divisors.push_back(j);
		}
		int divisors_sum = std::accumulate(divisors.begin(), divisors.end(), 0);
		if (divisors_sum > i)
		{
			nums.push_back(std::make_pair(i, divisors_sum - i));
		}
	}

	std::cout << "pairs of abundant numbers and its abundance\n";
	for (const auto& pair : nums)
		std::cout << '(' << pair.first << ", " << pair.second << ")\n";
}

int main()
{
	//problem1();
	//problem2();
	//problem3();
	//problem4();
	//problem5();
	problem6();
	return EXIT_SUCCESS;
}