/*
01 C++에서 제공하는 타입
왜 여러 가지 타입을 배워야 할까
타입이란 변수가 보관할 수 있는 값의 종류.
제공하는 타입이란 기본적인 정수, 실수, 문자 타입에 옵션을 달아 확장한 것까지.

컴퓨터는 정수를 계산하는 것보다 실수를 계산하는 것을 훨씬 힘들어 한다.
실수에 대한 사칙 연산은 시간이 매우 많이 걸리는 작업.
많은 CPU에서 실수를 계산하는 프로세서가 별도로 탑재.
실수를 보관하는 방식은 정수를 보관하는 방식과 판이하게 다르다.

짧은 정수, 긴 정수로 구분하는 것은 변수가 차지하는 공간을 절약하기 위한 것.
메모리가 될 수 있고, 하드디스크나 네트워크가 될 수도.
unsigned는 양수만을 보관할 수 있어 음수는 안되지만 더 큰 양수를 보관할 수 있는 장점.
세계 각국의 언어를 표현하기 위해서 넓은 공간이 필요해 wchar_t가 생김.
bool타입은 0,1대신 false,true로.
float, double, long double은 실수의 정밀도에 따라서 구분.
다양한 타입을 제공하는 이유는 개발자들에게 보다 많은 선택권을 주기 위함.

다양한 종류의 int 타입
그냥 int 는 signed int.
5_1.cpp
경고 메시지가 발생하지만 프로그램을 실행할 순 있다.
그러나 전혀 엉뚱한 값이 대입되는 결과.

1)보관하려는 값이 short int 타입에 들어갈 수 있다면 short int를 사용하라.
2)만약 더 큰 수고 음수가 아니라면 unsigned short int를 고려해보자.
3)그것도 모자라면 int나 long int를 사용하자.

보관할 수 있는 값의 범위가 클수록 시스템의 자원을 많이 소모한다.

error, warning
warning은 문제보다는 조심해야 될 것 같다고 말해주는 것이다.
오류가 하나라도 발생하면 프로그램을 실행할 수 없다.
경고는 프로그램을 실행할 수 있다.
반드시 경고의 원인을 파악하고 모든 경고 메시지를 없애기 위해서 노력해야 한다.

Warning Level
기본 값인 3보다 한 단계 더 강력한 경고 수준은 4단계

가이드라인이 항상 옳은 것은 아니지만 파일에 쓰는 것이라면 하드디스크가 절약,
네트워크로 보내는 경우라면 더 빨리 보낼 수 있을 것이다.

실제적인 가이드라인은
1)정수를 담을 때는 int를 사용한다.
2)보관하려는 값이 절대로 음수가 될 일이 없다면 unsigned int를 사용하자.

43억을 보관하려면
정수 타입에는 43억을 보관할 만한 것이 없다.
실수 타입은 부동 소수점 방식을 사용하기 때문에 가능하지만 끝 부분이 잘려나가기도 합니다.
C++표준에는 존재하지 않지만 C++에만 존재하는 대용량 정수 타입 _int64가 있습니다.
다만 비주얼 C++에만 존재해서 다른 환경에서는 동작하지 않을 수 있다.
long long int타입도 있는데 64비트의 크기를 갖는 정수 타입입니다. 43억 이상보관 가능.
보다 확실한 방법은 long int와 같은 기본 타입의 변수를 여러 개 묶어서 사용하는 것.
클래스를 이용하면 새로운 타입을 만드는 것이 가능하고, 모든 환경에서, 43억이상 보관가능.

비트와 바이트
비트는 전기 장치로 생각할 수 있다. 0과 1
8비트는 1바이트.
변수에 값이 보관된다고 할 때 그 값은 컴퓨터의 메모리에 보관되는 일.
short int는 2바이트로 2^16=65536개.
int나 long int는 4바이트로 2^32=43억개.

타입의 크기를 알아보는 방법
5_2.cpp
sizeof()는 C++에서 기본적으로 제공하는 연산자 중에 하나.
괄호 안에 타입 이름을 넣어주면 해당 타입의 크기가 나오게 됩니다.
변수 이름을 넣어주면 변수의 타입에 대한 크기가 나오게 됩니다.

하지만 C++표준안은 정수 타입의 크기를 정확하게 명시하고 있지 않다. 최소한의 규정은
1)short int는 2바이트보다 커야한다.
2)int의 크기는 적어도 short int보다 커야 한다.
3)long int는 적어도 4바이트보다 커야하고 int 크기보다 커야 한다.
int는 시스템의 자연스러운 크기를 따르도록 규정하고 있다.
자연스러운 크기는 시스템에서 한 번에 처리할 수 있는 크기.
윈도우즈 환경에서는 4바이트 32비트.
32비트 컴퓨터라는 것은 한 번에 처리할 수 있는 크기가 32비트.
DOS와 같은 16비트 시스템에서는 int는 2바이트의 크기.
signed와 unsigned는 동일한 크기를 갖는다는 규정도 포함하고 있다.

signed와 unsigned
short int는 0~32767,-32768~-1
unsigned short int는 0~65536

10진수, 8진수, 16진수의 표현
8진수나 16진수로 숫자를 적을 때는 숫자 앞에 공백 없이 0혹은 0x를 붙여주면된다.
5_3.cpp

실수타입
실수를 보관할 수 있는 타입을 보통 부동 소수점 타입이라고 말한다.
소수점이 이리 저리 옮겨 다닐 수 있다는 뜻.
5_4.cpp

float의 경우에만 f를 상수 뒤에 붙입니다.
C++에서 실수 뒤에 f가 붙어 있지 않으면 double에 상응하는 실수 값이라고 생각.
double보다 정밀도가 떨어지는 float타입의 변수에 대입하려고 하면 경고 메시지.

1.23E-3=1.23*10^-3=0.00123
지수를 사용해서 표현하면 공간도 절약되고, 자리 수 파악도 쉬워진다.

실수 타입의 내부 구조
고정 소수점 방식이 있다면 일정 공간은 정수 부분을 저장하고 나머지는 소수부분을 저장.
하지만 부동 소수점타입은 유효자리를 저장하고 나머지 공간에는 지수를 저장하고 있다.
부동 소수점 방식을 사용하면 보다 넓은 범위의 숫자를 보관할 수 있다.
그러나 정밀도를 잃어버릴 수 있다는 단점.
이진수를 사용해서 정확한 실수를 표현하는 것이 불가능하다는 것과 가수저장공간 제한에서 단점이.
float나 double의 구체적인 내부구조에 대해서는 IEEE754표준안에서 정의.
다만 모든 시스템에서 이 표준안을 완전하게 따르고 있지는 않다.

문자 타입
char는 표현할 수 있는 문자의 수가 제한적인 반면에 wchar_t는 세계각국의 문자와 기호표현가능.
실제에선 char를 주로 사용하고 wchar_t는 특별히 요구되는 상황에서만 사용.
5_5.cpp
문자 타입의 변수에는 오직 하나의 문자만 보관.
문자 상수를 표현할 때는 작은 따옴표로 감싸준다.
큰 따옴표로 감싸는 경우는 여러 개의 문자를 사용하는 경우.

char는 보통 1바이트의 크기. 2^8=256가지.
ASCII코드를 이용하고 'A'는 65와 대응.
5_6.cpp
정수 타입이라면 65가 정수로 해석될 것이고 문자 타입이라면 'A'로 해석될 것이다.

char는 signed char가 될 수도 있고 unsigned char가 될 수도 있다. 
표준안에서 규정하고 있지는 않다. 개발 환경에 따라 달라질 수 있다.

이스케이프 문자열(Escape Sequences)
특수 문자를 의미하는 암호를 만들었다.
모든 이스케이프 문자열은 역슬래쉬로 시작한다. 뒤에는 미리 약속된 다양한 문자.
특수문자   아스키 코드 상에서의 표현   C++에서의 표현
개행문자   NL(LF)                    \n
수평탭     HT                        \t
수직탭     VT                        \v
백스페이스 BS                        \b
캐리지리턴 CR                        \r
폼 필드    FF                        \f
벨소리     BEL                       \a
역슬래쉬   \                         \\
물음표     ?                         \?
작은따옴표 '                         \'
큰 따옴표  "                         \"
8진수     ooo                        \ooo
16진수    hhh                        \xhhh
5_7.cpp

이스케이프 문자열의 도입으로 역슬래쉬는 이제 이스케이프 문자열의 시작을 의미.
그래서 그냥 역슬래쉬만 쓰게 되면 이상한 결과를 가져옴.
8진수와 16진수는 역슬래쉬 뒤에 문자의 아스키 코드 값을 직접 써줌으로써 그 문자를 표현.
'A'는 65고 8진수면 101, 16진수면 41이 된다. 그래서 \101, \x41은 모두 'A'가 된다.

넓은 문자의 사용
wchar_t는 보통 2바이트의 크기. 아스키코드 대신에 유니코드를 이용.
wchar_t wc;
wc=L'(';
문자 상수 앞에 L을 붙이면 상수가 wchar_t 타입에 상응한다는 의미.

bool 타입
true 혹은 false값.
5_8.cpp

타입의 표시와 실제적인 의미
컴퓨터는 정수에서 뭐가 안써있으면 signed나 int가 생략된 것.

헝가리안 표기법
기본적인 아이디어는 변수의 이름 앞에 타입의 약자를 적어 넣는 것.
평범한 방식은 int maxSize;라고 할 수 있다.
헝가리안 표기법은 숫자의 약자인 n을 이용해 int nMaxSize;라고 한다.
윈도우즈 프로그래밍에서 주로 사용합니다.
API나 MFC에서 많이 사용됩니다.
관리를 소홀히 하게 되면 일치하지 않아 오히려 가독성을 떨어트릴 수 있습니다.
IDE는 헝가리안 표기법이 필요하지 않게 마우스를 가져다 대서 정보를 보여줌.

02 형변환
왜 형변환을 배워야 할까?
한 변수에 보관되어 있던 값을 다른 타입의 변수에 대입하는 경우.
값이 어느 정도 잘리는 경우도 있고, 정밀도가 떨어지는 경우도 있고 엉뚱한 값으로 될수도 있음.

형변환 규칙
5_9.cpp

형변환 시에 값이 변경되는 경우.
1)실수 타입에서 정수 타입으로 형변환이면 실수의 소수점 이하 부분이 잘리게 된다.
2)모든 타입에서 bool 타입으로 형변환이면 모든 0이 아닌 수는 true, 1이 된다.

문제가 발생하는 형변환
공통적인 조건은 큰타입에서 작은타입으로 형변환이 일어날 때 문제.
물리적인 한계로 인해서 올바른 값을 담을 수 없게 된다.
앞에 잘리는 경우는 예측되는 경우라 괜찮다.
5_10.cpp
고정된 소수점 방식을 출력하기 위해 cout << fixed;

명시적인 형변환
눈에 보이는 방식으로 직접 무언가 하는 것.
묵시적은 눈에 보이지 않게 자동적으로 수행되는 것.
지금까지는 모두 암시적인 형변환이었었다.
명시적으로 형변환을 시키게 되면 굳이 다른 타입의 변수에 대입하지 않아도된다.
5_11.cpp
명시적인 형변환을 위해서는 변수 혹은 값의 앞쪽에 괄호와 함께 타입을 적어주면 된다.
명시적인 형변환에는 임시 변수가 수반된다.
우리에게 보이지는 않지만 컴퓨터가 내부적으로 사용하려는 목적으로 만드는 변수.
우리가 (char)i라고 적어주면 내부적으로 char타입의 변수가 하나 만들어지고,
i의 값이 이 변수에 대입되면서 형변환을 발생시킨다.
결론적으로 (char)i라는 표현은 이 임시 변수를 의미한다.
이러한 임시 객체 때문에 발생하는 문제점이나 성능 저하가 있다.
소수점 이하 부분을 잘라내기 위해 일부러 형변환을 시킨 것이라면 명시적인 형변환을
사용해서 그 의도를 명확히 할 수 있다. 그러면 경고가 발생하지 않는다.
C++에서는 (char)i뿐만아니라 char(i)로 사용할 수도있다. 클래스 형변환과 관련해서.

*/