#include "crypto.h"
#include <stdlib.h>

void generate_random_key(uint8_t *key) {
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256;
    }
}

void generate_encryption_key(uint8_t *key, const uint8_t *x, const uint8_t *y) {
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = x[i] ^ y[i];
    }
}

void encrypt(uint8_t *content, size_t content_len, uint8_t *encrypted_content, uint8_t *key) {
    for (size_t i = 0; i < content_len; i++) {
        encrypted_content[i] = content[i] ^ key[i % KEY_SIZE];
    }
}

void decrypt(uint8_t *encrypted_content, size_t content_len, uint8_t *decrypted_content, uint8_t *key) {
    for (size_t i = 0; i < content_len; i++) {
        decrypted_content[i] = encrypted_content[i] ^ key[i % KEY_SIZE];
    }
}
