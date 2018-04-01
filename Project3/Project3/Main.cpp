#include<iostream>
#include<unordered_map>
#include<tuple>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

enum attr { NAME, CLASS, MAX_SPELL_LVL, SPELL };
enum spellAttr { spNAME, spTYPE, spCLASS, spLVL };

struct Spell
{
      string name;
      string sClass;
      string type;
      int lvl;

};

void printSpell(Spell* tmpSpell)
{
      cout << "\nName: " << tmpSpell->name << endl
            << "Class: " << tmpSpell->sClass << endl
            << "Type: " << tmpSpell->type << endl
            << "Level: " << tmpSpell->lvl << endl;
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
      while (!inFile.eof())
      {
            Spell sp;

            inFile >> tmp >> tmp2 >> tmpInt;

            sp.name = tmp;
            sp.sClass = tmp2;
            sp.lvl = tmpInt;

            spellList.push_back(sp);
      }
      inFile.close();
      //initialize lookup tables for each spell attribute
      for (auto iter : spellList)
      {
            pair<string, Spell*> tmpPair = make_pair(iter.name, &iter);
            spNameLookup.insert(tmpPair);

            pair<string, Spell*> tmpPair2 = make_pair(iter.sClass, &iter);
            spTypeLookup.insert(tmpPair2);

            pair<int, Spell*> tmpPair3 = make_pair(iter.lvl, &iter);
            spLvlLookup.insert(tmpPair3);
      }
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
            inFile >> tmp >> tmp2;
            for (auto iter : spellList)
            {
                  if (iter.name == tmp)
                  {
                        iter.type = tmp2;
                  }
            }
      }
      for (auto iter : spellList)
      {
            pair<string, Spell*> tmpPair = make_pair(iter.type, &iter);
            spTypeLookup.insert(tmpPair);
      }
      char userResponse;
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
                  auto iter = spNameLookup.equal_range(choice);
                  for_each(iter.first, iter.second,
                        [](unordered_map<string, Spell*>::value_type& x) { printSpell(x.second); });

                  while (iter->first == choice)
                  {
                        printSpell(iter->second);
                        ++iter;
                  }
                  break;
            }
            case 2:
            {
                  cout << "\n\nEnter Spell Class: "; cin >> choice;
                  auto iter = spClassLookup.find(choice);
                  while (iter->first == choice)
                  {
                        printSpell(iter->second);
                        ++iter;
                  }
                  break;
            }
            case 3:
            {
                  cout << "\n\nEnter Spell Type: "; cin >> choice;
                  auto iter = spTypeLookup.find(choice);
                  while (iter->first == choice)
                  {
                        printSpell(iter->second);
                        ++iter;
                  }
                  break;
            }
            case 4:
            {
                  cout << "\n\nEnter the Spell Level: "; cin >> intChoice;
                  auto iter = spLvlLookup.find(intChoice);
                  while (iter->first == intChoice)
                  {
                        printSpell(iter->second);
                        ++iter;
                  }
                  break;
            }
            }
            cout << "\n\nAnother Search (y/n)?: "; cin >> userResponse;
      } while (userResponse == 'y');

      return 0;
}