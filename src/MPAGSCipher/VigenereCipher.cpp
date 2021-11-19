#include "VigenereCipher.hpp"
#include "Alphabet.hpp"

#include <algorithm>
#include <string>

VigenereCipher::VigenereCipher ( const std::string& key )
{
    // Set the given key
    setKey(key);
}

void VigenereCipher::setKey( const std::string& key )
{
    key_ = key;
}

std::string VigenereCipher::applyCipher( const std::string& inputText, const CipherMode /*cipherMode*/ ) const
{
    return inputText;
}