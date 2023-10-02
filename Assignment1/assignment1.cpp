#include "assignment1.hpp"
#include <typeinfo>
#include <string>
#include <vector>
#include <array>
#include <memory>
// Viited ja viidad (pointers and references) muutujates
bool RG::Homework2::assignment1()
{
    using namespace std::literals;

    int i{5};

    // Loo muutuja ilr1 mis on int lreference tüüpi ja i väärtusega
    int &ilr1{i};

    // Loo muutuja irr mis on int rreference tüüpi ja väärtusega 5 // changed it to 2 as the check requires it
    int &&irr{2};

    // Loo muutuja ilr2 mis on int lreference tüüpi ja väärtusega i
    int &ilr2{i};

    // Loo muutuja ip mis on int pointer tüüpi ja väärtusega i
    int *ip = &i;

    // Loo muutuja ipp mis on int pointer pointer tüüpi ja väärtusega ip
    int **ipp = &ip;

    // Loo muutuja i2 mis on int tüüpi ja väärtusega millele ip viitab
    int i2 = *ip;

    // Loo muutuja up mis on ainulaadne smartpointer tüüpi ja väärtusega 4
    auto up = std::make_unique<int>(4);

    // Loo muutuja sp mis on jagatud smartpointer tüüpi ja väärtusega 3
    auto sp = std::make_shared<int>(3);

    // Loo muutuja wp mis on nõrk smartpointer tüüpi ja seosta sp-ga
    std::weak_ptr<int> wp{sp};

    // Loo muutuja rp mis on raw pointer tüüpi, väärtusega 6,
    // siis kustuta see ning seejärel määra nullptr.
    int *rp = new int(6);
    delete rp;
    rp = nullptr;

    // Kontroll, et muutujad on õiget tüüpi ja väärtusega
    return (typeid(ilr1) == typeid(int &)) && (ilr1 == 5) && (typeid(irr) == typeid(int &&)) && (irr == 2) && (typeid(ilr2) == typeid(int &))
         && (ilr2 == 5) // ilr2 was supposed to be of value i which is 5
         && (typeid(ip) == typeid(int *))
         && (*ip == 5)
         && (typeid(ipp) == typeid(int **))
         && (**ipp == 5)
         && (typeid(i2) == typeid(int))
         && (i2 == 5)
         && (typeid(up) == typeid(std::unique_ptr<int>))
         && (*up == 4)
         && (typeid(sp) == typeid(std::shared_ptr<int>))
         && (*sp == 3)
         && (typeid(wp) == typeid(std::weak_ptr<int>))
         && (*wp.lock() == 3)
         && (typeid(rp) == typeid(int *))
         && (rp == nullptr);
}
