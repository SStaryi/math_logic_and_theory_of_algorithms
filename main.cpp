//
// Created by Artyom on 15.11.2023.
//

// Здесь находится выполнение текущей лабораторной работы
#include <iostream>
#include <string>
#include <vector>

#include "lab1/lab1.h"

int main() {
    std::string formula = "(P->Q)&R";  // Здесь должна быть ваша формула

    formula = remove_implications(formula);
    formula = to_nnf(formula);
    formula = to_cnf(formula);

    std::cout << "Formula in CNF: " << formula << std::endl;

    std::vector<std::vector<int>> cnf = {{1, 2}, {3}};
    int n = 3;  // Количество переменных

    if (is_tautology(cnf, n))
        std::cout << "The formula is generally valid" << std::endl;
    else
        std::cout << "The formula is not universally valid" << std::endl;

//     TASK 5

    std::cout << "Interpretations on which the formula takes a false value:\n";
    find_false_interpretations(cnf, n);

    return 0;
}