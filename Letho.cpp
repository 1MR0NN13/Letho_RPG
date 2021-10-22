#include <iostream>
using namespace std;

class Player
{

    private:

    int health = 100;
    int xp = 0;
    int level = 1;
    int attackDamage = 20;
    int additionalDamage = 0;
    int healingCapacity;
  

    void generateRandomAdditionalDamage()
    {
      int additionalDamageMin = 5 ;
      int additionalDamageMax = 15;
     
      srand(time(0));
      additionalDamage = (rand() % (additionalDamageMax - additionalDamageMin + 1) + additionalDamageMin);

      if (additionalDamage >= 13) {
        //crit chance
        //show Crit chance UI
      }

    }

    void displayPlayerInfo()
    {
      cout<<"\nHi my name is Letho! We need to save princess and get her back"<<endl;
      cout<<"Here are some stats that might be useful for you going ahead"<<endl;
      cout<<"\nLetho's Health: "<<health;
      cout<<"\n__________________________________\n";
      cout<<"Letho's XP: "<<xp;
      cout<<"\n__________________________________\n";
      cout<<"Letho's Level: "<<level;
      cout<<"\n__________________________________\n";
      cout<<"Letho's Attack Damage: "<<attackDamage;
      cout<<"\n__________________________________\n";
      cout<<"Letho's Addtional Damage: 5 to 15";
      cout<<"\n__________________________________\n";
      cout<<"Letho's Healing Capacity: 10 to 20";
    }

    public:
    Player()
    {
      displayPlayerInfo();
    }

    int GetHealth()
    {
      return health;
    }

    int GiveDamage()
    {
      generateRandomAdditionalDamage();
      int totalDamage = attackDamage + additionalDamage + xp + level;
      xp ++;
      level++; 
       
      cout<<"\nLetho Dealt "<<attackDamage<<" Base Damage, "<<additionalDamage<<" additional Damage and "<<(xp+level)<<" level up damage to Hollow Knight!"<<endl;
      cout<<"Total Damage Dealt: "<<totalDamage;

      return totalDamage;
    }
    
    void TakeDamage(int damageRecieved)
    {
      health = health - damageRecieved;
      
      if(health > 0)
      {
      cout<<"\nLetho's Health After recieving Damage: "<<health<<endl;
      }
      else
      {
        cout<<"\nHollow Knight landed final blow to Letho!"<<endl;
        cout<<"Damage Given: "<<damageRecieved<<endl;
        cout<<"Letho's Health After recieving Damage: 00"<<endl;
        cout<<"Our great warrior sacrificed himself for the kingdom"<<endl;
        cout<<"Game Over.....:( \nThanks for playing Letho!";
      }
    }

    void Heal()
    {
      int minHealCapacity = 10;
      int maxHealCapacity = 20; 

      srand(time(0));
      int randomHeal = (rand()% (maxHealCapacity - minHealCapacity + 1 ) + minHealCapacity);

      health = health + randomHeal;

     cout<<"Letho Healed by:"<<randomHeal<<endl;
     cout<<"Health after healing:"<<health<<endl;

    }
};

class Enemy
{
  private:

  int hp = 100;
  int xp = 4;
  int lv = 3;
  int attackDamage = 15;
  int additionalDamage;
  int healCap;

  void generateRandomAdditionalDamage() 
  {
    int addedDmgMin = 10;
    int addedDmgMax = 25;

    srand(time(0));
    additionalDamage = (rand() % (addedDmgMax - addedDmgMin + 1) + addedDmgMin);

  }

  void displayEnemyInfo()
  {
    cout<<"\nHail my name! For I am the Hollow Knight! The Archduke of Darkness!!!\nTo this unholy night, Princess Barbara shall give herself to me and my might!"<<endl;
    cout<<"Here are some stats that might be useful for you going ahead"<<endl;
    cout<<"\nHollow Knight's Health: "<<hp;
    cout<<"\n__________________________________\n";
    cout<<"Hollow Knight's XP: "<<xp;
    cout<<"\n__________________________________\n";
    
    cout<<"Hollow Knight's Attack Damage: "<<attackDamage;
    cout<<"\n__________________________________\n";
    cout<<"Hollow Knight's Addtional Damage: 10 to 25";
    cout<<"\n__________________________________\n";
    cout<<"Hollow Knight's Healing Capacity: 10 to 20";
  }

