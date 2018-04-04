#include<iostream>
#include<unordered_map>
#include<map>
#include<tuple>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<utility>
#include<iomanip>
using namespace std;

//tuples from data2.txt
class SpellClass
{
public:
      private:
      
            SpellClass();
            string  name;
            string  sClass;
            string  lvl;
      public:
            SpellClass(string n, string c, string l)
            {
                  name   = n;
                  sClass = c;
                  lvl    = l;
            }
            string getName()  { return name;   }
            string getClass() { return sClass; }
            string getLvl()   { return lvl;    }
            SpellClass* getThis() { return this; }
            void printName()
            {
                  cout << "\n\tName:" << name;
                  cout << "\tClass:" << sClass;
                  cout << "\tLvl: " << lvl;
            }


};
//for spell name index
//-------------------------------------------------------
class SpellClassName
{
      private:
                  SpellClassName();
                  string name;
                  SpellClass* spellClassObject;
      public:
                  SpellClassName(string n, SpellClass* s)
                  {
                        name = n;
                        spellClassObject = s;
                  }
                  string getName()     { return name; }
                  SpellClass* getObj() { return spellClassObject; }
                  SpellClassName* getThis() { return this; }
                  

};
//for spell class index
//-------------------------------------------------------
class SpellClassClass
{
      private:
                  SpellClassClass();
                  string sClass;
                  SpellClass* spellClassObject;
      public:
            SpellClassClass(string c, SpellClass* s)
            {
                  sClass = c;
                  spellClassObject = s;
            }
            SpellClassClass* getThis() { return this; }
            string getClass() { return sClass; }
            SpellClass* getObj() { return spellClassObject; }
};
//for spell lvl index
//-------------------------------------------------------
class SpellClassLvl
{
      private:
                  SpellClassLvl();
                  string lvl;
                  SpellClass* spellClassObject;
      public:
            SpellClassLvl(string l, SpellClass* s)
            {
                  lvl = l;
                  spellClassObject = s;
            }
            SpellClassLvl* getThis() { return this; }
            string getLvl() { return lvl; }
            SpellClass* getObj() { return spellClassObject; }
};
//tuples from data3.txt
//-------------------------------------------------------
class SpellType
{
      private:
            SpellType();
            SpellType(string s, string t)
            {
                  name = s;
                  type   = t;
            }
            string name;
            string type;
      public:
            string getClass() { return name; }
            string getType()  { return type; }
            void print()
            {
                  cout << "\n\tSpell Name: " << name;
                  cout << "\tType Name:" << type;
            }
};
//for spellType name index
//-------------------------------------------------------
class SpellTypeName
{
      private:
            SpellTypeName();
            string name;
            SpellType* spellTypeObject;
      public:
            SpellTypeName(string n, SpellType* s)
            {
                  name = n;
                  spellTypeObject = s;
            }
            string getName()    { return name; }
            SpellType* getObj() { return spellTypeObject; }

            
};
//for spellType type index
//-------------------------------------------------------
class SpellTypeType
{
      private:
            SpellTypeType();
            string type;
            SpellType* spellTypeObject;
      public:
            SpellTypeType(string t, SpellType* s)
            {
                  type = t;
                  spellTypeObject = s;
            }
            string getType() { return type; }
            SpellType* getObj() { return spellTypeObject; }
};
//tuples from data1.txt
//-------------------------------------------------------
class Player
{
      private:
            Player();
            string plName;
            string plClass;
            string plMaxLvl;
      public:
            Player(string n, string c, string m)
            {
                  plName   = n;
                  plClass  = c;
                  plMaxLvl = m;
            }
            string getName()   { return plName;   }
            string getClass()  { return plClass;  }
            string getMaxLvl() { return plMaxLvl; }
            void printName()
            {
                  cout << "\n\tPlayer Name:" << plName;
                  cout << "\tPlayer Class:" << plClass;
                  cout << "\tPlayer MaxLvl: " << plMaxLvl;
            }
};
//for Player name index
//-------------------------------------------------------

