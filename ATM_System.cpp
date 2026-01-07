// ATM_System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<string>
#include <fstream>
#include<iomanip>
#include<cstdlib>
using namespace std;
enum enTransaction{enQuickWithdrow=1,enNormalWithdraw=2,enDeposit=3,enCheckBalance=4,enChangePassword=5,enLogout=6};
enum enQuickWithdrowChosse { enTwenty = 1, enFifty = 2, enOneHundred = 3, enTwoHundred = 4, enFourHundred = 5, enSixHundred = 6, enEightHundred = 7, enOneThousand = 8, enExit = 9 };

const string FileClient = "ClientFile.txt";

struct stinfo {
    string account, name;
    string pincode;
    string phoneNumber;
    double countbalance;
    bool flag = false;


};
stinfo CurrentClient;
void ShowAtmMainMenue();
void loginClient();
void QuickWithdrowScreen();
void NormalWithdrawScreen();
void ChangePasswordClientScreen();
string space(short num) {
    string s = "";
    for (short i = 0; i <= num; i++)
    {
        s += "\t";
    }

    return s;
}
string JoinString_struct(stinfo strinfo, string delim = "#//#") {


    string s = "";
    s += strinfo.account + delim;
    s += strinfo.name + delim;
    s += (strinfo.pincode) + delim;
    s += (strinfo.phoneNumber) + delim;
    s += to_string(strinfo.countbalance) + delim;

    return s.substr(0, s.length() - delim.length());

}
void loadVectorTofile(vector<stinfo>& Vname) {

    fstream myfile;
    string word = "";
    myfile.open(FileClient, ios::out);

    if (myfile.is_open()) {
        for (stinfo& S : Vname) {

            if (S.flag == false) {



                word = JoinString_struct(S);
                myfile << word << endl;
            }


        }




        myfile.close();
    }
    else {


        cout << "this file not open\n";

    }

}
vector <string> split(string name, string delim = "#//#") {
    vector<string> Vword;
    short pos = 0;
    string s = "";
    while ((pos = name.find(delim)) != std::string::npos) {

        s = name.substr(0, pos);
        if (s != "") {

            Vword.push_back(s);

        }

        name = name.erase(0, pos + delim.length());


    }
    if (name != "") {


        Vword.push_back(name);
    }


    return Vword;


}
stinfo converFromVectorToStruct(string name, string delim = "#//#") {
    stinfo info;
    vector<string> Vword = split(name, delim);

    info.account = Vword[0];
    info.name = (Vword[1]);
    info.pincode = Vword[2];
    info.phoneNumber = (Vword[3]);
    info.countbalance = stof(Vword[4]);

    return info;

}
vector<stinfo> loadfromfile(string file) {
    vector<stinfo>Vclien;
    fstream myfile;
    string line;
    stinfo stclient;

    myfile.open(file, ios::in);
    if (myfile.is_open()) {


        while (getline(myfile, line)) {

            stclient = converFromVectorToStruct(line);
            Vclien.push_back(stclient);


        }



        myfile.close();

    }





    return Vclien;

}
short ReadNumberFromMenue(string Message) {
    short num = 0;
    cout << Message;
    cin >> num;
    return num;
}
void GoToTransactoinMenue() {


    cout << "\n\nPress any key to go back to Transaction Menue...";
    system("pause>0");
    ShowAtmMainMenue();


}
void ClientBalance(string Message) {

    
    cout << "Your Balance "<<Message << CurrentClient.countbalance << endl;


}
void CheckBalanceScreen() {
    system("cls");
    cout << "================================================================================================\n";
    cout << space(4) << "Check Balance Screen \n";
    cout << "================================================================================================\n";
    ClientBalance("Now is ");


}
bool CheckValueLessThanTheBalance(float Value) {

    return (Value <= CurrentClient.countbalance);

}
void  MessageCheckBalance() {

  
        cout << " The amount exceeds your balance, make another choice.\n";
        cout << "\n\nPress any key to continue...";
        system("pause>0");
        system("cls");
        
    


}
bool Deposits(string account, double ammount, vector<stinfo>& Vword) {

    char ch = 'y';


    cout << "do you want to write in file:(y/n):";
    cin >> ch;
    if (tolower(ch) == 'y') {
        for (stinfo& C : Vword) {


            if (C.account == account) {

                C.countbalance += ammount;

                loadVectorTofile(Vword);
                cout << "Done Successfuly .NEW balance is :" << C.countbalance << endl;
                return true;
            }

        }

    }
    return false;

}
void Withdrow(float balance) {
  
   
    if (!CheckValueLessThanTheBalance(balance)) {
        MessageCheckBalance();
        QuickWithdrowScreen();
        return;
    }

    vector<stinfo>Vclient = loadfromfile(FileClient);
    Deposits(CurrentClient.account, balance * -1, Vclient);
    CurrentClient.countbalance -= balance;

}
void GoToAtmMenue() {


    cout << "\n\nPress any key to go back to ATM Main Menue...";
    system("pause>0");
    ShowAtmMainMenue();


}
void PerformQuickWitdrow(enQuickWithdrowChosse choose) {

    switch (choose) {

    case enQuickWithdrowChosse::enTwenty:
        Withdrow(20);
        GoToAtmMenue();
        break;
    case enQuickWithdrowChosse::enFifty:
        
        Withdrow(50);
        GoToAtmMenue();
        break;
    case enQuickWithdrowChosse::enOneHundred:
       
        Withdrow(100);
        GoToAtmMenue();
        break;
    case enQuickWithdrowChosse::enTwoHundred:
        
        Withdrow(200);
        GoToAtmMenue();
        break;
    case enQuickWithdrowChosse::enFourHundred:
     
        Withdrow(400);
        GoToAtmMenue();
        break;
    case enQuickWithdrowChosse::enSixHundred:
       
        Withdrow(600);
        GoToAtmMenue();
        break;
    case enQuickWithdrowChosse::enEightHundred:
       
        Withdrow(800);
        GoToAtmMenue();
        break;
    case enQuickWithdrowChosse::enOneThousand:
        Withdrow(1000);
        GoToAtmMenue();
        break;
    case enQuickWithdrowChosse::enExit:

        GoToAtmMenue();
        break;
    default:
        GoToAtmMenue();
        break;
    }








}
short ReadNumberInQuickWithdraw() {
    short num;
    do {
        cout << "Enter The Number From [1] - [9] :";
        cin >> num;
    } while (num < 1 || num>9);

    return num;

}
void QuickWithdrowScreen() {

    system("cls");
    cout << "================================================================================================\n";
    cout << space(4) << "Quick Withdrow \n";
    cout << "================================================================================================\n";
    cout <<space(4) <<"\t[1] 20  \t\t [2]50\n";
    cout <<space(4) <<"\t[3] 100 \t\t [4]200\n";
    cout <<space(4) <<"\t[5] 400 \t\t [6]600\n";
    cout <<space(4) <<"\t[7] 800 \t\t [8]1000\n";
    cout <<space(4) << "\t[9] Exit\n";
    cout << "================================================================================================\n";
    ClientBalance("Before Withdraw :");
    PerformQuickWitdrow(enQuickWithdrowChosse(ReadNumberInQuickWithdraw()));
   

}
float ReadAmount(string message) {

    float ammount = 0;
    cout << message;
    cin >> ammount;
    return ammount;

}
double ReadAmmontInDeposite() {
    double num;
    do {
        cout << "Enter The Posative Number :";
        cin >> num;

    } while (num < 0);

    return num;
}
void PerformanceDeposit() {

    double Ammount = ReadAmmontInDeposite();
    vector<stinfo>Vclients = loadfromfile(FileClient);
    Deposits(CurrentClient.account, Ammount, Vclients);
    CurrentClient.countbalance += Ammount;


}
void DepositScreen() {
    cout << "==========================================================\n";
    cout << space(1) << "Deposit Screen\n";
    cout << "==========================================================\n";
    ClientBalance("Before Deposit is :");
    PerformanceDeposit();
   


}
int ReadMultiplesOfFive(string message) {

    int num;
    do {

        cout << message;
        cin >> num;
    } while (num % 5 != 0);

        return num;
}
void PerformanceNormalWithdraw() {

    double ammount = ReadMultiplesOfFive("\n please Enter The Multiple 5`s?");
    if (!CheckValueLessThanTheBalance(ammount)) {
        MessageCheckBalance();
        NormalWithdrawScreen();
        return;
    }
    vector<stinfo>Vclient = loadfromfile(FileClient);
    Deposits(CurrentClient.account, ammount*-1, Vclient);
    CurrentClient.countbalance -= ammount;

 }
