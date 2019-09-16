/*
01 변수와 함수의 접근 범위와 존속 기간
왜 접근 범위와 존속 기간을 배워야 할까
접근 범위란 "어떤 종류의 변수는 어디에서는 접근할 수 없고, 어디에선 접근할수 있다"
존속 기간이란 "어떤 종류의 변수가 어떤 시점에 생성되고 어떤 시점에 소멸되는지"
잘못 이해하고 있으면 전혀 엉뚱한 결과가 나올 수도 있다.

지역변수와 전역변수
함수 안에서 정의한 변수를 지역변수(Local Variables)
함수 밖에서 정의한 변수를 전역변수(Global Variables)
26_1.cpp
지역변수:지역 변수를 정의한 함수에서만 접근할 수 있음
지역 변수가 정의될 때 생성. 함수가 종료될 떄 소멸.
객체의 경우는 해당하는 시점에서 생성자와 소멸자가 호출된다.
전역변수:전역변수를 정의한 파일에 있는 모든 함수에서 접근할 수 있음.
(다른 파일에서도 접근 할 수 있는 방법이 존재한다.)
프로그램이 시작할 때 생성. 프로그램이 종료할 때 소멸.
객체의 경우는 해당하는 시점에서 생성자와 소멸자가 호출된다.

지역 변수와 전역 변수의 초기값
지역변수를 초기화하지 않은 경우에는 쓰레기 값을 갖게 된다.
반면에 전역변수를 초기화를 안해도 0값을 갖는다.

자동 변수
지역 변수는 Auto Variables라는 이름으로 불리기도 한다.
함수를 종료할 때 자동으로 소멸되기 때문에.
auto라는 키워드가 존재한다.
auto int local = 20;
auto는 변수의 타입을 자동으로 지정해주는데, 오른쪽 값을 통해 결정한다.

extern 키워드
프로그램을 만들다보면 다른 파일에서 정의한 전역 변수에 접근할 일이 생긴다.
extern키워드를 사용해서 다른 파일에서 정의한 전역 변수에 접근할 수 있다.
26_2.cpp 26_2_2.cpp
다른 파일에서 정의한 전역 변수에 접근하기 위해서는 extern키워드를 사용해서
다시 한번 선언 해줄 필요가 있다.
"컴퓨터야, int타입의 전역 변수 ga가 다른 파일에 있는데 이 파일에서도 사용할게"

블록 안에서 정의된 변수
블록은 중괄호로 둘러 쌓인 코드의 블록.
26_3.cpp
중괄호만 사용해서 블록을 만들 수 있는데 블록 안에서 변수를 정의할 수도 있다.
같은 블록안에서만 변수에 접근할 수 있고 블록이 끝나면 변수 역시 소멸.
블록 안에서 정의한 변수는 지역 변수다.

다른 영역에 정의된 변수의 이름이 중복되는 경우
변수를 정의하는 영역이 다르다면 변수의 이름이 같아도 무방하다.
26_4.cpp
변수 x를 사용할 때 그 x는 가장 가까운 곳에서 정의한 변수 x를 의미.
하지만 이렇게하면 매우 혼동스러우니 바람직하진 않다.

for 명령 안에서 정의한 변수
for명령에서 초기 값을 적어주는 부분에서 변수를 정의할 수 있다.
26_5
for(int i = 0; i < 10; ++i)
	cout << i << "\n";
i = 100; //실패
for 명령 안에서 정의한 변수는 for명령 안에서만 존재하고 for명령끝나면 소멸.
조금 오래된 컴파일러들은 for명령 밖에서도 살아있게 만든다.
똑같은 이름의 변수를 두번 정의하면 오류가 발생.
닷넷은 둘다 허용하기도 한다.

비주얼 스튜디오가 컴파일러인가요?
컴파일러란 소스 코드를 실행 파일로 만들 때 필요한 프로그램.
비주얼 스튜디오는 컴파일러뿐아니라 편지빅와 탐색기 등 다양한 기능을 갖춘 IDE.

정적 변수
전역 변수나 지역 변수를 정의할 때 staic키워드로 존속기간, 접근범위에 변화를 준다.

static으로 정의한 지역변수
26_6.cpp
변수를 정의하는 순간에 생성된는 것은 동일하지만, 프로그램이 종료될 때까지 살아있는다.
static을 안쓰면 n의 값은 항상 1이 출력되야 한다.
static으로 정의한 지역 변수는 처음 생성할 때 한번만 초기화한다.
Sub()함수가 종료되어도 static으로 정의했기 때문에 프로그램이 종료할때까지 살아있는다.
만약에 함수가 종료되더라도 값을 유지하기를 원한다면 static키워드가 좋은 해결책.
static키워드를 사용한 지역변수는 존속기간은 변화하지만 접근 범위는 변하지 않는다.
n은 여전히 Sub()안에서만 접근 할 수 있다.

static으로 정의한 전역 변수
static으로 전역변수를 정의하면 다른 파일에서 이 변수에 접근할 수 없게 된다.
다른 파일에서 extern키워드를 사용해서 접근해도 오류가 발생한다.
26_2_2.cpp
//static으로 정의한 전역 변수
static int ga = 100; //오류 발생
전역 변수를 static으로 만드는 것은 클래스에서 접근 권한을 설정하는 것과 비슷.
다른 파일에서 전역 변수에 접근할 수 없게 만들고 싶을 때는 static키워드.
전역 변수를 static으로 만든 경우에도 존속 기간에는 차이가 없다.

레지스터 변수(Register Variables)
레지스터는 컴퓨터 안에 위치하고 있는 작고 빠른 메모리 공간을 의미한다.
32비트 CPU경우에는 32비트(4바이트) 크기의 레즈스터들을 가지고 있다.
레지스터는 메모리에 있는 데이터를 꺼내와서 레지스터 위에 올려놓은 뒤에 데이터를 사용.
변수들은 메모리에 자신의 값을 보관했지만 레지스터 변수는 레지스터에 보관한다.
레지스터 변수에 값을 읽고 쓰는 것은 훨씬 빠르게 동작한다.
냉장고에서 꺼내올 필요 없이 바로 도마 위에서 작업을 실행할 수 있다.
26_8
//레지스터 변수의 정의
register int i = 0;
while (i < 1000000)
	++i;
register키워드를 사용해서 변수를 정의하면 레지스터 변수를 만드는데 항상은 아니다.
"컴퓨터야, 가능하다면 이 변수를 레지스터 변수로 만들어줘"이므로 레지스터가 없으면
거절 당할 수도 있다.
현실적으로 레지스터 변수를 사용할 일은 많이 없다.
수행 시간에 민감한 코드를 작성할 일이 별로 없고, 요즘은 컴파일러가
반복 명령에 쓰이는 변수들은 알아서 레지스터 변수로 만들어 준다.
레지스터변수도 지역변수의 종류로 같은 함수에서만 접근이 가능하며 종료할 때 소멸.

함수와 접근 범위
멤버 함수가 아닌 일반적인 함수의 경우에 존속기간의 개념은 없지만 접근범위의 개념있다.

다른 파일에서 정의한 함수에 접근하기
함수의 접근 범위는 전역 변수와 비슷한 성격.
같은 파일에서 정의한 함수에 접근하는 것이 가능하며 extern키워드를 사용하면
다른 파일에서도 접근할 수 있다.
26_9.cpp 26_9_2.cpp
"컴퓨터야 어딘가에 void Func()함수가 있는데, 그 함수를 사용할게"
그 동안 우리가 다른 파일에서 정의한 함수를 사용할 때는 extern키워드를 생략하고
사용했던 것 뿐이다.
26_9.cpp
void Func();이라고 고쳐도 동일한 의미

static으로 정의한 함수
static 키워드를 사용해서 함수를 정의하는 것도 전역 변수와 비슷한 의미.
static void Func()으로 정의하면 다른 파일에서 Func()에 접근할 수 없다.

C언어와의 연결
C언어로 작성해둔 것이 있다면 굳이 새로 만드는 것보다 가져와서 사용하는 것이 효율적.
사실 C언의 모든 문법은 C++에서도 허용.
26_10
26_10.cpp 26_10_2.c
.c소스파일은 C언의 방식으로 컴파일하고, .cpp인 소스파일은 C++언의 방식으로 컴파일.
그런데 C와 C++는 함수의 이름을 내부적으로 보관하는 방법이 다르다.
C언어:_Func
C++:?Func@@YAXXZ
C++의 경우 오버로딩과 같은 기능을 제공하기 위해 함수의 종류나 인자에 정보를 가진다.
C의 경우에는 순수하게 함수 이름만 포함하고 있다.
서로 다른 함수이름이어서 오류를 발생한다.
해결하기 위해서는
26_10.cpp에서
extern "C" void Func();이라고 해주면 된다.
"컴퓨터야, C언어로 작성한 Func()라는 함수를 사용하고 싶어"

C언어의 방식으로 컴파일한다고요?
소스 코드를 실행 파일로 만드는 작업의 일부를 컴파일이라고 부른다.
컴퓨터는 C++언어를 이해할 수 없으므로 C++로 작성한 코드를 기계어로 번역해준다.
하지만 C언어의 방식과 C++언어의 방식이 컴파일하는 방법이 다르다.

*/