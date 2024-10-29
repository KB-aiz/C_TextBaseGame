#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <direct.h>
//CS102
//Game Creation Project
//Group 5
//Text Turn RPG

void SpeechBox()
{
	printf("\033[0;33m");
}

void EndTextColor()
{
	printf("\033[0m");
}

void ClearScreen()
{
	system("cls");
}

void GameTitle()
{
	char *game_cover =	"==================================================================================================================================================================================================================\n"
						"	                                                 #######   ######    ######                                                  \n"
						"	                                                 #      #  #     #  #      #                                                 \n"
						"	    #######  ######  #   #  #######              #      #  #     #  #                     #######  #     #  ######   #     # \n"
						"	       #     #        # #      #      ########   #######   ######   # ######   ########      #     #     #  #     #  # #   # \n"
						"	       #     ######    #       #                 #   #     #        #      #                 #     #     #  ######   #  #  # \n"
						"	       #     #        # #      #                 #    #    #        #      #                 #     #     #  #  #     #   # # \n"
						"	       #     ######  #   #     #                 #     #   #         ######                  #      #####   #    #   #     # \n"
						"==================================================================================================================================================================================================================\n";

	printf("%s\n", game_cover);
}

void TitleChoice()
{
	char choice;
	
	printf("Type X to start the game.\nType any other character to quit the game.\n");
	scanf("%c", &choice);

	if((choice == 'x' ) || (choice == 'X'))
	{
		ClearScreen();
	}
	else
	{
		exit(0);
	}
}
int ScanInputType(void)
{
	char input[60];

	scanf("%s", &input);

	if(isdigit(input[0]))
	{
		return input[0]-48;
	}
	else
	{
		return 0;
	}
}

void PrintInfo(int gold, int attack, int armor, int wrong_chioce)
{
	if(wrong_chioce == 1)
	{
		ClearScreen();
		printf("\033[0;31m");
		printf("Not that choice try agian!!!\n\n");
		printf("\033[0m");
	}

	printf("========================================\n");
	printf("Gold %d\nAttack %d | Armor %d\n", gold, attack, armor);
	printf("========================================\n\n");
}

