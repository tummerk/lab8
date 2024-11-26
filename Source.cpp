#include <iostream>
#include <string>
using namespace std;

string alph = "abcdefghijklmnopqrstuvwxyz";
string vowels="aeiouy";

void clearWords(int& cnt, string words[5000]) {
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < words[i].length(); j++) {
			if (!isalpha(words[i][j])) {
				words[i].erase(j, 1);
				j--;
			}
		}
	}
}

int letNum(string word){
	for (int i = 1; i < alph.length(); i++) {
		if (alph[i - 1] == tolower(word[0]))
			return i;
	}
}

bool repl(string word){
	char let;
	int len = word.length();
	for (int i = 0; i < len - 1; i++) {
		let = tolower(word[i]);
		for (int j = i + 1; j < len; j++) {
			if (let == tolower(word[j]))
				return true;
		}
	}return false;
}

string deleteVowels(string s){
	for (int i = 0; i < s.length(); i++) {
		for (int j = 0; j < 6; j++) {
			if (s[i] == vowels[j]) {
				s.erase(i, 1);
				i--;
				break;
			}
		}
	}return s;
}

void read(int& cntNoRep, int& cntRep, string rep[5000], string noRep[5000]) {
	string s;
	cntNoRep = 0;
	cntRep = 0;
	while (cin >> s) {
		if (s == "0") {
			break;
		}
		if (repl(s))
		{
		rep[cntRep] = deleteVowels(s);
		cntRep++;
		}else{ 
		noRep[cntNoRep] = s; 
		cntNoRep++;
		}
	}
	clearWords(cntRep, rep);
	clearWords(cntNoRep, noRep);
}

void swap(string& a, string& b) {
	string s = a;
	a = b;
	b = s;
}
void sort(string words[5000], int cmt) {
	for (int i = 0; i < cmt - 1; i++) {
		for (int j = i + 1; j < cmt; j++) {
			if (letNum(words[i]) < letNum(words[j]))
				swap(words[i],words[j]);
		}
	}
}
void write(int& cntNoRep, int& cntRep, string rep[5000], string noRep[5000]) {
	for (int i = 0; i < cntNoRep; i++) {
		cout << noRep[i] << ' ';
	}cout << "\n";
	for (int i = 0; i < cntRep; i++) {
		cout << rep[i] << ' ';
	}
}

void main() {
	string rep[5000],noRep[5000];
	int cntRep, cntNoRep;
	read(cntNoRep, cntRep, rep, noRep);
	sort(noRep, cntNoRep);
	write(cntNoRep, cntRep, rep, noRep);
}