# SSI P05 - MULTIPLICACIÓN EN SNOW 3G y AES

## Estructura del repositorio:

```
prct05-multSNOW3G-AES/
├─ docs/                                        # Project documentation folder
│  ├─ html/                                     ## Generated documentation  
├─ include/                                     # Library files folder
│  ├─ Catch2/catch.h                            ## C++ TDD testing framework
│  ├─ binary_mult.h                             #
│  ├─ lfsr.h                                    # LFSR class template file
├─ src/                                         # Source files folder
│  ├─ binary_mult.cpp                           ## main program source file
├─ test/                                        # Test files folder
│  ├─ binary_mult.test.h                        ##  
│  ├─ lfsr.test.h                               ## Tests for LFSR class template  
│  ├─ includer.test.cpp                         ## Tests core file 
├─ .gitignore                                   # Ignored files git config file
├─ makefile                                     # C++ tasks automation file
├─ Doxyfile                                     # Doxygen configuration file 
├─ PracticaProducto-SNOW3G-AES.pdf              # P05 - assignment
├─ README.md                                    # Front repository information file
```

## Uso

### **Compilación del ejecutable**

```bash
$ make
```

### **Ejecución del programa**

```bash
./binary_mult <aes/s3g> <num1> <num2> [trace]
```

**Ejemplos**

```bash
./binary_mult aes 0x57 0x83 

---- P05 AES MULT ----
result :11000001

```

```bash
./binary_mult s3g 0x57 0x83 

---- P05 SNOW 3G MULT ----
result :10010110

```

```bash
./binary_mult s3g 0x57 0x83 trace 

---- P05 SNOW 3G MULT ----
STEP 0: 
01010111
STEP 1: 
10101110
STEP 2: 
01011100 + 10101001 = 11110101
STEP 3: 
11101010 + 10101001 = 01000011
STEP 4: 
10000110
STEP 5: 
00001100 + 10101001 = 10100101
STEP 6: 
01001010 + 10101001 = 11100011
STEP 7: 
11000110 + 10101001 = 01101111
result :10010110


```

### **Lanzamiento de los tests**
```bash
$ make test
```

Se compila y ejecuta el conjunto de tests para luego ejecutarlos, de suceder satisfactoriamente debe aparecer lo siguiente por terminal:

```bash
Making tests: hash_simulator_test
g++ -o binary_mult_test ./src/entorno.cpp ./src/hormiga.cpp ./test/includer.test.cpp
./binary_mult_test
===============================================================================
All tests passed (38 assertions in 2 test cases)
```

También se puede ejecutar un despliegue detallado de los tests si ya se ha lanzado el comando anterior:

```bash
$ ./binary_mult_test -s
```

## Referencias y enlaces:

- [Enlace al repositorio](https://github.com/Eric-Durr/PRCT05-SNOW3G_AES_MULT)
- [Tutorial de Doxygen para C++](https://caiorss.github.io/C-Cpp-Notes/Doxygen-documentation.html)

**[Documentación online](https://eric-durr.github.io/PRCT05-SNOW3G_AES_MULT/)**

## Licencia

[MIT](https://choosealicense.com/licenses/mit/)

## Autoría

- Eric Dürr Sierra - [alu0101027005](alu0101027005@ull.edu.es)

