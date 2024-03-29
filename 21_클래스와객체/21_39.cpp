#include "Point.h"

int main() {
	//초기화용으로 객체를 만들어준다.
	//복사 생성자를 호출하려고.
	Point pt(50, 50);

	//동적으로 객체를 생성한다.
	Point* p1 = new Point(); //디폴트 생성자 사용
	Point* p2 = new Point(100, 100); //인자가 있는 생성자 사용
	Point* p3 = new Point(pt); //복사 생성자 사용

	//객체들의 내용을 출력한다.
	//연산자 ->를 사용해서 멤버에 접근.
	p1->Print();
	p2->Print();
	p3->Print();

	//동적으로 생성한 객체들을 정리한다.
	delete p1;
	delete p2;
	delete p3;
	p1 = p2 = p3 = 0; //NULL

	return 0;
}