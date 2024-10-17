#include<bits/stdc++.h>
#define endl '\n'
#define pii pair<int,int>
#define vvi vector<vector<int>>
#define vi vector<int>
#define vvb vector<vector<bool>>
#define vb vector<bool>
#define pino pair<int, Node*>
#define f first
#define s second

// Felipe Lages de Lima

using namespace std;

int N, caso = 1;

bool solution(vvb tab, int i, int j);
void greed(vvb tab, int linha);
void mostra(vvb tab);

int main()
{
    cin >> N;

    vvb tab(N + 4, vb(N + 4, false));

    greed(tab, 3);

    return 0;
}

bool solution(vvb tab, int x, int y)
{
    for(int i = 3; i <= N + 2; i++)
    {
        if(tab[x][i] && i != y) return false;
        if(tab[i][y] && i != x) return false;
    }

    for(int i = 1; i <= N + 200; i++)
    {
        if(x + i > N + 2 || y + i > N + 2) break;
        if(tab[x + i][y + i]) return false;
    }

    for(int i = 1; i <= N + 200; i++)
    {
        if(x + i > N + 2 || y - i < 3) break;
        if(tab[x + i][y - i]) return false;
    }

    for(int i = 1; i <= N + 200; i++)
    {
        if(x - i < 3 || y - i < 3) break;
        if(tab[x - i][y - i]) return false;
    }

    for(int i = 1; i <= N + 200; i++)
    {
        if(x - i < 3 || y + i > N + 2) break;
        if(tab[x - i][y + i]) return false;
    }

    return true;
}

void greed(vvb tab, int linha)
{
    if(linha == N + 3) mostra(tab);

    for(int i = 3; i <= N + 2; i++)
    {
        tab[linha][i] = true;

        if(solution(tab, linha, i)) greed(tab, linha + 1);

        tab[linha][i] = false;
    }
}

void mostra(vvb tab)
{
    cout << "Caso " << caso << endl;
    caso++;

    for(int i = 3; i <= N + 2; i++)
    {
        for(int j = 3; j <= N + 2; j++) 
        {
            if(tab[i][j]) cout << 1 << ' ';
            else cout << 0 << ' ';
        }

        cout << endl;
    }

    cout << endl;
}