class PlayerName
{
      private:
            PlayerName();
            string name;
            Player* playerObject;
      public:
            PlayerName(string s, Player* p)
            {
                  name = s;
                  playerObject = p;
            }
            string getName() { return name; }
            Player* getObj() { return playerObject; }
};
//for Player class index
//-------------------------------------------------------
class PlayerClass
{
      private:
            PlayerClass();
            string pClass;
            Player* playerObject;
      public:
            PlayerClass(string s, Player* p)
            {
                  pClass = s;
                  playerObject = p;
            }
            string getClass() { return pClass; }
            Player* getObj() { return playerObject; }
};
//for Player level index
//-------------------------------------------------------
class PlayerLvl
{
      private:
            PlayerLvl();
            string lvl;
            Player* playerObject;
      public:
            PlayerLvl(string s, Player* p)
            {
                  lvl = s;
                  playerObject = p;
            }
            string getLvl() { return lvl; }
            Player* getObj() { return playerObject; }
};
//-------------------------------------------------------

typedef vector<Player>                                                   PlayerSet;
typedef vector<SpellClass>                                               SpellClassSet;
typedef vector<SpellType>                                                SpellTypeSet;
typedef unordered_multimap<string, SpellClassName>                       SpellClassNameIndex;
typedef unordered_multimap<string, SpellClassClass>                      SpellClassClassIndex;
typedef unordered_multimap<string, SpellClassLvl>                        SpellClassLvlIndex;                         
typedef unordered_multimap<string, SpellTypeName>                        SpellTypeNameIndex;
typedef unordered_multimap<string, SpellTypeType>                        SpellTypeTypeIndex;
typedef unordered_multimap<string, PlayerName>                           PlayerNameIndex;
typedef unordered_multimap<string, PlayerClass>                          PlayerClassIndex;
typedef unordered_multimap<string, PlayerLvl>                            PlayerLvlIndex;

