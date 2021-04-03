#include "../include/binary_mult.h"

typedef uint8_t gal8; /* Galois field of order 2^8 */

int main(int argc, char *argv[])
{
  int flag = filter(argc, argv);
  if (flag != 0)
  {
    return flag;
  }

  if (std::string{argv[1]} == "aes")
    std::cout << "\n---- P05 AES MULT ----\n";
  else
    std::cout << "\n---- P05 SNOW 3G MULT ----\n";

  uint8_t a = std::stoi(std::string{argv[2]}.substr(2, 2), 0, 16);
  uint8_t b = std::stoi(std::string{argv[3]}.substr(2, 2), 0, 16);

  uint8_t prod = std::string{argv[1]} == "aes" ? aes_byte_mul(a, b) : s3g_byte_mul(a, b);

  std::cout << "result :";
  gal_print(prod);
  std::cout << "\n";
  return 0;
}