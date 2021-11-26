#include "Alphabet.hpp"
#include "CaesarCipher.hpp"
#include "VigenereCipher.hpp"

#include <algorithm>
#include <map>
#include <string>

VigenereCipher::VigenereCipher ( const std::string& key )
{
    // Set the given key
    setKey(key);
}

void VigenereCipher::setKey( const std::string& key )
{
    // Store the key
    key_ = key;

    // Make sure the key is uppercase
    std::transform(std::begin(key_), std::end(key_), std::begin(key_),
                   ::toupper);

    // Remove non-alphabet characters
    key_.erase(std::remove_if(std::begin(key_), std::end(key_),
                              [](char c) { return !std::isalpha(c); }),
               std::end(key_));

    // Check if the key is empty and replace with default if so
    if (key_.empty()) {
        key_ = 'A';
    }

    // loop over the key
    for (std::size_t i{0}; i < key_.length(); ++i) {

        // Find the letter position in the alphabet
        size_t letterPos{0};
        for (std::size_t j{0}; j < Alphabet::alphabet.length(); ++j) {
            if (key_[i] == Alphabet::alphabet[j]) {
                letterPos = j;
                break;
            }
        }

        // Create a CaesarCipher using this position as a key
        CaesarCipher casearCipher_i{letterPos};

        // Insert a std::pair of the letter and CaesarCipher into the lookup
        std::pair<char, CaesarCipher> pair_i{key_[i], casearCipher_i};
        charLookup_.insert(pair_i);

    }

}

std::string VigenereCipher::applyCipher( const std::string& inputText, const CipherMode cipherMode ) const
{
    std::string outputText{""};
    std::size_t keyLength_ = key_.length();

    // For each letter in input:
    for (std::size_t i{0}; i < inputText.length(); ++i) {

        // Find the corresponding letter in the key, repeating/truncating as required
        size_t keyPosition{i%keyLength_};
        char keyLetter{key_[keyPosition]};

        // Find the Caesar cipher from the lookup
        CaesarCipher caesarCipher_i{charLookup_.at(keyLetter)};

        // Run the (de)encryption
        std::string inputLetter{inputText[i]};
        std::string encryptedLetter{caesarCipher_i.applyCipher(inputLetter, cipherMode)};

        // Add the result to the output
        outputText += encryptedLetter;

    }

    return outputText;
}