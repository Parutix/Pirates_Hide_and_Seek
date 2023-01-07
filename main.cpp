#include <iostream>
#include <graphics.h>
#include <winbgim.h>
#include <time.h>

using namespace std;

int verifAfis = 1, piesePlasate, gameFail = 0;
int SS[4][4], SD[4][4], JS[4][4], JD[4][4], N[5], punePiesa[5][5][5];
bool zone[5];

void InitBoard()
{
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
        {
            SS[i][j] = 0;
            SD[i][j] = 0;
            JS[i][j] = 0;
            JD[i][j] = 0;
        }
    //Sus stanga
    SS[1][2] = 1;
    SS[1][3] = 2;
    SS[2][1] = 3;
    SS[2][3] = 4;
    SS[3][1] = 5;
    //sus dreapta
    SD[1][1] = 1;
    SD[1][2] = 6;
    SD[2][2] = 3;
    SD[2][3] = 4;
    SD[3][1] = 5;
    SD[3][2] = 8;
    //jos stanga
    JS[1][1] = 1;
    JS[1][2] = 2;
    JS[1][3] = 8;
    JS[2][1] = 3;
    JS[2][2] = 4;
    JS[3][1] = 8;
    JS[3][2] = 6;
    JS[3][3] = 7;
    //jos dreapta
    JD[2][1] = 6;
    JD[2][2] = 1;
    JD[2][3] = 7;
    JD[3][1] = 3;
    JD[3][2] = 8;
    JD[3][3] = 4;
    //Sus stanga

}
int P1[4][4], P2[4][4], P3[4][4], P4[4][4];
void InitPieces()
{
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
        {
            P1[i][j] = 1;
            P2[i][j] = 1;
            P3[i][j] = 1;
            P4[i][j] = 1;
        }
    P1[1][2] = 0;
    P1[2][2] = 0;
    P2[1][2] = 0;
    P2[3][2] = 0;
    P3[1][3] = 0;
    P3[3][2] = 0;
    P4[1][3] = 0;
    P4[3][1] = 0;


}
void Afisare()
{
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
            cout << SS[i][j] << ' ';
        for (int o = 1; o <= 3; o++)
            cout << SD[i][o] << ' ';
        cout << endl;
    }
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
            cout << JS[i][j] << ' ';
        for (int o = 1; o <= 3; o++)
            cout << JD[i][o] << ' ';
        cout << endl;
    }
}
int d1, d2, d3, d4;
void GenerareDirectii()
{
    int poz, k = 0, i, temp[5];
    srand(time(0));
    d1 = rand() % 4 + 1;
    d2 = rand() % 4 + 1;
    d3 = rand() % 4 + 1;
    d4 = rand() % 4 + 1;
    for (i = 1; i <= 4; i++)
    {
        N[i] = 0;
        temp[i] = 0;
    }
    srand(time(0));
    for (i = 0; i < 4; i++)
    {
        temp[i + 1] = rand() % (4 - i) + 1;
    }
    N[temp[1]] = 1;
    for (i = 1; i <= 4; i++)
    {
        if (N[i] == 0)
        {
            k++;
            if (k == temp[2])
                N[i] = 2;
        }
    }
    k = 0;
    for (i = 1; i <= 4; i++)
        if (N[i] == 0)
        {
            k++;
            if (k == temp[3])
                N[i] = 3;
        }
    for (i = 1; i <= 4; i++)
        if (N[i] == 0)
            N[i] = 4;



}
int I[10], Ic[9];
void afisareProvocare()
{
    int i, s = 1;
    for (i = 1; i <= 8; i++)
        if (I[i] != 0)
            s = s + I[i];

    rectangle(25, 20, 100, 670);
    if (d3 == 1)
        readimagefile("d3=1.jpg", 25, 10, 100, 85);
    if (d3 == 2)
        readimagefile("d3=2.jpg", 25, 10, 100, 85);
    if (d3 == 3)
        readimagefile("d3=3.jpg", 25, 10, 100, 85);
    if (d3 == 4)
        readimagefile("d3=4.jpg", 25, 10, 100, 85);
    int k = 1;
    for (i = 1; i <= 8; i++)
    {
        Ic[i] = I[i];
    }
    if (Ic[1] != 0)
    {
        for (i = 1; i <= Ic[1]; i++)
        {
            k++;
            readimagefile("1.gif", 25, 10 + 75 * (k - 1), 100, 10 + 75 * k);
        }
    }
    if (Ic[2] != 0)
    {
        for (i = 1; i <= Ic[2]; i++)
        {
            k++;
            readimagefile("2.gif", 25, 10 + 75 * (k - 1), 100, 10 + 75 * k);
        }
    }
    if (Ic[3] != 0)
    {
        for (i = 1; i <= Ic[3]; i++)
        {
            k++;
            readimagefile("3.gif", 25, 10 + 75 * (k - 1), 100, 10 + 75 * k);
        }
    }
    if (Ic[4] != 0)
    {
        for (i = 1; i <= Ic[4]; i++)
        {
            k++;
            readimagefile("4.gif", 25, 10 + 75 * (k - 1), 100, 10 + 75 * k);
        }
    }
    if (Ic[5] != 0)
    {
        for (i = 1; i <= Ic[5]; i++)
        {
            k++;
            readimagefile("5.gif", 25, 10 + 75 * (k - 1), 100, 10 + 75 * k);
        }
    }
    if (Ic[6] != 0)
    {
        for (i = 1; i <= Ic[6]; i++)
        {
            k++;
            readimagefile("6.gif", 25, 10 + 75 * (k - 1), 100, 10 + 75 * k);
        }
    }
    if (Ic[7] != 0)
    {
        for (i = 1; i <= Ic[7]; i++)
        {
            k++;
            readimagefile("7.gif", 25, 10 + 75 * (k - 1), 100, 10 + 75 * k);
        }
    }
    if (Ic[8] != 0)
    {
        for (i = 1; i <= Ic[8]; i++)
        {
            k++;
            readimagefile("8.gif", 25, 10 + 75 * (k - 1), 100, 10 + 75 * k);
        }
    }
}

