#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countCharacters(FILE *file) {// 统计字符数的函数 
    int count = 0;
    char ch;
    
    while ((ch = fgetc(file)) != EOF) {
        count++;
    }
    
    return count;
}

int countWords(FILE *file) {// 统计单词数的函数 
    int count = 0;
    int inWord = 0;
    char ch;
    
    // 要是遇到空格、换行或制表符的话就不记录单词 
    
    while ((ch = fgetc(file)) != EOF) {
        if (ch == ' ' || ch == '\n' || ch == '\t') {
            inWord = 0;
        } else if (inWord == 0) {
            inWord = 1;// 进入新单词
            count++;
        }
    }
    return count;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [-c | -w] [input_file_name]\n", argv[0]);
        return 1;
    }

    char *option = argv[1];//得到操作的参数-c/-w 
    char *filename = argv[2];//得到文件名 

    FILE *file = fopen(filename, "r");// 打开文件
    
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    
    int count=0;//count用来统计字符数或单词数 
	 
    if (strcmp(option, "-c") == 0) {
        count = countCharacters(file);//调用统计字符数函数 
        printf("字符数：%d\n", count);
    } else if (strcmp(option, "-w") == 0) {
        count = countWords(file);//调用统计单词数函数 
        printf("单词数：%d\n", count);
    } else {
        printf("Invalid option\n");
        return 1;
    }

    fclose(file);//关闭文件 
    return 0;
}

