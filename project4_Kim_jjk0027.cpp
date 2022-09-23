/* FILE NAME: project4_Kim_jjk0027
 * USER ID: jjk0027
 * AUTHOR: Joshua Kim
 * I used stackOverflow to learn more about linked lists.
 * I used stackOverflow to learn how to make two verison of the main method.
 * Compile command: g++ project4_Kim_jjk0027.cpp -o project4.out
 * Run Command: ./project4.out
 */

#include <iostream>
#include <cstdlib>
#include <assert.h>
#include <climits>
#include <fstream>

using namespace std;

struct triviaNode
{
    string question;
    string answer;
    int points;
    triviaNode* next;
};

typedef triviaNode* ptr_node;
int num_of_questions = 0;
int pointsMade;
bool userInput = false;

void clear() 
{
	cin.clear();
	cin.ignore(INT_MAX, '\n');
}

void init_question_list(ptr_node& q_list)
{
    ptr_node cur_ptr = new triviaNode;
    cur_ptr->question = "How long was the shortest war on record?";
    cur_ptr->answer = "38";
    cur_ptr->points = 100;
    num_of_questions++;

    cur_ptr->next = new triviaNode;
    q_list = cur_ptr;
    cur_ptr = q_list->next;

    cur_ptr->question = "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)";
    cur_ptr->answer = "Bank of Italy";
    cur_ptr->points = 50;
    num_of_questions++;

    cur_ptr->next = new triviaNode;
    cur_ptr = cur_ptr->next;

    cur_ptr->question = "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)";
    cur_ptr->answer = "Wii Sports";
    cur_ptr->points = 20;
    cur_ptr->next = NULL;
    num_of_questions++;
}

void add_question(ptr_node& q_list)
{
    string answer;
    ptr_node new_ptr = new triviaNode;
    ptr_node temp = new triviaNode;

    cout << "Enter a new question: ";
    getline(cin, new_ptr->question);

    cout << "Enter an answer: ";
    getline(cin, new_ptr->answer);

    cout << "Enter award points: ";
    cin >> new_ptr->points;

    num_of_questions++;
    new_ptr->next = q_list;
	q_list = new_ptr;
    userInput = true;
}

int ask_question(ptr_node q_list, int num_ask) 
{
    string user_answer;
    ptr_node cur_ptr;
    pointsMade = 0;
    int x = 0;
    cur_ptr = q_list;

    if (q_list == NULL)
    {
        return 1;
    }

    if (num_ask < 1) 
    {
        cout << "Warning - the number of trivia to be asked must equal to or be larger than 1." << endl;
    }

    else if (num_of_questions < num_ask) 
    {
        cout <<"Warning - There is only "<< num_of_questions <<" trivia in the list.";
    }

    else
    {
        for (int x = 0; x < num_ask; x++) 
        {
            if (!cur_ptr == NULL)
            {
                cout << endl;
                cout << "Question: " << cur_ptr->question << endl;
                cout << "Answer: ";
                getline(cin, user_answer);
                if (x == 0 && userInput)
                {
                    getline(cin, user_answer);
                }
                if(user_answer.compare(cur_ptr->answer) == 0)
                {
                    cout << "Correct. You have received " << cur_ptr->points << " points." << endl;
                    pointsMade += cur_ptr->points;
                    cout << "Total points: " << pointsMade << "\n\n";
                }

                else
                {
                    cout << "Incorrect. The correct answer was " << cur_ptr->answer << endl;
                    cout << "Total points: " << pointsMade << "\n\n";
                }
                cur_ptr = cur_ptr->next;
            }
            
            else
            {
                break;
            }
        }
    }
    return 0;
}

void Unit_Test() 
{
    ptr_node node_list = new triviaNode;
    init_question_list(node_list);
    cout << "Unit Test Case 1: Ask no question. The program should give a warning message." << endl;
    ask_question(node_list, 0);
    cout << "\nCase 1 Passed\n\n";

    cout <<"Unit Test Case 2: Ask 1 question in the linked list.  The tester enters an incorrect answer."<< endl;
    ask_question(node_list, 1);
    assert(pointsMade == 0);
    cout << "\nCase 2.1 Passed\n\n";

    cout << "Unit Test Case 2.2: Ask 1 question in the linked list. The tester enters a correct answer.";
    ask_question(node_list, 1);
    assert(pointsMade == 100);
    cout << "Case 2.2 Passed\n\n";

    cout << "\nUnit Test Case 3: Ask all the questions of the last trivia in the linked list."<< endl;
	ask_question(node_list, 3);
	cout << "Case 3 passed\n\n";

    cout << "\nUnit Test Case 4: Ask 5 questions in the linked list."<< endl;
	ask_question(node_list, 5);
	cout << "\nCase 4 passed\n\n" << endl;

    cout << "***End of the Debugging Version***\n\n";
}

//#define UNIT_TESTING
#define trivia_quiz
int main()
{
    #ifdef UNIT_TESTING
    Unit_Test();
    #endif

    #ifdef trivia_quiz
    bool cont = true;
    string answer, test;
    ptr_node node_list = new triviaNode;
    init_question_list(node_list);

    cout << "***Welcome to Joshua's trivia quiz game***" << endl;
    while (cont)
    {
        add_question(node_list);
        cout << "Continue? (Yes/No): ";
        cin >> answer;
        if (answer == "No" || answer == "no" || answer == "n" || answer == "NO")
        {
            break;
        }

        else if (answer == "Yes" || answer == "yes" || answer == "y" || answer == "YES")
        {
            cont = true;
        }

        else
        {
            cout << "Type either yes/y/Yes/YES or no/n/No/NO next time.";
            exit(1);
        }
        cout << endl;
        clear();
    }
    
    ask_question(node_list, num_of_questions);
    cout <<"\n*** Thank you for playing the trivia quiz game. Goodbye! ***";
    #endif
    return 0;
}