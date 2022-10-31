int main(){
	cout<< "\n\n\n";
	system("color 60");
	cout << "\t\t*    *    *  *****    *         *******   *********   *       *   *******\n";
	cout << "\t\t*   * *   *  *          *         *           *         *   * *   * *   *\n";
	cout << "\t\t*  *   *  *  *****    *         *           *         *   *   *   *   *******\n";
	cout << "\t\t* *     * *  *          *         *           *         *   *       *   *\n";
	cout << "\t\t*         *  *****    ******  *******   *********   *       *   *******\n";
	cout << "\nBuilt by\nK21-3298 Owais Ali Khan\nK21-3267 Mohammad Saad\nK21-4926 Fahad Ahmed\n";
	cout << "\n\npress any key to continue...");
	getch();
    system("CLS");
    
	int i, pass_flag=0;
	authorization=0;
	int retry;
	FILE *fa;
	char pass[30];
	printf("Enter password: ");
	fflush(stdin);
	gets(pass);
//	char passwords[TOTAL_PASSWORDS][30] = {"owais", "ali", "khan"};
//	char users[TOTAL_USERS][50] = {"CEO", "Manager", "Worker"};
	for (i=0; i<TOTAL_PASSWORDS; i++){
		if (strcmp(pass, passwords[i]) == 0){
			pass_flag = 1;
			authorization = i;
		}
	}
	if (pass_flag == 1){
		decode_file("encoded.txt", "decoded.txt");
		system("color 20");
		printf("Login successful. Currently logged in as %s with authorization level %d.\n",users[authorization], authorization);
//		getch();
//		system("color 60");
		int h,g;
		printf("\t\t\t\tLOADING");
		for(h=0;h<=10;h++){
			printf(" . ");
			for(g=0;g<=100000000;g++){
			}
		}
		system("color 60");
		menu(authorization);
	}
	else{
		system("color 40");
		printf("\a\nGiven password not in authorization list.\nEnter any key to try again, or 0 to exit: ");
		int num;
		num = getch();
		if (num-48 == 0){
//			system("color 64");
			system("cls");
			encode_file("decoded.txt", "encoded.txt");
			remove("decoded.txt");
			exit(0);
		}
		else{
			system("cls");
			main();
		}
/*
		if (num == 0){
			system("cls");
			remove("decoded.txt");
			exit(0);
		}
*/
		
	}
	encode_file("decoded.txt", "encoded.txt");
	remove("decoded.txt");
