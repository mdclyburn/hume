all: documentation.pdf

documentation.pdf: doc/latex/refman.tex
	cd doc/latex && pdflatex refman.tex &> /dev/null && pdflatex refman.tex &> /dev/null
	mv doc/latex/refman.pdf documentation.pdf

doc/latex/refman.tex: Doxyfile app/* audio/* core/* gfx/*
	doxygen Doxyfile
