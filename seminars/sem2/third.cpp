#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

// Функция split разбивает строку s по символу delimiter и возвращает вектор токенов.
vector<string> split(const string &s, char delimiter) {
    vector<string> tokens;
    size_t start = 0;
    size_t pos = s.find(delimiter);
    while (pos != string::npos) {
        tokens.push_back(s.substr(start, pos - start));
        start = pos + 1;
        pos = s.find(delimiter, start);
    }
    tokens.push_back(s.substr(start));
    return tokens;
}


double evaluatePostfix(const string &expr) {
  stack<double> st;// стек для хранения операндов.
  vector<string> tokens = split(expr, ' ');  // разбиваем строку посимвольно.

  for (size_t i = 0; i < tokens.size(); i++) {
    string token = tokens[i];
    if (token == "+" || token == "-" || token == "*" || token == "/") {
      if (st.size() < 2) {
        throw runtime_error("Недостаточно операндов для операции");
      }
// Извлекаем два операнда (сначала правый, затем левый).
  double op2 = st.top(); st.pop();
  double op1 = st.top(); st.pop();
  double result = 0;
  if (token == "+") {
    result = op1 + op2;
  } else if (token == "-") {
  result = op1 - op2;
  } else if (token == "*") {
  result = op1 * op2;
  } else if (token == "/") {
  if (op2 == 0) {
  throw runtime_error("Деление на ноль");
  }
  result = op1 / op2;
  }
  st.push(result); // Результат операции помещаем обратно в стек.
  } else {
  // Если токен не оператор, предполагаем, что это число.
            try {
                double num = stod(token); // Преобразуем строку в число.
                st.push(num);
            } catch (const invalid_argument &e) {
                throw runtime_error("Неверный операнд: " + token);
            }
        }
    }
    // После обработки всех токенов в стеке должен остаться ровно один элемент.
    if (st.size() != 1) {
        throw runtime_error("Некорректное выражение");
    }
    return st.top();
}

int main() {
    string expression;
    cout << "Введите выражение в постфиксной записи: ";
    getline(cin, expression); // Считываем всю строку ввода.
    
    try {
        double result = evaluatePostfix(expression);
        cout << "Результат: " << result << endl;
    } catch (const exception &e) {
        cout << "Ошибка: " << e.what() << endl;
    }
    return 0;
}
