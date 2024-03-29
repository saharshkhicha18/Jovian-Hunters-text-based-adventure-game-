#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "Jovian.h"
using namespace std;

//when monster is encountered
void war( int &charhp, int &charap, vector<string>& inventory_p, vector<int>& inventory_pvalue , vector<string>& monsternames, vector<int> &monster_hp,
vector<int> &monster_ap){ 
  int choosein; int damage = 0;
  srand(time(0)); //random monsters
  int randommonster = rand() % (monsternames.size()-1); 
  int foehp = monster_hp[randommonster];
  int foeap = monster_ap[randommonster];
  while (charhp > 0 && foehp > 0) //loops untill one of the character or monster dies
  {
    //monster attacks

    cout << monsternames[randommonster] << " is attacking you!!! " << " watch out!! " << endl;
    sleep(2);
    charhp -= foeap;
    if (charhp <=0) //if player dies
    {
      cout << endl;
      cout << "Those were some mad skills from " << monsternames[randommonster] << "!!" << endl;
      cout << "He got you this time!" << endl;
      cout << "Acquiring Kohinoor has never been easy!" << endl;
      cout << "Better luck next time!" << endl;
      break;
    }
    else 
    {
      cout << endl;
      cout << "Now its your time to take revenge!" <<endl;
      cout << "Your hp is " << charhp << endl;
      cout << "Its your chance to redeem youself!" << endl;
      sleep(2);
      cout << endl;
    }


    //player's turn
    if (inventory_p.size() == 0) //if player does not have any weapons
    {
      cout << "Your inventory is empty" << endl;
      cout << "You got only hands left;)" << endl;
      cout << "Input 0 to punch! -> ";
    }
    else
    {
      int i = 0;
      for(int index = 0; index < inventory_p.size(); index++)
      {
        cout << i+1 << ") " << "You have " << inventory_p[i] << " with damage of " << inventory_pvalue[i] << "." << endl;
        i++;
      }
      cout << "Choose one option number from above?" << endl; 
      cout << endl;
      for (int count = 1; count <= i; count++){
         cout << "Input " << count <<  " to pick the " << inventory_p[count-1] <<endl;
      }
      cout << "Input 0 if you do not want to use any weapon -> " <<endl; 
    }
    //choosing from the inventory
    cin >> choosein;
    while (choosein > inventory_p.size()) //notifies invalid input
    {
      cout << "Invalid input!" << endl;
      cout << "You got only hands left;)" << endl;
      cout << "Input 0 to punch! -> ";
      cin >> choosein;
    }
    if (choosein == 0) //if player does not want to use any weapons from inventory
    {
      cout << "You attack the monster with your hands" << endl;
      damage = charap;
      foehp -= damage;
      if (foehp <= 0) //check if monster died
      {
        cout << endl;
        sleep(2);
        cout << "Wooohooo! You killed " << monsternames[randommonster] << endl;
        cout << "Your skills are impeccable " << endl;
        monsternames.erase (monsternames.begin()+randommonster);
        monster_hp.erase (monster_hp.begin()+randommonster);
        monster_ap.erase (monster_ap.begin()+randommonster);
        break; //if monster dies break the loop
      }
      else
      {
        cout << monsternames[randommonster] << " is still alive. You might have to push harder!" << endl;
        cout << endl;
      }
    }
    if (choosein == 1 || choosein == 2 || choosein == 3) //if player wants to use a weapon from inventory
    {
      cout << "You are attacking the "<< monsternames[randommonster] << " with a " << inventory_p[choosein-1] << endl;
      damage = inventory_pvalue[choosein-1];
      foehp -= damage;
      inventory_p.erase (inventory_p.begin()+(choosein-1)); //erases the weapon once used
      inventory_pvalue.erase (inventory_pvalue.begin()+(choosein-1)); //erases its corresponding damage value
      if (foehp <= 0) //checking if the monster died
      {
        cout << endl;
        sleep(2);
        cout << "Wooohooo! You killed " << monsternames[randommonster] << endl;
        cout << "Your skills are impeccable " << endl;
        monsternames.erase (monsternames.begin()+randommonster);
        monster_hp.erase (monster_hp.begin()+randommonster);
        monster_ap.erase (monster_ap.begin()+randommonster);
        break;
      }
      else
      {
        cout << monsternames[randommonster] << " is still alive. You might have to push harder!" << endl;
        cout << endl;
      }
    }
    }
  }
