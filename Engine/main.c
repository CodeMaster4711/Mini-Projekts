#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include "database.h"
#include "user_input.h"
#include "programm_start_engine.h"


char source[260];
char games_folder_names[300][260];
char games_exe_names[300][260];
int amount_of_games = 0;
int clock = 0;

void print_subdirectories(const TCHAR *path);
void search_exe_files(const TCHAR *path);
void get_current_directory(char *buffer);
int _tmainexe(int argc, TCHAR *argv[]);
int input(int amount);
void engine_start(char path[260], char exe[260]);




int main(){
    _tmainexe(0, NULL);



    return 0;
}









int _tmainexe(int argc, TCHAR *argv[]) {


    char directory[260];
    get_current_directory(directory);
    printf("Der Pfad ist: %s\n", directory);
    strcpy(source, directory);
    printf("Der const Pfad ist: %s\n", source);

    sprintf(directory, "%s\\Games", directory);
    print_subdirectories(TEXT(directory));

    for (int i = 2; i < strlen(games_folder_names[i]); i++) {printf("%s\n", games_folder_names[i]);}


    char cmake[] = "cmake-build-debug";
    char games [] = "Games";
    char temp[260];
    for (int i = 1; i < 260; i++) {
        sprintf(temp, "%s\\%s\\%s\\%s", source , games ,games_folder_names[i], cmake);
        search_exe_files(TEXT(temp));
        if(games_folder_names[2][i] == '\0'){
            break;
        }
    }
    line(50);
    for (int j = 1; j < 300; j++) {
        if(games_exe_names[j][0] == '\0'){
            break;
        }
        printf("%d . %s\n",j ,games_exe_names[j]);
        amount_of_games = j;
    }
    line(50);
    int userinput = input(amount_of_games);
    printf("Der Pfad wird vorbereitet...\n");
    char temp2[260];
    sprintf(temp2, "%s\\%s\\%s\\%s", source , games,games_folder_names[userinput+1] ,cmake);
    start_engine(temp2, games_exe_names[userinput]);




    return 0;

}

void print_subdirectories(const TCHAR *path) {
    int counter = 0;
    WIN32_FIND_DATA FindFileData;
    HANDLE hFind = INVALID_HANDLE_VALUE;
    TCHAR DirSpec[MAX_PATH];
    DWORD dwError;


    _tprintf(TEXT("\nTarget directory is %s\n\n"), path);

    _stprintf_s(DirSpec, MAX_PATH, TEXT("%s\\*"), path);

    hFind = FindFirstFile(DirSpec, &FindFileData);

    if (hFind == INVALID_HANDLE_VALUE) {
        return;
    }
    else {
        if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            strcpy(games_folder_names[counter], FindFileData.cFileName);
            counter++;
            TCHAR subDir[MAX_PATH];
            _stprintf_s(subDir, MAX_PATH, TEXT("%s\\%s"), path, FindFileData.cFileName);
            search_exe_files(subDir);


        }
        while (FindNextFile(hFind, &FindFileData) != 0) {
            if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
                strcpy(games_folder_names[counter], FindFileData.cFileName);
                counter++;
                TCHAR subDir[MAX_PATH];
                _stprintf_s(subDir, MAX_PATH, TEXT("%s\\%s"), path, FindFileData.cFileName);
                search_exe_files(subDir);

            }
        }
        dwError = GetLastError();
        FindClose(hFind);
        if (dwError != ERROR_NO_MORE_FILES) {
            printf("FindNextFile error. Error is %u\n", dwError);
            return;
        }
    }
}

void search_exe_files(const TCHAR *path) {
    WIN32_FIND_DATA FindFileData;
    HANDLE hFind = INVALID_HANDLE_VALUE;
    TCHAR DirSpec[MAX_PATH];
    DWORD dwError;

    _stprintf_s(DirSpec, MAX_PATH, TEXT("%s\\*"), path);

    hFind = FindFirstFile(DirSpec, &FindFileData);

    if (hFind == INVALID_HANDLE_VALUE) {
        return;
    }
    else {
        do {
            char *ext = strrchr(FindFileData.cFileName, '.');
            if (ext != NULL && _tcscmp(ext, TEXT(".exe")) == 0) {
                strcpy(games_exe_names[clock], FindFileData.cFileName);
                clock++;
            }
        } while (FindNextFile(hFind, &FindFileData) != 0);

        dwError = GetLastError();
        FindClose(hFind);
        if (dwError != ERROR_NO_MORE_FILES) {
            return;
        }
    }
}

void get_current_directory(char *buffer) {
    GetCurrentDirectory(260, buffer);

    // Find the "Games" directory in the path
    char *games = strstr(buffer, "Engine");
    if (games != NULL) {
        // Add 5 to the pointer to include the length of "Games"
        games += 6;
        // Null-terminate the string at the end of "Games"
        *games = '\0';
    }
}


