all: cbuild/teste_exemplo
	
# executa o teste
test: cbuild/teste_exemplo
	./cbuild/teste_exemplo

# teste estatico
cppcheck:
	cd src; cppcheck *

# teste de cobertura
gcovr: test
	gcovr

# teste de cobertura com saida em html
gcovr-html: test
	gcovr --html-details coverage.html
	firefox coverage.html

# teste de complexidade ciclomatica
lizard:
	cd ./src; lizard

# cria a pasta cbuild (build reservado para CMakeLists)
cbuild:
	mkdir -p cbuild

# compila
cbuild/teste_exemplo: cbuild tests/teste_exemplo.cpp src/exemplo.cpp
	g++ tests/teste_exemplo.cpp src/exemplo.cpp -o ./cbuild/teste_exemplo --coverage -g -O0 -lCppUTest -lCppUTestExt -I ./src