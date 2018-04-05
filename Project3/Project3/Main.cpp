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
#include<array>
using namespace std;


//tuples from data2.txt
class SpellClass
{
      private:
      
            SpellClass();
            array<string, 3>  attr = { "SpellName", "Class", "Level" };
            string            objName = "SpellClass";
            string            spName;
            string            pClass;
            string            lvl;

      public:

            SpellClass(string n, string c, string l)
            {
                  spName  = n;
                  pClass  = c;
                  lvl     = l;
            }
            string           getName()  { return spName; } 
            string           getClass() { return pClass; }
            string           getLvl()   { return lvl;    }
            array<string,3>  getAttr()  { return attr;   }
            SpellClass*      getThis()  { return this;   }
            void print()
            {
                  cout  << left << "\t" << setw(20) << spName;
                  cout  << "" << setw(15) << pClass;
                  cout  << "Lvl " << setw(10) << lvl;
            }
            void printExcept(string x)
            {
                  if (x == "SpellName")
                        cout << "\t" << left << setw(10) << pClass  << "Lvl: " << lvl;
                  if (x == "Class")
                        cout << "\t" << left << setw(15) << spName  << "Lvl: " << lvl;
                  if (x == "Level")
                        cout << "\t" << left << setw(15) << spName << setw(15) << pClass;
            }
            string printName(string x)
            {
                  if (x == "SpellName") { return spName; }
                  if (x == "Class"    ) { return pClass; }
                  if (x == "Level"    ) { return lvl;    }

                  return "\nInvalid Input for SpellClass::printName";
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
            string      name;
            SpellClass* classObj;

      public:

            SpellClassName(string n, SpellClass* s)
            {
                  name     = n;
                  classObj = s;
            }
            string          getName() { return name;     }
            SpellClass*     getObj()  { return classObj; }
            SpellClassName* getThis() { return this;     } 
            void            print()   { cout << name;    }
};

//for spell class index
//-------------------------------------------------------
class SpellClassClass
{
      private:

            SpellClassClass();
            string      sClass;
            SpellClass* classObj;

      public:

            SpellClassClass(string c, SpellClass* s)
            {
                  sClass   = c;
                  classObj = s;
            }
            SpellClassClass* getThis()  { return this;     }
            string           getClass() { return sClass;   }
            SpellClass*      getObj()   { return classObj; }
            void             print()    { cout << sClass;  }
};

//for spell lvl index
//-------------------------------------------------------
class SpellClassLvl
{
      private:

            SpellClassLvl();
            string      lvl;
            SpellClass* classObj;

      public:

            SpellClassLvl(string l, SpellClass* s)
            {
                  lvl      = l;
                  classObj = s;
            }
            SpellClassLvl* getThis() { return this;     }
            string         getLvl()  { return lvl;      }
            SpellClass*    getObj()  { return classObj; }
            void print()             { cout << lvl;     }
};

//tuples from data3.txt
//-------------------------------------------------------
class SpellType
{
      private:

            SpellType();
            array<string, 2> attr = { "SpellName", "SpellType" };
            string objName = "SpellType";
            string spName;
            string spType;

      public:

            SpellType(string s, string t)
            {
                  spName  = s;
                  spType  = t;
            }
            string           getName()  { return spName; }
            string           getType()  { return spType; }
            array<string,2>  getAttr()  { return attr;   }
            void print()
            {
                  cout  << left << "\t" << setw(15) << spName;
                  cout  << spType;
            }
            void printExcept(string x)
            {
                  if (x == "SpellName")
                        cout << "\t" << left << setw(20) << spType;
                  if (x == "SpellType")
                        cout << "\t" << left << setw(20) << spName;
            }
            string printName(string x)
            {
                  if (x == "SpellName") { return spName; }
                  if (x == "Class") { return spType; }

                  return "\nInvalid Input for SpellType::printName";
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
            string     name;
            SpellType* classObj;

      public:

            SpellTypeName(string n, SpellType* s)
            {
                  name     = n;
                  classObj = s;
            }
            string     getName() { return name;     }
            SpellType* getObj()  { return classObj; }   
            void print() { cout << name; }
};

//for spellType type index
//-------------------------------------------------------
class SpellTypeType
{
      private:

