G++ = g++ -std=c++17
CHECKFLAGS = -Wall -Werror -Wextra
TEST_LIBS = -lgtest -pthread
TEST_SRC = GTest/*.cc
TEST_NAME = test

ifeq ($(OS), Darwin)
	NAME_APP=3DViewerV2.app
else
	NAME_APP=3DViewerV2
endif

P_NAME = FreshViewer
P_VIEW_DIR = Views
P_BUILD_DIR = build
P_DOCS_DIR = Docs



all: clean test

install:
	rm -rf build
	mkdir build
	cd Views && qmake && make && mv 3DViewer.app ../build && cd ..

uninstall:
	rm -rf build*
	rm -rf qt_files/moc*
	rm -rf qt_files/*.o
	rm -rf qt_files/ui*

doxygen:
	rm -rf $(P_DOCS_DIR)
	doxygen Doxyfile
	echo "Documentation created ($(PWD)/$(P_DOCS_DIR)/html/annotated.html)."

dvi: doxygen
	open ./$(P_DOCS_DIR)/html/annotated.html

dist: install
	rm -rf Archive_3DViewer/
	mkdir Archive_3DViewer/
	mkdir Archive_3DViewer/src
	cp -r ./build/3DViewer.app Archive_3DViewer/src/
	tar cvzf Archive_3DViewer.tgz Archive_3DViewer/
	rm -rf Archive_3DViewer/

test: 
	$(G++) $(CHECKFLAGS) $(TEST_SRC) -o $(TEST_NAME) $(TEST_LIBS) -g
	./$(TEST_NAME) --gtest_break_on_failure

clean:
	@echo "\e[32mClean s in progress...\e[0m"
	rm -rf lib_obj test lib/*.o ./*.a ./*.o ./a.out gcov_test *.html *.css report lib/*.dSYM ./*.gcno ./*.gcda ./*.info ./*.dSYM ./CPPLINT*
	@echo "\e[32mClean done!\e[0m"

gcov_report: clean
	$(G++) $(CHECKFLAGS) $(TEST_SRC) $(TEST_LIBS) -coverage -o gcov_test
	chmod +x *
	./gcov_test
	lcov -t "gcov_test" -o gcov_test.info --no-external -c -d .
	genhtml -o report/ gcov_test.info
	open ./report/index.html

format: 
	clang-format -style=google -i */*.cc
	clang-format -style=google -i */*.h
	clang-format -style=google -i */*.tpp

clang-format: 
	clang-format -style=google -n */*.cc
	clang-format -style=google -n */*.h
	clang-format -style=google -n */*.tpp

fsanitize: 
	$(G++) $(TEST_SRC) $(CHECKFLAGS) -g -fsanitize=address $(TEST_LIBS) -o $(TEST_NAME) 
	./$(TEST_NAME)

valgrind: test
	valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(TEST_NAME)

GTest_install:
	echo -e "\e[32m[---Start install GTest lib ubuntu20---]\e[0m"
	sudo apt-get install libgtest-dev libgmock-dev
	sudo apt-get install libtbb-dev
	sudo apt-get install cmake
	cd /usr/src/googletest/
	sudo mkdir build
	cd build
	sudo cmake ..
	sudo make
	cd ..
	sudo cp lib/* /usr/lib
	echo -e "\e[32m[---Done---]\e[0m"
