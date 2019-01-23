#include <iostream>
#include <string>
using namespace std;

class Tennis
{
public:
	Tennis();
	void createPlayer(string player1Name, string player2Name);
	bool isPlayerNameValid(string playerName);
	void WonPoint (string playerName);
	string GetGameScore ();
private:
	int score1;
    int score2;
    string player1Name;
    string player2Name;
};

Tennis::Tennis()
{
    score1 = 0;
    score2 = 0;
}


void Tennis::createPlayer (string player1, string player2)
{
    player1Name = player1;
    player2Name = player2;
}

bool Tennis::isPlayerNameValid(string playerName)
{
	if((playerName == player1Name) ||(playerName == player2Name))
		return true;
	else
		return false;
}

void Tennis::WonPoint (string playerName)
{
    if (playerName == player1Name)
        score1 += 1;
    else
        score2 += 1;
}

string Tennis:: GetGameScore ()
{
      string gameScore = "";
      int tempScore=0;
	  /*if score is same */
      if (score1==score2)
      {
        switch (score1)
        {
        case 0:
          gameScore = "Love-All";
          break;
        case 1:
          gameScore = "Fifteen-All";
          break;
        case 2:
          gameScore = "Thirty-All";
          break;
        default:
          gameScore = "Deuce";
          break;
        }
      }
      else if (score1>=4 || score2>=4)
      {
        int minusResult = score1-score2;
        if (minusResult==1) 
			gameScore ="Advantage player1";
        else if (minusResult ==-1) 
			gameScore ="Advantage player2";
        else if (minusResult>=2) 
			gameScore = "Win for player1";
        else 
			gameScore ="Win for player2";
      }
      else
      {
        for (int i=1; i<3; i++)
        {
          if (i==1) tempScore = score1;
          else { gameScore+="-"; tempScore = score2;}
          switch(tempScore)
          {
          case 0:
            gameScore+="Love";
            break;
          case 1:
            gameScore+="Fifteen";
            break;
          case 2:
            gameScore+="Thirty";
            break;
          case 3:
            gameScore+="Forty";
            break;
          }
        }
      }
      return gameScore;
    }


int main()
{
	string player1,player2,playerName;
	Tennis myTennis;
	cout<<"Enter Player 1 Name"<<endl;
	cin>>player1;
	cout<<"Enter Player 2 Name"<<endl;
	cin>>player2;

	myTennis.createPlayer(player1,player2);
	while(1) {
	    cout<<"Enter the player who won the point"<<endl;
	    cin>> playerName;
	    if(myTennis.isPlayerNameValid(playerName))
	    {
		    myTennis.WonPoint(playerName);
		    cout<<"Score is " << myTennis.GetGameScore()<<endl;
			if((myTennis.GetGameScore() == "Win for player1") || (myTennis.GetGameScore() == "Win for player2")) {
				break;
			}
	    }
	    else {
		    cout<<"Wrong Player: Please choose "<<player1 <<" or "<<player2 <<endl;
	    }
	}
	system("PAUSE");
}
