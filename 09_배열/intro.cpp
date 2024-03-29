/*
01 배열의 기본
왜 배열을 사용해야 할까
배열은 동일한 타입의 변수 여러 개를 묶어 놓은 것.
또한 배열은 자신 안에 포함된 여러 개의 변수를 하나로 묶는 그룹 개념.
2바이트짜리 변수 10000개를 모아둔 배열은 20000바이트의 정보를 담을 수 있다.

배열의 정의
9_1.cpp
변수를 몇 개나 만들 것인지를 대괄호 안에 적어주면 끝난다.
컴퓨터는 해당 타입의 값을 담을 수 있는 공간이 연속적인 5개 생김.
배열에 포함된 각각의 변수들을 배열의 원소라고 한다.
배열의 원소에 접근하기 위해서, 배열의 이름 뒤에 대괄호를 붙이고, 그 안에 인덱스를 적으면된다.
배열의 첫번째 원소는 0의 인덱스를 갖는다.

배열의 범위와 접근 위반
컴퓨터를 사용하다보면 갑자기 죽어버리는 프로그램 즉, '비정상 종료'를 한다.
그 중 한가지 원인은 접근 위반(Access Violation)이고 또, 잘못된 배열의 사용이다.
9_2.cpp
올바른 인덱스를 사용해야 한다.
Code 0xC0000005는 '접근 위반 오류'를 의미하는 값.
범위를 약간 벗어난 인덱스를 사용할 때 컴퓨터 내부적인 동작 방식에 의해 종료가 안될 수도있다.

원소의 탐색
9_3.cpp

배열의 초기화
배열을 정의하는 동시에 초기화하는 것이 가능하다.
9_4.cpp
중괄호를 사용해서 각 원소의 값을 차례로 적어주면 되고, 0번째 원소의 값이 제일 앞에 위치.
배열의 크기보다 적은 개수의 초기 값을 넣어줄 수 있다.
초기화에서 제외된 원소의 값은 자동적으로 0으로 채워진다.
int kor_scores [5] = { 100,88 }; //100,88,0,0,0
배열의 초기화를 사용하면 배열의 크기를 지정해주지 않아도 된다.
int kor_scores [] = { 100,88,,92,40,76 };
배열을 정의할 때 말고는 초기화할 수 없다.
int kor_scores[];
kor_scores = { 100,88,92,40,76 }; 이것은 불가능하다.
배열끼리 대입하는 것도 불가능하다.
int arrayA [3] = { 1,2,3 };
int arrayB [3] = arrayA; 오류
arrayB = arrayA; //오류
배열의 이름은 모든 원소들을 대표하는 기능 밖에 없다.
배열을 정의한 이후에 초기화를 하거나 복사하려면 각 원소를 하나씩 대입하는 수 밖에없다.
9_5.cpp

초기화되지 않은 값
초기화하지 않으면 예상할 수 없는 임의의 값을 갖게 된다.
변수의 정의를 통해서 확보되는 메모리 공간은 이전에 다른 변수가 쓰던 공간.
그 전 주인은 자신이 소멸하면서 청소하지 않았다.
새 변수는 그 값을 그대로 갖게 되고, '쓰레기 값'이라고 불린다.

배열의 크기
sizeof 연산자
9_6.cpp
변수와 타입의 크기를 바이트 단위로 반환한다.
기본적으로 전체 배열의 크기는 '각 원소의 크기'x'원소의 개수'
9_7.cpp
원소의 개수를 계산하다는 것이 가능하고 유리하다.
9_8.cpp
for문 조건 범위가 상수라 개수가 변하면 접근 위반이 발생한다.
더 좋은 해결책은 컴퓨터 스스로 원소의 개수를 계산하게 만드는 것.
9_9.cpp

성능문제
sizeof(array)/sizeof(array[0])을 계속 계산하면 프로그램이 느려질것같지만,
그 값을 계산해두고 그 값을 사용한다. 매번 계산하지 않는다.

02 배열에서의 문자열 사용
문자열의 개념
String은 문자가 여러개 이어져 있는 것. 
문자열은 문자의 배열인데, 마지막 문자가 반드시 '\0'이어야 한다.
'\0'은 이스케이프 문자열로 아스키코드가 0인 문자고 NULL이라고 부른다.
char 타입에 저장하는 값은 결국 아스키 코드이다.
문자열의 마지막 문자가 NULL이라는 것은 약속이다.
없으면
9_10.cpp
뒤에 이상한 문자가 찍힌다. 그것은 ThisIsNotString 배열의 이웃에 살고 있는 값들.
컴퓨터의 내부적인 동작 방식 때문에 ThisIsString이 늦게 정의되었음에도 메모리의 앞쪽에 위치.
cout객체 뿐만아니라 문자열을 다루는 많은 코드들은 for와 같은 반복 명령을 통해 한글자씩 처리.
이 때 반복 명령이 종료하는 조건은 'NULL문자를 만날 때까지'이다.
ThisIsNotString은 NULL문자가 없기 때문에 계속해서 반복 수행을 하기 때문.

문자열 상수(String Literal)
쌍 타옴표를 사용해서 문자열 상수를 만들 수 있다.
그리고 여기에는 NULL문자가 보이지 않는다.
쌍 따옴표를 사용해서 문자열 상수를 만든 경우에는 자동으로 NULL문자가 끝에 따라 붙는다.
9_11.cpp
크기와 내용면에서 완전히 동일.

*/