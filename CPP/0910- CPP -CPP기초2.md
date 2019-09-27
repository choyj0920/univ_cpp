# 0910

공백 포함 문자열 

getline(cin,string aa);

## 문자열 숫자값으로 변환 (stringstream)

```c++
int main(){
    string mystr;
	float price =0;
	int quantity =0;
	cout <<"Enter price :";
	getline(cin,mystr);
	stringstream(mystr)>>price;
	cout<<"Enter quantity: ";
	getline(cin, mystr);
	stringstream(mystr)>>quantity;
	cout<<"total price : "<< price *quantity<<endl;
}
```

## 변수와 상수

변수: 저장된 값의 변경이 가능한 공간

상수: 선언하면서 초기화를 꼭 해야하며 변경 불가

## 자료형의 종류



## 변수형 결정 (auto /decltype)

```c++
int foo =0;
auto bar =foo;  //sampe int bar =foo;

int foo =0;
decltype(foo) bar; // same int bar;
```

## 문자열 타입

문자열의 비교는 == 연산자로 가능

s1 == s2

### 리터럴 상수 

```
75
0113
0x
```

### 포인터 변수 초기화

```c++
int *p =nullptr
```

### 기호 상수

#define 의 경우 에러도 찾기 힘들고,  타입 지정도 안돼서 되도록 사용x

const type name;