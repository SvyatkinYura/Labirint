#include <iostream>
#include "Libs\\TXLib.h"
#include "Libs\\wall.cpp"
#include "Libs\\Menu.cpp"
#include "Libs\\road.cpp"
using namespace std;


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

    massButt();

    HDC kart = NULL;

    int x;
    int y;
    bool risovat = false;

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txSetFillColor(TX_BLACK);
        txClear();

        Wall w[1];

        w[0] = {200, 200};

        Road r[1];

        r[0] = {300, 300};

        txSetColour(RGB(0, 0, 0), 1);
        txSetFillColour(RGB(255, 255, 255));
        txSelectFont("Times New Roman", 25);
        for (int Button_number = 0; Button_number < KOLICHESTVO_KNOPOK; Button_number++)
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
                    kart = txLoadImage(""); // H Y )|( H A  K A P T U H K A
                }
                if (Button_number == 1)
                {
                    drawMouseRoad(txMouseX(), txMouseY());
                    drawRoad(r[0]);
                    kart = txLoadImage(""); // H Y )|( H A  K A P T U H K A
                }
            }
        }

        if(txMouseButtons() & 1
           && txMouseX() > 150)
        {
            
            risovat = true;
            x = txMouseX();
            y = txMouseY();
        }

        if (risovat)
        {
            txBitBlt(txDC(),x,y,800,620,kart,0,0);
        }

        txSleep (10);
        txEnd();
    }
    return 0;
}
