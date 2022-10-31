#include<iostream>  
#include<stdlib.h>
#include"classesf.h"
using namespace std;

 
int main(){
	Login l ;  inventory v ;
	customer c ; billing b ; 
	
 
	system("color E0"); 
	cout << "\n\n" << endl;
	cout << "\t\t\t*    *    *  *****    *         *******   *********   *       *   *******\n";
	cout << "\t\t\t*   * *   *  *        *         *         *       *   * *   * *   *       \n";
	cout << "\t\t\t*  *   *  *  *****    *         *         *       *   *   *   *   *******\n";
	cout << "\t\t\t* *     * *  *        *         *         *       *   *       *   *       \n";
	cout << "\t\t\t*         *  *****    ******    *******   *********   *       *   *******\n";
	
	l.description() ; l.display() ;
	if( l.checkshopkeeper()){
		system("cls");
		system("color B0");
		
		int choice ; char choice1[1]; 
		while (strcmp(choice1,"n")){
		system("cls");	
		cout << "Press   " << endl;
		cout << "1. To View stock " << endl ;
		cout << "2. To Add a product " << endl ;
		cout << "3. To Search a product "<< endl;
		cout << "4. To Remove a product"  << endl ;
	
		cout << "5. Exit" << endl;
		  
		
		 
		cin >> choice ; 
		switch(choice){
			
			case 1 :   v.showstock(); break ;
			case 2 :   v.addproduct(); break ;
			case 3 :   v.searchproduct(); break ;
			case 4 :   v.delproduct(); break ;
			//case 5 :   b.readbill() ; break ; 
			case 5 :   exit(0); 
				  
		    }// END OF SWITCH
		cout << " wanna perform another operation ?(y or n)" ; cin >> choice1 ;   
	    } // end of while   
	} // end of if
	
	if(l.checkcustomer()){
		system("cls");
		system("color B0");

		
		cout << "1.view products " << endl;
		cout << "2.purchase products" << endl;
		cout << "3.give feedback " << endl;
		cout << "4.Exit" << endl;
				
		int input; cin >> input;
		switch(input){
			case 1: v.showstock(); cin >>input; 
			
			
			case 2: 
		
		
	 	char choice2[1] ; int choice3 ;
	 	
	    for (int j=0;j<4;++j){       
		     cout << " Help us out in searching your product please " << endl ;
		     c.getname();
		     v.searchproduct(c.name);
             b.iprice[j] = v.price;
             b.total += v.price; 
		     strncpy(b.pname[j], v.name, 30);
		     ++c.netpurchase;
		     cout << "\nDo you want to purchase another(y or n) " << endl ;
		     cin >> choice2 ;
		     if (strcmp(choice2,"y"))
		         break;
              		    
					    
			} // end of for loop
			system("cls"); 
			if(c.checkpurchase()){
				cout << "\nyou have selected the following product/products:\n"; 
			    for (int k=0;k < c.netpurchase;++k)
			        cout << b.pname[k] << endl;
			    cout << "\nYour total bill is : " << b.total << "$"; 
			    char choice5[5] ;
			    c.request_order();
			    cout << "\nYour bill is ready , want to see it ?" << endl ; cin >> choice5;
			    if (strcmp(choice5,"y")==0)
				   {    system("cls");
				int w =15;   
			    cout << "\n\t\t\t\t       C A S H   R E C E I P T      ";
			    cout << "\n\t\t\t\t************************************";
			    cout <<"\n\t\t\t\t"<< setw(3) << "The Gem Galore" << endl ;//<<s.address
		 	    cout << "\n\t\t\t\t" <<setw(3) << "0323-2352830" << endl; //s.phone num
			    cout << "\n\t\t\t\t--------------------------------------"<< endl;
			    cout <<"\n\t\t\t\t" ;datetime();
			    cout << "\n\t\t\t\t--------------------------------------" << endl;
		 	    cout << "\n\t\t\t\tCustomer Name : " << c.cname << endl;
			    cout <<  "\n\t\t\t\tCustomer Phone # : " << c.phonenum << endl;
			    int serial = 0;
			    cout << "\n\t\t\t\tProduct Name " << setw(w) << "Price " << endl;
			    for (int j=0 ; j<c.netpurchase ; ++j ){
			        cout <<"\t\t\t\t" << ++serial << ". " << b.pname[j] << setw(w) << b.iprice[j] << endl;
			    } //end of loop  	
			    cout <<"\t\t\t\t"<< setw(30) << "Total : " << b.total <<" $" << endl;
			    cout << "\t\t\t\t**************************************" << endl;
			    cout << "\t\t\t\t          T H A N K     Y O U         " << endl;
			    cout << "\t\t\t\t***************************************"<< endl;	    
	     	    b.savebill();
				getch();}}
			
				     
		system("cls");
		c.payment(b.total);     
		c.getProduct(); 
		cout << "\nWould you like us to give feedback?(y or n )  " << endl; char opt[1] ; 
		cin >> opt;
		if (strcmp(opt,"y")!=0)
			{
				break;
				cout << "\nGood Bye" << endl;  	}
		else
		     
	case 3: system("cls") ; c.writefeedback(); break;
	case 4: cout << "\nGood Bye" << endl; exit(0); 
	} // end of switch
	}// end of 	if
}		  	
		
		
		
				    
		 		  

	 
	 
	  
	  
