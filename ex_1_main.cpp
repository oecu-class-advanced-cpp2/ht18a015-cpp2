// ex_1_main.cpp
#include <iostream>
#define CPP2_PRIME_UPPER_LIMIT 1000000 //�T������l�̏���l�B


int nth_prime(unsigned int a, unsigned int d, unsigned int n);


int main() {
	std::cout << nth_prime(367, 186, 151) << std::endl;
	// �ȉ��A���l�ɁA���o�͗�ʂ�ɂȂ邩�m�F����B
	return 0;
}
