#ifndef MPAGSCIPHER_CIPHER_HPP
#define MPAGSCIPHER_CIPHER_HPP

#include "CipherMode.hpp"

#include <string>

/**
 * \file Cipher.hpp
 * \brief Contains the declaration of the Purely Abstract Base class for the ciphers
 */

/**
 * \class Cipher
 * \brief Purely Abstract Base class for the different available ciphers
 */
class Cipher {
  public:
    /**
     * \brief Empty constructor (Compiler-provided special function)
     */
    Cipher() = default;
    
    /**
     * \brief Copy constructor (Compiler-provided special function)
     */
    Cipher(const Cipher& rhs) = default;
    
    /**
     * \brief Move constructor (Compiler-provided special function)
     */
    Cipher(Cipher&& rhs) = default;
    
    /**
     * \brief Copy assignment operator (Compiler-provided special function)
     */
    Cipher& operator=(const Cipher& rhs) = default;
    
    /**
     * \brief Move assignment operator (Compiler-provided special function)
     */
    Cipher& operator=(Cipher&& rhs) = default;
    
    /**
     * \brief Destructor (Compiler-provided special function)
     */
    virtual ~Cipher() = default;
    
    /**
     * \brief Function to encrypt and decrypt the supplied text.
     *
     * \param input the text to encrypt or decrypt
     * \param Mode whether to encrypt or decrypt the input text
     * \return the result of applying the cipher to the input text
     */
    virtual std::string applyCipher( const std::string& input, const CipherMode mode ) const = 0;

  private:

};

#endif