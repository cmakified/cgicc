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
	vector <string > *cardsList;
	string identifiant;
	bool isPlaying;
	int points;
	string actualCard;
};

struct datasgame
{
	vector <datasplayer *> *playersList;
	
	vector<string> *playedCards;
	vector<string> *piocheCards;

};
	
string convertStructToString( datasplayer *pPlayer)
{
	
	std::vector<string>::iterator itVectorData;
	stringstream buffer;
	buffer <<pPlayer->identifiant<<"::";
	for(itVectorData = pPlayer->cardsList->begin(); itVectorData != pPlayer->cardsList->end(); itVectorData++)
	{
	
		buffer << *itVectorData;
		if (itVectorData != pPlayer->cardsList->end())
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
				datas->cardsList->push_back(word);
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
	{
		
		return "";
	}
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
	dgame->playersList=new vector<datasplayer*>;
	
	
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
	vector <string > *cardsList= new vector<string>;
	string identifiant;
	string actualCard;
	bool isPlaying;
	int points;
	
	int vNBCardsQueue1=0;
	int vCardsCounterQ1=0;
	int vNBCardsQueue2=0;
	int vCardsCounterQ2=0;
	bool vCountedCardsQ1;
	bool vCountedCardsQ2;
	vCountedCardsQ1=false;
	vCountedCardsQ2=false;
	vector <string > *queue1= new vector<string>;
	dgame->playedCards=queue1;

	vector <string > *queue2= new vector<string>;
	dgame->piocheCards=queue2;	
	
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
						
						actualCard=word;
					}
					if (playerCounterElement==4)
					{
						
						vNBCards=atoi(word.c_str());
					}
					if (playerCounterElement>=5&&vCardsCounter<vNBCards)
					{
						
						cardsList->push_back(word);
						vCardsCounter++; 
					}
					if (vCardsCounter==vNBCards&&playerCounterElement>=5)
					{
						
						datasplayer *vPlay= new datasplayer;
						
						vPlay->identifiant=identifiant;
						vPlay->points=points;
						vPlay->isPlaying=isPlaying;
						vPlay->cardsList=cardsList;
						vPlay->actualCard=actualCard;
						dgame->playersList->push_back(vPlay	);
						playerCounter++;
						vCardsCounter=0;
						playerCounterElement=0;
						
						cardsList=new vector <string >;
						
						 
					}else{playerCounterElement++;	}
					
					
				}
				else
				{//Saved queue
					
					if (vNBCardsQueue1==0&&!vCountedCardsQ1)
					{	
						vNBCardsQueue1=atoi(word.c_str());
						vCountedCardsQ1=true;
	
						
					}else
					{
						
						if (vCardsCounterQ1<vNBCardsQueue1)
						{
							
							queue1->push_back(word);
							
							vCardsCounterQ1++;
						}else
						if (!vCountedCardsQ2&&vNBCardsQueue2==0&&vCardsCounterQ1==vNBCardsQueue1)
						{
							
							vNBCardsQueue2=atoi(word.c_str());
							vCountedCardsQ2=true;
							//dgame->playedCards=queue1;
							
							
						}else
						if (vCardsCounterQ2<vNBCardsQueue2)
						{
							
							queue2->push_back(word);
							
							vCardsCounterQ2++;
						}
						if (vCardsCounterQ2==vNBCardsQueue2&&vCardsCounterQ2!=0)
						{
							
							//dgame->piocheCards=queue2;
							
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



void writeGame(datasplayer *pPlayer,datasgame *pGame)
{
	
	stringstream buffer;
	
	datasplayer * itVectorData;
	buffer <<pGame->playersList->size()<<"::";
	for(int i=0;i<pGame->playersList->size(); i++)
	{
	
		itVectorData=pGame->playersList->at(i);
		
		
		std::vector<string>::iterator itVectorData2;
		buffer <<itVectorData->identifiant<<"::"<<((itVectorData->isPlaying)?"1":"0")<<"::"<<itVectorData->points<<"::"<<itVectorData->actualCard<<"::";
		//NBCards
		buffer <<itVectorData->cardsList->size()<<"::";
		for(itVectorData2 = itVectorData->cardsList->begin(); itVectorData2 != itVectorData->cardsList->end(); itVectorData2++)
		{
			buffer <<*itVectorData2<<"::";
	
		}
		
	}
	
	//NBCards played
	buffer <<pGame->playedCards->size()<<"::";
	for (int i=0;i<pGame->playedCards->size();i++)
	{
		buffer <<pGame->playedCards->at(i)<<"::";
		
	}
	
	
	
	//NBCards in queue
	
	buffer <<pGame->piocheCards->size()<<"::";
	
	for (int i=0;i<pGame->piocheCards->size();i++)
	{
		buffer <<pGame->piocheCards->at(i)<<"::";
		
		
	}
	
	
	
	writeFileGame(pPlayer->identifiant,buffer.str());
	
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
	
	  	string tempo;
	  	inFile >> tempo;
	  	
	    vNBLigne++;
	  }
	
	  inFile.close();
	  
	
	  return vNBLigne;

}

vector<string> *loadAndMixCards()
{
	vector<string> UnorderedPioche;
	UnorderedPioche.push_back("TA");
	UnorderedPioche.push_back("TZ");
	UnorderedPioche.push_back("T2");
	UnorderedPioche.push_back("T3");
	UnorderedPioche.push_back("T4");
	UnorderedPioche.push_back("T5");
	UnorderedPioche.push_back("T6");
	UnorderedPioche.push_back("T7");
	UnorderedPioche.push_back("T8");
	UnorderedPioche.push_back("T9");
	UnorderedPioche.push_back("TD");
	UnorderedPioche.push_back("TR");
	UnorderedPioche.push_back("TB");
	UnorderedPioche.push_back("CA");
	UnorderedPioche.push_back("CZ");
	UnorderedPioche.push_back("C2");
	UnorderedPioche.push_back("C3");
	UnorderedPioche.push_back("C4");
	UnorderedPioche.push_back("C5");
	UnorderedPioche.push_back("C6");
	UnorderedPioche.push_back("C7");
	UnorderedPioche.push_back("C8");
	UnorderedPioche.push_back("C9");
	UnorderedPioche.push_back("CD");
	UnorderedPioche.push_back("CR");
	UnorderedPioche.push_back("CB");
	UnorderedPioche.push_back("PA");
	UnorderedPioche.push_back("PZ");
	UnorderedPioche.push_back("P2");
	UnorderedPioche.push_back("P3");
	UnorderedPioche.push_back("P4");
	UnorderedPioche.push_back("P5");
	UnorderedPioche.push_back("P6");
	UnorderedPioche.push_back("P7");
	UnorderedPioche.push_back("P8");
	UnorderedPioche.push_back("P9");
	UnorderedPioche.push_back("PD");
	UnorderedPioche.push_back("PR");
	UnorderedPioche.push_back("PB");
	UnorderedPioche.push_back("HA");
	UnorderedPioche.push_back("HZ");
	UnorderedPioche.push_back("H2");
	UnorderedPioche.push_back("H3");
	UnorderedPioche.push_back("H4");
	UnorderedPioche.push_back("H5");
	UnorderedPioche.push_back("H6");
	UnorderedPioche.push_back("H7");
	UnorderedPioche.push_back("H8");
	UnorderedPioche.push_back("H9");
	UnorderedPioche.push_back("HD");
	UnorderedPioche.push_back("HR");
	UnorderedPioche.push_back("HB");
	srand ( time(NULL) );
	int nb_aleatoire;
	
	vector<string> *vRet= new vector<string>;
	while(UnorderedPioche.size()>0)
	{
		
		nb_aleatoire=(rand()%UnorderedPioche.size()); 
		vRet->push_back(UnorderedPioche[nb_aleatoire]);
		UnorderedPioche.erase((UnorderedPioche.begin())+nb_aleatoire);
	}
	return vRet;
	
}

int calculateCard(string pCard)
{
	
	if (pCard.compare("TA")==0) return 10;
	if (pCard.compare("TZ")==0) return 14;
	if (pCard.compare("T2")==0) return 2;
	if (pCard.compare("T3")==0) return 3;
	if (pCard.compare("T4")==0) return 4;
	if (pCard.compare("T5")==0) return 5;
	if (pCard.compare("T6")==0) return 6;
	if (pCard.compare("T7")==0) return 7;
	if (pCard.compare("T8")==0) return 8;
	if (pCard.compare("T9")==0) return 9;
	if (pCard.compare("TD")==0) return 12;
	if (pCard.compare("TR")==0) return 13;
	if (pCard.compare("TB")==0) return 11;
	if (pCard.compare("CA")==0) return 10;
	if (pCard.compare("CZ")==0) return 14;
	if (pCard.compare("C2")==0) return 2;
	if (pCard.compare("C3")==0) return 3;
	if (pCard.compare("C4")==0) return 4;
	if (pCard.compare("C5")==0) return 5;
	if (pCard.compare("C6")==0) return 6;
	if (pCard.compare("C7")==0) return 7;
	if (pCard.compare("C8")==0) return 8;
	if (pCard.compare("C9")==0) return 9;
	if (pCard.compare("CD")==0) return 12;
	if (pCard.compare("CR")==0) return 13;
	if (pCard.compare("CB")==0) return 11;
	if (pCard.compare("PA")==0) return 10;
	if (pCard.compare("PZ")==0) return 14;
	if (pCard.compare("P2")==0) return 2;
	if (pCard.compare("P3")==0) return 3;
	if (pCard.compare("P4")==0) return 4;
	if (pCard.compare("P5")==0) return 5;
	if (pCard.compare("P6")==0) return 6;
	if (pCard.compare("P7")==0) return 7;
	if (pCard.compare("P8")==0) return 8;
	if (pCard.compare("P9")==0) return 9;
	if (pCard.compare("PD")==0) return 12;
	if (pCard.compare("PR")==0) return 13;
	if (pCard.compare("PB")==0) return 11;
	if (pCard.compare("HA")==0) return 10;
	if (pCard.compare("HZ")==0) return 14;
	if (pCard.compare("H2")==0) return 2;
	if (pCard.compare("H3")==0) return 3;
	if (pCard.compare("H4")==0) return 4;
	if (pCard.compare("H5")==0) return 5;
	if (pCard.compare("H6")==0) return 6;
	if (pCard.compare("H7")==0) return 7;
	if (pCard.compare("H8")==0) return 8;
	if (pCard.compare("H9")==0) return 9;
	if (pCard.compare("HD")==0) return 12;
	if (pCard.compare("HR")==0) return 13;
	if (pCard.compare("HB")==0) return 11;
	return 0;
	
}

datasgame * createGame(datasplayer *vPlayer)
{
	
	datasplayer *p1=new datasplayer;
	datasplayer *p2=new datasplayer;
	datasplayer *p3=new datasplayer;
	datasplayer *p4=new datasplayer;
	p1->identifiant=vPlayer->identifiant;
	p1->actualCard="";
	p1->isPlaying=true;
	p1->points=0;
	p2->identifiant="FREE1";
	p2->actualCard="";
	p2->isPlaying=false;
	p2->points=0;
	p3->identifiant="FREE2";
	p3->actualCard="";
	p3->isPlaying=false;
	p3->points=0;
	p4->identifiant="FREE3";
	p4->actualCard="";
	p4->isPlaying=false;
	p4->points=0;
	
	datasgame *myGame= new datasgame;
	myGame->playersList=new vector <datasplayer *>;
	myGame->playersList->push_back(p1);
	myGame->playersList->push_back(p2);
	myGame->playersList->push_back(p3);
	myGame->playersList->push_back(p4);
	myGame->playedCards=new vector<string>;
	
	myGame->piocheCards=loadAndMixCards();
	
	int vNbCards=myGame->piocheCards->size();
	//distribution des cartes
	for (int i=0;i<myGame->playersList->size();i++)
	{
		
		myGame->playersList->at(i)->cardsList=new vector<string>;
		for (int j=0;j<vNbCards/myGame->playersList->size();j++)
		{
		
			myGame->playersList->at(i)->cardsList->push_back(myGame->piocheCards->front());
			myGame->piocheCards->erase(myGame->piocheCards->begin());
		}
	
	}
	
	
	writeGame(p1,myGame);
	return myGame;
}

void drawCards(vector <string> *cardList)
{
	
	
	for (int i=0;i<cardList->size();i++)
	{
		cout <<"<div style=\"position:absolute;top:50;left:"<<i*150+150<<"\" >"; 
		cout <<"<img border=\"0\" width=\"100\" src=\"images/"<<cardList->at(i)<<".png\" alt=\"Carte ["<<i<<"]="<<cardList->at(i)<<"\" />"<<endl;
		cout <<"</div>";
	}
	cout <<"<br />";
}

void drawInfos(datasplayer *vPlayer)
{
	cout <<"<div style=\"position:absolute;width:140;top:50;left:"<<0<<"\" >"; 
	cout <<"The latest Played Cards ";
	cout <<"</div>";
	cout <<"<div style=\"width:140;position:absolute;top:180;left:"<<0<<"\" >"; 
	cout <<"Actual Cards in the Game<br>You are the player :"<<vPlayer->identifiant;
	cout <<"</div>";
	cout <<"<div style=\"width:140;position:absolute;top:375;left:"<<0<<"\" >"; 
	cout <<"Your Cards, you can choose one card.";
	cout <<"</div>";
}	

void drawPlayers(datasgame *pGame)
{
	
	bool vFirst=false;
	for (int i=0;i<pGame->playersList->size();i++)
	{
		bool afficheFirst=false;
		if (vFirst==false&&pGame->playersList->at(i)->actualCard.compare("")!=0)
		{
			vFirst=true;
			afficheFirst=true;
		}
		cout <<"<div style=\"outline-color:"<<((afficheFirst==false)?"black":"red")<<";outline-style:solid;outline-width:"<<((afficheFirst==false)?"1":"2")<<"px;position:absolute;top:180;left:"<<i*200+150<<"\" >"; 
		cout <<"Name :"<<pGame->playersList->at(i)->identifiant<<"<br>";
		cout <<"Score :"<<pGame->playersList->at(i)->points<<"<br>";
		
		cout <<"<img border=\"0\" width=\"100\" src=\"images/"<<pGame->playersList->at(i)->actualCard<<".png\" alt=\" \" />"<<endl;
		if  (afficheFirst==true)
		{	
			cout <<"<br>The color to play";
		}
		cout <<"</div>";
	}
	cout <<"<br />";
}

void drawCardInPlay(datasgame *pGame)
{
	
	
	for (int i=0;i<pGame->playedCards->size();i++)
	{
		cout <<"<div style=\"position:absolute;top:100;left:"<<i*110<<"\" >"; 
		cout <<"<img border=\"0\" width=\"100\" src=\"images/"<<pGame->playedCards->at(i)<<".png\" alt=\"Carte ["<<i<<"]="<<pGame->playedCards->at(i)<<"\" />"<<endl;
		cout <<"</div>";
	}
	cout <<"<br />";
}
void drawPlayerCards(datasplayer *vPlayer)
{
	sort (vPlayer->cardsList->begin(),vPlayer->cardsList->end());
	cout <<"<form name=\"cards\">"; 
	cout <<"<input type=\"hidden\" name=\"actionner\" value=\"\">"; 
	cout <<"<input type=\"hidden\" name=\"card\" value=\"\">"; 
	//affiche les cartes du joueurs
	for (int i=0;i<vPlayer->cardsList->size();i++)
	{
		cout <<"<div style=\"position:absolute;top:375;left:"<<i*20+150<<"\" >"; 
		if (vPlayer->isPlaying==true)
		{
			cout <<"<a  href=\"javascript:document.forms.cards.actionner.value='playcard';document.forms.cards.card.value='"<<vPlayer->cardsList->at(i)<<"';document.forms.cards.submit();\">"; 
		}
		cout <<"<img border=\"0\" width=\"100\" src=\"images/"<<vPlayer->cardsList->at(i)<<".png\" alt=\"Carte ["<<i<<"]="<<vPlayer->cardsList->at(i)<<"\" />"<<endl;
		if (vPlayer->isPlaying)
		{
			cout <<"</a>";
		}
		cout <<"</div>";
	}
	cout <<"</form>"; 
}
void playACard(datasplayer *vPlayer,datasgame *readedGame,string *card)
{
	
	
	for (int i=0;i<readedGame->playersList->size();i++)
	{
	
		
		if (readedGame->playersList->at(i)->identifiant.compare(vPlayer->identifiant)==0)
		{
			
			//vPlayer->
			
			for (int j=0;j<readedGame->playersList->at(i)->cardsList->size();j++)
			{
				
							
				if(readedGame->playersList->at(i)->cardsList->at(j).compare(*card)==0)
				{
					if (readedGame->piocheCards==NULL)
					{
						readedGame->piocheCards=new vector<string>;
					}
					//string carde=*card;
					//readedGame->piocheCards->push(carde);
					readedGame->playedCards->push_back(*card);
					readedGame->playersList->at(i)->actualCard=*card;
					readedGame->playersList->at(i)->cardsList->erase(readedGame->playersList->at(i)->cardsList->begin()+j);
					
					break;
					
				}
			}
			
			break;
		}
	}
	
}

void turnPlayers(datasplayer *vPlayer,datasgame *readedGame)
{
	int IdTurn=0;
	vPlayer->isPlaying=false;
	//Find the player
	for (int i=0;i<readedGame->playersList->size();i++)
	{
		
		if (readedGame->playersList->at(i)->identifiant.compare(vPlayer->identifiant)==0)
		{
			readedGame->playersList->at(i)->isPlaying=false;
			IdTurn=i;	
			break;
		}
	}
	IdTurn++;
	if (IdTurn==readedGame->playersList->size())
	{
		IdTurn=0;
	}
	
	readedGame->playersList->at(IdTurn)->isPlaying=true;
	
}

bool testCard(datasplayer *vPlayer,datasgame *readedGame,string *card)
{

	//If first Card in the Bloxk
	if (readedGame->playedCards->size()==0)
	{
		return true;
	}
	//take the color of the first Card
	string color=readedGame->playedCards->front().substr(0,1);
	//Test if it's the same color
	if (color.compare(card->substr(0,1))==0)
	{
		return true;
	}
	
	//Test if the player has a good colored card in his game
	vPlayer->isPlaying=false;
	//Find the player
	for (int i=0;i<readedGame->playersList->size();i++)
	{
		
		if (readedGame->playersList->at(i)->identifiant.compare(vPlayer->identifiant)==0)
		{
			
			for (int j=0;j<readedGame->playersList->at(i)->cardsList->size();j++)
			{
				if (color.compare(readedGame->playersList->at(i)->cardsList->at(j).substr(0,1))==0)
					return false;
			}
			return true;
			
		}
	}
	
	return true;
	
}

void IAPlay(datasgame *readedGame,int pId)
{
	//If first Card in the Block
	if (readedGame->playedCards->size()==0)
	{
		playACard(readedGame->playersList->at(pId),readedGame,&readedGame->playersList->at(pId)->cardsList->front());
		turnPlayers(readedGame->playersList->at(pId),readedGame);
		return ;
	}
	//If not take the color of the first Card
	string color=readedGame->playedCards->front().substr(0,1);
	
	sort(readedGame->playersList->at(pId)->cardsList->begin(),readedGame->playersList->at(pId)->cardsList->end());

	//color Finded
	bool vColorOk=false;
	int vId=0;
	for (int i=0;i<readedGame->playersList->at(pId)->cardsList->size();i++)
	{	
		int actualColor=color.compare(readedGame->playersList->at(pId)->cardsList->at(i).substr(0,1));
		
		
		//If the next color is not the same the card is the max
		if (actualColor==0&&vColorOk==true)
		{
			
			vId=i;
		}
		if (actualColor!=0&&vColorOk==true)
		{
			
			break;
		}
		
		//If Color Finded
		if (actualColor==0&&vColorOk==false)
		{
			
			vColorOk=true;
			vId=i;
		}
	}
	
	playACard(readedGame->playersList->at(pId),readedGame,&readedGame->playersList->at(pId)->cardsList->at(vId));
	turnPlayers(readedGame->playersList->at(pId),readedGame);
}

void gameRules(datasplayer *vPlayer, string *action, string * card)
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
		readedGame=createGame(vPlayer);
	
	}
	int thePlayer=0;
	//Find the player
	for (int i=0;i<readedGame->playersList->size();i++)
	{
		
		if (readedGame->playersList->at(i)->identifiant.compare(vPlayer->identifiant)==0)
		{
			//vPlayer->
			vPlayer->cardsList=readedGame->playersList->at(i)->cardsList;
			vPlayer->isPlaying=readedGame->playersList->at(i)->isPlaying;
			vPlayer->points=readedGame->playersList->at(i)->points;
			thePlayer=i;
			break;
		
		}
	}
	

	//Gestion des actions de l'utilisateur
	int vResComp=action->compare("playcard");
	
	if ( vResComp==0 && vPlayer->isPlaying==true)
	{
		if (testCard(vPlayer,readedGame,card)==true)
		{
			playACard(vPlayer,readedGame,card);
			turnPlayers(vPlayer,readedGame);
			writeGame(vPlayer,readedGame);
		}
		else
		{
			cout <<"<div style=\"position:absolute;top:50;left:"<<150<<"\" >"; 
			cout <<"<b>You can not Play this card!</b><br>\n";
			cout <<"</div>"; 
		}
		
	}
	//Tant que l'utilisateur n'a pas encore le droit de jouer on fait tourner l'IA
	int vNbTurns=0;
	while (vNbTurns<=readedGame->playersList->size()+1&&readedGame->playersList->at(thePlayer)->isPlaying==false)
	{	
		vNbTurns++;
		for (int i=0;i<readedGame->playersList->size();i++)
		{
			if (readedGame->playersList->size()<=readedGame->playedCards->size())
			{
				break;
			}
			if (i==thePlayer)
			{
				if (readedGame->playersList->at(thePlayer)->isPlaying==true)
				
				break;
			}	
			else
			{
				if (readedGame->playersList->at(i)->isPlaying==true)
				{
					IAPlay(readedGame,i);
				}
			}
		}
		
	}
	
	vector <string> *lastPlayedCard= new vector<string>;
	//A end is finish??
	if (readedGame->playersList->size()<=readedGame->playedCards->size())
	{
		//Find the winner
		//The Winner is
		int vWiner=0;
		int theMax=0;
		int total=0;
		for(int i=0;i<readedGame->playersList->size();i++)
		{
			string plCard=readedGame->playersList->at(i)->actualCard;
			readedGame->playersList->at(i)->isPlaying=false;
			int cardValue=calculateCard(plCard);
			readedGame->playersList->at(i)->actualCard="";
			int compCard=plCard.substr(0,1).compare(readedGame->playedCards->front().substr(0,1));
			
			
			if (theMax<cardValue&&compCard==0)
			{
				theMax=cardValue;
				vWiner=i;

			}
			
			if (compCard==0)
			{
				total+=cardValue;
			}
		}
		
		readedGame->playersList->at(vWiner)->isPlaying=true;
		readedGame->playersList->at(vWiner)->points+=total;

		//clear and add In Pioche
		
		while (!readedGame->playedCards->empty())
		{
			readedGame->piocheCards->push_back(readedGame->playedCards->front());
			lastPlayedCard->push_back(readedGame->playedCards->front());
			readedGame->playedCards->erase(readedGame->playedCards->begin());
		}
	}
	if (readedGame->playersList->at(thePlayer)->isPlaying==true)
	{
		vPlayer->isPlaying=true;
	}
	//Tant que l'utilisateur n'a pas encore le droit de jouer on fait tourner l'IA
	vNbTurns=0;

	while (readedGame->playersList->at(thePlayer)->isPlaying==false)
	{	
		vNbTurns++;
		for (int i=0;i<readedGame->playersList->size();i++)
		{
			if (i==thePlayer)
			{
				if (readedGame->playersList->at(thePlayer)->isPlaying==true)
				
				break;
			}	
			else
			{
				if (readedGame->playersList->at(i)->isPlaying==true)
				{
					IAPlay(readedGame,i);
				}
			}
		}
		
	}

	if (readedGame->playersList->at(thePlayer)->isPlaying==true)
	{
		vPlayer->isPlaying=true;
	}
	try{
	writeGame(vPlayer,readedGame);
	drawCards(lastPlayedCard);
	drawPlayers(readedGame);
	//drawCardInPlay(readedGame);
	drawPlayerCards(vPlayer);
	drawInfos(vPlayer);
	}
	catch(std::exception &error)
	{
		cout <<"Erreur:"<<error.what()<<"<br>\n";
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
       
       const_form_iterator actionIn = cgi.getElement("actionner");
       const_form_iterator playedCard = cgi.getElement("card");
       string action;
       string card;
        
       
       if (actionIn!= cgi.getElements().end() &&actionIn->getValue().empty() == false)
       {
       		action=actionIn->getValue();
       		
       }
       if (playedCard!= cgi.getElements().end() &&playedCard->getValue().empty() == false)
       {
       		card=playedCard->getValue();
       		
       }
	string staticSession="";
	
      //get a static session
	if (argc>1)
	{
		
		staticSession =argv[1];
		
	}

	
      // Send HTTP header
	   
      string vRet=getNUMCookie(cgi.getEnvironment().getCookieList());
      
      
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
      
      cout <<"<H1>Card Game</H1>";
    //if the are a cookie in the stock we parse data
    	datasplayer *vPlayer;
	if (getValue(vRet).compare("")!=0)
	{
	
		vPlayer=convertStringToStuct(getValue(vRet));
		
	}else
	{
		
		vPlayer= new datasplayer;
		srand ( time(NULL) );     
		int nb_aleatoire;     
		
		stringstream buffer;
		buffer << "P"<<(rand()%1000)+1<<"_"<<(rand()%1000)+1;
		vPlayer->identifiant=buffer.str();
		
		//We write a new empty value
		
		writeValue(vRet,convertStructToString(vPlayer));
		
	}
     	
     	gameRules(vPlayer,&action,&card);
      //Test Write Game
	/*
	datasplayer *p1= new datasplayer;
	datasplayer *p2=new datasplayer;
	datasplayer *p3=new datasplayer;
	datasplayer *p4=new datasplayer;
	p1->cardsList= new vector<string>;
	p1->cardsList->push_back("1");
	p1->cardsList->push_back("5");
	p1->cardsList->push_back("8");
	p1->identifiant="P1";
	p1->isPlaying=true;
	p1->points=10;
	p2->cardsList= new vector<string>;
	p2->cardsList->push_back("2");
	p2->cardsList->push_back("3");
	p2->cardsList->push_back("4");
	p2->cardsList->push_back("5");
	p2->identifiant="P2";
	p2->isPlaying=false;
	p2->points=11;
	p3->cardsList= new vector<string>;
	p3->cardsList->push_back("6");
	p3->cardsList->push_back("7");
	p3->cardsList->push_back("8");
	
	p3->identifiant="P3";
	p3->isPlaying=false;
	p3->points=12;
	p4->cardsList= new vector<string>;
	p4->cardsList->push_back("9");
	p4->cardsList->push_back("0");
	p4->cardsList->push_back("1");
	p4->cardsList->push_back("2");
	p4->identifiant="P4";
	p4->isPlaying=false;
	p4->points=13;
	
	datasgame myGame;
	
	myGame.playersList=new vector <datasplayer *>;
	myGame.playersList->push_back(p1);
	myGame.playersList->push_back(p2);
	myGame.playersList->push_back(p3);
	myGame.playersList->push_back(p4);
	
	myGame.playedCards= new queue<string>;
	myGame.playedCards->push("FFFE");
	myGame.playedCards->push("EE22");
	myGame.playedCards->push("1E23");
	
	myGame.piocheCards= new queue<string>;
	myGame.piocheCards->push("FE23");
	myGame.piocheCards->push("GE23");
	
	writeGame(*p1,&myGame);
	
	datasgame *readedGame=getGame("P1");
	if (readedGame!=NULL)
	{
		cout <<"REEEE="<<readedGame->playersList->front()->identifiant<<"\n";
		cout <<"REEEE="<<readedGame->playersList->front()->isPlaying<<"\n";
		cout <<"REEEE="<<readedGame->playersList->front()->points<<"\n";
		//cout <<"REEEE="<<readedGame->playersList.front().cardsList.front()<<"\n";
	}
	
	queue<string> *MyList=loadAndMixCards();
	while(MyList->size()>0)
	{
		cout <<"ER="<<MyList->front()<<endl;
		MyList->pop();
	}*/
      // Close the HTML document
      cout << body() << html();
	
   }
   catch(exception& e) {
      // handle any errors - omitted for brevity
   }
}


