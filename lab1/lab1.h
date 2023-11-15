//
// Created by Artyom on 15.11.2023.
//

#ifndef MATH_LOGIC_AND_THEORY_OF_ALGORITHMS_LAB1_H
#define MATH_LOGIC_AND_THEORY_OF_ALGORITHMS_LAB1_H

#include <iostream>
#include <string>
#include <stack>
#include <vector>

// Функция для удаления импликаций из формулы
std::string remove_implications(const std::string &formula);

// Функция для приведения формулы к негативной нормальной форме (NNF)
std::string to_nnf(const std::string &formula);

// Функция для приведения формулы к конъюнктивной нормальной форме (CNF)
std::string to_cnf(const std::string &formula);

// Функция для вычисления значения логического выражения
bool compute_cnf(const std::vector<std::vector<int>> &cnf, const std::vector<bool> &values);

// Функция для проверки всех возможных наборов значений
bool check_all_values(const std::vector<std::vector<int>> &cnf, int n, int i, std::vector<bool> &values);

// Функция для проверки общезначимости формулы
bool is_tautology(const std::vector<std::vector<int>> &cnf, int n);

// Функция для поиска всех интерпретаций, на которых формула принимает ложное значение
void find_false_interpretations(const std::vector<std::vector<int>>& cnf, int n);

#endif //MATH_LOGIC_AND_THEORY_OF_ALGORITHMS_LAB1_H
