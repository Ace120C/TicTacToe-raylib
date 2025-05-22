default:
	gcc main.c -lraylib -lGL -lm -Llib -Iinclude -lpthread -ldl -lrt -lX11 -o game
