CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla
EXEC = a4q1
OBJECTS = main.o expression.o var.o integer.o binary.o unary.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
