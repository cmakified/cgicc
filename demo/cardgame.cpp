#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <fstream>
#include <queue>

#include "cgicc/CgiDefs.h"
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"
#include "cgicc/HTTPCookie.h"
#define COOKIE_NAME "ELPIELOJUEGO"
#define COOKIE_FILE_NAME "sessions.tmp"
#define GAME_FILE_NAME "games.tmp"
#define MAX_GAME 10

using namespace std;
using namespace cgicc;

struct datasplayer
{
	vector <string > cardsList;
	string identifiant;
	bool isPlaying;
	int points;
};

struct datasgame
{
	vector <datasplayer > playersList;
	queue<string> playedCards;
	queue<string> piocheCards;

};
	
string convertStructToString( datasplayer *pPlayer)
{
	
	std::vector<string>::iterator itVectorData;
	stringstream buffer;
	buffer <<pPlayer->identifiant<<"::";
	for(itVectorData = pPlayer->cardsList.begin(); itVectorData != pPlayer->cardsList.end(); itVectorData++)
	{
	
		buffer << *itVectorData;
		if (itVectorData != pPlayer->cardsList.end())
		{
			buffer <<"||";
	
		}
	}
	
	//Global Separator
	
	return buffer.str();
}

datasplayer * convertStringToStuct( string pPlayer)
{
	datasplayer *datas= new datasplayer;
	char *carList=(char *)pPlayer.c_str();
	int wordCounter=0;
	string word;
	stringstream actualWord;
	for (unsigned int i=0;i<pPlayer.size();i++)
	{
		if (i+1<pPlayer.size())
		if (carList[i]==':'&&carList[i+1]==':')
		{
			word=actualWord.str();
			//first , the player name
			if (wordCounter==0)
			{
				//first is no data word
			}
			else
			if (wordCounter==1)
			{
				datas->identifiant=word;
			}else 
			{
				datas->cardsList.push_back(word);
			}
			wordCounter++;
			actualWord.clear();
			i++;
		}else {
			actualWord <<carList[i];
		}
	}
	
	
	return datas;
}

string getNUMCookie(std::vector< HTTPCookie > pCookieVector)
{
	
	if (pCookieVector.size()== 0)
		return "";
	std::vector<HTTPCookie>::iterator itVectorData;
	for(itVectorData = pCookieVector.begin(); itVectorData != pCookieVector.end(); itVectorData++)
	{
		
		HTTPCookie theCookie = *(itVectorData);
		if (theCookie.getName ().compare(COOKIE_NAME)==0)
		{
			return theCookie.getValue ();
		}
	}


	return "";
}

string getValue(string pName)
{
	ifstream inFile;
	inFile.open(COOKIE_FILE_NAME);
	if (!inFile) {
		ofstream outFile(COOKIE_FILE_NAME, ios::out);
		outFile.put('\n');
		outFile.close();
		inFile.open(COOKIE_FILE_NAME);
	}
	// Lecture ligne a ligne
	  while (inFile&&!inFile.eof ())
	  {
	    char ligne[32000];
	    std::string s;

	    inFile.getline (ligne, sizeof (ligne));
	    s = ligne;
		
	    if (s.find (pName)!= string::npos)
	    {
		
		    s.replace(0,pName.size(),""); 
		    inFile.close();
		    return s;
	    }
	  }
	  inFile.close();
	  return "";

}

string getFileGame(string pName)
{
	ifstream inFile;
	inFile.open(GAME_FILE_NAME);
	if (!inFile) {
		ofstream outFile(GAME_FILE_NAME, ios::out);
		outFile.put('\n');
		outFile.close();
		inFile.open(GAME_FILE_NAME);
	}
	// Lecture ligne a ligne
	  while (inFile&&!inFile.eof ())
	  {
	    char ligne[32000];
	    std::string s;

	    inFile.getline (ligne, sizeof (ligne));
	    s = ligne;
		
	    if (s.find (pName)!= string::npos)
	    {
		
		    inFile.close();
		    return s;
	    }
	  }
	  inFile.close();
	  return "";

}

