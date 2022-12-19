#include "graphics.h"
#include <dos.h>
#include<string>
#include <stdio.h>
#include <conio.h>
#include <queue>

using namespace std;

void taoKhung()
{
       //REAR
    char s1[] = "Rear";
    char s2[] = "...";

    setcolor(3);
    rectangle(320, 200, 380, 250);
    setcolor(9);
    line(310, 250, 350, 270);
    line(390, 250, 350, 270);
    line(310, 250, 390, 250);
    drawText(315, 210, s1);

    // Khung
    setcolor(2);
    line(300, 300, 800, 300);
    line(300, 400, 800, 400);
    line(300, 300, 300, 400);
    line(400, 300, 400, 400);
    line(500, 300, 500, 400);
    line(600, 300, 600, 400);
    line(700, 300, 700, 400);
    line(800, 300, 800, 400);
    for (int i = 0; i < 5; i++)
    {
        rectangle(300 + i * 100, 300, 400 + i * 100, 400);
    }
    setcolor(14);
    rectangle(800, 300, 900, 400);
    drawText(830, 320, s2);
}
void dem(int n, int& t)
{
    while (n != 0)
    {
        //sau một vòng lặp thì count sẽ tăng lên 1
        t++;
        //chia lấy nguyên cho 10, cứ một lần chia thì số n sẽ có một chữ số
        n = n / 10;
    }
}

// Print the queue

void show(queue<int> gq, int size)
{
    char s1[] = "Front";
    queue<int> g = gq;
    system("cls");
    taoKhung();
    setcolor(8);

    //Front
    rectangle(320 + g.size() * 100, 450, 380 + g.size() * 100, 500);
    setcolor(9);
    line(310 + g.size() * 100, 450, 350 + g.size() * 100, 420);
    line(390 + g.size() * 100, 450, 350 + g.size() * 100, 420);
    line(310 + g.size() * 100, 450, 390 + g.size() * 100, 450);
    drawText(330 + g.size() * 100, 460, s1);

    for (int j = 0; j < gq.size(); j++)
    {
        char temp[5];
        int n = g.front();
        int t = 0;
        dem(n, t);
        for (int i = t - 1; i >= 0; i--)
        {
            temp[i] = (n % 10) + 48;
            n = n / 10;
        }
        temp[t] = '\0';
        drawText(330 + (j) * 100, 330, temp);
        g.pop();
    }

}

void kiemTra(queue<int> S)
{
    cout << "Chon'1' de Insert" << endl;
    cout << "Chon'2' de Delete"<<endl;
    cout << "Nhan phim bat ki de Thoat."<<endl;
    int key;
    int text;
    cin >> key;
    if (key == 1)
    {
        if (S.size() < 5)
        {
            cin >> text;
            S.push(text);

            show(S, S.size());
            kiemTra(S);
        }
        else
        {
            cout << "Chi co the DELETE." << endl;;
            kiemTra(S);
        }
    }
    else if (key == 2)
    {
        if (S.size() > 0)
        {
            S.pop();
            setcolor(2);
            show(S, S.size());
            kiemTra(S);
        }
        else
        {
            cout << "Hang doi Trong(NULL)." << endl;
            kiemTra(S);
        }
    }
}

int main()
{
    queue<int> S;
    initgraph();
    //Comment
    char s1[] = "Press any key to view the program.";
    drawText(400, 50, s1);

    //Dong comment
    line(100, 500, 900, 500);
    //Noi dung
    int temp = 0;
    _getch();
    system("cls");
    taoKhung();

    kiemTra(S);
    return 0;
}