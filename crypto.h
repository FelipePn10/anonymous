#ifndef CRYPTO_H
#define CRYPTO_H

#include <stdint.h>
#include <stddef.h>

#define KEY_SIZE 32
#define ENCRYPTION_KEY_SIZE 64

void generate_random_key(uint8_t *key);
void generate_encryption_key(uint8_t *key, const uint8_t *x, const uint8_t *y);
void encrypt(uint8_t *content, size_t content_len, uint8_t *encrypted_content, uint8_t *key);
void decrypt(uint8_t *encrypted_content, size_t content_len, uint8_t *decrypted_content, uint8_t *key);

#endif
