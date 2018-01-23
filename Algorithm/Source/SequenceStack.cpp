#include "myheader.h"
/*
ù �ٿ� n(1��n��100,000)�� �־�����. ��° �ٺ��� n���� �ٿ��� ������ �̷�� 1�̻� n������ ������
�ϳ��� ������� �־�����. ���� ���� ������ �� �� ������ ���� ����
�Էµ� ������ ����� ���� �ʿ��� ������ �� �ٿ� �� ���� ����Ѵ�.
push������ +��, pop ������ -�� ǥ���ϵ��� �Ѵ�. �Ұ����� ��� NO�� ����Ѵ�.
STL ����?
- stack<type> stack ���� ������ �����
- stack.push(������)�� �߰��ϰ��� �ϴ� �����͸� �Է��մϴ�.
- stack.size() �� ���� ���ÿ� ����Ǿ��ִ� �������� ������ ��ȯ�մϴ�.
- stack.top()�� ���� ���� �ֻ����� �����͸� �����ɴϴ� (������ ���� �ƴϿ���)
- stack.pop()�� ���� ���� �ֻ����� �����͸� �����մϴ�.
- stack.empty() �� ���� ������ ������� true, �ƴϸ� false�� ��ȯ�մϴ�.
*/
int Algorithm::SequenceStack() {
	int end;
	char result[200000];
	int stack[100000], s_index = 0, r_index = 0, max = 0;
	
	int N;
	scanf_s("%d",&N);

	while (N--) {//N>0�϶� �ݺ�
		int input;
		scanf_s("%d", &input);
		if (max < input) {
			for (int i = max + 1; i <= input; i++) {
				stack[s_index++] = i;//���� ��, s_index++
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
		//������
		s_index--;
		result[r_index++] = '-';
	}
	for (int i = 0; i < r_index; i++) printf("%c\n", result[i]);
	return 0;
}

