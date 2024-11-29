#include <iostream>
#include <string>
#include <fstream>
using namespace std;
const int N_max = 2000;

void swap(string& a, string& b) {
	string t = a;
	a = b;
	b = t;
}
bool uniq(string s, string words[N_max],int& cnt) {
	for (int i = 0; i < cnt; i++) {
		if (s == words[i])
			return false;
	}return true;
}
bool noLet(string s, char a1, char a2, char a3) {
	for (int i = 0; i < s.length(); i++) {
		if ((s[i] == a1) || (s[i] == a2) || (s[i] == a3))
			return false;
	}
	return true;
}
void clearWords(int& cnt, string words[N_max]) {
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < words[i].length(); j++) {
			if (!isalpha(words[i][j])) {
				words[i].erase(j, 1);
				j--;
			}
		}
	}
}

void write(int& cnt, string words[N_max], int N) {
	std::ofstream out;         
	out.open("out.txt");
	for (int i = 0; i < N; i++) {
		out << words[i] << endl;
	}
}
void read(int& cnt,string words[N_max],char a1,char a2,char a3){
	cnt = 0;
	fstream in("text.txt");
	string s;
	while (!in.eof()) {
		in >> s;
		if (noLet(s, a1, a2, a3)&&uniq(s,words,cnt))
		{
			words[cnt] = s;
			cnt++;
		}
		
	}
	clearWords(cnt, words);

}

void sort(int& cnt, string words[N_max]) {
	for (int i = 0; i < cnt-1; i++) {
		for (int j = i; j < cnt; j++) {
			if (words[j].length() > words[i].length()) {
				swap(words[i],words[j]);
			}
		}
	}
}
void main() {
	int cnt;
	string words[N_max];
	char a1, a2, a3;
	cin >> a1 >> a2 >> a3;
	int N;
	cin >> N;
	read(cnt, words,a1,a2,a3);
	sort(cnt, words);
	write(cnt, words,N);
}