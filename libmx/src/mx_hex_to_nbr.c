#include "../inc/libmx.h"

bool mx_isdigit(char c) {
	return (c >= 48 && c <= 57); 
}

bool mx_isupper(char c) {
    return (c >= 65 && c <= 90);
}

bool mx_islower(char c) {
    return (c >= 97 && c <= 122);
}

unsigned long int mx_pow_16(unsigned long pow) {
    if (pow == 0)
        return 1;

    unsigned long sixteen = 1;

    for (unsigned long i = 0; i < pow; i++)
        sixteen *= 16;

    return sixteen;
}

unsigned long mx_hex_to_nbr(const char *hex) {
    if (hex == NULL)
        return 0;

    unsigned long result = 0;
    int pow;

    for (pow = 0; hex[pow] != '\0'; pow++) {
        
    }

    pow--;

    for (int i = 0; hex[i] != '\0'; i++) {
        if (mx_isdigit(hex[i])) {
            result += (hex[i] - 48) * mx_pow_16(pow);
            pow--;
        }
        else if (mx_isupper(hex[i])) {
            result += (hex[i] - '\0' - 55) * mx_pow_16(pow);
            pow--;
        }
        else if (mx_islower(hex[i])) {
            result += (hex[i] - '\0' - 87) * mx_pow_16(pow);
            pow--;
        }
    }

    return result;
}

// int main(int argc, char *argv[]) {
//     for (int i = 1; i < argc; i++) {
//         mx_printint(mx_hex_to_nbr(argv[i]));
//         mx_printstr("\n");
//     }
// }

