#include<iostream>
#include<unordered_map>
#include<tuple>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<utility>
#include<iomanip>
using namespace std;


class SpellClass
{
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


};
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
};
struct SpellClassClass
{
            string sClass;
            SpellClass* spellClassObject;
};
struct SpellClassLvl
{
            string lvl;
            SpellClass* spellClassObject;
};

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
            string getType()  { return type;   }
};

struct SpellTypeNameIndex
{
      string name;
      SpellType* spellTypeObject;
};
struct SpellTypeTypeIndex
{
      string type;
      SpellType* spellTypeObject;
};

class Player
{
      private:
            Player();
            Player(string n, string c, string m)
            {
                  plName   = n;
                  plClass  = c;
                  plMaxLvl = m;
            }
            string plName;
            string plClass;
            string plMaxLvl;
      public:
            string getName()   { return plName;   }
            string getClass()  { return plClass;  }
            string getMaxLvl() { return plMaxLvl; }
};

class allInfo
{
      vector<string> spellName;
      vector<string> spellClass;
      vector<string> spellType;
      vector<string> spellLvl;
      string playerName;
      string playerClass;
      string PlayerMaxLvl;
};

typedef unordered_map<string, unordered_multimap<string, SpellClass*>>   spellLookupDir  ;
typedef unordered_map<string, unordered_multimap<string, Player*>>  playerLookupDir ;
typedef unordered_map<string, unordered_multimap<string, allInfo*>> allInfoLookupDir;
typedef unordered_multimap<string, SpellClass*>                     Index_Spell ;
typedef unordered_multimap<string, Player*>                         Index_Player;
typedef unordered_multimap<string, allInfo*>                        Index_allInfo;
typedef vector<pair<string, allInfo*>>                              infoPair;
typedef vector<Player>                                              HashTable_Player;
//typedef vector<SpellClass>                                          HashTable_Spell;
typedef set<SpellClass>                                             SpellClassSet;
typedef unordered_multimap<string, SpellClassName>                  SpellClassNameIndex;
typedef set<SpellClassClass>                                        SpellClassClassIndex;
typedef set<SpellClassLvl>                                          SpellClassLvlIndex;
typedef vector<allInfo>                                             HashTable_allInfo;                             
typedef unordered_multimap<vector<string>, allInfo*>                tmpVecInfoIndex;
typedef vector<string>                                              tmpTable;

void initializeJoinTable(/*spellLookupDir &tmpSpell, playerLookupDir& tmpPlayer, allInfoLookupDir& tmpAll, */HashTable_allInfo& tmpA, HashTable_Player& tmpP, HashTable_Spell& tmpS)
{
      /*tmpVecTable* spellName    = new tmpVecTable;
      tmpVecTable* spellClass   = new tmpVecTable;
      tmpVecTable* spellType    = new tmpVecTable;
      tmpVecTable* spellLvl     = new tmpVecTable;
      tmpTable* playerName   = new tmpTable;
      tmpTable* playerClass  = new tmpTable;
      tmpTable* playerMaxLvl = new tmpTable;
      for (auto iter : tmpSpell["spNameIndex"])    { spellName->push_back(iter.first);    }
      for (auto iter : tmpSpell["spClassIndex"])   { spellClass->push_back(iter.first);   }
      for (auto iter : tmpSpell["spTypeIndex"])    { spellType->push_back(iter.first);    }
      for (auto iter : tmpSpell["spLvlIndex"])     { spellLvl->push_back(iter.first);     }
      for (auto iter : tmpPlayer["plNameIndex"])   { playerName->push_back(iter.first);   }
      for (auto iter : tmpPlayer["plClassIndex"])  { playerClass->push_back(iter.first);  }
      for (auto iter : tmpPlayer["plMaxLvlIndex"]) { playerMaxLvl->push_back(iter.first); }
      sort(spellName->begin(), spellName->end());
      sort(spellClass->begin(), spellClass->end());
      sort(spellType->begin(), spellType->end());
      sort(spellLvl->begin(), spellLvl->end());
      sort(playerName->begin(), playerName->end());
      sort(playerClass->begin(), playerClass->end());
      sort(playerMaxLvl->begin(), playerMaxLvl->end());
      for (auto iter : *spellName) { allInfo tmp;  tmpA->push_back(tmp); }
      for (auto iter : *spellName) 
      { 
            static int i = 0; 
            tmpA->at(i).spellName = iter; 
            tmpAll["plNameIndex"] 
      }*/
      int i = 0;
      for (auto iter : tmpP)
      {
            int j = 0;
            for (auto iter2 : tmpS)
            {
                  if (iter.plClass == iter2.sClass && stoi(iter.plMaxLvl) > stoi(iter2.lvl))
                  {
                        if (j == 0)
                        {
                              tmpA.at(i).playerName = iter.plName;
                              tmpA.at(i).playerClass = iter.plClass;
                              tmpA.at(i).PlayerMaxLvl = iter.plMaxLvl;
                              tmpA.at(i).spellName.push_back(iter2.name);
                              tmpA.at(i).spellClass.push_back(iter2.sClass);
                              tmpA.at(i).spellType.push_back(iter2.type);
                              tmpA.at(i).spellLvl.push_back(iter2.lvl);
                              ++j;
                        }
                        else
                        {
                              tmpA.at(i).spellName.push_back(iter2.name);
                              tmpA.at(i).spellClass.push_back(iter2.sClass);
                              tmpA.at(i).spellType.push_back(iter2.type);
                              tmpA.at(i).spellLvl.push_back(iter2.lvl);
                        }
                  }
            }
            ++i;
      }
}
void initializeIndex(allInfoLookupDir& tmpDir, Index_allInfo& tmpInd, HashTable_allInfo& tmpHash)
{
      vector<pair<string, allInfo*>>* spellName    = new vector<pair<string, allInfo*>>;
      vector<pair<string, allInfo*>>* spellClass   = new vector<pair<string, allInfo*>>;
      vector<pair<string, allInfo*>>* spellType    = new vector<pair<string, allInfo*>>;
      vector<pair<string, allInfo*>>* spellLvl     = new vector<pair<string, allInfo*>>;
      infoPair*       playerName   = new infoPair;
      infoPair*       playerClass  = new infoPair;
      infoPair*       playerMaxLvl = new infoPair;

      for (auto iter : tmpHash)
      {
            int i = 0;
            pair<string, allInfo*> tmpPair = make_pair(iter.playerName, &tmpHash.at(i));
            playerName->push_back(tmpPair);
      }
}