datasgame *getGame(string pName)
{
	datasgame *dgame= new datasgame;
	string vGame=getFileGame(pName);
	if (vGame.compare("")==0)
	{
		return NULL; 
	}
	
	
	
	char *carList=(char *)vGame.c_str();
	int wordCounter=0;
	string word;
	stringstream actualWord;
	int vNBPLayers=0;
	int playerCounter=0;
	int playerCounterElement=0;
	int vNBCards=0;
	int vCardsCounter=0;
	vector <string > cardsList;
	string identifiant;
	bool isPlaying;
	int points;
	
	int vNBCardsQueue1=0;
	int vCardsCounterQ1=0;
	int vNBCardsQueue2=0;
	int vCardsCounterQ2=0;
	queue <string > queue1;
	queue <string > queue2;
	
	
	for (unsigned int i=0;i<vGame.size();i++)
	{
		if (i+1<vGame.size())
		if (carList[i]==':'&&carList[i+1]==':')
		{
			
			word=actualWord.str();
			

			
			//first , NB Players Value
			if (wordCounter==0)
			{
				vNBPLayers=atoi(word.c_str());
			}else
			{
				//Add of a player
				if (playerCounter<vNBPLayers)
				{
					
					//In first the name
					if (playerCounterElement==0)
					{
						
						identifiant=word;
					}
					if (playerCounterElement==1)
					{
						
						isPlaying=(word.compare("1")==0)?true:false;
					}
					if (playerCounterElement==2)
					{
						
						points=atoi(word.c_str());
					}
					if (playerCounterElement==3)
					{
						
						vNBCards=atoi(word.c_str());
					}
					if (playerCounterElement>=4&&vCardsCounter<vNBCards)
					{
						
						cardsList.push_back(word);
						vCardsCounter++; 
					}
					if (vCardsCounter==vNBCards&&playerCounterElement>=4)
					{
						
						datasplayer vPlay;
						vPlay.identifiant=identifiant;
						vPlay.points=points;
						vPlay.isPlaying=isPlaying;
						vPlay.cardsList=cardsList;
						dgame->playersList.push_back(vPlay	);
						playerCounter++;
						vCardsCounter=0;
						playerCounterElement=0;
						cardsList.clear();
						 
					}else{playerCounterElement++;}
					
					
				}
				else
				{//Saved queue
					
					if (vNBCardsQueue1==0)
					{
						vNBCardsQueue1=atoi(word.c_str());
						
					}else
					{
						if (vCardsCounterQ1<vNBCardsQueue1)
						{
							queue1.push(word);
							
							vCardsCounterQ1++;
						}else
						if (vNBCardsQueue2==0&&vCardsCounterQ1==vNBCardsQueue1)
						{
							vNBCardsQueue2=atoi(word.c_str());
							
							dgame->playedCards=queue1;
							
							
						}else
						if (vCardsCounterQ2<vNBCardsQueue2)
						{
							queue2.push(word);
							
							vCardsCounterQ2++;
						}
						if (vCardsCounterQ2==vNBCardsQueue2&&vCardsCounterQ2!=0)
						{
							
							dgame->piocheCards=queue2;
							
						}
						
					}
				}
			}
			
			
			wordCounter++;
			actualWord.str("");
			actualWord.clear();
			actualWord.flush();
			

			i++;
		}else {
			actualWord <<carList[i];
		}
	}
	return dgame;
	
}

void writeValue(string pName,string pValue)
{
	
	ofstream outFile(COOKIE_FILE_NAME, ios::out|ios::app);
	
	outFile << pName<<"::"<<pValue<<"\n";
	
	outFile.close();
	
}

void writeFileGame(string pName,string pValue)
{
	
	ifstream inFile;
	
	//Find Index of the game
	inFile.open(GAME_FILE_NAME,ios::in);
	if (!inFile) {
		ofstream outFile(GAME_FILE_NAME, ios::out|ios::app);
		

		outFile << "\n";
	
		outFile.close();
		inFile.open(GAME_FILE_NAME,ios::in);
	}
	///read of the file
	if (inFile) {
		stringstream buffer;
		bool haveWrited;
		haveWrited=false;
		while (inFile&&!inFile.eof ())
		{
			char ligne[32000];
			std::string s;
			inFile.getline (ligne, sizeof (ligne));
			s = ligne;
			
			if (s.find (pName)!= string::npos)
			{
				
				buffer << pValue<<"\n";
				
				haveWrited=true;
				
			}
			else
			{
				buffer << s <<"\n";
			}
			
		}
		inFile.close();
		ofstream outFile(GAME_FILE_NAME, ios::out|ios::trunc);
		

		outFile << buffer.str();
		if (!haveWrited)
		{
			outFile << pValue<<"\n";
		}
	
		outFile.close();
		
		
	}
	
	

}



void writeGame(datasplayer pPlayer,datasgame pGame)
{
	stringstream buffer;
	
	std::vector<datasplayer>::iterator itVectorData;
	buffer <<pGame.playersList.size()<<"::";
	for(itVectorData = pGame.playersList.begin(); itVectorData != pGame.playersList.end(); itVectorData++)
	{
		std::vector<string>::iterator itVectorData2;
		buffer <<itVectorData->identifiant<<"::"<<((itVectorData->isPlaying)?"1":"0")<<"::"<<itVectorData->points<<"::";
		//NBCards
		buffer <<itVectorData->cardsList.size()<<"::";
		for(itVectorData2 = itVectorData->cardsList.begin(); itVectorData2 != itVectorData->cardsList.end(); itVectorData2++)
		{
			buffer <<*itVectorData2<<"::";
		}
	}
	
	//NBCards played
	buffer <<pGame.playedCards.size()<<"::";
	while(!pGame.playedCards.empty())
	{
		buffer <<pGame.playedCards.front()<<"::";
		pGame.playedCards.pop();
	}
	
	
	//NBCards in queue
	buffer <<pGame.piocheCards.size()<<"::";
	while(!pGame.piocheCards.empty())
	{
		buffer <<pGame.piocheCards.front()<<"::";
		pGame.piocheCards.pop();
	}
	writeFileGame(pPlayer.identifiant,buffer.str());
	
}


