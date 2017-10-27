#include <iostream>
#include "TXLib.h"
#include "wall.cpp"
#include "road.cpp"
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

void drawMouseWall(int x, int y)
{
    txSetColor(RGB(128, 128, 128));
    txSetFillColor(RGB(128, 128, 128));
    txRectangle(x - 22, y - 22, x + 22, y + 22);
}

void drawMouseRoad(int x, int y)
{
    txSetColor(RGB (100, 0, 0));
    txSetFillColor(RGB (100, 0, 0));
    txRectangle(x - 20, y - 20, x + 20, y + 20);
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

        b[0] = {0, 0,   "Стена"};
        b[1] = {0, 50,  "Дорога"};
        b[2] = {0, 100, "Главный герой"};
        b[3] = {0, 150, "Вентиляция"};
        b[4] = {0, 200, "Бочка"};
        b[5] = {0, 250, "Ловушка"};
        b[6] = {0, 300, "Кнопка"};
        b[7] = {0, 350, "Охранник"};
        b[8] = {0, 400, "Воидзона"};

        Wall w[1];

        w[0] = {200, 200};

        Road r[1];

        r[0] = {300, 300};


        txSetColour(RGB(0, 0, 0), 1);
        txSetFillColour(RGB(255, 255, 255));
        txSelectFont("Times New Roman", 25);
        for (int Button_number = 0; Button_number < 9; Button_number++)
        {
            dButton(b[Button_number]);
            if (txMouseButtons() & 1
            && txMouseX() >= b[Button_number].x
            && txMouseX() <= b[Button_number].x + 150
            && txMouseY() >= b[Button_number].y
            && txMouseY() <= b[Button_number].y + 50)
            {
                if (Button_number == 0)
                {
                    drawMouseWall(txMouseX(), txMouseY());
                    drawWall(w[0]);
                }
                if (Button_number == 1)
                {
                    drawMouseRoad(txMouseX(), txMouseY());
                    drawRoad(r[0]);
                }
            }
        }

        txSleep (10);
        txEnd();
    }
    return 0;
}

