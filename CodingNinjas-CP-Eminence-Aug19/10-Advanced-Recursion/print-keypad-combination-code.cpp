/*
 * Author: Jitendra Kumar (seawolf001)
 * Email: jitendra.iitp@gmail.com
 */
#include <string>
using namespace std;

string get_chars(int d) {
    switch(d) {
        case 2: return "abc"; break;
        case 3: return "def"; break;
        case 4: return "ghi"; break;
        case 5: return "jkl"; break;
        case 6: return "mno"; break;
        case 7: return "pqrs"; break;
        case 8: return "tuv"; break;
        case 9: return "wxyz"; break;
        default : return ""; break;
    }
}

void keypad_recurr(int num, string curr) {
    if (num <= 0) {
        cout << curr << endl;
        return;
    } else {
        int d = num % 10;
        num /= 10;
        string chars = get_chars(d);
        for (int i=0; i < chars.size(); i++) {
            keypad_recurr(num, chars[i]+curr);
        }
    }
}

void printKeypad(int num){
    keypad_recurr(num, "");
}

