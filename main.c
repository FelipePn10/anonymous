#include <stdio.h>
#include <string.h>
#include "crypto.h"

int main() {
    uint8_t x[KEY_SIZE], y[KEY_SIZE];
    uint8_t encryption_key[ENCRYPTION_KEY_SIZE];

    generate_random_key(x);
    generate_random_key(y);
    generate_encryption_key(encryption_key, x, y);

    const char *content_str = "Hello World";
    size_t content_len = strlen(content_str);
    uint8_t content[content_len];
    uint8_t encrypted_content[content_len];
    uint8_t decrypted_content[content_len];

    for (size_t i = 0; i < content_len; i++) {
        content[i] = content_str[i];
    }

    encrypt(content, content_len, encrypted_content, encryption_key);
    printf("Encrypted content: ");
    for (size_t i = 0; i < content_len; i++) {
        printf("%02x ", encrypted_content[i]);
    }
    printf("\n");

    decrypt(encrypted_content, content_len, decrypted_content, encryption_key);
    printf("Decrypted content: ");
    for (size_t i = 0; i < content_len; i++) {
        printf("%c", decrypted_content[i]);
    }
    printf("\n");

    return 0;
}

