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
      private:
      
            SpellClass();
            string attr[3] = { "SpellName", "Class", "Level" };
            string  spName;
            string  pClass;
            string  lvl;

      public:

            SpellClass(string n, string c, string l)
            {
                  spName   = n;
                  pClass = c;
                  lvl    = l;
            }
            string       getName()  { return spName;   }
            string       getClass() { return pClass; }
            string       getLvl()   { return lvl;    }
            string*      getAttr()  { return attr;   }
            SpellClass*  getThis()  { return this;   }
            void print()
            {
                  cout  << left << "\t" << setw(20) << spName;
                  cout  << "" << setw(15) << pClass;
                  cout  << "Lvl: " << setw(10) << lvl;
            }
            void printExcept(string x)
            {
                  if (x == "SpellName")
                        cout << "\t" << left << setw(20) << pClass << setw(20) << lvl;
                  if (x == "Class")
                        cout << "\t" << left << setw(20) << spName << setw(20) << lvl;
                  if (x == "Level")
                        cout << "\t" << left << setw(20) << spName << setw(20) << pClass;
            }
            friend bool operator< (SpellClass &left,SpellClass &right)
            {
                  if (left.getName()[0] < right.getName()[0]) return true;
                  else return false;
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
            void print() { cout << name; }
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
            void print() { cout << sClass; }
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
            void print() { cout << lvl; }
};

//tuples from data3.txt
//-------------------------------------------------------
class SpellType
{
      private:

            SpellType();
            string attr[2] = { "SpellName", "SpellType" };
            string spName;
            string spType;

      public:

            SpellType(string s, string t)
            {
                  spName = s;
                  spType   = t;
            }
            string  getName()  { return spName; }
            string  getType()  { return spType; }
            string* getAttr()  { return attr; }
            void print()
            {
                  cout  << left << "\tSpell Name: " << setw(20) << spName;
                  cout  << "Type Name:" << setw(15) << spType;
            }
            void printExcept(string x)
            {
                  if (x == "SpellName")
                        cout << "\t" << left << setw(20) << spType;
                  if (x == "SpellType")
                        cout << "\t" << left << setw(20) << spName;
            }
            friend bool operator< (SpellType &left, SpellType &right)
            {
                  if (left.getName()[0] < right.getName()[0]) return true;
                  else return false;
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
            void print() { cout << name; }
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
            void print() { cout << type; }
};

//tuples from data1.txt
//-------------------------------------------------------
class Player
{
private:
      Player();
            string attr[3] = { "PlayerName", "Class", "Level" };
            string plName;
            string pClass;
            string lvl;

      public:

            Player(string n, string c, string m)
            {
                  plName   = n;
                  pClass  = c;
                  lvl = m;
            }
            string  getName()   { return plName;   }
            string  getClass()  { return pClass;  }
            string  getMaxLvl() { return lvl; }
            string* getAttr()   { return attr;     }
            void print()
            {
                  cout  << left << "\t" << setw(20) << plName;
                  cout   << setw(20) << pClass;
                  cout   << "Lvl: " << setw(20) << lvl;
            }
            void printExcept(string x) 
            {
                  if (x == "PlayerName") 
                        cout << "\t" << left << setw(20) << pClass << setw(20) << lvl;
                  if (x == "Class")
                        cout << "\t" << left << setw(20) << plName << setw(20) << lvl;
                  if (x == "Level")
                        cout << "\t" << left << setw(20) << plName << setw(20) << pClass;                                    
            }
            friend bool operator< (Player &left,Player &right)
            {
                  if (left.getName()[0] < right.getName()[0]) return true;
                  else return false;
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
            void print() { cout << name; }
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
            void print() { cout << pClass; }
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
            void print() { lvl; }
};

//-------------------------------------------------------

template <class L, class R>
void join(L firstTable, R secondTable)
{
      string match = "";
      int k = 0;
      
      //search for matching column headers
      for (int i = 0; i < firstTable.at(0).getAttr()->size(); ++i)
      {
            for (int j = 0; j < secondTable.at(0).getAttr()->size(); ++j)
            {
                  if (firstTable.at(0).getAttr()[i] == secondTable.at(0).getAttr()[j])
                  {
                        match = firstTable.at(0).getAttr()[i];
                  }
            }     
      }
      if (match != "")
      {
            if (firstTable.size() > secondTable.size())
            {
                  for (int i = 0; i < secondTable.size(); ++i)
                  {
                        cout << endl;
                        firstTable.at(i).printExcept(match);
                        secondTable.at(i).print();
                  }
            }
            else
            {
                  for (int i = 0; i < firstTable.size(); ++i)
                  {
                        cout << endl;
                        firstTable.at(i).printExcept(match);
                        secondTable.at(i).print();
                  }
            }
      }
      else { cout << "\nThese tables have no columns in common"; }
}

typedef vector<Player     >                              PlayerSet;
typedef vector<SpellClass >                              SpellClassSet;
typedef vector<SpellType  >                              SpellTypeSet;
typedef unordered_multimap<string, SpellClassName  >     SpellClassNameIndex;
typedef unordered_multimap<string, SpellClassClass >     SpellClassClassIndex;
typedef unordered_multimap<string, SpellClassLvl   >     SpellClassLvlIndex;
typedef unordered_multimap<string, SpellTypeName   >     SpellTypeNameIndex;
typedef unordered_multimap<string, SpellTypeType   >     SpellTypeTypeIndex;
typedef unordered_multimap<string, PlayerName      >     PlayerNameIndex;
typedef unordered_multimap<string, PlayerClass     >     PlayerClassIndex;
typedef unordered_multimap<string, PlayerLvl       >     PlayerLvlIndex;

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
      SpellTypeSet          spellTypeList;
      SpellTypeNameIndex    spellTypeNameIndex;
      SpellTypeTypeIndex    spellTypeTypeIndex;

