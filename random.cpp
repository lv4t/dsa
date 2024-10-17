#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));
 int thoc =0;
 int thit =0;
 int ngo =0;
 int traicay =0;
    for(int i=0; i<100;i++)
    {
        int randomNumber = std::rand() % 4 + 1;
        switch (randomNumber) {
    case 1:
       thoc ++;
        break;
    case 2:
        ngo ++;
        break;
    case 3:
        thit ++;
    default:
        traicay++;
    }
    }
    std::cout <<"so lan ra thoc " << thoc <<"\n";
    std::cout <<"so lan ra thit " << thit <<"\n";
    std::cout <<"so lan ra ngo " << ngo <<"\n";
    std::cout <<"so lan ra traicay " << traicay <<"\n";
    return 0;
}
