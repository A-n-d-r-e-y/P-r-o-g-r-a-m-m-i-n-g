#include <iostream>
#include <string.h>
#include <cstring>
#include <stdlib.h>
#include <ctype.h>
#include <fstream>
#include <locale.h>
using namespace std;

string get_word(istream& is) {
    string w;
    is >> w;
    return w;
}


int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "---1 задание---" << endl;

    cout << "Напишите функцию склейки строки и n символов другой строки. " << endl;
    cout << "Функция должна добавлять n символов второй строки к первой. " << endl;
    cout << "Введите два слова каждой строки: " << endl;
    char first[64];
    cin >> first;
    char second[64];
    cin >> second;

    snprintf(first, sizeof first, "%s%s", first, second);
    cout << "Объединённые строки - " << first << endl;

    /*
    const int c = 64;
    char first[c];
    cin.getline(first, c);// cin >> first;
    cin >> first;
    char second[c];
    cin.getline(second, c);
    cin >> second;
    int n;
    cin >> n;

    first[64] += second[n];

    cout << first << endl;
    */

    cout << endl << "---2 задание---" << endl;

    cout << "Дан текст:" << endl;
    cout << "Do you like programming? " << endl;
    cout << "I love programming!" << endl;
    cout << "But sometimes I lose my head from love." << endl;
    cout << "Выведите на экран самое короткое слово последней строки данного текста." << endl;


    ifstream file("text.txt");
    if (!file) {
        cerr << "Не удалось открыть файл" << endl;
        return 1;
    }

    string word, min_word;
    size_t len, min_len = 1000;

    while (file) {
        word = get_word(file);
        if (word.length() == 0)
            break;

        len = word.length();

        if (len < min_len) {
            min_len = len;
            min_word = word;
        }
    }

    file.close();

    cout << "Самое короткое слово: " << min_word << " - " << min_len << endl;

    cout << endl << "---3 задание---" << endl;

    cout << "Упорядочите слова текста из задания 2 по убыванию их длины. " << endl;
    cout << " " << endl;


    ifstream file3("text3.txt");
    if (!file3) {
        cerr << "Не удалось открыть файл" << endl;
        return 1;
    }
    string max_word;
    size_t max_len = 0;

    while (file3) {
        word = get_word(file3);
        if (word.length() == 0)
            break;
        
                len = word.length();
                if (len > max_len) {
                    max_len = len;
                    max_word = word;
                    cout << max_word << " -> ";
                }
            
        
    }

    file3.close();
    
    cout << endl;

    return 0;
}