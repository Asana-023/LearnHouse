#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countCharacters(FILE *file) {// ͳ���ַ����ĺ��� 
    int count = 0;
    char ch;
    
    while ((ch = fgetc(file)) != EOF) {
        count++;
    }
    
    return count;
}

int countWords(FILE *file) {// ͳ�Ƶ������ĺ��� 
    int count = 0;
    int inWord = 0;
    char ch;
    
    // Ҫ�������ո񡢻��л��Ʊ���Ļ��Ͳ���¼���� 
    
    while ((ch = fgetc(file)) != EOF) {
        if (ch == ' ' || ch == '\n' || ch == '\t') {
            inWord = 0;
        } else if (inWord == 0) {
            inWord = 1;// �����µ���
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

    char *option = argv[1];//�õ������Ĳ���-c/-w 
    char *filename = argv[2];//�õ��ļ��� 

    FILE *file = fopen(filename, "r");// ���ļ�
    
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    
    int count=0;//count����ͳ���ַ����򵥴��� 
	 
    if (strcmp(option, "-c") == 0) {
        count = countCharacters(file);//����ͳ���ַ������� 
        printf("�ַ�����%d\n", count);
    } else if (strcmp(option, "-w") == 0) {
        count = countWords(file);//����ͳ�Ƶ��������� 
        printf("��������%d\n", count);
    } else {
        printf("Invalid option\n");
        return 1;
    }

    fclose(file);//�ر��ļ� 
    return 0;
}

