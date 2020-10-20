#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <random>
#include <stdio.h>     
#include <stdlib.h> 
#include <iostream>
#include <fstream>

using namespace std;
 
//function prototype
string player_RPS(int);
void RPS_comparison(string,string,vector<string>&,int&,int&);
void winner_tally_to_file(const vector<string>&);
void official_tally_from_file(int,int);


int main(){


//While loop
int count = 1;
int playerScore = 0;
int computerScore = 0;
vector<string> winners;
while (count <= 10){

//user input
  int user_num_input;
  string user_input;
  string comp_input;
  
  cout << "Type a number  b/w 1 and 3: " << endl;
  cout << "(1) is for rock, (2) is for paper, and (3) is for scissors: "; 

  cin >> user_num_input; // Get user input from the keyboard
  user_input = player_RPS(user_num_input);
  cout << "you selected: " << user_input << endl;

  //Computer Selection 
  string computer_selection;
    srand(time(0));
    int comp_selection = rand() % 3 + 1; /* rand()%3 == for num in range(0,3) */

    if (comp_selection == 1){
    comp_input = "paper";
    } else if (comp_selection == 2){
    comp_input = "scissor";
    } else if (comp_selection == 3){
    comp_input = "rock";
    }
    computer_selection = comp_input;
    cout << "computer selected: " << comp_input << endl;

    // Look at comment above fuction definition
    RPS_comparison(user_input,computer_selection,winners,playerScore,computerScore);

    count++;
}

 // Look at comment above function definition
 winner_tally_to_file(winners);

 return 0;
}

/* 
  parameter: 
    Vector of whoever won the round
  function: 
    Loops through vector and adds each winner line by line
 */
void winner_tally_to_file(const vector<string> &winners){
  string line;
 

  

  ofstream MyFile("rpx.txt");
  if (MyFile.is_open()){

      // Format line 77 to follow the grading format
      for(string winner:winners){
        MyFile<<winner<<endl;
      }
      
      MyFile.close();
  }
  else{
    cout<<"Cannot read this file"<< endl;
  }

}


//
void official_tally_from_file(int userScore,int computerScore) {
  // Do the same as winner_tally_to_file
}

//player RPS  functiion 

string player_RPS( int user_choice){
  if (user_choice==1){
    return "rock";
    cout <<" you picked rock"; 
  }

  else if (user_choice == 2){
    return "paper";
  }

  else {
    return "scissor";
  }

} 


/* 
  parameters:
    {user_input}: string of user input
    {comp_input}: string of computer input
    {winners}: a vector to place each round winner within for later use(for file implementation)
    {playerScore}: integer of current player score
    {computerScore}: integer of current computer score
  function: 
    Compares user's choice with computer's choice and checks to see who won
 */
void RPS_comparison(string user_input , string comp_input,vector<string>& winners, int &playerScore, int &computerScore){


//(1) is for rock, (2) is for paper, and (3) is for scissors: 

  if(comp_input  == user_input) {
    cout << "It was a tie!" << endl;
    ++playerScore; ++computerScore;
    winners.push_back("Tie");
  } else if (comp_input  == "rock" && user_input  == "scissor") {
      cout << "The computer won! Better luck next time!" << endl;
      ++computerScore;
      winners.push_back("Computer");
  } else if (comp_input == "paper" && user_input  == "rock") {
      cout << "The computer won! Better luck next time!" << endl;
      ++computerScore;
      winners.push_back("Computer");
  }else if (comp_input  == "scissor" && user_input  == "paper") {
      cout << "The computer won! Better luck next time!" << endl;
      ++computerScore;
      winners.push_back("Computer");
  } else {
      cout << "Congrats! You won!" << endl;
      ++playerScore;
      winners.push_back("User");
  }

}


//Do not understand what the 2*5 Dimension array is for!!




