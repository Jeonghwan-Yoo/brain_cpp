#include <iostream>
using namespace std;

int main() {
	//계속해서 메뉴를 보여준다.
	while (1) {
		//메뉴 보여주기
		cout << "\n------- 메뉴 -------\n";
		cout << "1. 학생 성적 추가\n";
		cout << "2. 전체 성적 보기\n";
		cout << "Q. 프로그램 종료\n";
		cout << "--------------------\n\n";
		cout << "원하는 작업의 번호를 입력하세요 : ";

		//작업 입력 받기
		char select;
		cin >> select;

		//선택된 값에 따라서 처리
		switch (select) {
		case '1':
			//학생 성적 추가
			cout << "\n학생 성적 추가가 선택되었습니다.\n";
			break;
		case '2':
			//전체 성적 보기
			cout << "\n전체 성적 보기가 선택되었습니다.\n";
			break;
		case 'Q':
		case 'q':
			//종료
			cout << "\n프로그램을 종료합니다.\n";
			return 0;
		default:
			//그 외의 선택
			cout << "\n올바른 값을 입력해주세요.\n";
			break;
		}
	}
	return 0;
}