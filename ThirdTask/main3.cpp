// Задача 3
// Что нужно сделать
// Вам дали задание разработать хранилище для целочисленных значений во встраиваемой операционной системе. 
// Такие системы работают в большей части техники, которая нас окружает: автомобилях, стиральных машинах, микроволновках, холодильниках. 
// Только вот незадача: объём памяти этой системы очень небольшой, поэтому в хранилище не может находиться более 20 элементов.

// В хранилище, являющееся вектором, с клавиатуры приходят целочисленные значения и помещаются один за другим.

// При вводе −1 с клавиатуры необходимо вывести всё содержимое хранилища (допускается вывести все 20 элементов, даже если введено меньше). 
// При выводе элементы должны быть в том порядке, в котором они добавлялись.

#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers (20);
    int count = 0;
    int startPos = 0;
    int finishPos;
    while(true){
        std::cout << "\nInput number: ";
        int input;
        std::cin >> input;

        if (count > 20) {
            startPos = count % 20;
            finishPos = startPos;
        }  else {
            finishPos = count;
        }

        if (input == -2) return 0;
        
        if (input == -1) {
            int i = startPos;
            do{      
                if (i >= 20) i %= 20;
                std::cout << numbers[i] << " ";
                i++;
            } while (i != finishPos);
        } else {
            numbers[count%20] = input;
            count++;
        }
    }
}