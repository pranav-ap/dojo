```cmd
# 1. Build std module (once per project dir)
>> g++ -std=c++23 -fmodules -fsearch-include-path bits/std.cc -c -fmodule-only 

# 2. Compile the module interface FIRST
>> g++ -std=c++23 -fmodules -c employee.cppm

# 3. Compile the importer + link everything
>> g++ -std=c++23 -fmodules cpp_2_struct.cpp employee.o -o a.out

# 4. Run
>> ./a.out
```
