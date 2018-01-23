#include "myheader.h"
/*
첫째 줄에 단어의 개수 N이 주어진다. (1≤N≤20,000) 둘째 줄부터 N개의 줄에 걸쳐 알파벳
소문자로 이루어진 단어가 한 줄에 하나씩 주어진다. 주어지는 문자열의 길이는 50을 넘지 않는다.
조건에 따라 정렬하여 단어들을 출력한다. 단, 같은 단어가 여러 번 입력된 경우에는 한 번씩만 출력한다.

길이가 짧은 것부터
길이가 같으면 사전 순으로
정렬 참고링크 : https://www.acmicpc.net/blog/view/22
*/
vector<pair<int, string>> word;//문자, 길이 쌍
int Algorithm::SortWord() {
	int N;
	string front = "";

	scanf_s("%d", &N);
	for (int i = 0; i<N; i++)
	{
		string w_temp;
		cin >> w_temp;
		int wl_temp = w_temp.length();//0번째 문자열 길이
									  //이미 벡터에 중복된 값이 있나 확인
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