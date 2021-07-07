#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    
    for (vector<string>::iterator iter = phone_book.begin(); iter + 1 != phone_book.end(); iter++) {
        if (*iter == (*(iter + 1)).substr(0, (*iter).length())) return false;
    }
    
    return answer;
}