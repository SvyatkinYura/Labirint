#include <iostream>
#include "TXLib.h"
using namespace std;

void dButton(int x, int y, const char* text)
{
    txSetColor(RGB(0, 0, 0), 1);
    txSetFillColor(RGB(255, 255, 255));
    txSelectFont("Times New Roman", 25);
    txRectangle(x, y, x + 150 , y + 50);
    txTextOut(x + 10, y + 15, text);
}

int main()
{
    txCreateWindow(800, 600);

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txSetFillColor(TX_BLACK);
        txClear();

        txSetColour(RGB(0, 0, 0), 1);
        txSetFillColour(RGB(255, 255, 255));
        txSelectFont("Times New Roman", 25);
        dButton(0, 0, "Стена");
        dButton(0, 50, "Дорога");
        dButton(0, 100, "Главный герой");
        dButton(0, 150, "Вентиляция");
        dButton(0, 200, "Бочка");
        dButton(0, 250, "Ловушка");
        dButton(0, 300, "Кнопка");
        dButton(0, 350, "Охранник");
        dButton(0, 400, "Воидзона");

        txSleep (10);
        txEnd();
    }
    return 0;
}
