// ex_2_main.cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

namespace cpp2 {
	/* --------------------------------------------------------------------- */
	/*
	mcxi

	mcxi 記法を解析するクラスです。
	*/
	/* --------------------------------------------------------------------- */
	class mcxi {
	public:
		//mcxiのコンストラクタを定義
		mcxi(const std::string& s) : value_(0) {//コンストラクタ
			int digit = 0;
			for (auto pos = s.begin(); pos != s.end(); ++pos) {
				if (*pos >= '2' && *pos <= '9') {
					digit = *pos - '0';
				}
				else {
					auto u = unit(*pos);
					value_ += std::max(digit, 1) * u;
					digit = 0;
				}
			}
		};
		// 2 つのオブジェクトの加算結果を取得
		mcxi operator + (const mcxi& rhs) {
			mcxi dest(*this);
			dest.value_ += rhs.value_;
			return dest;
		}

		std::string to_string() const {

			std::stringstream ss;
			int num = 0;
			num = value_;
			//1000の位の変換
			if (num >= 1000) {
				int m = num / 1000;
				if (m == 1) {
					ss << 'm';
				}
				if (m > 1) {
					ss << m;
					ss << 'm';
				}
				num = num - m * 1000;
			}
			//100の位の変換
			if (num >= 100) {
				int c = num / 100;
				if (c == 1) {
					ss << 'c';
				}
				if (c > 1) {
					ss << c;
					ss << 'c';
				}
				num = num - c * 100;
			}
			//10の位の変換
			if (num >= 10) {
				int x = num / 10;
				if (x == 1) {
					ss << 'x';
				}
				if (x > 1) {
					ss << x;
					ss << 'x';
				}
				num = num - x * 10;
			}
			//1の位の変換
			if (num == 1) {
				ss << 'i';
			}
			if (num > 1) {
				ss << num;
				ss << 'i';
			}
			return ss.str();
		}

	private:
		// 単位に対応する値を取得
		int unit(char c) {
			switch (c) {
			case 'm': return 1000;
			case 'c': return 100;
			case 'x': return 10;
			case 'i': return 1;
			}
		};
		int value_{
		};
	};
} // namespace cpp2
	int main() {
		cpp2::mcxi a0("xi");
		cpp2::mcxi b0("x9i");
		auto result0 = a0 + b0;
		std::cout << "3x" << " " << result0.to_string() << std::endl;

		cpp2::mcxi a1("i");
		cpp2::mcxi b1("9i");
		auto result1 = a1 + b1;
		std::cout << "x" << " " << result1.to_string() << std::endl;

		cpp2::mcxi a2("c2x2i");
		cpp2::mcxi b2("4c8x8i");
		auto result2 = a2 + b2;
		std::cout << "6cx" << " " << result2.to_string() << std::endl;

		cpp2::mcxi a3("m2ci");
		cpp2::mcxi b3("4m7c9x8i");
		auto result3 = a3 + b3;
		std::cout << "5m9c9x9i" << " " << result3.to_string() << std::endl;

		cpp2::mcxi a4("9c9x9i");
		cpp2::mcxi b4("i");
		auto result4 = a4 + b4;
		std::cout << "m" << " " << result4.to_string() << std::endl;

		cpp2::mcxi a5("i");
		cpp2::mcxi b5("9m9c9x8i");
		auto result5 = a5 + b5;
		std::cout << "9m9c9x9i" << " " << result5.to_string() << std::endl;

		cpp2::mcxi a6("m");
		cpp2::mcxi b6("i");
		auto result6 = a6 + b6;
		std::cout << "mi" << " " << result6.to_string() << std::endl;

		cpp2::mcxi a7("i");
		cpp2::mcxi b7("m");
		auto result7 = a7 + b7;
		std::cout << "mi" << " " << result7.to_string() << std::endl;

		cpp2::mcxi a8("m9i");
		cpp2::mcxi b8("i");
		auto result8 = a8 + b8;
		std::cout << "mx" << " " << result8.to_string() << std::endl;

		cpp2::mcxi a9("9m8c7xi");
		cpp2::mcxi b9("c2x8i");
		auto result9 = a9 + b9;
		std::cout << "9m9c9x9i" << " " << result9.to_string() << std::endl;

		std::cin.get();
	}