            SpellTypeType();
            string     type;
            SpellType* classObj;

      public:

            SpellTypeType(string t, SpellType* s)
            {
                  type     = t;
                  classObj = s;
            }
            string     getType() { return type;     }
            SpellType* getObj()  { return classObj; }
            void print() { cout << type; }
};

//tuples from data1.txt
//-------------------------------------------------------
class Player
{
private:

            Player();
            array<string, 3> attr = { "PlayerName", "Class", "Level" };
            string objName = "Player";
            string plName;
            string pClass;
            string lvl;

      public:

            Player(string n, string c, string m)
            {
                  plName  = n;
                  pClass  = c;
                  lvl     = m;
            }
            string           getName()   { return plName; }
            string           getClass()  { return pClass; }
            string           getMaxLvl() { return lvl;    }
            array<string, 3> getAttr()   { return attr;   }
            void print()
            {
                  cout  << left    << "\t"     << setw(20) ;
                  cout  << plName  << setw(20) << pClass;
                  cout  << "Lvl "  << setw(20) << lvl;
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
            string printName(string x)
            {
                  if (x == "SpellName") { return plName; }
                  if (x == "Class"    ) { return pClass; }
                  if (x == "Level"    ) { return lvl;    }

                  return "\nInvalid Input for Player::printName";
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
            string  name;
            Player* classObj;

      public:

            PlayerName(string s, Player* p)
            {
                  name     = s;
                  classObj = p;
            }
            string  getName() { return name;     }
            Player* getObj()  { return classObj; }
            void print() { cout << name; }
};

//for Player class index
//-------------------------------------------------------
class PlayerClass
{
      private:

            PlayerClass();
            string  pClass;
            Player* classObj;

      public:

            PlayerClass(string s, Player* p)
            {
                  pClass   = s;
                  classObj = p;
            }
            string  getClass() { return pClass;   }
            Player* getObj()   { return classObj; }
            void print() { cout << pClass; }
};

//for Player level index
//-------------------------------------------------------
class PlayerLvl
{
      private:

            PlayerLvl();
            string  lvl;
            Player* classObj;

      public:

            PlayerLvl(string s, Player* p)
            {
                  lvl = s;
                  classObj = p;
            }
            string  getLvl() { return lvl;      }
            Player* getObj() { return classObj; }
            void print() { lvl; }
};

//template for join
template <typename L, typename R>
void join(L &firstTable, R &secondTable);

//template function for Project
template <typename L, typename S>
void projection(L &table, S &column);

//template function for Select
template <typename L, typename R, typename D, typename F>
void select(L &table, R &nameIndex, D &classIndex, F &lvlIndex);

//template function for Select (overload)
template <typename L, typename R, typename D>
void select(L &table, R &nameIndex, D &typeIndex);



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


pair<SpellTypeNameIndex, SpellTypeTypeIndex> createSpellTypeIndex(vector<SpellType> &tmpVec);
tuple<PlayerNameIndex, PlayerClassIndex, PlayerLvlIndex> createPlayerIndex(vector<Player> &tmpVec);
tuple<SpellClassNameIndex, PlayerClassIndex, PlayerLvlIndex> createSpellClassIndex(vector<SpellClassSet> &tmpVec);

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
      inFile.close();

      //create Index for each attribute in Player table
      //unpack tuple into the three Index hashtables
      tie(playerNameIndex, playerClassIndex, playerLvlIndex) = createPlayerIndex(playerList);

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
      
      //sort vector
      sort(spellClassList.begin(), spellClassList.end());
      //create index objects and populate the associated hash tables
      for (auto i = 0; i < spellClassList.size()-1; ++i)
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
      
      //sort vector
      sort(spellTypeList.begin(), spellTypeList.end());
      //create index object and populate the associated hash tables
      for (auto i = 0; i < spellTypeList.size()-1; ++i)
      {
            SpellTypeName  tmpTn (spellTypeList[i].getName(),&spellTypeList[i]);
            SpellTypeType  tmpTT (spellTypeList[i].getType(),&spellTypeList[i]);

            spellTypeNameIndex.insert(make_pair(spellTypeList[i].getName(), tmpTn));
            spellTypeTypeIndex.insert(make_pair(spellTypeList[i].getType(), tmpTT));
      }

      char userResponse;
      // MAIN MENU
      do
      {
            string choice;
            int    menuChoice;
            cout << "\n1 - Selection (also works as search)\n";
            cout << "2 - Project\n";
            cout << "3 - Join\n";

            cout << "\nEnter 1-3: "; cin >> menuChoice;

            switch (menuChoice)
            {
                  case 1:
                  {
                        int iChoice;
                        
                        cout << "\n1 - Spell Type Info\n";
                        cout << "2 - Spell Class Info\n";
                        cout << "3 - Player Info\n";
                        cout << "\nEnter table to select from: "; cin >> iChoice;                       
                        
                        if(iChoice == 1) select(spellTypeList, spellTypeNameIndex, spellTypeTypeIndex);
                        if(iChoice == 2) select(spellClassList, spellClassNameIndex, spellClassClassIndex, spellClassLvlIndex);
                        if(iChoice == 3) select(playerList, playerNameIndex, playerClassIndex, playerLvlIndex);

                        break;
                  }
                  case 2:
                  {
                        int    choice2;
                        string choice3;
                        
                        cout << "\n1 - SpellName";
                        cout << "\n2 - Class";
                        cout << "\n3 - Level";
                        cout << "\n\nEnter attribute to project: "; cin >> choice2;
                        switch (choice2)
                        {
                              if      (choice2 == 1) choice3 = "SpellName"; 
                              else if (choice2 == 2) choice3 = "Class"; 
                              else if (choice2 == 3) choice3 = "Level"; 
                              
                              else cout << "\nNot a valid option!";
                        }
                        //projection(spellClassList, choice3); break;
                  }
                  case 3:
                  {
                        int iChoice, jChoice;
                        cout << "1 - Spell Type Info\n";
                        cout << "2 - Spell Class Info\n";
                        cout << "3 - Player Info\n";

                        cout << "\nEnter 1st table: "; cin >> iChoice;
                        cout << "\nEnter table to join with " << iChoice << ": ";
                        cin >> jChoice;
                  }
            }
            cout << "\n\nAnother Search (y/n)?: "; cin >> userResponse;
      } while (userResponse == 'y');

      return 0;
}

/*pair<SpellTypeNameIndex, SpellTypeTypeIndex> createSpellTypeIndex(vector<SpellType> &tmpVec)
{

}*/
tuple<PlayerNameIndex, PlayerClassIndex, PlayerLvlIndex> createPlayerIndex(vector<Player> &tmpVec)
{
      PlayerNameIndex  tmpName;
      PlayerClassIndex tmpClass;
      PlayerLvlIndex   tmpLvl;

      sort(tmpVec.begin(), tmpVec.end());
      //create index objects and populate the associated hash tables
      //hash key is the string name, class, or level
      for (auto i = 0; i < tmpVec.size() - 1; ++i)
      {
            PlayerName   tmpP(tmpVec[i].getName(), &tmpVec[i]);
            PlayerClass  tmpCl(tmpVec[i].getClass(), &tmpVec[i]);
            PlayerLvl    tmpLv(tmpVec[i].getMaxLvl(), &tmpVec[i]);

            tmpName.insert(make_pair(tmpVec[i].getName(), tmpP));
            tmpClass.insert(make_pair(tmpVec[i].getClass(), tmpCl));
            tmpLvl.insert(make_pair(tmpVec[i].getMaxLvl(), tmpLv));
      }
      return make_tuple(tmpName, tmpClass, tmpLvl);
}
/*tuple<SpellClassNameIndex, PlayerClassIndex, PlayerLvlIndex> createSpellClassIndex(vector<SpellClassSet> &tmpVec)
{

}*/

//selection function 
template <typename L, typename R, typename D>
void select(L &table, R &nameIndex, D &typeIndex)
{
      int response;
      vector<string> choices;
      for (auto iter : table)
      {
            cout << "\n\n";
            for (int i = 0; i < iter.getAttr().size(); ++i)
            {
                  cout << i + 1 << " - " << iter.getAttr()[i] << endl;
                  choices.push_back(iter.getAttr()[i]);
            } break;
      }
      cout << "\nEnter what attribute to select for: "; cin >> response;
      switch (response)
      {
            case 1:
            {
                  vector<string> values;
                  string tmp;
                  cout << "\nEnter specific values separated by a space (followed by a 'c' to continue): ";
                  cin >> tmp;
                  while (tmp != "c")
                  {
                        values.push_back(tmp);
                        cin >> tmp;
                  }
                  if (values.size() == 0)
                  {
                        for (auto iter : table)
                        {
                              iter.print();
                        } return;
                  }
                  for (int i = 0; i < values.size(); ++i)
                  {
                        auto iter = nameIndex.find(values[i]);
                        for (int j = 0; j < nameIndex.count(values[i]); ++j)
                        {
                              cout << endl;
                              iter->second.getObj()->print();
                              ++iter;
                        }
                  } break;
            }
            case 2:
            {
                  vector<string> values;
                  string tmp;
                  cout << "Enter specific values separated by a space (followed by a 'c' to continue)";
                  cin >> tmp;
                  while (tmp != "c")
                  {
                        values.push_back(tmp);
                        cin >> tmp;
                  }
                  if (values.size() == 0)
                  {
                        for (auto iter : table) { iter.print(); } return;
                  }
                  for (int i = 0; i < values.size(); ++i)
                  {
                        auto iter = typeIndex.find(values[i]);
                        for (int j = 0; j < typeIndex.count(values[i]); ++j)
                        {
                              cout << endl;
                              iter->second.getObj()->print();
                              ++iter;
                        }
                  } break;
            }
      }
}
//selection function (overload)
template <typename L, typename R, typename D, typename F>
void select(L &table, R &nameIndex, D &classIndex, F &lvlIndex)
{
      int response;
      vector<string> choices;
      for (auto iter : table)
      {
            cout << "\n\n";
            for (int i = 0; i < iter.getAttr().size(); ++i)
            {
                  cout << i + 1 << " - " << iter.getAttr()[i] << endl;
                  choices.push_back(iter.getAttr()[i]);
            } break;
      }
      cout << "\nEnter what attribute to select for: "; cin >> response;
      switch (response)
      {
            case 1:
            {
                  vector<string> values;
                  string tmp;
                  cout << "\nEnter specific names separated by a space (followed by a 'c' to continue): ";
                  cin >> tmp;
                  while (tmp != "c")
                  {
                        values.push_back(tmp);
                        cin >> tmp;
                  }
                  if (values.size() == 0)
                  {
                        for (auto iter : table) { iter.print(); } return;
                  }
                  for (int i = 0; i < values.size(); ++i)
                  {
                        auto iter = nameIndex.find(values[i]);
                        for (int j = 0; j < nameIndex.count(values[i]); ++j)
                        {
                              cout << endl;
                              iter->second.getObj()->print();
                              ++iter;
                        }
                  } break;
            }
            case 2:
            {
                  vector<string> values;
                  string tmp;
                  cout << "\nEnter specific classes separated by a space (followed by a 'c' to continue): ";
                  cin >> tmp;
                  while (tmp != "c")
                  {
                        values.push_back(tmp);
                        cin >> tmp;
                  }
                  if (values.size() == 0)
                  {
                        for (auto iter : table) { iter.print(); } return;
                  }
                  for (int i = 0; i < values.size(); ++i)
                  {
                        auto iter = classIndex.find(values[i]);
                        for (int j = 0; j < classIndex.count(values[i]); ++j)
                        {
                              cout << endl;
                              iter->second.getObj()->print();
                              ++iter;
                        }
                  } break;
            }
            case 3:
            {
                  int choice2;
                  string lvl;
                  cout << "\n\t1 - >=";
                  cout << "\n\t2 - <=";
                  cout << "\n\t3 - ==";
                  cout << "\n\nEnter operation (1-3): "; cin >> choice2;
                  cout << "\nEnter Level: "; cin >> lvl;
                  if (choice2 == 1)
                  {
                        for (auto iter : lvlIndex)
                        {
                              if (stoi(iter.first) >= stoi(lvl))
                              {
                                    cout << endl;
                                    iter.second.getObj()->print();
                              }
                        } return;
                  }
                  else if (choice2 == 2)
                  {
                        for (auto iter : lvlIndex)
                        {
                              if (stoi(iter.first) <= stoi(lvl))
                              {
                                    cout << endl;
                                    iter.second.getObj()->print();
                              }
                        } return;
                  }
                  else if (choice2 == 3)
                  {
                        for (auto iter : lvlIndex)
                        {
                              if (stoi(iter.first) == stoi(lvl))
                              {
                                    cout << endl;
                                    iter.second.getObj()->print();
                              }
                        } return;
                  }
            }
      }
}
//projection function
template <typename L, typename S>
void projection(L &table, S &column)
{
      set<S> stringSet;
      char   response;

      //ask if user wants duplicate entries in there projection
      cout << "\nPrint without duplicates? (y/n): "; cin >> response;

      //print without duplicates
      if (response == 'y' || response == 'Y')
      {
            cout << endl;
            for (auto iter : table) { stringSet.insert(iter.printName(column)); }
            for (auto iter : stringSet) { cout << iter << endl; }
            return;
      }
      //print with duplicates
      else if (response == 'n' || response == 'N')
      {
            cout << endl;
            for (auto iter : table)
            {
                  cout << endl;
                  cout << iter.printName(column);
            } return;
      }
      else { cout << "\nInvalid input."; return; }
}
//join function
template <typename L, typename R>
void join(L &firstTable, R &secondTable)
{
      string overlap;
      int    firstTableSize;
      int    secondTableSize;
      //search for overlapping columns (only search first object of first and second Table)
      for (auto iter : firstTable)
      {
            for (auto iter2 : secondTable)
            {
                  for (int i = 0; i < iter.second.getObj()->getAttr().size(); ++i)
                  {
                        if (iter.second.getObj()->getAttr()[i] == iter2.second.getObj()->getAttr()[i])
                        {
                              firstTableSize   = iter.second.getObj()->getAttr().size();
                              secondTableSize  = iter2.second.getObj()->getAttr().size();
                              overlap          = iter.second.getObj()->getAttr()[i];
                              break;
                        }
                  } break;
            } break;
      }
      for (auto iter : firstTable)
      {
            try
            {
                  int count;

                  count = secondTable.count(iter.first);
                  auto key = secondTable.find(iter.first);
                  cout << endl << endl;
                  iter.second.getObj()->print();
                  cout << endl;
                  for (int i = 0; i < count; ++i)
                  {
                        cout << "\n\t";
                        key->second.getObj()->printExcept(overlap);
                        ++key;
                  }
            }
            catch (exception& e) { continue; }
      }
}

template <typename A, typename B, typename C>
void join(A &firstTable, B &secondTable, C &thridTable)
{

}

