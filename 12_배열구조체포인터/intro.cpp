/*
01 포인터와 배열
배열의 원소를 가리키는 포인터
포인터의 덧셈과 뺄셈
int* p = &arrays[5];
p가 인덱스5를 가지는 원소를 가리키게 만든다.
p++;
를 하면 다음 주소를 가리켜 &arrays[6];과 같은 의미.
p++를 해도 1이 더해지는 것이 아니라 4가 더해진다.
12_1.cpp
포인터 타입의 덧셈은 산술 타입의 덧셈과는 그 의미가 다르기 때문에 수행방법도 다르다.
포인터 변수에 1을 더하는 것은 "다음 원소를 가리켜라"라는 뜻.
즉, 가리키고 있는 타입의 크기만큼 증가되는 것.
즉, 포인터 변수에 n만큼 더하는 것은 실제로 '가리키고 있는 타입의 크기*n'만큼 주소값 증가.
그리고 이는 포인터가 현재 가리키고 있는 원소에서 n개 만큼 뒤에 있는 원소를 가리킴.
뺄셈도 동일하게 동작.
12_2.cpp
포인터간의 뺄셈도 포인터가 가리키는 타입의 크기게 영향을 받는다.
12_3.cpp
포인터간의 뺄셈은 단순히 그 주소간의 차를 반환하지 않는다.
대신에 두 포인터가 가리키는 원소 사이에 몇 개의 원소가 있는지를 반환한다.
포인터간의 뺄셈이 포인터의 덧셈이나 뺄셈과 같은 원리로 동작합니다.
컴퓨터의 입장에서는 '바이트'라는 단위를 사용했고, 그 값이 우리에게 반환될 때는 
'원소 하나의 크기'라는 단위를 사용하게 변경한 것.
포인터와 관련한 연산에서 우리가 사용하는 단위는 '원소 하나의 크기'가 되고,
실제 컴퓨터가 작업을 할 때는 '바이트'라는 단위로 작업을 하게 된다.

배열의 이름은 첫번째 원소의 주소다.
float f[5];
f == &f[0]
f는 배열의 이름이다. &f[0]은 첫번째 원소의 주소다.

배열의 원소를 가리키는 포인터만 이렇게 동작할까?
보통의 변수를 가리키는 포인터도 똑같이 동작한다.
그 경우에는 덧셈이나 뺄셈을 수행하는 것이 의미가 없는 것.
일반 변수를 가리키는 포인터에 덧셈이나 뺼셈을 수행한 후 접근하면
그곳에 어떤 정보가 있는지 알 수 없기 때문에 문제가 발생.
배열도 배열의 범위를 벗어나지 않게 해야한다.

포인터로 원소 탐색하기
12_4.cpp
포인터의 덧셈을 사용한 소스
12_5.cpp
p+i가 괄호로 싸여있기 때문에 제일 먼저 계산이 된다.
거기의 *를 붙여줌으로써 nArray[i]와 같은 의미.
포인터 변수를 사용할 때도 배열의 원소에 접근하는 문법과 동일한 문법을 사용할 수 있다.
즉, p[i] = i;라고 작성해도 같다.
또한 배열의 이름을 포인터처럼 사용할 수 있다.
*(nArray + i) = i;도 같은 의미가 된다.
포인터는 다른 원소를 가리키게 변경할 수 있지만, 배열의 이름은 항상 첫번째 원소의 주소만
의미하는 상수. nArray++ 같은 것은 불가능.

배열을 가리키는 포인터
12_6.cpp
[]연산자가 *연산자보다 우선 순위가 높다.
long* p[20]이라고 써주면 p[20]이 먼저 해석이 되기 때문에 
'long* 타입의 원소 20개를 갖는 배열'을 정의한다.
괄호로 우선순위로 바꿔 'long 타입의 원소 20개를 갖는 배열에 대한 포인터'가 정의.
(*p)[3]라고 해주면 'p가 가리키는 배열의 3번째 원소'라는 의미.
p를 하나 증가시키면 실제로 p의 값을 80바이트 만큼 증가하게 된다.

포인터의 배열
12_7.cpp
원소의 타입이 포인터라는 것을 제외하고는 일반적인 배열과 같다.

02 배열과 구조체
배열을 포함하는 구조체
어떤 타입이든지 구조체의 멤버가 될 수 있고 배열도 가능.
12_8.cpp

구조체의 배열
원소의 타입이 구조체라는 점을 제외하고는 같다.
12_9.cpp
구조체와 배열을 합치면 복잡하고 방대한 자료를 효율적으로 관리할 수 있다.
구조체는 학생별로 신상정보를 관리, 배열은 여러 학생의 정보를 한 곳에 모아 관리.

03 포인터와 구조체
구조체를 가리키는 포인터
포인터로 구조체를 가리키는 것은 아주 흔한 일이다.
12_10.cpp
연산자의 우선순위 때문에 (*p).x처럼 괄호로 감싸줄 필요가 있다.
물론 p->x로 처리할 수 있고, 더 많이 사용한다.
'p가 가리키는 구조체 변수의 x라는 멤버'로 해석하면 된다.

포인터를 포함하는 구조체
구조체 안에 그냥 포인터 변수를 정의해주면 됩니다.
12_11.cpp
구조체 안에 포함된 포인터 변수가 구조체 자신을 가리킨다면 재밌어진다.
12_12.cpp
각 구조체 변수의 멤버 p는 다음 구조체 변수를 가리키게 설정되었다.
a.p->id는 (*a.p).id가 되고, b의 주소를 가리키기 때문에 b.id
a.p는 'a의 멤버 p'가 된다.
a.p->id는 'a의 멤버 p가 가리키는 구조체의 멤버 id'라는 뜻. 'b의 멤버 id'

링크드 리스트(Linked List)
대표적인 자료구조 중 하나.
동적으로 구성원을 넣고 뺄 수 있는 장점 때문에 배열을 대신해서 많이 사용한다.

*/