ASTYLE_OPTIONS = --style=allman --indent=spaces=4 --indent-namespaces --align-pointer=type --align-reference=type --formatted

all: documentation.pdf

cppcheck.xml:
	cppcheck --xml --xml-version=2 --language=c++ --enable=warning,style,performance,portability --inconclusive -i build . 2>cppcheck.xml

documentation.pdf: doc/latex/refman.tex
	cd doc/latex && pdflatex refman.tex && pdflatex refman.tex
	mv doc/latex/refman.pdf documentation.pdf

doc/latex/refman.tex: Doxyfile app/* audio/* core/* gfx/*
	doxygen Doxyfile

.PHONY: clean format

clean:
	rm -rf build doc

format:
	find . -type f \( -name '*.h' -or -name '*.cpp' \) | xargs astyle ${ASTYLE_OPTIONS}
