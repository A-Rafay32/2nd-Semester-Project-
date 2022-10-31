#include<iostream> 
#include<fstream>
#include<stdio.h>
#include<ctime>
#include<iomanip>
#include<conio.h>

using namespace std;

class product{
	public:
		char name[20],producttype[20],category[20],material[20] ;
		float price;
		char productID[5];
		int quantity;
	
	 
};
/////////////////////////////////////////////////////////////////////////////////////////////////

class inventory : public product{
	
	public :
		void set(){
			cout << "\n Name : "   ; cin >> name; //cin.getline(name ,20) ;
			cout << "\nProduct type :  "  ; cin >> producttype;
			cout << "\nProduct ID : "  ; cin >> productID;//cin.getline( producttype,20 );
			cout << "\ncategory : "   ; cin >> category;
			cout << "\nPrice : " ; cin >> price ;
		}
		void get(){
			cout << "\n Name : " << name << endl ;
			cout << "\nProduct ID : " <<  productID   << endl;
			cout << "\nProduct type :  " << producttype << endl;
			cout << "\ncategory : " << category << endl ;
			cout << "\nPrice :  " << price << endl;   
			
		}		
		void writeobjects(){
			int tobjects = 10;
			fstream fo; 
			fo.open("Stocks.DAT", ios :: binary  | ios :: app );
	 
			for (int j=0;j<tobjects ; ++j){
				 set();
				 fo.write((char*)this , sizeof(*(this)));
				 cout << "this object is written , write another " << endl; }  
		} 

		void addproduct(){
			fstream fo;
			fo.open("Stocks.DAT", ios :: binary |ios :: out | ios :: app );
			set();//write to end of file
			fo.write((char*)this,sizeof(*this)); 
		}
		void readproduct( int n ){
			fstream fi;
			fi.open("Stocks.DAT", ios :: binary |ios :: in );
			//fi.seekg(0,ios :: beg ) 	
			int position = (n-1)*sizeof(*this);
			  
			fi.seekg(position);
			fi.read((char*)this, sizeof(*this));
			//get();
			}
		void delproduct(){
			char ID[5];   
			fstream fin; ofstream fout;
			fin.open("Stocks.DAT",ios :: binary | ios :: in );
			fout.open("Temp(2).DAT", ios :: binary | ios :: out | ios :: app);
			cout << "Enter Product ID" ; cin >> ID ; 
			
			while (!fin.eof()){
				fin.read((char*)this , sizeof(*this)); 
				if(strcmp(ID,productID)==0)
				   {  }  
				   
				else   
				    fout.write((char*)this , sizeof(*this));
				    
    
			}// end of while 
			fin.close(  ) ; fout.close() ;
			remove("Stocks.DAT"); //cout << "\nremoved ";
			rename	("Temp(2).DAT","Stocks.DAT"); //cout << "\nrenamed";
			
			cout << "\nProduct deleted successfully " << endl;
		} 
		
		void searchproduct( ){
			ifstream fin;
	
			bool found = false;		fin.open("Stocks.DAT" , ios :: binary | ios :: in );
			fin.seekg(ios :: beg); 
			int choice ;
			cout <<"\nHow do you want to search the item ?\n1.By name \n2.By product ID";
			cout << endl;
			cin >> choice ;     			      
			if (choice == 1){
				char n[10];
				char ID[5] ; cout << "Enter product name  : " ; cin >> n ;
			    while(fin.read((char*)this, sizeof(*(this)))){
			     
				   cout << "\n.......Searching......" << endl;
				   int r = strcmp(n,name);
				   if (r == 0)
					   {  cout << "\nProduct found"<< endl;
				          get(); fin.close(); found = true; 	}
			    	
				}
			    if (found == false )	  
				    cout << "\n not found" ;	
			} // end of choice 1
			 
			if (choice == 2){
				char ID[5] ; cout << "Enter product ID : " ; cin >> ID;
			    while(fin.read((char*)this, sizeof(*(this)))){
			     
				    cout << "\n....Searching......" << endl;
				    int r = strcmp(ID,productID);
				    if (r == 0)
					    {  cout << "\nProduct found"<< endl;
				           get(); fin.close();found = true; 		   	}
			    	
				} //end of file 
			    if (found == false )
				{ // fin.seekg(+sizeof(*this),ios :: beg ); fin.close();				  	  
				   cout << "\nSorry ,This product is not available right now "<< endl;}
				   	
			} // end of choice 2
		} // end of function
		
