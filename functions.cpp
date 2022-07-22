#include "functions.h"
using namespace std;
//----------------------------WELCOME--------------------------------
string welcome()
{
    string sign_choice;
    cout << "Khaje Nasir Toosi university of technology" << endl;
    cout << "are you new student ? (yes/no) " << endl;
    cin >> sign_choice ;
    return sign_choice ;
}
//----------------------------Main logic-----------------------------
     // *** VARIABLES ***
string new_username,new_password,new_password_repeat,answer; // signup section
string username_input,password_input,username_check,password_check; // login section
// NOTE : put your own address path at file[0] .
string file[] = { "C:\\Users\\user\\Desktop\\C++\\PROJECTS\\login_system\\userpass\\"
                  ,".txt","pass.txt"};
bool userC=false,passC=false;

//----------------------------signUp---------------------------------
string signUp_func(string sign_choice)
{
    if (sign_choice == "yes")
    {
        //get username
        cout << "you need to create a student account to start your journey here !" << endl;
        cout << "Please enter username : " << endl;
        cin >> new_username;
        ofstream usernames_file( file[0] + new_username + file[1] );
        usernames_file << new_username << endl;
        usernames_file.close();

        //get password
        cout << "please enter a password : " << endl;
        cin >> new_password;
        cout << "Confirm your password: " << endl;
        cin >> new_password_repeat;
        while (new_password != new_password_repeat) // check password inputs
        {
            cout << "your passwords are not the same!\nConfirm your password again : " << endl;
            cin >> new_password_repeat;
        }
        ofstream passwords_file( file[0] + new_username + file[2] );
        passwords_file << new_password << endl;
        passwords_file.close();
        cout << "Done ! would you like to login to your account now ? " << endl;
        cin >> answer ;
        if (answer == "yes") { return sign_choice = "no" ; }
        else cout << "see you later";
    }
}

//----------------------------login---------------------------------
void login_func(string sign_choice)
{
    if (sign_choice == "no")
    {
        // get username password
        cout << "Please enter your username : " << endl;
        cin >> username_input;
        cout << "Please enter your password : " << endl;
        cin >> password_input;

        // read from files
        cout << new_username.length() << endl;
        ifstream usernames_file(file[0] + username_input + file[1] );
        getline(usernames_file, username_check);
        ifstream passwords_file(file[0] + username_input + file[2] );
        getline(passwords_file, password_check);

        // check
        if (username_input == username_check ) { userC = true;}
        if (username_input != username_check ) {
            while (userC == false) {
                cout << "invalid username!" << endl;
                cout << "Please enter your username again : " << endl;
                cin >> username_input;
                if (username_input == username_check) { userC = true; }
            }
        }
        if (password_input == password_check ) { passC = true;}
        else
            while (passC == false) {
                cout << "invalid password!" << endl;
                cout << "Please enter your password again : " << endl;
                cin >> password_input;
                if (password_input == password_check) { passC = true; }
            }
        if (userC = true && passC == true) {
            cout << "you are logged in successfully" << endl; }
    }
}
