// ex_2_main.cpp
#include <iostream>
#include <string>
namespace cpp2 {
	/* --------------------------------------------------------------------- */
	/*
	mcxi
	mcxi 記法を解析するクラスです。
	*/
	/* --------------------------------------------------------------------- */
	class mcxi {
	private:
		//mcxiの数値を格納する変数
		int value_;

	public:
		//mcxiのコンストラクタを定義
		mcxi(const std::string& s);//コンストラクタ

		int hanntei(char c);

		//メソッド同士の足し算を定義
		//friend mcxi operator+(mcxi a, mcxi b);//例：a0＋b0の計算

		//mcxiの計算結果をstringに直すモノを定義
		//std::string to_string() const;
	};

	mcxi::mcxi(const std::string& s) : value_(0)
	{
		//○○ = s;

		//int digit = *pos - '0';で実行可能

		for (auto pos = s.begin(); pos != s.end(); pos++) {
			std::cout << *pos << "  ";
			std::cout << "(" << *pos - '0' << ")" << ",   ";
		}
		std::cout << std::endl;

		for (auto pos = s.begin(); pos != s.end(); pos++) {
			std::cout << *pos << "  ";
			std::cout << "(" << hanntei(*pos) << ")" << ",  ";
		}
		std::cout << std::endl << std::endl;

		//value_ = ○○;
	}


	int unit(char c) {
		switch (c) {
		case 'm': return 1000;
		case 'c': return 100;
		case 'x': return 10;
		case 'i': return 1;
		}
	};
} // namespace cpp2
int main() {
	cpp2::mcxi a0("xi");
	cpp2::mcxi b0("x9i");
	cpp2::mcxi result0 = a0 + b0;
	std::cout << "3x" << " " << result0.to_string() << std::endl;
	cpp2::mcxi a1("i");
	cpp2::mcxi b1("9i");
	cpp2::mcxi result1 = a1 + b1;
	std::cout << "x" << " " << result1.to_string() << std::endl;
	cpp2::mcxi a2("c2x2i");
	cpp2::mcxi b2("4c8x8i");
	cpp2::mcxi result2 = a2 + b2;
	std::cout << "6cx" << " " << result2.to_string() << std::endl;
	cpp2::mcxi a3("m2ci");
	cpp2::mcxi b3("4m7c9x8i");
	cpp2::mcxi result3 = a3 + b3;
	std::cout << "5m9c9x9i" << " " << result3.to_string() << std::endl;
	cpp2::mcxi a4("9c9x9i");
	cpp2::mcxi b4("i");
	cpp2::mcxi result4 = a4 + b4;
	std::cout << "m" << " " << result4.to_string() << std::endl;
	cpp2::mcxi a5("i");
	cpp2::mcxi b5("9m9c9x8i");
	cpp2::mcxi result5 = a5 + b5;
	std::cout << "9m9c9x9i" << " " << result5.to_string() << std::endl;
	cpp2::mcxi a6("m");
	cpp2::mcxi b6("i");
	cpp2::mcxi result6 = a6 + b6;
	std::cout << "mi" << " " << result6.to_string() << std::endl;
	cpp2::mcxi a7("i");
	cpp2::mcxi b7("m");
	cpp2::mcxi result7 = a7 + b7;
	std::cout << "mi" << " " << result7.to_string() << std::endl;
	cpp2::mcxi a8("m9i");
	cpp2::mcxi b8("i");
	cpp2::mcxi result8 = a8 + b8;
	std::cout << "mx" << " " << result8.to_string() << std::endl;
	cpp2::mcxi a9("9m8c7xi");
	cpp2::mcxi b9("c2x8i");
	cpp2::mcxi result9 = a9 + b9;
	std::cout << "9m9c9x9i" << " " << result9.to_string() << std::endl;
}