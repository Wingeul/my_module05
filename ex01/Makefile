# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paul <paul@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/09 18:14:41 by paul              #+#    #+#              #
#    Updated: 2025/06/18 18:42:08 by paul             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom du fichier source
SRC = main.cpp Bureaucrat.cpp Bureaucrat.hpp Form.cpp Form.hpp

# Nom du fichier exécutable
OUT = Form

# Flags de compilation
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Compilateur
CXX = c++

# Règle par défaut : compilé le programme
all: $(OUT)

# Règle pour générer l'exécutable
$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

# Règle pour nettoyer les fichiers générés
clean:
	rm -f $(OUT)

# Règle pour tout nettoyer (inclut le clean)
fclean: clean

# Règle pour recompiler
re: fclean all