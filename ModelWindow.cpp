#include "ModelWindow.h"

// Конструктори (залишаються без змін)
ModelWindow::ModelWindow(string t, int posX, int posY, int w, int h, string col, bool visible, bool border) {
    if (w <= 0 || h <= 0) throw invalid_argument("Розміри вікна повинні бути додатніми");
    title = t; x = posX; y = posY; width = w; height = h; color = col; isVisible = visible; hasBorder = border;
    if (!isWithinScreen(x, y, width, height)) throw invalid_argument("Початкове положення виходить за межі екрана");
}

ModelWindow::ModelWindow(string t, int w, int h)
    : title(t), width(w), height(h), x(100), y(100), color("сірий"), isVisible(true), hasBorder(true) {
    if (!isWithinScreen(x, y, width, height)) throw invalid_argument("Розміри вікна завеликі для екрана");
}

ModelWindow::ModelWindow(const ModelWindow& other)
    : title(other.title + " (копія)"), x(other.x + 20), y(other.y + 20),
    width(other.width), height(other.height), color(other.color),
    isVisible(other.isVisible), hasBorder(other.hasBorder) {
    if (!isWithinScreen(x, y, width, height)) { x = other.x; y = other.y; }
}

// ПЕРЕВАНТАЖЕНІ ОПЕРАТОРИ:

// 1. Оператор присвоєння =
ModelWindow& ModelWindow::operator=(const ModelWindow& other) {
    if (this != &other) { // перевірка на самоприсвоєння
        title = other.title + " (присвоєно)";
        x = other.x;
        y = other.y;
        width = other.width;
        height = other.height;
        color = other.color;
        isVisible = other.isVisible;
        hasBorder = other.hasBorder;
    }
    return *this;
}

// 2. Оператор порівняння ==
bool ModelWindow::operator==(const ModelWindow& other) const {
    return (x == other.x && y == other.y &&
        width == other.width && height == other.height &&
        color == other.color &&
        isVisible == other.isVisible && hasBorder == other.hasBorder);
}

// 3. Оператори пересування +=
ModelWindow& ModelWindow::operator+=(int delta) {
    moveHorizontal(delta);
    return *this;
}

ModelWindow& ModelWindow::operator-=(int delta) {
    moveVertical(-delta); // мінус для інтуїтивного використання
    return *this;
}

// 4. Оператор виводу <<
ostream& operator<<(ostream& os, const ModelWindow& window) {
    os << "[" << window.title << "] Pos:(" << window.x << "," << window.y
        << ") Size:" << window.width << "x" << window.height
        << " Color:" << window.color
        << " " << (window.isVisible ? "Visible" : "Hidden")
        << " " << (window.hasBorder ? "Bordered" : "Borderless");
    return os;
}

// Решта методів залишаються без змін
bool ModelWindow::isWithinScreen(int newX, int newY, int newWidth, int newHeight) const {
    return (newX >= 0 && newY >= 0 &&
        newX + newWidth <= SCREEN_WIDTH &&
        newY + newHeight <= SCREEN_HEIGHT);
}

void ModelWindow::moveHorizontal(int deltaX) {
    int newX = x + deltaX;
    if (isWithinScreen(newX, y, width, height)) {
        x = newX;
    }
    else {
        throw out_of_range("Пересування виходить за межі екрана");
    }
}

void ModelWindow::moveVertical(int deltaY) {
    int newY = y + deltaY;
    if (isWithinScreen(x, newY, width, height)) {
        y = newY;
    }
    else {
        throw out_of_range("Пересування виходить за межі екрана");
    }
}

void ModelWindow::resize(int newWidth, int newHeight) {
    if (newWidth <= 0 || newHeight <= 0) throw invalid_argument("Розміри повинні бути додатніми");
    if (isWithinScreen(x, y, newWidth, newHeight)) {
        width = newWidth; height = newHeight;
    }
    else {
        throw out_of_range("Новий розмір виходить за межі екрана");
    }
}

void ModelWindow::setWidth(int newWidth) { resize(newWidth, height); }
void ModelWindow::setHeight(int newHeight) { resize(width, newHeight); }
void ModelWindow::setColor(string newColor) { color = newColor; }
void ModelWindow::toggleVisibility() { isVisible = !isVisible; }
void ModelWindow::toggleBorder() { hasBorder = !hasBorder; }

string ModelWindow::getTitle() const { return title; }
int ModelWindow::getX() const { return x; }
int ModelWindow::getY() const { return y; }
int ModelWindow::getWidth() const { return width; }
int ModelWindow::getHeight() const { return height; }
string ModelWindow::getColor() const { return color; }
bool ModelWindow::getVisibility() const { return isVisible; }
bool ModelWindow::getBorderState() const { return hasBorder; }

void ModelWindow::display() const {
    cout << "=== Інформація про вікно ===" << endl;
    cout << "Заголовок: " << title << endl;
    cout << "Координати: (" << x << ", " << y << ")" << endl;
    cout << "Розміри: " << width << "x" << height << endl;
    cout << "Колір: " << color << endl;
    cout << "Видимість: " << (isVisible ? "видиме" : "невидиме") << endl;
    cout << "Рамка: " << (hasBorder ? "так" : "ні") << endl;
    cout << "=============================" << endl;
}
