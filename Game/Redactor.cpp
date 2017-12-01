#include <iostream>
#include <math.h>
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
    int nomer_kartinki = 1;
    double pictureX;
    double pictureY;

    int picsNumber = 2000;

    //Init
    kartinka pics[picsNumber];
    for (int nomer = 0; nomer < picsNumber; nomer++)
    {
        pics[nomer].picture = NULL;
        pics[nomer].risovat = false;
    }

    massButt();
    HDC pic;

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
          
            //Saving pic into buffer
            if (txMouseButtons() & 1
            && txMouseX() >= b[Button_number].x
            && txMouseX() <= b[Button_number].x + SHIRINA_KNOPKI
            && txMouseY() >= b[Button_number].y
            && txMouseY() <= b[Button_number].y + VISOTA_KNOPKI)
            {
                for (int nomer = nomer_kartinki; nomer < picsNumber; nomer++)
                {
                    pics[nomer].picture = b[Button_number].kartinka;
                }
            }
        }


        if(txMouseButtons() & 1  && txMouseX() > SHIRINA_KNOPKI)
        {
            pics[nomer_kartinki].x = round (txMouseX() / 40) * 40;
            pics[nomer_kartinki].y = round (txMouseY() / 40) * 40;
            pics[nomer_kartinki].height = 40;
            pics[nomer_kartinki].width = 40;

            //Checking if here exists another picture
            bool many = false;
            for (int nomer = 0; nomer < nomer_kartinki; nomer++)
            {
                if ((pics[nomer_kartinki].x == pics[nomer].x &&
                     pics[nomer_kartinki].y == pics[nomer].y))
                {
                    many = true;
                }
            }

            if (!many)
            {
                pics[nomer_kartinki].risovat = true;
            }

            txSleep (10);
        }

        for (int nomer = 0; nomer < picsNumber; nomer++)
        {
            if (pics[nomer].risovat)
            {
                txBitBlt(txDC(), pics[nomer].x, pics[nomer].y, pics[nomer].width, pics[nomer].height, pics[nomer].picture, 0, 0);
                nomer_kartinki = nomer + 1;
            }
        }

        txSleep (10);
        txEnd();
    }

    for (int nomer = 0; nomer < picsNumber; nomer++)
    {
        txDeleteDC (pics[nomer].picture);
    }
    return 0;
}