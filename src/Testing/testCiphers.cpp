//! Generalised Unit Tests for MPAGSCipher Cipher Classes
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../MPAGSCipher/Cipher.hpp"
#include "../MPAGSCipher/CipherMode.hpp"
#include "../MPAGSCipher/CaesarCipher.hpp"
#include "../MPAGSCipher/PlayfairCipher.hpp"
#include "../MPAGSCipher/VigenereCipher.hpp"

bool testCipher( const Cipher& cipher, const CipherMode mode, const std::string& inputText, const std::string& outputText) {
    std::string testOutputText{cipher.applyCipher(inputText, mode)};
    if (testOutputText == outputText) {
        return true;
    } else {
        return false;
    }

}

TEST_CASE("All Cipher encryption", "[all ciphers]")
{
    CaesarCipher cc{10};
    PlayfairCipher pc{"hello"};
    VigenereCipher vc{"key"};
    REQUIRE(testCipher(cc, CipherMode::Encrypt, "HELLOWORLD", "ROVVYGYBVN"));
    REQUIRE(testCipher(pc, CipherMode::Encrypt, "BOBISSOMESORTOFJUNIORCOMPLEXXENOPHONEONEZEROTHING", "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA"));
    REQUIRE(testCipher(vc, CipherMode::Encrypt, "HELLOWORLD", "RIJVSUYVJN"));
}

TEST_CASE("All Cipher decryption", "[all ciphers]")
{
    CaesarCipher cc{10};
    PlayfairCipher pc{"hello"};
    VigenereCipher vc{"key"};
    REQUIRE(testCipher(cc, CipherMode::Decrypt, "ROVVYGYBVN", "HELLOWORLD"));
    REQUIRE(testCipher(pc, CipherMode::Decrypt, "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA", "BOBISXSOMESORTOFIUNIORCOMPLEXQXENOPHONEONEZEROTHINGZ"));
    REQUIRE(testCipher(vc, CipherMode::Decrypt, "RIJVSUYVJN", "HELLOWORLD"));
}
