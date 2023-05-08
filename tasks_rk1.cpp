#include <cstring>
#include <map>
#include <fstream>
#include "tasks_rk1.h"

char* NewChar(const char* s){
    char* NewString = new char[20];
    int count = 0;
    for (int i = 0; i < strlen(s); ++i) {
        int count1 = 0;
        for (int j = i; j > 0; j--) {
            if(s[i] == s[j - 1]){
                count++;
                count1++;
                break;
            }
        }
        if(count1 == 0) {
            NewString[i - count] = s[i];
            NewString[i - count + 1] = '\0';
        }
    }
    return NewString;
}

void WorkWithFile::readFromFile(const char *fileName) {
    std::ifstream inf(fileName);
    std::string s0;
    std::string s1;
    while(std::getline(inf,s1))
        s0+=s1;
    inf.close();
    for (int i = 0; i < s0.length() ; ++i) {
        dataOfFile[i] = s0[i];
        dataOfFile[i+1] = '\0';
    }
}

void WorkWithFile::prepareTestFile(const char *fileName) {
    FILE * pFile;
    pFile = fopen ( fileName , "w" );
    int val = 20;
    int i;
    srand(time(nullptr));
    char mass;
    for(i=0; i<val; ++i)
    {
        mass=(rand() % ('z'-'a'+1))+'a';
        if (mass < 'a') mass = ' ';
        fwrite (&mass , 1 , sizeof(mass) , pFile );
    }
    fclose (pFile);
}

WorkWithFile::WorkWithFile(const char *fileName) {
    readFromFile(fileName);
}

WorkWithFile::WorkWithFile() {
    prepareTestFile("sourceFile_task1.txt");
}

WorkWithFile::~WorkWithFile() {
    delete[] dataOfFile;
}

void WorkWithFile::writeStatInfoToFile(const char *outFile) {
    char* UniqueSimbols = NewChar(dataOfFile);
    int* CounterArray = new int[strlen(UniqueSimbols)];
    for (int i = 0; i < strlen(UniqueSimbols); ++i) {
        CounterArray[i] = 0;
    }
    for (int i = 0; UniqueSimbols[i] != '\0'; ++i) {
        for (int j = 0; j < strlen(dataOfFile); ++j) {
            if(UniqueSimbols[i] == dataOfFile[j])
                CounterArray[i]++;
        }
    }
    FILE* pFile = fopen(outFile, "w");
    for (int i = 0; i < strlen(UniqueSimbols); ++i) {
        fprintf(pFile, "%c\t%d\n", UniqueSimbols[i], CounterArray[i]);
    }
    fclose(pFile);
    delete[] UniqueSimbols;
    delete[] CounterArray;
}

