#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>

//CS102
//Game Creation Project
//Group 5
//Text Turn RPG

typedef struct
{
	char name[100];
	int gold;
	int attack;
	int defense;
	int heart;
	int healthpoint;
	int heal;
}Character;
typedef struct
{
	int hp;
	int max_hp;
	int attack;
	int gold_drop;
}Monster;

int ScanInput();
void ClearScreen();
void delay(float number_of_seconds);
void NameColor();
void SpeechBox();
void MonsterSoundColor();
void EndTextColor();
void Slime();
void Wolf();
void Skeleton();
void Troll();
void Orc();
void Golem();
void Kong();
void Dragon();
void FullScreen();
void GameTitle();
void TitleChoice();
void PrintInfo(Character player ,int wrong_chioce);
Character CharacterName(Character player);

int main()
{	
	srand(time(NULL));

	CONSOLE_SCREEN_BUFFER_INFO csbi;
    
	int max_columns;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    max_columns = csbi.dwSize.X;

	char PowerBar_E[2][20] = {{" ________________\n"},{"|________________|"}};

	Character player;

	Monster slime;
		slime.attack = 5;
		slime.hp = 50;
		slime.max_hp = 50;
		slime.gold_drop = 25 + ((rand() % 10) - (rand() % 10));

	Monster wolf;
		wolf.attack = 15;
		wolf.hp = 100;
		wolf.max_hp = 100;
		wolf.gold_drop = 50 + ((rand() % 10) - (rand() % 10));

	Monster skeleton;
		skeleton.attack = 30;
		skeleton.hp = 75;
		skeleton.max_hp = 75;
		skeleton.gold_drop = 50 + ((rand() % 10) - (rand() % 10));
	
	Monster orc;
		orc.attack = 50;
		orc.hp = 150;
		orc.max_hp = 150;
		orc.gold_drop = 125 + ((rand() % 10) - (rand() % 10));
	
	Monster troll;
		troll.attack = 75;
		troll.hp = 250;
		troll.max_hp = 250;
		troll.gold_drop = 200 + ((rand() % 20) - (rand() % 20));

	Monster golem;
		golem.attack = 75;
		golem.hp = 500;
		golem.max_hp = 500;
		golem.gold_drop = 450 + ((rand() % 30) - (rand() % 30));

	Monster kong;
		kong.attack = 100;
		kong.hp = 625;
		kong.max_hp = 625;
		kong.gold_drop = 700 + ((rand() % 30) - (rand() % 30));

	Monster dragon;
		dragon.attack = 200;
		dragon.hp = 1000;
		dragon.max_hp = 1000;
		dragon.gold_drop = 1000;

	int max_hp;
	int attack_damage, receive_damage, player_crit, monster_crit, monster_strong_attack, monster_count; 
	int game = 0, progress = 0, choice = 0, wrong_chioce = 0;
	double story = 0;

	ClearScreen();
	FullScreen();
	GameTitle();
	TitleChoice();
	player = CharacterName(player);

	story = rand() % 3;
	story += 1;
			
	while (game == 0)
	{
		while(story == 1) //Worrier start
		{
			ClearScreen();

			player.gold = 50;
			player.attack = 10;
			player.defense = 20;
			player.heart = 3;
			player.healthpoint = 200;
			player.heal = 30;

			max_hp = 200;
			
			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("<Worrier>\nYou are a skilled warrior who has attempted and failed numerous times to pass the knight exam. Then you give up and decide to become a mercenary instead in order to make a living. The fresh air on a new morning is the same as on any other day, but now you are not the same. Now you are a beginner mercenary.\n\n");
			printf("In the morning you decide to...\n");
			printf("1. Wake up and have a breakfast in the inn.\n2. Wake up and practice swordsmanship.\n3. Wake up and go exercise.\n4. Wake up and have some drinks while listening to other people talk.\n5. Wake up and go on an adventure.\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				story = 1.1;
				break;
			}
			else if(choice == 2)
			{
				story = 1.2;
				break;
			}
			else if(choice == 3)
			{
				story = 1.3;
				break;
			}
			else if(choice == 4)
			{
				story = 1.4;
				break;
			}
			else if(choice == 5)
			{
				story = 1.5;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}
            
            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 2) //Merchant start
		{
			ClearScreen();

			player.gold = 300;
			player.attack = 10;
			player.defense = 10;
			player.heart = 2;
			player.healthpoint = 100;
			player.heal = 30;

			max_hp = 100;

			PrintInfo(player, wrong_chioce);

			wrong_chioce = 0;

			printf("<Merchant>\nYou are an experienced merchant that roams all over every town. But nowadays, no one would like to buy anything from you. You spend so much time thinking about what happened but still have no clue. Finally, you decided to be an adventurer to make some money and continue living. Now you are a beginner adventurer.\n\n");
			printf("In the morning you decide to...\n");
			printf("1. Wake up and have a breakfast in the inn.\n2. Wake up and practice swordsmanship.\n3. Wake up and go exercise.\n4. Wake up and have some drinks while listening to other people talk.\n5. Wake up and go on an adventure.\n\n");
			printf("Type : ");

			choice = ScanInput();

			if(choice == 1)
			{
				story = 1.1;
				break;
			}
			else if(choice == 2)
			{
				story = 1.2;
				break;
			}
			else if(choice == 3)
			{
				story = 1.3;
				break;
			}
			else if(choice == 4)
			{
				story = 1.4;
				break;
			}
			else if(choice == 5)
			{
				story = 1.5;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 3) //Vagabond start
		{
			ClearScreen();

			player.gold = 50;
			player.attack = 20;
			player.defense = 10;
			player.heart = 4;
			player.healthpoint = 150;
			player.heal = 30;

			max_hp = 150;

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("<Vagabond>\nYou are a vagabond that roams around the town. You honed your skills at avoiding danger, surviving in the wild, and navigating wild animals, but now you want to pursue your dreams. So, you've decided to join an adventure guild in order to pursue your dream and make it come true. Now you are a beginner adventurer.\n\n");
			printf("In the morning you decide to...\n");
			printf("1. Wake up and have a breakfast in the inn.\n2. Wake up and practice swordsmanship.\n3. Wake up and go exercise.\n4. Wake up and have some drinks while listening to other people talk.\n5. Wake up and go on an adventure.\n\n");
			printf("Type : ");

			choice = ScanInput();

			if(choice == 1)
			{
				story = 1.1;
				break;
			}
			else if(choice == 2)
			{
				story = 1.2;
				break;
			}
			else if(choice == 3)
			{
				story = 1.3;
				break;
			}
			else if(choice == 4)
			{
				story = 1.4;
				break;
			}
			else if(choice == 5)
			{
				story = 1.5;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 1.1) //Have a good meal at starter inn
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("You have a very good meal and feel full and healty. It's time for an adventure.\n\n== Heart + 1 ==\n== Restore Health Point ==\n\n");
			printf("Type 1 to start an adventure\n\n");
			printf("Type : ");

			choice = ScanInput();

			if(choice == 1)
			{	
				player.heart += 1;
				player.healthpoint = max_hp;
				story = 2.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 1.2) //Practicing swordsmanship at starter inn
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);

			wrong_chioce = 0;

			printf("You've finished practicing swordsmanship. You feel like you know how to use a sword a little better. It's time for an adventure.\n\n== Attack + 1 ==\n\n");
			printf("Type 1 to start an adventure\n\n");
			printf("Type : ");

			choice = ScanInput();

			if(choice == 1)
			{	
				player.attack += 1;
				story = 2.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 1.3) //Do an exercise at starter inn
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);

			wrong_chioce = 0;

			printf("You've finished all the exercises. You can feel your muscles heating up. It's time for an adventure.\n\n== defense + 1 ==\n\n");
			printf("Type 1 to start an adventure\n\n");
			printf("Type : ");

			choice = ScanInput();

			if(choice == 1)
			{	
				player.defense += 1;
				story = 2.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 1.4) //Listen to other story at starter inn
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);

			wrong_chioce = 0;

			printf("You hear a fascinating story and want to learn more about it. So, you get up and join their conversation.\n\n== Unlock mini story==\n\n");
			printf("Type 1 to sit and listen to their story.\n\n");
			printf("Type : ");

			choice = ScanInput();

			if(choice == 1)
			{	
				story = 1.41;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 1.41) //Talk to other at starter inn
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);

			wrong_chioce = 0;

				SpeechBox();
			printf("\"Ah hahaha, did you eavesdrop our conversation? Well then, let's me ask you some adventurer knowlage. What is the most important thing for an adventurer?\"\n\n");
				EndTextColor();
			printf("You answer...\n");
			printf("1. Wealth.\n2. Dreams.\n3. Family.\n4. Strongest.\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{	
				story = 1.411;
				break;
			}
			else if(choice == 2)
			{
				story = 1.412;
				break;
			}
			else if(choice == 3)
			{
				story = 1.413;
				break;
			}
			else if(choice == 4)
			{
				story = 1.414;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 1.411) //Wealth answer
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);

			wrong_chioce = 0;

			printf("Your answer is to have wealth that can support you and your family until you die.\n\n");
				SpeechBox();
			printf("Woh, what an amazing little Billionaire! There's neither the correct nor the wrong choice. But I just want to know what your goal is. Here is your reward!!\n\n");
				EndTextColor();
			printf("== Gold + 50 ==\n\n");
			printf("Type 1 to start an adventure\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{	
				player.gold += 50;
				story = 2.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 1.412) //Dreams answer
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);

			wrong_chioce = 0;

			printf("Your answer is to achieve your dreams before you die.\n\n");
				SpeechBox();
			printf("Woh, what an amazing little Dreamer! There's neither the correct nor the wrong choice. But I just want to know what your goal is. Here is your reward!!\n\n");
				EndTextColor();
			printf("== Heart + 1 ==\n\n");
			printf("Type 1 to start an adventure\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{	
				player.heart += 1;
				story = 2.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 1.413) //Family answer
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);

			wrong_chioce = 0;

			printf("Your answer is to have a happy family life until you die.\n\n");
				SpeechBox();
			printf("Woh, what an amazing little Family maker! There's neither the correct nor the wrong choice. But I just want to know what your goal is. Here is your reward!!\n\n");
				EndTextColor();
			printf("== Defense + 1 ==\n\n");
			printf("Type 1 to start an adventure\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{	
				player.defense += 1;
				story = 2.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 1.414) //Strongest adventurer answer
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);

			wrong_chioce = 0;

			printf("Your answer is to be the strongest adventurer in history.\n\n");
				SpeechBox();
			printf("Woh, what an amazing little Fighter! There's neither the correct nor the wrong choice. But I just want to know what your goal is. Here is your reward!!\n\n");
				EndTextColor();
			printf("== Attack + 1 ==\n\n");
			printf("Type 1 to start an adventure\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{	
				player.attack += 1;
				story = 2.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 1.5) //Leave the town
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);

			wrong_chioce = 0;

			printf("You're leaving the town through the main entrance. Now it's time for an adventure.\n\n== Begin adventure ==\n\n");
			printf("Type 1 to start an adventure\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{	
				story = 2.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 2.0) //Found slime
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("At the edge of the forest. You hear a squishy sound and follow it. Then, you see a green slime that idling in front of you.\n\n");
			printf("You decide to....\n");
			printf("1. Attack it!!\n2. Pass by.\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				monster_count = 0;
				monster_strong_attack = 5;
				story = 2.1;
				break;
			}
			else if(choice == 2)
			{
				story = 2.2;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 2.1) //Fight slime
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			if((monster_strong_attack > 1) && (slime.hp > 0) && (player.healthpoint > 0))
			{
				printf("\"Beware of monster strong attack in %d turns.\"     ", monster_strong_attack);
			}
			else if((monster_strong_attack == 1) && (slime.hp > 0) && (player.healthpoint > 0))
			{
				printf("\"Beware of monster strong attack in next turns.\"     ");
			}

			if((monster_count >= 0) && (slime.hp > 0))
			{
				printf("\"Monster left : %d\"\n", monster_count + 1);
			}
			else
			{
				printf("\n");
			}

			if(player.healthpoint <= 0)
			{
				printf("You cannot defeat it and you decided to run.\n");
				delay(3);
				player.heart -= 1;
				player.healthpoint = max_hp;
				story = 2.2;
				break;
			}
			else if((slime.hp <= 0) && (monster_count > 0))
			{
				player.gold += slime.gold_drop;
				printf("You win the fight.\n\n== Gold + %d ==\n\n", slime.gold_drop);
				delay(3);
				monster_count -= 1;
				slime.hp = slime.max_hp;
				monster_strong_attack = 5;
				break;
			}
			else if((slime.hp <= 0) && (monster_count == 0))
			{
				player.gold += slime.gold_drop;
				printf("You win the fight.\n\n== Gold + %d ==\n\n", slime.gold_drop);
				delay(3);
				story = 3.0;
				break;
			}

			for(int j = 0; j < (max_columns /2) - 10; j++)
			{
				printf(" ");
			}

			printf("%s", PowerBar_E[0]);
			
			for(int j = 0; j < (max_columns /2) - 10; j++)
			{
				printf(" ");
			}

			printf("%s", PowerBar_E[1]);
			printf(" %d\n", slime.hp);
			
			Slime();

			printf("1. Attack.\n2. Defend.\n3. Heal.\n4. Escape.\n\n");
			printf("Type : ");

			choice = ScanInput();

			if(choice == 1)
			{
				monster_strong_attack -= 1;

				player_crit = rand() % 5;

				if(player_crit == 4)
				{
					attack_damage = slime.hp;
					slime.hp -= (player.attack + ((rand() % player.attack / 2) - (rand() % player.attack / 3))) * ((rand() % 2) + 2);
				
					printf("\nYour critical attack = \" %d \" damage.\n", attack_damage - slime.hp);
					delay(1.5);
				}
				else
				{
					attack_damage = slime.hp;
					slime.hp -= player.attack + ((rand() % player.attack / 2) - (rand() % player.attack / 3));
				
					printf("\nYour attack = \" %d \" damage.\n", attack_damage - slime.hp);
					delay(1.5);
				}

				monster_crit = rand() % 15;

				if(monster_strong_attack == 0 && slime.hp > 0)
				{
					monster_strong_attack = 5;

					receive_damage = player.healthpoint;
					player.healthpoint -= (((slime.attack) + ((rand() % slime.attack / 2) - (rand() % slime.attack / 3))) * 1.5) / (1 + (player.defense / 100));
					
					printf("Enemy strong attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if(monster_crit == 14 && slime.hp > 0)
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= (((slime.attack) + ((rand() % slime.attack / 2) - (rand() % slime.attack / 3))) * ((rand() % 2) + 2)) / (1 + (player.defense / 100));
					
					printf("Enemy critical attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if(slime.hp > 0)
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= ((slime.attack) + ((rand() % slime.attack / 2) - (rand() % slime.attack / 3))) / (1 + (player.defense / 100));
					
					printf("Enemy attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else
				{
					break;
				}
			}
			else if(choice == 2)
			{
				monster_strong_attack -= 1;

				monster_crit = rand() % 15;

				if(monster_strong_attack == 0 && slime.hp > 0)
				{
					monster_strong_attack = 5;

					receive_damage = player.healthpoint;
					player.healthpoint -= (((slime.attack) + ((rand() % slime.attack / 2) - (rand() % slime.attack / 3))) * 1.5) / (2 + (player.defense / 100));
					
					printf("Enemy strong attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if(monster_crit == 14 && slime.hp > 0)
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= (((slime.attack) + ((rand() % slime.attack / 2) - (rand() % slime.attack / 3))) * ((rand() % 2) + 2)) / (2 + (player.defense / 100));
					
					printf("Enemy critical attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if(slime.hp > 0)
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= ((slime.attack) + ((rand() % slime.attack / 2) - (rand() % slime.attack / 3))) / (2 + (player.defense / 100));
					
					printf("Enemy attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else
				{
					break;
				}
			}
			else if(choice == 3)
			{
				monster_strong_attack -= 1;

				player.healthpoint += player.heal;

				if(player.healthpoint >= max_hp)
				{
					player.healthpoint = max_hp;
				}
				
				printf("\nYou health restore = \" %d \" point.\n", player.heal);
				delay(1.5);

				monster_crit = rand() % 15;

				if(monster_strong_attack == 0 && slime.hp > 0)
				{
					monster_strong_attack = 5;

					receive_damage = player.healthpoint;
					player.healthpoint -= (((slime.attack) + ((rand() % slime.attack / 2) - (rand() % slime.attack / 3))) * 1.5) / (1 + (player.defense / 100));
					
					printf("Enemy strong attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if(monster_crit == 14 && slime.hp > 0)
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= (((slime.attack) + ((rand() % slime.attack / 2) - (rand() % slime.attack / 3))) * ((rand() % 2) + 2)) / (1 + (player.defense / 100));
					
					printf("Enemy critical attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if(slime.hp > 0)
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= ((slime.attack) + ((rand() % slime.attack / 2) - (rand() % slime.attack / 3))) / (1 + (player.defense / 100));
					
					printf("Enemy attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else
				{
					break;
				}
			}
			else if(choice == 4)
			{
				story = 2.2;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 2.2) //Pass by slime
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("That's not the the worst choice. Let's go to other place.\n\n");
			printf("Type 1 to continue.\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				story = 3.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 3.0) //Found mysterious shop
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("You see an old and mysterious shop, but it is filled with people in front of you.\n\n");
			printf("You decide to...\n");
			printf("1. Go and see what the shop has to sell.\n2. Pass by.\n\n");
			printf("Type : ");

			choice = ScanInput();

			if(choice == 1)
			{
				story = 3.1;
				break;
			}
			else if(choice == 2)
			{
				story = 4.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 3.1) //See what the shop has to sell
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;
			
			SpeechBox();
			printf("\"Hello Stanger!!! Welcome to our shop. What would you like to buy?\"\n\n");
				EndTextColor();
			printf("1. Small attack potion.\n\tPirce 50 gold\n\tAttack + 2\n2. Attack potion.\n\tPrice 100 gold\n\tAttack + 5\n3. Small defense potion.\n\tPrice 50 gold\n\tDefense + 2\n4. Defense potion.\n\tPrice 100 gold\n\tDefense + 5\n5. Healty potion.\n\tPrice 100 gold\n\tHealt Point + 50\n6. Recovery potion.\n\tPrice 100 gold\n\tRestore all health\n7.Exit the shop.\n\n");
			printf("Type : ");

			choice = ScanInput();

			if((choice == 1) && (player.gold >= 50))
			{
				printf("== Attack + 2 ==\n");
				delay(1.5);
				player.attack += 2;
				player.gold -= 50;
				break;
			}
			else if((choice == 1) && (player.gold < 50))
			{
				printf("not enough gold!!!\n");
				delay(1.5);
				break;
			}
			else if((choice == 2) && (player.gold >= 100))
			{
				printf("== Attack + 5 ==\n");
				delay(1.5);
				player.attack += 5;
				player.gold -= 100;
				break;
			}
			else if((choice == 2) && (player.gold < 100))
			{
				printf("not enough gold!!!\n");
				delay(1.5);
				break;
			}
			else if((choice == 3) && (player.gold >= 50))
			{
				printf("== Defense + 2 ==\n");
				delay(1.5);
				player.defense += 2;
				player.gold -= 50;
				break;
			}
			else if((choice == 3) && (player.gold < 50))
			{
				printf("not enough gold!!!\n");
				delay(1.5);
				break;
			}
			else if((choice == 4) && (player.gold >= 100))
			{
				printf("== Defense + 5 ==\n");
				delay(1.5);
				player.defense += 5;
				player.gold -= 100;
				break;
			}
			else if((choice == 4) && (player.gold < 100))
			{
				printf("not enough gold!!!\n");
				delay(1.5);
				break;
			}
			else if((choice == 5) && (player.gold >= 100))
			{
				printf("== Health Point + 50 ==\n");
				delay(1.5);
				player.healthpoint += 50;
				max_hp += 50;
				player.gold -= 100;
				break;
			}
			else if((choice == 5) && (player.gold < 100))
			{
				printf("not enough gold!!!\n");
				delay(1.5);
				break;
			}
			else if((choice == 6) && (player.gold >= 100) && (player.healthpoint < max_hp))
			{
				printf("== Restore all health ==\n");
				delay(1.5);
				player.healthpoint = max_hp;
				player.gold -= 100;
				break;
			}
			else if((choice == 6) && (player.gold >= 100) && (player.healthpoint = max_hp))
			{
				printf("You are already at full health. Do not waste money!!!\n");
				delay(1.5);
				break;
			}
			else if((choice == 6) && (player.gold < 100) && (player.healthpoint < max_hp))
			{
				printf("not enough gold!!!\n");
				delay(1.5);
				break;
			}
			else if(choice == 7)
			{
				story = 4.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

			if(player.heart == 0)
			{
				game = 1;
				break;
			}
		}
		while(story == 4.0) //Found two-way junction
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("In the middle of the forest, you see a two-way junction path. An oak tree is on the left, and a burned tree is on the right.\n\n");
			printf("You decide to....\n");
			printf("1. Take an oak tree path.\n2. Take a burned-tree path.\n3. Find other ways.\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				story = 4.1;
				break;
			}
			else if(choice == 2)
			{
				story = 4.2;
				break;
			}
			else if(choice == 3)
			{
				story = 4.3;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 4.1) //Take an oak tree path || Found two-way junction again
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("You decide to take an oak tree path. But when you walk 5 minutes further, you see a two-way junction again. This time, a birch tree is on the left, and a maple tree is on the right.\n\n");
			printf("You decide to....\n");
			printf("1. Take a birch tree path.\n2. Take a maple tree path.\n3. Go back to the previous path.\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				story = 4.11;
				break;
			}
			else if(choice == 2)
			{
				story = 4.12;
				break;
			}
			else if(choice == 3)
			{
				story = 4.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 4.11) //Take a birch tree path || See an old blacksmith house || Take ancient golden sword
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("You walk for about 5 minutes, and then you see an old blacksmith house. You decide to go in, look around, and find a shining golden sword. You pick it up, and your vision becomes blurred.\n\n");
			printf("Type 1 to continue.\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				story = 4.111;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
			
		}
		while(story == 4.111) //Receive ancient golden sword
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("You opened your eyes and saw the blue sky. Your right arm is glowing gold, resembling the sword from before. You're wondering what just happened. You were deep in thought when you sighed quietly. Then, you get up and look for a safe place to make a small campfire and spend the night.\n\n== receive ancient golden sword ==\n== Attack + 20 ==\n\n");
			printf("Type 1 to continue.\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				player.attack += 20;
				story = 5.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 4.12) //Take a maple tree path || Found dryad || Dryad question
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("You keep walking and walking until you almost collapse. Then you can hear some giggle noises from somewhere nearby. When you turn around to see what that noise is, your eyes catch up with the light ball that is floating around. The light ball then comes to a halt, revealing the body of a young girl with gold eyes and green hair. Her arm and leg wrap around with vines, and her body emits a little green light. She stares at you, then asks.\n\n");
				SpeechBox();
			printf("\"Can you guess who am I?\"\n\n");
				EndTextColor();
			printf("You answer her. She is....\n");
			printf("1. an Elf.\n2. a Fairy.\n3. a Dryad.\n4. You don't know.\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				story = 4.121;
				break;
			}
			else if(choice == 2)
			{
				story = 4.121;
				break;
			}
			else if(choice == 3)
			{
				story = 4.122;
				break;
			}
			else if(choice == 4)
			{
				story = 4.123;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 4.121) //Not correct but try || Dryad small gift
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
		
			wrong_chioce = 0;

			printf("She heard what you said and seemed disappointed. Then your vision is blurred, and you hear whispers.\n\n");
				SpeechBox();
			printf("\"Not correct.I'm a dryad, but considerate of your effort I will grant you some gift.\"\n");
				EndTextColor();
			printf("Type 1 to continue\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				story = 4.1211;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 4.1211) //Set up a camp || Recieve dryad small gift
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("You opened your eyes and saw the blue sky. You're wondering what just happened. You were deep in thought when you sighed quietly. Then, you get up and look for a safe place to make a small campfire and spend the night.\n\n== Restore Health Point ==\n== Receive 50 gold ==\n== Attack + 5\n== Defense + 5 ==\n\n");
			printf("Type 1 to continue.\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				player.healthpoint = max_hp;
				player.gold += 50;
				player.attack += 5;
				player.defense += 5;
				story = 5.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 4.122) //Correct || Dryad gift
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("She heard what you said and smile. Then your vision is blurred, and you hear whispers.\n\n");
				SpeechBox();
			printf("\"You are correct. I'm a dryad, and I'll give you a huge gift for your luck or your knowledge. Goodbye the chosen one.\"\n\n");
				EndTextColor();
			printf("Type 1 to continue\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				story = 4.1221;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 4.1221) //Set up a camp || Recieve dryad gift
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("You opened your eyes and saw the blue sky. You're wondering what just happened. You were deep in thought when you sighed quietly. Then, you get up and look for a safe place to make a small campfire and spend the night.\n\n== Restore Healt Point ==\n== Receive 200 gold ==\n== Attack + 10\n== Defense + 10 ==\n\n");
			printf("Type 1 to continue.\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				player.healthpoint = max_hp;
				player.gold += 200;
				player.attack += 10;
				player.defense += 10;
				story = 5.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 4.123) //Not correct and not try || Dryad curse
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("She heard what you said and seemed angry and disappointed. Then your vision is blurred, and you hear whispers.\n\n");
				SpeechBox();
			printf("\"Can't you at least try to guess? You've disappointed me so much. Just get out of my sight!!!\"\n");
				EndTextColor();
			printf("Type 1 to continue\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				story = 4.1231;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 4.1231) //Set up a camp || Recieve dryad curse
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("You opened your eyes and saw the blue sky. Your body felt weaker and limper. You're wondering what just happened. You were deep in thought when you sighed quietly. Then, you get up and look for a safe place to make a small campfire and spend the night.\n\n== Heart - 1 ==\n== Attack - 5 ==\n== Defense - 5 ==\n\n");
			printf("Type 1 to continue.\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
                player.heart -= 1;
				player.attack -= 5;
				player.defense -= 5;
				story = 5.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
            
		}
		while(story == 4.2) //Take a burned-tree path || Found a dragon far away
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("You decide to take a burned-tree path. You continue walking for a while until you hear an explosion far ahead, followed by the sound of a massive wing flapping and that sound slowly flying further away.\n\n");
			printf("Type 1 to continue.\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				story = 4.21;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}
            
            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 4.21) //Walking forward || See a small village
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("Your hand is trembling in fear, but your brave heart tells you to keep going. You take a deep breath and keep moving forward. It took some time to walk, but now you see a small village that was burned to the ground by a gigantic mysterious monster, and there's no one left that you can help.\n\n");
			printf("Type 1 to pray for them and pass by.\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				story = 4.211;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 4.211) //Set up a camp || Recieve brave heart
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("You walk through the village with a sad mind but a brave heart. You still seem puzzled about what happened to the village, but the sun is slowly going down. The orange-blue sky is telling you to go find someplace and rest for the day. So, you speed up and look for a safe place to make a small campfire and spend the night.\nWith your brave heart you defense has increse.\n== Defense + 5==\n\n");
			printf("Type 1 to continue.\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				player.defense += 5;
				story = 5.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 4.3) //Take a other way
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("You decide to take a other way. But no matter how much you walk, you still can't find the way out and somehow go back to the same spot in the same forest before you start walking.\n\n");
			printf("Type 1 to continue.\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				story = 4.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 5.0) //Found pack of wolves
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("The new morning has come. You open your eyes with full of energy and walk until you get out of the forest and see the roads that go up the hill. After about 10 minutes of walking, you come across a pack of wolves hunting a deer.\n\n");
			printf("You decide to....\n");
			printf("1. Sneek and attack a wolf that was left out alone.\n2. Attack all the wolves by yourself.\n3. Sneak and pass by.\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{	
				monster_count = 0;
				monster_strong_attack = 5;
				story = 5.1;
				break;
			}
			else if(choice == 2)
			{
				monster_count = 4;
				monster_strong_attack = 5;
				story = 5.2;
				break;
			}
			else if(choice == 3)
			{
				story = 5.3;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 5.1) //Fight lone wolf
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			if((monster_strong_attack > 1) && (wolf.hp > 0) && (player.healthpoint > 0))
			{
				printf("\"Beware of monster strong attack in %d turns.\"     ", monster_strong_attack);
			}
			else if((monster_strong_attack == 1) && (wolf.hp > 0) && (player.healthpoint > 0))
			{
				printf("\"Beware of monster strong attack in next turns.\"     ");
			}

			if((monster_count >= 0) && (wolf.hp > 0))
			{
				printf("\"Monster left : %d\"\n", monster_count + 1);
			}
			else
			{
				printf("\n");
			}

			if(player.healthpoint <= 0)
			{
				printf("You cannot defeat it and you decided to run.\n");
				delay(3);
				player.heart -= 1;
				player.healthpoint = max_hp;
				story = 6.0;
				break;
			}
			else if((wolf.hp <= 0) && (monster_count > 0))
			{
				player.gold += wolf.gold_drop;
				printf("You win the fight.\n\n== Gold + %d ==\n\n", wolf.gold_drop);
				delay(3);
				monster_count -= 1;
				wolf.hp = wolf.max_hp;
				monster_strong_attack = 5;
				break;
			}
			else if((wolf.hp <= 0) && (monster_count == 0))
			{
				player.gold += wolf.gold_drop;
				printf("You win the fight.\n\n== Gold + %d ==\n\n", wolf.gold_drop);
				delay(3);
				story = 6.0;
				break;
			}

			for(int j = 0; j < (max_columns /2) - 10; j++)
			{
				printf(" ");
			}

			printf("%s", PowerBar_E[0]);
			
			for(int j = 0; j < (max_columns /2) - 10; j++)
			{
				printf(" ");
			}

			printf("%s", PowerBar_E[1]);
			printf(" %d\n", wolf.hp);
			
			Wolf();

			printf("1. Attack.\n2. Defend.\n3. Heal.\n4. Escape.\n\n");
			printf("Type : ");

			choice = ScanInput();

			if(choice == 1)
			{
				monster_strong_attack -= 1;

				player_crit = rand() % 5;

				if(player_crit == 4)
				{
					attack_damage = wolf.hp;
					wolf.hp -= (player.attack + ((rand() % player.attack / 2) - (rand() % player.attack / 3))) * ((rand() % 2) + 2);
				
					printf("\nYour critical attack = \" %d \" damage.\n", attack_damage - wolf.hp);
					delay(1.5);
				}
				else
				{
					attack_damage = wolf.hp;
					wolf.hp -= player.attack + ((rand() % player.attack / 2) - (rand() % player.attack / 3));
				
					printf("\nYour attack = \" %d \" damage.\n", attack_damage - wolf.hp);
					delay(1.5);
				}

				monster_crit = rand() % 15;

				if((monster_strong_attack == 0) && (wolf.hp > 0))
				{
					monster_strong_attack = 5;

					receive_damage = player.healthpoint;
					player.healthpoint -= (((wolf.attack) + ((rand() % wolf.attack / 2) - (rand() % wolf.attack / 3))) * 1.5) / (1 + (player.defense / 100));
					
					printf("Enemy strong attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if((monster_crit == 14) && (wolf.hp > 0))
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= (((wolf.attack) + ((rand() % wolf.attack / 2) - (rand() % wolf.attack / 3))) * ((rand() % 2) + 2)) / (1 + (player.defense / 100));
					
					printf("Enemy critical attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if(wolf.hp > 0)
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= ((wolf.attack) + ((rand() % wolf.attack / 2) - (rand() % wolf.attack / 3))) / (1 + (player.defense / 100));
					
					printf("Enemy attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else
				{
					break;
				}
			}
			else if(choice == 2)
			{
				monster_strong_attack -= 1;

				monster_crit = rand() % 15;

				if((monster_strong_attack == 0) && (wolf.hp > 0))
				{
					monster_strong_attack = 5;

					receive_damage = player.healthpoint;
					player.healthpoint -= (((wolf.attack) + ((rand() % wolf.attack / 2) - (rand() % wolf.attack / 3))) * 1.5) / (2 + (player.defense / 100));
					
					printf("Enemy strong attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if((monster_crit == 14) && (wolf.hp > 0))
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= (((wolf.attack) + ((rand() % wolf.attack / 2) - (rand() % wolf.attack / 3))) * ((rand() % 2) + 2)) / (2 + (player.defense / 100));
					
					printf("Enemy critical attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if(wolf.hp > 0)
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= ((wolf.attack) + ((rand() % wolf.attack / 2) - (rand() % wolf.attack / 3))) / (2 + (player.defense / 100));
					
					printf("Enemy attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else
				{
					break;
				}
				
				printf("Enemy attack = \"%d\"", receive_damage - player.healthpoint);
				delay(1.5);
				break;
			}
			else if(choice == 3)
			{
				monster_strong_attack -= 1;

				player.healthpoint += player.heal;

				if(player.healthpoint >= max_hp)
				{
					player.healthpoint = max_hp;
				}

				printf("\nYou health restore = \" %d \" point.\n", player.heal);
				delay(1.5);
				
				monster_crit = rand() % 15;

				if((monster_strong_attack == 0) && (wolf.hp > 0))
				{
					monster_strong_attack = 5;

					receive_damage = player.healthpoint;
					player.healthpoint -= (((wolf.attack) + ((rand() % wolf.attack / 2) - (rand() % wolf.attack / 3))) * 1.5) / (1 + (player.defense / 100));
					
					printf("Enemy strong attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if((monster_crit == 14) && (wolf.hp > 0))
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= (((wolf.attack) + ((rand() % wolf.attack / 2) - (rand() % wolf.attack / 3))) * ((rand() % 2) + 2)) / (1 + (player.defense / 100));
					
					printf("Enemy critical attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if(wolf.hp > 0)
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= ((wolf.attack) + ((rand() % wolf.attack / 2) - (rand() % wolf.attack / 3))) / (1 + (player.defense / 100));
					
					printf("Enemy attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else
				{
					break;
				}
			}
			else if(choice == 4)
			{
				story = 6.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 5.2) //Fight pack of wolves
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			if((monster_strong_attack > 1) && (wolf.hp > 0) && (player.healthpoint > 0))
			{
				printf("\"Beware of monster strong attack in %d turns.\"     ", monster_strong_attack);
			}
			else if((monster_strong_attack == 1) && (wolf.hp > 0) && (player.healthpoint > 0))
			{
				printf("\"Beware of monster strong attack in next turns.\"     ");
			}

			if((monster_count >= 0) && (wolf.hp > 0))
			{
				printf("\"Monster left : %d\"\n", monster_count + 1);
			}
			else
			{
				printf("\n");
			}

			if(player.healthpoint <= 0)
			{
				printf("You cannot defeat it and you decided to run.\n");
				delay(3);
				player.heart -= 1;
				player.healthpoint = max_hp;
				story = 6.0;
				break;
			}
			else if((wolf.hp <= 0) && (monster_count > 0))
			{
				player.gold += wolf.gold_drop;
				printf("You win the fight.\n\n== Gold + %d ==\n\n", wolf.gold_drop);
				delay(3);
				monster_count -= 1;
				wolf.hp = wolf.max_hp;
				monster_strong_attack = 5;
				break;
			}
			else if((wolf.hp <= 0) && (monster_count == 0))
			{
				player.gold += wolf.gold_drop;
				printf("You win the fight.\n\n== Gold + %d ==\n\n", wolf.gold_drop);
				delay(3);
				story = 6.0;
				break;
			}
			
			for(int j = 0; j < (max_columns /2) - 10; j++)
			{
				printf(" ");
			}

			printf("%s", PowerBar_E[0]);
			
			for(int j = 0; j < (max_columns /2) - 10; j++)
			{
				printf(" ");
			}

			printf("%s", PowerBar_E[1]);
			printf(" %d\n", wolf.hp);
			
			Wolf();

			printf("1. Attack.\n2. Defend.\n3. Heal.\n4. Escape.\n\n");
			printf("Type : ");

			choice = ScanInput();

			if(choice == 1)
			{
				monster_strong_attack -= 1;

				player_crit = rand() % 5;

				if(player_crit == 4)
				{
					attack_damage = wolf.hp;
					wolf.hp -= (player.attack + ((rand() % player.attack / 2) - (rand() % player.attack / 3))) * ((rand() % 2) + 2);
				
					printf("\nYour critical attack = \" %d \" damage.\n", attack_damage - wolf.hp);
					delay(1.5);
				}
				else
				{
					attack_damage = wolf.hp;
					wolf.hp -= player.attack + ((rand() % player.attack / 2) - (rand() % player.attack / 3));
				
					printf("\nYour attack = \" %d \" damage.\n", attack_damage - wolf.hp);
					delay(1.5);
				}

				monster_crit = rand() % 15;

				if((monster_strong_attack == 0) && (wolf.hp > 0))
				{
					monster_strong_attack = 5;

					receive_damage = player.healthpoint;
					player.healthpoint -= (((wolf.attack) + ((rand() % wolf.attack / 2) - (rand() % wolf.attack / 3))) * 1.5) / (1 + (player.defense / 100));
					
					printf("Enemy strong attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if((monster_crit == 14) && (wolf.hp > 0))
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= (((wolf.attack) + ((rand() % wolf.attack / 2) - (rand() % wolf.attack / 3))) * ((rand() % 2) + 2)) / (1 + (player.defense / 100));
					
					printf("Enemy critical attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if(wolf.hp > 0)
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= ((wolf.attack) + ((rand() % wolf.attack / 2) - (rand() % wolf.attack / 3))) / (1 + (player.defense / 100));
					
					printf("Enemy attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else
				{
					break;
				}
			}
			else if(choice == 2)
			{
				monster_strong_attack -= 1;

				monster_crit = rand() % 15;

				if((monster_strong_attack == 0) && (wolf.hp > 0))
				{
					monster_strong_attack = 5;

					receive_damage = player.healthpoint;
					player.healthpoint -= (((wolf.attack) + ((rand() % wolf.attack / 2) - (rand() % wolf.attack / 3))) * 1.5) / (2 + (player.defense / 100));
					
					printf("Enemy strong attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if((monster_crit == 14) && (wolf.hp > 0))
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= (((wolf.attack) + ((rand() % wolf.attack / 2) - (rand() % wolf.attack / 3))) * ((rand() % 2) + 2)) / (2 + (player.defense / 100));
					
					printf("Enemy critical attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if(wolf.hp > 0)
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= ((wolf.attack) + ((rand() % wolf.attack / 2) - (rand() % wolf.attack / 3))) / (2 + (player.defense / 100));
					
					printf("Enemy attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else
				{
					break;
				}
				
				printf("Enemy attack = \"%d\"", receive_damage - player.healthpoint);
				delay(1.5);
				break;
			}
			else if(choice == 3)
			{
				monster_strong_attack -= 1;

				player.healthpoint += player.heal;

				if(player.healthpoint >= max_hp)
				{
					player.healthpoint = max_hp;
				}

				printf("\nYou health restore = \" %d \" point.\n", player.heal);
				delay(1.5);
				
				monster_crit = rand() % 15;

				if((monster_strong_attack == 0) && (wolf.hp > 0))
				{
					monster_strong_attack = 5;

					receive_damage = player.healthpoint;
					player.healthpoint -= (((wolf.attack) + ((rand() % wolf.attack / 2) - (rand() % wolf.attack / 3))) * 1.5) / (1 + (player.defense / 100));
					
					printf("Enemy strong attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if((monster_crit == 14) && (wolf.hp > 0))
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= (((wolf.attack) + ((rand() % wolf.attack / 2) - (rand() % wolf.attack / 3))) * ((rand() % 2) + 2)) / (1 + (player.defense / 100));
					
					printf("Enemy critical attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if(wolf.hp > 0)
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= ((wolf.attack) + ((rand() % wolf.attack / 2) - (rand() % wolf.attack / 3))) / (1 + (player.defense / 100));
					
					printf("Enemy attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else
				{
					break;
				}
			}
			else if(choice == 4)
			{
				story = 6.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 5.3) //Sneak pass by || lone wolf notice
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

				MonsterSoundColor();
			printf("\"Growlllll..... grawhh!!\"\n");
				EndTextColor();
			printf("You try to sneak past a pack of wolves, but a lone wolf that was left out of the group notices you and walks right up to you.\n\n");
			printf("You decide to....\n");
			printf("1. Keep your body straight and fight it.\n2. Run!!! As fast as you can.\n");
			
			choice = ScanInput();

			if(choice == 1)
			{
				monster_count = 0;
				monster_strong_attack = 5;
				story = 5.1;
				break;
			}
			else if(choice == 2)
			{
				story = 6.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 6.0) //At the dwarves gate
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("You passed the pack of wolves, and not too far away, you can see there is a town on top of a hill. You set that town as your next destination and keep walking. An hour and a half of walking. Finally, you arrive at the town gate and feel a little tired. One of the dwarves' guards approaches you and hands you a canteen of water before asking.\n\n");
				SpeechBox();
			printf("\"What business do you have here, Adventer?\"\n\n");
				EndTextColor();
			printf("You answer....\n");
			printf("1. I'm just passing by, and I don't really know where to go. Can I enter your town?\n2. You know? I'm a thief with an eye for plunder this town and a plan for it. So, get out of my way, or else I'll kill you.\n3. I'm the hero that pass by and saw your town. Can I enter and have some rest?\n4. I'm just passing by this town. Thanks for the water.\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				story = 6.1;
                break;
			}
			else if(choice == 2)
			{
				story = 6.2;
                break;
			}
            else if(choice == 3)
            {
                story = 6.3;
                break;
            }
            else if(choice == 4)
            {
                story = 8.0; 
                break;
            }
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart = 0)
            {
                game = 1;
                break;
            }
		}
        while(story == 6.1) //Adventurer that passing by
        {
           ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("You answer with I'm just passing by, and I don't really know where to go. Can I enter your town? The guard heard that and make a little smile and say.\n\n");
				SpeechBox();
			printf("\"To enter our town, it has to have an entry fee, and it costs 10 gold.\"\n\n");
				EndTextColor();
			printf("You decide to....\n");
			printf("1. Pay the entry fee with 10 gold and enter the town.\n2. Not enter the town and go to other place.\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				story = 6.11;
                break;
			}
			else if(choice == 2)
			{
				story = 8.0;
                break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart = 0)
            {
                game = 1;
                break;
            }
        }
        while(story == 6.11) //Adventurer pay entry fee dwarf town
        {
            ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

            printf("You pay the entry fee with 10 gold and enter the town. Then, dwarves' guards smile and say.\n\n");
			    SpeechBox();
			printf("\"Thank you. I hope you have fun when you stay in our town.\"\n\n");
			    EndTextColor();
            printf("Type 1 to continue.\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				player.gold -= 10;
				story = 7.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
        }
        while(story == 6.2) //Thef that want to plunder this town
        {
            ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("You answer with I'm a thief with an eye for plunder this town and a plan for it. So, get out of my way, or else I'll kill you. The guard heard that and make a little smile and say.\n\n");
				SpeechBox();
			printf("\"Try me if you dare....\"\n\n");
				EndTextColor();
			printf("You decide to....\n");
			printf("1. Just kidding here the entry fee.\n2. Not enter the town and go to other place.\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				story = 6.21;
                break;
			}
			else if(choice == 2)
			{
				story = 8.0;
                break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart = 0)
            {
                game = 1;
                break;
            }
        }
        while(story == 6.21) //Thief pay entry fee dwarf town
        {
            ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

            printf("You pay the entry fee with 20 gold and enter the town. Then, dwarves' guards smile and say.\n\n");
			    SpeechBox();
			printf("\"Sigh... Huh.. Huh.. Well, if you are not a real man. But thank you for the gold. I hope you have fun when you stay in our town.\"\n\n");
			    EndTextColor();
            printf("Type 1 to continue.\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				player.gold -= 20;
				story = 7.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
        }
        while(story == 6.3) //Hero that passing by
        {
            ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("You answer with I'm the hero that pass by and saw your town. Can I enter and have some rest? The guard heard that and make a little smile and say.\n\n");
				SpeechBox();
			printf("\"Even the hero like you. To enter our town, it has to have an entry fee, and it costs 10 gold.\"\n\n");
				EndTextColor();
			printf("You decide to....\n");
			printf("1. Pay the entry fee with 10 gold and enter the town.\n2. Not enter the town and go to other place.\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				story = 6.31;
                break;
			}
			else if(choice == 2)
			{
				story = 8.0;
                break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart = 0)
            {
                game = 1;
                break;
            }
        }
        while(story == 6.31) //Hero pay entry fee dwarf town
        {
            ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

            printf("You pay the entry fee with 10 gold and enter the town. Then, dwarves' guards smile and say.\n\n");
			    SpeechBox();
			printf("\"Thank you. I hope you have fun when you stay in our town.\"\n\n");
			    EndTextColor();
            printf("Type 1 to continue.\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				player.gold -= 10;
				story = 7.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
        }
        while(story == 7.0) //In the dwarf town
        {
            ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

            printf("On the town square, you can see an inn on the left, a blacksmith in front of you, and a shop not far away, as well as a guild building on the right.\n\n");
			printf("You decide to....\n");
			printf("1. Go to an inn.\n2. Go to a blacksmith.\n3. Go to a store.\n4. Go to a guild.\n5. Leave the dwarf town.\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				story = 7.1;
				break;
			}
			else if(choice == 2)
			{
                story = 7.2;
				break;
			}
			else if(choice == 3)
			{
				story = 7.3;
				break;
			}
            else if(choice == 4)
            {
                story = 7.4;
                break;
            }
			else if(choice == 5)
			{
				story == 8.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
        }
        while(story == 7.1) //Dwarfer inn
        {
            ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

            printf("In the dwarfer inn, the place whare full of people that are talking and making noise. You came in and walked straight to the reception. A man that is tall about half of your height but full of muscle looks at you and asks.\n\n");
                SpeechBox();
            printf("\"What do you want adventure?\"\n\n");
                EndTextColor();
			printf("You answer....\n");
			printf("1. I want to take a rest today.\n2. I want to try some of the delicious foods you recommend.\n3. I want to use your training ground to practice swordsmanship.\n4. I want to use your training ground to do some exercise.\n5. Go outside the inn.\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				story = 7.11;
				break;
			}
			else if(choice == 2)
			{
                story = 7.12;
				break;
			}
			else if(choice == 3)
			{
				story = 7.13;
				break;
			}
            else if(choice == 4)
            {
                story = 7.14;
                break;
            }
            else if(choice == 5)
            {
                story = 7.0;
                break;
            }
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
        }
        while(story == 7.11) //Dwarfer inn rest for today
        {
            ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

            printf("You answer that you want to rest for today. He nodded once before saying.\n\n");
                SpeechBox();
            printf("\"10 gold for one night.\"\n\n");
                EndTextColor();
            printf("You decide to....\n");
            printf("1. Pay 10 gold and take a rest.\n2. Think about what you want to do again.\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				player.gold -= 10;
				story = 7.111;
				break;
			}
			else if(choice == 2)
			{
                story = 7.1;
				break;
			}
            else
            {
                wrong_chioce = 1;
				break;
            }

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
        }
        while(story == 7.111) //Dwarfer inn take a rest
        {
            ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

            printf("You have a good night rest.\n\n== Restore Health Point ==\n\n");
            printf("Type 1 to continue.\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
                player.healthpoint = max_hp;
				story = 7.1;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
        }
        while(story == 7.12) //Dwarfer inn pay delicious foods
        {
            ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

            printf("You answer that I want to try some of the delicious foods you recommend. He smile and say.\n\n");
                SpeechBox();
            printf("\"30 gold for our inn's most recommended and delicious full-course meal.\"\n\n");
                EndTextColor();
            printf("You decide to....\n");
            printf("1. Pay 30 gold and eat the full-course meal.\n2. Think about what you want to do again.\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				player.gold -= 30;
				story = 7.121;
				break;
			}
			else if(choice == 2)
			{
                story = 7.1;
				break;
			}
            else
            {
                wrong_chioce = 1;
				break;
            }

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
        }
        while(story == 7.121) //Dwarfer inn try delicious foods
        {
            ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("You have a very good meal and feel full and healty.\n\n== Heart + 1 ==\n\n");
            printf("Type 1 to continue.\n\n");
			printf("Type : ");

			choice = ScanInput();

			if(choice == 1)
			{	
				player.heart += 1;
				story = 7.1;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
        }
        while(story == 7.13) //Dwarfer inn pay for practice swordsmanship
        {
            ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

            printf("You answer that I want to use your training ground to practice swordsmanship. He used to think for a moment before nodding and saying.\n\n");
                SpeechBox();
            printf("\"Our training ground hasn't been used in a while, but it will cost you 5 gold per use if you want to use it.\"\n\n");
                EndTextColor();
            printf("You decide to....\n");
            printf("1. Pay 5 gold and use traning ground to practice swordsmanship.\n2. Think about what you want to do again.\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				player.gold -= 5;
				story = 7.131;
				break;
			}
			else if(choice == 2)
			{
                story = 7.1;
				break;
			}
            else
            {
                wrong_chioce = 1;
				break;
            }

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
        }
		while(story == 7.131) //Dwarfer inn practice swordsmanship
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("You've finished practicing swordsmanship. You feel like you know how to use a sword a little bit better.\n\n== Attack + 1 ==\n\n");
            printf("Type 1 to continue.\n\n");
			printf("Type : ");

			choice = ScanInput();

			if(choice == 1)
			{	
				player.attack += 1;
				story = 7.1;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
        while(story == 7.14) //Dwarfer inn pay for exercise
        {
            ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

            printf("You answer that I want to use your training ground to do some exercise. He used to think for a moment before nodding and saying.\n\n");
                SpeechBox();
            printf("\"Our training ground hasn't been used in a while, but it will cost you 5 gold per use if you want to use it.\"\n\n");
                EndTextColor();
            printf("You decide to....\n");
            printf("1. Pay 5 gold and use traning ground to do some exercise..\n2. Think about what you want to do again.\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				player.gold -= 5;
				story = 7.141;
				break;
			}
			else if(choice == 2)
			{
                story = 7.1;
				break;
			}
            else
            {
                wrong_chioce = 1;
				break;
            }

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
        }
        while(story == 7.141) //Dwarfer inn do exercise
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);

			wrong_chioce = 0;

			printf("You've finished all the exercises. You can feel your muscles heating up and growing at the same time.\n\n== defense + 1 ==\n\n");
			printf("Type 1 to start an adventure\n\n");
			printf("Type : ");

			choice = ScanInput();

			if(choice == 1)
			{	
				player.defense += 1;
				story = 7.1;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 7.2) //Dwarf blacksmith
        {
            ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("You walked into the blacksmith and immediately felt intense heat. The flame is glowing at the back of the workshop. The man smashing a hammer with the glowing red iron came to a halt, then looked at you and asked.\n\n");
				SpeechBox();
            printf("\"You want to buy weapons or armor, or do you want my skill to do something else for you?\"\n\n");
                EndTextColor();
			printf("You answer....\n");
			printf("1. I want to see what the blacksmith has to sell.\n2. Go outside the blacksmith.\n\n");
			printf("Type : ");

			choice = ScanInput();

			if(choice == 1)
			{
				story = 7.21;
				break;
			}
			else if(choice == 2)
			{
				story = 7.1;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
        }
        while(story == 7.21) //Dwarf blacksmith sell list
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;
			
			SpeechBox();
			printf("\"Ha!! Welcome adventure!! What you want in our smith?\"\n\n");
				EndTextColor();
			printf("1. Repair sword.\n\tPirce 50 gold\n\tAttack + 3\n2. Upgrade sword.\n\tPrice 100 gold\n\tAttack + 6\n3. Repair armor.\n\tPrice 50 gold\n\tDefense + 3\n4. Upgrade armor.\n\tPrice 100 gold\n\tDefense + 6\n5. Exit the blacksmith.\n\n");
			printf("Type : ");

			choice = ScanInput();

			if((choice == 1) && (player.gold >= 50))
			{
				printf("== Attack + 2 ==\n");
				delay(1.5);
				player.attack += 3;
				player.gold -= 50;
				break;
			}
			else if((choice == 1) && (player.gold < 50))
			{
				printf("not enough gold!!!\n");
				delay(1.5);
				break;
			}
			else if((choice == 2) && (player.gold >= 100))
			{
				printf("== Attack + 5 ==\n");
				delay(1.5);
				player.attack += 6;
				player.gold -= 100;
				break;
			}
			else if((choice == 2) && (player.gold < 100))
			{
				printf("not enough gold!!!\n");
				delay(1.5);
				break;
			}
			else if((choice == 3) && (player.gold >= 50))
			{
				printf("== Defense + 2 ==\n");
				delay(1.5);
				player.defense += 3;
				player.gold -= 50;
				break;
			}
			else if((choice == 3) && (player.gold < 50))
			{
				printf("not enough gold!!!\n");
				delay(1.5);
				break;
			}
			else if((choice == 4) && (player.gold >= 100))
			{
				printf("== Defense + 5 ==\n");
				delay(1.5);
				player.defense += 6;
				player.gold -= 100;
				break;
			}
			else if((choice == 4) && (player.gold < 100))
			{
				printf("not enough gold!!!\n");
				delay(1.5);
				break;
			}
			else if(choice == 5)
			{
				story = 7.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

			if(player.heart == 0)
			{
				game = 1;
				break;
			}
		}
		while(story == 7.3) //Dwarf shop
        {
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("You step into the shop and see lots of armor and weapons on the shelves. And you seem amazed when you look around and see so many things on sale. A little dwarf girl salesman walks up to you, then stops and ask.\n\n");
				SpeechBox();
            printf("\"Hi, our customer. What would you like to buy from our shop?\"\n\n");
                EndTextColor();
			printf("You answer....\n");
			printf("1. I want to see what the shop has to sell.\n2. Go outside the blacksmith.\n\n");
			printf("Type : ");

			choice = ScanInput();

			if(choice == 1)
			{
				story = 7.31;
				break;
			}
			else if(choice == 2)
			{
				story = 7.1;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
        }
		while(story == 7.31) //Dwarf shop sell list
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;
			
			SpeechBox();
			printf("\" Welcome adventure!! Got some rare things on sale!! What you want to buy in our shop?\"\n\n");
				EndTextColor();
			printf("1. Small healty potion.\n\tPrice 50 gold\n\tHealth Point + 25\n2. Healty potion.\n\tPrice 100 gold\n\tHealt Point + 50\n3. Medium grade holy potion.\n\tPrice 50 gold\n\tHeal Power + 10\n4. Highest grade holy potion.\n\tPrice 100 gold\n\tHeal Power + 25\n5. Exit the shop.\n\n");
			printf("Type : ");

			choice = ScanInput();

			if((choice == 1) && (player.gold >= 50))
			{
				printf("== Health Point + 25 ==\n");
				delay(1.5);
				player.healthpoint += 25;
				max_hp += 25;
				player.gold -= 50;
				break;
			}
			else if((choice == 1) && (player.gold < 50))
			{
				printf("not enough gold!!!\n");
				delay(1.5);
				break;
			}
			else if((choice == 2) && (player.gold >= 100))
			{
				printf("== Health Point + 50 ==\n");
				delay(1.5);
				player.healthpoint += 50;
				max_hp += 50;
				player.gold -= 100;
				break;
			}
			else if((choice == 2) && (player.gold < 100))
			{
				printf("not enough gold!!!\n");
				delay(1.5);
				break;
			}
			else if((choice == 3) && (player.gold >= 50))
			{
				printf("== Heal Power + 10 ==\n");
				delay(1.5);
				player.heal += 10;
				player.gold -= 50;
				break;
			}
			else if((choice == 3) && (player.gold < 50))
			{
				printf("not enough gold!!!\n");
				delay(1.5);
				break;
			}
			else if((choice == 4) && (player.gold >= 100))
			{
				printf("== Heal Power + 25 ==\n");
				delay(1.5);
				player.heal += 25;
				player.gold -= 100;
				break;
			}
			else if((choice == 4) && (player.gold < 100))
			{
				printf("not enough gold!!!\n");
				delay(1.5);
				break;
			}
			else if(choice == 5)
			{
				story = 7.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

			if(player.heart == 0)
			{
				game = 1;
				break;
			}
		}
        while(story == 7.4) //Dwarf guild
        {
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("You step into the adventure guild and see lots of people of different races talking with each other, including humans. And you seem amazed when you look around and see how big this guild is. Then, you keep walking forward and stop at the reception. A little elf girl looked up, put down her pen, and ask.\n\n");
				SpeechBox();
            printf("\"Hello, adventerer. What would you like me to do for you? Or do you want me to recommend some suitable quests for you?\"\n\n");
                EndTextColor();
			printf("You answer....\n");
			printf("1. I want to hunt slime.\n2. I want to hunt wolf.\n3. I want to hunt skeleton.\n4. I want to hunt orc.\n5. I want to hunt troll.\n6. Exit the adventure guild.\n\n");
			printf("Type : ");

			choice = ScanInput();

			if(choice == 1)
			{
				story = 7.41;
				break;
			}
			else if(choice == 2)
			{
				story = 7.42;
				break;
			}
			else if(choice == 3)
			{
				story = 7.43;
				break;
			}
			else if(choice == 4)
			{
				story = 7.44;
				break;
			}
			else if(choice == 5)
			{
				story = 7.45;
				break;
			}
			else if(choice == 6)
			{
				story = 7.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
        }
		while(story == 7.41) //Receive quest to hunt slime
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("You answer that you want to hunt some slimes. She silently nodded, then spent some time looking for the paper and handing the quest paper to you.\n\n== You recieve slime hunt quest ==\n\n");
			printf("Type 1 to continue\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				story = 7.411;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 7.411) //Found a group of slime
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			monster_count = (rand() % 9) + 1;

			slime.hp = slime.max_hp;

			printf("At the edge of town. You're walking slowly and looking for a smile to hunt when you notice something near the edge of the forest. You walk closer to it and discover %d slime.\n\n", monster_count);
			printf("You decide to....\n");
			printf("1. Fight with the slime.\n2. Looking for other slime to hunt.\n3. Go back to the adventure guild.\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				monster_strong_attack = 5;
				story = 7.4111;
				break;
			}
			else if(choice == 2)
			{
				story = 7.411;
			}
			else if(choice == 3)
			{
				story = 7.4;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 7.4111) //Fight group of slime
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			if((monster_strong_attack > 1) && (slime.hp > 0) && (player.healthpoint > 0))
			{
				printf("\"Beware of monster strong attack in %d turns.\"     ", monster_strong_attack);
			}
			else if((monster_strong_attack == 1) && (slime.hp > 0) && (player.healthpoint > 0))
			{
				printf("\"Beware of monster strong attack in next turns.\"     ");
			}

			if((monster_count >= 0) && (slime.hp > 0))
			{
				printf("\"Monster left : %d\"\n", monster_count + 1);
			}
			else
			{
				printf("\n");
			}

			if(player.healthpoint <= 0)
			{
				printf("You cannot defeat it and you decided to run.\n");
				delay(3);
				player.heart -= 1;
				player.healthpoint = max_hp;
				story = 7.411;
				break;
			}
			else if((wolf.hp <= 0) && (monster_count > 0))
			{
				player.gold += slime.gold_drop;
				printf("You win the fight.\n\n== Gold + %d ==\n\n", slime.gold_drop);
				delay(3);
				monster_count -= 1;
				slime.hp = slime.max_hp;
				monster_strong_attack = 5;
				break;
			}
			else if((slime.hp <= 0) && (monster_count == 0))
			{
				player.gold += slime.gold_drop;
				printf("You win the fight.\n\n== Gold + %d ==\n\n", slime.gold_drop);
				delay(3);
				story = 7.411;
				break;
			}
			
			for(int j = 0; j < (max_columns /2) - 10; j++)
			{
				printf(" ");
			}

			printf("%s", PowerBar_E[0]);
			
			for(int j = 0; j < (max_columns /2) - 10; j++)
			{
				printf(" ");
			}

			printf("%s", PowerBar_E[1]);
			printf(" %d\n", slime.hp);
			
			Slime();

			printf("1. Attack.\n2. Defend.\n3. Heal.\n4. Escape.\n\n");
			printf("Type : ");

			choice = ScanInput();

			if(choice == 1)
			{
				monster_strong_attack -= 1;

				player_crit = rand() % 5;

				if(player_crit == 4)
				{
					attack_damage = slime.hp;
					slime.hp -= (player.attack + ((rand() % player.attack / 2) - (rand() % player.attack / 3))) * ((rand() % 2) + 2);
				
					printf("\nYour critical attack = \" %d \" damage.\n", attack_damage - slime.hp);
					delay(1.5);
				}
				else
				{
					attack_damage = slime.hp;
					slime.hp -= player.attack + ((rand() % player.attack / 2) - (rand() % player.attack / 3));
				
					printf("\nYour attack = \" %d \" damage.\n", attack_damage - slime.hp);
					delay(1.5);
				}

				monster_crit = rand() % 15;

				if((monster_strong_attack == 0) && (slime.hp > 0))
				{
					monster_strong_attack = 5;

					receive_damage = player.healthpoint;
					player.healthpoint -= (((slime.attack) + ((rand() % slime.attack / 2) - (rand() % slime.attack / 3))) * 1.5) / (1 + (player.defense / 100));
					
					printf("Enemy strong attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if((monster_crit == 14) && (slime.hp > 0))
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= (((slime.attack) + ((rand() % slime.attack / 2) - (rand() % slime.attack / 3))) * ((rand() % 2) + 2)) / (1 + (player.defense / 100));
					
					printf("Enemy critical attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if(slime.hp > 0)
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= ((slime.attack) + ((rand() % slime.attack / 2) - (rand() % slime.attack / 3))) / (1 + (player.defense / 100));
					
					printf("Enemy attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else
				{
					break;
				}
			}
			else if(choice == 2)
			{
				monster_strong_attack -= 1;

				monster_crit = rand() % 15;

				if((monster_strong_attack == 0) && (slime.hp > 0))
				{
					monster_strong_attack = 5;

					receive_damage = player.healthpoint;
					player.healthpoint -= (((slime.attack) + ((rand() % slime.attack / 2) - (rand() % slime.attack / 3))) * 1.5) / (2 + (player.defense / 100));
					
					printf("Enemy strong attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if((monster_crit == 14) && (slime.hp > 0))
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= (((slime.attack) + ((rand() % slime.attack / 2) - (rand() % slime.attack / 3))) * ((rand() % 2) + 2)) / (2 + (player.defense / 100));
					
					printf("Enemy critical attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if(slime.hp > 0)
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= ((slime.attack) + ((rand() % slime.attack / 2) - (rand() % slime.attack / 3))) / (2 + (player.defense / 100));
					
					printf("Enemy attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else
				{
					break;
				}
				
				printf("Enemy attack = \"%d\"", receive_damage - player.healthpoint);
				delay(1.5);
				break;
			}
			else if(choice == 3)
			{
				monster_strong_attack -= 1;

				player.healthpoint += player.heal;

				if(player.healthpoint >= max_hp)
				{
					player.healthpoint = max_hp;
				}

				printf("\nYou health restore = \" %d \" point.\n", player.heal);
				delay(1.5);
				
				monster_crit = rand() % 15;

				if((monster_strong_attack == 0) && (slime.hp > 0))
				{
					monster_strong_attack = 5;

					receive_damage = player.healthpoint;
					player.healthpoint -= (((slime.attack) + ((rand() % slime.attack / 2) - (rand() % slime.attack / 3))) * 1.5) / (1 + (player.defense / 100));
					
					printf("Enemy strong attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if((monster_crit == 14) && (slime.hp > 0))
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= (((slime.attack) + ((rand() % slime.attack / 2) - (rand() % slime.attack / 3))) * ((rand() % 2) + 2)) / (1 + (player.defense / 100));
					
					printf("Enemy critical attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if(slime.hp > 0)
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= ((slime.attack) + ((rand() % slime.attack / 2) - (rand() % slime.attack / 3))) / (1 + (player.defense / 100));
					
					printf("Enemy attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else
				{
					break;
				}
			}
			else if(choice == 4)
			{
				story = 7.411;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 7.42) //Receive quest to hunt wolf
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("You answer that you want to hunt some wolves. She silently nodded, then spent some time looking for the paper and handing the quest paper to you.\n\n== You recieve wolf hunt quest ==\n\n");
			printf("Type 1 to continue\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				story = 7.421;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 7.421) //Found a pack of wolves
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			monster_count = (rand() % 3) + 2;

			wolf.hp = wolf.max_hp;

			printf("At the edge of town. You're walking slowly and looking for a pack of wolves to hunt when you notice something deep further into the forest. You walk closer to it and discover %d wolves.\n\n", monster_count);
			printf("You decide to....\n");
			printf("1. Fight with the wolves.\n2. Looking for other wolves pack to hunt.\n3. Go back to the adventure guild.\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				monster_strong_attack = 5;
				story = 7.4211;
				break;
			}
			else if(choice == 2)
			{
				story = 7.421;
			}
			else if(choice == 3)
			{
				story = 7.4;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 7.4211) //Fight pack of wolves
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			if((monster_strong_attack > 1) && (wolf.hp > 0) && (player.healthpoint > 0))
			{
				printf("\"Beware of monster strong attack in %d turns.\"     ", monster_strong_attack);
			}
			else if((monster_strong_attack == 1) && (wolf.hp > 0) && (player.healthpoint > 0))
			{
				printf("\"Beware of monster strong attack in next turns.\"     ");
			}

			if((monster_count >= 0) && (wolf.hp > 0))
			{
				printf("\"Monster left : %d\"\n", monster_count + 1);
			}
			else
			{
				printf("\n");
			}

			if(player.healthpoint <= 0)
			{
				printf("You cannot defeat it and you decided to run.\n");
				delay(3);
				player.heart -= 1;
				player.healthpoint = max_hp;
				story = 7.421;
				break;
			}
			else if((wolf.hp <= 0) && (monster_count > 0))
			{
				player.gold += wolf.gold_drop;
				printf("You win the fight.\n\n== Gold + %d ==\n\n", wolf.gold_drop);
				delay(3);
				monster_count -= 1;
				wolf.hp = wolf.max_hp;
				monster_strong_attack = 5;
				break;
			}
			else if((wolf.hp <= 0) && (monster_count == 0))
			{
				player.gold += wolf.gold_drop;
				printf("You win the fight.\n\n== Gold + %d ==\n\n", wolf.gold_drop);
				delay(3);
				story = 7.421;
				break;
			}
			
			for(int j = 0; j < (max_columns /2) - 10; j++)
			{
				printf(" ");
			}

			printf("%s", PowerBar_E[0]);
			
			for(int j = 0; j < (max_columns /2) - 10; j++)
			{
				printf(" ");
			}

			printf("%s", PowerBar_E[1]);
			printf(" %d\n", wolf.hp);
			
			Wolf();

			printf("1. Attack.\n2. Defend.\n3. Heal.\n4. Escape.\n\n");
			printf("Type : ");

			choice = ScanInput();

			if(choice == 1)
			{
				monster_strong_attack -= 1;

				player_crit = rand() % 5;

				if(player_crit == 4)
				{
					attack_damage = wolf.hp;
					wolf.hp -= (player.attack + ((rand() % player.attack / 2) - (rand() % player.attack / 3))) * ((rand() % 2) + 2);
				
					printf("\nYour critical attack = \" %d \" damage.\n", attack_damage - wolf.hp);
					delay(1.5);
				}
				else
				{
					attack_damage = wolf.hp;
					wolf.hp -= player.attack + ((rand() % player.attack / 2) - (rand() % player.attack / 3));
				
					printf("\nYour attack = \" %d \" damage.\n", attack_damage - wolf.hp);
					delay(1.5);
				}

				monster_crit = rand() % 15;

				if((monster_strong_attack == 0) && (wolf.hp > 0))
				{
					monster_strong_attack = 5;

					receive_damage = player.healthpoint;
					player.healthpoint -= (((wolf.attack) + ((rand() % wolf.attack / 2) - (rand() % wolf.attack / 3))) * 1.5) / (1 + (player.defense / 100));
					
					printf("Enemy strong attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if((monster_crit == 14) && (wolf.hp > 0))
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= (((wolf.attack) + ((rand() % wolf.attack / 2) - (rand() % wolf.attack / 3))) * ((rand() % 2) + 2)) / (1 + (player.defense / 100));
					
					printf("Enemy critical attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if(wolf.hp > 0)
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= ((wolf.attack) + ((rand() % wolf.attack / 2) - (rand() % wolf.attack / 3))) / (1 + (player.defense / 100));
					
					printf("Enemy attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else
				{
					break;
				}
			}
			else if(choice == 2)
			{
				monster_strong_attack -= 1;

				monster_crit = rand() % 15;

				if((monster_strong_attack == 0) && (wolf.hp > 0))
				{
					monster_strong_attack = 5;

					receive_damage = player.healthpoint;
					player.healthpoint -= (((wolf.attack) + ((rand() % wolf.attack / 2) - (rand() % wolf.attack / 3))) * 1.5) / (2 + (player.defense / 100));
					
					printf("Enemy strong attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if((monster_crit == 14) && (wolf.hp > 0))
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= (((wolf.attack) + ((rand() % wolf.attack / 2) - (rand() % wolf.attack / 3))) * ((rand() % 2) + 2)) / (2 + (player.defense / 100));
					
					printf("Enemy critical attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if(wolf.hp > 0)
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= ((wolf.attack) + ((rand() % wolf.attack / 2) - (rand() % wolf.attack / 3))) / (2 + (player.defense / 100));
					
					printf("Enemy attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else
				{
					break;
				}
				
				printf("Enemy attack = \"%d\"", receive_damage - player.healthpoint);
				delay(1.5);
				break;
			}
			else if(choice == 3)
			{
				monster_strong_attack -= 1;

				player.healthpoint += player.heal;

				if(player.healthpoint >= max_hp)
				{
					player.healthpoint = max_hp;
				}

				printf("\nYou health restore = \" %d \" point.\n", player.heal);
				delay(1.5);
				
				monster_crit = rand() % 15;

				if((monster_strong_attack == 0) && (wolf.hp > 0))
				{
					monster_strong_attack = 5;

					receive_damage = player.healthpoint;
					player.healthpoint -= (((wolf.attack) + ((rand() % wolf.attack / 2) - (rand() % wolf.attack / 3))) * 1.5) / (1 + (player.defense / 100));
					
					printf("Enemy strong attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if((monster_crit == 14) && (wolf.hp > 0))
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= (((wolf.attack) + ((rand() % wolf.attack / 2) - (rand() % wolf.attack / 3))) * ((rand() % 2) + 2)) / (1 + (player.defense / 100));
					
					printf("Enemy critical attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if(wolf.hp > 0)
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= ((wolf.attack) + ((rand() % wolf.attack / 2) - (rand() % wolf.attack / 3))) / (1 + (player.defense / 100));
					
					printf("Enemy attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else
				{
					break;
				}
			}
			else if(choice == 4)
			{
				story = 7.421;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 7.43) //Receive quest to hunt skeleton
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("You answer that you want to hunt some skeletons. She silently nodded, then spent some time looking for the paper and handing the quest paper to you.\n\n== You recieve skeleton hunt quest ==\n\n");
			printf("Type 1 to continue\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				story = 7.431;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 7.431) //Found a group of skeleton
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			monster_count = (rand() % 4) + 1;

			skeleton.hp = skeleton.max_hp;

			printf("At the edge of the forest. You're walking slowly and looking for a skeleton to hunt when you notice something deep further into the forest. You walk closer to it and discover %d skeleton.\n\n", monster_count);
			printf("You decide to....\n");
			printf("1. Fight with the skeleton.\n2. Looking for other skeleton to hunt.\n3. Go back to the adventure guild.\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				monster_strong_attack = 5;
				story = 7.4311;
				break;
			}
			else if(choice == 2)
			{
				story = 7.431;
			}
			else if(choice == 3)
			{
				story = 7.4;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 7.4311) //Fight group of skeleton
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			if((monster_strong_attack > 1) && (skeleton.hp > 0) && (player.healthpoint > 0))
			{
				printf("\"Beware of monster strong attack in %d turns.\"     ", monster_strong_attack);
			}
			else if((monster_strong_attack == 1) && (skeleton.hp > 0) && (player.healthpoint > 0))
			{
				printf("\"Beware of monster strong attack in next turns.\"     ");
			}

			if((monster_count >= 0) && (skeleton.hp > 0))
			{
				printf("\"Monster left : %d\"\n", monster_count + 1);
			}
			else
			{
				printf("\n");
			}

			if(player.healthpoint <= 0)
			{
				printf("You cannot defeat it and you decided to run.\n");
				delay(3);
				player.heart -= 1;
				player.healthpoint = max_hp;
				story = 7.431;
				break;
			}
			else if((skeleton.hp <= 0) && (monster_count > 0))
			{
				player.gold += skeleton.gold_drop;
				printf("You win the fight.\n\n== Gold + %d ==\n\n", skeleton.gold_drop);
				delay(3);
				monster_count -= 1;
				skeleton.hp = skeleton.max_hp;
				monster_strong_attack = 5;
				break;
			}
			else if((skeleton.hp <= 0) && (monster_count == 0))
			{
				player.gold += skeleton.gold_drop;
				printf("You win the fight.\n\n== Gold + %d ==\n\n", skeleton.gold_drop);
				delay(3);
				story = 7.431;
				break;
			}
			
			for(int j = 0; j < (max_columns /2) - 10; j++)
			{
				printf(" ");
			}

			printf("%s", PowerBar_E[0]);
			
			for(int j = 0; j < (max_columns /2) - 10; j++)
			{
				printf(" ");
			}

			printf("%s", PowerBar_E[1]);
			printf(" %d\n", skeleton.hp);
			
			Skeleton();

			printf("1. Attack.\n2. Defend.\n3. Heal.\n4. Escape.\n\n");
			printf("Type : ");

			choice = ScanInput();

			if(choice == 1)
			{
				monster_strong_attack -= 1;

				player_crit = rand() % 5;

				if(player_crit == 4)
				{
					attack_damage = skeleton.hp;
					skeleton.hp -= (player.attack + ((rand() % player.attack / 2) - (rand() % player.attack / 3))) * ((rand() % 2) + 2);
				
					printf("\nYour critical attack = \" %d \" damage.\n", attack_damage - skeleton.hp);
					delay(1.5);
				}
				else
				{
					attack_damage = skeleton.hp;
					skeleton.hp -= player.attack + ((rand() % player.attack / 2) - (rand() % player.attack / 3));
				
					printf("\nYour attack = \" %d \" damage.\n", attack_damage - skeleton.hp);
					delay(1.5);
				}

				monster_crit = rand() % 15;

				if((monster_strong_attack == 0) && (skeleton.hp > 0))
				{
					monster_strong_attack = 5;

					receive_damage = player.healthpoint;
					player.healthpoint -= (((skeleton.attack) + ((rand() % skeleton.attack / 2) - (rand() % skeleton.attack / 3))) * 1.5) / (1 + (player.defense / 100));
					
					printf("Enemy strong attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if((monster_crit == 14) && (skeleton.hp > 0))
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= (((skeleton.attack) + ((rand() % skeleton.attack / 2) - (rand() % skeleton.attack / 3))) * ((rand() % 2) + 2)) / (1 + (player.defense / 100));
					
					printf("Enemy critical attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if(skeleton.hp > 0)
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= ((skeleton.attack) + ((rand() % skeleton.attack / 2) - (rand() % skeleton.attack / 3))) / (1 + (player.defense / 100));
					
					printf("Enemy attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else
				{
					break;
				}
			}
			else if(choice == 2)
			{
				monster_strong_attack -= 1;

				monster_crit = rand() % 15;

				if((monster_strong_attack == 0) && (skeleton.hp > 0))
				{
					monster_strong_attack = 5;

					receive_damage = player.healthpoint;
					player.healthpoint -= (((skeleton.attack) + ((rand() % skeleton.attack / 2) - (rand() % skeleton.attack / 3))) * 1.5) / (2 + (player.defense / 100));
					
					printf("Enemy strong attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if((monster_crit == 14) && (skeleton.hp > 0))
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= (((skeleton.attack) + ((rand() % skeleton.attack / 2) - (rand() % skeleton.attack / 3))) * ((rand() % 2) + 2)) / (2 + (player.defense / 100));
					
					printf("Enemy critical attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if(skeleton.hp > 0)
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= ((skeleton.attack) + ((rand() % skeleton.attack / 2) - (rand() % skeleton.attack / 3))) / (2 + (player.defense / 100));
					
					printf("Enemy attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else
				{
					break;
				}
				
				printf("Enemy attack = \"%d\"", receive_damage - player.healthpoint);
				delay(1.5);
				break;
			}
			else if(choice == 3)
			{
				monster_strong_attack -= 1;

				player.healthpoint += player.heal;

				if(player.healthpoint >= max_hp)
				{
					player.healthpoint = max_hp;
				}

				printf("\nYou health restore = \" %d \" point.\n", player.heal);
				delay(1.5);
				
				monster_crit = rand() % 15;

				if((monster_strong_attack == 0) && (skeleton.hp > 0))
				{
					monster_strong_attack = 5;

					receive_damage = player.healthpoint;
					player.healthpoint -= (((skeleton.attack) + ((rand() % skeleton.attack / 2) - (rand() % skeleton.attack / 3))) * 1.5) / (1 + (player.defense / 100));
					
					printf("Enemy strong attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if((monster_crit == 14) && (skeleton.hp > 0))
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= (((skeleton.attack) + ((rand() % skeleton.attack / 2) - (rand() % skeleton.attack / 3))) * ((rand() % 2) + 2)) / (1 + (player.defense / 100));
					
					printf("Enemy critical attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if(skeleton.hp > 0)
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= ((skeleton.attack) + ((rand() % skeleton.attack / 2) - (rand() % skeleton.attack / 3))) / (1 + (player.defense / 100));
					
					printf("Enemy attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else
				{
					break;
				}
			}
			else if(choice == 4)
			{
				story = 7.431;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 7.44) //Receive quest to hunt orc
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("You answer that you want to hunt some orcs. She silently nodded with a worried face, then spent some time looking for the paper and handing the quest paper to you.\n\n== You recieve orc hunt quest ==\n\n");
			printf("Type 1 to continue\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				story = 7.441;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 7.441) //Found a group of orc
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			monster_count = (rand() % 2) + 1;

			orc.hp = orc.max_hp;

			printf("At the middle of the forest. You're walking slowly and looking for an orc to hunt when you notice something deep further into the deeper forest. You walk closer to it and discover %d orc.\n\n", monster_count);
			printf("You decide to....\n");
			printf("1. Fight with the orc.\n2. Looking for other orc to hunt.\n3. Go back to the adventure guild.\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				monster_strong_attack = 5;
				story = 7.4411;
				break;
			}
			else if(choice == 2)
			{
				story = 7.441;
			}
			else if(choice == 3)
			{
				story = 7.4;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 7.4411) //Fight group of orc
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			if((monster_strong_attack > 1) && (orc.hp > 0) && (player.healthpoint > 0))
			{
				printf("\"Beware of monster strong attack in %d turns.\"     ", monster_strong_attack);
			}
			else if((monster_strong_attack == 1) && (orc.hp > 0) && (player.healthpoint > 0))
			{
				printf("\"Beware of monster strong attack in next turns.\"     ");
			}

			if((monster_count >= 0) && (orc.hp > 0))
			{
				printf("\"Monster left : %d\"\n", monster_count + 1);
			}
			else
			{
				printf("\n");
			}

			if(player.healthpoint <= 0)
			{
				printf("You cannot defeat it and you decided to run.\n");
				delay(3);
				player.heart -= 1;
				player.healthpoint = max_hp;
				story = 7.441;
				break;
			}
			else if((orc.hp <= 0) && (monster_count > 0))
			{
				player.gold += orc.gold_drop;
				printf("You win the fight.\n\n== Gold + %d ==\n\n", orc.gold_drop);
				delay(3);
				monster_count -= 1;
				orc.hp = orc.max_hp;
				monster_strong_attack = 5;
				break;
			}
			else if((orc.hp <= 0) && (monster_count == 0))
			{
				player.gold += orc.gold_drop;
				printf("You win the fight.\n\n== Gold + %d ==\n\n", orc.gold_drop);
				delay(3);
				story = 7.441;
				break;
			}
			
			for(int j = 0; j < (max_columns /2) - 10; j++)
			{
				printf(" ");
			}

			printf("%s", PowerBar_E[0]);
			
			for(int j = 0; j < (max_columns /2) - 10; j++)
			{
				printf(" ");
			}

			printf("%s", PowerBar_E[1]);
			printf(" %d\n", orc.hp);
			
			Orc();

			printf("1. Attack.\n2. Defend.\n3. Heal.\n4. Escape.\n\n");
			printf("Type : ");

			choice = ScanInput();

			if(choice == 1)
			{
				monster_strong_attack -= 1;

				player_crit = rand() % 5;

				if(player_crit == 4)
				{
					attack_damage = orc.hp;
					orc.hp -= (player.attack + ((rand() % player.attack / 2) - (rand() % player.attack / 3))) * ((rand() % 2) + 2);
				
					printf("\nYour critical attack = \" %d \" damage.\n", attack_damage - orc.hp);
					delay(1.5);
				}
				else
				{
					attack_damage = orc.hp;
					orc.hp -= player.attack + ((rand() % player.attack / 2) - (rand() % player.attack / 3));
				
					printf("\nYour attack = \" %d \" damage.\n", attack_damage - orc.hp);
					delay(1.5);
				}

				monster_crit = rand() % 15;

				if((monster_strong_attack == 0) && (orc.hp > 0))
				{
					monster_strong_attack = 5;

					receive_damage = player.healthpoint;
					player.healthpoint -= (((orc.attack) + ((rand() % orc.attack / 2) - (rand() % orc.attack / 3))) * 1.5) / (1 + (player.defense / 100));
					
					printf("Enemy strong attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if((monster_crit == 14) && (orc.hp > 0))
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= (((orc.attack) + ((rand() % orc.attack / 2) - (rand() % orc.attack / 3))) * ((rand() % 2) + 2)) / (1 + (player.defense / 100));
					
					printf("Enemy critical attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if(orc.hp > 0)
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= ((orc.attack) + ((rand() % orc.attack / 2) - (rand() % orc.attack / 3))) / (1 + (player.defense / 100));
					
					printf("Enemy attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else
				{
					break;
				}
			}
			else if(choice == 2)
			{
				monster_strong_attack -= 1;

				monster_crit = rand() % 15;

				if((monster_strong_attack == 0) && (orc.hp > 0))
				{
					monster_strong_attack = 5;

					receive_damage = player.healthpoint;
					player.healthpoint -= (((orc.attack) + ((rand() % orc.attack / 2) - (rand() % orc.attack / 3))) * 1.5) / (2 + (player.defense / 100));
					
					printf("Enemy strong attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if((monster_crit == 14) && (orc.hp > 0))
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= (((orc.attack) + ((rand() % orc.attack / 2) - (rand() % orc.attack / 3))) * ((rand() % 2) + 2)) / (2 + (player.defense / 100));
					
					printf("Enemy critical attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if(orc.hp > 0)
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= ((orc.attack) + ((rand() % orc.attack / 2) - (rand() % orc.attack / 3))) / (2 + (player.defense / 100));
					
					printf("Enemy attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else
				{
					break;
				}
				
				printf("Enemy attack = \"%d\"", receive_damage - player.healthpoint);
				delay(1.5);
				break;
			}
			else if(choice == 3)
			{
				monster_strong_attack -= 1;

				player.healthpoint += player.heal;

				if(player.healthpoint >= max_hp)
				{
					player.healthpoint = max_hp;
				}

				printf("\nYou health restore = \" %d \" point.\n", player.heal);
				delay(1.5);
				
				monster_crit = rand() % 15;

				if((monster_strong_attack == 0) && (orc.hp > 0))
				{
					monster_strong_attack = 5;

					receive_damage = player.healthpoint;
					player.healthpoint -= (((orc.attack) + ((rand() % orc.attack / 2) - (rand() % orc.attack / 3))) * 1.5) / (1 + (player.defense / 100));
					
					printf("Enemy strong attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if((monster_crit == 14) && (orc.hp > 0))
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= (((orc.attack) + ((rand() % orc.attack / 2) - (rand() % orc.attack / 3))) * ((rand() % 2) + 2)) / (1 + (player.defense / 100));
					
					printf("Enemy critical attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if(orc.hp > 0)
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= ((orc.attack) + ((rand() % orc.attack / 2) - (rand() % orc.attack / 3))) / (1 + (player.defense / 100));
					
					printf("Enemy attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else
				{
					break;
				}
			}
			else if(choice == 4)
			{
				story = 7.441;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 7.45) //Receive quest to hunt troll
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("You answer that you want to hunt some trolls. She silently nodded with a worried face, then spent some time looking for the paper and handing the quest paper to you and warning you.\n\n");
				SpeechBox();
			printf("Troll hunt is our highest quest tier, and trolls are extremely difficult to hunt. Be cautious when confronting and fighting it.\n\n");
				EndTextColor();
			printf("== You recieve troll hunt quest ==\n\n");
			printf("Type 1 to continue\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				story = 7.451;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 7.451) //Found a group of troll
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			monster_count = (rand() % 1) + 1;

			troll.hp = troll.max_hp;

			printf("At the middle of the forest. You're walking slowly and looking for a troll to hunt when you notice something deep further into the deeper forest. You walk closer to it and discover %d troll.\n\n", monster_count);
			printf("You decide to....\n");
			printf("1. Fight with the troll.\n2. Looking for other troll to hunt.\n3. Go back to the adventure guild.\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				monster_strong_attack = 5;
				story = 7.4511;
				break;
			}
			else if(choice == 2)
			{
				story = 7.451;
			}
			else if(choice == 3)
			{
				story = 7.4;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 7.4511) //Fight group of troll
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			if((monster_strong_attack > 1) && (troll.hp > 0) && (player.healthpoint > 0))
			{
				printf("\"Beware of monster strong attack in %d turns.\"     ", monster_strong_attack);
			}
			else if((monster_strong_attack == 1) && (troll.hp > 0) && (player.healthpoint > 0))
			{
				printf("\"Beware of monster strong attack in next turns.\"     ");
			}

			if((monster_count >= 0) && (troll.hp > 0))
			{
				printf("\"Monster left : %d\"\n", monster_count + 1);
			}
			else
			{
				printf("\n");
			}

			if(player.healthpoint <= 0)
			{
				printf("You cannot defeat it and you decided to run.\n");
				delay(3);
				player.heart -= 1;
				player.healthpoint = max_hp;
				story = 7.451;
				break;
			}
			else if((troll.hp <= 0) && (monster_count > 0))
			{
				player.gold += troll.gold_drop;
				printf("You win the fight.\n\n== Gold + %d ==\n\n", troll.gold_drop);
				delay(3);
				monster_count -= 1;
				troll.hp = troll.max_hp;
				monster_strong_attack = 5;
				break;
			}
			else if((troll.hp <= 0) && (monster_count == 0))
			{
				player.gold += troll.gold_drop;
				printf("You win the fight.\n\n== Gold + %d ==\n\n", troll.gold_drop);
				delay(3);
				story = 7.451;
				break;
			}
			
			for(int j = 0; j < (max_columns /2) - 10; j++)
			{
				printf(" ");
			}

			printf("%s", PowerBar_E[0]);
			
			for(int j = 0; j < (max_columns /2) - 10; j++)
			{
				printf(" ");
			}

			printf("%s", PowerBar_E[1]);
			printf(" %d\n", troll.hp);
			
			Troll();

			printf("1. Attack.\n2. Defend.\n3. Heal.\n4. Escape.\n\n");
			printf("Type : ");

			choice = ScanInput();

			if(choice == 1)
			{
				monster_strong_attack -= 1;

				player_crit = rand() % 5;

				if(player_crit == 4)
				{
					attack_damage = troll.hp;
					troll.hp -= (player.attack + ((rand() % player.attack / 2) - (rand() % player.attack / 3))) * ((rand() % 2) + 2);
				
					printf("\nYour critical attack = \" %d \" damage.\n", attack_damage - troll.hp);
					delay(1.5);
				}
				else
				{
					attack_damage = troll.hp;
					troll.hp -= player.attack + ((rand() % player.attack / 2) - (rand() % player.attack / 3));
				
					printf("\nYour attack = \" %d \" damage.\n", attack_damage - troll.hp);
					delay(1.5);
				}

				monster_crit = rand() % 15;

				if((monster_strong_attack == 0) && (troll.hp > 0))
				{
					monster_strong_attack = 5;

					receive_damage = player.healthpoint;
					player.healthpoint -= (((troll.attack) + ((rand() % troll.attack / 2) - (rand() % troll.attack / 3))) * 1.5) / (1 + (player.defense / 100));
					
					printf("Enemy strong attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if((monster_crit == 14) && (troll.hp > 0))
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= (((troll.attack) + ((rand() % troll.attack / 2) - (rand() % troll.attack / 3))) * ((rand() % 2) + 2)) / (1 + (player.defense / 100));
					
					printf("Enemy critical attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if(troll.hp > 0)
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= ((troll.attack) + ((rand() % troll.attack / 2) - (rand() % troll.attack / 3))) / (1 + (player.defense / 100));
					
					printf("Enemy attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else
				{
					break;
				}
			}
			else if(choice == 2)
			{
				monster_strong_attack -= 1;

				monster_crit = rand() % 15;

				if((monster_strong_attack == 0) && (troll.hp > 0))
				{
					monster_strong_attack = 5;

					receive_damage = player.healthpoint;
					player.healthpoint -= (((troll.attack) + ((rand() % troll.attack / 2) - (rand() % troll.attack / 3))) * 1.5) / (2 + (player.defense / 100));
					
					printf("Enemy strong attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if((monster_crit == 14) && (troll.hp > 0))
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= (((troll.attack) + ((rand() % troll.attack / 2) - (rand() % troll.attack / 3))) * ((rand() % 2) + 2)) / (2 + (player.defense / 100));
					
					printf("Enemy critical attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if(troll.hp > 0)
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= ((troll.attack) + ((rand() % troll.attack / 2) - (rand() % troll.attack / 3))) / (2 + (player.defense / 100));
					
					printf("Enemy attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else
				{
					break;
				}
				
				printf("Enemy attack = \"%d\"", receive_damage - player.healthpoint);
				delay(1.5);
				break;
			}
			else if(choice == 3)
			{
				monster_strong_attack -= 1;

				player.healthpoint += player.heal;

				if(player.healthpoint >= max_hp)
				{
					player.healthpoint = max_hp;
				}

				printf("\nYou health restore = \" %d \" point.\n", player.heal);
				delay(1.5);
				
				monster_crit = rand() % 15;

				if((monster_strong_attack == 0) && (troll.hp > 0))
				{
					monster_strong_attack = 5;

					receive_damage = player.healthpoint;
					player.healthpoint -= (((troll.attack) + ((rand() % troll.attack / 2) - (rand() % troll.attack / 3))) * 1.5) / (1 + (player.defense / 100));
					
					printf("Enemy strong attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if((monster_crit == 14) && (troll.hp > 0))
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= (((troll.attack) + ((rand() % troll.attack / 2) - (rand() % troll.attack / 3))) * ((rand() % 2) + 2)) / (1 + (player.defense / 100));
					
					printf("Enemy critical attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if(troll.hp > 0)
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= ((troll.attack) + ((rand() % troll.attack / 2) - (rand() % troll.attack / 3))) / (1 + (player.defense / 100));
					
					printf("Enemy attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else
				{
					break;
				}
			}
			else if(choice == 4)
			{
				story = 7.451;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 8.0) //Found golem
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

            printf("You leave the dawrf town behind and keep walking until you reach the next mountain. At the top, it has a flat space with a huge rock. You look at the rock with suspicious eyes. Not to long after that, the ground around you begins to shake, and the massive rock in front of you begins to form a shape. It's a golem!!\n\n");
			printf("You decide to....\n");
			printf("1. Take a deep breath, maintain your posture, and fight it.\n2. Run!! No matter what. JUST... RUN!!.\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				monster_count = 0;
				monster_strong_attack = 5;
				story = 8.1;
				break;
			}
			else if(choice == 2)
			{
                story = 8.2;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 8.1) //Fight golem
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			if((monster_strong_attack > 1) && (golem.hp > 0) && (player.healthpoint > 0))
			{
				printf("\"Beware of monster strong attack in %d turns.\"     ", monster_strong_attack);
			}
			else if((monster_strong_attack == 1) && (golem.hp > 0) && (player.healthpoint > 0))
			{
				printf("\"Beware of monster strong attack in next turns.\"     ");
			}

			if((monster_count >= 0) && (golem.hp > 0))
			{
				printf("\"Monster left : %d\"\n", monster_count + 1);
			}
			else
			{
				printf("\n");
			}

			if(player.healthpoint <= 0)
			{
				printf("You cannot defeat it and you decided to run.\n");
				delay(3);
				player.heart -= 1;
				player.healthpoint = max_hp;
				story = 8.2;
				break;
			}
			else if((golem.hp <= 0) && (monster_count > 0))
			{
				player.gold += golem.gold_drop;
				printf("You win the fight.\n\n== Gold + %d ==\n\n", golem.gold_drop);
				delay(3);
				monster_count -= 1;
				golem.hp = golem.max_hp;
				monster_strong_attack = 5;
				break;
			}
			else if((golem.hp <= 0) && (monster_count == 0))
			{
				player.gold += golem.gold_drop;
				printf("You win the fight.\n\n== Gold + %d ==\n\n", golem.gold_drop);
				delay(3);
				story = 8.11;
				break;
			}
			
			for(int j = 0; j < (max_columns /2) - 10; j++)
			{
				printf(" ");
			}

			printf("%s", PowerBar_E[0]);
			
			for(int j = 0; j < (max_columns /2) - 10; j++)
			{
				printf(" ");
			}

			printf("%s", PowerBar_E[1]);
			printf(" %d\n", golem.hp);
			
			Golem();

			printf("1. Attack.\n2. Defend.\n3. Heal.\n4. Escape.\n\n");
			printf("Type : ");

			choice = ScanInput();

			if(choice == 1)
			{
				monster_strong_attack -= 1;

				player_crit = rand() % 5;

				if(player_crit == 4)
				{
					attack_damage = golem.hp;
					golem.hp -= (player.attack + ((rand() % player.attack / 2) - (rand() % player.attack / 3))) * ((rand() % 2) + 2);
				
					printf("\nYour critical attack = \" %d \" damage.\n", attack_damage - golem.hp);
					delay(1.5);
				}
				else
				{
					attack_damage = golem.hp;
					golem.hp -= player.attack + ((rand() % player.attack / 2) - (rand() % player.attack / 3));
				
					printf("\nYour attack = \" %d \" damage.\n", attack_damage - golem.hp);
					delay(1.5);
				}

				monster_crit = rand() % 15;

				if((monster_strong_attack == 0) && (golem.hp > 0))
				{
					monster_strong_attack = 5;

					receive_damage = player.healthpoint;
					player.healthpoint -= (((golem.attack) + ((rand() % golem.attack / 2) - (rand() % golem.attack / 3))) * 1.5) / (1 + (player.defense / 100));
					
					printf("Enemy strong attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if((monster_crit == 14) && (golem.hp > 0))
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= (((golem.attack) + ((rand() % golem.attack / 2) - (rand() % golem.attack / 3))) * ((rand() % 2) + 2)) / (1 + (player.defense / 100));
					
					printf("Enemy critical attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if(golem.hp > 0)
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= ((golem.attack) + ((rand() % golem.attack / 2) - (rand() % golem.attack / 3))) / (1 + (player.defense / 100));
					
					printf("Enemy attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else
				{
					break;
				}
			}
			else if(choice == 2)
			{
				monster_strong_attack -= 1;

				monster_crit = rand() % 15;

				if((monster_strong_attack == 0) && (golem.hp > 0))
				{
					monster_strong_attack = 5;

					receive_damage = player.healthpoint;
					player.healthpoint -= (((golem.attack) + ((rand() % golem.attack / 2) - (rand() % golem.attack / 3))) * 1.5) / (2 + (player.defense / 100));
					
					printf("Enemy strong attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if((monster_crit == 14) && (golem.hp > 0))
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= (((golem.attack) + ((rand() % golem.attack / 2) - (rand() % golem.attack / 3))) * ((rand() % 2) + 2)) / (2 + (player.defense / 100));
					
					printf("Enemy critical attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if(golem.hp > 0)
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= ((golem.attack) + ((rand() % golem.attack / 2) - (rand() % golem.attack / 3))) / (2 + (player.defense / 100));
					
					printf("Enemy attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else
				{
					break;
				}
				
				printf("Enemy attack = \"%d\"", receive_damage - player.healthpoint);
				delay(1.5);
				break;
			}
			else if(choice == 3)
			{
				monster_strong_attack -= 1;

				player.healthpoint += player.heal;

				if(player.healthpoint >= max_hp)
				{
					player.healthpoint = max_hp;
				}

				printf("\nYou health restore = \" %d \" point.\n", player.heal);
				delay(1.5);
				
				monster_crit = rand() % 15;

				if((monster_strong_attack == 0) && (golem.hp > 0))
				{
					monster_strong_attack = 5;

					receive_damage = player.healthpoint;
					player.healthpoint -= (((golem.attack) + ((rand() % golem.attack / 2) - (rand() % golem.attack / 3))) * 1.5) / (1 + (player.defense / 100));
					
					printf("Enemy strong attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if((monster_crit == 14) && (golem.hp > 0))
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= (((golem.attack) + ((rand() % golem.attack / 2) - (rand() % golem.attack / 3))) * ((rand() % 2) + 2)) / (1 + (player.defense / 100));
					
					printf("Enemy critical attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if(golem.hp > 0)
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= ((golem.attack) + ((rand() % golem.attack / 2) - (rand() % golem.attack / 3))) / (1 + (player.defense / 100));
					
					printf("Enemy attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else
				{
					break;
				}
			}
			else if(choice == 4)
			{
				story = 8.2;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 8.11) //Golem exploded and you fell into a jungle forest
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

            printf("You fight and defeat the giant golem, then sit down because you are exhausted from the battle. But the golems that fall down start shaking, and before you can do anything, it explode and push you with ginormous power until you bounce off the cliff and fall into the unknown jungle.\n\n");
			printf("Type 1 to continue.\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				printf("Heart - 1\n");
				delay(1.5);
				player.heart -= 1;
				story = 9.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 8.2) //Escape from golem
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

            printf("You run as fast as you can, but the golem can still catch up to you. Then, it punches you with ginormous power, and you bounce off the cliff and fall into the unknown jungle.\n\n");
			printf("Type 1 to continue.\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				printf("Heart - 1\n");
				delay(1.5);
				player.heart -= 1;
				story = 9.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 9.0) //In the middle of the jungle
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

            printf("At somewhere in the jungle forest. You look up at the sky and sigh. Your heart and body are tired and covered with pain, but you still get up and keep walking. It's lonely and dark, and every step you take feels like there are a million eyes watching you. You can't find your way out of the forest after setting up camp and walking for three days. When you are about to give up, you hear some noises and something giggling then suddenly you feel as if something has hit your head. Your vision gradually darkens, but before you close your eyes, you notice more than ten unknown creatures emerge from behind the tree.\n\n");
			printf("Type 1 to continue.\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				story = 9.1;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 9.1) //Kong territory
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

            printf("You get your senses back and slowly open your eyes. The first thing you see is the throne that the monster that looks like a human is sitting on. You try to move your hand, but it's like your hand is tied up with the vines and can't be moved. Now that your eyes are fully opened, you can clearly see that monster. It's a gigantic Kong!! It notices you and then speaks.\n\n");
				MonsterSoundColor();
			printf("\"Ook-ook! Welcome to our empire, strong humans. Do you want to live? human. If you want... Eeek-aak!!! fight me and win!!! Then I will let you survive.\"");
				EndTextColor();
			printf("You decide to....\n");
			printf("1. Accept the duel!!\n2. Try every way possible to escape.\n3. I don't care. Just kill me!!\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				monster_count = 0;
				monster_strong_attack = 5;
				story = 9.11;
				break;
			}
			else if(choice == 2)
			{
				story == 9.12;
				break;
			}
			else if(choice == 3)
			{
				story == 9.13;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 9.11) //Fight with kong
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			if((monster_strong_attack > 1) && (kong.hp > 0) && (player.healthpoint > 0))
			{
				printf("\"Beware of monster strong attack in %d turns.\"     ", monster_strong_attack);
			}
			else if((monster_strong_attack == 1) && (kong.hp > 0) && (player.healthpoint > 0))
			{
				printf("\"Beware of monster strong attack in next turns.\"     ");
			}

			if((monster_count >= 0) && (kong.hp > 0))
			{
				printf("\"Monster left : %d\"\n", monster_count + 1);
			}
			else
			{
				printf("\n");
			}

			if(player.healthpoint <= 0)
			{
				printf("You cannot defeat it and you decided to run.\n");
				delay(3);
				player.heart -= 1;
				player.healthpoint = max_hp;
				story = 9.12;
				break;
			}
			else if((kong.hp <= 0) && (monster_count > 0))
			{
				player.gold += kong.gold_drop;
				printf("You win the fight.\n\n== Gold + %d ==\n\n", kong.gold_drop);
				delay(3);
				monster_count -= 1;
				kong.hp = kong.max_hp;
				monster_strong_attack = 5;
				break;
			}
			else if((kong.hp <= 0) && (monster_count == 0))
			{
				player.gold += kong.gold_drop;
				printf("You win the fight.\n\n== Gold + %d ==\n\n", kong.gold_drop);
				delay(3);
				story = 9.111;
				break;
			}
			
			for(int j = 0; j < (max_columns /2) - 10; j++)
			{
				printf(" ");
			}

			printf("%s", PowerBar_E[0]);
			
			for(int j = 0; j < (max_columns /2) - 10; j++)
			{
				printf(" ");
			}

			printf("%s", PowerBar_E[1]);
			printf(" %d\n", kong.hp);
			
			Kong();

			printf("1. Attack.\n2. Defend.\n3. Heal.\n4. Escape.\n\n");
			printf("Type : ");

			choice = ScanInput();

			if(choice == 1)
			{
				monster_strong_attack -= 1;

				player_crit = rand() % 5;

				if(player_crit == 4)
				{
					attack_damage = kong.hp;
					kong.hp -= (player.attack + ((rand() % player.attack / 2) - (rand() % player.attack / 3))) * ((rand() % 2) + 2);
				
					printf("\nYour critical attack = \" %d \" damage.\n", attack_damage - kong.hp);
					delay(1.5);
				}
				else
				{
					attack_damage = kong.hp;
					kong.hp -= player.attack + ((rand() % player.attack / 2) - (rand() % player.attack / 3));
				
					printf("\nYour attack = \" %d \" damage.\n", attack_damage - kong.hp);
					delay(1.5);
				}

				monster_crit = rand() % 15;

				if((monster_strong_attack == 0) && (kong.hp > 0))
				{
					monster_strong_attack = 5;

					receive_damage = player.healthpoint;
					player.healthpoint -= (((kong.attack) + ((rand() % kong.attack / 2) - (rand() % kong.attack / 3))) * 1.5) / (1 + (player.defense / 100));
					
					printf("Enemy strong attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if((monster_crit == 14) && (kong.hp > 0))
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= (((kong.attack) + ((rand() % kong.attack / 2) - (rand() % kong.attack / 3))) * ((rand() % 2) + 2)) / (1 + (player.defense / 100));
					
					printf("Enemy critical attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if(kong.hp > 0)
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= ((kong.attack) + ((rand() % kong.attack / 2) - (rand() % kong.attack / 3))) / (1 + (player.defense / 100));
					
					printf("Enemy attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else
				{
					break;
				}
			}
			else if(choice == 2)
			{
				monster_strong_attack -= 1;

				monster_crit = rand() % 15;

				if((monster_strong_attack == 0) && (kong.hp > 0))
				{
					monster_strong_attack = 5;

					receive_damage = player.healthpoint;
					player.healthpoint -= (((kong.attack) + ((rand() % kong.attack / 2) - (rand() % kong.attack / 3))) * 1.5) / (2 + (player.defense / 100));
					
					printf("Enemy strong attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if((monster_crit == 14) && (kong.hp > 0))
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= (((kong.attack) + ((rand() % kong.attack / 2) - (rand() % kong.attack / 3))) * ((rand() % 2) + 2)) / (2 + (player.defense / 100));
					
					printf("Enemy critical attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if(kong.hp > 0)
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= ((kong.attack) + ((rand() % kong.attack / 2) - (rand() % kong.attack / 3))) / (2 + (player.defense / 100));
					
					printf("Enemy attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else
				{
					break;
				}
				
				printf("Enemy attack = \"%d\"", receive_damage - player.healthpoint);
				delay(1.5);
				break;
			}
			else if(choice == 3)
			{
				monster_strong_attack -= 1;

				player.healthpoint += player.heal;

				if(player.healthpoint >= max_hp)
				{
					player.healthpoint = max_hp;
				}

				printf("\nYou health restore = \" %d \" point.\n", player.heal);
				delay(1.5);
				
				monster_crit = rand() % 15;

				if((monster_strong_attack == 0) && (kong.hp > 0))
				{
					monster_strong_attack = 5;

					receive_damage = player.healthpoint;
					player.healthpoint -= (((kong.attack) + ((rand() % kong.attack / 2) - (rand() % kong.attack / 3))) * 1.5) / (1 + (player.defense / 100));
					
					printf("Enemy strong attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if((monster_crit == 14) && (kong.hp > 0))
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= (((kong.attack) + ((rand() % kong.attack / 2) - (rand() % kong.attack / 3))) * ((rand() % 2) + 2)) / (1 + (player.defense / 100));
					
					printf("Enemy critical attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if(kong.hp > 0)
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= ((kong.attack) + ((rand() % kong.attack / 2) - (rand() % kong.attack / 3))) / (1 + (player.defense / 100));
					
					printf("Enemy attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else
				{
					break;
				}
			}
			else if(choice == 4)
			{
				story = 9.12;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 9.111) //Win the fight with kong
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;
				MonsterSoundColor();
            printf("Ook-ook! Strong human. As I promised, my soldier will lead you to the way out of this jungle forest. But here, take this. That is my gift for the strong human like you. It is a very fun fight. See you... human... Eeek-aak-eek!\n\n");
				EndTextColor();
			printf("== Recieve mysterious amulet ==\n== Health Point + 50 ==\n== Attack + 20 ==\n== Defense + 20 ==\n== Heal Power + 50 ==\n\n");
			printf("Type 1 to continue.\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				player.healthpoint += 50;
				player.attack += 20;
				player.defense += 20;
				player.heal += 50;
				story = 10.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 9.12) //Try every way possible to escape
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("It's been 5 days. And you mysteriously appear to be surviving at the edge of the jungle forest. You use every last bit of your power to walk a bit further, but you pass out at a small tree in the middle of the way.\n\n");
			printf("Type 1 to continue.\n\n");
			printf("Type : ");

			choice = ScanInput();

			if(choice == 1)
			{
				player.heart -= 1;
				story = 10.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}
		}
		while(story == 9.13) //Answer I don't care. Just kill me!!
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

            printf("You yell at that gigantic Kong monster, that I don't care. Just kill me!!. When the Kong heard you answer, he slapped his knee once and say.\n\n");
				MonsterSoundColor();
			printf("\"Ook-aak!! Ha!!! I'm disappointed in you. Human. Soldier!! Drag him out of my sight and throw this human away at the edge of the forest!!!\"");
				EndTextColor();
			printf("Type 1 to continue.\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				player.heart -= 2;
				story = 10.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 10.0) //The mysterious merchant
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("You can finally get out of the jungle forest and still keep walking. Then, out of nowhere, someone with their entire body covered up until the top of their head approaches you and speaks to you.\n\n");
				SpeechBox();
			printf("\"Hello stanger!! After this road is a dragon's nest!! Stanger!!. Ya want to buyin somethin'?? I really got some rare things on sale that might interest ya, stranger!! Wanna buy some??\"\n\n");
				EndTextColor();
			printf("You decide to....\n");
			printf("1. Take a look at what this man has to sell.\n2. Pass by.\n\n");
			printf("Type : ");

			choice = ScanInput();

			if(choice == 1)
			{
				story = 10.1;
				break;
			}
			else if(choice == 2)
			{
				story == 11.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}
		}
		while(story == 10.1) //The mysterious merchant shop list
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;
			
			SpeechBox();
			printf("\" Welcome adventure!! Got some rare things on sale!! What you want to buy in our shop?\"\n\n");
				EndTextColor();
			printf("1. Huge attack potion\n\tPrice 200 gold\n\tAttack + 15\n2. Huge defense potion\n\tPrice 200 gold\n\tDefense + 15\n3. Huge healty potion.\n\tPrice 200 gold\n\tHealth Point + 100\n 4. Highest grade holy potion.\n\tPrice 100 gold\n\tHeal Power + 25\n5. Life Potion\n\tPrice 300\n\tHeart + 1\n6. Recovery potion.\n\tPrice 100 gold\n\tRestore all health\n7. Exit the shop.\n\n");
			printf("Type : ");

			choice = ScanInput();

			if((choice == 1) && (player.gold >= 200))
			{
				printf("== Attack + 15 ==\n");
				delay(1.5);
				player.attack += 15;
				player.gold -= 200;
				break;
			}
			else if((choice == 1) && (player.gold < 200))
			{
				printf("Not enough gold, stranger!!!\n");
				delay(1.5);
				break;
			}
			else if((choice == 2) && (player.gold >= 200))
			{
				printf("== Defense + 15 ==\n");
				delay(1.5);
				player.defense += 15;
				player.gold -= 200;
				break;
			}
			else if((choice == 2) && (player.gold < 200))
			{
				printf("Not enough gold, stranger!!!\n");
				delay(1.5);
				break;
			}
			else if((choice == 3) && (player.gold >= 200))
			{
				printf("== Health Point + 100 ==\n");
				delay(1.5);
				player.healthpoint += 100;
				max_hp += 100;
				player.gold -= 200;
				break;
			}
			else if((choice == 3) && (player.gold < 200))
			{
				printf("Not enough gold, stranger!!!\n");
				delay(1.5);
				break;
			}
			else if((choice == 4) && (player.gold >= 100))
			{
				printf("== Heal Power + 25 ==\n");
				delay(1.5);
				player.heal += 25;
				player.gold -= 100;
				break;
			}
			else if((choice == 4) && (player.gold < 100))
			{
				printf("Not enough gold, stranger!!!\n");
				delay(1.5);
				break;
			}
			else if((choice == 5) && (player.gold >= 300))
			{
				printf("== Heal Power + 25 ==\n");
				delay(1.5);
				player.heart += 1;
				player.gold -= 300;
				break;
			}
			else if((choice == 5) && (player.gold < 300))
			{
				printf("Not enough gold, stranger!!!\n");
				delay(1.5);
				break;
			}
			else if((choice == 6) && (player.gold >= 100) && (player.healthpoint < max_hp))
			{
				printf("== Restore all health ==\n");
				delay(1.5);
				player.healthpoint = max_hp;
				player.gold -= 100;
				break;
			}
			else if((choice == 6) && (player.gold >= 100) && (player.healthpoint = max_hp))
			{
				printf("You are already at full health. Do not waste money!!!\n");
				delay(1.5);
				break;
			}
			else if((choice == 6) && (player.gold < 100) && (player.healthpoint < max_hp))
			{
				printf("Not enough gold, stranger!!!\n");
				delay(1.5);
				break;
			}
			else if(choice == 7)
			{
				story = 11.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

			if(player.heart == 0)
			{
				game = 1;
				break;
			}
		}
		while(story == 11.1) //Found dragon
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

            printf("You are still walking. But you notice that the heat is slowly rising and the air is also drying out. Then, not too long into the walk, you can clearly see all the trees that burned into the ash and all the dirt that is filled with hot liquid red rock. Then you hear something roar, and the sound of gigantic wings flapping is coming toward you. Then something as large as a mountain lands and roars in front of you, and then it speaks.\n\n");
				MonsterSoundColor();
			printf("\"Roarrrr....!!!! Get out of my territory right now, human. If not, then I have no choice but to burn you into ashes. This is my only warning!!!\"");
				EndTextColor();
			printf("You decide to....\n");
			printf("1. Close your eyes, take a deep breath, maintain your posture, strengthen your body, and fight it.\n2. Turn around and find another way to go.\n\n");
			printf("Type : ");
			
			choice = ScanInput();

			if(choice == 1)
			{
				monster_count = 0;
				monster_strong_attack = 5;
				story = 11.11;
				break;
			}
			else if(choice == 2)
			{
                game = 1;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
		while(story == 11.11) //Fight the dragon
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			if((monster_strong_attack > 1) && (dragon.hp > 0) && (player.healthpoint > 0))
			{
				printf("\"Beware of monster strong attack in %d turns.\"     ", monster_strong_attack);
			}
			else if((monster_strong_attack == 1) && (dragon.hp > 0) && (player.healthpoint > 0))
			{
				printf("\"Beware of monster strong attack in next turns.\"     ");
			}

			if(monster_count >= 1)
			{
				printf("\"Monster left : %d\"\n", monster_count);
			}
			else
			{
				printf("\n");
			}

			if(player.healthpoint <= 0)
			{
				printf("You cannot defeat it and you decided to run.\n");
				delay(3);
				player.heart -= 1;
				player.healthpoint = max_hp;
				game = 1;
				break;
			}
			else if((dragon.hp <= 0) && (monster_count > 0))
			{
				player.gold += dragon.gold_drop;
				printf("You win the fight.\n\n== Gold + %d ==\n\n", dragon.gold_drop);
				delay(3);
				monster_count -= 1;
				dragon.hp = dragon.max_hp;
				monster_strong_attack = 5;
				break;
			}
			else if((dragon.hp <= 0) && (monster_count == 0))
			{
				player.gold += dragon.gold_drop;
				printf("You win the fight.\n\n== Gold + %d ==\n\n", dragon.gold_drop);
				delay(3);
				progress = 1;
				game = 1;
				break;
			}
			
			for(int j = 0; j < (max_columns /2) - 10; j++)
			{
				printf(" ");
			}

			printf("%s", PowerBar_E[0]);
			
			for(int j = 0; j < (max_columns /2) - 10; j++)
			{
				printf(" ");
			}

			printf("%s", PowerBar_E[1]);
			printf(" %d\n", dragon.hp);
			
			Dragon();

			printf("1. Attack.\n2. Defend.\n3. Heal.\n4. Escape.\n\n");
			printf("Type : ");

			choice = ScanInput();

			if(choice == 1)
			{
				monster_strong_attack -= 1;

				player_crit = rand() % 5;

				if(player_crit == 4)
				{
					attack_damage = dragon.hp;
					dragon.hp -= (player.attack + ((rand() % player.attack / 2) - (rand() % player.attack / 3))) * ((rand() % 2) + 2);
				
					printf("\nYour critical attack = \" %d \" damage.\n", attack_damage - dragon.hp);
					delay(1.5);
				}
				else
				{
					attack_damage = dragon.hp;
					dragon.hp -= player.attack + ((rand() % player.attack / 2) - (rand() % player.attack / 3));
				
					printf("\nYour attack = \" %d \" damage.\n", attack_damage - dragon.hp);
					delay(1.5);
				}

				monster_crit = rand() % 15;

				if((monster_strong_attack == 0) && (dragon.hp > 0))
				{
					monster_strong_attack = 5;

					receive_damage = player.healthpoint;
					player.healthpoint -= (((dragon.attack) + ((rand() % dragon.attack / 2) - (rand() % dragon.attack / 3))) * 1.5) / (1 + (player.defense / 100));
					
					printf("Enemy strong attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if((monster_crit == 14) && (dragon.hp > 0))
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= (((dragon.attack) + ((rand() % dragon.attack / 2) - (rand() % dragon.attack / 3))) * ((rand() % 2) + 2)) / (1 + (player.defense / 100));
					
					printf("Enemy critical attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if(dragon.hp > 0)
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= ((dragon.attack) + ((rand() % dragon.attack / 2) - (rand() % dragon.attack / 3))) / (1 + (player.defense / 100));
					
					printf("Enemy attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else
				{
					break;
				}
			}
			else if(choice == 2)
			{
				monster_strong_attack -= 1;

				monster_crit = rand() % 15;

				if((monster_strong_attack == 0) && (dragon.hp > 0))
				{
					monster_strong_attack = 5;

					receive_damage = player.healthpoint;
					player.healthpoint -= (((dragon.attack) + ((rand() % dragon.attack / 2) - (rand() % dragon.attack / 3))) * 1.5) / (2 + (player.defense / 100));
					
					printf("Enemy strong attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if((monster_crit == 14) && (dragon.hp > 0))
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= (((dragon.attack) + ((rand() % dragon.attack / 2) - (rand() % dragon.attack / 3))) * ((rand() % 2) + 2)) / (2 + (player.defense / 100));
					
					printf("Enemy critical attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if(dragon.hp > 0)
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= ((dragon.attack) + ((rand() % dragon.attack / 2) - (rand() % dragon.attack / 3))) / (2 + (player.defense / 100));
					
					printf("Enemy attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else
				{
					break;
				}
				
				printf("Enemy attack = \"%d\"", receive_damage - player.healthpoint);
				delay(1.5);
				break;
			}
			else if(choice == 3)
			{
				monster_strong_attack -= 1;

				player.healthpoint += player.heal;

				if(player.healthpoint >= max_hp)
				{
					player.healthpoint = max_hp;
				}

				printf("\nYou health restore = \" %d \" point.\n", player.heal);
				delay(1.5);
				
				monster_crit = rand() % 15;

				if((monster_strong_attack == 0) && (dragon.hp > 0))
				{
					monster_strong_attack = 5;

					receive_damage = player.healthpoint;
					player.healthpoint -= (((dragon.attack) + ((rand() % dragon.attack / 2) - (rand() % dragon.attack / 3))) * 1.5) / (1 + (player.defense / 100));
					
					printf("Enemy strong attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if((monster_crit == 14) && (dragon.hp > 0))
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= (((dragon.attack) + ((rand() % dragon.attack / 2) - (rand() % dragon.attack / 3))) * ((rand() % 2) + 2)) / (1 + (player.defense / 100));
					
					printf("Enemy critical attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else if(dragon.hp > 0)
				{
					receive_damage = player.healthpoint;
					player.healthpoint -= ((dragon.attack) + ((rand() % dragon.attack / 2) - (rand() % dragon.attack / 3))) / (1 + (player.defense / 100));
					
					printf("Enemy attack = \" %d \" damage.\n", receive_damage - player.healthpoint);
					delay(1.5);
					break;
				}
				else
				{
					break;
				}
			}
			else if(choice == 4)
			{
				game = 1;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}

            if(player.heart == 0)
            {
                game = 1;
                break;
            }
		}
	}

	ClearScreen();

	if((game == 1) && (progress == 1))
	{
		printf("You are the greatest hero who defeated the dragon. Your name and story will be known throughout the world, and it will be recorded in world history. Everyone will remember it even after the century has passed.\n\n");
	}
	else if((game == 1) && (progress == 0))
	{
		printf("You are a regular adventurer who travels the world creating stories and frames. Your name and story will be remembered by someone.\n\n");
	}

	printf("\"THANK YOU FOR PLAYING OUR GAME\"\n\n\"END\"\n\n");

	printf("This is you final score.\n\n");

	PrintInfo(player, wrong_chioce);
	
	return 1;
}

int ScanInput()
{
	char input[1000];

	scanf("%s", &input);

	if(isdigit(input[0]) && strlen(input) <= 1)
	{	
		return input[0] - 48;
	}
	else
	{
		return 0;
	}
}

void ClearScreen()
{
	system("cls");
}

void delay(float number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;
 
    clock_t start_time = clock();
 
    while (clock() < start_time + milli_seconds);
}

void NameColor()
{
	printf("\033[0;36m");
}

void SpeechBox()
{
	printf("\033[0;33m");
}

void MonsterSoundColor()
{
	printf("\033[0;31m");
}

void EndTextColor()
{
	printf("\033[0m");
}

void Slime()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
    
	int columns;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.dwSize.X;

	char slime[6][150] =  
	 {{"   ___________    \n"}
	, {"  /           \\ \n"}
	, {" /             \\\n"}
	, {"|     o   o     |\n"}
	, {"|               |\n"}
	, {" \\_____________/ \n"}};

	for(int i = 0; i < 6; i++)
	{
		for(int j = 0; j < (columns / 2) - 9; j++)
		{
			printf(" ");
		}
	
		printf("%s", slime[i]);
	}

	for(int i = 0; i < 19; i++)
	{
		printf("\n");
	}

	for(int i = 0; i < columns; i++)
	{
		printf("=");
	}

	printf("\n");
}

void Wolf()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
    
	int columns;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.dwSize.X;

	char wolf[14][150] =
	 {{"                                                77777?7777777 \n"}
	, {"                     wwwwwwwwwwwVVVVww  YYYNNN//       777    \n"}
	, {"                  ww?                 ?w??           777      \n"}
	, {"               +++    //...                   WWW  >N7        \n"}
	, {"EEEERRR++++++EEII   <_|_]                      WWWWN          \n"}
	, {"e   }                                         Www             \n"}
	, {" WWe                                          RRR             \n"}
	, {"  WWi       A                                 ? WWW           \n"}
	, {"    ii_____AA                        |\\         ?RRWWWWw     \n"}
	, {"     RRRRRRR>>>                        \\\\||//???MMTTTTTW    \n"}
	, {"             \\RRvTTTTTww                    \\WWWWWWWWWWWW   \n"}
	, {"                vTTTTTwwRRRRR               \\\\PPPPPPPPPPPP  \n"}
	, {"                vTTTTTwwRRR                  \\\\PPPPPPPPPPPP \n"}  
	, {"                 vTTTTT_____________________________________\\\n"}};

	for(int i = 0; i < 14; i++)
	{
		for(int j = 0; j < (columns / 2) - 31; j++)
		{
			printf(" ");
		}
		printf("%s", wolf[i]);
	}

	for(int i = 0; i < 11; i++)
	{
		printf("\n");
	}

	for(int i = 0; i < columns; i++)
	{
		printf("=");
	}

	printf("\n");
}

void Skeleton()
{	
	CONSOLE_SCREEN_BUFFER_INFO csbi;
    
	int columns;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.dwSize.X;

	char skeleton[16][150] = 
	 {{"          ________             \n"}
	, {"         /        \\           \n"}
	, {"       /            \\         \n"}
	, {"      |    _     _   |         \n"}
	, {"      |   |_|   |_|  |         \n"}
	, {"       \\     A      /         \n"}
	, {"        |           |          \n"}
	, {"        \\__ |   |__/          \n"}
	, {"            |_|_|              \n"}
	, {"             |||               \n"}
	, {"  //{{UU===//|||\\\\===UU}}\\\\\n"}
	, {"|||   [_[_[__|||__]_]_]   |||  \n"} 
	, {"|||          |||          |||  \n"}  
	, {"|||   [_[_[__|||__]_]_]   |||  \n"} 
	, {"|||          |||          |||  \n"}
	, {"|||   [_[_[__|||__]_]_]   |||  \n"}};

	for(int i = 0; i < 16; i++)
	{
		for(int j = 0; j < (columns / 2) - 15; j++)
		{
			printf(" ");
		}
		printf("%s", skeleton[i]);
	}

	for(int i = 0; i < 9; i++)
	{
		printf("\n");
	}

	for(int i = 0; i < columns; i++)
	{
		printf("=");
	}

	printf("\n");
}

void Orc()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
    
	int columns;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.dwSize.X;

	char orc[17][150] = 
	 {{"                                  ^            ^              \n"}
	, {"                            //MMM/ |WWWWWW\\  / |             \n"}
	, {"                         W??   /   /     \\W7   /             \n"}
	, {"                        WW    /    /       /   /              \n"}
	, {"                   ^    W                      W?             \n"}
	, {"                  | \\ |                         W|           \n"}
	, {"                  \\ \\\\                         R           \n"}
	, {"                   | \\\\                         |           \n"}
	, {"                  /              {O}       {O}   |            \n"}
	, {"                  o //||                         R            \n"}
	, {"                     WWW                        RU            \n"}
	, {"                      RR                        PP            \n"}
	, {"                    R?? ||      _----------_   ??             \n"}
	, {"                  EE      ||   /\\  /  \\  / \\               \n"}
	, {"               EE/          \\    \\/    \\/ //\\\\           \n"}
	, {"  o===========TTT            \\           //eeeEE========o    \n"}
	, {"//_____________________________\\________/eeeeerr_________\\\\\n"}};

	for(int i = 0; i < 17; i++)
	{
		for(int j = 0; j < (columns / 2) - 30; j++)
		{
			printf(" ");
		}
		printf("%s", orc[i]);
	}

	for(int i = 0; i < 8; i++)
	{
		printf("\n");
	}

	for(int i = 0; i < columns; i++)
	{
		printf("=");
	}

	printf("\n");
}

void Troll()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
    
	int columns;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.dwSize.X;
	
	char troll[14][150] =
	 {{"______               ______  \n"} 
	, {"\\. \\  \\             /  / /\n"}
	, {"  \\.\\  \\___________/_./ / \n"}
	, {"    \\.                \\/   \n"}
	, {"      |               |      \n"}
	, {"      |     []     [] |      \n"}
	, {"      \\_______________/     \n"}
	, {"          _/     \\_         \n"}
	, {"        _/         \\_       \n"}
	, {"       /   /       \\ \\     \n"}
	, {"      /   /         | \\     \n"}
	, {"     /    |       __/  \\    \n"}
	, {"    /     |    /\\   |   \\  \n"}
	, {"    \\__U__/___/ |___|_U_/   \n"}};

	for(int i = 0; i < 14; i++)
	{
		for(int j = 0; j < (columns / 2) - 15; j++)
		{
			printf(" ");
		}
	
		printf("%s", troll[i]);
	}

	for(int i = 0; i < 11; i++)
	{
		printf("\n");
	}

	for(int i = 0; i < columns; i++)
	{
		printf("=");
	}

	printf("\n");

}

void Golem()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
    
	int columns;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.dwSize.X;

	char golem[18][150] =  
	 {{"   _______________                            _______________     \n"} 
	, {"  /               \\_________________________/               \\   \n"}
	, {" /                /   _      _    \\         |                \\  \n"}
	, {"|                 |  |_|    |_|   |         |                  |  \n"}
	, {"|                 |               |       //|                  |  \n"}
	, {"|                _|_  _   _   ___ |       //|                  |  \n"}
	, {" \\              |  |_| |_| |_|  |_|=====//|||                /   \n"}
	, {"  \\_____________|                 |      |   \\_____________/    \n"}
	, {"      [0       0\\_________________/      |       [0       0]     \n"}
	, {"      [0_______0]  |                      /       [0_______0]     \n"}
	, {"      [0_______0]  |                      \\      [0_______0]     \n"}
	, {"     _[0_______0]   |                     \\      [0_______0]_    \n"}
	, {"    /           \\   \\                    \\     /            \\ \n"}
	, {"   /             \\   \\                    \\   /              \\\n"}
	, {"  |              |    \\                    \\  |                |\n"}
	, {"  |              |     \\____________________\\ |                |\n"}
	, {"  |              |     \\____________________\\ |                |\n"}				   
	, {"  |______________|_____|______________________|_|________________|\n"}};

	for(int i = 0; i < 18; i++)
	{
		for(int j = 0; j < (columns / 2) - 33; j++)
		{
			printf(" ");
		}
		printf("%s", golem[i]);
	}

	for(int i = 0; i < 7; i++)
	{
		printf("\n");
	}

	for(int i = 0; i < columns; i++)
	{
		printf("=");
	}

	printf("\n");
}

void Kong()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
    
	int columns;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.dwSize.X;

	char kong[18][150] =   
	 {{"                                        ,mmmmmMMMMMmmmmm,                                     \n"} 
	, {"                                     //                  \\\\                                 \n"}
	, {"                                    //                    \\\\                                \n"}
	, {"                                   //                       \\\\                              \n"}
	, {"                          __     //      \\             /     \\\\    __                      \n"}
	, {"                         |  \\\\ //     __ \\_        _/ __    \\\\ //  |                     \n"}
	, {"                         |   \\ ||    /_O_\\ \\      / /_O_\\    ||/    |                     \n"}
	, {"                         \\   \\|             _    _            //     /                      \n"}
	, {"                         ||    |           /_|  |_\\            |    ||                       \n"}
	, {"                         \\                _________                 /                        \n"}
	, {"                          \\___/\\         /_________\\        /\\__/                         \n"}
	, {"                            ??   \\      //VVVVVVVVV\\\\      / ??                            \n"}
	, {"                           AAA    |    // _________ \\\\     | AAA                            \n"}
	, {"                        AA        |   || /    |    \\ ||    |    AA                           \n"}
	, {"      /ppppppppp      AA           |  ||/     |     \\||    |      AA     ppppppppp\\         \n"}
	, {"    //         \\WWWWW              |  ||\\           /||  |          WWW/           \\\\     \n"}
	, {"  //            \\WWWWW             \\  || \\         / ||  /        WWW/              \\\\   \n"}
	, {"//_______________\\WWW_______________\\__\\\\_\\_______/_//__/________WWW_________________\\\\\n"}};

	for(int i = 0; i < 18; i++)
	{
		for(int j = 0; j < (columns / 2) - 46; j++)
		{
			printf(" ");
		}
		printf("%s", kong[i]);
	}
	
	for(int i = 0; i < 7; i++)
	{
		printf("\n");
	}
	
	for(int i = 0; i < columns; i++)
	{
		printf("=");
	}

	printf("\n");
}

void Dragon()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
    
	int columns;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.dwSize.X;

	char dragon[22][150] = 
	 {{"<<---<<<<<<<<<<<<<<=============\\                                                                   \n"}
	, {"\\____                          \\                                /\\          /\\                   \n"}
	, {"  \\______                      \\__                             /  \\        /  \\                  \n"}
	, {"          \\_                      \\                            \\  \\        \\  \\                \n"}
	, {"             \\                      \\__                        \\   \\       \\   \\               \n"}
	, {"             \\                         \\_                      \\     \\      \\    \\             \n"}
	, {"             \\                           \\                      \\     \\\\    \\     \\           \n"}
	, {"             |                            \\_                    //|   /  \\\\ //    \\\\\\          \n"}
	, {"            /            _____               \\               <<//  \\_/    \\\\_\\__// \\\\^\\      \n"}
	, {"           /          __/      \\              \\             <<//                        |          \n"}
	, {"         /          _/            \\______       \\          <<//           ^\\__    \\_    \\       \n"}
	, {"       /        ___/                         >>>>>       <<//               <<\\   <<\\_^  \\        \n"}
	, {"     /        _/  /                        //         <<//                 <_|_\\_  <_|_\\ /         \n"}
	, {"    /       _/  /                         //        <<//                                  \\         \n"}
	, {"  /       /    /                         //       <<//                                    ^\\   A    \n"}
	, {" /      /     /                         //      <<//                  ----                 \\^\\/ \\ \n"}
	, {" /    /      /                         ||    <<//                    /    V\\__             _    \\  \n"}
	, {"/    /      /                         //    <<//                  __/     <<>>\\_\\           \\   \\\n"}
	, {"|  /       /                          ||   <<//                  /_________ //vv\\_vV\\      _/  //  \n"}
	, {"| /         \\                           \\  <<//                _/        //>>       \\_V\\_______/ \n"}
	, {"||           \\                          \\<<//                /_________//>>                        \n"}
	, {"|              \\________________________\\<<//_______________|_________\\\\>>                       \n"}};

	for(int i = 0; i < 22; i++)
	{
		for(int j = 0; j < (columns / 2) - 50; j++)
		{
			printf(" ");
		}
		printf("%s", dragon[i]);
	}

	for(int i = 0; i < 3; i++)
	{
		printf("\n");
	}

	for(int i = 0; i < columns; i++)
	{
		printf("=");
	}

	printf("\n");
}

void FullScreen()
{
	int choice, not_full_screen;

	not_full_screen = 0;

	do
	{
		ClearScreen();

		if(not_full_screen == 0)
		{
			printf("Please use full screen mode for better experince!!\n");
			printf("Using full screen right now?\n\nType 1 if using full screen.\nType other number if not using full screen.\n\n");
			printf("Type : ");
		}
		else if(not_full_screen == 1)
		{
			printf("Please.....\n");
			delay(2.5);
			ClearScreen();
			printf("Please use full screen mode for better experince!!\n\n");
			printf("Using full screen right now?\nType 1 if using full screen.\nType other number if not using full screen.\n\n");
			printf("Type : ");
		}
		else
		{
			printf("Please..... The game title might be broken... Please.....\n");
			delay(3.5);
			ClearScreen();
			printf("Please use full screen mode for better experince!!\n\n");
			printf("Using full screen right now?\nType 1 if using full screen.\nType other number if not using full screen.\n\n");
			printf("Type : ");
		}
		
		choice = ScanInput();

		if(choice != 1)
		{
			not_full_screen += 1;
		}

		if(not_full_screen == 3)
		{
			ClearScreen();

			printf("Fine....\n");
			delay(1);
			printf("GOOD LUCK!!!\n");
			delay(1.5);
			printf("HAVE FUN!!!\n");
			delay(2.5);
			break;
		}
	}while (choice != 1);
}

void GameTitle()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    
	int columns;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.dwSize.X;

	char game_cover[7][150] = 
	 {{"                                             #######   ######    ######                                                  \n"}
	, {"                                             #      #  #     #  #      #                                                 \n"}
	, {"#######  ######  #   #  #######              #      #  #     #  #                     #######  #     #  ######   #     # \n"}
	, {"   #     #        # #      #      ########   #######   ######   # ######   ########      #     #     #  #     #  # #   # \n"}
	, {"   #     ######    #       #                 #   #     #        #      #                 #     #     #  ######   #  #  # \n"}
	, {"   #     #        # #      #                 #    #    #        #      #                 #     #     #  #  #     #   # # \n"}
	, {"   #     ######  #   #     #                 #     #   #         ######                  #      #####   #    #   #     # \n"}};

	ClearScreen();

	for(int i = 0; i < columns; i++)
	{
		printf("=");
	}
	
	printf("\n");

	for(int i = 0; i < 7; i++)
	{
		for(int j = 0; j < (columns / 2) - 61; j++)
		{
			printf(" ");
		}
	
		printf("%s",game_cover[i]);
	}

	for(int i = 0; i < columns; i++)
	{
		printf("=");
	}
	
	printf("\n");
}

void TitleChoice()
{
	char choice;
	
	printf("Type 1 to start the game.\nType 2 to quit the game.\n\n");
	printf("Type : ");
	
	choice = ScanInput();

	if(choice == 1)
	{
		ClearScreen();
	}
	else if(choice == 2)
	{
		exit(0);
	}
	else
	{
		GameTitle();
		TitleChoice();
	}
}

void PrintInfo(Character player ,int wrong_chioce)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
    
	int columns;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.dwSize.X;

	if(wrong_chioce == 1)
	{
		ClearScreen();
		printf("\033[0;34m");
		printf("Not that choice try agian!!!\n\n");
		printf("\033[0m");
	}

	for(int i = 0; i < columns; i++)
	{
		printf("=");
	}

		NameColor();
	printf("%s\n",player.name);
		EndTextColor();
	printf("Heart %d ", player.heart);
	
	if(player.healthpoint <= 0)
	{
		printf("| Health Point 0 ");
	}
	else
	{
		printf("| Health Point %d ", player.healthpoint);
	}

	printf("| Heal Power %d\n",player.heal);
	printf("Gold %d\nAttack %d | Armor %d\n", player.gold, player.attack, player.defense);
	
	for(int i = 0; i < columns; i++)
	{
		printf("=");
	}
}

Character CharacterName(Character player)
{
	printf("Enter your character name (no more than 100 characters): ");
	scanf("%s", player.name);
	printf("Welcome ");
		NameColor();
	printf("%s ", player.name);
		EndTextColor();
	printf("to The new World and The new Adventure.\n");
		delay(3.5);
	printf("It is time to begin your story.......\n");
		delay(2.5);
		
	return player;	
}