void GenerareProvocare(int dir, int A[4][4], int poz)
{
    int i, j;
    if (dir == 1 && poz == 1)
    {
        for (i = 1; i <= 3; i++)
            for (j = 1; j <= 3; j++)
            {
                if (A[i][j] == 1)
                    SS[i][j] = 0;
            }

    }
    if (dir == 1 && poz == 2)
    {
        for (i = 1; i <= 3; i++)
            for (j = 1; j <= 3; j++)
            {
                if (A[i][j] == 1)
                    SD[i][j] = 0;
            }
    }
    if (dir == 1 && poz == 3)
    {
        for (i = 1; i <= 3; i++)
            for (j = 1; j <= 3; j++)
            {
                if (A[i][j] == 1)
                    JS[i][j] = 0;
            }
    }
    if (dir == 1 && poz == 4)
    {
        for (i = 1; i <= 3; i++)
            for (j = 1; j <= 3; j++)
            {
                if (A[i][j] == 1)
                    JD[i][j] = 0;
            }
    }
    if (dir == 2 && poz == 1)
    {
        for (i = 1; i <= 3; i++)
            for (j = 1; j <= 3; j++)
            {
                if (A[4 - j][i] == 1)
                    SS[i][j] = 0;
            }
    }
    if (dir == 2 && poz == 2)
    {
        for (i = 1; i <= 3; i++)
            for (j = 1; j <= 3; j++)
            {
                if (A[4 - j][i] == 1)
                    SD[i][j] = 0;
            }
    }
    if (dir == 2 && poz == 3)
    {
        for (i = 1; i <= 3; i++)
            for (j = 1; j <= 3; j++)
            {
                if (A[4 - j][i] == 1)
                    JS[i][j] = 0;
            }
    }
    if (dir == 2 && poz == 4)
    {
        for (i = 1; i <= 3; i++)
            for (j = 1; j <= 3; j++)
            {
                if (A[4 - j][i] == 1)
                    JD[i][j] = 0;
            }
    }
    if (dir == 3 && poz == 1)
    {
        for (i = 1; i <= 3; i++)
            for (j = 1; j <= 3; j++)
            {
                if (A[4 - i][4 - j] == 1)
                    SS[i][j] = 0;
            }
    }
    if (dir == 3 && poz == 2)
    {
        for (i = 1; i <= 3; i++)
            for (j = 1; j <= 3; j++)
            {
                if (A[4 - i][4 - j] == 1)
                    SD[i][j] = 0;
            }
    }
    if (dir == 3 && poz == 3)
    {
        for (i = 1; i <= 3; i++)
            for (j = 1; j <= 3; j++)
            {
                if (A[4 - i][4 - j] == 1)
                    JS[i][j] = 0;
            }
    }
    if (dir == 3 && poz == 4)
    {
        for (i = 1; i <= 3; i++)
            for (j = 1; j <= 3; j++)
            {
                if (A[4 - i][4 - j] == 1)
                    JD[i][j] = 0;
            }
    }
    if (dir == 4 && poz == 1)
    {
        for (i = 1; i <= 3; i++)
            for (j = 1; j <= 3; j++)
            {
                if (A[j][4 - i] == 1)
                    SS[i][j] = 0;
            }
    }
    if (dir == 4 && poz == 2)
    {
        for (i = 1; i <= 3; i++)
            for (j = 1; j <= 3; j++)
            {
                if (A[j][4 - i] == 1)
                    SD[i][j] = 0;
            }
    }
    if (dir == 4 && poz == 3)
    {
        for (i = 1; i <= 3; i++)
            for (j = 1; j <= 3; j++)
            {
                if (A[j][4 - i] == 1)
                    JS[i][j] = 0;
            }
    }
    if (dir == 4 && poz == 4)
    {
        for (i = 1; i <= 3; i++)
            for (j = 1; j <= 3; j++)
            {
                if (A[j][4 - i] == 1)
                    JD[i][j] = 0;
            }
    }
}

