// 4-3.cpp

#include <iostream>
#include <iomanip>

using namespace std;

//숫자가 문자열로 변경할 때 
// 문자열의 길이를 반환하는 함수
int get_length(int num) {
	//Base vase: 0
	int length = 1;
	while (num / 10 > 0) {
		num /= 10; 
		++length; // 10 / 10 = 1 +
	}
	return length;
}

int main(void) {

	const int max_num = 1000;

	int max_len = get_length(max_num);
	int max_sq = get_length(max_num * max_num);
	for (int i = 1; i <= 1000; i++) {
		cout << 
			setw(max_len) << i << ": " << 
			setw(max_sq + 1) << i * i << endl; 
	}

	return 0;
}