      ifstream              inFile;    
      string                tmpName; 
      string                tmpClass; 
      string                tmpLvl;

      inFile.open("data1.txt");
      if (inFile.fail())
      {
            cout << "File failed to open. Exiting program...";
            exit(1);
      }
      inFile >> tmpName >> tmpClass >> tmpLvl;
      while (!inFile.eof())
      {
            inFile >> tmpName;
            inFile >> tmpClass;
            inFile >> tmpLvl;
            
            Player p(tmpName, tmpClass, tmpLvl);                                    
            playerList.push_back(p);
      }
      //create index objects and populate the associated hash tables
      for (auto i = 0; i < playerList.size(); ++i)
      {
            PlayerName   tmpP(playerList[i].getName(), &playerList[i]);
            PlayerClass  tmpCl(playerList[i].getClass(), &playerList[i]);
            PlayerLvl    tmpLv(playerList[i].getMaxLvl(), &playerList[i]);

            playerNameIndex.insert(make_pair(playerList[i].getName(), tmpP));  //[tmpName ]  = tmpSp;
            playerClassIndex.insert(make_pair(playerList[i].getClass(), tmpCl)); //[tmpClass]  = tmpC;
            playerLvlIndex.insert(make_pair(playerList[i].getMaxLvl(), tmpLv));   //[tmpLvl  ]
      }
      inFile.close();


      //import spell info, containing spell names, class, and level
      inFile.open("data2.txt");
      if (inFile.fail())
      {
            cout << "File failed to open, exiting program\n";
            exit(1);
      }
      //pass by column headers
      inFile >> tmpName >> tmpClass >> tmpLvl;
      //load spell names in from file
      int i = 0;
      while (!inFile.eof())
      {
            
            inFile >> tmpName;
            inFile >> tmpClass;
            inFile >> tmpLvl;

            SpellClass sp(tmpName, tmpClass, tmpLvl);
            spellClassList.push_back(sp);

      }
      inFile.close();
      
      //create index objects and populate the associated hash tables
      for (auto i = 0; i < spellClassList.size(); ++i)
      {
            SpellClassName   tmpSp (spellClassList [i]. getName(),  &spellClassList[i]);
            SpellClassClass  tmpC  (spellClassList [i]. getClass(), &spellClassList[i]);
            SpellClassLvl    tmpL  (spellClassList [i]. getLvl(),   &spellClassList[i]);

            spellClassNameIndex  .insert(make_pair(spellClassList[i].getName(),  tmpSp));
            spellClassClassIndex .insert(make_pair(spellClassList[i].getClass(), tmpC));
            spellClassLvlIndex   .insert(make_pair(spellClassList[i].getLvl(),   tmpL)); 
      }

      //import spell types, which inclues spell name and spell type
      inFile.open("data3.txt");
      if (inFile.fail())
      {
            cout << "File failed to open, exiting program\n";
            exit(1);
      }
      //pass by column headers 
      inFile >> tmpName >> tmpClass;
      //import data2.txt and 
      string tmpName2, tmpType;
      while (!inFile.eof())
      {
            inFile >> tmpName2;
            inFile >> tmpType;

            SpellType st(tmpName2, tmpType);
            spellTypeList.push_back(st);
      }
      inFile.close();

      //create index object and populate the associated hash tables
      for (auto i = 0; i < spellTypeList.size(); ++i)
      {
            SpellTypeName   tmpTn(spellTypeList[i].getName(), &spellTypeList[i]);
            SpellTypeType  tmpTT(spellTypeList[i].getType(), &spellTypeList[i]);

            spellTypeNameIndex.insert(make_pair(spellTypeList[i].getName(), tmpTn));  //[tmpName ]  = tmpSp;
            spellTypeTypeIndex.insert(make_pair(spellTypeList[i].getType(), tmpTT)); //[tmpClass]  = tmpC;
      }

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
            cout << "8 - Join Tables\n";
            cout << "\nEnter 1-7: "; cin >> menuChoice;