		void searchproduct(char n[15] ){
			ifstream fin; 
			
			bool found = false;fin.open("Stocks.DAT", ios :: binary | ios :: in );
			fin.seekg(ios :: beg); 
			while(fin.read((char*)this, sizeof(*(this)))){
			   
			    cout << "\n....Searching......" << endl;
			    int r = strcmp(n,name);
				if (r == 0)
					{  cout << "\nProduct found"<< endl;
				           get(); fin.close(); found = true; 
						   	}
			    	
				} //end of while 
			    if (found == false )
				{
					
				   cout << "\nSorry ,This product is not available right now "<< endl;	}
			} // end of function
		
		    
		void deleteproduct(){
			fstream fio; 	bool found = false;
			fio.open("Stocks.DAT", ios :: binary | ios :: in | ios :: app );
			
			  			      
			
				char n[10];
				cout << "Enter product ID  : " ; cin >> n ;
			    while(fio.read((char*)this, sizeof(*(this)))){
			     
				   int r = strcmp(n,productID);
				   if (r == 0)
					   {  cout << "\nProduct found"<< endl;
					      strncpy(category , " " , sizeof(category) );
						  strncpy(name , " " , sizeof(name ) );
						  strncpy(producttype," ", sizeof(producttype));
						  strncpy(productID," ",sizeof(productID));
						  found = true; 	 
						  int n1 = fio.tellg();
						  cout << n1;	  
						  fio.seekp(+(sizeof(*this)), ios :: cur);
						  
						  fio.write((char*)this , sizeof(*this)) ; 
						  cout << "this product has been deleted" << endl; 	}
			    	      fio.close() ; 
				}
			    if (found == false )	  
				    cout << "\n not found" ;	
		}  //end of function
		
	    void showstock(){
	    	ifstream file;
            file.open("Stocks.DAT", ios::binary);
            file.seekg(0 , ios::end); 
            int n = (int)file.tellg() / sizeof(*this);
			cout <<"\n    Name       Category     Product Type     Product ID      Price  " << endl;   
			cout <<"-----------------------------------------------------------------------"<< endl; 
			int serial = 0; 
            for(int j = 1 ; j<=n ; ++j ){
            	readproduct(j); 
            	int w=13;
            	cout<< ++serial<<". " << setw(w) << left << name << setw(w) << left << category ;
				cout<< setw(20) << left << producttype << setw(10) << left << productID  << left << price <<" $"<< endl;
				//get();  
            	
			}//end of for 
		}//end of function   	 	
};
/////////////////////////////////////////////////////////////////////////////////////////
 
void datetime(){
	time_t timetoday;
    time(&timetoday);
    cout << " date and time: " << asctime(localtime(&timetoday));
	}


class customer 
{
	public:
		char name[15] ; 
		char ID[5] ;
		char category[15];
		
		string  address , phonenum , creditCardNo  , cname , ans; //phonenum;
		
		int  pay , get  ; int netpurchase = 0;
		float money ;
		float balance = 20000.000 ;
		
	public:
			
	void getname()
	{
		 //cout<<"Enter product info:" <<endl;
		 cout<<"\nProduct name : ";
		 cin>>name;	 }
	
	void request_order()
	{
		cout<<"\nEnter customer info"<<endl;
		cout<<"\nEnter your name: ";
		fflush(stdin);
		getline(cin , cname) ; fflush(stdin);	
		cout<<"\nEnter adress: "; fflush(stdin);
		getline( cin ,address); fflush(stdin);
		cout<<"\nEnter phone number: ";
		getline(cin , phonenum ) ; fflush(stdin);	}
		 
	bool checkpurchase(){
    
		return(netpurchase>0)? true : false;
    		
	}    
	
	void payment(float money )  
	{
		cout<<"Choose your way of payment: \n 1.online \n 2.offline\n\nEnter your choice(1-2): ";
		cin>>pay;
		
		if (pay==1)
		{
			int choice;
			cout << "\nselect way of online payment: \n 1.easy paisa \n2.Jazz Cash \n3.credit or debit card \n4.bank transfer";
		    cin >> choice;
		    switch(choice)
		    {
		    	case 1: cout<<"Send RS "<<money <<" on this easy paisa number: 1232456789";
		    	break;
		    	case 2: cout<<"Send RS "<<money<<" on this easy paisa number: 1232456789";
		    	break;
		    	case 3: cout<<"Enter your debit/credit card no: ";;
		    	cin>>creditCardNo;
		    	break;
		    	case 4: cout<<"Deposit money in this bank account: 154649878891";
		    	break;
		    	default: cout<<"INVALID CHOICE.";}
		    
		}
		
		else if(pay==2)
		{   cout<<"Enter money";
			float cash;
		    cin >> cash;
			  balance -= money ; 
		    cout << "\nYour updated Balance is  " << balance  ;}
		
		else
		cout<<"Invalid option";}
	
