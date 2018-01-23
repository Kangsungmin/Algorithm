#include "myheader.h"
/*
입력 데이터는 표준 입력을 사용한다. 입력은 T개의 테스트 데이터로 주어진다. 
입력의 첫 번째 줄에는 입력 데이터의 수를 나타내는 정수 T가 주어진다. 
각 테스트 데이터의 첫째 줄에는 괄호 문자열이 한 줄에 주어진다. 하나의 괄호 문자열의 길이는 2 이상 50 이하이다. 
')'를 입력받을때 +1를 하고 '('를 입력받으면 -1를 한다. 한 줄을 모두 확인 했을 때 0이 아니면 NO, 0이면 YES
*/
int Algorithm::ParenthesisStack() {
	int T;
	char P_string[50];
	string res = "";
	scanf_s("%d",&T);
	while (T--)
	{
		scanf_s("%s", P_string);
		printf("%s",P_string);
	}
	return 0;
}