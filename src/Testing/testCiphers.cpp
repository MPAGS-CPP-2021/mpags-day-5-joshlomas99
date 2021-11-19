//! Generalised Unit Tests for MPAGSCipher Cipher Classes
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

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
    auto cc{cipherFactory( CipherType::Caesar, "10" )};
    auto pc{cipherFactory( CipherType::Playfair, "hello" )};
    auto vc{cipherFactory( CipherType::Vigenere, "key" )};
    REQUIRE(testCipher(cc, CipherMode::Encrypt, "HELLOWORLD", "ROVVYGYBVN"));
    REQUIRE(testCipher(pc, CipherMode::Encrypt, "BOBISSOMESORTOFJUNIORCOMPLEXXENOPHONEONEZEROTHING", "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA"));
    REQUIRE(testCipher(vc, CipherMode::Encrypt, "HELLOWORLD", "RIJVSUYVJN"));
}

TEST_CASE("All Cipher decryption", "[all ciphers]")
{
    auto cc{cipherFactory( CipherType::Caesar, "10" )};
    auto pc{cipherFactory( CipherType::Playfair, "hello" )};
    auto vc{cipherFactory( CipherType::Vigenere, "key" )};
    REQUIRE(testCipher(cc, CipherMode::Decrypt, "ROVVYGYBVN", "HELLOWORLD"));
    REQUIRE(testCipher(pc, CipherMode::Decrypt, "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA", "BOBISXSOMESORTOFIUNIORCOMPLEXQXENOPHONEONEZEROTHINGZ"));
    REQUIRE(testCipher(vc, CipherMode::Decrypt, "RIJVSUYVJN", "HELLOWORLD"));
}
