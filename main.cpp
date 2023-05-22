#include "tasks_rk1.h"

void task_1() {
    WorkWithFile a("sourceFile_task1.txt");
    a.writeStatInfoToFile("result_sourceFile_task1.txt");
}

void task_2(){
    char* aaa = new char[256]{"result_task2.txt\0"};
    writeToFile(*aaa, convertDecToBin(67));
}

void task_3(){
    writeToFile("result_task3.txt", 0, convertBinToHex("0000000001101"), "0000000001101");
}

void task_4(){
    buildTree(5);
}

void task_5(){
    float Matrix[5][5];
    for (int i = 0; i < 5; ++i) {
        randFill(Matrix[i], 5);
    }
    std::vector<float> vec = averStr2DArray(*Matrix, 5, 5);
    FILE* pFile = fopen("result_task5.txt", "w");
    int v = 0;
    for (auto i: vec) {
        fprintf(pFile, "%d\t%c\t%f\n", v, ':', i);
        v++;
    }
    fclose(pFile);
}

LinkedList lst;

void task_6(){
    for (int i = 0; i < 5; ++i) {
        lst.push_back(2 * i);
    }
    lst.writeToFileFromHead();
    lst.writeToFileFromTail();
}

void task_7(){
    lst.insert(8, 3);
}

void task_8(){
    StudentInfo test;
    test.addSubj("OP");
    test.addMark("OP", 5);
    test.writeAllInfoToFile();
}

void task_9(){
    bool OK = brackets("(<<>{((hehe))}[<<<>{}>()>]>)");
    if(OK)
        std::cout << "OK";
    else
        std::cout << "BAD";
}

void task_10(){
    bool OK = true;
    RingedBuffer<int> Buf(5);
    Buf.AddEl(67);
    int buf;
    Buf.GetEl(buf);
    if(buf != 67)
        OK = false;
    for (int i = 0; i < 100; ++i) {
        Buf.AddEl(i+1);
    }
    for (int i = 0; i < 100; ++i) {
        Buf.GetEl(buf);
        if(buf != i+1)
            OK = false;
    }
    if(OK)
        std::cout << std::endl << "RingedBuffer works properly";
    else
        std::cout << std::endl << "RingedBuffer does not work properly";
}

int main() {
    task_1();
    task_2();
    task_3();
    task_4();
    task_5();
    task_6();
    task_7();
    task_8();
    task_9();
    task_10();
    return 0;
}
