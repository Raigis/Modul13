// Задача 1
// Что нужно сделать 

// Необходимо из заданного пользователем вектора удалить число X.

// Как работает программа

// Пользователь вводит с клавиатуры число n — размер вектора, который надо заполнять.
// Пользователь вводит n целых чисел, которые заполняют вектор.
// Пользователь вводит значение — X. X — удаляемое из вектора значение. Необходимо удалить из вектора все элементы, которые равны заданному значению.
// В конце программы необходимо вывести итоговое состояние вектора.

#include <iostream>
#include <vector>

std::vector<int> input() {
    int size;
    bool isCorrect;
    do{
        std::cout << "Input vectior size: ";
        std::cin >> size;
        if(isCorrect = size <= 0) std::cout << "Incorrect input. Try again.\n";
    } while (isCorrect);
    
    std::vector<int> vec(size);
    std::cout << "Input numbers:\n";
    for (int i = 0; i < size; i++) std::cin >> vec[i];

    return vec;
}

std::vector<int> delete_num (std::vector<int> vec, int num) {
    if (!vec.empty()){
        int temp = vec.back();
        vec.pop_back();
        vec = delete_num(vec, num);
        if (temp != num) vec.push_back(temp);
    }
    return vec;
}

void print(std::vector<int> vec) {
    std::cout << "result: ";
    for (int i : vec) {
        std::cout << i << " ";
    }
}

int main() {
    std::vector<int> numbers = input();
    int delNum;
    std::cout << "Input number to delete: ";
    std::cin >> delNum;
    numbers = delete_num(numbers, delNum);
    print(numbers);
}