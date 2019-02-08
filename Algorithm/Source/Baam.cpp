#include "Baam.h"
using namespace std;
/*
첫째 줄에 보드의 크기 N이 주어진다. (2 ≤ N ≤ 100) 다음 줄에 사과의 개수 K가 주어진다. (0 ≤ K ≤ 100)
다음 K개의 줄에는 사과의 위치가 주어지는데, 첫 번째 정수는 행, 두 번째 정수는 열 위치를 의미한다. 사과의
위치는 모두 다르며, 맨 위 맨 좌측 (1행 1열) 에는 사과가 없다.
다음 줄에는 뱀의 방향 변환 횟수 L 이 주어진다. (1 ≤ L ≤ 100)
다음 L개의 줄에는 뱀의 방향 변환 정보가 주어지는데,  정수 X와 문자 C로 이루어져 있으며. X초가 끝난 뒤에
왼쪽(C가 'L') 또는 오른쪽(C가 'D')로 90도 방향을 회전시킨다는 뜻이다. X는 10,000 이하의 양의 정수이며, 
방향 전환 정보는 X가 증가하는 순으로 주어진다.

예제 입력
>>
6 보드 사이즈
3 사과 수
3 4 <행, 열>
2 5
5 3
3
3 D
15 L
17 D

예제 출력
>>
9

게임이 끝나는 시간 출력
*/



class Baam {

    vector<vector<int>> bMap;
    int N = 0, K = 0;
    vector<pair<int, int>> applePos;
    int L = 0;
    vector<pair<int, int>> actionQueue;

    void Input() // 입력을 받는다.
    {
        scanf_s("%d %d", &N, &K);
        for (int i = 0; i < K; ++i)
        {
            int x, y;
            scanf_s("%d %d", &x, &y);
            applePos.push_back(pair<int, int>(x, y));
        }
        scanf_s("%d", &L);
        for (int i = 0; i < L; ++i)
        {
            int X, C;
            scanf_s("%d %d", &X, &C);
            actionQueue.push_back(pair<int, int>(X, C));
        }

        // 초기화
        for (int j=0; j <= N + 1; j++)
        {
            vector<int> row;
            for (int i=0; i <= N + 1; i++)
            {
                if (j == 0 || i == 0 || j == N + 1 || i == N + 1)
                {
                    row.push_back(i);
                }
            }
            bMap.push_back(row);
        }
    }

    void Solve() 
    {
        
    }

    void DoSelf()
    {
        Input();
        Solve();
    }
};
