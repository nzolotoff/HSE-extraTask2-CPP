#include <iostream>

int minMovesToMakePalindrome(std::string str) {
    int sizeOfString = str.size(); // находим размер строки
    int i = 0; // i-й указатель на 0-й элемент строки
    int j = sizeOfString-1; // j-й указатель на последний
    int counter = 0; // счетчик перестановок
    int centralElement = -1; // центральный элемент
    int left,right = 0;

    while (i<=j) { // в цикле идем по строке слева и справа пока указатели не сойдутся

        // если элементы не равны
        if (str[i] != str[j]) {
            left = i+1;

            while (str[left] != str[j] && left < j) {
                left++;
            }

            // если строка нечетная ищем центральный элемент
            if (left == j) {

                centralElement = j;
                j--;
                continue;
            }

            else {
                for (int k = left; k > i; k--) {

                    std::swap(str[k],str[k-1]);
                    counter++;
                }
            }

        }

        // если элементы равны
        else {
            i++;
            j--;
        }
    }

    // если нашли центральный
    if (centralElement != -1) {
        counter += centralElement - (sizeOfString / 2);
    }
    return counter; // возвращаем количество перестановок
}

int main() {
    std::string str;
    std::cout << "Please, enter your line" << std::endl;
    std::cin >> str;
    std::cout << minMovesToMakePalindrome(str) << std::endl;
    return 0;
}

