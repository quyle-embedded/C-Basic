#include "stdio.h"
#include "stdint.h"

typedef enum
{
    AUDI = 0,
    MAZDA,
    HONDA,
    VINFAST,
    BWM,
    PORSCHE,
    MERCEDES,
} car_type;

void calc_price_car(float km)
{
    if (km <= 1)
    {
        printf("Kilometer: %.2f km\nPrice car: %.2f VND", km, km * 14000);
    }
    else if (km <= 30)
    {
        printf("Kilometer: %.2f km\nPrice car: %.2f VND", km, 14000 + (km - 1) * 12000);
    }
    else if (km > 30)
    {
        printf("Kilometer: %.2f km\nPrice car: %.2f VND", km, 14000 + 29 * 12000 + (km - 30) * 10000);
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    int8_t months = 1;
    switch (months)
    {
    case 1:
        /* code */
        printf("1");
        break;
    case 2:
        printf("2");
        break;
    case 3:
        printf("3");
        break;
    default:
        break;
    }

    return 0;
}