void printAllHeader()
{
      cout << endl << "     " << setw(20) << left << "Name" << setw(15) << "Class" << setw(15) << "Lvl" << setw(15) << "Spell"
            << setw(15) << "Spell Type" << setw(15) << "Spell Level "<< setw(15) << "Spell Class\n";
}

void printAllInfo(allInfo& info)
{
      int i = 0;
      cout << endl << "     " << setw(20) << left << info.playerName << setw(15)
            << info.playerClass << setw(15) << info.PlayerMaxLvl << setw(15)
            << info.spellName.at(i) << setw(10) << info.spellType.at(i) << setw(10) << info.spellClass.at(i) << endl;
      for (int i = 1; i < info.spellName.size(); ++i)
      {
            cout << setw(70) << info.spellName.at(i) << setw(15) << info.spellType.at(i) 
                  << setw(15) << info.spellLvl.at(i) << setw(15) << info.spellClass.at(i) << endl;
      }
}
void printSpellHeader()
{
      cout << endl << "     " << setw(20) << left <<  "Spell" << setw(15) <<   "Type" 
                   << setw(10) << "Class" << setw(10) <<   "Level\n";
}

void printSpell(SpellClass* tmpSpell)
{
      cout << endl << "     " << setw(20) << tmpSpell->name; //   << endl;
      cout << setw(15) << tmpSpell->type;// << endl;
      cout << setw(10) << tmpSpell->sClass;// << endl;
      cout << setw(10) << tmpSpell->lvl;// << endl;
      return;
}

void listSpellAttribute(set<string> &tmp)
{
      int i = 1;
      cout << endl;
      for (auto iter : tmp)
      {
            cout << setw(17) << iter;
            if (i % 4 == 0)
            {
                  cout << endl;
            }
            ++i;
      }
}

void printPlayer(Player* tmpPlayer)
{
      cout << "\nName: "    << tmpPlayer->plName   << endl;
      cout << "Class: "     << tmpPlayer->plClass  << endl;
      cout << "Max_Level: " << tmpPlayer->plMaxLvl << endl;
      return;
}

/*
string printSpellByClass(hashTable_Spell* base)
{
      hashTable_Spell::iterator iter1 = base->begin();
      while(iter1 != base->end())
      { 
            auto iter2 = base->equal_range(iter1->first);
            for (;iter1 != iter2.second; ++iter1)
            { 
            
            }
      }
}
string printSpellByLvl(unordered_multimap<int, Spell*>* tmpMap, int lvl)
{

}*/

