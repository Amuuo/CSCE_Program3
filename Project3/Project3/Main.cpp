#include<iostream>
#include<unordered_map>
#include<tuple>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<utility>
using namespace std;


struct Spell
{
      string  name;
      string  sClass;
      string  type;
      string  lvl;
};

struct Player
{
      string plName;
      string plClass;
      string plMaxLvl;
};

typedef unordered_map<string, unordered_multimap<string, Spell*>> spellLookupDir;
typedef unordered_map<string, unordered_multimap<string, Player*>> playerLookupDir;
typedef unordered_multimap<string, Spell*> hashTable_Spell;
typedef unordered_multimap<string, Player*> hashTable_Player;

void printSpell(Spell* tmpSpell)
{
      cout << "\nName: " << tmpSpell->name   << endl;
      cout << "Class: "  << tmpSpell->sClass << endl;
      cout << "Type: "   << tmpSpell->type   << endl;
      cout << "Level: "  << tmpSpell->lvl    << endl;
      return;
}

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

}

int main()
{
      spellLookupDir    spellLookup;      // holds all the attribute indexes for spell
      playerLookupDir   playerLookup;     // holds all the attributes indexes for player
      hashTable_Spell   spNameIndex;      // holds pairs of spell names, and pointers to spell obj
      hashTable_Spell   spClassIndex;     // holds pairs of spell classes, and pointers to spell obj
      hashTable_Spell   spTypeIndex;      // holds pairs of spell types, and pointers to spell obj
      hashTable_Spell   spLvlIndex;       // holds pairs of spell levels, and pointers to spell obj
      hashTable_Player  plNameIndex;      // holds pairs of player names, and pointers to player obj
      hashTable_Player  plClassIndex;     // holds pairs of player classes, and pointers to player obj
      hashTable_Player  plMaxLvlIndex;    // holds pairs of player max level, and pointers to player obj 
      vector<Player>    playerList;       // vector of all the players, who can we searched by any index
      vector<Spell>     spellList;        // vector of all the spells; all can be searched by spell index
      ifstream          inFile;           // istream to import data files
      string            tmp, tmp2, tmp3;  // temporary strings to capture file input


      inFile.open("data2.txt");
      if (inFile.fail())
      {
            cout << "File failed to open, exiting program\n";
            exit(1);
      }
      //pass by column headers
      inFile >> tmp >> tmp2 >> tmp3;
      //load spell names in from file
      string tmpClass = "";
      while (!inFile.eof())
      {
            string tmpName;
            Spell sp;

            inFile >> tmp;
            inFile >> tmp2;
            inFile >> tmp3;

            sp.name   = tmp;
            sp.sClass = tmp2;
            sp.lvl    = tmp3;
            sp.type   = "";

            spellList.push_back(sp);
      }
      inFile.close();

      //initialize index tables for each spell attribute
      vector<pair<string, Spell*>>*  names   = new vector<pair<string, Spell*>>;
      vector<pair<string, Spell*>>*  classes = new vector<pair<string, Spell*>>;
      vector<pair<string, Spell*>>*  levels  = new vector<pair<string, Spell*>>;

      //load names, classes, and levels into vectors alongside a ptr to the parent object
      for (auto iter : spellList)
      {
            static int i = 0;
            pair<string, Spell*> tmpPair = make_pair(iter.name, &spellList.at(i));
            names->push_back(tmpPair);

            pair<string, Spell*> tmpPair2 = make_pair(iter.sClass, &spellList.at(i));
            classes->push_back(tmpPair2);

            pair<string, Spell*> tmpPair3 = make_pair(iter.lvl, &spellList.at(i));
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

      spellLookup["spNameLookup"]  = spNameIndex;
      spellLookup["spClassLookup"] = spClassIndex;
      spellLookup["spLvlLookup"]   = spLvlIndex;

      inFile.open("data3.txt");
      if (inFile.fail())
      {
            cout << "File failed to open, exiting program\n";
            exit(1);
      }
      while (!inFile.eof())
      {

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
            int i = 0;
            while(itBegin != itEnd)
            {
                  if (itBegin->name == tmp)
                  {
                        itBegin->type += tmp2;
                        //cout << "\nSpell Name: " << itBegin->name << "\nSpell Type: " << itBegin->type << endl;
                        //cout << "\nType from spellList: " << spellList.at(i).type;
                  }
                  ++itBegin;
                  i++;
            }
      }
      inFile.close();
      //create temporary vector and load types in
      vector<pair<string, Spell*>>* types = new vector<pair<string, Spell*>>;
      for (auto iter : spellList)
      {
            static int i = 0;
            pair<string, Spell*> tmpPair = make_pair(iter.type, &spellList.at(i));
            types->push_back(tmpPair);
            ++i;
      }
      sort(types->begin(), types->end());
      for (auto iter : *types) { spTypeIndex.insert(iter); } delete types;
      spellLookup["spTypeLookup"] = spTypeIndex;

      inFile.open("data3.txt");
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
            cout << "6 = Search Player by Class\n";
            cout << "7 = Search Player by Max Level\n";
            cout << "Enter 1-4: "; cin >> menuChoice;

            switch (menuChoice)
            {
                  case 1:
                  {
                        cout << "\n\nEnter Spell Name: "; cin >> choice;
                        auto iter2 = spNameIndex.find(choice);
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
                        cout << "\n\nEnter Spell Class: "; cin >> choice;
                        auto iter2 = spClassIndex.find(choice);
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
                        cout << "\n\nEnter Spell Type: "; cin >> choice;
                        auto iter2 = spTypeIndex.find(choice);
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
                        cout << "\n\nEnter the Spell Level: "; cin >> choice;
                        auto iter2 = spellLookup["spLvlIndex"].find(choice);
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
                        cout << "\n\nEnter the Player Name: "; cin >> choice;
                        auto iter2 = playerLookup["plNameIndex"].find(choice);
                        if (playerLookup["plNameIndex"].count(choice) > 1)
                        {
                              auto iter = playerLookup["plNameIndex"].equal_range(choice);
                              for (; iter2 != iter.second; ++iter2)
                              {
                                    printSpell(iter2->second);
                              }
                        }
                        else { printSpell(iter2->second); }
                        break;
                  }
            }
            cout << "\n\nAnother Search (y/n)?: "; cin >> userResponse;
      } while (userResponse == 'y');

      return 0;
}