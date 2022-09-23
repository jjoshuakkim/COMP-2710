/* FILE NAME: project2_Kim_jjk0027.cpp
 * USERID: jjk0027
 * AUTHOR: Joshua Kim
 * I did not use any external help on this project, other than lecture videos.
 * Compile command: g++ project2_Kim_jjk0027.cpp -o project1.out
 * Run Command: ./project2.out
*/

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <ctime>
#include <cstdlib>

using namespace std;

bool at_least_two_alive (bool A_alive, bool B_alive, bool C_alive)
{
    if ((A_alive && B_alive) || (A_alive && C_alive) || (C_alive && B_alive))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Aaron_shoots1 (bool& B_alive, bool& C_alive)
{
    const int aaronStat = 33;
    int random_shot = rand() % 100;
    if (random_shot <= aaronStat)
    {
        if (C_alive)
        {
            C_alive = false;
        }

        else
        {
            B_alive = false;
        }
    }
}

void Bob_shoots (bool& A_alive, bool& C_alive)
{
    const int bobStat = 50;
    int random_shot = rand() % 100;
    if (random_shot <= bobStat)
    {
        if (C_alive)
        {
            C_alive = false;
        }

        else
        {
            A_alive = false;
        }
    }
}

void Charlie_shoots (bool& A_alive, bool& B_alive)
{
    if (true)
    {
        if (B_alive)
        {
            B_alive = false;
        }

        else
        {
            A_alive = false;
        }
    }
}

void Aaron_shoots2 (bool& B_alive, bool& C_alive)
{
    if (!B_alive || !C_alive)
    {
        int random_shot = rand() % 100;
        if (random_shot <= 33)
        {
            if (C_alive)
            {
                C_alive = false;
            }

            else
            {
                B_alive = false;
            }
        }
    }
}

void press_Key()
{
    cout << "Press any key to continue...";
    cin.ignore().get();
}

void test_at_least_two_alive (void)
{
    cout << "Unit Testing 1: Function - at_least_two_alive() \n";

    cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
    assert (true == at_least_two_alive (true, true, true));
    cout << "\tCase passed ...\n";

    cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
    assert (true == at_least_two_alive(false, true, true));
    cout << "\tCase passed ...\n";

    cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
    assert (true == at_least_two_alive(true, false, true));
    cout << "\tCase passed ...\n";

    cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
    assert (true == at_least_two_alive(true, true, false));
    cout << "\tCase passed ...\n";

    cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
    assert (false == at_least_two_alive(false, false, true));
    cout << "\tCase passed ...\n";

    cout << "\tCase 6: Aaron alive, Bob dead, Charlie dead\n";
    assert (false == at_least_two_alive(true, false, false));
    cout << "\tCase passed ...\n";

    cout << "\tCase 7: Aaron dead, Bob alive, Charlie dead\n";
    assert (false == at_least_two_alive(false, true, false));
    cout << "\tCase passed ...\n";

    cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
    assert (false == at_least_two_alive(false, false, false));
    cout << "\tCase passed ...\n";
}

void test_Aaron_shoots1()
{
    bool bob_alive, charlie_alive;

    cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";
    cout << "\tCase 1: Bob alive, Charlie alive\n\t\tAaron is shooting at Charlie\n";
    Aaron_shoots1(bob_alive, charlie_alive);
    if (charlie_alive)
    {
        cout << "\t\tAaron misses\n";
        assert (true == charlie_alive);
    }

    else
    {
        cout << "\t\tCharlie is dead\n";
        assert (false == charlie_alive);
    }

    bob_alive = false;
    charlie_alive = true;
    cout << "\tCase 2: Bob dead, Charlie alive\n\t\tAaron is shooting at Charlie\n";
    Aaron_shoots1(bob_alive, charlie_alive);
    if (charlie_alive)
    {
        cout << "\t\tAaron misses\n";
        assert (true == charlie_alive);
    }

    else
    {
        cout << "\t\tCharlie is dead\n";
        assert (false == charlie_alive);
    }

    bob_alive = true;
    charlie_alive = false;
    cout << "\tCase 3: Bob alive, Charlie dead\n\t\tAaron is shooting at Bob\n";
    Aaron_shoots1(bob_alive, charlie_alive);
    if (bob_alive)
    {
        cout << "\t\tAaron misses\n";
        assert (true == bob_alive);
    }

    else
    {
        cout << "\t\tBob is dead\n";
        assert (false == bob_alive);
    }
}

void test_Bob_shoots()
{
    bool aaron_alive, charlie_alive;
    cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";
    cout << "\tCase 1: Aaron alive, Charlie alive\n\t\tBob is shooting at Charlie\n";
    Bob_shoots(aaron_alive, charlie_alive);
    if (charlie_alive)
    {
        cout << "\t\tBob misses\n";
        assert (true == charlie_alive);
    }

    else
    {
        cout << "\t\tCharlie is dead\n";
        assert (false == charlie_alive);
    }

    aaron_alive = false;
    charlie_alive = true;
    cout << "\tCase 2: Aaron dead, Charlie alive\n\t\tBob is shooting at Charlie\n";
    Bob_shoots(aaron_alive, charlie_alive);
    if (charlie_alive)
    {
        cout << "\t\tBob misses\n";
        assert (true == charlie_alive);
    }

    else
    {
        cout << "\t\tCharlie is dead\n";
        assert (false == charlie_alive);
    }

    aaron_alive = true;
    charlie_alive = false;
    cout << "\tCase 3: Aaron alive, Charlie dead\n\t\tBob is shooting at Aaron\n";
    Bob_shoots(aaron_alive, charlie_alive);
    if (aaron_alive)
    {
        cout << "\t\tBob misses\n";
        assert (true == aaron_alive);
    }

    else
    {
        cout << "\t\tAaron is dead\n";
        assert (false == aaron_alive);
    }
}

void test_Charlie_shoots()
{
    bool aaron_alive, bob_alive;
    cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";
    cout << "\tCase 1: Aaron alive, Bob alive\n\t\tCharlie is shooting at Bob\n";
    Charlie_shoots(aaron_alive, bob_alive);
    if (bob_alive)
    {
        cout << "\t\tCharlie misses\n";
        assert (true == bob_alive);
    }

    else
    {
        cout << "\t\tBob is dead\n";
        assert (false == bob_alive);
    }

    aaron_alive = false;
    bob_alive = true;
    cout << "\tCase 2: Aaron dead, Bob alive\n\t\tCharlie is shooting at Bob\n";
    Charlie_shoots(aaron_alive, bob_alive);
    if (bob_alive)
    {
        cout << "\t\tCharlie misses\n";
        assert (true == bob_alive);
    }

    else
    {
        cout << "\t\tBob is dead\n";
        assert (false == bob_alive);
    }

    aaron_alive = true;
    bob_alive = false;
    cout << "\tCase 3: Aaron alive, Bob false\n\t\tCharlie is shooting at Aaron\n";
    Charlie_shoots(aaron_alive, bob_alive);
    cout << "\t\tAaron is dead\n";
    assert (false == aaron_alive);
}

void test_Aaron_shoots2()
{
    bool bob_alive, charlie_alive;
    bob_alive = true;
    charlie_alive = true;

    cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";
    cout << "\tCase 1: Bob alive, Charlie alive\n\t\tAaron intentionally misses his first shot\n";

    Aaron_shoots2(bob_alive, charlie_alive);
    assert (true == bob_alive);
    assert (true == charlie_alive);
    cout << "\t\tBoth Bob and Charlie are alive.\n";

    bob_alive = false;
    charlie_alive = true;
    cout << "\tCase 2: Bob dead, Charlie_alive\n\t\tAaron is shooting at Charlie\n";

    Aaron_shoots2(bob_alive, charlie_alive);
    if (charlie_alive)
    {
        cout << "\t\tAaron misses\n";
        assert (true == charlie_alive);
    }

    else
    {
        cout << "\t\tCharlie is dead\n";
        assert (false == charlie_alive);
    }

    bob_alive = true;
    charlie_alive = false;
    cout << "\tCase 3: Bob alive, Charlie dead\n\t\tAaron is shooting at Bob\n";

    Aaron_shoots2(bob_alive, charlie_alive);
    if (bob_alive)
    {
        cout << "\t\tAaron_misses\n";
        assert (true == bob_alive);
    }

    else
    {
        cout << "\t\tBob is dead\n";
        assert (false == bob_alive);
    }
}

int main()
{
    cout << "***Welcome to Joshua's Duel Simulator***\n";
    srand(time(0));

    test_at_least_two_alive();
    press_Key();

    test_Aaron_shoots1();
    press_Key();

    test_Bob_shoots();
    press_Key();

    test_Charlie_shoots();
    press_Key();

    test_Aaron_shoots2();
    press_Key();

    cout << "Ready to test strategy 1 (run 10000 times):\n";
    press_Key();

    bool aaronAlive, bobAlive, charlieAlive;
    int aaronPoints = 0;
    int bobPoints = 0;
    int charliePoints = 0;

    const int TOTAL_RUNS = 10000;

    for (int i = 0; i < TOTAL_RUNS; i++)
    {
        aaronAlive = true;
        bobAlive = true;
        charlieAlive = true;
        while (at_least_two_alive(aaronAlive, bobAlive, charlieAlive))
        {
            if (aaronAlive)
            {
                Aaron_shoots1(bobAlive, charlieAlive);
            }

            if (bobAlive)
            {
                Bob_shoots(aaronAlive, charlieAlive);
            }

            if (charlieAlive)
            {
                Charlie_shoots(aaronAlive, bobAlive);
            }
        }

        if (aaronAlive)
        {
            aaronPoints++;
        }

        else if (bobAlive)
        {
            bobPoints++;
        }

        else
        {
            charliePoints++;
        }
    }

    cout << "Aaron won " << aaronPoints << "/10000 duels or " << static_cast<double> (aaronPoints) / 100 << "%\n"
         << "Bob won " << bobPoints << "/10000 duels or " << static_cast<double> (bobPoints) / 100 << "%\n"
         << "Charlie won " << charliePoints << "/10000 duels or " << static_cast<double> (charliePoints) / 100 << "%\n"
         << "\nReady to test strategy 2 (run 10000 times):\n";
    press_Key();

    int aaronPoints2 = 0;
    int bobPoints2 = 0;
    int charliePoints2 = 0;
    for (int i = 0; i < TOTAL_RUNS; i++)
    {
        aaronAlive = true;
        bobAlive = true;
        charlieAlive = true;
        while (at_least_two_alive(aaronAlive, bobAlive, charlieAlive))
        {
            if (aaronAlive)
            {
                Aaron_shoots2(bobAlive, charlieAlive);
            }

            if (bobAlive)
            {
                Bob_shoots(aaronAlive, charlieAlive);
            }

            if (charlieAlive)
            {
                Charlie_shoots(aaronAlive, bobAlive);
            }
        }

        if (aaronAlive)
        {
            aaronPoints2++;
        }

        else if (bobAlive)
        {
            bobPoints2++;
        }

        else
        {
            charliePoints2++;
        }
    }

    cout << "Aaron won " << aaronPoints2 << "/10000 duels or " << static_cast<double> (aaronPoints2) / 100 << "%\n"
         << "Bob won " << bobPoints2 << "/10000 duels or " << static_cast<double> (bobPoints2) / 100 << "%\n"
         << "Charlie won " << charliePoints2 << "/10000 duels or " << static_cast<double> (charliePoints2) / 100 << "%\n";

    if (aaronPoints > aaronPoints2)
    {
        cout << "\nStrategy 1 is better than strategy 2\n";
    }

    else
    {
        cout << "\nStrategy 2 is better than strategy 1\n";
    }
}