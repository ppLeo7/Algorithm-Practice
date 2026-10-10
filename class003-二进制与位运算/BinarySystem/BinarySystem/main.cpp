#include<iostream>
#include<cstdint>	//引入int32_t,uint32_t
#include<limits>	//获取int32_t的最小值，最大值
using namespace std;
//打印函数，将十进制整数（int32_t类型）以二进制形式输出，高位在左
void printBinary(int32_t num) {
	//传入的int32_t强制转换成uint32_t处理
	//避免C++算数右移
	uint32_t bits = static_cast<uint32_t>(num);
	for (int i = 31;i >= 0;--i) {
		cout << (((bits >> i) & 1u) ? "1" : "0");
	}
	cout << '\n';
}
void printBinaryUnsigned(uint32_t bits) {
	for (int i = 31;i >= 0;--i) {
		cout << (((bits >> i) & 1u) ? "1" : "0") ;
	}
	cout << '\n';
}
bool returnTrue() {
	cout << "进入了returnTrue函数" << '\n';
	return true;
}
bool returnFalse() {
	cout << "进入了returnFalse函数" << '\n';
	return false;
}
int main() {
	int32_t a = 78;
	cout << a << '\n';
	printBinary(a);
	cout << "===a===" << '\n';

	int32_t b = -6;
	cout << b << '\n';
	printBinary(b);
	cout << "===b===" << '\n';

	int32_t c = 0b1001110;
	cout << c << '\n';
	printBinary(c);
	cout << "===c===" << '\n';

	int32_t d = 0x4e;
	cout << d << '\n';
	printBinary(d);
	cout << "===d===" << '\n';

	//核心公式 ~a+1=-a
	//使用uint32_t进行无符号运算，确保不会触发有符号整数溢出UB
	uint32_t e_bits = (static_cast<uint32_t>(~a) + 1u);
	//使用 64 位整数进行计算，避免 32 位溢出
	int64_t e_val64 = static_cast<int64_t>(~static_cast<int32_t>(a)) + 1u;
	cout << e_val64 << " (注意：在 C++ 中直接取 -a 可能 UB，这里用 64 位展示数值)" << '\n';
	printBinaryUnsigned(e_bits);
	cout << "===e===" << '\n';

	//获取 32 位有符号整数的最小值
	int32_t f = numeric_limits<int32_t>::min();
	cout << f << '\n';
	printBinary(f);
	int64_t negf64 = -static_cast<int64_t>(f);
	cout << negf64 << " (使用 64 位展示数学上的相反数，C++ 中对 int 取反可能 UB)" << '\n';

	//~f+1==f
	uint32_t uf = static_cast<uint32_t>(f);
	uint32_t neg_bits = (~uf) + 1u;
	printBinaryUnsigned(neg_bits);
	cout << "===f===" << '\n';

	int32_t i = 0b0011010;
	printBinary(i);
	printBinary(i << 1);
	printBinary(i << 2);
	printBinary(i << 3);
	cout << "===i << ===" << '\n';

	printBinary(i);
	printBinary(i >> 2);
	printBinaryUnsigned(static_cast<uint32_t>(i) >> 2);
	cout << "===i >> >>>===" << '\n';

	// --- 演示 11：负数的右移（算术右移保留符号位 vs 逻辑右移补0） ---
	// 定义一个无符号 32 位整数，最高位（符号位）为 1，其余位为特定模式
	uint32_t j_bits = 0b11110000000000000000000000000000u;
	// 将该无符号数的位模式强制转换为有符号 int32_t（此时 j 是一个负数）
	int32_t j = static_cast<int32_t>(j_bits);

	printBinary(j);            // 打印负数 j 的二进制补码
	// 对负数 j 进行算术右移 2 位。C++ 实现通常会保留符号位（高位补 1）
	printBinary(j >> 2);
	// 将 j 转回无符号数后进行逻辑右移 2 位。高位强制补 0，符号位被破坏
	printBinaryUnsigned(static_cast<uint32_t>(j) >> 2);
	std::cout << "===j >> >>>===" << std::endl; // 打印分隔符

	// --- 演示 12：左移/右移 与 乘除法的对应关系 ---
	int32_t k = 10;            // 定义整数 k，赋值为 10
	std::cout << k << std::endl; // 打印原始值 10
	std::cout << (k << 1) << std::endl; // 左移1位，输出 20 (10 * 2^1)
	std::cout << (k << 2) << std::endl; // 左移2位，输出 40 (10 * 2^2)
	std::cout << (k << 3) << std::endl; // 左移3位，输出 80 (10 * 2^3)
	std::cout << (k >> 1) << std::endl; // 右移1位，输出 5  (10 / 2^1)
	std::cout << (k >> 2) << std::endl; // 右移2位，输出 2  (10 / 2^2，向下取整)
	std::cout << (k >> 3) << std::endl; // 右移3位，输出 1  (10 / 2^3，向下取整)
	std::cout << "===k===" << std::endl; // 打印分隔符
	return 0;
}