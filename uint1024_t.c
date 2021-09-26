#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <math.h>

// allocate memory for num

// delete padding zeros

// create test cases

int max(int x, int y) {
    return x > y ? x : y;
}

int min(int x, int y) {
    return x < y ? x : y;
}

struct uint1024_t_s {
    uint8_t * num; 
    int filled;
};

typedef struct uint1024_t_s uint1024_t;

uint8_t read(uint1024_t x, uint8_t i) {
    if (i >= x.filled) {
        return 0;
    }

    if (i % 2) {
        return x.num[i / 2] & 0b1111;
    }

    return x.num[i / 2] >> 4;
    
}

void set(uint1024_t * x, uint8_t i, uint8_t val) {
    if (i % 2) {
        x->num[i / 2] &= 0b11110000;
        x->num[i / 2] += val;
    } else {
        x->num[i / 2] &= 0b1111;
        x->num[i / 2] += val << 4;
    }
}

uint8_t size(uint16_t filled) {
    return filled / 2 + filled % 2;
}

void create(uint1024_t * x) {
    x->num = (uint8_t *)calloc(size(x->filled), sizeof(uint8_t));
}

void delete_leading_zeros(uint1024_t * x) {
    uint8_t size_x = size(x->filled);
    uint8_t initial_size_x = size_x;

    while (size_x > 1 && x->num[size_x - 1] == 0) {
        size_x--;
    }

    x->filled = size_x * 2;

    if (read(*x, x->filled - 1) == 0) {
        x->filled--;
    }

    if (initial_size_x != size_x) {
        realloc(x->num, size_x);
    }
}

uint1024_t uint1024_t_from_uint(unsigned int x) {
    uint1024_t res;

    if (x == 0) {
        res.filled = 1;
        create(&res);

        return res;
    }

    res.filled = floor(log10(x)) + 1;
    create(&res);

    for (int i = 0; i < res.filled; i++) {
        set(&res, i, x % 10);
        x /= 10;
    }
    
    return res;
}

void printf_value(uint1024_t x) {
    for (int i = x.filled - 1; i >= 0; i--)
    {
        printf("%" PRIu8 "", read(x, i));
    }
}

void scanf_value(uint1024_t * x) {
    char num[310];
    gets(num);
    int len = 0;
    x->filled = strlen(num);
    free(x->num);
    create(x);

    for (int i = 0; i < x->filled; i++) {
        set(x, i, num[x->filled - i - 1] - 48);
    }
}

uint1024_t uint1024_t_add_op(uint1024_t x, uint1024_t y) {
    uint1024_t res;
    res.filled = max(x.filled, y.filled);
    create(&res);

    uint8_t carry = 0;
    for (int i = 0; i < res.filled; i++) {
        uint8_t cur = read(x, i) + read(y, i) + carry;
        carry = cur / 10;
        set(&res, i, cur % 10);
    }

    if (carry) {
        res.filled += 1;
        if (res.filled % 2 == 0) {
            realloc(res.num, size(res.filled));
        }

        set(&res, res.filled - 1, carry);
    }
    
    return res;
}

uint1024_t uint1024_t_subtr_op(uint1024_t x, uint1024_t y) {
    uint1024_t res;
    res.filled = max(y.filled, x.filled);
    create(&res);
    uint8_t borrow = 0;

    for (int i = 0; i < res.filled; i++)
    {
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

uint1024_t uint1024_t_mult_op(uint1024_t x, uint1024_t y) {
    uint1024_t res;

    if (x.num[0] == 0 && x.filled == 1 || y.num[0] == 0 && y.filled == 1) {
        res.filled = 1;
        create(&res);
        
        return res;
    }

    res.filled = x.filled + y.filled;
    create(&res);
    uint8_t carry;

    for (int i = 0; i < x.filled; i++) {
        carry = 0;

        for (int j = 0; j < y.filled; j++) {
            carry = read(res, i + j) + carry + read(x, i) * read(y, j);
            set(&res, i + j, carry % 10);
            carry /= 10;
        }

        set(&res, i + y.filled, carry);
    }
    delete_leading_zeros(&res);

    return res;
}

int main(int argc, char* argv[]) {
    uint1024_t x;
    uint1024_t y;
    printf("Type in the uint1024_t number: ");
    scanf_value(&x);
    printf("Here is the number you typed in: ");
    printf_value(x);
    printf("\n\n");

    x = uint1024_t_from_uint(56547216);
    y = uint1024_t_from_uint(75855);
    printf_value(x);
    printf(" + ");
    printf_value(y);
    printf(" = ");
    printf_value(uint1024_t_add_op(x, y));
    printf("\n");
    
    printf_value(x);
    printf(" - ");
    printf_value(y);
    printf(" = ");
    printf_value(uint1024_t_subtr_op(x, y));
    printf("\n");
    
    printf_value(x);
    printf(" * ");
    printf_value(y);
    printf(" = ");
    printf_value(uint1024_t_mult_op(x, y));

    return 0;
}