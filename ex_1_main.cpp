// ex_1_main.cpp
#include <iostream>
#define CPP2_PRIME_UPPER_LIMIT 1000000 //探索する値の上限値。


int nth_prime(unsigned int a, unsigned int d, unsigned int n);


int main() {
	std::cout << nth_prime(367, 186, 151) << std::endl;
	// 以下、同様に、入出力例通りになるか確認せよ。
	return 0;
}