void ResetGame()
{
    int i, j, k;
    verifAfis = 1;
    piesePlasate = 0;
    for(i = 0; i <= 4; ++i)
        zone[i] = false;
    for(i = 1; i <= 4; ++i)
    {
        for(j = 1; j <= 4; ++j)
        {
            for(k = 1; k <= 4; ++k)
                punePiesa[i][j][k] = 0;
        }
    }
}

void ReturnareProvocare()
{
    int i, j;
    for (i = 1; i <= 4; i++)
    {
        if (N[1] == i)
            GenerareProvocare(d1, P1, i);
        if (N[2] == i)
            GenerareProvocare(d2, P2, i);
        if (N[3] == i)
            GenerareProvocare(d3, P3, i);
        if (N[4] == i)
            GenerareProvocare(d4, P4, i);
    }


    for (i = 0; i <= 8; i++)
        I[i] = 0;
    for (i = 1; i <= 3; i++)
        for (j = 1; j <= 3; j++)
        {
            I[SS[i][j]]++;
            I[SD[i][j]]++;
            I[JS[i][j]]++;
            I[JD[i][j]]++;
        }
    for (i = 1; i <= 8; i++)
        if (I[i] != 0)
        {
            cout << i << ' ' << I[i];
            cout << endl;
        }
    cout << d3 << endl;

}
void createButton(int left, int top, int right, int bottom)
{
    setfillstyle(1, 7);
    rectangle(left, top, right, bottom);
    floodfill(left + 1, top + 1, WHITE);
}

int verifyClick(int left, int top, int right, int bottom, int mX, int mY)
{
    if (mX >= left && mX <= right && mY >= top && mY <= bottom) return 1;
    return 0;
}

int verifyClickDirectie()
{
    bool ok = false;
    int x, y;
    while (!ok)
    {
        getmouseclick(WM_LBUTTONDOWN, x, y);
        if (verifyClick(800, 400, 850, 499, x, y))
        {
            return 1;
        }
        if (verifyClick(850, 500, 950, 549, x, y))
        {
            return 2;
        }
        if (verifyClick(800, 550, 850, 649, x, y))
        {
            return 3;
        }
        if (verifyClick(700, 500, 800, 549, x, y))
        {
            return 4;
        }
    }
}

