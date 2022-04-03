#include <iostream>
#include <string>

using namespace std;

void print_line(int C, int s) {
    if (s==0){
        for (int i = 0; i < C; i++) {
            cout << '+'<< '-';
        }
        cout << '+' << '\n';
    }
    else if(s==1) {
        for (int i = 0; i < C; i++) {
            cout << '|'<< '.';
        }
        cout << '|' << '\n';
    }
    else if(s==2) {
        cout<<'.'<<'.';
        for (int i = 0; i < C-1; i++) {
            cout << '+'<< '-';
        }
        cout << '+' << '\n';
    }
    else {
        cout<<'.'<<'.';
        for (int i = 0; i < C-1; i++) {
            cout << '|'<< '.';
        }
        cout << '|' << '\n';
    }
}

void print_card(int R, int C) {
    print_line(C,2);
    print_line(C,3);
    for (int i = 0; i < R-1; i++) {
        print_line(C,0);
        print_line(C,1);
    }
    print_line(C,0);
}

int main()
{
    int T;
    cin >> T;
    for(int t=0; t<T; t++) {
        cout<<"Case #"<<t+1<<":\n";
        int R, C;
        cin >> R >> C;
        print_card(R,C);
    }
}