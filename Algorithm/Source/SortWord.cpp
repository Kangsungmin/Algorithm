#include "myheader.h"
/*
ù° �ٿ� �ܾ��� ���� N�� �־�����. (1��N��20,000) ��° �ٺ��� N���� �ٿ� ���� ���ĺ�
�ҹ��ڷ� �̷���� �ܾ �� �ٿ� �ϳ��� �־�����. �־����� ���ڿ��� ���̴� 50�� ���� �ʴ´�.
���ǿ� ���� �����Ͽ� �ܾ���� ����Ѵ�. ��, ���� �ܾ ���� �� �Էµ� ��쿡�� �� ������ ����Ѵ�.

���̰� ª�� �ͺ���
���̰� ������ ���� ������
���� ����ũ : https://www.acmicpc.net/blog/view/22
*/
vector<pair<int, string>> word;//����, ���� ��
int Algorithm::SortWord() {
	int N;
	string front = "";

	scanf_s("%d", &N);
	for (int i = 0; i<N; i++)
	{
		string w_temp;
		cin >> w_temp;
		int wl_temp = w_temp.length();//0��° ���ڿ� ����
									  //�̹� ���Ϳ� �ߺ��� ���� �ֳ� Ȯ��
		word.push_back(pair<int, string>(wl_temp, w_temp));
	}
	sort(word.begin(), word.end());

	for (int i = 0; i < word.size(); i++) {
		if (front.compare(word[i].second) != 0) {
			front = word[i].second;
			cout << word[i].second << endl;
		}
	}

	return 0;
}