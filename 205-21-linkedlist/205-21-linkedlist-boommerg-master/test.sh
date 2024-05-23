#!/bin/sh
set -e # аварийно завершить работу, если программа вернёт ошибку
# если вы тестируете случай, при котором ваша программа должна завершиться с ошибкой,
# укажите это в виде отрицания перед командой:
# ! ./main ...

# Запуск тестов
./main < fixtures/test1.in.txt
./main < fixtures/test2.in.txt
./main < fixtures/test3.in.txt
./main < fixtures/test4.in.txt
./main < fixtures/test5.in.txt
./main < fixtures/test6.in.txt
./main < fixtures/test7.in.txt
./main < fixtures/test8.in.txt
./main < fixtures/test9.in.txt
./main < fixtures/test10.in.txt
./main < fixtures/test11.in.txt
./main < fixtures/test12.in.txt