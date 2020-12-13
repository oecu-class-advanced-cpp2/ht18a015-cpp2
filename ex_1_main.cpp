#include <iostream>
#define CPP2_PRIME_UPPER_LIMIT 1000000 //�T������l�̏���l�B
using namespace std;

bool is_prime(int n) {
	if (n == 1) {
		return false;
	}
	for (int i = 2; i <= n - 1; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}


int nth_prime(unsigned int a, unsigned int d, unsigned int n) {
	int x = a;
	unsigned int cnt = 0;
	if (a % 2 == 0 && d % 2 == 0)return 0;
	while (cnt < n) {
		if (is_prime(x) == 1) {
			cnt++;
		}
		x += d;
	}
	return x - d;
};

int main() {
	std::cout << "����92809�F�o�͒l" << nth_prime(367, 186, 151) << std::endl;
	std::cout << "����6709�F�o�͒l" << nth_prime(179, 10, 203) << std::endl;
	std::cout << "����12037�F�o�͒l" << nth_prime(271, 37, 39) << std::endl;
	std::cout << "����103�F�o�͒l" << nth_prime(103, 230, 1) << std::endl;
	std::cout << "����93523�F�o�͒l" << nth_prime(27, 104, 185) << std::endl;
	std::cout << "����14503�F�o�͒l" << nth_prime(253, 50, 85) << std::endl;
	std::cout << "����2�F�o�͒l" << nth_prime(1, 1, 1) << std::endl;
	std::cout << "����899429�F�o�͒l" << nth_prime(9075, 337, 210) << std::endl;
	std::cout << "����5107�F�o�͒l" << nth_prime(307, 24, 79) << std::endl;
	std::cout << "����412717�F�o�͒l" << nth_prime(331, 221, 177) << std::endl;
	std::cout << "����22699�F�o�͒l" << nth_prime(259, 170, 40) << std::endl;
	std::cout << "����25673�F�o�͒l" << nth_prime(269, 58, 102) << std::endl;
	std::cin.get();
	return 0;
}