int verifyClickZone()
{
    bool ok = false;
    int x, y;
    while (!ok)
    {
        getmouseclick(WM_LBUTTONDOWN, x, y);
        if (verifyClick(180, 100, 400, 340, x, y))
        {
            return 1;
        }
        if (verifyClick(400, 100, 630, 340, x, y))
        {
            return 2;
        }
        if (verifyClick(180, 360, 400, 600, x, y))
        {
            return 3;
        }
        if (verifyClick(400, 360, 630, 600, x, y))
        {
            return 4;
        }
    }
}

int verificareSolutie()
{
    //d1,d2,d3,d4,N[]=i unde i e pozitia
    int dir[5], i;
    dir[1] = d1;
    dir[2] = d2;
    dir[3] = d3;
    dir[4] = d4;
    //  for (i = 1; i <= 4; i++)
    // {
    if (punePiesa[2][N[2]][1] == 1)
        punePiesa[2][N[2]][3] = 1;
    if (punePiesa[2][N[2]][2] == 1)
        punePiesa[2][N[2]][4] = 1;
    if (punePiesa[2][N[2]][3] == 1)
        punePiesa[2][N[2]][1] = 1;
    if (punePiesa[2][N[2]][4] == 1)
        punePiesa[2][N[2]][2] = 1;
    if (punePiesa[4][N[4]][3] == 1)
        punePiesa[4][N[4]][1] = 1;
    if (punePiesa[4][N[4]][4] == 1)
        punePiesa[4][N[4]][2] = 1;
    if (punePiesa[4][N[4]][1] == 1)
        punePiesa[4][N[4]][3] = 1;
    if (punePiesa[4][N[4]][2] == 1)
        punePiesa[4][N[4]][4] = 1;


    // }
    for (i = 1; i <= 4; i++)
        if (!punePiesa[i][N[i]][dir[i]])
            return 0;
    return 1;

}

