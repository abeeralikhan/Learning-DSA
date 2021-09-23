#include <iostream>

using namespace std;

struct Mobile {
    float screenSize;
    int batterySize;
};

int main() {
    // 1st Way
    struct Mobile* m_ptr;

    m_ptr = new struct Mobile[2];

    // 2nd Way
    struct Mobile* p = new struct Mobile;

    p->batterySize = 4000;
    p->screenSize = 6.38;

    cout << "Mobile's battery size is " << p->batterySize << " Mah " << endl;    
    cout << "and screen size is " << p->screenSize << "in " << endl;

    delete m_ptr, p;  
    return 0;
}