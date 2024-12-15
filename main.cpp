#include <iostream>
#include <unistd.h>
#include <cctype>
#include <cstdio>
#define uint unsigned int

#ifdef _WIN32
    #include <windows.h>
    #include <conio.h>
    #define CLEAR "cls"
    #define PAUSE system("pause");
    #define GETCHAR getch()
#else
    #define CLEAR "clear"
    #define PAUSE std::cin.get();
    #include <termios.h>
    #define GETCHAR getchar()
#endif

void PrintImage (char board[17][17], uint x = 17, uint y = 17, bool noPauses = false, std::string message = "", uint highlightX = -1, uint highlightY = -1) {
    system (CLEAR);
    std::cout << "   ";
    for (uint i = 0; i < 17; i++) {
        if (i == x) printf("\x1B[42m%02d\033[0m", i);
        else printf("%02d", i);
    }
    printf("\n");
    for (int i = 0; i < 17; i ++){
        if (y == i) printf("\x1B[42m%02d\033[0m|", i);
        else printf("%02d|", i);
        for (int j = 0; j < 17; j ++){
            if (i == highlightY && j == highlightX) {
                std::cout << "\x1B[47m  \033[0m";
                continue;
            }
            switch (board[i][j]) {
                case ' ': {
                    std::cout << "  ";
                    break;
                }
                case '#': {
                    std::cout << "\x1B[41m  \033[0m";
                    break;
                }
                case '@': {
                    std::cout << "\x1B[44m  \033[0m";
                    break;
                }
                case '^': {
                    std::cout << "\x1B[42m  \033[0m";
                    break;
                }
            }
        }
        printf("|\n");
        if (i == 16) {
            if (y != 17 && x != 17)
                printf("X : %02d; Y : %02d\n", x, y);
            std::cout << message;
        }
    }

    if (!noPauses) PAUSE;
}

void Fill (uint x, uint y, char board[17][17]) {
    if (x == 0 || y == 0 || x == 16 || y == 16) {
        board[y][x] = '#';
        return;
    }
    char c = board[y][x];
    if (c != '#' && c != '@'){
        board[y][x] = '@';
        PrintImage(board, x , y);
        Fill (x - 1, y, board);
        Fill (x + 1, y, board);
        Fill (x, y - 1, board);
        Fill (x, y + 1, board);
    }
}

void Paint1 () {
    char board[17][17] = {
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', '#', ' ', ' ', '#', '#', '#', ' ', ' ', '#', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' '},
        {' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' '},
        {' ', '#', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', '#', ' '},
        {' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#', ' '},
        {' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#', ' '},
        {' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#', ' '},
        {' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#', ' '},
        {' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#', ' '},
        {' ', '#', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', '#', ' '},
        {' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' '},
        {' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' '},
        {' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' '},
        {' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };
    Fill (10, 3, board);
}

void Paint2 () {
    char board[17][17] = {
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', '#', ' ', ' ', '#', '#', '#', ' ', ' ', '#', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' '},
        {' ', ' ', '#', ' ', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' '},
        {' ', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' '},
        {' ', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' '},
        {' ', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' '},
        {' ', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' '},
        {' ', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' '},
        {' ', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' '},
        {' ', '#', ' ', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' '},
        {' ', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' '},
        {' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };
    Fill (2, 5, board);
    PrintImage (board);
}

void UserImage () {
    std::cout << "\nВВОД РИСУНКА.\nИнструкция:\n1. Введите # чтобы создать границу\n2. Нажмите ^ чтобы обозначить стартовую точку\n3. Стартовая точка не может быть расположена на границе рисунка\n4. Стартовая точка может быть только одна\n";
    PAUSE;
    const char _template[17][17] = {
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };
    char board[17][17] = {};
    std::copy(&_template[0][0], &_template[0][0]+17*17,&board[0][0]);

    int startPointX = -1, startPointY = -1;
    bool startPaint = false;
    int y = 0, x = 0;

    while (!startPaint) {
        PrintImage(board, x, y, true, "r - Стереть рисунок\nf - Стереть строку\nq - Вернуться в меню\nb - Начать закраску\nw, s, a, d - Вверх, вниз, влево, вправо", x, y);
        switch (GETCHAR) {
            case '#': {
                if (board[y][x] == '^') {
                    startPointX = -1;
                    startPointY = -1;
                }
                board[y][x++] = '#';
                break;
            }
            case ' ': {
                if (board[y][x] == '^') {
                    startPointX = -1;
                    startPointY = -1;
                }
                board[y][x++] = ' ';
                break;
            }
            case '^': {
                if (y != 0 && x != 0 && y != 16 && x != 16) {
                    if (startPointX != -1 && startPointY != -1) board[startPointY][startPointX] = ' ';
                    board[y][x] = '^';
                    startPointX = x ++;
                    startPointY = y;
                }
                break;
            }
            case 'r': {
                y = 0;
                x = 0;
                std::copy(&_template[0][0], &_template[0][0]+17*17,&board[0][0]);
                break;
            }
            case 'f': {
                x = 0;
                std::copy(&_template[y][0], &_template[y][16], &board[y][0]);
                break;
            }
            case 'b': {
                if (startPointX == -1 && startPointY == -1) {
                    std::cout << "\n\033[37m\033[41mНет стартовой точки!!!\033[0m\n";
                    PAUSE;
                }
                else startPaint = true;
                break;
            }
            case 'w': {
                y --;
                break;
            }
            case 's': {
                y ++;
                break;
            }
            case 'a': {
                x --;
                break;
            }
            case 'd': {
                x ++;
                break;
            }
            case 'q': {
                return;
            }
            default: break;
        }
        if (y == 16 && x == 16) {
            y = 0;
            x = -1;
        }
        if (x == 17) y ++;
        else if (x == -1) y --;
        x = (x + 17) % 17;
        y = (y + 17) % 17;
    }
    Fill(startPointX, startPointY, board);
    PrintImage(board, 17, 17, true);
}

int Menu(char options[][1024], int numOptions, std::string message = "") {
    int chosenOption = 0;

    while (true) {
        system(CLEAR);

        for (int i = 0; i < numOptions; i++) {
            if (i == chosenOption) {
                printf("\x1b[36m%d. %s\n\x1b[0m", i, options[i]);
            } else {
                printf("%d. %s\n", i, options[i]);
            }
        }

        if (message != "") std::cout << message;

        switch (GETCHAR) {
            case 'w': {
                chosenOption = (chosenOption - 1 + numOptions) % numOptions;
                break;
            }
            case 's': {
                chosenOption = (chosenOption + 1) % numOptions;
                break;
            }
            case 'e':
                return chosenOption;
            default: break;
        }
    }
}

int main () {
#if defined _WIN32
    SetConsoleOutputCP(65001);
#else
    termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
#endif

    char options[][1024] = {"Пример 1", "Пример 2", "Ввод рисунка", "Выход"};
    std::string message = "Для перемещения между пунктами использовать w и s. Для выбора пункта нажмите e (латинскую). Если не работает, попробуйте поменять раскладку.";
    bool isRunning = true;

    while (isRunning) {
        switch (Menu(options, 4, message)) {
            case 0: {
                Paint1();
                break;
            }
            case 1: {
                Paint2();
                break;
            }
            case 2: {
                UserImage();
                break;
            }
            default: {
                isRunning = false;
                break;
            }
        }

        system(CLEAR);
    }

#if !defined _WIN32
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
#endif
	return 0;
}
