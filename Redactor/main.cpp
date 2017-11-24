#include <iostream>
#include "Libs\\TXLib.h"
#include "Libs\\wall.cpp"
#include "Libs\\Menu.cpp"
#include "Libs\\road.cpp"
#include "Libs\\massivs.cpp"
#include "Libs\\const.cpp"

void drawMouseWall(int x, int y)
{
    txSetColor(RGB(128, 128, 128));
    txSetFillColor(RGB(128, 128, 128));
    txRectangle(x - SHIRINA_OBJ, y - SHIRINA_OBJ, x + SHIRINA_OBJ, y + SHIRINA_OBJ);
}

void drawMouseRoad(int x, int y)
{
    txSetColor(RGB (100, 0, 0));
    txSetFillColor(RGB (100, 0, 0));
    txRectangle(x - SHIRINA_OBJ, y - SHIRINA_OBJ, x + SHIRINA_OBJ, y + SHIRINA_OBJ);
}

int main()
{
    txCreateWindow(800, 600);

    kartinka pics[100];
    pics[0].picture = NULL;
    pics[0].risovat = false;

    massButt();

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txSetFillColor(TX_BLACK);
        txClear();

        txSetColour(RGB(0, 0, 0), 1);
        txSetFillColour(RGB(255, 255, 255));
        txSelectFont("Times New Roman", 25);
        for (int Button_number = 0; Button_number < KOLICHESTVO_KNOPOK; Button_number++)
        {
            dButton(b[Button_number]);
            if (txMouseButtons() & 1
            && txMouseX() >= b[Button_number].x
            && txMouseX() <= b[Button_number].x + SHIRINA_KNOPKI
            && txMouseY() >= b[Button_number].y
            && txMouseY() <= b[Button_number].y + VISOTA_KNOPKI)
            {
                if (Button_number == 0)
                {
                    pics[0].picture = txLoadImage("stenka.bmp");
                }
                else if (Button_number == 1)
                {
                    pics[0].picture = txLoadImage("doroga.bmp");
                }
            }
        }

        if(txMouseButtons() & 1
           && txMouseX() > SHIRINA_KNOPKI)
        {
            pics[0].risovat = true;
            pics[0].x = txMouseX();
            pics[0].y = txMouseY();
            pics[0].height = 150;
            pics[0].width = 150;
        }

        if (pics[0].risovat)
        {
            txBitBlt(txDC(), pics[0].x, pics[0].y, pics[0].width, pics[0].height, pics[0].picture, 0, 0);
        }

        txSleep (10);
        txEnd();
    }
    return 0;
}