  public:
  
  Enemy()
  {
    displayEnemyInfo();
  }

  int GetHealth()
    {
      return hp;
    }

    int GiveDamage()
    {
      generateRandomAdditionalDamage();
      int totalDamage = attackDamage + additionalDamage + xp; 
      xp += 2;
      
       
      cout<<"\nHollow Knight Dealt "<<attackDamage<<" Base Damage and "<<additionalDamage<<" additional Damage to Letho!"<<endl;
      cout<<"Total Damage Dealt: "<<totalDamage;

      return totalDamage;
    }
    
    void TakeDamage(int damageReceived)
    {
      hp -= damageReceived;
      
      if(hp > 0)
      {
      cout<<"\nHollow Knight's Health After recieving Damage: "<<hp<<endl;
      }
      else
      {
        cout<<"\nLetho landed final blow to Hollow Knight!"<<endl;
        cout<<"Damage Given: "<<damageReceived<<endl;
        cout<<"Hollow Knight's Health After recieving Damage: 00"<<endl;
        cout<<"Our great warrior Letho vanquished the immortal Hollow Knight and successfully rescued the damsel in distress!!!"<<endl;
        cout<<"You Win..... :D \nThanks for playing Letho!";
      }
    }

    void Heal()
    {
      int minHealCapacity = 10;
      int maxHealCapacity = 20; 

      srand(time(0));
      int randomHeal = (rand()% (maxHealCapacity - minHealCapacity + 1 ) + minHealCapacity);

      hp += randomHeal;

     cout<<"Hollow Knight Healed by:"<<randomHeal<<endl;
     cout<<"Health after healing:"<<hp<<endl;


    }
};


void gameStory()
{
    system("clear");
    cout<<"\n__________________________________\n";
    cout<<"| Letho : A true Warrior |";
    cout<<"\n__________________________________\n";
    cout<<"\nOnce upon a time, there was a kingdom full of happiness. The king named Garelt had a beautiful princess named Barbara."<<endl;
    cout<<"\n__________________________________\n";
    cout<<"\nUnfortunately, on one evil day, the Hollow Knight kidnapped Barbara.\nNow the entire kingdom is at stake. Hollow Knight is a ruler of the dark world."; 
    cout<<"\n__________________________________\n";
}

void GameLoop(Player player, Enemy enemy)
{
  char gamePlayOptions;
  do
  {
    cout<<"\n__________________________________\n";
    cout<<"__________________________________\n\n";
    cout<<"\nPress A to attack Hollow Knight or Press H to heal yourself"<<endl;
    cin >> gamePlayOptions;
    system("clear");
    cout<<"\n__________________________________\n";
    cout<<"__________________________________\n";

    if (gamePlayOptions == 'a' || gamePlayOptions == 'A')
    {
      enemy.TakeDamage(player.GiveDamage());

      if (player.GetHealth() > 0 && enemy.GetHealth() > 0)
        player.TakeDamage(enemy.GiveDamage());
    }

    else if (gamePlayOptions == 'h' || gamePlayOptions == 'H')
    {
      if (player.GetHealth() < enemy.GetHealth())      
      {
        player.Heal();
      }
      else
        cout<<"**!!Healing Potion Inaccessible!!**"<<endl;
    }

    else
    {
      cout<<"Invalid Input! , please give valid input"<<endl;
    }
  } while(player.GetHealth() > 0 && enemy.GetHealth() > 0);
} 

int main() 
{
   gameStory();
  
  //*******Covered Till Part-2**************

  char startGame, gamePlayControls;
  do
  {
      cout<<"\n\nPress S to start the game and any other key to exit."<<endl;
      cin>>startGame;

      if(startGame == 's' || startGame == 'S')
      {
        //*******Covered Till Part-2**************
        system("clear");
        // Task: Create Object of Enemy Class
        Enemy enemy;
        // Task: Create Object of Player Class
        Player player;
        GameLoop(player, enemy);
      }
      else
      {
       cout<<"Thanks for playing Letho!"<<endl;
      }
  } while(startGame == 's' || startGame == 'S');
}