int main()
{	
	int game = 0, story = 0, choice = 0, wrong_chioce = 0;
	int gold = 0, attack = 0, defense = 0;

	ClearScreen();
	GameTitle();
	TitleChoice();

	srand(time(NULL));

	story = rand() % 3;

	story += 1;

	while (game == 0)
	{
		while(story == 1)
		{
			ClearScreen();

			gold = 50;
			attack = 10;
			defense = 20;
			
			PrintInfo(gold, attack, defense, wrong_chioce);
			
			wrong_chioce = 0;

			printf("<Worrier>\nYou are a skilled warrior who has attempted and failed numerous times to pass the knight exam. Then you give up and decide to become a mercenary instead in order to make a living. The fresh air on a new morning is the same as on any other day, but now you are not the same. Now you are a beginner mercenary.\n\n");
			printf("In the morning you decide to...\n");
			printf("1. Wake up and have a breakfast in the inn.\n2. Wake up and practice swordsmanship.\n3. Wake up and go exercise.\n4. Wake up and have some drinks while listening to other people talk.\n5. Wake up and go on an adventure.\n");
			
			choice = ScanInputType();

			if(choice == 1)
			{
				story = 4;
				
				break;
			}
			else if(choice == 2)
			{
				story = 5;
				
				break;
			}
			else if(choice == 3)
			{
				story = 6;
				
				break;
			}
			else if(choice == 4)
			{
				story = 7;
				
				break;
			}
			else if(choice == 5)
			{
				story = 8;
				
				break;
			}
			else
			{
				wrong_chioce = 1;
				
				break;
			}
		}
		while(story == 2)
		{
			ClearScreen();

			gold = 200;
			attack = 10;
			defense = 10;

			PrintInfo(gold, attack, defense, wrong_chioce);

			wrong_chioce = 0;

			printf("<Merchant>\nYou are an experienced merchant that roams all over every town. But nowadays, no one would like to buy anything from you. You spend so much time thinking about what happened but still have no clue. Finally, you decided to be an adventurer to make some money and continue living. Now you are a beginner adventurer.\n\n");
			printf("In the morning you decide to...\n");
			printf("1. Wake up and have a breakfast in the inn.\n2. Wake up and practice swordsmanship.\n3. Wake up and go exercise.\n4. Wake up and have some drinks while listening to other people talk.\n5. Wake up and go on an adventure.\n");

			choice = ScanInputType();

			if(choice == 1)
			{
				story = 4;
				
				break;
			}
			else if(choice == 2)
			{
				story = 5;
				
				break;
			}
			else if(choice == 3)
			{
				story = 6;
				
				break;
			}
			else if(choice == 4)
			{
				story = 7;
				
				break;
			}
			else if(choice == 5)
			{
				story = 8;
				
				break;
			}
			else
			{
				wrong_chioce = 1;
				
				break;
			}
		}
		while(story == 3)
		{
			ClearScreen();

			gold = 50;
			attack = 20;
			defense = 10;

			PrintInfo(gold, attack, defense, wrong_chioce);
			
			wrong_chioce = 0;

			printf("<Vagabond>\nYou are a vagabond that roams around the town. You honed your skills at avoiding danger, surviving in the wild, and navigating wild animals, but now you want to pursue your dreams. So, you've decided to join an adventure guild in order to pursue your dream and make it come true. Now you are a beginner adventurer.\n\n");
			printf("In the morning you decide to...\n");
			printf("1. Wake up and have a breakfast in the inn.\n2. Wake up and practice swordsmanship.\n3. Wake up and go exercise.\n4. Wake up and have some drinks while listening to other people talk.\n5. Wake up and go on an adventure.\n");
			
			choice = ScanInputType();

			if(choice == 1)
			{
				story = 4;
				
				break;
			}
			else if(choice == 2)
			{
				story = 5;
				
				break;
			}
			else if(choice == 3)
			{
				story = 6;
				
				break;
			}
			else if(choice == 4)
			{
				story = 7;
				
				break;
			}
			else if(choice == 5)
			{
				story = 8;
				
				break;
			}
			else
			{
				wrong_chioce = 1;
				
				break;
			}
		}
		while(story == 4)
		{
			ClearScreen();

			PrintInfo(gold, attack, defense, wrong_chioce);
			
			wrong_chioce = 0;

			printf("You have a good meal and feel full. It's time for an adventure.\n\n== Not thing change (not implement yet!!) ==\n\n");
			printf("Type 1 to start an adventure\n");
			
			choice = ScanInputType();

			if(choice == 1)
			{	
				story = 9;
				
				break;
			}
			else
			{
				wrong_chioce = 1;
				
				break;
			}
		}
		while(story == 5)
		{
			ClearScreen();

			PrintInfo(gold, attack, defense, wrong_chioce);

			wrong_chioce = 0;

			printf("You've finished practicing swordsmanship. You feel like you know how to use a sword better. It's time for an adventure.\n\n== Attack + 1 ==\n\n");
			printf("Type 1 to start an adventure\n");
			
			choice = ScanInputType();

			if(choice == 1)
			{	
				attack += 1;

				story = 9;
				
				break;
			}
			else
			{
				wrong_chioce = 1;
				
				break;
			}
		}
		while(story == 6)
		{
			ClearScreen();

			PrintInfo(gold, attack, defense, wrong_chioce);

			wrong_chioce = 0;

			printf("You've finished all the exercise. You can feel your muscles heating up. It's time for an adventure.\n\n== defense + 1 ==\n\n");
			printf("Type 1 to start an adventure\n");
			
			choice = ScanInputType();

			if(choice == 1)
			{	
				defense += 1;

				story = 9;

				break;
			}
			else
			{
				wrong_chioce = 1;
				
				break;
			}
		}
		while(story == 7)
		{
			ClearScreen();

			PrintInfo(gold, attack, defense, wrong_chioce);

			wrong_chioce = 0;

			printf("You hear some interesting story and want to find that out. It's time for an adventure.\n\n== Unlock new story (not implement yet!!) ==\n\n");
			printf("Type 1 to start an adventure\n");
			
			choice = ScanInputType();

			if(choice == 1)
			{	

				story = 9;
				
				break;
			}
			else
			{
				wrong_chioce = 1;
				
				break;
			}
		}
		while(story == 8)
		{
			ClearScreen();

			PrintInfo(gold, attack, defense, wrong_chioce);

			wrong_chioce = 0;

			printf("You're leaving the town through the main entrance. Now it's time for an adventure.\n\n== Begin adventure ==\n\n");
			printf("Type 1 to start an adventure\n");
			
			choice = ScanInputType();

			if(choice == 1)
			{	
				story = 9;
				
				break;
			}
			else
			{
				wrong_chioce = 1;
				
				break;
			}
		}
		while(story == 9)
		{
			ClearScreen();

			PrintInfo(gold, attack, defense, wrong_chioce);
			
			wrong_chioce = 0;

			printf("At the edge of the forest. You hear a squishy sound and follow it. Then, you see a green slime that idling in front of you.\n\n");
			printf("You decide to....\n");
			printf("1. Attack it!!\n2. Pass by.\n");
			
			choice = ScanInputType();

			if(choice == 1)
			{
				story = 10;
				
				break;
			}
			else if(choice == 2)
			{
				story = 11;
				
				break;
			}
			else
			{
				wrong_chioce = 1;
				
				break;
			}
		}
		while(story == 10)
		{
			ClearScreen();

			PrintInfo(gold, attack, defense, wrong_chioce);
			
			wrong_chioce = 0;

			printf("This part is not implement yet. but we'll give you gold insted.\n\n== receive 50 gold ==\n\n");
			printf("Type 1 to continue.\n");
			
			choice = ScanInputType();

			if(choice == 1)
			{	
				gold += 50;

				story = 12;
				
				break;
			}
			else
			{
				wrong_chioce = 1;
				
				break;
			}
		}
		while(story == 11)
		{
			ClearScreen();

			PrintInfo(gold, attack, defense, wrong_chioce);
			
			wrong_chioce = 0;

			printf("That's not the the worst choice. Let's go to other place.\n\n");
			printf("Type 1 to continue.\n");
			
			choice = ScanInputType();

			if(choice == 1)
			{
				story = 12;
				
				break;
			}
			else
			{
				wrong_chioce = 1;
				
				break;
			}
		}
		while(story == 12)
		{
			ClearScreen();

			PrintInfo(gold, attack, defense, wrong_chioce);
			
			wrong_chioce = 0;

			printf("In the middle of the forest, you see a two-way junction. An oak tree is on the left, and a burned tree is on the right.\n\n");
			printf("You decide to....\n");
			printf("1. Take an oak tree path.\n2. Take a burned tree path.\n3. Find other ways.\n");
			
			choice = ScanInputType();

			if(choice == 1)
			{
				story = 13;
				
				break;
			}
			else if(choice == 2)
			{
				story = 23;

				break;
			}
			else if(choice == 3)
			{
				story = 24;

				break;
			}
			else
			{
				wrong_chioce = 1;
				
				break;
			}
		}
		while(story == 13)
		{
			ClearScreen();

			PrintInfo(gold, attack, defense, wrong_chioce);
			
			wrong_chioce = 0;

			printf("You decide to take an oak tree path. But when you walk 5 minutes further, you see a two-way junction again. This time, a birch tree is on the left, and a maple tree is on the right.\n\n");
			printf("You decide to....\n");
			printf("1. Take a birch tree path.\n2. Take a maple tree path.\n3. Go back to the previous path.\n");
			
			choice = ScanInputType();

			if(choice == 1)
			{
				story = 14;

				break;
			}
			else if(choice == 2)
			{
				story = 15;

				break;
			}
			else if(choice == 3)
			{
				story = 12;

				break;
			}
			else
			{
				wrong_chioce = 1;
				
				break;
			}
			
			
		}
		while(story == 14)
		{
			ClearScreen();

			PrintInfo(gold, attack, defense, wrong_chioce);
			
			wrong_chioce = 0;

			printf("You walk for about 5 minutes, and then you see an old blacksmith house. You decide to go in, look around, and find a shining golden sword. You pick it up, and your vision becomes blurred.\n\n");
			printf("Type 1 to continue.\n");
			
			choice = ScanInputType();

			if(choice == 1)
			{
				story = 22;

				break;
			}
			else
			{
				wrong_chioce = 1;

				break;
			}
			
		}
		while(story == 15)
		{
			ClearScreen();

			PrintInfo(gold, attack, defense, wrong_chioce);
			
			wrong_chioce = 0;

			printf("You keep walking and walking until you almost collapse. Then you can hear some giggle noises from somewhere nearby. When you turn around to see what that noise is, your eyes catch up with the light ball that is floating around. The light ball then comes to a halt, revealing the body of a young girl with gold eyes and green hair. Her arm and leg wrap around with vines, and her body emits a little green light. She stares at you, then asks ");
				SpeechBox();
			printf("\"Can you guess who I am?\"\n\n");
				EndTextColor();
			printf("You answer her. she is....\n");
			printf("1. an Elf.\n2. a Fairy.\n3. a Dryad.\n4. You don't know.\n");
			
			choice = ScanInputType();

			if(choice == 1)
			{
				story = 16;

				break;
			}
			else if(choice == 2)
			{
				story = 16;

				break;
			}
			else if(choice == 3)
			{
				story = 17;

				break;
			}
			else if(choice == 4)
			{
				story = 18;

				break;
			}
			else
			{
				wrong_chioce = 1;

				break;
			}			
		}
		while(story == 16)
		{
			ClearScreen();

			PrintInfo(gold, attack, defense, wrong_chioce);
		
			wrong_chioce = 0;

			printf("She heard what you said and seemed disappointed. Then your vision is blurred, and you hear whispers ");
				SpeechBox();
			printf("\"Not correct.I'm a dryad, but considerate of your effort I will grant you some gift.\"\n");
				EndTextColor();
			printf("Type 1 to continue\n");
			
			choice = ScanInputType();

			if(choice == 1)
			{
				story = 19;
				
				break;
			}
			else
			{
				wrong_chioce = 1;

				break;
			}
		}
		while(story == 17)
		{
			ClearScreen();

			PrintInfo(gold, attack, defense, wrong_chioce);
			
			wrong_chioce = 0;

			printf("She heard what you said and smile. Then your vision is blurred, and you hear whispers ");
				SpeechBox();
			printf("\"You are correct. I'm a dryad, and I'll give you a huge gift for your luck or your knowledge. Goodbye the chosen one\"\n\n");
				EndTextColor();
			printf("Type 1 to continue\n");
			
			choice = ScanInputType();

			if(choice == 1)
			{
				story = 20;
				
				break;
			}
			else
			{
				wrong_chioce = 1;

				break;
			}
		}
		while(story == 18)
		{
			ClearScreen();

			PrintInfo(gold, attack, defense, wrong_chioce);
			
			wrong_chioce = 0;

			printf("She heard what you said and seemed angry and disappointed. Then your vision is blurred, and you hear whispers");
				SpeechBox();
			printf("\"Can't you at least try to guess? You've disappointed me so much. Just get out of my sight!!!\"\n");
				EndTextColor();
			printf("Type 1 to continue\n");
			
			choice = ScanInputType();

			if(choice == 1)
			{
				story = 21;
				
				break;
			}
			else
			{
				wrong_chioce = 1;

				break;
			}
		}
		while(story == 19)
		{
			ClearScreen();

			PrintInfo(gold, attack, defense, wrong_chioce);
			
			wrong_chioce = 0;

			printf("You opened your eyes and saw the blue sky. You're wondering what just happened. You were deep in thought when you sighed quietly. Your adventurous life will still continue.\n\n== receive 50 gold ==\n== Attack + 50\n== defense + 50 ==\n\n");
			printf("Type 1 to continue.");
			
			choice = ScanInputType();

			if(choice == 1)
			{
				gold += 50;
				attack += 50;
				defense += 50;

				story = 22;

				break;
			}
			else
			{
				wrong_chioce = 1;

				break;
			}
		}
		while(story == 20)
		{
			ClearScreen();

			PrintInfo(gold, attack, defense, wrong_chioce);
			
			wrong_chioce = 0;

			printf("You opened your eyes and saw the blue sky. You're wondering what just happened. You were deep in thought when you sighed quietly. Your adventurous life will still continue.\n\n== receive 500 gold ==\n== Attack + 100\n== defense + 100 ==\n\n");
			printf("Type 1 to continue.\n");
			
			choice = ScanInputType();

			if(choice == 1)
			{
				gold += 500;
				attack += 100;
				defense += 100;

				story = 22;

				break;
			}
			else
			{
				wrong_chioce = 1;

				break;
			}
		}
		while(story == 21)
		{
			ClearScreen();

			PrintInfo(gold, attack, defense, wrong_chioce);
			
			wrong_chioce = 0;

			printf("You opened your eyes and saw the blue sky. You're wondering what just happened. You were deep in thought when you sighed quietly. Your adventurous life will still continue.\n\n== lost all gold ==\n== remove all stats ==\n\n");
			printf("Type 1 to continue.\n");
			
			choice = ScanInputType();

			if(choice == 1)
			{
				gold = 0;
				attack = 0;
				defense = 0;

				story = 22;

				break;
			}
			else
			{
				wrong_chioce = 1;

				break;
			}
		}
		while(story == 22)
		{
			ClearScreen();

			PrintInfo(gold, attack, defense, wrong_chioce);
			
			wrong_chioce = 0;

			printf("Thank you. For playing the demo \"TextTurnRPG\" we hope that you have fun with our demo, and we promise. We will make this game until it is finished.\n\n");
			printf("Type 1 to \"END THE DEMO GAME\"\n");
			
			choice = ScanInputType();

			if(choice == 1)
			{
				game = 1;

				break;
			}
			else
			{
				wrong_chioce = 1;

				break;
			}
		}
		while(story == 23)
		{
			ClearScreen();

			PrintInfo(gold, attack, defense, wrong_chioce);
			
			wrong_chioce = 0;

			printf("You decide to take a burned tree path. But no matter how much you walk, you still can't find the way out.\n\n");
			printf("Type 1 to continue.\n");
			
			choice = ScanInputType();

			if(choice == 1)
			{
				story = 22;

				break;
			}
			else
			{
				wrong_chioce = 1;
				
				break;
			}
			
			
		}
		while(story == 24)
		{
			ClearScreen();

			PrintInfo(gold, attack, defense, wrong_chioce);
			
			wrong_chioce = 0;

			printf("You decide to take a other path. But no matter how much you walk, you still can't find the way out.\n\n");
			printf("Type 1 to continue.\n");
			
			choice = ScanInputType();

			if(choice == 1)
			{
				story = 22;

				break;
			}
			else
			{
				wrong_chioce = 1;
				
				break;
			}
		}
	}

	printf("This is you final score.\n\n");

	PrintInfo(gold, attack, defense, wrong_chioce);
	
	return 1;
}