#include "graphics.h"
#include<iostream>
#include<string>
#include <stdio.h>
#include <conio.h>
#include <cstdlib>

using namespace std;

#define Max 5 //so phan tu toi da cua Queue
typedef int item; //kieu du lieu

struct Queue
{
    int Front, Rear; //front: phan tu dau hang, rear: phan tu cuoi hang
    item Data[Max]; //Mang cac phan tu
    int count; //dem so phan tu cua Queue
};

void Init(Queue& Q); //khoi tao Queue rong
int Isempty(Queue Q); //kiem tra Queue rong
int Isfull(Queue Q); //kiem tra Queue day
void Push(Queue& Q, item x); //them phan tu vao cuoi hang doi
int Pop(Queue& Q); //Loai bo phan tu khoi dau hang doi
int Qfront(Queue Q); //xem thong tin phan tu dau hang doi 
void Input(Queue& Q); //Nhap 
void Output(Queue Q); //Xuat 

void Init(Queue& Q) //khoi tao Queue rong
{
    Q.Front = 0; //phan tu dau
    Q.Rear = -1; // phan tu cuoi o -1 (khong co phan tu trong Q)
    Q.count = 0; //so phan tu bang 0
}

int Isempty(Queue Q) //kiem tra Queue rong
{
    if (Q.count == 0) //so phan tu = 0 => rong
        return 1;
    return 0;
}

int Isfull(Queue Q) //kiem tra Queue day
{
    if (Q.count == Max) //so phan tu = Max => day
        return 1;
    return 0;
}

void Push(Queue& Q, item x) //them phan tu vao cuoi Queue
{
    if (Isfull(Q)) printf("Hang doi day !");
    else
    {
        Q.Data[++Q.Rear] = x; //tang Rear len va gan phan tu vao
        Q.count++; //tang so phan tu len
    }
}

int Pop(Queue& Q) //Loai bo phan tu khoi dau hang doi
{
    if (Isempty(Q)) printf("Hang doi rong !");
    else
    {
        item x = Q.Data[Q.Front];
        for (int i = Q.Front; i < Q.Rear; i++) //di chuyen cac phan tu ve dau hang
            Q.Data[i] = Q.Data[i + 1];
        Q.Rear--; // giam vi tri phan tu cuoi xuong
        Q.count--;//giam so phan tu xuong
        return x; //tra ve phan tu lay ra
    }
}
int size(Queue& Q) //Loai bo phan tu khoi dau hang doi
{
    return Q.count;
}

item peek(Queue Q) //xem thong tin phan tu dau hang
{
    if (Isempty(Q)) printf("Hang doi rong !");
    else return Q.Data[Q.Front];
}

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

void show(Queue gq, int s)
{
    char s1[] = "Front";
    Queue g = gq;
    system("cls");
    taoKhung();
    setcolor(8);

    //Front
    rectangle(320 + size(g) * 100, 450, 380 + size(g) * 100, 500);
    setcolor(9);
    line(310 + size(g) * 100, 450, 350 + size(g) * 100, 420);
    line(390 + size(g) * 100, 450, 350 + size(g) * 100, 420);
    line(310 + size(g) * 100, 450, 390 + size(g) * 100, 450);
    drawText(330 + size(g) * 100, 460, s1);

    for (int j = 0; j < size(gq); j++)
    {
        char temp[5];
        int n = peek(g);
        int t = 0;
        dem(n, t);
        for (int i = t - 1; i >= 0; i--)
        {
            temp[i] = (n % 10) + 48;
            n = n / 10;
        }
        temp[t] = '\0';
        drawText(330 + (j) * 100, 330, temp);
        Pop(g);
    }

}

void kiemTra(Queue S)
{
    cout << "Chon'1' de Insert" << endl;
    cout << "Chon'2' de Delete"<<endl;
    cout << "Nhan phim bat ki de Thoat."<<endl;
    int key;
    int text;
    cin >> key;
    if (key == 1)
    {
        if (size(S) < 5)
        {
            cin >> text;
            Push(S,text);

            show(S, size(S));
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
        if (size(S) > 0)
        {
            Pop(S);
            setcolor(2);
            show(S, size(S));
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
    Queue S;
    Init(S);
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