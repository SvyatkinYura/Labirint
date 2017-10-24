#include <iostream>
#include "TXLib.h"
using namespace std;

struct Button {
    int x,y;
    const char* text;
};

void dButton(Button b)
{
    txSetColor(RGB(0, 0, 0), 1);
    txSetFillColor(RGB(255, 255, 255));
    txSelectFont("Times New Roman", 25);
    txRectangle(b.x, b.y, b.x + 150 , b.y + 50);
    txTextOut(b.x + 10, b.y + 15, b.text);
}

int main()
{
    txCreateWindow(800, 600);

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txSetFillColor(TX_BLACK);
        txClear();

        Button b[9];

        b[0] = {0, 0, "Стена"};
        b[1] = {0, 50, "Дорога"};
        b[2] = {0, 100, "Главный герой"};
        b[3] = {0, 150, "Вентиляция"};
        b[4] = {0, 200, "Бочка"};
        b[5] = {0, 250, "Ловушка"};
        b[6] = {0, 300, "Кнопка"};
        b[7] = {0, 350, "Охранник"};
        b[8] = {0, 400, "Воидзона"};

        txSetColour(RGB(0, 0, 0), 1);
        txSetFillColour(RGB(255, 255, 255));
        txSelectFont("Times New Roman", 25);
        for (int Button_number = 0; Button_number < 9; Button_number++)
        {
            dButton(b[Button_number]);
        }

        txSleep (10);
        txEnd();
    }
    return 0;
}
