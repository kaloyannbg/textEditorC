int isFileExist(char file[]);

void createNewFile(char file[]);

void writeInFile(char file[]);

void readFromFile(char file[]);

void clearContentFromFile(char file[], char cChoice);

void redactContentFromFile(char *file);

int isContinue(char c);

void readNamesOfAllFiles(char *file);

// menus
void printMenu();
// menus end

// helper Q&A
void printHelper();
void printVersionUpdates();
void printChoicesForExt();
// end Q&A

// STRING FUNCTIONS
int isLetter(char c);
char toLower(char c);
int isDigit(char c);
void stringSymbCutter(char *string);
int checkMaxLength(char *string, int maxSize);
int checkMinLength(char *string, int minSize);
void printArray(char *str, char *fileName);
void getFileName(char *file);
// END STRING FUNCTIONS

// FUN FUNCTIONS
void printSpaces(int count);
// END FUN FUNCTIONS