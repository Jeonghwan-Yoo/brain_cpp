#include <iostream>
using namespace std;

void PrintMessage(); //PrintMessage()가 아래쪽에 있다는 점을 컴퓨터에게 알려준다.세미콜론.

int main() {
	//PrintMessage()함수를 호출
	PrintMessage(); //함수를 호출한다는 것은 실행한다는 것이다.
	return 0;
}

void PrintMessage() { //함수 정의
	cout << "Hi, I'm your first function!!!\n";
}
