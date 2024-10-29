#include <stdio.h>
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
}Character;

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

void EndTextColor()
{
	printf("\033[0m");
}

void FullScreen()
{
	int choice;

	do
	{
		ClearScreen();
		
		printf("Please use full screen mode for better experince!!\n\n");
		printf("Using full screen right now?\nType 1 if using full screen.\nType other number if not using full screen.\n");
		
		choice = ScanInput();
	}while (choice != 1);
}

void GameTitle()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    
	int columns;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.dwSize.X;

	char game_cover[7][150];
	
	strcpy(game_cover[0], "                                             #######   ######    ######                                                  \n");
	strcpy(game_cover[1], "                                             #      #  #     #  #      #                                                 \n");
	strcpy(game_cover[2], "#######  ######  #   #  #######              #      #  #     #  #                     #######  #     #  ######   #     # \n");
	strcpy(game_cover[3], "   #     #        # #      #      ########   #######   ######   # ######   ########      #     #     #  #     #  # #   # \n");
	strcpy(game_cover[4], "   #     ######    #       #                 #   #     #        #      #                 #     #     #  ######   #  #  # \n");
	strcpy(game_cover[5], "   #     #        # #      #                 #    #    #        #      #                 #     #     #  #  #     #   # # \n");
	strcpy(game_cover[6], "   #     ######  #   #     #                 #     #   #         ######                  #      #####   #    #   #     # \n");

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
	
	printf("Type 1 to start the game.\nType 2 to quit the game.\n");
	
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
	printf("Heart %d\n", player.heart);
	printf("Gold %d\nAttack %d | Armor %d\n", player.gold, player.attack, player.defense);
	
	for(int i = 0; i < columns; i++)
	{
		printf("=");
	}
}

