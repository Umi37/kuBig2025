CC = gcc
CFLAGS = -I/opt/homebrew/Cellar/mysql-client/9.2.0/include
LDFLAGS = -L/opt/homebrew/Cellar/mysql-client/9.2.0/lib -lmysqlclient
TARGET = mySQLtest
SRC = mySQLtest.c

all:
	$(CC) -o $(TARGET) $(SRC) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(TARGET)
