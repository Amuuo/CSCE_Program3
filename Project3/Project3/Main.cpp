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

enum attr { NAME, CLASS, MAX_SPELL_LVL, SPELL };
enum spellAttr { spNAME, spTYPE, spCLASS, spLVL };

struct Spell
{
      string name;
      //string sClass;
      unordered_map<string, string> sClass;
      string type;
      int lvl;

};

void printSpell(Spell* tmpSpell)
{
      cout << "\nName: " << tmpSpell->name   << endl;
      cout << "Class: " << endl;
      for (auto iter : tmpSpell->sClass)
      {
            static int i = 1;
            cout << i << ": " << iter.second << endl;
            i++;
      }
      cout << "Type: "   << tmpSpell->type   << endl;
      cout << "Level: "  << tmpSpell->lvl    << endl;
      return;
}

int main()
{
      ifstream inFile;
      vector<Spell> spellList;
      unordered_multimap<string, Spell*> spNameLookup;
      unordered_multimap<string, Spell*> spClassLookup;
      unordered_multimap<string, Spell*> spTypeLookup;
      unordered_multimap<int, Spell*> spLvlLookup;
      string tmp, tmp2, tmp3;
      int tmpInt;


      inFile.open("data2.txt");
      if (inFile.fail())
      {
            cout << "File failed to open, exiting program\n";
            exit(1);
      }
      //pass by column headers
      inFile >> tmp >> tmp2 >> tmp3;
      vector<pair<string, string>>* tmpClass = new vector<pair<string,string>>;
      while (!inFile.eof())
      {
            Spell sp;

            inFile >> tmp >> tmp2 >> tmpInt;

            sp.name = tmp;
            pair<string, string> tmpPair = make_pair(tmp, tmp2);
            tmpClass->push_back(tmpPair);
            sp.lvl = tmpInt;
            sp.type = "";

            spellList.push_back(sp);
      }
      inFile.close();
      //initialize lookup tables for each spell attribute
      vector<pair<string, Spell*>> names;
      for (auto iter : spellList ) { cout << iter.name << endl; }
      vector<pair<string, Spell*>> classes;
      vector<pair<int, Spell*>> levels;
      for (auto iter : spellList)
      {
            static int i = 0;
            pair<string, Spell*> tmpPair = make_pair(iter.name, &spellList.at(i));
            names.push_back(tmpPair);

            pair<string, Spell*> tmpPair2 = make_pair(iter.sClass, &spellList.at(i));
            classes.push_back(tmpPair2);

            pair<int, Spell*> tmpPair3 = make_pair(iter.lvl, &spellList.at(i));
            levels.push_back(tmpPair3);
            i++;
      }
      sort(names.begin(), names.end());
      sort(classes.begin(), classes.end());
      sort(levels.begin(), levels.end());
      for (auto iter : names)   { spNameLookup.insert(iter);  }
      for (auto iter : classes) { spClassLookup.insert(iter); }
      for (auto iter : levels)  { spLvlLookup.insert(iter);   }
      /*
      sort(begin(spNameLookup), end(spNameLookup));
      sort(begin(spTypeLookup), end(spTypeLookup));
      sort(begin(spLvlLookup), end(spLvlLookup));
      */
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
            int i = 0;
            while(itBegin != itEnd)
            {
                  if (itBegin->name == tmp)
                  {
                        itBegin->type += tmp2;
                        cout << "\nSpell Name: " << itBegin->name << "\nSpell Type: " << itBegin->type << endl;
                        cout << "\nType from spellList: " << spellList.at(i).type;
                  }
                  ++itBegin;
                  i++;
            }
      }
      vector<pair<string, Spell*>> types;
      for (auto iter : spellList)
      {
            static int i = 0;
            pair<string, Spell*> tmpPair = make_pair(iter.type, &spellList.at(i));
            types.push_back(tmpPair);
      }
      
      for(auto iter : spellList)
      {
            static int i = 0;
            cout << "Name: " << iter.name << endl;
            cout << "Class: " << iter.sClass << endl;
            cout << "Type: " << iter.type << endl;
            cout << "Level: " << iter.lvl << endl;
            cout << "Memory Address: " << &spellList.at(i) << endl << endl;
            ++i;
      }
      sort(types.begin(), types.end());
      for (auto iter : types)
      {
            cout << iter.second << endl;
            spTypeLookup.insert(iter);
      }
      //sort(begin(spTypeLookup), end(spTypeLookup));
      for (auto iter : spNameLookup)
      {
            cout << iter.first << endl;
      }
      char userResponse;
      cout << "\n*******SP_CLASS_LOOKUP*********\n" << endl;

      for (auto iter : spClassLookup)
      {           
            cout << iter.first << endl;
      }
      cout << "\n*******SP_NAME_LOOKUP*********\n" << endl;

      for (auto iter : spNameLookup)
      {
       
            printSpell(iter.second);
      }
      cout << "\n*******SP_TYPE_LOOKUP*********\n" << endl;

      for (auto iter : spTypeLookup)
      {
            cout << iter.first << endl;
      }
      cout << "\n*******SP_LEVEL_LOOKUP*********\n" << endl;

      for (auto iter : spLvlLookup)
      {
            cout << iter.first << endl;
      }
      do
      {
            string choice;
            int intChoice;
            int menuChoice;
            cout << "1 - Search Spell By Name\n";
            cout << "2 - Search Spell By Class\n";
            cout << "3 - Search Spell By Type\n";
            cout << "4 - Search Spell by Level\n";
            cout << "Enter 1-4: "; cin >> menuChoice;

            switch (menuChoice)
            {
            case 1:
            {
                  cout << "\n\nEnter Spell Name: "; cin >> choice;
                  auto iter2 = spNameLookup.find(choice);
                  if (spNameLookup.count(choice) > 1)
                  {
                        auto iter = spNameLookup.equal_range(choice);
                        for (; iter2 != iter.second; ++iter2)
                        {
                              printSpell(iter2->second);
                        }
                  }
                  else
                  {
                        printSpell(iter2->second);
                  }
                  break;
            }
            case 2:
            {
                  cout << "\n\nEnter Spell Class: "; cin >> choice;
                  auto iter2 = spClassLookup.find(choice);
                  if (spClassLookup.count(choice) > 1)
                  {
                        auto iter = spClassLookup.equal_range(choice);
                        for (; iter2 != iter.second; ++iter2)
                        {
                              printSpell(iter2->second);
                        }
                  }
                  else
                  {
                        printSpell(iter2->second);
                  }
                  break;
            }
            case 3:
            {
                  cout << "\n\nEnter Spell Type: "; cin >> choice;
                  auto iter2 = spTypeLookup.find(choice);
                  if (spTypeLookup.count(choice) > 1)
                  {
                        auto iter = spTypeLookup.equal_range(choice);
                        for (; iter2 != iter.second; ++iter2)
                        {
                              printSpell(iter2->second);
                        }
                  }
                  else
                  {
                        printSpell(iter2->second);
                  }
                  break;
            }
            case 4:
            {
                  cout << "\n\nEnter the Spell Level: "; cin >> intChoice;
                  auto iter2 = spLvlLookup.find(intChoice);
                  if (spClassLookup.count(choice) > 1)
                  {
                        auto iter = spLvlLookup.equal_range(intChoice);
                        for (; iter2 != iter.second; ++iter2)
                        {
                              printSpell(iter2->second);
                        }
                  }
                  else
                  {
                        printSpell(iter2->second);
                  }
                  break;
            }
            }
            cout << "\n\nAnother Search (y/n)?: "; cin >> userResponse;
      } while (userResponse == 'y');

      return 0;
}