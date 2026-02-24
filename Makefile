NAME = push_swap
BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror

COMMON_SRC = info.c \
	target.c \
	cost.c \
	rot.c \
	rev_rot.c \
	sort.c \
	push.c \
	swap.c \
	exe.c \
	utils.c \
	parse.c \
	index.c \
	error.c \
	libft/ft_atol.c \
	libft/ft_lstadd_back.c \
	libft/ft_lstclear.c \
	libft/ft_lstnew.c \
	libft/ft_lstsize.c \
	libft/ft_calloc.c \
	libft/ft_bzero.c \
	libft/ft_split.c

SRC = main.c \
	$(COMMON_SRC)

BONUS_SRC = bonus/ceccherino.c \
	bonus/ceccherino_mosse.c \
	$(COMMON_SRC)

OBJ = $(SRC:.c=.o)

BONUS_OBJ  = $(BONUS_SRC:.c=.o)

# Colori
GREEN = \033[1;32m
RESET = \033[0m

# Arte ASCII
define ASCII_ART
      ___           ___                       ___           ___                                 
     /\  \         /\  \          ___        /\__\         /\  \          ___                   
    /::\  \       /::\  \        /\  \      /::|  |       /::\  \        /\  \\                  
   /:/\ \  \     /:/\:\  \       \:\  \    /:|:|  |      /:/\:\  \       \:\  \\                 
  _\:\~\ \  \   /::\~\:\  \      /::\__\  /:/|:|  |__   /:/  \:\  \      /::\__\\                
 /\ \:\ \ \__\ /:/\:\ \:\__\  __/:/\/__/ /:/ |:| /\__\ /:/__/_\:\__\  __/:/\/__/                
 \:\ \:\ \/__/ \/__\:\/:/  / /\/:/  /    \/__|:|/:/  / \:\  /\ \/__/ /\/:/  /                   
  \:\ \:\__\        \::/  /  \::/__/         |:/:/  /   \:\ \:\__\   \::/__/                    
   \:\/:/  /         \/__/    \:\__\         |::/  /     \:\/:/  /    \:\__\                    
    \::/  /                    \/__/         /:/  /       \::/  /      \/__/                    
     \/__/                                   \/__/         \/__/                                

      ___           ___           ___           ___                                     ___     
     /  /\         /  /\         /  /\         /__/\         _____        ___          /  /\\    
    /  /:/_       /  /:/        /  /::\       |  |::\       /  /::\      /  /\        /  /::\\   
   /  /:/ /\     /  /:/        /  /:/\:\      |  |:|:\     /  /:/\:\    /  /:/       /  /:/\:\\  
  /  /:/ /::\   /  /:/  ___   /  /:/~/::\   __|__|:|\:\   /  /:/~/::\  /__/::\      /  /:/~/::\\ 
 /__/:/ /:/\:\ /__/:/  /  /\ /__/:/ /:/\:\ /__/::::| \:\ /__/:/ /:/\:| \__\/\:\__  /__/:/ /:/\:\\
 \  \:\/:/~/:/ \  \:\ /  /:/ \  \:\/:/__\/ \  \:\~~\__\/ \  \:\/:/~/:/    \  \:\/\ \  \:\/:/__\/
  \  \::/ /:/   \  \:\  /:/   \  \::/       \  \:\        \  \::/ /:/      \__\::/  \  \::/     
   \__\/ /:/     \  \:\/:/     \  \:\        \  \:\        \  \:\/:/       /__/:/    \  \:\\     
     /__/:/       \  \::/       \  \:\        \  \:\        \  \::/        \__\/      \  \:\\    
     \__\/         \__\/         \__\/         \__\/         \__\/                     \__\/    
                                                                                                
endef
export ASCII_ART

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)$$ASCII_ART$(RESET)"
	@echo "$(GREEN)Compilazione eseguita con successo!$(RESET)"

bonus: $(BONUS)

$(BONUS): $(BONUS_OBJ)
	@$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(BONUS)
	@echo "$(GREEN)"
	@echo "Verificatore compilato con successo!"
	@echo "$(RESET)"

# Regola per compilare un file oggetto da un file sorgente
# Cfr. https://www.gnu.org/software/make/manual/make.html#Automatic-Variables
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

re_bonus: fclean bonus

valgrind: $(NAME)
	@ARG=$$(shuf -i 0-2000 -n 100 | tr '\n' ' '); \
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $$ARG

rand100: $(NAME)
	@ARG=$$(python3 -c "import random; print(' '.join(map(str, random.sample(range(0, 100), 100))))"); \
	./$(NAME) $$ARG; \
	echo "\n--- NUMERI IN INGRESSO ---\n$$ARG"

rand500: $(NAME)
	@ARG=$$(python3 -c "import random; print(' '.join(map(str, random.sample(range(0, 500), 500))))"); \
	./$(NAME) $$ARG; \
	echo "\n--- NUMERI IN INGRESSO ---\n$$ARG"

test100: $(NAME)
	@echo "Eseguendo 100 prove con 100 interi casuali. Attendi..."
	@for i in $$(seq 1 100); do \
		ARG=$$(shuf -i 0-100 -n 100 | tr '\n' ' '); \
		./$(NAME) $$ARG | wc -l; \
	done | awk '{sum+=$$1; if($$1>700) fail++; if(NR==1 || $$1<min) min=$$1; if(NR==1 || $$1>max) max=$$1} END {print "Min: " min ", Max: " max ", Media: " int(sum/NR) " | >700: " fail+0 "/100"}'

test500: $(NAME)
	@echo "Eseguendo 100 prove con 500 interi casuali. Attendi..."
	@for i in $$(seq 1 100); do \
		ARG=$$(shuf -i 0-500 -n 500 | tr '\n' ' '); \
		./$(NAME) $$ARG | wc -l; \
	done | awk '{sum+=$$1; if($$1>5500) fail++; if(NR==1 || $$1<min) min=$$1; if(NR==1 || $$1>max) max=$$1} END {print "Min: " min ", Max: " max ", Media: " int(sum/NR) " | >5500: " fail+0 "/100"}'

# test500stats: $(NAME)
# 	@echo "Esecuzione di 500 test con 500 numeri (Attendere, operazione lunga)..."
# 	@count=0; \
# 	moves=""; \
# 	for i in $$(seq 1 500); do \
# 		arg=$$(shuf -i 0-2147483647 -n 500 | tr '\n' ' '); \
# 		ops=$$(./$(NAME) $$arg 2>&1); \
# 		num_ops=$$(echo "$$ops" | grep -v "STACK IS SORTED" | grep -v "Error" | grep -v "^$$" | wc -l); \
# 		if [ $$num_ops -gt 5500 ]; then \
# 			printf "\n[Attenzione] Trovato caso pessimo (%d mosse > 5500):\n" $$num_ops; \
# 			echo "$$arg"; \
# 			echo ""; \
# 		fi; \
# 		moves="$$moves $$num_ops"; \
# 		count=$$((count + 1)); \
# 		printf "\rProgresso: %d/500" $$count; \
# 	done; \
# 	echo ""; \
# 	max=$$(echo $$moves | tr ' ' '\n' | sort -rn | head -n1); \
# 	min=$$(echo $$moves | tr ' ' '\n' | sort -n | head -n1); \
# 	avg=$$(echo $$moves | tr ' ' '\n' | awk '{sum+=$$1} END {if (NR>0) printf "%.0f", sum/NR}'); \
# 	echo "---------------------------"; \
# 	echo "Statistiche su 500 iterazioni:"; \
# 	echo "Mosse massime: $$max"; \
# 	echo "Mosse minime:  $$min"; \
# 	echo "Mosse medie:   $$avg"; \
# 	echo "---------------------------"

.PHONY: all clean fclean re valgrind