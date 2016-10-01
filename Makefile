ASTYLE_OPTIONS = --style=allman --indent=spaces=4 --indent-namespaces --align-pointer=type --align-reference=type --formatted

all: documentation.pdf

documentation.pdf: doc/latex/refman.tex
	cd doc/latex && pdflatex refman.tex &> /dev/null && pdflatex refman.tex &> /dev/null
	mv doc/latex/refman.pdf documentation.pdf

doc/latex/refman.tex: Doxyfile app/* audio/* core/* gfx/*
	doxygen Doxyfile

.PHONY: format

format:
	find . -type f \( -name '*.h' -or -name '*.cpp' \) | xargs astyle ${ASTYLE_OPTIONS}
