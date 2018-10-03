NAME = pam_spy.so
CFLAGS += -fPIC -Wextra -Wall
LDFLAGS = -lpam


INCDIR = include
INCFILES = pam_spy.h
INCFULL = $(addprefix $(INCDIR)/, $(INCFILES))
INC = $(addprefix -I, $(INCDIR)) $(LIBINC)
SRCDIR = src

SRC = webcam.c \
      timestamp.c \
      pam.c

VPATH= $(SRCDIR)
OBJDIR = obj
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

.PHONY: all lib clean fclean re

all:
	@$(MAKE) $(NAME)

install:
	install -g root -o root $(NAME) /usr/lib/security

$(NAME): $(OBJ) $(LIBAR)
	$(CC) -shared $(CFLAGS) $(OBJ) $(LDFLAGS) -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.c $(INCFULL) | $(OBJDIR)
	$(CC) $(CFLAGS) $(LDFLAGS) -c -o $@ $< $(INC)

clean:
	$(RM) -r $(OBJDIR)

fclean:
	$(RM) -r $(OBJDIR) $(NAME)

re:
	@$(MAKE) --no-print-directory fclean
	@$(MAKE) --no-print-directory
