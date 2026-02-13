#include <iostream>
#include <string>
using namespace std;

// structure for a question
struct Question {
    string text;
    string choices[4];
    int correctIndex;
};

// function prototypes
void askQuestion(Question* q, int& score);
void showResults(int score, int total);

int main() {

    // array of 4 questions
    Question quiz[4];

    // Question 1
    quiz[0].text = "Which country has over 250,000 islands?";
    quiz[0].choices[0] = "A) Philippines";
    quiz[0].choices[1] = "B) United States";
    quiz[0].choices[2] = "C) Sweden";
    quiz[0].choices[3] = "D) Canada";
    quiz[0].correctIndex = 2;

    // Question 2
    quiz[1].text = "What is the only letter that does not appear in any of the 50 U.S state names?";
    quiz[1].choices[0] = "A) Z";
    quiz[1].choices[1] = "B) Q";
    quiz[1].choices[2] = "C) Y";
    quiz[1].choices[3] = "D) B";
    quiz[1].correctIndex = 1;

    // Question 3
    quiz[2].text = "What is the only continent with no active volcanoes?";
    quiz[2].choices[0] = "A) Africa";
    quiz[2].choices[1] = "B) Australia";
    quiz[2].choices[2] = "C) Antarctica";
    quiz[2].choices[3] = "D) Europe";
    quiz[2].correctIndex = 1;

    // Question 4
    quiz[3].text = "What color is least used in the flags of countries?";
    quiz[3].choices[0] = "A) Brown";
    quiz[3].choices[1] = "B) Pink";
    quiz[3].choices[2] = "C) Purple";
    quiz[3].choices[3] = "D) Grey";
    quiz[3].correctIndex = 2;

    int score = 0;
    char start;

    cout << "Welcome to the Quiz Game!" << endl;
    cout << "Press S to start: ";
    cin >> start;

    // do-while loop for replay
    do {

        if (start == 'S' || start == 's') {

            // for loop to go through 4 questions
            for (int i = 0; i < 4; i++) {
                askQuestion(&quiz[i], score);
            }

            showResults(score, 4);
        }
        else {
            cout << "You must press S to start." << endl;
        }

        cout << "\nPlay again? (Y/N): ";
        cin >> start;

        if (start == 'Y' || start == 'y') {
            score = 0; // reset score
        }

    } while (start == 'Y' || start == 'y');

    cout << "Thanks for playing!" << endl;

    return 0;
}

// function to ask a question
void askQuestion(Question* q, int& score) {

    cout << "\n" << q->text << endl;

    // while loop to print choices
    int i = 0;
    while (i < 4) {
        cout << q->choices[i] << endl;
        i++;
    }

    char answer;
    cout << "Your answer: ";
    cin >> answer;

    int index;

    if (answer == 'A' || answer == 'a') index = 0;
    else if (answer == 'B' || answer == 'b') index = 1;
    else if (answer == 'C' || answer == 'c') index = 2;
    else if (answer == 'D' || answer == 'd') index = 3;
    else {
        cout << "Invalid." << endl;
        return;
    }

    if (index == q->correctIndex) {
        cout << "Correct!" << endl;
        score++;
    }
    else {
        cout << "Incorrect!" << endl;
    }
}

// function to show results
void showResults(int score, int total) {

    cout << "\n--- Results ---" << endl;
    cout << "Score: " << score << " out of " << total << endl;

    if (score == total) {
        cout << "Perfect!" << endl;
    }
    else if (score >= total / 2) {
        cout << "Nice work!" << endl;
    }
    else {
        cout << "We'll get them next time!" << endl;
    }
}

