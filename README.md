# Default Error Tracer
Implementation of [Specification of Default Error Tracer AUTOSAR CP R20-11](https://www.autosar.org/fileadmin/user_upload/standards/classic/21-11/AUTOSAR_SWS_DefaultErrorTracer.pdf).

## Tools
 - Compiler: GCC
 - Static analysis: Cppcheck
 - Coverage: gcov, gcovr
 - Unit tests: Acutest
 - Mocks: fff

## Makefile
 - `make`, `make all` - build files and runs static analysis, tests, coverage and generates report
 - `make clean` - clean workspace
