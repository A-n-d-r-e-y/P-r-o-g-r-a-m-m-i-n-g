#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include "STL.h"
#include <string>
#include <algorithm>
#include <stack>
#include <locale.h>

using namespace std;

bool is_correct(const string& str){
    stack < char > stack;

    for (int i = 0; i < (int)str.length(); ++i){
        if (str[i] == '(' || str[i] == '{' || str[i] == '['){
            stack.push(str[i]);
        }
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']'){
            if ( stack.empty()
            || ((str[i] == ')') ^ (stack.top() == '('))
            || ((str[i] == '}') ^ (stack.top() == '{'))
            || ((str[i] == ']') ^ (stack.top() == '[')) )
        return false;
        stack.pop();
        }
    }
    return stack.empty();
}

int main() {
    setlocale(LC_ALL, "Russian");

    string q, w, sk;  // = "1, 2, 6, 7, 2, 1";
    stack <char> st;
    cout << "----Задание 1.1----" << endl;
    cout << "---Программа проверки строки чисел на полиндром!---" << endl;
    cout << " Введите строку - "; cin >> sk;
    for (int i = 0; i < sk.length(); i++)
        st.push(sk.at(i));

    for (int i = 0; i < sk.length() / 2; i++) {
        if (sk.at(i) != st.top()) {
            cout << " Введённая строка - НЕ палиндром! " << endl; break;
        }
        else if (sk.at(i) = st.top()) {
            cout << " Введённая строка - палиндром! " << endl; break;
        }
    }

    cout << endl << "----Задание 1.2----" << endl;
    cout << endl << "Задана строка, содержащая скобки" << endl;
    cout << "Проверить баланс скобок" << endl;
    cout<<"(для каждой открывающейся скобки должна быть закрывающаяся скобка такого же вида)" << endl;
    cout << "Например: () [] {}" << endl;

    string st2;
    cin >> st2;
    cout << (is_correct(st2) ? "Баланс скобок содлюдён! " : "Баланс скобок НЕ содлюдён!") << endl;


    cout << endl << "-----Задание 2-----" << endl;
    cout << "Задан набор целых чисел (данные вводятся из файла)." << endl;
    cout << " Вектор, заполненный элементами их файла: " << endl;

    ifstream fh("Text.txt");
    int n; int b; int c = 0;
    vector<int> v;
    int s;
    while (fh >> s) {
        v.push_back(s);
    }

    for (int i = 0; i < v.size(); i++) {
        cout << "v[" << i + 1 << "]" << " - " << v[i] << endl;
    }

    cout << "Введите n = "; cin >> n;
    cout << "  Числа, равные n: " << endl;
    vector<int>::iterator it = find(v.begin(), v.end(), n);
    while (it != v.end()){
        int index = distance(v.begin(), it);
        cout << "v[" << index + 1 << "]" << " - " << v[index] << endl;
        ++it;
        it = find(it, v.end(), n);
    }cout << endl;

    size_t Equalu = count_if(v.begin(), v.end(), Eq(n));
    cout << "   Количество чисел, равных n - " << Equalu << endl;
    size_t evenCount = count_if(v.begin(), v.end(), [](int i) {return i % 2 == 0; });
    
    cout << "    Количество чёт чисел - " << evenCount << endl;
    it = find_if(v.begin(), v.end(), [](int i) {return i % 2 == 0; });
    
    cout << "Чёт элементы: " << endl;
    while (it != v.end()){
        int index = distance(v.begin(), it);
        cout << "v[" << index + 1 << "]" << " - " << v[index] << endl;
        ++it;
        it = find_if(it, v.end(), [](int i) {return i % 2 == 0; });
    }cout << endl;

    size_t oddCount = count_if(v.begin(), v.end(), [](int i) {return i % 2 == 1; });
    cout << "     Количество нечёт чисел - " << oddCount << endl;
    cout << "Нечёт элементы: " << endl;
    it = find_if(v.begin(), v.end(), [](int i) {return i % 2 == 1; });
    while (it != v.end()){
        int index = distance(v.begin(), it);
        cout << "v[" << index + 1 << "]" << " - " << v[index] << endl;
        ++it;
        it = find_if(it, v.end(), [](int i) {return i % 2 == 1; });
    }cout << endl;

    int sum = 0;
    if (evenCount > oddCount) {
        it = find_if(v.begin(), v.end(), [](int i) {return i % 2 == 0; });
        while (it != v.end()) {
            int index = distance(v.begin(), it);
            sum += v[index];
            ++it;
            it = find_if(it, v.end(), [](int i) {return i % 2 == 0; });
        }
        cout << "      Сумма чёт элементов - : " << sum;
    }
    else {
        for_each(v.begin(), v.end(), [&](int n) {
            sum += n;
            });
        cout << "       Сумма элементов - " << sum << endl;
    }cout << endl;

    
    int m = 0;
    sort(v.begin(), v.end());
    cout << "Отсортированный вектор: " << endl;
    it = v.begin();
    while (it != v.end()) {
        m++;
        cout << "v[" << m << "]" << " - " << *it << endl;
        it++;
    }cout << endl;

    int size = v.size();
    swap(v[0], v[size - 1]);
    cout << "Вектор с переменными первым и последним элементами: " << endl;
    it = v.begin();
    m = 0;
    while (it != v.end()) {
         m++;
         cout << "v[" << m << "]" << " - " << *it << endl;
         it++;
    }

	return 0;
}

