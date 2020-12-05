#include <iostream>

using namespace std;

void reverse(const string& x);

int main()
{
    string sentence;
    cout << "Enter a string :" <<endl;
    getline (cin, sentence);
    reverse(sentence);
    return 0;
}

void reverse(const string& sentence)
{
    size_t numOfChars = sentence.size();
    if (numOfChars == 1)
        cout << sentence << endl;
    else
    {
        cout << sentence [numOfChars -1];
        reverse(sentence.substr(0, numOfChars -1));
    }
}