int main()
{
      spellLookupDir      spellLookup;      // holds all the attribute indexes for spell
      playerLookupDir     playerLookup;     // holds all the attributes indexes for player
      allInfoLookupDir    allLookup;
      Index_Spell         spNameIndex;      // holds pairs of spell names, and pointers to spell obj
      Index_Spell         spClassIndex;     // holds pairs of spell classes, and pointers to spell obj
      Index_Spell         spTypeIndex;      // holds pairs of spell types, and pointers to spell obj
      Index_Spell         spLvlIndex;       // holds pairs of spell levels, and pointers to spell obj
      Index_Player        plNameIndex;      // holds pairs of player names, and pointers to player obj
      Index_Player        plClassIndex;     // holds pairs of player classes, and pointers to player obj
      Index_Player        plMaxLvlIndex;    // holds pairs of player max level, and pointers to player obj 
      Index_allInfo       aSpellName;
      Index_allInfo       aSpellType;
      Index_allInfo       aSpellLvl;
      Index_allInfo       aClass;
      Index_allInfo       aLvl;
      Index_allInfo       aName;
      HashTable_Player    playerList;       // Table of all the players, who can we searched by any index
      //HashTable_Spell    spellList;        // Table of all the spells; all can be searched by spell index
      SpellClassSet       spellClass;
      SpellClassNameIndex spellClassNameIndex;
      SpellClassClassIndex spellClassClassIndex;
      SpellClassLvlIndex  spellClassLvlIndex;
      HashTable_allInfo   allList;          // Table of all data, all can be searched by any index
      set<string>         spellNameList;
      ifstream            inFile;           // istream to import data files
      ifstream            inFile2;
      string              tmp, tmp2, tmp3;  // temporary strings to capture file input

      allLookup["aSpellName"] = aSpellName;
      allLookup["aSpellType"] = aSpellType;
      allLookup["aSpellLvl"]  = aSpellLvl;
      allLookup["aClass"]     = aClass;
      allLookup["aLvl"]       = aLvl;
      allLookup["aName"]      = aName;

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
      while (!inFile.eof())
      {
            inFile >> tmp;
            inFile >> tmp2;
            inFile >> tmp3;

            SpellClass sp(tmp, tmp2, tmp3);
            spellClass.insert(sp);
            SpellClassName tmpSp(tmp, &sp);
            spellClassNameIndex[tmp] = tmpSp;
      }
      inFile.close();

      //initialize index tables for each spell attribute
      vector<pair<string, SpellClass*>>*  names   = new vector<pair<string, SpellClass*>>;
      vector<pair<string, SpellClass*>>*  classes = new vector<pair<string, SpellClass*>>;
      vector<pair<string, SpellClass*>>*  levels  = new vector<pair<string, SpellClass*>>;

      //load names, classes, and levels into vectors alongside a ptr to the parent object
      for (auto iter : spellList)
      {
            static int i = 0;
            pair<string, SpellClass*> tmpPair = make_pair(iter.name, &spellList.at(i));
            names->push_back(tmpPair);

            pair<string, SpellClass*> tmpPair2 = make_pair(iter.sClass, &spellList.at(i));
            classes->push_back(tmpPair2);

            pair<string, SpellClass*> tmpPair3 = make_pair(iter.lvl, &spellList.at(i));
            levels->push_back(tmpPair3);
            i++;
      }
      //sort vectors
      sort(names->begin(), names->end());
      sort(classes->begin(), classes->end());
      sort(levels->begin(), levels->end());
      //load vectors into hash tables
      for (auto iter : *names   ) { spNameIndex.insert(iter);  } delete names;
      for (auto iter : *classes ) { spClassIndex.insert(iter); } delete classes;
      for (auto iter : *levels  ) { spLvlIndex.insert(iter);   } delete levels;

      spellLookup["spNameIndex"]  = spNameIndex;
      spellLookup["spClassIndex"] = spClassIndex;
      spellLookup["spLvlIndex"]   = spLvlIndex;

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
      while (!inFile.eof())
      {
            auto itBegin = spellList.begin();
            auto itEnd = spellList.end();
            inFile >> tmp >> tmp2;
            //cout << tmp << " " << tmp2;
            while(itBegin != itEnd)
            {
                  if (itBegin->name == tmp)
                  {
                        itBegin->type += tmp2;
                        //cout << "\nSpell Name: " << itBegin->name << "\nSpell Type: " << itBegin->type << endl;
                        //cout << "\nType from spellList: " << spellList.at(i).type;
                  }
                  ++itBegin;
            }
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
      inFile.open("data1.txt");
      if (inFile.fail())
      {
            cout << "File failed to open. Exiting program...";
            exit(1);
      }
      inFile >> tmp >> tmp2 >> tmp3;
      while (!inFile.eof())
      {
            Player p;

            inFile >> tmp >> tmp2 >> tmp3;

            p.plName   = tmp;
            p.plClass  = tmp2;
            p.plMaxLvl = tmp3;

            playerList.push_back(p);
      }
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

      return 0;
}