void NormalWithdrawScreen() {
    cout << "==========================================================\n";
    cout << space(1) << "Normal Withdraw\n";
    cout << "==========================================================\n";
    ClientBalance("Before Normal Withdrow is :");
    PerformanceNormalWithdraw();
   



}
void PerfromTransaction(enTransaction choose) {

    switch (choose) {

    case enTransaction::enQuickWithdrow:
        system("cls");
        QuickWithdrowScreen();
        GoToAtmMenue();
      
        break;
    case enTransaction::enNormalWithdraw:
        system("cls");
        NormalWithdrawScreen();
        GoToAtmMenue();
        break;
    case enTransaction::enDeposit:
        system("cls");
        DepositScreen();
        GoToAtmMenue();
        break;
     
    case enTransaction::enCheckBalance:
        system("cls");
        CheckBalanceScreen();
        GoToAtmMenue();
        
        break;
    case enTransaction::enChangePassword:
        system("cls");
        ChangePasswordClientScreen();
        GoToAtmMenue();
        break;
    case enTransaction::enLogout:
        system("cls");
        loginClient();
        
        break;

    }





}

void ShowAtmMainMenue() {

    system("cls");
    cout << "================================================================================================\n";
    cout << space(4) << "ATM Main Menue Screen\n";
    cout << "================================================================================================\n";
    cout << space(4) << "[1] Quick Withdraw.\n";
    cout << space(4) << "[2] Normal Withdraw \n";
    cout << space(4) << "[3] Deposit \n";
    cout << space(4) << "[4] Check Balance  \n";
    cout << space(4) << "[5] Change Password  \n";
    cout << space(4) << "[6] Logout  \n";

    
    cout << "================================================================================================\n";
   

    PerfromTransaction(enTransaction(ReadNumberFromMenue("Choose what do you want to do? [1 to 5]?")));



}

