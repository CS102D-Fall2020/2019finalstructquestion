#include <stdio.h>
#include <string.h>

struct Currency {
    float denomination;
    int year;
    char material[100];
    char specialProperty[100];
    float actualValue;
};

struct Wallet {
    char owner[100];
    int numOfTotalCurrencies;
    struct Currency c[20];
    float totalVal;
};

void computeActualValue(struct Currency *c) {
    c->actualValue = c->denomination;
    if (c->year < 1964) {
        c->actualValue += 2;
    }
    if (strcmp(c->material, "silver") == 0) {
        printf("SILVER\n");
        c->actualValue += 3;
    }
    if (strcmp(c->material, "steel") == 0) {
        c->actualValue += 1;
    }
    if (strcmp(c->specialProperty, "error") == 0) {
        c->actualValue *= 1.5;
    }
    if (strcmp(c->specialProperty, "star") == 0) {
        c->actualValue *= 1.1;
    }
}

void addCurrencyToWallet(struct Wallet *w, struct Currency *c) {
    w->c[w->numOfTotalCurrencies] = *c;
    w->numOfTotalCurrencies++;
}

void computeWalletActualValue(struct Wallet *w) {
    float totalVal = 0;
    for (int i=0; i<w->numOfTotalCurrencies; i++) {
        totalVal += w->c[i].actualValue;
    }
    w->totalVal = totalVal;
}

int main() {

    struct Currency q = {0.25, 1950, "silver", "error"};
    struct Currency p = {0.01, 1943, "steel", "none"};
    struct Currency h = {100, 2019, "paper", "star"};

    struct Wallet w = {"Kaito", 0};

    computeActualValue(&q);
    computeActualValue(&p);
    computeActualValue(&h);
    
    addCurrencyToWallet(&w, &q);
    addCurrencyToWallet(&w, &p);
    addCurrencyToWallet(&w, &h);

    computeWalletActualValue(&w);

    printf("%f\n", w.totalVal);

    return 0;
}
