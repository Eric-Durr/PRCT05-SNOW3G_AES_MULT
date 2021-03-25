# SSI P05 - MULTIPLICACIÓN EN SNOW 3G y AES

## Estructura del repositorio:

```SQL
prct05-multSNOW3G-AES/
├─ docs/                                        # Project documentation folder
│  ├─ PracticaProducto-SNOW3G-AES.pdf           ## P05 - assignment
├─ include/                                     # Library files folder
│  ├─ Catch2/catch.h                            ## C++ TDD testing framework
│  ├─ binary_mult.h                             #
├─ src/                                         # Source files folder
│  ├─ binary_mult.cpp                           ## main program source file
├─ test/                                        # Test files folder
│  ├─ binary_mult.test.h                        ##  
│  ├─ includer.test.cpp                         ## Tests core file 
├─ .gitignore                                   # Ignored files git config file
├─ makefile                                     # C++ tasks automation file
├─ README.md                                    # Front repository information file
```

## Uso

### **Compilación del ejecutable**

```bash
$ make
```

### **Ejecución del programa**
./binary_mult


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

## Licencia

[MIT](https://choosealicense.com/licenses/mit/)

## Autoría

- Eric Dürr Sierra - [alu0101027005](alu0101027005@ull.edu.es)