Character CharacterName(Character player)
{
	printf("Enter your character name: ");
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

int main()
{	
	Character player;

	int game = 0, choice = 0, wrong_chioce = 0;
	double story = 0;

	ClearScreen();
	FullScreen();
	GameTitle();
	TitleChoice();
	player = CharacterName(player);

	srand(time(NULL));
	story = rand() % 3;
	story += 1;
			
	while (game == 0)
	{
		while(story == 1)
		{
			ClearScreen();

			player.gold = 50;
			player.attack = 10;
			player.defense = 20;
			player.heart = 6;
			
			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("<Worrier>\nYou are a skilled warrior who has attempted and failed numerous times to pass the knight exam. Then you give up and decide to become a mercenary instead in order to make a living. The fresh air on a new morning is the same as on any other day, but now you are not the same. Now you are a beginner mercenary.\n\n");
			printf("In the morning you decide to...\n");
			printf("1. Wake up and have a breakfast in the inn.\n2. Wake up and practice swordsmanship.\n3. Wake up and go exercise.\n4. Wake up and have some drinks while listening to other people talk.\n5. Wake up and go on an adventure.\n");
			
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
		}
		while(story == 2)
		{
			ClearScreen();

			player.gold = 200;
			player.attack = 10;
			player.defense = 10;
			player.heart = 5;

			PrintInfo(player, wrong_chioce);

			wrong_chioce = 0;

			printf("<Merchant>\nYou are an experienced merchant that roams all over every town. But nowadays, no one would like to buy anything from you. You spend so much time thinking about what happened but still have no clue. Finally, you decided to be an adventurer to make some money and continue living. Now you are a beginner adventurer.\n\n");
			printf("In the morning you decide to...\n");
			printf("1. Wake up and have a breakfast in the inn.\n2. Wake up and practice swordsmanship.\n3. Wake up and go exercise.\n4. Wake up and have some drinks while listening to other people talk.\n5. Wake up and go on an adventure.\n");
			
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
		}
		while(story == 3)
		{
			ClearScreen();

			player.gold = 50;
			player.attack = 20;
			player.defense = 10;
			player.heart = 7;

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("<Vagabond>\nYou are a vagabond that roams around the town. You honed your skills at avoiding danger, surviving in the wild, and navigating wild animals, but now you want to pursue your dreams. So, you've decided to join an adventure guild in order to pursue your dream and make it come true. Now you are a beginner adventurer.\n\n");
			printf("In the morning you decide to...\n");
			printf("1. Wake up and have a breakfast in the inn.\n2. Wake up and practice swordsmanship.\n3. Wake up and go exercise.\n4. Wake up and have some drinks while listening to other people talk.\n5. Wake up and go on an adventure.\n");
			
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
		}
		while(story == 1.1)
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("You have a very good meal and feel full and healty. It's time for an adventure.\n\n== Heart + 1 ==\n\n");
			printf("Type 1 to start an adventure\n");
			
			choice = ScanInput();

			if(choice == 1)
			{	
				player.heart += 1;
				story = 4.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}
		}
		while(story == 1.2)
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);

			wrong_chioce = 0;

			printf("You've finished practicing swordsmanship. You feel like you know how to use a sword a little better. It's time for an adventure.\n\n== Attack + 1 ==\n\n");
			printf("Type 1 to start an adventure\n");
			
			choice = ScanInput();

			if(choice == 1)
			{	
				player.attack += 1;
				story = 4.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}
		}
		while(story == 1.3)
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);

			wrong_chioce = 0;

			printf("You've finished all the exercise. You can feel your muscles heating up. It's time for an adventure.\n\n== defense + 1 ==\n\n");
			printf("Type 1 to start an adventure\n");
			
			choice = ScanInput();

			if(choice == 1)
			{	
				player.defense += 1;
				story = 4.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}
		}
		while(story == 1.4)
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);

			wrong_chioce = 0;

			printf("You hear a fascinating story and want to learn more about it. So, you get up and join their conversation.\n\n== Unlock mini story==\n\n");
			printf("Type 1 to sit and listen to their story.\n");
			
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
		}
		while(story == 1.41)
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);

			wrong_chioce = 0;

				SpeechBox();
			printf("\"Ah hahaha, did you eavesdrop our conversation? Well then, let's me ask you some adventurer knowlage.\"\n\"What is the most important thing for an adventurer?\"\n\n");
				EndTextColor();
			printf("You answer...\n");
			printf("1. Wealth.\n2. Dreams.\n3. Family.\n4. Strongest.\n");
			
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
		}
		while(story == 1.411)
		{
			printf("Your answer is to have wealth that can support you and your family until you die.\n");
				SpeechBox();
			printf("Woh, what an amazing little Billionaire! There's neither the correct nor the wrong choice. But I just want to know what your goal is. Here is your reward!!\n");
				EndTextColor();
			printf("\n\n== Gold + 50 ==\n\n");
			printf("Type 1 to start an adventure\n");
			
			choice = ScanInput();

			if(choice == 1)
			{	
				player.gold += 50;
				story = 4.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}
		}
		while(story == 1.412)
		{
			printf("Your answer is to achieve your dreams before you die.\n");
				SpeechBox();
			printf("Woh, what an amazing little Dreamer! There's neither the correct nor the wrong choice. But I just want to know what your goal is. Here is your reward!!\n");
				EndTextColor();
			printf("\n\n== Heart + 1 ==\n\n");
			printf("Type 1 to start an adventure\n");
			
			choice = ScanInput();

			if(choice == 1)
			{	
				player.heart += 1;
				story = 4.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}
		}
		while(story == 1.413)
		{
			printf("Your answer is to have a happy family life until you die.\n");
				SpeechBox();
			printf("Woh, what an amazing little Family maker! There's neither the correct nor the wrong choice. But I just want to know what your goal is. Here is your reward!!\n");
				EndTextColor();
			printf("\n\n== Defense + 1 ==\n\n");
			printf("Type 1 to start an adventure\n");
			
			choice = ScanInput();

			if(choice == 1)
			{	
				player.defense += 1;
				story = 4.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}
		}
		while(story == 1.414)
		{
			printf("Your answer is to be the strongest adventurer in history.\n");
				SpeechBox();
			printf("Woh, what an amazing little Fighter! There's neither the correct nor the wrong choice. But I just want to know what your goal is. Here is your reward!!\n");
				EndTextColor();
			printf("\n\n== Attack + 1 ==\n\n");
			printf("Type 1 to start an adventure\n");
			
			choice = ScanInput();

			if(choice == 1)
			{	
				player.attack += 1;
				story = 4.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}
		}
		while(story == 1.5)
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);

			wrong_chioce = 0;

			printf("You're leaving the town through the main entrance. Now it's time for an adventure.\n\n== Begin adventure ==\n\n");
			printf("Type 1 to start an adventure\n");
			
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
		}
		while(story == 4.0)
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("At the edge of the forest. You hear a squishy sound and follow it. Then, you see a green slime that idling in front of you.\n\n");
			printf("You decide to....\n");
			printf("1. Attack it!!\n2. Pass by.\n");
			
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
			else
			{
				wrong_chioce = 1;
				break;
			}
		}
		while(story == 4.1)
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("This part is not implement yet. but we'll give you gold insted.\n\n== receive 50 gold ==\n\n");
			printf("Type 1 to continue.\n");
			
			choice = ScanInput();

			if(choice == 1)
			{	
				player.gold += 50;
				story = 5.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}
		}
		while(story == 4.2)
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("That's not the the worst choice. Let's go to other place.\n\n");
			printf("Type 1 to continue.\n");
			
			choice = ScanInput();

			if(choice == 1)
			{
				story = 5.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}
		}
		while(story == 5.0)
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("You see an old and mysterious shop, but it is filled with people in front of you.\n\n");
			printf("You decide to...\n");
			printf("1. Go and see what the shop has to sell.\n2. Pass by.\n");

			choice = ScanInput();

			if(choice == 1)
			{
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
		}
		while(story == 5.1)
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;
			
			SpeechBox();
			printf("\"Hello Stanger!!! Welcome to our shop. What would you like to buy?\"\n\n");
				EndTextColor();
			printf("1. Small attack potion.\n\tPirce 50 gold\n\tAttack + 2\n2. Attack potion.\n\tPrice 100 gold\n\tAttack + 5\n3. Small defense potion.\n\tPrice 50 gold\n\tDefense + 2\n4. Defense potion.\n\tPrice 100 gold\n\tDefense + 5\n5.Exit the shop.\n");

			choice = ScanInput();

			if((choice == 1) && (player.gold >= 50))
			{
				printf("Attack + 2\n");
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
				printf("Attack + 5\n");
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
				printf("Defense + 2\n");
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
				printf("Defense + 5\n");
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
			else if(choice == 5)
			{
				story = 6.0;
				break;
			}
		}
		while(story == 6.0)
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("In the middle of the forest, you see a two-way junction. An oak tree is on the left, and a burned tree is on the right.\n\n");
			printf("You decide to....\n");
			printf("1. Take an oak tree path.\n2. Take a burned tree path.\n3. Find other ways.\n");
			
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
			else
			{
				wrong_chioce = 1;
				break;
			}
		}
		while(story == 6.1)
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("You decide to take an oak tree path. But when you walk 5 minutes further, you see a two-way junction again. This time, a birch tree is on the left, and a maple tree is on the right.\n\n");
			printf("You decide to....\n");
			printf("1. Take a birch tree path.\n2. Take a maple tree path.\n3. Go back to the previous path.\n");
			
			choice = ScanInput();

			if(choice == 1)
			{
				story = 6.11;
				break;
			}
			else if(choice == 2)
			{
				story = 6.12;
				break;
			}
			else if(choice == 3)
			{
				story = 6.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}
		}
		while(story == 6.11)
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("You walk for about 5 minutes, and then you see an old blacksmith house. You decide to go in, look around, and find a shining golden sword. You pick it up, and your vision becomes blurred.\n\n");
			printf("Type 1 to continue.\n");
			
			choice = ScanInput();

			if(choice == 1)
			{
				story = 7.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}
			
		}
		while(story == 6.12)
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("You keep walking and walking until you almost collapse. Then you can hear some giggle noises from somewhere nearby. When you turn around to see what that noise is, your eyes catch up with the light ball that is floating around. The light ball then comes to a halt, revealing the body of a young girl with gold eyes and green hair. Her arm and leg wrap around with vines, and her body emits a little green light. She stares at you, then asks\n");
				SpeechBox();
			printf("\"Can you guess who I am?\"\n\n");
				EndTextColor();
			printf("You answer her. she is....\n");
			printf("1. an Elf.\n2. a Fairy.\n3. a Dryad.\n4. You don't know.\n");
			
			choice = ScanInput();

			if(choice == 1)
			{
				story = 6.121;
				break;
			}
			else if(choice == 2)
			{
				story = 6.121;
				break;
			}
			else if(choice == 3)
			{
				story = 6.122;
				break;
			}
			else if(choice == 4)
			{
				story = 6.123;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}			
		}
		while(story == 6.121)
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
		
			wrong_chioce = 0;

			printf("She heard what you said and seemed disappointed. Then your vision is blurred, and you hear whispers\n");
				SpeechBox();
			printf("\"Not correct.I'm a dryad, but considerate of your effort I will grant you some gift.\"\n");
				EndTextColor();
			printf("Type 1 to continue\n");
			
			choice = ScanInput();

			if(choice == 1)
			{
				story = 6.1211;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}
		}
		while(story == 6.1211)
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("You opened your eyes and saw the blue sky. You're wondering what just happened. You were deep in thought when you sighed quietly. Your adventurous life will still continue.\n\n== receive 50 gold ==\n== Attack + 50\n== defense + 50 ==\n\n");
			printf("Type 1 to continue.");
			
			choice = ScanInput();

			if(choice == 1)
			{
				player.gold += 50;
				player.attack += 50;
				player.defense += 50;
				story = 7.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}
		}
		while(story == 6.122)
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("She heard what you said and smile. Then your vision is blurred, and you hear whispers\n");
				SpeechBox();
			printf("\"You are correct. I'm a dryad, and I'll give you a huge gift for your luck or your knowledge. Goodbye the chosen one\"\n\n");
				EndTextColor();
			printf("Type 1 to continue\n");
			
			choice = ScanInput();

			if(choice == 1)
			{
				story = 6.1221;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}
		}
		while(story == 6.1221)
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("You opened your eyes and saw the blue sky. You're wondering what just happened. You were deep in thought when you sighed quietly. Your adventurous life will still continue.\n\n== receive 500 gold ==\n== Attack + 100\n== defense + 100 ==\n\n");
			printf("Type 1 to continue.\n");
			
			choice = ScanInput();

			if(choice == 1)
			{
				player.gold += 500;
				player.attack += 100;
				player.defense += 100;
				story = 7.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}
		}
		while(story == 6.123)
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("She heard what you said and seemed angry and disappointed. Then your vision is blurred, and you hear whispers\n");
				SpeechBox();
			printf("\"Can't you at least try to guess? You've disappointed me so much. Just get out of my sight!!!\"\n");
				EndTextColor();
			printf("Type 1 to continue\n");
			
			choice = ScanInput();

			if(choice == 1)
			{
				story = 6.1231;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}
		}
		while(story == 6.1231)
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("You opened your eyes and saw the blue sky. You're wondering what just happened. You were deep in thought when you sighed quietly. Your adventurous life will still continue.\n\n== lost all gold ==\n== remove all stats ==\n\n");
			printf("Type 1 to continue.\n");
			
			choice = ScanInput();

			if(choice == 1)
			{
				player.gold = 0;
				player.attack = 0;
				player.defense = 0;
				story = 7.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}
		}
		while(story == 6.2)
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("You decide to take a burned tree path. But no matter how much you walk, you still can't find the way out.\n\n");
			printf("Type 1 to continue.\n");
			
			choice = ScanInput();

			if(choice == 1)
			{
				story = 7.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}
		}
		while(story == 6.3)
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("You decide to take a other way. But no matter how much you walk, you still can't find the way out.\n\n");
			printf("Type 1 to continue.\n");
			
			choice = ScanInput();

			if(choice == 1)
			{
				story = 7.0;
				break;
			}
			else
			{
				wrong_chioce = 1;
				break;
			}
		}
		while(story == 7.0)
		{
			ClearScreen();

			PrintInfo(player, wrong_chioce);
			
			wrong_chioce = 0;

			printf("Thank you. For playing the demo \"TextTurnRPG\" we hope that you have fun with our demo, and we promise. We will make this game until it is finished.\n\n");
			printf("Type 1 to \"END THE DEMO GAME\"\n");
			
			choice = ScanInput();

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
	}

	ClearScreen();

	printf("This is you final score.\n\n");

	PrintInfo(player, wrong_chioce);
	
	return 1;
}

