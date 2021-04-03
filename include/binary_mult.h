
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdint.h>

const uint8_t s3g_poly = 0xA9;
const uint8_t aes_poly = 0x1B;

int filter(int argc, char *argv[])
{

  if (argc < 4)
  {
    std::cout << "ERROR: wrong execution input\n";
    std::cout << "USAGE: " << argv[0] << " [aes/s3g] [num1] [num2]\n";
    return 1;
  }

  if (std::string{argv[1]} != "aes" &&
      std::string{argv[1]} != "s3g")
  {
    std::cout << "ERROR: unknown algorithm byte input - "
                 "introduced "
              << argv[1] << "\n";
    std::cout << "USAGE: " << argv[0] << " [aes/s3g] [num1] [num2]\n";
    return 2;
  }

  if (std::string{argv[2]}.substr(0, 2) != "0x")
  {
    std::cout << "ERROR: expected hex format in numbers - "
                 "introduced "
              << argv[2] << " - expected 0xXX\n";
    std::cout << "USAGE: " << argv[0] << " [aes/s3g] [num1] [num2]\n";
    return 3;
  }

  if (std::string{argv[3]}.substr(0, 2) != "0x")
  {
    std::cout << "ERROR: expected hex format in numbers - "
                 "introduced "
              << argv[3] << " - expected 0xYY\n";
    std::cout << "USAGE: " << argv[0] << " [aes/s3g] [num1] [num2]\n";
    return 4;
  }

  if (std::string{argv[2]}.size() != 4)
  {
    std::cout << "ERROR: expected hex number of 8 bits - "
                 "introduced "
              << argv[2] << " - expected 0xXX\n";
    std::cout << "USAGE: " << argv[0] << " [aes/s3g] [num1] [num2]\n";
    return 5;
  }

  if (std::string{argv[3]}.size() != 4)
  {
    std::cout << "ERROR: expected hex number of 8 bits - "
                 "introduced "
              << argv[3] << " - expected 0xYY\n";
    std::cout << "USAGE: " << argv[0] << " [aes/s3g] [num1] [num2]\n";
    return 6;
  }

  return 0;
}

uint8_t byte_add(const uint8_t &a, const uint8_t &b)
{
  return a ^ b;
}

void gal_print(uint8_t a)
{
  int i = 8;
  while (i--)
    putchar((a >> i & 1) + '0');
}

uint8_t s3g_byte_mul(uint8_t &a, uint8_t &b)
{

  uint8_t prod;

  (b & (1 << 0)) == 1 ? prod = a : prod = 0x00;

  int k = 0;
  std::cout << "STEP " << k << ": \n";
  gal_print(a);
  std::cout << "\n";

  for (int i = 1; i < 8; i++)
  {
    if (((a & (1 << 7)) >> 7) == 0x01)
    {
      a <<= 1;
      std::cout << "STEP " << ++k << ": \n";
      gal_print(a);
      std::cout << " + ";
      gal_print(s3g_poly);
      std::cout << " = ";
      a = byte_add(a, s3g_poly);
      gal_print(a);
      std::cout << "\n";
    }
    else
    {
      a <<= 1;
      std::cout << "STEP " << ++k << ": \n";
      gal_print(a);
      std::cout << "\n";
    }
    if (((b & (1 << i)) >> i) == 0x01)
    {
      prod = byte_add(prod, a);
    }
  }
  return prod;
}

uint8_t aes_byte_mul(uint8_t &a, uint8_t &b)
{

  uint8_t prod;

  (b & (1 << 0)) == 1 ? prod = a : prod = 0x00;

  int k = 0;
  std::cout << "STEP " << k << ": \n";
  gal_print(a);
  std::cout << "\n";

  for (int i = 1; i < 8; i++)
  {
    if (((a & (1 << 7)) >> 7) == 0x01)
    {
      a <<= 1;
      std::cout << "STEP " << ++k << ": \n";
      gal_print(a);
      std::cout << " + ";
      gal_print(aes_poly);
      std::cout << " = ";
      a = byte_add(a, aes_poly);
      gal_print(a);
      std::cout << "\n";
    }
    else
    {
      a <<= 1;
      std::cout << "STEP " << ++k << ": \n";
      gal_print(a);
      std::cout << "\n";
    }
    if (((b & (1 << i)) >> i) == 0x01)
    {
      prod = byte_add(prod, a);
    }
  }
  return prod;
}
