G++ = g++ -std=c++17
CHECKFLAGS = -Wall -Werror -Wextra
TEST_LIBS = -lgtest -pthread
TEST_SRC = GTest/*.cc
TEST_NAME = test

ifeq ($(OS), Darwin)
	NAME_APP=FreshViewer.app
else
	NAME_APP=FreshViewer
endif

P_NAME = FreshViewer
P_VIEW_DIR = Views
P_BUILD_DIR = build
P_DOCS_DIR = Docs



all: clean test install

install:
	rm -rf $(P_BUILD_DIR)
	cmake -S $(P_VIEW_DIR) -B $(P_BUILD_DIR) #--debug-find-pkg=Qt6Widgets
	make -C $(P_BUILD_DIR) FreshViewer

uninstall:
	rm -rf $(P_BUILD_DIR)*
	rm -rf $(P_VIEW_DIR)/moc*
	rm -rf $(P_VIEW_DIR)/*.o
	# rm -rf $(P_VIEW_DIR)/ui*

doxygen:
	rm -rf $(P_DOCS_DIR)
	doxygen Doxyfile
	echo "Documentation created ($(PWD)/$(P_DOCS_DIR)/html/annotated.html)."

dvi: doxygen
	open ./$(P_DOCS_DIR)/html/annotated.html

dist: install
	rm -rf FreshViewer_archive/
	mkdir FreshViewer_archive/
	mkdir FreshViewer_archive/src
	cp -r ./build/$(NAME_APP) FreshViewer_archive/src/
	tar cvzf FreshViewer_archive.tgz FreshViewer_archive/
	rm -rf FreshViewer_archive/

test: 
	$(G++) $(CHECKFLAGS) $(TEST_SRC) -o $(TEST_NAME) $(TEST_LIBS) -g
	./$(TEST_NAME) --gtest_break_on_failure

clean: uninstall
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

gtest_install:
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

doxygen_install:
	echo -e "\e[32m[---Start install doxygen---]\e[0m"
	sudo apt-get install doxygen
	echo -e "\e[32m[---Done---]\e[0m"
	
