#pragma once
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class ModelWindow {
private:
    string title;
    int x, y;           // координати лівого верхнього кута
    int width, height;  // розміри
    string color;
    bool isVisible;
    bool hasBorder;

    static const int SCREEN_WIDTH = 1920;
    static const int SCREEN_HEIGHT = 1080;

    bool isWithinScreen(int newX, int newY, int newWidth, int newHeight) const;

public:
    // Конструктори
    ModelWindow(string t, int posX, int posY, int w, int h, string col, bool visible = true, bool border = true);
    ModelWindow(string t, int w, int h);
    ModelWindow(const ModelWindow& other);

    // ПЕРЕВАНТАЖЕНІ ОПЕРАТОРИ:

    // 1. Оператор присвоєння =
    ModelWindow& operator=(const ModelWindow& other);

    // 2. Оператор порівняння ==
    bool operator==(const ModelWindow& other) const;

    // 3. Оператори пересування +=
    ModelWindow& operator+=(int delta); // пересування по горизонталі
    ModelWindow& operator-=(int delta); // пересування по вертикалі (від'ємне)

    // 4. Оператор виводу <<
    friend ostream& operator<<(ostream& os, const ModelWindow& window);

    // Основні методи (залишаються)
    void moveHorizontal(int deltaX);
    void moveVertical(int deltaY);
    void resize(int newWidth, int newHeight);
    void setWidth(int newWidth);
    void setHeight(int newHeight);
    void setColor(string newColor);
    void toggleVisibility();
    void toggleBorder();

    string getTitle() const;
    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;
    string getColor() const;
    bool getVisibility() const;
    bool getBorderState() const;

    void display() const;
};
