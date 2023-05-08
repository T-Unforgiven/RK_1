#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <list>

#ifndef BMSTU_2023_TASKS_RK1_H
#define BMSTU_2023_TASKS_RK1_H

char* NewChar(const char* s);

class WorkWithFile {
private :
    char* dataOfFile = new char[256];

    void readFromFile(const char* fileName);

    void prepareTestFile(const char* fileName);

public :
    WorkWithFile(const char* fileName);

    WorkWithFile();

    ~WorkWithFile();

    void writeStatInfoToFile(const char* outFile);
};

char* convertDecToBin(int number);

void writeToFile(const char& fileName, const char* strNum);

void buildTree(int height);

char* convertBinToHex(const char* binNum);

void writeToFile(const char* fileName, int writeAppend, const char* hexNum, const char* binNum);

std::vector<float> averStr2DArray(const float* ar, int colCount, int rowCount);

void randFill(float* ar, int N);

struct Node  {
    Node* next;
    Node* prev;
    int nameNode;
    static int countNodes;
};

class LinkedList {
private :
    Node* Head;
    Node* Tail;
public :
    LinkedList();

    ~LinkedList();

    void push_back(int value);

    void writeToFileFromTail();

    void writeToFileFromHead();

    void insert(int nameNode, int position);
};

class StudentInfo {
private :
    std::tuple<std::string /*фамилия*/,std::string /*имя*/,char* /*№ студ билета*/> info;
    std::map<std::string/*название предмета*/, std::pair<std::list<int> /*список оценок*/, float /*средняя оценка*/>> subjMark;
public :
    /*	desription	:	добавления отметки по выбранному предмету
        input		:	subjName - название предмета, mark -- оценка
        output		:	0 - оценка добавлена, 1 - нет такого предмета
        author		:
        date		:
    */
    int addMark(const std::string& subjName, int mark);
    /*	desription	:	добавления отметки по выбранному предмету
        input		:	subjName - название предмета
        output		:	0 - предмет добавлен, 1 - такой предмет уже есть
        author		:
        date		:

    */
    int addSubj(const std::string& subjName);
    /*	desription	:	добавления нового предмета
        input		:	subjName - название предмета
        output		:	среднее значение оценки
        author		:
        date		:
    */
    float getAverMark(const std::string& subjName);
    /*	desription	:	вычисления средней оценки по предметам
        input		:	subjName - название предмета
        output		:	среднее значение оценки
        author		:
        date		:
    */
    void printInfoStudent(bool writeFile = false);
    /*	desription	:	запись данных в файл формат файла
                            [Фамилия] [имя] : [номер билета]
                                [предмет 1]	:	[оценка 1], [оценка 2],... [оценка N] -- [среднее значение]
                                [предмет 2]	:	[оценка 1], [оценка 2],... [оценка N] -- [среднее значение]
        input		:	subjName - название предмета
        output		:	среднее значение оценки
        author		:
        date		:
    */
    void writeAllInfoToFile();
};

bool brackets(const char* str);

class FILO {
private:
    int DataLen;
    int size;
    char* ar;
public:
    FILO(){
        size = 256;
        ar = new char[size];
        DataLen = 0;
    }

    int AddEl(char element){
        if(DataLen == size)
            return -1;
        ar[DataLen++] = element;
        return 0;
    }

    int GetEl(char& element){
        if(DataLen == 0)
            return -1;
        element =  ar[--DataLen];
        return 0;
    }

    bool IsEmpty(){
        return DataLen == 0;
    }
};

template<typename T>
class RingedBuffer{
private:
    int begin;
    int end;
    int DataLen;
    int size;
    T *ar;
public:
    RingedBuffer(){
        begin = end = 0;
        size = 256;
        DataLen = 0;
        ar = new T[size];
    }
    RingedBuffer(int FirstEl){
        size = 256;
        DataLen = 0;
        ar = new T[size];
        begin = end = FirstEl;
    }
    int AddEl(T element){
        if(DataLen == size)
            return -1;
        ar[end] = element;
        DataLen++;
        end = (begin+DataLen)%size;
        return 0;
    }
    int GetEl(T& element){
        if(DataLen == 0)
            return -1;
        element = ar[begin++];
        begin = begin%size;
        DataLen--;
        return 0;
    }
};



#endif
