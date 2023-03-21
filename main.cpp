#include "tasks_rk1.h"

void task_1() {
    WorkWithFile a("sourceFile_task1.txt");
    a.writeStatInfoToFile("result_sourceFile_task1.txt");
}

void task_2(){
    writeToFile("result_task2.txt", convertDecToBin(30));
}

void task_3(){
    writeToFile("result_task3.txt", 0, convertBinToHex("1000110101111"), "1000110101111");
}

void task_4(){
    buildTree(8);
}

void task_5(){
    float Matrix[5][5];
    for (int i = 0; i < 5; ++i) {
        randFill(Matrix[i], 5);
    }
    std::vector<std::pair<int, float>> vec = averStr2DArray(*Matrix, 5, 5);
    FILE* pFile = fopen("result_task5.txt", "w");
    for (auto i: vec)
        fprintf(pFile, "%d\t%c\t%f\n", i.first, ':', i.second);
    fclose(pFile);
}

int Node::countNodes = 0;

void task_6_7(){
    LinkedList lst;
    for (int i = 0; i < 5; ++i) {
        lst.push_back(2 * i);
    }
    lst.insert(8, 3);
    lst.writeToFileFromHead();
    lst.writeToFileFromTail();
}

int main() {
    task_1();
    task_2();
    task_3();
    task_4();
    task_5();
    task_6_7();

    return 0;
}