bool CheckIAccountAndPincodeInFile(string account, string pincode, stinfo& user) {
    vector<stinfo>Vclient = loadfromfile(FileClient);

    for (stinfo& s : Vclient) {
        if ((account == s.account && pincode == s.pincode)) {
            user = s;
            return true;
        }



    }
    return false;
}
bool LoadClientInfo(string account, string pincode) {

    return CheckIAccountAndPincodeInFile(account, pincode, CurrentClient);

}

string ReadPassword(string message) {
    string pass="";
    cout << message;
    getline(cin >> ws,pass);


    return pass;


}
bool ArePasswordsEqual(string currentpassword, string newpassword) {

    return (currentpassword == newpassword);

}
void ChangePasswordInfile(string account, string pincode, vector<stinfo>& Vclient) {
    char ch = 'y';
    cout << "do you want to write in file:(y/n):";
    cin >> ch;
    if (tolower(ch) == 'y') {
        for (stinfo& C : Vclient) {
            if (C.account == account) {

                C.pincode = pincode;
                loadVectorTofile(Vclient);
                cout << "Done Successfuly,Change Password :-)";
                return;
            }



        }

    }
    return;



}
void VerifyAndRetryPassword(const string& correctPassword, string& enteredPassword, string message) {
    short count = 0;
    bool notfound = true;
    do {
        enteredPassword = ReadPassword(message);
        (!ArePasswordsEqual(correctPassword, enteredPassword)) ? count++ : notfound = false;
        if (count == 3) {
            cout << "You have attempted 3 times. Please try again later\n";
            GoToAtmMenue();
        }

    } while (notfound);



}
void PerformanceChangePasswordClient() {

    string newpassword, oldpassword,renewpassword;
    short count = 0;
    bool notfound = true;  

    VerifyAndRetryPassword(CurrentClient.pincode, oldpassword, "Enter the current password:");
   

    newpassword = ReadPassword("Enter the new password :");
    VerifyAndRetryPassword(newpassword, renewpassword, "Re - enter the new password:");

    vector<stinfo>Vclient = loadfromfile(FileClient);
    ChangePasswordInfile(CurrentClient.account, newpassword, Vclient);
    CurrentClient.pincode = newpassword;

}
void ChangePasswordClientScreen() {

    system("cls");
    cout << "================================================================================================\n";
    cout << space(4) << " Change Password Screen \n";
    cout << "================================================================================================\n";
    PerformanceChangePasswordClient();


}





void loginClient() {


    string account, pincode;
    bool Notfound = false;
    do {

        system("cls");
        cout << "================================================================================================\n";
        cout << space(4) << " login Screen \n";
        cout << "================================================================================================\n";
        if (Notfound) {
            cout << "invlaid AccountNumber / Pincode\n";
        }


        cout << "Enter Account Number?";
        getline(cin >> ws, account);
        cout << "Enter Pincode?";
        getline(cin >> ws, pincode);
        Notfound = !LoadClientInfo(account, pincode);

    } while (Notfound);



    ShowAtmMainMenue();

}
int main()
{
    loginClient();
}
