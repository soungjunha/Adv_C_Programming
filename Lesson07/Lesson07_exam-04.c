#include <stdio.h>
#include <malloc.h>


int my_strcmp(char* str1, char* str2) {
    int i = 0;
    char ch1, ch2;
    while (str1[i] != '\0' && str2[i] != '\0') {
        ch1 = (str1[i] >= 'A' && str1[i] <= 'Z') ? (str1[i] + ('a' - 'A')) : str1[i];
        ch2 = (str2[i] >= 'A' && str2[i] <= 'Z') ? (str2[i] + ('a' - 'A')) : str2[i];
        if (ch1 > ch2) {
            return 1;
        }
        else if (ch1 < ch2) {
            return -1;
        }
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0') {
        return 0;
    }
    else if (str1[i] == '\0') {
        return -1;
    }
    else if (str2[i] == '\0') {
        return 1;
    }
}

void make_dictionary(char** words, int cnt) {
    char* temp;
    int least;
    for (int i = 0; i < cnt - 1; i++) {
        least = i;
        for (int j = i + 1; j < cnt; j++) {
            if (my_strcmp(words[least], words[j]) > 0) {
                least = j;
            }
        }
        if (least != i) {
            temp = words[least];
            words[least] = words[i];
            words[i] = temp;
        }
    }
}

int main() {
    FILE* input,*dic;
    char** words = (char**)malloc(sizeof(char*) * 1);
    input = fopen("words.txt", "r");
    char buffer[100], buffer2[100];
    int cnt = 0; 

    for (int i = 0; !feof(input); i++) {
        if (fscanf(input, "%s", buffer) != EOF) { 
            int j, idx = 0; 
            for (j = 0; buffer[j] != '\0'; j++) {
                buffer2[idx] = buffer[j];
                if (buffer[j] == ';' || buffer[j] == '|' || buffer[j] == ',') { 
                    buffer2[idx] = '\0';
                    words[cnt] = (char*)malloc(sizeof(char) * (strlen(buffer2) + 1));
                    strcpy(words[cnt], buffer2);
                    words = (char**)realloc(words, sizeof(char*) * (cnt + 2));
                    idx = 0;
                    cnt++;
                }
                else {
                    idx++;
                }
            }
            if (buffer[j - 1] != ';' && buffer[j - 1] != '|' && buffer[j - 1] != ',') {
                buffer2[idx] = '\0';
                words[cnt] = (char*)malloc(sizeof(char) * (strlen(buffer2) + 1));
                strcpy(words[cnt], buffer2);
                words = (char**)realloc(words, sizeof(char*) * (cnt + 2));
                cnt++;
            }
        }
    }

    make_dictionary(words, cnt);

    dic = fopen("dictionary.txt", "w");
    for (int i = 0; i < cnt; i++) {
        fprintf(dic, "%s\n", words[i]);
    }
    fclose(dic);
    fclose(input);

    for (int i = 0; i < cnt; i++) {
        free(words[i]);
    }
    free(words);
    return 0;
}