void buildTree(int height){
    int count = height - 1;
    for(int j = 1; j <= height; j++) {
        for (int i = count--; i > 0; i--) {
            std::cout << " ";
        }
        for (int i = 0; i < 2*j-1; ++i) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

char* convertDecToBin(int number){
    if(number != 0) {
        int CoolNum = abs(number);
        char *string = new char[33];
        int count = 0;
        for (int i = 32; CoolNum > 0; i--) {
            string[i] = CoolNum % 2 + '0';
            CoolNum /= 2;
            count++;
        }
        char *CoolString = new char[count];
        int Index = 33 - count;
        for (int i = 0; i < count; ++i) {
            if (i == 0 && number < 0) {
                CoolString[i] = '-';
                count++;
                continue;
            }
            CoolString[i] = string[Index++];
            CoolString[i + 1] = '\0';
        }
        delete[]string;
        return CoolString;
    }
    else{
        char* str1 = new char[2];
        str1[0] = '0';
        str1[1] = '\0';
        return str1;
    }
}

void writeToFile(const char& fileName, const char* strNum){
    FILE* pFile = fopen(&fileName, "w");
    fprintf(pFile, "%s", strNum);
    fclose(pFile);
}

char* convertBinToHex(const char* binNum){
    int number = 0;
    if((int)(strlen(binNum))%4 != 0)
        number = 4 - (int)(strlen(binNum))%4;
    char* CoolBinNum = new char[number + strlen(binNum) + 1];
    std::map<std::string , char> m {{"0000", '0'}, {"0001", '1'}, {"0010", '2'},
                              {"0011", '3'}, {"0100", '4'}, {"0101", '5'},
                              {"0110", '6'}, {"0111", '7'}, {"1000", '8'},
                              {"1001", '9'}, {"1010", 'A'}, {"1011", 'B'},
                              {"1100", 'C'}, {"1101", 'D'}, {"1110", 'E'},
                              {"1111", 'F'}};
    for (int i = 0; i < number; ++i) {
        CoolBinNum[i] = '0';
    }
    for (int i = number; i < number + strlen(binNum) + 1; ++i) {
        CoolBinNum[i] = binNum[i - number];
        CoolBinNum[i+1] = '\0';
    }
    char* hexNum = new char[8];
    int Index = 0;
    int i = 0;
    while(i< strlen(CoolBinNum)){
        char *temp = new char[5];
        for (int j = 0; j < 4; ++j) {
            temp[j] = CoolBinNum[i++];
            temp[j+1] = '\0';
        }
        hexNum[Index++] = m.find(temp)->second;
        delete[] temp;
    }
    hexNum[Index] = '\0';
    delete[] CoolBinNum;
    int counter = 0;
    for (int j = 0;hexNum[j] == '0' ; ++j) {
        counter++;
    }
    for (int j = 0; j < counter; ++j) {
        for (int k = 0; k < strlen(hexNum)-1; ++k) {
            std::swap(hexNum[k], hexNum[k+1]);
        }
    }
    hexNum[strlen(hexNum)-counter] = '\0';
    return hexNum;
}

void writeToFile(const char* fileName, int writeAppend, const char* hexNum, const char* binNum){
    FILE* pFile = fopen(fileName, "w");
    fprintf(pFile, "%s\t%s", binNum, hexNum);
    fclose(pFile);
}

std::vector<float> averStr2DArray(const float* ar, int colCount, int rowCount){
    std::vector<float> vec;
    for (int i = 0; i < rowCount; ++i) {
        float sum = 0;
        for (int j = 0; j < colCount; ++j) {
            sum += (*(ar + (i*colCount) + j));
        }
        float average = sum/colCount;
        vec.emplace_back(average);
    }
    return vec;
}

void randFill(float* ar, int N){
    for(int i = 0;i < N;i++) {
        ar[i] =rand()/float(RAND_MAX)*24.f+1.f;
    }
}

LinkedList::LinkedList() {
    Head = nullptr;
    Tail = nullptr;
}

LinkedList::~LinkedList() {
    while(Head != nullptr){
        Node* p = Head;
        Head = Head->next;
        delete p;
    }
}

void LinkedList::push_back(int nameNode) {
    Node *Element = new Node;
    if(Head == nullptr) {
        Element->nameNode = nameNode + 1;
        Element->next = nullptr;
        Element->prev = nullptr;
        Head = Tail = Element;
    }
    else{
        Element->next = nullptr;
        Element->nameNode = nameNode + 1;
        Element->prev = Tail;
        Tail->next = Element;
        Tail = Element;
    }
    Node::countNodes++;
}

void LinkedList::writeToFileFromTail() {
    FILE* pFile = fopen("ListFromTail.txt", "w");
    Node* p = Tail;
    while(p != nullptr){
        fprintf(pFile, "%d%c%s", p->nameNode, ';', " ");
        p = p->prev;
    }
    fclose(pFile);
}

void LinkedList::writeToFileFromHead(){
    FILE* pFile = fopen("ListFromHead.txt", "w");
    Node* p = Head;
    while(p != nullptr){
        fprintf(pFile, "%d%c%s", p->nameNode, ';', " ");
        p = p->next;
    }
    fclose(pFile);
}

void LinkedList::insert(int nameNode, int position){
    if(position >= 0 && position < Node::countNodes + 1){
        Node* Element = new Node;
        Element->nameNode = nameNode;
       if(position == 0){
           Element->next = Head;
           Element->prev = nullptr;
           Head->prev = Element;
           Head = Element;
       }
       else{
           Node* p = Head;
           for (int i = 0; i < position -1; ++i) {
               p = p->next;
           }
           Element->next = p->next;
           Element->prev = p;
           p->next = Element;
           if(position != Node::countNodes)
               Element->next->prev = Element;
           else
               Tail = Element;
       }
       Node::countNodes++;
    }
}

float StudentInfo::getAverMark(const std::string &subjName) {
    float sum = 0;
    for(auto it = subjMark.find(subjName)->second.first.begin(); it != subjMark.find(subjName)->second.first.end(); it++){
        sum+=*it;
    }
    float average = sum/subjMark.find(subjName)->second.first.size();
    return average;
}

int StudentInfo::addMark(const std::string &subjName, int mark) {
    if(subjMark.find(subjName) == subjMark.end())
        return 1;
    subjMark.find(subjName)->second.first.push_back(mark);
    subjMark.find(subjName)->second.second = getAverMark(subjName);
    return  0;
}

int StudentInfo::addSubj(const std::string &subjName) {
    if(subjMark.find(subjName) != subjMark.end())
        return 1;
    std::list<int> lst;
    float aver = 0;
    std::pair<std::list<int>, float> pair;
    pair.first = lst;
    pair.second = aver;
    subjMark.emplace(subjName, pair);
    return 0;
}

void StudentInfo::printInfoStudent(bool writeFile) {
    if(!writeFile) {
        FILE *pFile = fopen("Student.txt", "w");
        std::string s = std::get<0>(info);
        std::string s1 = std::get<1>(info);
        std::string s2 = std::get<2>(info);
        fprintf(pFile, "%s\t%s%c%s\n", s.c_str(), s1.c_str(), ':', s2.c_str());
        for (auto it = subjMark.begin(); it != subjMark.end(); it++) {
            fprintf(pFile, "%s%s", it->first.c_str(), " :\t");
            for (auto it1 = it->second.first.begin(); it1 != it->second.first.end(); it1++) {
                fprintf(pFile, "%d%s", *it1, ", ");
            }
            fprintf(pFile, "%s%f\n", " -- ", it->second.second);
        }
        fclose(pFile);
    }
}

void StudentInfo::writeAllInfoToFile() {
    std::ofstream out("AllInfo.txt", std::ios::binary);
    out.write((char*)&info, sizeof(info));
    out.close();
}

bool brackets(const char* str){
    std::map<char, char> m {{'(', ')'},{'[',']'},{'<','>'}, {'{','}'}};
    FILO Stack;
    for (int i = 0; i < strlen(str); ++i) {
        bool IsBracket = false;
        for (auto iter = m.begin(); iter != m.end(); iter++) {
            if (iter->first == str[i] || iter->second == str[i]) {
                IsBracket = true;
                break;
            }
        }
        if(IsBracket) {
            bool OpenBracket = false;
            for (auto iter = m.begin(); iter != m.end(); iter++) {
                if (iter->first == str[i]) {
                    Stack.AddEl(str[i]);
                    OpenBracket = true;
                    break;
                }
            }
            if(!OpenBracket) {
                char buf;
                Stack.GetEl(buf);
                if (m.find(buf)->second != str[i]) {
                    Stack.AddEl(buf);
                    Stack.AddEl(str[i]);
                }
            }
        }
    }
    return Stack.IsEmpty();
}