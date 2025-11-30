#include "ModelWindow.h"
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    try {
        cout << "=== ДЕМОНСТРАЦІЯ ПЕРЕВАНТАЖЕНИХ ОПЕРАТОРІВ ===" << endl << endl;

        ModelWindow window1("Вікно 1", 100, 100, 400, 300, "синій");
        ModelWindow window2("Вікно 2", 200, 200, 500, 400, "червоний");

        cout << "1. Оператор виводу <<:" << endl;
        cout << "window1: " << window1 << endl;
        cout << "window2: " << window2 << endl << endl;

        cout << "2. Оператор порівняння ==:" << endl;
        cout << "window1 == window2: " << (window1 == window2 ? "так" : "ні") << endl << endl;

        cout << "3. Оператори пересування += і -=:" << endl;
        cout << "До пересування: " << window1 << endl;
        window1 += 50;  // пересування вправо
        window1 -= 30;  // пересування вниз
        cout << "Після пересування: " << window1 << endl << endl;

        cout << "4. Оператор присвоєння =:" << endl;
        ModelWindow window3 = window1;  // використання оператора присвоєння
        cout << "window3 (копія window1): " << window3 << endl;

        cout << endl << "5. Порівняння після присвоєння:" << endl;
        cout << "window1 == window3: " << (window1 == window3 ? "так" : "ні") << endl;

    }
    catch (const exception& e) {
        cout << "Помилка: " << e.what() << endl;
    }

    return 0;
}
