//
// Created by Artyom on 15.11.2023.
//

#include "lab1.h"

std::string remove_implications(const std::string &formula) {
    std::string result;

    for (size_t i = 0; i < formula.size(); ++i)
        if (formula[i] == '-' && i + 1 < formula.size() && formula[i + 1] == '>') {
            result += "|";
            ++i;
        } else
            result += formula[i];

    return result;
}

std::string to_nnf(const std::string &formula) {
    std::string result;
    std::stack<bool> negations;
    negations.push(false);

    for (char c: formula)
        if (c == '~')  // Отрицание
            negations.top() = !negations.top();
        else if (c == '(') {  // Открывающая скобка
            result += c;
            negations.push(negations.top());
        } else if (c == ')') {  // Закрывающая скобка
            result += c;
            negations.pop();
        } else if (c == '&' || c == '|')  // Конъюнкция или дизъюнкция
            result += negations.top() ? (c == '&' ? '|' : '&') : c;
        else  // Переменная
            result += (negations.top() ? "~" : "") + std::string(1, c);

    return result;
}

std::string to_cnf(const std::string &formula) {
    std::string result;
    std::stack<bool> negations;
    negations.push(false);

    for (char c: formula)
        if (c == '~')  // Отрицание
            negations.top() = !negations.top();
        else if (c == '(') {  // Открывающая скобка
            result += c;
            negations.push(negations.top());
        } else if (c == ')') {  // Закрывающая скобка
            result += c;
            negations.pop();
        } else if (c == '&' || c == '|')  // Конъюнкция или дизъюнкция
            result += negations.top() ? (c == '&' ? '|' : '&') : c;
        else  // Переменная
            result += (negations.top() ? "~" : "") + std::string(1, c);

    return result;
}

bool compute_cnf(const std::vector<std::vector<int>> &cnf, const std::vector<bool> &values) {
    for (const auto &clause: cnf) {
        bool clause_result = false;

        for (int var: clause)
            clause_result |= values[abs(var) - 1] ^ (var < 0);

        if (!clause_result)
            return false;
    }

    return true;
}

bool check_all_values(const std::vector<std::vector<int>> &cnf, int n, int i, std::vector<bool> &values) {
    if (i == n)
        return compute_cnf(cnf, values);

    values[i] = false;

    if (!check_all_values(cnf, n, i + 1, values))
        return false;

    values[i] = true;

    return check_all_values(cnf, n, i + 1, values);
}

bool is_tautology(const std::vector<std::vector<int>> &cnf, int n) {
    std::vector<bool> values(n);

    return check_all_values(cnf, n, 0, values);
}

void find_false_interpretations(const std::vector<std::vector<int>>& cnf, int n) {
    std::vector<bool> values(n);
    check_all_values(cnf, n, 0, values);
}