string generateUnicCookie()
{
	
	srand ( time(NULL) );     
	int nb_aleatoire;     
	nb_aleatoire=(rand()%100)+1;    
	
	
	stringstream buffer;
	buffer << nb_aleatoire<<"_"<<time(NULL);

	string vNum=buffer.str() ;
	
	return vNum;
}

int countGame()
{
	ifstream inFile;
	inFile.open(GAME_FILE_NAME);
	if (!inFile) {
		return 0;
	}
	int vNBLigne=0;
	// Lecture ligne a ligne
	while (inFile&&!inFile.eof ())
	  {
	    vNBLigne++;
	  }
	  inFile.close();
	  return vNBLigne;

}


void gameRules(datasplayer *vPlayer)
{
	//search the player in a game
	datasgame *readedGame=getGame(vPlayer->identifiant);
	if (readedGame==NULL)
	{
		//It' isn't in game
		//Count the number of games
		if (countGame()>MAX_GAME)
		{
			cout <<"THE PLAY TABLES ARE FULL!"<<endl;
			return;
		}
		//Create a new Game for Four Player
		
	}
}

int 
main(int argc, 
     char **argv)
{
   try {
      Cgicc cgi;
      
       // Get the name and value of the cookie to set
       const_form_iterator name = cgi.getElement("name");
       const_form_iterator value = cgi.getElement("value");
	string staticSession="";
	
      //get a static session
	if (argc>1)
	{
		
		staticSession =argv[1];
		
	}

	
      // Send HTTP header
	   
      string vRet=getNUMCookie(HTTPHTMLHeader().getCookies());
	if (vRet.compare("")==0&&staticSession.compare("")!=0)
	{
		
		vRet=staticSession;
	}
	
	if (vRet.compare("")==0&&getValue(vRet).compare("")==0)
	{	
		vRet=generateUnicCookie();
		
		cout << HTTPHTMLHeader()
	.setCookie(HTTPCookie(COOKIE_NAME, vRet));
	}
    else
      cout << HTTPHTMLHeader();      // Set up the HTML document
    
      cout << html() << head(title("Cgicc CardGame example")) << endl;
      cout << body() << endl;
    //if the are a cookie in the stock we parse data
	if (getValue(vRet).compare("")!=0)
	{
		datasplayer *vPlayer=convertStringToStuct(getValue(vRet));
		cout <<"RRRRRRRRRRR\n"<<"ee="<<vPlayer->identifiant<<"//"<<vPlayer->cardsList.size()<<"\n";
	}else
	{
		datasplayer *vPlayer= new datasplayer;
		srand ( time(NULL) );     
		int nb_aleatoire;     
		
		stringstream buffer;
		buffer << "P"<<(rand()%1000)+1<<"_"<<(rand()%1000)+1;
		vPlayer->identifiant=buffer.str();
		
		//We write a new empty value
		writeValue(vRet,convertStructToString(vPlayer));
	}
     
      //Test Write Game
	
	datasplayer p1;
	datasplayer p2;
	datasplayer p3;
	datasplayer p4;
	p1.cardsList.push_back("1");
	p1.cardsList.push_back("5");
	p1.cardsList.push_back("8");
	p1.identifiant="P1";
	p1.isPlaying=true;
	p1.points=10;
	p2.cardsList.push_back("2");
	p2.cardsList.push_back("3");
	p2.cardsList.push_back("4");
	p2.cardsList.push_back("5");
	p2.identifiant="P2";
	p2.isPlaying=false;
	p2.points=11;
	
	p3.cardsList.push_back("6");
	p3.cardsList.push_back("7");
	p3.cardsList.push_back("8");
	p3.identifiant="P3";
	p3.isPlaying=false;
	p3.points=12;
	p4.cardsList.push_back("9");
	p4.cardsList.push_back("0");
	p4.cardsList.push_back("1");
	p4.cardsList.push_back("2");
	p4.identifiant="P4";
	p4.isPlaying=false;
	p4.points=13;
	datasgame myGame;
	myGame.playersList.push_back(p1);
	myGame.playersList.push_back(p2);
	myGame.playersList.push_back(p3);
	myGame.playersList.push_back(p4);
	myGame.playedCards.push("FFFE");
	myGame.playedCards.push("EE22");
	myGame.playedCards.push("1E23");
	myGame.piocheCards.push("FE23");
	myGame.piocheCards.push("GE23");
	
	writeGame(p1,myGame);
	
	datasgame *readedGame=getGame("P1");
	if (readedGame!=NULL)
	{
		cout <<"REEEE="<<readedGame->playersList.front().identifiant<<"\n";
		cout <<"REEEE="<<readedGame->playersList.front().isPlaying<<"\n";
		cout <<"REEEE="<<readedGame->playersList.front().points<<"\n";
		//cout <<"REEEE="<<readedGame->playersList.front().cardsList.front()<<"\n";
	}
      // Close the HTML document
      cout << body() << html();
	
   }
   catch(exception& e) {
      // handle any errors - omitted for brevity
   }
}