void desenarePiesa()
{
    if (punePiesa[1][1][1])
    {
        readimagefile("piesa1.gif", 183, 108, 391, 336);
    }
    if (punePiesa[2][1][1])
    {
        readimagefile("piesa2.gif", 183, 108, 391, 336);
    }
    if (punePiesa[3][1][1])
    {
        readimagefile("piesa3.gif", 183, 108, 391, 336);
    }
    if (punePiesa[4][1][1])
    {
        readimagefile("piesa4.gif", 183, 108, 391, 336);
    }

    //1
    if (punePiesa[1][1][2])
    {
        readimagefile("piesa1D.gif", 183, 108, 391, 336);
    }
    if (punePiesa[2][1][2])
    {
        readimagefile("piesa2D.gif", 183, 108, 391, 336);
    }
    if (punePiesa[3][1][2])
    {
        readimagefile("piesa3D.gif", 183, 108, 391, 336);
    }
    if (punePiesa[4][1][2])
    {
        readimagefile("piesa4D.gif", 183, 108, 391, 336);
    }
    //2
    if (punePiesa[1][1][3])
    {
        readimagefile("piesa1J.gif", 183, 108, 391, 336);
    }
    if (punePiesa[2][1][3])
    {
        readimagefile("piesa2J.gif", 183, 108, 391, 336);
    }
    if (punePiesa[3][1][3])
    {
        readimagefile("piesa3J.gif", 183, 108, 391, 336);
    }
    if (punePiesa[4][1][3])
    {
        readimagefile("piesa4J.gif", 183, 108, 391, 336);
    }
    //3
    if (punePiesa[1][1][4])
    {
        readimagefile("piesa1S.gif", 183, 108, 391, 336);
    }
    if (punePiesa[2][1][4])
    {
        readimagefile("piesa2S.gif", 183, 108, 391, 336);
    }
    if (punePiesa[3][1][4])
    {
        readimagefile("piesa3S.gif", 183, 108, 391, 336);
    }
    if (punePiesa[4][1][4])
    {
        readimagefile("piesa4S.gif", 183, 108, 391, 336);
    }
    //4
    if (punePiesa[1][2][1])
    {
        readimagefile("piesa1.gif", 416, 108, 624, 336);
    }
    if (punePiesa[2][2][1])
    {
        readimagefile("piesa2.gif", 416, 108, 624, 336);
    }
    if (punePiesa[3][2][1])
    {
        readimagefile("piesa3.gif", 416, 108, 624, 336);
    }
    if (punePiesa[4][2][1])
    {
        readimagefile("piesa4.gif", 416, 108, 624, 336);
    }

    //1
    if (punePiesa[1][2][2])
    {
        readimagefile("piesa1D.gif", 416, 108, 624, 336);
    }
    if (punePiesa[2][2][2])
    {
        readimagefile("piesa2D.gif", 416, 108, 624, 336);
    }
    if (punePiesa[3][2][2])
    {
        readimagefile("piesa3D.gif", 416, 108, 624, 336);
    }
    if (punePiesa[4][2][2])
    {
        readimagefile("piesa4D.gif", 416, 108, 624, 336);
    }
    //2
    if (punePiesa[1][2][3])
    {
        readimagefile("piesa1J.gif", 416, 108, 624, 336);
    }
    if (punePiesa[2][2][3])
    {
        readimagefile("piesa2J.gif", 416, 108, 624, 336);
    }
    if (punePiesa[3][2][3])
    {
        readimagefile("piesa3J.gif", 416, 108, 624, 336);
    }
    if (punePiesa[4][2][3])
    {
        readimagefile("piesa4J.gif", 416, 108, 624, 336);
    }
    //3
    if (punePiesa[1][2][4])
    {
        readimagefile("piesa1S.gif", 416, 108, 624, 336);
    }
    if (punePiesa[2][2][4])
    {
        readimagefile("piesa2S.gif", 416, 108, 624, 336);
    }
    if (punePiesa[3][2][4])
    {
        readimagefile("piesa3S.gif", 416, 108, 624, 336);
    }
    if (punePiesa[4][2][4])
    {
        readimagefile("piesa4S.gif", 416, 108, 624, 336);
    }
    //4
    if (punePiesa[1][3][1])
    {
        readimagefile("piesa1.gif", 183, 364, 391, 592);
    }
    if (punePiesa[2][3][1])
    {
        readimagefile("piesa2.gif", 183, 364, 391, 592);
    }
    if (punePiesa[3][3][1])
    {
        readimagefile("piesa3.gif", 183, 364, 391, 592);
    }
    if (punePiesa[4][3][1])
    {
        readimagefile("piesa4.gif", 183, 364, 391, 592);
    }

    //1
    if (punePiesa[1][3][2])
    {
        readimagefile("piesa1D.gif", 183, 364, 391, 592);
    }
    if (punePiesa[2][3][2])
    {
        readimagefile("piesa2D.gif", 183, 364, 391, 592);
    }
    if (punePiesa[3][3][2])
    {
        readimagefile("piesa3D.gif", 183, 364, 391, 592);
    }
    if (punePiesa[4][3][2])
    {
        readimagefile("piesa4D.gif", 183, 364, 391, 592);
    }
    //2
    if (punePiesa[1][3][3])
    {
        readimagefile("piesa1J.gif", 183, 364, 391, 592);
    }
    if (punePiesa[2][3][3])
    {
        readimagefile("piesa2J.gif", 183, 364, 391, 592);
    }
    if (punePiesa[3][3][3])
    {
        readimagefile("piesa3J.gif", 183, 364, 391, 592);
    }
    if (punePiesa[4][3][3])
    {
        readimagefile("piesa4J.gif", 183, 364, 391, 592);
    }
    //3
    if (punePiesa[1][3][4])
    {
        readimagefile("piesa1S.gif", 183, 364, 391, 592);
    }
    if (punePiesa[2][3][4])
    {
        readimagefile("piesa2S.gif", 183, 364, 391, 592);
    }
    if (punePiesa[3][3][4])
    {
        readimagefile("piesa3S.gif", 183, 364, 391, 592);
    }
    if (punePiesa[4][3][4])
    {
        readimagefile("piesa4S.gif", 183, 364, 391, 592);
    }
    //4
    if (punePiesa[1][4][1])
    {
        readimagefile("piesa1.gif", 416, 364, 624, 592);
    }
    if (punePiesa[2][4][1])
    {
        readimagefile("piesa2.gif", 416, 364, 624, 592);
    }
    if (punePiesa[3][4][1])
    {
        readimagefile("piesa3.gif", 416, 364, 624, 592);
    }
    if (punePiesa[4][4][1])
    {
        readimagefile("piesa4.gif", 416, 364, 624, 592);
    }

    //1
    if (punePiesa[1][4][2])
    {
        readimagefile("piesa1D.gif", 416, 364, 624, 592);
    }
    if (punePiesa[2][4][2])
    {
        readimagefile("piesa2D.gif", 416, 364, 624, 592);
    }
    if (punePiesa[3][4][2])
    {
        readimagefile("piesa3D.gif", 416, 364, 624, 592);
    }
    if (punePiesa[4][4][2])
    {
        readimagefile("piesa4D.gif", 416, 364, 624, 592);
    }
    //2
    if (punePiesa[1][4][3])
    {
        readimagefile("piesa1J.gif", 416, 364, 624, 592);
    }
    if (punePiesa[2][4][3])
    {
        readimagefile("piesa2J.gif", 416, 364, 624, 592);
    }
    if (punePiesa[3][4][3])
    {
        readimagefile("piesa3J.gif", 416, 364, 624, 592);
    }
    if (punePiesa[4][4][3])
    {
        readimagefile("piesa4J.gif", 416, 364, 624, 592);
    }
    //3
    if (punePiesa[1][4][4])
    {
        readimagefile("piesa1S.gif", 416, 364, 624, 592);
    }
    if (punePiesa[2][4][4])
    {
        readimagefile("piesa2S.gif", 416, 364, 624, 592);
    }
    if (punePiesa[3][4][4])
    {
        readimagefile("piesa3S.gif", 416, 364, 624, 592);
    }
    if (punePiesa[4][4][4])
    {
        readimagefile("piesa4S.gif", 416, 364, 624, 592);
    }
    //4


}

