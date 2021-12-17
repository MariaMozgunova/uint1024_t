#include "utils.c"

int main(int argc, char* argv[]) {
    uint1024_t x;
    uint1024_t y;
    uint1024_t res;
    printf("Type in the uint1024_t number: ");
    scanf_value(&x);
    printf("Here is the number you typed in: ");
    printf_value(&x);
    printf("\n\n");

    x = from_uint(56547216);  // CHANGEME
    y = from_uint(75855);  // CHANGEME
    printf_value(&x);
    printf(" + ");
    printf_value(&y);
    printf(" = ");
    res = add_op(&x, &y);
    printf_value(&res);
    printf("\n");
    
    printf_value(&x);
    printf(" - ");
    printf_value(&y);
    printf(" = ");
    free(res.num);
    res = subtr_op(&x, &y);
    printf_value(&res);
    printf("\n");
    
    printf_value(&x);
    printf(" * ");
    printf_value(&y);
    printf(" = ");
    free(res.num);
    res = mult_op(&x, &y);
    printf_value(&res);
    printf("\n");

    return 0;
}