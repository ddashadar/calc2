#ifndef CALC2_MENU_H
#define CALC2_MENU_H

#include "Infix.h"
#include <string>

void info() {
    cout << "Введите '+' если хотите добавить инфиксное выражение\n";
    cout << "Введите '-' если хотите вычесть инфиксное выражение\n";
    cout << "Введите '*' если хотите умножить на инфиксное выражение\n";
    cout << "Введите '/' если хотите разделить на инфиксное выражение\n";
    cout << "Введите 'q' если хотите завершить работу\n";
}

void calculate() {
    Infix calculator;
    string input;
    char userChoice = ' ';
    while (userChoice != 'q') {
        cout << "Введите инфиксное выражение:\n";
        getline(cin, input);
        string tmp = string() + userChoice + '(';
        calculator.setExpression(tmp + input + ')');
        if (!calculator.calculate()) {
            cout << "ВЫРАЖЕНИЕ НЕПРАВИЛЬНОЕ!\n";
            break;
        }
        int res = calculator.getResult();
        cout << "Результат: " << res << '\n';
        info();
        cin >> userChoice;
        while (userChoice != '+' && userChoice != '-' && userChoice != '*' && userChoice != '/' && userChoice != 'q') {
            cout << "НЕВЕРНО! Ещё раз:\n";
            info();
            cin >> userChoice;
        }
        getline(cin, input);
    }
}


#endif //CALC2_MENU_H