void JocStart()
{
    int i, s = 1;
    readimagefile("background.jpg", 0, 0, 1000, 700);
    readimagefile("masaJoc.gif", 130, 50, 680, 650);

    afisareProvocare();
    desenarePiesa();
    if (verifAfis % 2 != 0) readimagefile("piesa1.gif", 685, 50, 835, 200);
    if (verifAfis % 3 != 0) readimagefile("piesa2.gif", 840, 50, 990, 200);
    if (verifAfis % 5 != 0) readimagefile("piesa3.gif", 685, 240, 835, 390);
    if (verifAfis % 7 != 0) readimagefile("piesa4.gif", 840, 240, 990, 390);
    if (piesePlasate == 4)
    {
        if (verificareSolutie() == 1)
        {
            readimagefile("textFelicitari.gif", 715, 150, 965, 190);
            readimagefile("textCastig.gif", 715, 200, 965, 240);
            createButton(715, 390, 965, 450);
            createButton(715, 480, 965, 540);
            readimagefile("butonIesire.gif", 730, 490, 950, 530);
            readimagefile("provocareNoua.gif", 720, 400, 960, 440);
            bool ok = false;
            int x, y;
            while(!ok)
            {
                getmouseclick(WM_LBUTTONDOWN, x, y);
                if(verifyClick(715, 480, 965, 540, x, y))
                    exit(0);
                if(verifyClick(715, 390, 965, 450, x, y))
                {
                    ResetGame();
                    GenerareDirectii();
                    ReturnareProvocare();
                    JocStart();
                }
            }
        }
        else
        {
            gameFail = 1;
            ResetGame();
            JocStart();
        }
    }
    else
    {
        if(gameFail == 1)
        {
            gameFail = 0;
            readimagefile("incearca.gif", 715, 450, 965, 490);
        }
        else
        {
            readimagefile("butonAlege.gif", 715, 450, 965, 490);

        }
        bool ok = false;
        int x, y;
        while (!ok)
        {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            if (verifyClick(690, 50, 840, 200, x, y) && verifAfis % 2 != 0)
            {
                readimagefile("background.jpg", 0, 0, 1000, 700);
                readimagefile("masaJoc.gif", 130, 50, 680, 650);
                readimagefile("alegeZona.gif", 700, 100, 970, 140);
                desenarePiesa();
                afisareProvocare();
                /// prima zona - 180, 100, 400, 340
                /// a doua zona - 400, 100, 630, 340
                /// a treia zona - 180, 360, 400, 600
                /// a patra zona - 400, 360, 630, 600
                int nrZona;
                while (nrZona = verifyClickZone())
                {
                    if (zone[nrZona] == false) break;
                }
                if (zone[nrZona] == false)
                {
                    zone[nrZona] = true;
                    readimagefile("alegeDirectie.gif", 690, 230, 980, 270);
                    readimagefile("arrowup.gif", 800, 400, 850, 499);
                    readimagefile("arrowright.gif", 850, 500, 950, 549);
                    readimagefile("arrowdown.gif", 800, 550, 850, 649);
                    readimagefile("arrowleft.gif", 700, 500, 800, 549);
                    int nrDirectie = verifyClickDirectie();
                    punePiesa[1][nrZona][nrDirectie] = 1;

                    /// aici punem in joc piesa 1-nrZona-nrDirectie

                    verifAfis *= 2;
                    piesePlasate++;
                    cout << piesePlasate << "\n";
                    ok = true;
                    JocStart();
                }
            }
            if (verifyClick(850, 50, 1000, 200, x, y) && verifAfis % 3 != 0)
            {
                readimagefile("background.jpg", 0, 0, 1000, 700);
                readimagefile("masaJoc.gif", 130, 50, 680, 650);
                readimagefile("alegeZona.gif", 700, 100, 970, 140);
                desenarePiesa();
                afisareProvocare();
                int nrZona;
                while (nrZona = verifyClickZone())
                {
                    if (zone[nrZona] == false) break;
                }
                if (zone[nrZona] == false)
                {
                    zone[nrZona] = true;
                    readimagefile("alegeDirectie.gif", 690, 230, 980, 270);
                    readimagefile("arrowup.gif", 800, 400, 850, 499);
                    readimagefile("arrowright.gif", 850, 500, 950, 549);
                    readimagefile("arrowdown.gif", 800, 550, 850, 649);
                    readimagefile("arrowleft.gif", 700, 500, 800, 549);

                    int nrDirectie = verifyClickDirectie();
                    punePiesa[2][nrZona][nrDirectie] = 1;

                    /// aici punem in joc piesa 2-nrZona-nrDirectie
                    verifAfis *= 3;
                    piesePlasate++;
                    cout << piesePlasate << "\n";
                    ok = true;
                    JocStart();
                }
            }
            if (verifyClick(690, 240, 840, 390, x, y) && verifAfis % 5 != 0)
            {
                readimagefile("background.jpg", 0, 0, 1000, 700);
                readimagefile("masaJoc.gif", 130, 50, 680, 650);
                readimagefile("alegeZona.gif", 700, 100, 970, 140);
                desenarePiesa();
                afisareProvocare();
                int nrZona;
                while (nrZona = verifyClickZone())
                {
                    if (zone[nrZona] == false) break;
                }
                if (zone[nrZona] == false)
                {
                    zone[nrZona] = true;
                    readimagefile("alegeDirectie.gif", 690, 230, 980, 270);
                    readimagefile("arrowup.gif", 800, 400, 850, 499);
                    readimagefile("arrowright.gif", 850, 500, 950, 549);
                    readimagefile("arrowdown.gif", 800, 550, 850, 649);
                    readimagefile("arrowleft.gif", 700, 500, 800, 549);

                    int nrDirectie = verifyClickDirectie();
                    punePiesa[3][nrZona][nrDirectie] = 1;
                    /// aici punem in joc piesa 3-nrZona-nrDirectie

                    verifAfis *= 5;
                    piesePlasate++;
                    cout << piesePlasate << "\n";
                    ok = true;
                    JocStart();


                }
            }
            if (verifyClick(850, 240, 1000, 390, x, y) && verifAfis % 7 != 0)
            {
                ok = true;
                readimagefile("background.jpg", 0, 0, 1000, 700);
                readimagefile("masaJoc.gif", 130, 50, 680, 650);
                readimagefile("alegeZona.gif", 700, 100, 970, 140);
                desenarePiesa();
                afisareProvocare();
                int nrZona;
                while (nrZona = verifyClickZone())
                {
                    if (zone[nrZona] == false) break;
                }
                if (zone[nrZona] == false)
                {
                    zone[nrZona] = true;
                    readimagefile("alegeDirectie.gif", 690, 230, 980, 270);
                    readimagefile("arrowup.gif", 800, 400, 850, 499);
                    readimagefile("arrowright.gif", 850, 500, 950, 549);
                    readimagefile("arrowdown.gif", 800, 550, 850, 649);
                    readimagefile("arrowleft.gif", 700, 500, 800, 549);

                    int nrDirectie = verifyClickDirectie();
                    punePiesa[4][nrZona][nrDirectie] = 1;

                    /// aici punem in joc piesa 4-nrZona-nrDirectie
                    verifAfis *= 7;
                    piesePlasate++;
                    cout << piesePlasate << "\n";
                    ok = true;
                    JocStart();
                }
            }
        }
    }

}

