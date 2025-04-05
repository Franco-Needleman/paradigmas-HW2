#include "ejer4.hpp"

Ctabnc::Ctabnc(double d, string t) : dinero(d), titular(t) {}

void Ctabnc::depo(double d) {
    dinero+=d;
}

Ahorro::Ahorro(double d, string t):Ctabnc(d,t), cant_info (0) {}

void Ahorro::retirar(double d) {
    if (dinero>=d){
        dinero-= d;
        cout << "se retriro: $" << d << " de la caja de ahorro"<< endl;
    }
    else{
        cout << "se retriro: $" << dinero<<" de la caja de ahorro"<< endl;
        dinero = 0;
    }
    cout<< "balance de la caja de ahorro: $" << dinero<< endl;
}

void Ahorro::mostrar_info() {
    cout<< "titular de la caja de ahorro " << titular<< endl;
    cout<< "balance de la caja de ahorro: $" << dinero<< endl;
    cant_info+=1;
    if (cant_info==2){
        cant_info=0;
        this->retirar(20);
        cout << "debido a la cantidad de veces que se mostro la informacion de cuenta" << endl;
    }
}

Corriente::Corriente(double d, string t, Ahorro* cta):Ctabnc(d,t), cta_ahorro(cta) {}


void Corriente::retirar(double d) {
    if (dinero>=d){
        dinero-= d;
        cout << "se retriro: $" << d << " de la cta corriente"<< endl;
    }
    else{
        cout << "se retriro: $" << dinero<<" de la cta corriente"<< endl;
        d-=dinero;
        dinero = 0;
        this->cta_ahorro->retirar(d);
    }
    cout<< "balance de la cuenta corriente: $" << dinero<< endl;
}
void Corriente::mostrar_info() {
    cout<< "titular de la cuenta corriente " << titular<< endl;
    cout<< "balance de la caja de ahorro: $" << dinero<< endl;
}