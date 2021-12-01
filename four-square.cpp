#include <iostream>
#include <cstring>

int getCharFromTable(char lookfor, char* table){
    for (int i = 0; table[i];i++)
        if(table[i] == lookfor)
            return i;
    return 0;
}

int cross(int i0, int i1){
    return (i0 / 5) * 5 + i1 % 5;
}

char* change(char* txt, char* ul, char* ur, char* bl, char* br){
    char *wynik = new char[strlen(txt) + 1];
    strcpy(wynik, txt);
    int i = 0, i0, i1;
    for (; txt[i] && txt[i + 1];i+=2){
        i0 = getCharFromTable(wynik[i], ul);
        i1 = getCharFromTable(wynik[i + 1], br);
        wynik[i] = ur[cross(i0, i1)];
        wynik[i + 1] = bl[cross(i1, i0)];
    }
    return wynik;
}

char* cipher(char* txt, char* alphabet, char* key1, char* key2){
    return change(txt, alphabet, key1, key2, alphabet);
}

char* decipher(char* txt, char* alphabet, char* key1, char* key2){
    return change(txt, key1, alphabet, alphabet, key2);
}

int main(){
    char* alphabet = new char[26];
    char* key1 = new char[26];
    char *key2 = new char[26];
    char *txt = new char[128];
    std::cin >> alphabet >> key1 >> key2;
    std::cin.sync();
    std::cin.getline(txt, 128);
    char* txtc = cipher(txt, alphabet, key1, key2);
    std::cout << txtc << "\n";
    char *txtd = decipher(txtc, alphabet, key1, key2);
    std::cout << txtd << "\n";
    delete[] alphabet, key1, key2, txt, txtc, txtd;
    return 0;
}

/*
ABCDEFGHIJKLMNOPQRSTUVWXYZ
LVGTZAKBRFIEYHOPWQDUMCNXS
IUTBOVACZKDWNEYLFSXHRPGOP
TEST
UOUX
TEST
*/