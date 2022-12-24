#include<iostream>
using namespace std;

class Account{
    public:
     string ID;
     string Password;
     int bankbalance;
    /*public:
     void setID(string id){
        ID=id;
     }
     string getID(){
        return ID;
     }
     void setpassword(string password){
        Password=password;
     }
     string getpassword(){
        return Password;
     }*/
//usage of constructors beneficial?

};
Account currentaccount;
int main(){
    string Id,password,IdReceiver;
    int a,c,g=0,h=0,k=0,l=0;
    Account accounts[10];
    accounts[0].ID="Shaurya1"; //giving dummy values(3 people) as of now to test program
    accounts[0].Password="Atharvanoob1";
    accounts[0].bankbalance=50000;
    accounts[1].ID="Shaurya2";
    accounts[1].Password="Atharvanoob2";
    accounts[1].bankbalance=10000;
    accounts[2].ID="Shaurya3";
    accounts[2].Password="Atharvanoob3";
    accounts[2].bankbalance=5000;
    int userSerial=3; //i dont want this everytime i run,how will it remember serial number,want this to get everytime from a permananent memory
    cout<<"Welcome to the online portal of Vijay Malya Bank"<<endl;
    cout<<"1)Login to existing bank account(press 1)"<<endl;
    cout<<"2)create new account(press 2)"<<endl;
    cin>>a;
    if(a==1){
        cout<<"enter ID"<<endl;
        cin>>Id;
        for(int b=0;b<3;b++){ //after change put b<serial number
            if(Id==accounts[b].ID){
                k++;
                cout<<"enter password"<<endl;
                cin>>password;
                if(password==accounts[b].Password){ 
                    l++;
                    cout<<"***Account verified***"<<endl;
                    cout<<"press the number key for the function you would like to perform"<<endl;
                    cout<<"1)Deposit money"<<endl;
                    cout<<"2)Withdraw money"<<endl;
                    cout<<"3)Transfer money to another account of Vijay Malya Bank"<<endl;
                    cin>>c;
                    if(c==1){
                        int sumDeposited;
                        cout<<"How much money would you like to deposit"<<endl;
                        cout<<"current bank balance is "<<accounts[b].bankbalance<<endl;
                        cin>>sumDeposited;
                        if(sumDeposited>=0){
                            accounts[b].bankbalance=accounts[b].bankbalance+sumDeposited;
                            cout<<"current bank balance set to "<<accounts[b].bankbalance<<endl;
                        }
                        else{
                            cout<<"invalid input(please enter number greater than 0)"<<endl;
                        }

                    }
                    else if(c==2){
                        int sumwithdrawn;
                        cout<<"how much money would you like to withdraw"<<endl;
                        cin>>sumwithdrawn;
                        if(sumwithdrawn>=0&&sumwithdrawn<=accounts[b].bankbalance){
                             accounts[b].bankbalance=accounts[b].bankbalance-sumwithdrawn;
                             cout<<"current bank balance set to "<<accounts[b].bankbalance<<endl;
                        }
                        else{
                            cout<<"invalid input"<<endl;
                        }

                    }
                    else if(c==3){
                        int sumtransferred;
                        cout<<"enter the amount of money you want to transfer"<<endl;
                        cin>>sumtransferred;
                        if(sumtransferred>=0&&sumtransferred<= accounts[b].bankbalance){
                            cout<<"enter the account ID to which you need to transfer"<<endl;
                            cin>>IdReceiver;
                            for(int f=0;f<3;f++){//later change to f<serial number
                            if(accounts[f].ID==IdReceiver){
                                accounts[f].bankbalance= accounts[f].bankbalance+sumtransferred;
                                accounts[b].bankbalance= accounts[b].bankbalance-sumtransferred;
                                cout<<"amount has been transferred successfully"<<endl;
                                cout<<"your current balance is now "<<accounts[b].bankbalance;
                                g++;
                            }
                            }
                            if(g==0){
                                cout<<"invalid ID"<<endl;
                            }
                    } else{
                        cout<<"invalid entry"<<endl;
                    }
                    }

            }}}
            if(k==0){
                cout<<"This ID does not exist"<<endl;
            }
            if(l==0){
                cout<<"Incorrect password"<<endl;
            }
            
        

    }
    else if(a==2){
        cout<<"enter an ID(alphabets/numbers/special characters without space{more than 5 characters})"<<endl;
        cin>>accounts[userSerial].ID;
        for(int e=0;e<userSerial;e++){
            if(accounts[userSerial].ID==accounts[e].ID){
                cout<<"this Id has already been taken"<<endl;
                accounts[userSerial].ID='*';
                h++;
            }
        }
            if(h==0){
                cout<<"create a password(use special characters too for a stronger password)"<<endl;
                cin>>accounts[userSerial].Password;
                cout<<"enter initial sum to be deposited"<<endl;
                int initialsum;
                cin>>initialsum;
                accounts[userSerial].bankbalance=initialsum;
                cout<<"your account has been successfuly created,welcome to Vijay Malya Bank"<<endl;
                cout<<"current bank balance= "<<accounts[userSerial].bankbalance<<endl;
                 userSerial++;//so that next person can input their account into next space in array
            }
        }
        else{
            cout<<"invalid number"<<endl;
        }
        return 0;
    }

    



