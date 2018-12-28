#pragma once
#ifndef RAND_H
#define RAND_H
//http://www.cyberforum.ru/cpp-beginners/thread383355.html
double rand(double b, double e) //Функция самописная, честно стыреная с cyberforum
{
    return b + (rand() % static_cast<unsigned int>((e - b) * 1000)) / 1000.f;
}

#endif