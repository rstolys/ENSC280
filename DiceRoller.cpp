#include <iostream> 
#include <fstream>
#include <string> 
#include <cstdlib> 

using namespace std;

////////////////////////////////////////////////////////////////
/// This program will simulates n dice rolls and computes the mean
///     of those rolls 
/// The rolling of those n rolls will be repated m times 
/// The program will also construct a csv file containing the 
///     results of the m trials 
////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////
/// Generates random dice roll 
/// 
/// param[in]   seed for random number generator
/// 
/// return      die_value
///
/////////////////////////////////////////////////////////
int rollDie(int seed)
{
    // return number between 1 and 6
    return ((rand() % 6) + 1); 
} 

/////////////////////////////////////////////////////////
///
/// Main Function
/// 
/////////////////////////////////////////////////////////
int main()
{
    ofstream    csv_output; 
    string      fileName = ""; 

    int         rollsPerTrial = 0; 
    int         numTrials = 0;
  
    int         trialTotal = 0;
    double       meanOfTrial = 0.0;

    int         i,j;


    // Ask user for number of rolls per trial 
    cout << "How many rolls per trial? (integer only) : "; 
    cin >> rollsPerTrial; 

    // Ask for number of trials 
    cout << "How many trials will be performed? (integer only) : "; 
    cin >> numTrials; 

    //Error checking 
    if( numTrials <= 0 || rollsPerTrial <= 0 )
    {
        cout << "Invalid inputs: " << numTrials << " OR " << rollsPerTrial << endl; 
        cout << "Must be greater than 0... TRY AGAIN" << endl; 

        return 0; 
    }

    //Ask for file name
    cout << "What is the desired name of the output file? ";
    cin >> fileName; 
    
    //Open and write top line of file 
    csv_output.open(fileName); 

    csv_output << "trailNum, meanOfTrial" << endl;


    //Initalize random number generator 
    srand(time(NULL)); 


    //Perform dice rolls 
    for(i = 0; i < numTrials; i++ )
    {
        for(j = 0; j < rollsPerTrial; j++)
        {
            trialTotal += rollDie(j + i);        //Get dice roll and add to average 
        }

        meanOfTrial = (double)trialTotal / (double)rollsPerTrial; 

        //reset trial total
        trialTotal = 0.0;

        //Print to file
        csv_output << (i + 1) << "," << meanOfTrial << endl;             
    }

    //close file 
    csv_output.close();


    return 0; 
}