void Reguli()
{
    readimagefile("backgroundReguli.jpg", 0, 0, 1000, 700);

    createButton(200, 600, 400, 650);
    createButton(600, 600, 800, 650);
    readimagefile("butonJoaca.gif", 220, 610, 380, 640);
    readimagefile("butonIesire.gif", 620, 610, 780, 640);
    bool ok = false;
    int x, y;
    while (!ok)
    {
        getmouseclick(WM_LBUTTONDOWN, x, y);
        if (verifyClick(600, 600, 800, 650, x, y))
        {
            exit(0);
            ok = true;
        }
        else if (verifyClick(200, 600, 400, 650, x, y))
        {
            JocStart();
            ok = true;
        }

    }

}

void buttonClick()
{
    int x, y, Ax, Ay;
    POINT cursorPosition;
    bool ok = false;
    while (!ok)
    {
        getmouseclick(WM_LBUTTONDOWN, x, y);
        GetCursorPos(&cursorPosition);
        Ax = cursorPosition.x;
        Ay = cursorPosition.y;
        if (verifyClick(650, 600, 800, 650, x, y))
        {
            exit(0);
            ok = true;
        }
        else if (verifyClick(150, 600, 300, 650, x, y))
        {
            JocStart();
            ok = true;
        }
        else if (verifyClick(400, 600, 550, 650, x, y))
        {
            Reguli();
            ok = true;
        }
    }
}

void mainMenu()
{

    initwindow(1000, 700, "Pirates Hide & Seek");
    readimagefile("background.jpg", 0, 0, 1000, 700);
    readimagefile("titlu.gif", 200, 50, 800, 100);
    createButton(150, 600, 300, 650);
    createButton(400, 600, 550, 650);
    createButton(650, 600, 800, 650);
    readimagefile("butonJoaca.gif", 170, 610, 280, 640);
    readimagefile("butonReguli.gif", 420, 610, 530, 640);
    readimagefile("butonIesire.gif", 670, 610, 780, 640);

    buttonClick();

    getch();
    closegraph();

}


int i;
int main()
{
    InitBoard();
    InitPieces();
    GenerareDirectii();
    ReturnareProvocare();
    Afisare();
    InitBoard();
    mainMenu();
    verificareSolutie();

    return 0;
}