	    void writefeedback(){
	    	cout << "\nOn a scale of 1-10 " << endl ;  
	    	cout << "How likely are you to recommend our shop to others? "<< endl;
	    	cin >> ans; 
	    	cout << "How satisfied were you with your  experience? "<< endl;
	    	cin >> ans;
	    	cout << " How easy was it to find what you were looking for? " << endl;
	    	cin >> ans;
	    	cout << "Did you [find what you were looking for(yes or no)? "<<endl;
	    	cin >> ans;
	    	cout << "How satisfied are you with the value for money of your purchase? "<< endl;
	    	cin >> ans;
	    	cout << "What could we do to improve product or service? " << endl ;
	    	cin >> ans;
	    	cout << "GoodBye" << endl;
		}  		
		
		
   
		
		void getProduct()
		{	cout<<"Choose your way of get product(1-2): \n\n1.Home delivery\n2. Get from shop keeper\n";
			cin>>get;
			cout << "Thank you for using our services , We hope to see you again" << endl; }
		
	
};	 
//////////////////////////////////////////////////////////////////////////////////////////////////
class billing{
	public: 
	   
	   float total = 0.0 ;
	   customer c  ;
	   char pname[5][31];
       float iprice[5];
	   
	   
	public:
			
		void savebill(){
			fstream fio;
		    fio.open("Bills.DAT" , ios :: app | ios :: binary);
		    fio.write((char*)this, sizeof(*this));
			fio.close(); 		}    	
		void readbill(){
			fstream fio;
		    fio.open("Bills.DAT" , ios :: in | ios :: binary);
		    while (!fio){
			    fio.read((char*)this, sizeof(*this));
			    
		        }
			fio.close(); }		
			
	    
};
/////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////
 
class Login
{
  public:

    int choice;
    char email[30];
    char password[20];
    
    

  public:
  	
  	bool checkshopkeeper(){
  		
  		int r1 = (strcmp(email , "shop@gmail.com"));
		int r2 = (strcmp(password  , "123")) ;
		if (r1 == 0 && r2 == 0 )   
  		    return true;
		else 
		    return false;
		   	    
		    
	  }
  	bool checkcustomer(){
  		int r1 = (strcmp(email , "guest@gmail.com"));
		int r2 = (strcmp(password  , "abc")) ;
		if (r1 == 0 && r2 == 0 )   
  		    return true;
		else 	
			return false;
			
	   }
  		
	  	    

    void description(){

    cout<<"\t\t\t\t-------------------------------------------------\n";
    cout<<"\t\t\t\t                                                 \n";
    cout<<"\t\t\t\t                 SHOP MAIN MENU                  \n";
    cout<<"\t\t\t\t                                                 \n";
    cout<<"\t\t\t\t-------------------------------------------------\n";
    cout<<"\t\t\t\t                                                 \n";
 
    cout<<"\t\t\t\t|               1)Shopkeeper                     \n";
    cout<<"\t\t\t\t|                                                \n";
    cout<<"\t\t\t\t|               2)Customer                       \n";
    cout<<"\t\t\t\t|                                                \n";
    cout<<"\t\t\t\t|               3)Exit                           \n";
    cout<<"\t\t\t\t              Please Select!";
    cin>>choice;
}
    
    
    void display(){
  
				 
      int count = 3;  	
      switch(choice)
      //int a ,b;
    
	{
        case 1:	
        
        for ( int j = 0 ; j<3 ; ++j){
        	cout<<"\t\t\t Please Login  \n";
            cout<<"\t\t\t Enter Email   \n";
            cin>>email;
            cout<<"\t\t\t Enter Password  \n";
            cin>>password;
            if (checkshopkeeper() == true)
                {
				  cout <<"\a";
                 system("color A0");     
                 int h ,g;
                 cout <<"\t\t\t\tLOADING";
		         for(h=0;h<=10;h++){
			        cout<<" . ";
			        for(g=0;g<=100000000;g++){   }
		         }
		         
				 break ;
				}
				 
            else 
            {
			--count;
            system("color 40");
			cout << "\ninvalid email or password\nTry again" << endl;
			cout << "Tries Remaining :" << count << endl;}
		}// end of for
		
        break;    
    case 2: 
        
        for (int j = 0 ; j<3 ; ++j){
	    cout<<"\t\t\t Please Login  \n";
        cout<<"\t\t\t Enter Email   \n";
        cin>>email;
        cout<<"\t\t\t Enter Password  \n";
        cin>>password;
        //checkcustomer();
        if (checkcustomer() == true)
              {
				 cout <<"\a";
                 system("color A0");
                 int h ,g;
                 cout <<"\t\t\t\tLOADING";
		         for(h=0;h<=10;h++){
			     cout << " . ";
			     for(g=0;g<=100000000;g++){   }
		         }
		         break ;  }
        else
	{	    --count;
	        system("color 40");    
		    cout << "\ninvalid email or password\nTry again" << endl; 
			cout<<"\nTries remaining : " << count << endl;    }
	} // end of for	
		
        break;   
    
    case 3: exit(0);     //successfull termination of program
     
    default: cout<<"Please select from the given options"; 
    
    } // end of switch
    //} // end of while
} // end of function

}; // end of class

 