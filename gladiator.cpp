#include <cstdlib>
#include <iostream>
#include <ctime>

class Gladiator {
public:
    int damage;
    int health;
    int armor;

    Gladiator(int d, int h) : damage(rand() % d + (d / 2)), health(h){};

    void attack(Gladiator& opponent) {
        opponent.health -= damage;
    } //Наносит врагу урон
};

int get_winner(const Gladiator& gladiator1, const Gladiator& gladiator2) {
    if (gladiator1.health > gladiator2.health)
        return 1;
    else if (gladiator1.health < gladiator2.health)
        return 2;
    else
        return 0;
} /*Возвращает победившего гладиатора*/

int main() {
    srand(time(nullptr));

    const int MAXDAMAGE = 45;
    const int MAXHEALTH = 250;
    const int MINDAMAGE = MAXDAMAGE / 2;

    Gladiator first_gladiator(MAXDAMAGE, MAXHEALTH);
    Gladiator second_gladiator(MAXDAMAGE, MAXHEALTH);

    while (first_gladiator.health > 0 && second_gladiator.health > 0) {
        first_gladiator.attack(second_gladiator);
        std::cout << "\t\tПервый гладиатор наносит удар -" << first_gladiator.damage <<
            " Здоровья у второго гладиатора. Осталось: " << second_gladiator.health << std::endl;

        if (second_gladiator.health <= 0 || first_gladiator.health <= 0)
            break;

        second_gladiator.attack(first_gladiator);
        std::cout << "\t\tВторой гладиатор наносит удар -" << second_gladiator.damage <<
            " Здоровья у первого гладиатора. Осталось: " << first_gladiator.health << std::endl;
    }

    if (get_winner(first_gladiator, second_gladiator) == 1)
        std::cout << "\t\tПобеду одержал первый гладиатор!!";
    else if (get_winner(first_gladiator, second_gladiator) == 2)
        std::cout << "\t\tПобеду одержал второй гладиатор!!";
    else
        std::cout << "\t\tНичья!";

    return 0;
}
