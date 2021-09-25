#include "../include/control.hpp"

void Control::toCorrect(int &x)
{
    std::cout << "Zly wymiar planszy. Wprowadz jeszcze raz" << std::endl;
    std::cin >> x;
    if (x < 5 || x > 35)
        x = 20;
}

void Control::setOptions()
{
    std::cout << "Gra Snake" << std::endl;
    //wybor
    std::cout << "Podaj szerokosc planszy od 5 do 35" << std::endl;
    std::cin >> width;
    if (width < 5 || width > 35)
        toCorrect(width);

    std::cout << "Podaj wysokosc planszy od 5 do 35" << std::endl;
    std::cin >> height;
    if (height < 5 || height > 35)
        toCorrect(height);

    std::cout << "Podaj szybkosc od 1 do 10" << std::endl;
    std::cin >> speed;
    if (speed < 1)
        speed = 1;
    if (speed > 10)
        speed = 10;
}

void Control::setControls()
{
     std::cout << "Nacisnij klawisze ktorymi chcesz zagrac" << std::endl;

    std::cout << "UP" << std::endl;
    up = getchar();
    if (leftd == 224)
        leftd += getchar();
    if (leftd == 0)
        leftd -= getchar();
    getchar();

    std::cout << "DOWN" << std::endl;
    down = getchar();
    if (leftd == 224)
        leftd += getchar();
    if (leftd == 0)
        leftd -= getchar();
    getchar();

    std::cout << "LEFT" << std::endl;
    leftd = getchar();
    if (leftd == 224)
        leftd += getchar();
    if (leftd == 0)
        leftd -= getchar();
    getchar();

    std::cout << "RIGHT" << std::endl;
    rightd = getchar();
    if (rightd == 224)
        rightd += getchar();
    if (rightd == 0)
        rightd -= getchar();
    getchar();
}

