#include "TXLib.h"
#include "const.cpp"

struct Button {
    int x,y;
    const char* text;
    const char* znak;
    HDC kartinka;
};

Button b[KOLICHESTVO_KNOPOK];

void dButton(Button b)
{
    txSetColor(RGB(0, 0, 0), 1);
    txSetFillColor(RGB(255, 255, 255));
    txSelectFont("Times New Roman", 25);
    txRectangle(b.x, b.y, b.x + SHIRINA_KNOPKI , b.y + VISOTA_KNOPKI);
    txTextOut(b.x + 10, b.y + 15, b.text);
}

void massButt()
{
    b[0] = {0, 0,   "wall", "#", txLoadImage("Pictures\\stenka.bmp")};
    b[1] = {0, 40,  "road", ".", txLoadImage("Pictures\\doroga.bmp")};
    b[2] = {0, 80, "hero", "h", txLoadImage("Pictures\\corvo.bmp")};
    b[3] = {0, 120, "knife", "s", txLoadImage("Pictures\\noj.bmp")};
    b[4] = {0, 160, "ventilation", "v", txLoadImage("Pictures\\vint.bmp")};
    b[5] = {0, 200, "barrel", "b", txLoadImage("Pictures\\barrel.bmp")};
    b[6] = {0, 240, "trap", "t", txLoadImage("Pictures\\trap.bmp")};
    b[7] = {0, 280, "button", "B", txLoadImage("Pictures\\button.bmp")};
    b[8] = {0, 320, "guard", "g", txLoadImage("Pictures\\guard.bmp")};
    b[9] = {0, 360, "void", "@", txLoadImage("Pictures\\void.bmp")};
}
