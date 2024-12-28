#include <iostream>
using namespace std;

struct stQuestion {
    short QuestionNumber1, QuestionNumber2;
};

struct stQuizz {

    short QuestionsNumber, QuestionLevel, OperationType, UserAnswer, WrongAnswers = 0, RightAnswers = 0;
    stQuestion Questions;
    
};

stQuizz Requirement() {

    stQuizz Info;

    cout << "How many questinos you want to answer? " << endl;
    cin >> Info.QuestionsNumber;

    cout << "Enter Questions Level [1] Easy, [2] Med, [3] Hard, [4] Mix : " << endl;
    cin >> Info.QuestionLevel;

    cout << "Enter Operation Type [1] Add, [2] Sub, [3] Multiply, [4] Division, [5] Mix : " << endl;
    cin >> Info.OperationType;
  
    return Info;
}

int RandomNumber(int From, int To) {

    int randNum = rand() % (To + From - 1) + From;
    return randNum;
}

char GetOperationType(short OpType) {

    switch (OpType)
    {
    case 1:
        return '+';
        break;
    case 2:
        return '-';
        break;
    case 3:
        return '*';
        break;
    case 4:
        return '/';
        break;
    case 5:
        return GetOperationType(RandomNumber(1, 4));
        break;
    default:
        return '+';
        break;
    }

}

int GetQuestionElement(short QuestionLevel) {
    
    switch (QuestionLevel)
    {
    case 1:
        return RandomNumber(1, 10);
        break;
    case 2:
        return RandomNumber(10, 50);
        break;
    case 3:
        return RandomNumber(50, 100);
        break;
    case 4:
        return RandomNumber(1, 20);
        break;
    default:
        return RandomNumber(1, 10);
        break;
    }

}

void CurrentResult(short Answer, stQuizz &Info) {

    if (Answer == Info.UserAnswer)
    {
        system("color 2F");
        Info.RightAnswers++;
        cout << "Right Answer :-)\n";
    }
    else
    {
        system("color 4F");
        cout << "\a";
        cout << "Wrong Answer :-(\n";
        cout << "Right Answer is " << Answer << endl;
        Info.WrongAnswers++;
    }

}

string PassFail(stQuizz Info) {

    if (Info.RightAnswers > Info.WrongAnswers)
        return "Pass :-)";
    else 
        return "Fail :-(";
}

string OpTypeUsed(stQuizz Info) {

    switch (Info.OperationType)
    {
    case 1:
        return "Add";
        break;
    case 2:
        return "Sub";
        break;
    case 3:
        return "Multiply";
        break;
    case 4:
        return "Division";
        break;
    case 5:
        return "Mix";
        break;
    default:
        return " ";
        break;
    }

}

string LevelHardness(stQuizz Info) {

    switch (Info.QuestionLevel)
    {
    case 1:
        return "Easy";
        break;
    case 2:
        return "Medium";
        break;
    case 3:
        return "Hard";
        break;
    case 4:
        return "Mix";
        break;
    default:
        return " ";
        break;
    }
}

void GetQuestion(short Question, stQuizz& Info) {

    Info.Questions.QuestionNumber1 = GetQuestionElement(Info.QuestionLevel);
    Info.Questions.QuestionNumber2 = GetQuestionElement(Info.QuestionLevel);
    char OpType = GetOperationType(Info.OperationType);

    cout << "\nQuestion [" << Question << "/" << Info.QuestionsNumber << "]:\n";
    cout << Info.Questions.QuestionNumber1 << endl;
    cout << Info.Questions.QuestionNumber2 << "\t" << OpType << endl;
    cout << "--------------\n";
    cin >> Info.UserAnswer;

    int Result;

    switch (OpType)
    {
    case '+':
        Result = Info.Questions.QuestionNumber1 + Info.Questions.QuestionNumber2;
        break;
    case '-':
        Result = Info.Questions.QuestionNumber1 - Info.Questions.QuestionNumber2;
        break;
    case '*':
        Result = Info.Questions.QuestionNumber1 * Info.Questions.QuestionNumber2;
        break;
    case '/':
        Result = Info.Questions.QuestionNumber1 / Info.Questions.QuestionNumber2;
        break;
    default:
        Result = Info.Questions.QuestionNumber1 / Info.Questions.QuestionNumber2;
        break;
    }

    CurrentResult(Result, Info);

}

void FinalResult(stQuizz Info) {
    
    cout << "------------------------\n";
    cout << "Final Result is" << PassFail(Info) << endl;
    cout << "------------------------\n";
    cout << "Number Of Questions : " << Info.QuestionsNumber << endl;
    cout << "QuestionsLevel : " << LevelHardness(Info) << endl;
    cout << "Operation Type : " << OpTypeUsed(Info) << endl;
    cout << "Number Of Right Answers: " << Info.RightAnswers<< endl;
    cout << "Number Of Wrong Answers: " << Info.WrongAnswers<< endl;

}

void StartGame(stQuizz &Info) {

    for (short Question = 1; Question <= Info.QuestionsNumber; Question++)
    {
        GetQuestion(Question, Info);
    }

}

void ResetScreen() {
    system("cls");
    system("color 0F");
}

bool MoreQuestions() {

    char Answer;

    do
    {
        cout << "Do you Want to answer more questinos ? Yes :[Y/y], No :[N/n] : ";
        cin >> Answer;

    } while (Answer != 'Y' && Answer != 'y' && Answer != 'N' && Answer != 'n');

    if (Answer == 'Y' || Answer == 'y')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Game() {

    do
    {
        ResetScreen();
        stQuizz Info = Requirement();
        StartGame(Info);
        FinalResult(Info);

    } while (MoreQuestions());


}

int main()
{
    srand((unsigned)time(NULL));
    Game();

}