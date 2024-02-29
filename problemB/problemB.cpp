#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <stdio.h>

using namespace std;

int main()
{
 
	int t;
	cin >> t;

	while (t--) {

		string in;
		cin >> in;

		int wynik = 0;
		int reszta = 0;
		char znak = 'o';
		int cyfraA;
		int cyfraB;
		int x = 0;
		int y = 0;
		int pomoc = 0;
		int w = 0;
		int m = 0;
		stack <int> stos;

		for (int i = 0; i < in.length(); i++) {
			if (in[i] == '+' || in[i] == '-' || in[i] == '*' || in[i] == '/') {
				znak = in[i];
				break;
			}
			x++;
		}
		for (int i = x + 1; i < in.length(); i++) {
			y++;
		}

		string A = "";
		string B = "";

		for (int i = 0; i < x; i++) {
			A += in[i];
		}
		for (int i = 0; i < y; i++) {
			B += in[x + 1 + i];
		}

		if (znak == '+') {
			string s = "";
			m = x;
			w = y;
			if (x > y) {
				m = y;
				w = x;
			}
			for (int i = 0; i < m; i++) {
				wynik = (A[--x] - '0') + (B[--y] - '0') + reszta;
				s += to_string(wynik % 10);
				reszta = wynik / 10;
			}
			if (x > y) {
				for (int i = 0; i < w - m; i++) {
					wynik = (A[--x] - '0') + reszta;
					s += to_string(wynik % 10);
					reszta = wynik / 10;
				}
			}
			else {
				for (int i = 0; i < w - m; i++) {
					wynik = (B[--y] - '0') + reszta;
					s += to_string(wynik % 10);
					reszta = wynik / 10;
				}
			}
			if (reszta > 0) {
				s += to_string(reszta);
			}
			reverse(s.begin(), s.end());
			cout << s << endl;
		}

		if (znak == '*') {
			vector <int> koniec(x + y, 0);
			int A_i = 0;
			int B_i = 0;
			for (int i = x - 1; i >= 0; i--) {
				cyfraA = (A[i] - '0');
				B_i = 0;
				reszta = 0;
				for (int j = y - 1; j >= 0; j--) {
					cyfraB = (B[j] - '0');
					wynik = cyfraA * cyfraB + koniec[A_i + B_i] + reszta;
					reszta = wynik / 10;
					koniec[A_i + B_i] = wynik % 10;
					B_i++;
				}
				if (reszta > 0) {
					koniec[A_i + B_i] += reszta;
				}
				A_i++;
			}
			int q = koniec.size() - 1;
			while (q >= 0 && koniec[q] == 0) {
				q--;
			}
			if (q == -1) {
				return '0';
			}
			string s = "";
			while (q >= 0) {
				s += to_string(koniec[q--]);
			}
			cout << s << endl;
		}

		if (znak == '-') {
			bool test = true;
			m = y;
			w = x;
			string s = "";
			if (y > x) {
				m = x;
				w = y;
				test = false;
				swap(A, B);
			}
			if (x == y) {
				for (int i = 0; i < x; i++) {
					if (A[i] < B[i]) {
						test = false;
						swap(A, B);
						break;
					}
					else if (A[i] > B[i]) {
						break;
					}
				}
			}
			reverse(A.begin(), A.end());
			reverse(B.begin(), B.end());
			reszta = 0;
			for (int i = 0; i < m; i++) {
				wynik = ((A[i] - '0') - (B[i] - '0') - reszta);
				if (wynik < 0) {
					wynik += 10;
					reszta = 1;
				}
				else {
					reszta = 0;
				}
				s += (wynik + '0');
			}
			for (int i = m; i < w; i++) {
				int wynik = ((A[i] - '0') - reszta);
				if (wynik < 0) {
					wynik += 10;
					reszta = 1;
				}
				else {
					reszta = 0;
				}
				s += (wynik + '0');
			}
			if (test == false) {
				s += '-';
			}
			reverse(s.begin(), s.end());
			while (s[0] == '0') {
					s.erase(0, 1);
			}
			while(s[0] == '-' && s[1] == '0'){
				s.erase(1, 1);
			}
			cout << s << endl;
		}

		if (znak == '/') {
			int d = 0;
			m = y;
			w = x;
			bool test = true;
			if (y > x) {
				test = false;
				d = 0;
				break;
			}
			if (x == y) {
				for (int i = 0; i < x; i++) {
					if (A[i] < B[i]) {
						test = false;
						d = 0;
						break;
					}
					else if (A[i] > B[i]) {
						break;
					}
				}
			}
			if (test) {
				bool test2 = true;
				reverse(B.begin(), B.end());
				while (test2) {
					string s = "";
					reverse(A.begin(), A.end());
					reszta = 0;
					for (int i = 0; i < m; i++) {
						wynik = ((A[i] - '0') - (B[i] - '0') - reszta);
						if (wynik < 0) {
							wynik += 10;
							reszta = 1;
						}
						else {
							reszta = 0;
						}
						s += (wynik + '0');
					}
					for (int i = m; i < w; i++) {
						int wynik = ((A[i] - '0') - reszta);
						if (wynik < 0) {
							wynik += 10;
							reszta = 1;
						}
						else {
							reszta = 0;
						}
						s += (wynik + '0');
					}
					reverse(s.begin(), s.end());
					while (s[0] == '0') {
						s.erase(0, 1);
					}
					A = s;
					int dl = A.length();
					w = dl;
					d++;
					if (y > dl) {
						test2 = false;
						break;
					}
					if (dl == y) {
						for (int i = 0; i < dl; i++) {
							if (A[i] < B[i]) {
								test2 = false;
								break;
							}
							else if (A[i] > B[i]) {
								break;
							}
						}
					}
				}
			}
			cout << d << endl;
		}
	}
}