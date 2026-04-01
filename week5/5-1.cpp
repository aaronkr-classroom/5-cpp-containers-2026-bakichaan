#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 문자열을 단어로 나누기 (직접 구현)
vector<string> split(const string& line) {
    vector<string> words;
    string word = "";

    for (int i = 0; i < line.length(); i++) {
        if (line[i] == ' ') {
            if (word != "") {
                words.push_back(word);
                word = "";
            }
        }
        else {
            word += line[i];
        }
    }

    if (word != "") words.push_back(word);

    return words;
}

// 단어들을 하나의 문자열로 합치기
string join(const vector<string>& words) {
    string result = "";
    for (int i = 0; i < words.size(); i++) {
        result += words[i];
        if (i != words.size() - 1)
            result += " ";
    }
    return result;
}

// 문자열 비교 (사전순)
bool isLess(const string& a, const string& b) {
    int len = (a.length() < b.length()) ? a.length() : b.length();

    for (int i = 0; i < len; i++) {
        if (a[i] < b[i]) return true;
        if (a[i] > b[i]) return false;
    }
    return a.length() < b.length();
}

// 버블 정렬
void bubbleSort(vector<string>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (!isLess(arr[j], arr[j + 1])) {
                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    vector<string> lines;
    string input;

    // 입력
    while (getline(cin, input)) {
        if (input != "")
            lines.push_back(input);
    }

    vector<string> result;

    // 순환 인덱스 생성
    for (int i = 0; i < lines.size(); i++) {
        vector<string> words = split(lines[i]);
        int n = words.size();

        for (int j = 0; j < n; j++) {
            vector<string> rotated;

            // j부터 끝까지
            for (int k = j; k < n; k++)
                rotated.push_back(words[k]);

            // 0부터 j-1까지
            for (int k = 0; k < j; k++)
                rotated.push_back(words[k]);

            result.push_back(join(rotated));
        }
    }

    // 정렬
    bubbleSort(result);

    // 출력
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }

    return 0;
}
