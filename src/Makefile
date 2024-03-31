CC = gcc
ASAN = -g -fsanitize=address
FLAG_COV = --coverage
FLAG_ER = -Wall -Werror -Wextra -std=c11
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes
BACKDIR = BACKEND
OUTDIR = BUILD
TESTDIR = TESTS
TESTS_C = $(TESTDIR)/suite_*.c $(TESTDIR)/tests.c
s21_CALC_C = $(BACKDIR)/s21_*.c
SUITE_CASES_O = suite_*.o
FLAG_TESTS = -lcheck -lm -lgcov -lsubunit


all: gcov_report

test:
	mkdir BUILD
	for file in $(TESTS_C); do \
		$(CC) -c $(FLAG_ER) -c -o $(OUTDIR)/$$(basename $$file .c).o $$file; \
	done
	$(CC) $(FLAG_ER) $(FLAG_COV) -o $(OUTDIR)/tests $(s21_CALC_C) $(OUTDIR)/tests.o $(OUTDIR)/$(SUITE_CASES_O) $(FLAG_TESTS)
	./$(OUTDIR)/tests

asan:
	for file in $(TESTS_C); do \
		$(CC) -c $(FLAG_ER) -c -o $(OUTDIR)/$$(basename $$file .c).o $$file; \
	done
	$(CC) $(FLAG_ER) $(FLAG_COV) -o $(OUTDIR)/tests $(s21_CALC_C) $(OUTDIR)/tests.o $(OUTDIR)/$(SUITE_CASES_O) $(FLAG_TESTS) $(ASAN)
	./$(OUTDIR)/tests

valgrind_test:
	for file in $(TESTS_C); do \
		$(CC) -c $(FLAG_ER) -c -o $(OUTDIR)/$$(basename $$file .c).o $$file -g; \
	done
	$(CC) $(FLAG_ER) $(FLAG_COV) -o $(OUTDIR)/tests $(s21_CALC_C) $(OUTDIR)/tests.o $(OUTDIR)/$(SUITE_CASES_O) $(FLAG_TESTS)
	valgrind $(VALGRIND_FLAGS) ./$(OUTDIR)/tests

gcov_report: clean test
	gcovr --html-details -o $(OUTDIR)/report.html

install:
	mkdir Qt/Calculator
	cp Qt/S21_Calc_1/* Qt/Calculator/. 
	qmake -o Qt/Calculator/Makefile Qt/Calculator/S21_Calc_1.pro
	cd Qt/Calculator/; make
	cp Qt/Calculator/S21_Calc_1 ./

uninstall:
	rm -rf Qt/Calculator
	rm -rf S21_Calc_1

dist:
	tar -czf SmartCalc.install.tar.gz ./*

dvi:
	open ./instruction.md

cpp_check:
	cppcheck --enable=all --force $(BACKDIR)/*.h $(BACKDIR)/*.c

style_check:
	cp ../materials/linters/.clang-format ./
	clang-format -n $(BACKDIR)/*.c
	clang-format -i $(BACKDIR)/*.c
	rm -rf .clang-format

clean:
	-rm -rf $(OUTDIR)/*.o $(OUTDIR)/*.html $(OUTDIR)/*.gcda $(OUTDIR)/*.gcno $(OUTDIR)/*.css $(OUTDIR)/*.a $(OUTDIR)/*.gcov $(OUTDIR)/*.info $(OUTDIR)/*.out $(OUTDIR)/*.cfg $(OUTDIR)/*.txt
	-rm -rf $(OUTDIR)/tests
	-rm -rf BUILD
	-rm -rf Qt/build-S21_Calc_1-Desktop-Debug
	-rm -rf SmartCalc.install.tar.gz
	-rm -rf .qmake.stash