            switch (menuChoice)
            {
                  case 1:
                  {
                        cout << "\nEnter Spell Name: "; cin >> choice;
                        auto iter2 = spellClassNameIndex.find(choice);
                        //printSpellHeader();
                        if (spellClassNameIndex.count(choice) > 1)
                        {
                              auto iter = spellClassNameIndex.equal_range(choice);
                              for (; iter2 != iter.second; ++iter2)
                              {
                                    (iter2->second).getObj()->print();
                              }
                        }
                        else { (iter2->second).getObj()->print(); }
                        break;
                  }
                  case 2:
                  {
                        cout << "\nEnter Spell Class: "; cin >> choice;
                        auto iter2 = spellClassClassIndex.find(choice);
                        //printSpellHeader();
                        if (spellClassClassIndex.count(choice) > 1)
                        {
                              auto iter = spellClassClassIndex.equal_range(choice);
                              for (; iter2 != iter.second; ++iter2)
                              {
                                    (iter2->second).getObj()->print();
                              }
                        }
                        else { (iter2->second).getObj()->print(); }
                        break;
                  }
                  case 3:
                  {
                        cout << "\nEnter Spell Type: "; cin >> choice;
                        auto iter2 = spellTypeTypeIndex.find(choice);
                        //printSpellHeader();
                        if (spellTypeTypeIndex.count(choice) > 1)
                        {
                              auto iter = spellTypeTypeIndex.equal_range(choice);
                              for (; iter2 != iter.second; ++iter2)
                              {
                                    (iter2->second).getObj()->print();
                              }
                        }
                        else { (iter2->second).getObj()->print(); }
                        break;
                  }
                  case 4:
                  {
                        cout << "\nEnter the Spell Level: "; cin >> choice;
                        auto iter2 = spellClassLvlIndex.find(choice);
                        //printSpellHeader();
                        if (spellClassLvlIndex.count(choice) > 1)
                        {
                              auto iter = spellClassLvlIndex.equal_range(choice);
                              for (; iter2 != iter.second; ++iter2)
                              {
                                    (iter2->second).getObj()->print();
                              }
                        }
                        else { (iter2->second).getObj()->print(); }
                        break;
                  }
                  case 5:
                  {
                        cout << "\nEnter the Player Name: "; cin >> choice;
                        auto iter2 = playerNameIndex.find(choice);
                        if (playerNameIndex.count(choice) > 1)
                        {
                              auto iter = playerNameIndex.equal_range(choice);
                              for (; iter2 != iter.second; ++iter2)
                              {
                                    (iter2->second).getObj()->print();
                              }
                        }
                        else { (iter2->second).getObj()->print(); }
                        break;
                  }
                  case 6:
                  {
                        cout << "\nEnter Class: "; cin >> choice;
                        auto iter2 = playerClassIndex.find(choice);
                        if (playerClassIndex.count(choice) > 1)
                        {
                              auto iter = playerClassIndex.equal_range(choice);
                              for (; iter2 != iter.second; ++iter2)
                              {
                                    (iter2->second).getObj()->print();
                              }
                        }
                        else { (iter2->second).getObj()->print(); }
                        break;
                  }
                  case 7:
                  {
                        cout << "\nEnter the Player's Max Level: "; cin >> choice;
                        auto iter2 = playerLvlIndex.find(choice);
                        if (playerLvlIndex.count(choice) > 1)
                        {
                              auto iter = playerLvlIndex.equal_range(choice);
                              for (; iter2 != iter.second; ++iter2)
                              {
                                    (iter2->second).getObj()->print();
                              }
                        }
                        else { (iter2->second).getObj()->print();; }
                        break;
                  }
                  //option for join operation
                  case 8:
                  {
                        int iChoice, jChoice;
                        cout << "1 - Spell Type Info\n";
                        cout << "2 - Spell Class Info\n";
                        cout << "3 - Player Info\n";

                        cout << "\nEnter 1st table: "; cin >> iChoice;
                        cout << "\nEnter table to join with " << iChoice << ": ";
                        cin >> jChoice;
                        switch (iChoice)
                        {
                              case 1:
                                    switch (jChoice)
                                    {
                                          case 1:
                                                join(spellTypeList, spellClassList); goto end; break;
                                          case 2:
                                                join(spellTypeList, spellClassList); goto end; break;
                                          case 3:
                                                join(spellTypeList, playerList);     goto end; break;
                                          default: break;
                                    }
                              case 2:
                                    switch (jChoice)
                                    {
                                          case 1:
                                                join(spellClassList, spellTypeList);  goto end; break;
                                          case 2:
                                                join(spellClassList, spellClassList); goto end; break;
                                          case 3:
                                                join(spellClassList, playerList);     goto end; break;
                                          default: break;
                                    }
                              case 3:
                                    switch (jChoice)
                                    {
                                          case 1:
                                                join(playerList, spellTypeList);  goto end; break;
                                          case 2:
                                                join(playerList, spellClassList); goto end; break;
                                          case 3:
                                                join(playerList, playerList);     goto end; break;
                                          default: break;
                                    }
                              default: break;
                        }
                  }
            }
            end:
            cout << "\n\nAnother Search (y/n)?: "; cin >> userResponse;
      } while (userResponse == 'y');

      return 0;
      
}