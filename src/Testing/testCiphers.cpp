//! Generalised Unit Tests for MPAGSCipher Cipher Classes
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <vector>

#include "../MPAGSCipher/Cipher.hpp"
#include "../MPAGSCipher/CipherFactory.hpp"
#include "../MPAGSCipher/CipherMode.hpp"
#include "../MPAGSCipher/CipherType.hpp"
#include "../MPAGSCipher/CaesarCipher.hpp"
#include "../MPAGSCipher/PlayfairCipher.hpp"
#include "../MPAGSCipher/VigenereCipher.hpp"

bool testCipher( const std::unique_ptr<Cipher>& cipher, const CipherMode mode, const std::string& inputText, const std::string& outputText) {
    std::string testOutputText{cipher->applyCipher(inputText, mode)};
    if (testOutputText == outputText) {
        return true;
    } else {
        return false;
    }

}

TEST_CASE("All Cipher encryption", "[all ciphers]")
{
    std::vector<std::unique_ptr<Cipher>> ciphers;
    std::vector<std::string> encrypted_text;
    ciphers.push_back( cipherFactory( CipherType::Caesar, "10" ) );
    encrypted_text.push_back( "ROVVYGYBVN" );
    ciphers.push_back( cipherFactory( CipherType::Playfair, "hello" ) );
    encrypted_text.push_back( "ELDLOAYESEGX" );
    ciphers.push_back( cipherFactory( CipherType::Vigenere, "key" ) );
    encrypted_text.push_back( "RIJVSUYVJN" );

    int cipher_num{0};
    for ( const auto& c : ciphers ) {
        REQUIRE(testCipher(c, CipherMode::Encrypt, "HELLOWORLD", encrypted_text.at(cipher_num)));
        cipher_num++;
    }
}

TEST_CASE("All Cipher decryption", "[all ciphers]")
{
    std::vector<std::unique_ptr<Cipher>> ciphers;
    std::vector<std::string> encrypted_text;
    std::vector<std::string> decrypted_text;
    ciphers.push_back( cipherFactory( CipherType::Caesar, "10" ) );
    encrypted_text.push_back( "ROVVYGYBVN" );
    decrypted_text.push_back( "HELLOWORLD" );
    ciphers.push_back( cipherFactory( CipherType::Playfair, "hello" ) );
    encrypted_text.push_back( "ELDLOAYESEGX" );
    decrypted_text.push_back( "HELXLOWORLDZ" );
    ciphers.push_back( cipherFactory( CipherType::Vigenere, "key" ) );
    encrypted_text.push_back( "RIJVSUYVJN" );
    decrypted_text.push_back( "HELLOWORLD" );

    int cipher_num{0};
    for ( const auto& c : ciphers ) {
        REQUIRE(testCipher(c, CipherMode::Decrypt, encrypted_text.at(cipher_num), decrypted_text.at(cipher_num)));
        cipher_num++;
    }
}
