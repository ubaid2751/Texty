#ifndef _SO_H
#define _SO_H
#include<string>
#include<vector>
#include<fstream>

#define String std::string
#define Vector std::vector
static String punctuations = "!\"'(),-.:;?[]_{}";

Vector<String> separateWordWithDelimiter(String st, char ch);
String removePunctuations(String &st);

bool searchCharacter(String &st, char &ch);

#endif

#ifdef _SO_IMPLEMENTATION
class FileHandle {
private:
    int noOfChars;
    int noOfLines;
    int noOfWords;
    fstream file;
    Vector<String> words;

public:
    String fileContent;
    String contentWithPunc;
    Vector<String> LineContent;

    FileHandle(String file_name) {
        noOfChars = 0;
        noOfLines = 0;
        noOfWords = 0;
        file.open(file_name, ios::in);

        if (!file.is_open()) {
            std::cerr << "Failed to open file " << file_name << std::endl;
            return;
        }

        fileContent = "";
        String text = "";

        while(getline(file, text)) {
            LineContent.push_back(text);
            fileContent += text;
            fileContent += " ";
            noOfLines += 1;
            noOfChars += text.size();
        }

        file.close();
        contentWithPunc = removePunctuations(fileContent);
    }

    String getContents() {
        return this->fileContent;
    }

    void showLineContents() {
        std::cout << "[\n";
        for(auto &line: LineContent) {
            std::cout << line << std::endl;
        }
        std::cout << "]\n";
    }

    bool find(String wordToFind) {
        for(auto &word: words) {
            if(word == wordToFind) {
                return true;
            }
        } 
        return false;
    }

    void separateWords() {
        String st = contentWithPunc;
        String temp = "";
        int size = st.size();

        for(int i = 0; i < size; i++) {
            char ch = st[i];
            if(ch == ' ') {
                if(temp.size() > 0) {
                    words.push_back(temp);
                    temp = "";
                }
            }
            else {
                temp += ch;
            }
        }
        if(temp.size() > 0) {
            words.push_back(temp);
        }
        noOfWords = words.size();
    }

    void showWords() {
        cout << "[\n"; 
        for(auto &word: words) {
            cout << word << ", ";
        }
        cout << "\n]";
    }

    void toLower() {
        for (int i = 0; i < fileContent.size(); i++) {
            char ch = fileContent[i];
            if(ch >= 'A' && ch <= 'Z') {
                fileContent[i] = ch - 'A' + 'a';
            }
        }
    }

    bool searchWord(string s, string word) {
        string temp = "";
        int size = s.size();

        for(int i = 0; i < size; i++) {
            char ch = s[i];
            if(ch == ' ' && temp.size() > 0) {
                if(temp == word) {
                    return true;
                }
                else {
                    temp = "";
                }
            }
            else {
                temp += ch;
            }
        }
        return false;
    }

    void findWordinFile(String word) {
        cout << "Lines at which \"" << word << "\" is present: [";
        for(int i = 0; i < LineContent.size(); i++) {
            if(searchWord(removePunctuations(LineContent[i]), word)) {
                cout << (i+1) << ", ";
            }
        }
        cout << "]";
    }    

    int averageWordLength() {
        if(words.size() <= 0) {
            return 0;
        }

        int sum = 0;
        for(auto &word: words) {
            sum += word.size();
        }
        return sum / words.size();
    }
};

bool searchCharacter(String &punctuations, char &ch) {
    for(int i = 0; i < punctuations.size(); i++) {
        if(punctuations[i] == ch) {
            return true;
        }
    }
    return false;
}

String removePunctuations(String &st) {
    String ans = "";
    for(int i = 0; i < st.size(); i++) {
        char ch = st[i];
        if(searchCharacter(punctuations, ch) == false) {
            ans += ch;
        }
        else {
            ans += " ";
        }
    }
    return ans;
}

Vector<String> separateWordWithDelimiter(String st, char delimiter=' ') {
    Vector<String> words;
    String temp = "";
    int size = st.size();

    for(int i = 0; i < size; i++) {
        char ch = st[i];
        if(ch == delimiter) {
            if(temp.size() > 0) {
                words.push_back(temp);
                temp = "";
            }
        }
        else {
            temp += ch;
        }
    }
    if(temp.size() > 0) {
        words.push_back(temp);
    }
    return words;
}

#endif