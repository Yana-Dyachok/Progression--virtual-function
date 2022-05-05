/*2. Створити абстрактний базовий клас “Прогресія” з віртуальною функцією – обчислення суми прогресії. Створити похідні класи: “Арифметична прогресія” і “Геометрична прогресія”.
Кожний клас має два поля типу double: перший член прогресії і постійна різниця (для арифметичної) і постійне відношення (для геометричної). 
Визначити функцію обчислення суми, де параметром є кількість елементів прогресії.*/
#include<math.h>
#include <iostream>
using namespace std;

class Progression { //базовий клас
protected:
    virtual double Sum(int n) = 0; //віртуальна функція  обчислення суми, де параметром є кількість елементів прогресії
};
class GeometricProgression: public Progression {
protected:
    double a1;//перший член прогресії
    double q;//постійне відношення
    double sum;//сума геометричної прогресії
public:
    GeometricProgression(double a1, double q){
        this->a1 = a1;
        this->q=q;
    }
    double Sum(int n)
    {
        if (q != 1) sum = (a1 * (1 - pow(q, n)))/(1 - q);
        return sum;
    }
   ~GeometricProgression() {}
};
class ArithmeticProgression : public Progression{
protected:
    double a1;//перший член прогресії
    double d;//постійна різниця 
    double sum;//сума арифметичної прогресії
public:
    ArithmeticProgression(double a1, double d) {
        this->a1 = a1;
        this->d = d;
    }

    double Sum(int n)
    {
        sum = ((2*a1+(n-1)*d) / 2)*n;
        return sum;
    }
    ~ArithmeticProgression() {};
};

int main()
{
    ArithmeticProgression A(2, 2);
    GeometricProgression G(4,2);
    cout <<"Sum of arithmetic progression " << A.Sum(5)<<endl;//виводимо суму арифметичної прогресії
    cout << "Sum of  geometric progression " << G.Sum(3)<<endl;//виводимо суму геометричної прогресії
} 