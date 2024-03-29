#include "DynamicArray.h"
#include "MyException.h"
#include <iostream>
using namespace std;

void UseArray(DynamicArray& arr1, DynamicArray& arr2);

int main() {
	//배열 객체를 2개 만든다.
	DynamicArray arr1(10);
	DynamicArray arr2(8);

	UseArray(arr1, arr2);

	return 0;
}

void UseArray(DynamicArray& arr1, DynamicArray& arr2) {
	try {
		arr1.SetAt(5, 100);
		arr2.SetAt(5, 100);

		arr1.SetAt(8, 100);
		arr2.SetAt(8, 100);

		arr1.SetAt(10, 100);
		arr2.SetAt(10, 100);
	}
	catch (MyException& ex) { //레퍼런스 타입으로 받는 것이 좋다.
		//두 배열의 주소를 먼저 출력한다.
		cout << "&arr1 = " << &arr1 << "\n&arr2 = " << &arr2 << "\n";
		
		//예외에 대한 자세한 정보를 출력한다.
		cout << "예외를 던진 객체의 주소는 = " << ex.sender << "\n";
		cout << "예외에 대한 설명 = " << ex.description << "\n";
		cout << "부가 정보 = " << ex.info << "\n";
	}
}