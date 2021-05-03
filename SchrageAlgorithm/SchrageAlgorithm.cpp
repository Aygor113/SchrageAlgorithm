#include <iostream>
#include <fstream>
using namespace std;

int Schrage(int N, int*R, int*P, int*Q, int*X)
{
    int F[100];
    for (int i = 0; i < N; i++)
    {
        F[i] = 0;
    }
    int t = 0, cmax = 0;
    for (int n = 0; n < N; n++)
    {
        // 1. wybor zadan dostepnych
        int k = 0;
        for (int i = 0; i < N; i++)
        {
            if ((R[i] <= t) && (F[i] != 2))
            {
                F[i] = 1;
                k++;
            }
        }
        if (k == 0)
        {
            t = 99999999;
            for (int i = 0; i < N; i++)
            {
                if (F[i] == 0)
                {
                    t = min(t, R[i]);
                }
            }
            for (int i = 0; i < N; i++)
            {
                if ((R[i] <= t) && (F[i] != 2))
                {
                    F[i] = 1;
                }
            }

        }
        int maxQ = -1;
        for (int i = 0; i < N; i++)
        {
            if ((F[i] == 1) && (maxQ < Q[i]))
            {
            k = i;
            maxQ = Q[i];
            }
        }
        X[n] = k;
        F[k] = 2;
        t += P[k];
        cmax = max(cmax, t + Q[k]);
    }
    return cmax;
}
int main()
{
    int N, R[100], P[100], Q[100], X[100];
    ifstream f("data.txt");
    string s;
    while (s != "data.000:") f >> s;
    f >> N;
    for (int i = 0; i < N; i++) f >>R[i]>>P[i]>>Q[i];
    f.close();

    int c = Schrage(N, R, P, Q, X);
    cout << "Cmax: " << c << endl;
    for (int i = 0; i < N; i++) cout << X[i] + 1 << " ";
    cin.get();
    return 0;
}