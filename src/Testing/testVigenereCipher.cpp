//! Unit Tests for MPAGSCipher VigenereCipher Class
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "VigenereCipher.hpp"

TEST_CASE("Vigenere Cipher encryption", "[Vigenere]") {
  VigenereCipher vc{"key"};
  REQUIRE( vc.applyCipher("HELLOWORLD", CipherMode::Encrypt) == "RIJVSUYVJN");
}

TEST_CASE("Vigenere Cipher decryption", "[Vigenere]") {
  VigenereCipher vc{"key"};
  REQUIRE( vc.applyCipher("RIJVSUYVJN", CipherMode::Decrypt) == "HELLOWORLD");
}