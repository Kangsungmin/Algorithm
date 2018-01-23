#include "myheader.h"
/*
첫 줄에 n(1≤n≤100,000)이 주어진다. 둘째 줄부터 n개의 줄에는 수열을 이루는 1이상 n이하의 정수가
하나씩 순서대로 주어진다. 물론 같은 정수가 두 번 나오는 일은 없다
입력된 수열을 만들기 위해 필요한 연산을 한 줄에 한 개씩 출력한다.
push연산은 +로, pop 연산은 -로 표현하도록 한다. 불가능한 경우 NO를 출력한다.
STL 스택?
- stack<type> stack 으로 스택을 만들고
- stack.push(데이터)로 추가하고자 하는 데이터를 입력합니다.
- stack.size() 는 현재 스택에 저장되어있는 데이터의 갯수를 반환합니다.
- stack.top()은 현재 스택 최상위의 데이터를 가져옵니다 (빼내는 것은 아니에요)
- stack.pop()은 현재 스택 최상위의 데이터를 제거합니다.
- stack.empty() 는 현재 스택이 비었으면 true, 아니면 false를 반환합니다.
*/
int Algorithm::SequenceStack() {
	int end;
	char result[200000];
	int stack[100000], s_index = 0, r_index = 0, max = 0;
	
	int N;
	scanf_s("%d",&N);

	while (N--) {//N>0일때 반복
		int input;
		scanf_s("%d", &input);
		if (max < input) {
			for (int i = max + 1; i <= input; i++) {
				stack[s_index++] = i;//대입 후, s_index++
				result[r_index++] = '+';
			}
			max = input;
		}
		else {
			if(stack[s_index-1] != input){
				printf("NO");
				break;
			}
		}
		//뺄차례
		s_index--;
		result[r_index++] = '-';
	}
	for (int i = 0; i < r_index; i++) printf("%c\n", result[i]);
	return 0;
}

