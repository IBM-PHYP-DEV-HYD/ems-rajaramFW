

int menuOne();
int mainMenu_1();
int mainMenu_2();
int mainMenu_3();
int mainMenu_4();

//data typr choice 
enum MenuChoice {
    INTEGERCHOICE = 1,
    FLOATCHOICE,
    STRINGCHOICE,
    USERDEFINEDCHOICE
};

enum DequeInitChoice {
    EMPTY_DEQUE = 1,
    DEQUE_WITH_ELEMENTS,
    PREVIOUS_MENU,
    QUIT
};


//data typr choice 
enum DataTypeChoice {
    CREATE_EMPTY_DEQUE = 1,
    CREATE_DEQUE_N_ELEMENTS
};

void cinBufferClear();