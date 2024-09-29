valgrind	--suppressions=ignore_readline_leaks.txt \
		--leak-check=full \
		--show-leak-kinds=all \
		./minishell
