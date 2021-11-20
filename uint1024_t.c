#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <math.h>

const int FIRST_FOUR_BITS = 0b1111;
const int SECOND_FOUR_BITS = 0b11110000;
const int MAX_LENGTH = 308;

int max(int x, int y) {
    return x > y ? x : y;
}

int min(int x, int y) {
    return x < y ? x : y;
}

typedef struct uint1024_t {
    uint8_t * num; 
    int filled;
} uint1024_t;

uint8_t read(uint1024_t * x, uint8_t i) {
    if (i >= x->filled) {
        return 0;
    }

    if (i % 2) {
        return x->num[i / 2] & FIRST_FOUR_BITS;
    }

    return x->num[i / 2] >> 4;    
}

void set(uint1024_t * x, uint8_t i, uint8_t val) {
    if (i % 2) {
        x->num[i / 2] &= SECOND_FOUR_BITS;
        x->num[i / 2] += val;
    } else {
        x->num[i / 2] &= FIRST_FOUR_BITS;
        x->num[i / 2] += val << 4;
    }
}

uint8_t size(uint16_t filled) {
    return filled / 2 + filled % 2;
}

void create(uint1024_t * x) {
    if (x->filled > MAX_LENGTH) {
        return;
    }
    
    x->num = (uint8_t *)calloc(size(x->filled), sizeof(uint8_t));
}

void resize(uint1024_t * x) {
    if (x->filled > MAX_LENGTH) {
        return;
    }

    realloc(x->num, size(x->filled));
}

void num_to_str(uint1024_t * x, char str[]) {
    for (int i = 0; i < x->filled; i++) {
        str[x->filled - 1 - i] = read(x, i) + 48;
    }

    str[x->filled] = '\0';
}

void delete_leading_zeros(uint1024_t * x) {
    uint8_t size_x = size(x->filled);
    uint8_t initial_size_x = size_x;

    while (size_x > 1 && x->num[size_x - 1] == 0) {
        size_x--;
    }

    x->filled = size_x * 2;

    if (read(x, x->filled - 1) == 0) {
        x->filled--;
    }

    if (initial_size_x != size_x) {
        resize(x);
    }
}

uint1024_t from_uint(unsigned int x) {
    uint1024_t res;

    if (x == 0) {
        res.filled = 1;
        create(&res);

        return res;
    }

    res.filled = floor(log10(x)) + 1;  // find out the number of digits in x
    create(&res);

    for (int i = 0; i < res.filled; i++) {
        set(&res, i, x % 10);
        x /= 10;
    }
    
    return res;
}

void printf_value(uint1024_t * x) {
    char str[309];
    num_to_str(x, str);
    printf(str);
}

void scanf_value(uint1024_t * x) {
    char num[MAX_LENGTH];
    gets(num);
    int len = 0;
    x->filled = strlen(num);
    free(x->num);
    create(x);

    for (int i = 0; i < x->filled; i++) {
        set(x, i, num[x->filled - i - 1] - 48);
    }
}

uint1024_t add_op(uint1024_t * x, uint1024_t * y) {
    uint1024_t res;
    res.filled = max(x->filled, y->filled);
    create(&res);

    uint8_t carry = 0;
    for (int i = 0; i < res.filled; i++) {
        uint8_t cur = read(x, i) + read(y, i) + carry;
        carry = cur / 10;
        set(&res, i, cur % 10);
    }

    if (carry) {
        res.filled += 1;
        
        if (res.filled % 2) {
            resize(&res);
            res.num[res.filled / 2] = 0;
        }

        set(&res, res.filled - 1, carry);
    }
    
    return res;
}

uint1024_t subtr_op(uint1024_t * x, uint1024_t * y) {
    uint1024_t res;
    res.filled = max(y->filled, x->filled);
    create(&res);
    uint8_t borrow = 0;

    for (int i = 0; i < res.filled; i++) {
        int cur = read(x, i) - read(y, i) - borrow;
        borrow = 0;

        if (cur < 0) {
            borrow = 1;
            cur += 10;
        }

        set(&res, i, cur);
    }

    delete_leading_zeros(&res);
    return res;    
}

uint1024_t mult_op(uint1024_t * x, uint1024_t * y) {
    uint1024_t res;

    if (x->num[0] == 0 && x->filled == 1 || y->num[0] == 0 && y->filled == 1) {
        res.filled = 1;
        create(&res);
        
        return res;
    }

    res.filled = x->filled + y->filled;
    create(&res);
    uint8_t carry;

    for (int i = 0; i < x->filled; i++) {
        carry = 0;

        for (int j = 0; j < y->filled; j++) {
            carry = read(&res, i + j) + carry + read(x, i) * read(y, j);
            set(&res, i + j, carry % 10);
            carry /= 10;
        }

        set(&res, i + y->filled, carry);
    }

    delete_leading_zeros(&res);
    return res;
}

// int main(int argc, char* argv[]) {
//     uint1024_t x;
//     uint1024_t y;
//     uint1024_t res;
//     printf("Type in the uint1024_t number: ");
//     scanf_value(&x);
//     printf("Here is the number you typed in: ");
//     printf_value(&x);
//     printf("\n\n");

//     x = from_uint(56547216);  // CHANGEME
//     y = from_uint(75855);  // CHANGEME
//     printf_value(&x);
//     printf(" + ");
//     printf_value(&y);
//     printf(" = ");
//     res = add_op(&x, &y);
//     printf_value(&res);
//     printf("\n");
    
//     printf_value(&x);
//     printf(" - ");
//     printf_value(&y);
//     printf(" = ");
//     free(res.num);
//     res = subtr_op(&x, &y);
//     printf_value(&res);
//     printf("\n");
    
//     printf_value(&x);
//     printf(" * ");
//     printf_value(&y);
//     printf(" = ");
//     free(res.num);
//     res = mult_op(&x, &y);
//     printf_value(&res);
//     printf("\n");

//     return 0;
// }