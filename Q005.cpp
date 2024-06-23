#include <iostream>
#include <string>

unsigned long hashString(const std::string& str) {
    unsigned long hash = 5381; // Начальное значение
    const char* s = str.c_str(); // Получение указателя на символы строки

    for (int i = 0; s[i]; ++i) {
        hash = ((hash << 5) + hash) + s[i]; /* hash * 33 + s[i] */
    }

    return hash % 10000007; // Применяем операцию модуля для получения хеша фиксированной длины
}

int main() {
    std::string input = "Hello, World!";
    unsigned long hashValue = hashString(input);

    std::cout << "Hash of \"" << input << "\" is: " << hashValue << std::endl;

    return 0;
}