int main()
{
      //------------PLAYER STUFF-------------
      PlayerSet             playerList;           
      PlayerNameIndex       playerNameIndex;
      PlayerClassIndex      playerClassIndex;
      PlayerLvlIndex        playerLvlIndex;
      //------------SPELL STUFF--------------
      SpellClassSet         spellClassList;
      SpellClassNameIndex   spellClassNameIndex;
      SpellClassClassIndex  spellClassClassIndex;
      SpellClassLvlIndex    spellClassLvlIndex;
      //----------SPELL TYPE STUFF-----------
      SpellTypeNameIndex    spellTypeNameIndex;
      SpellTypeTypeIndex    spellTypeTypeIndex;

    
      set<string>           spellNameList;
      ifstream              inFile;                // istream to import data files
      ifstream              inFile2;
      string                tmp, tmp2, tmp3;       // temporary strings to capture file input


      //import spell info, containing spell names, class, and level
      inFile.open("data2.txt");
      if (inFile.fail())
      {
            cout << "File failed to open, exiting program\n";
            exit(1);
      }
      //pass by column headers
      inFile >> tmp >> tmp2 >> tmp3;
      //load spell names in from file
      string tmpName, tmpClass, tmpLvl;
      int i = 0;
      while (!inFile.eof())
      {
            
            inFile >> tmpName;
            inFile >> tmpClass;
            inFile >> tmpLvl;

            SpellClass sp(tmpName, tmpClass, tmpLvl);
            spellClassList.push_back(sp);

      }
      //create index objects and populate the associated hash tables
      for (int i = 0; i < spellClassList.size(); ++i)
      {
            SpellClassName   tmpSp(spellClassList[i].getName(), &spellClassList[i]);
            SpellClassClass  tmpC(spellClassList[i].getClass(), &spellClassList[i]);
            SpellClassLvl    tmpL(spellClassList[i].getLvl(), &spellClassList[i]);

            spellClassNameIndex.insert(make_pair(spellClassList[i].getName(), tmpSp));  //[tmpName ]  = tmpSp;
            spellClassClassIndex.insert(make_pair(spellClassList[i].getClass(), tmpC)); //[tmpClass]  = tmpC;
            spellClassLvlIndex.insert(make_pair(spellClassList[i].getLvl(), tmpL));   //[tmpLvl  ]
      }
      inFile.close();
   
      cout << "\nspellClassNameIndex:\n";
      for (auto iter : spellClassNameIndex)
      {
            cout << "\nSpell Key: " << iter.first;
            cout << "\nSpell Name: " << iter.second.getName() << endl;
            cout << "\nParent Object: " << endl;
            iter.second.getObj()->printName();
      }
      for (auto iter2 : spellClassClassIndex)
      {
            cout << "\nClass Key:" << iter2.first;
            cout << "\nClass: " << iter2.second.getClass() << endl;
            cout << "\nParent Object: " << endl;
            iter2.second.getObj()->printName();
      }

      inFile.open("data1.txt");
      if (inFile.fail())
      {
            cout << "File failed to open. Exiting program...";
            exit(1);
      }
      inFile >> tmp >> tmp2 >> tmp3;
      while (!inFile.eof())
      {

            inFile >> tmp;
            inFile >> tmp2;
            inFile >> tmp3;
            
            Player p(tmp, tmp2, tmp3);                                    
            playerList.push_back(p);
      }
      for (int i = 0; i < playerList.size(); ++i)
      {
            PlayerName   tmpP(playerList[i].getName(), &playerList[i]);
            PlayerClass  tmpCl(playerList[i].getClass(), &playerList[i]);
            PlayerLvl    tmpLv(playerList[i].getMaxLvl(), &playerList[i]);

            playerNameIndex.insert(make_pair(playerList[i].getName(), tmpP));  //[tmpName ]  = tmpSp;
            playerClassIndex.insert(make_pair(playerList[i].getClass(), tmpCl)); //[tmpClass]  = tmpC;
            playerLvlIndex.insert(make_pair(playerList[i].getMaxLvl(), tmpLv));   //[tmpLvl  ]
      }
      system("PAUSE");
      /*
      for (auto iter : spellLookup["spNameIndex"])
      {
            spellNameList.insert(iter.first);
      }

      //import spell types, which inclues spell name and spell type
      inFile.open("data3.txt");
      if (inFile.fail())
      {
            cout << "File failed to open, exiting program\n";
            exit(1);
      }
      //pass by column headers 
      inFile >> tmp >> tmp2;
      //import data2.txt and 
      string tmpName, tmpType
      while (!inFile.eof())
      {
            inFile >> tmpName >> tmpType;
            
      }
      inFile.close();
      //create temporary vector and load types in
      vector<pair<string, SpellClass*>>* types = new vector<pair<string, SpellClass*>>;
      for (auto iter : spellList)
      {
            static int i = 0;
            pair<string, SpellClass*> tmpPair = make_pair(iter.type, &spellList.at(i));
            types->push_back(tmpPair);
            ++i;
      }
      sort(types->begin(), types->end());
      for (auto iter : *types) { spTypeIndex.insert(iter); } delete types;
      spellLookup["spTypeLookup"] = spTypeIndex;


      //import player file, which includes player name, class, and max level
      
      inFile.close();
      //initialize index tables for each player attribute
      vector<pair<string, Player*>>*  pName   = new vector<pair<string, Player*>>;
      vector<pair<string, Player*>>*  pClass  = new vector<pair<string, Player*>>;
      vector<pair<string, Player*>>*  pMaxLvl = new vector<pair<string, Player*>>;
      for (auto iter : playerList)
      {
            static int i = 0;
            pair<string, Player*> tmpPair = make_pair(iter.plName, &playerList.at(i));
            pName->push_back(tmpPair);

            pair<string, Player*> tmpPair2 = make_pair(iter.plClass, &playerList.at(i));
            pClass->push_back(tmpPair2);

            pair<string, Player*> tmpPair3 = make_pair(iter.plMaxLvl, &playerList.at(i));
            pMaxLvl->push_back(tmpPair3);
            i++;
      }
      //sort vectors
      sort ( pName->begin(),   pName->end()   );
      sort ( pClass->begin(),  pClass->end()  );
      sort ( pMaxLvl->begin(), pMaxLvl->end() );

      //load vectors into hash tables
      for (auto iter : *pName)   { plNameIndex.insert(iter);   } delete pName;
      for (auto iter : *pClass)  { plClassIndex.insert(iter);  } delete pClass;
      for (auto iter : *pMaxLvl) { plMaxLvlIndex.insert(iter); } delete pMaxLvl;

      //group player indexes in playerLookup for easy lookup
      playerLookup["plNameIndex"]   = plNameIndex;
      playerLookup["plClassIndex"]  = plClassIndex;
      playerLookup["plMaxLvlIndex"] = plMaxLvlIndex;

      initializeJoinTable(allList, playerList, spellList);

      char userResponse;
      do
      {
            string choice;
            //int intChoice;
            int menuChoice;
            cout << "1 - Search Spell By Name\n";
            cout << "2 - Search Spell By Class\n";
            cout << "3 - Search Spell By Type\n";
            cout << "4 - Search Spell by Level\n";
            cout << "5 - Search Player by Name\n";
            cout << "6 - Search Player by Class\n";
            cout << "7 - Search Player by Max Level\n";
            cout << "\nEnter 1-7: "; cin >> menuChoice;

            switch (menuChoice)
            {
                  case 1:
                  {
                        listSpellAttribute(spellNameList);
                        cout << "\nEnter Spell Name: "; cin >> choice;
                        auto iter2 = spNameIndex.find(choice);
                        printSpellHeader();
                        if (spNameIndex.count(choice) > 1)
                        {
                              auto iter = spNameIndex.equal_range(choice);
                              for (; iter2 != iter.second; ++iter2)
                              {
                                    printSpell(iter2->second);
                              }
                        }
                        else { printSpell(iter2->second); }
                        break;
                  }
                  case 2:
                  {
                        cout << "\nEnter Spell Class: "; cin >> choice;
                        auto iter2 = spClassIndex.find(choice);
                        printSpellHeader();
                        if (spClassIndex.count(choice) > 1)
                        {
                              auto iter = spClassIndex.equal_range(choice);
                              for (; iter2 != iter.second; ++iter2)
                              {
                                    printSpell(iter2->second);
                              }
                        }
                        else { printSpell(iter2->second); }
                        break;
                  }
                  case 3:
                  {
                        cout << "\nEnter Spell Type: "; cin >> choice;
                        auto iter2 = spTypeIndex.find(choice);
                        printSpellHeader();
                        if (spTypeIndex.count(choice) > 1)
                        {
                              auto iter = spTypeIndex.equal_range(choice);
                              for (; iter2 != iter.second; ++iter2)
                              {
                                    printSpell(iter2->second);
                              }
                        }
                        else { printSpell(iter2->second); }
                        break;
                  }
                  case 4:
                  {
                        cout << "\nEnter the Spell Level: "; cin >> choice;
                        auto iter2 = spellLookup["spLvlIndex"].find(choice);
                        printSpellHeader();
                        if (spellLookup["spLvlIndex"].count(choice) > 1)
                        {
                              auto iter = spellLookup["spLvlIndex"].equal_range(choice);
                              for (; iter2 != iter.second; ++iter2)
                              {
                                    printSpell(iter2->second);
                              }
                        }
                        else { printSpell(iter2->second); }
                        break;
                  }
                  case 5:
                  {
                        cout << "\nEnter the Player Name: "; cin >> choice;
                        auto iter2 = playerLookup["plNameIndex"].find(choice);
                        if (playerLookup["plNameIndex"].count(choice) > 1)
                        {
                              auto iter = playerLookup["plNameIndex"].equal_range(choice);
                              for (; iter2 != iter.second; ++iter2)
                              {
                                    printPlayer(iter2->second);
                              }
                        }
                        else { printPlayer(iter2->second); }
                        break;
                  }
                  case 6:
                  {
                        cout << "\nEnter Class: "; cin >> choice;
                        auto iter2 = playerLookup["plClassIndex"].find(choice);
                        if (playerLookup["plClassIndex"].count(choice) > 1)
                        {
                              auto iter = playerLookup["plClassIndex"].equal_range(choice);
                              for (; iter2 != iter.second; ++iter2)
                              {
                                    printPlayer(iter2->second);
                              }
                        }
                        else { printPlayer(iter2->second); }
                        break;
                  }
                  case 7:
                  {
                        cout << "\nEnter the Player's Max Level: "; cin >> choice;
                        auto iter2 = playerLookup["plMaxLvlIndex"].find(choice);
                        if (playerLookup["plMaxLvlIndex"].count(choice) > 1)
                        {
                              auto iter = playerLookup["plMaxLvlIndex"].equal_range(choice);
                              for (; iter2 != iter.second; ++iter2)
                              {
                                    printPlayer(iter2->second);
                              }
                        }
                        else { printPlayer(iter2->second); }
                        break;
                  }
            }
            cout << "\n\nAnother Search (y/n)?: "; cin >> userResponse;
      } while (userResponse == 'y');
      */
      return 0;
      
}