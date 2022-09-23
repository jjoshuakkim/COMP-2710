/* FILE NAME: project3_Kim_jjk0027.cpp
 * USERID: jjk0027
 * AUTHOR: Joshua Kim
 * I did not use any external help on this project, other than lecture videos.
 * Compile command: g++ project3_Kim_jjk0027.cpp -o project3.out
 * Run Command: ./project3.out
*/
#include <fstream>
#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

int readfile(int input_array[], ifstream& instream) 
{
    int index = 0;

    instream >> input_array[index];
    while (!instream.eof()) 
    {
        index++;
        instream >> input_array[index];
    }
    return index;
}

int sort(int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[])
{
    int i = 0;
    int k = 0;
    int outputIndex = 0;
    bool checkedAll = false;

    while (!checkedAll)
    {
        if (i < inputArray1_size && k < inputArray2_size)
        {
            if (inputArray1[i] <= inputArray2[k])
            {
                outputArray[outputIndex] = inputArray1[i];
                i++;
            }

            else
            {               
                outputArray[outputIndex] = inputArray2[k];
                k++;
            }

            outputIndex++;
        }

        else if (i < inputArray1_size)
        {
            outputArray[outputIndex] = inputArray1[i];
            i++;
            outputIndex++;
        }

        else if (k < inputArray2_size)
        {
            outputArray[outputIndex] = inputArray2[k];
            k++;
            outputIndex++;
        }

        else
        {
            checkedAll = true;
        }
    }

    return outputIndex;
}

void writefile(int outputArray[], int outputArray_size)
{
    ofstream output;
    string output_filename;

    cout << "\nEnter the output file name: ";
    cin >> output_filename;
    output.open((char*)output_filename.c_str());

    for (int i = 0; i < outputArray_size; i++)
    {
        output << outputArray[i] << endl;
    }

    output.close();
    cout << "*** Please check the new file -" << output_filename << "\n****** Goodbye. ***";
}

int main() 
{
    string fileName, fileName2;
    ifstream openFile;

    int iArray1[MAX_SIZE];
    int iArray1_size;
    int iArray2[MAX_SIZE];
    int iArray2_size;
    int outputArr[MAX_SIZE];
    int outputArr_size;

    cout << "*** Welcome to Joshua's sorting program ***" << endl;
    
    do {
        cout << "Enter the first input file name: ";
        cin >> fileName;
        openFile.open((char*)fileName.c_str());
        if (openFile.eof())
        {
            break;
        }

        else if (openFile.fail()) 
        {
            cout << "Error: Invalid filename, please try again" << endl;
        }
    }
    while (openFile.fail());

    iArray1_size = readfile(iArray1, openFile);
    openFile.close();
    cout << "The list of " << iArray1_size << " numbers in file " << fileName << " is:\n";
    for (int i = 0; i < iArray1_size; i++)
    {
        cout << iArray1[i] << endl;
    }

    do {
        cout << "Enter the second input file name: ";
        cin >> fileName2;
        openFile.open((char*)fileName2.c_str());
        if (openFile.eof())
        {
            break;
        }

        else if (openFile.fail()) 
        {
            cout << "Error: Invalid filename, please try again" << endl;
        }
    }
    while (openFile.fail());

    iArray2_size = readfile(iArray2, openFile);
    openFile.close();
    cout << "The list of " << iArray2_size <<  " numbers in file " << fileName2 << " is:\n";
    for (int i = 0; i < iArray2_size; i++)
    {
        cout << iArray2[i] << endl;
    }

    outputArr_size = sort(iArray1, iArray1_size, iArray2, iArray2_size, outputArr);
    cout << "The sorted list of " << outputArr_size << " numbers is: ";

    for (int i = 0; i < (iArray1_size + iArray2_size); i++)
    {
        cout << outputArr[i] << " ";
    }

    writefile(outputArr, outputArr_size);
}