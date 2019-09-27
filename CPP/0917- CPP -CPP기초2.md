# 0917_cpp

switch문에서 블락{}없을때에는 선언문 사용 안됨 . 블락으로 묶었을 경우 선언 가능

## 과제 관련 

system("pause")와 system("cls") , cin 에러 

```c++
//메뉴 출력 입력 부
int main(){
	while (menu != 4) {
        system("cls");
		cout << "1) 과제1   2) 과제2   3) 과제3   4) 종료" << endl;
		cout << "메뉴를 선택하세요 : ";
        int menu;
		cin>>menu;
        if(cin.fail()){
            cin.clear();  //cin 에러 발생 클리어
            cin.ignore(1000,"\n");  //cin 버퍼 제거
            continue;
        }

		switch (menu)
		{
		case 1:
			_HW01();
			break;
		case 2:
			_HW02();
			break;
		case 3:
			_HW03();
			break;
		case 4:
			break;

		}
	}

}

```

## 배열..

인덱스: 원소의 배열 순서

### 배열 선언

int grade[10];

배열 크기 지정에  변수 못 들어감   하지만 동적할당에서는 가능~

배열의 크기는 고정 불변 런타임에 그 크기를 변경 할수 없다 

### 배열 복사, 배열 비교

```c++
int grade[SIZE];
int b[SIZE];

grade= b; //오류!
방대 방으로 복사 


```

```c++
int num[12];
//num은 첫번째 방의 주소
num == &num[0];
&num[4]==  (num+4);
```

그러면 num과 &num[0]은 완전히 똑같을까 X



## 이차원 배열

```c++
int num[4][3];

num ==&num[0]
num[0] =&num[0][0]

//이차원 배열의 이름은 층의 시작 주소!(&num[0])
num[a][b] == *(*(num+a)+b)
```

