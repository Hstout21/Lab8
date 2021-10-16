/**
 *   @file: Lab8.cc
 * @author: Hunter Stout
 *   @date: October 15, 2021
 *  @brief: File encryptor/decryptor.
 */

#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

//Function prototypes.

/**
 * displayMenu - Display menu to the user.
 * @param key - For a more interactive main menu :D
 * @return - Void function.
 */
void displayMenu(int key);

/**
 * keySelector - Change the Encryption/Decryption key.
 * @return - New key selected by user.
 */
int keySelector();

/**
 * Encryption - Encrypts a file into a new file of the user's choosing.
 * @param key - Inputs the user-selected key/default key to encrypt the file.
 * @return - Void function.
 */
void encryption(int key);

/**
 * Decryption - Decrypts a file into a new file of the user's choosing.
 * @param key - Inputs the user-selected key/default key to decrypt the file.
 * @return - Void function.
 */
void decryption(int key);

//Main function.
int main() {

    //Menu & Key
    int choice, key;

    //Default Key
    key = 3;

    //Main Do-While loop, executes while when quitting program.
    do {

        //Menu function, & asks for menu choice.
        displayMenu(key);
        cin >> choice;

    //Key selector function.
    if (choice == 1) {
        key = keySelector();

    }
    //Encryption function.
    else if (choice == 2) {
        encryption(key);

    }
    //Decryption function.
    else if (choice == 3) {
        decryption(key);
    }

    //Quit program.
    } while(choice != 4);
        exit (0);

return 0;
}

//Function for main menu.
void displayMenu(int key) {

    //Menu with default key.
    if (key == 3) {
        cout << " " << endl;
        cout << "*------------------------------------------*" << endl;
        cout << "*- Welcome to hunter's file protector! :D -*" << endl;
        cout << "*------------------------------------------*" << endl;
        cout << "* 1. Pick a key value 1-10 (Default: 3)    *" << endl;
        cout << "* 2. Encryption for selected file          *" << endl;
        cout << "* 3. Decryption for selected file          *" << endl;
        cout << "* 4. Quit                                  *" << endl;
        cout << "*------------------------------------------*" << endl;
    }

    //Menu with altered key.
    else {
        cout << " " << endl;
        cout << "*------------------------------------------*" << endl;
        cout << "*- Welcome to hunter's file protector! :D -*" << endl;
        cout << "*------------------------------------------*" << endl;
        cout << "* 1. Pick a key value 1-10 (Current: " << key << ")    *" << endl;
        cout << "* 2. Encryption for selected file          *" << endl;
        cout << "* 3. Decryption for selected file          *" << endl;
        cout << "* 4. Quit                                  *" << endl;
        cout << "*------------------------------------------*" << endl; 
    }
}

//Key selector function.
int keySelector() {

    //Placeholder for wrong key input.
    keyStart:

    //Input for new key.
    int newKey;

    //Key main menu & input.
    cout << " " << endl;
    cout << "Enter a key value 1-10 (Default 3)" << endl;
    cout << "New Encryption/Decryption Key: ";
    cin >> newKey;

        //Successful key input, (1-10).
        if (newKey >=1 && newKey <=10) {
            cout << " " << endl;
            cout << "The new key you have selected: " << newKey << endl;
        }

        //Failed key input.
        else {
            cout << " " << endl;
            cout << "The number you have chosen is not between 1-10, Try again!" << endl;
            goto keyStart;
        }

    //Returns new key.
    return (newKey);
}

void encryption(int key) {

    //Main ifstream & ofstream for file altering.
    ifstream inStream;
    ofstream outStream;

    //Strings for file name cins.
    string input, output;

    //Main char for altering file.
    char fileContent;

    //Main message & input for file to alter.
    cout << " " << endl;
    cout << "Enter file name to Encrypt: ";
    cin >> input;

    //ifstream open.
    inStream.open(input);

        //ifstream fail check.
        if (inStream.fail()) {
            cout << " " << endl;
            cout << "Error we could not locate this file. Try again" << endl;
            exit (0);
        }

    //Main message & input for file to output.
    cout << " " << endl;
    cout << "Enter the new Encrypted file name:";
    cin >> output;

    //ofstream open.
    outStream.open(output);

        //ofstream fail check.
        if (outStream.fail()) {
            cout << " " << endl;
            cout << "Error we failed to create this new file. Try again" << endl;
            exit (0);
        }

    //Grabs first character from file before loop.
    inStream.get(fileContent);

        //While loop with sentinel at the end of the ifstream file.
        while (!inStream.eof()) {

            //Main math for encryption.
            fileContent = fileContent + key;

            //Outputs new encrypted character.
            outStream << fileContent;

            //Grabs rest of the characters in the file.
            inStream.get(fileContent);
        }

    //Main completed file message.
    cout << " " << endl;
    cout << "File: " << input << " has been encrypted into file: " << output << endl;

    //ifstream & ofstream close.
    inStream.close();
    outStream.close();
}

void decryption(int key) {

    //Main ifstream & ofstream for file altering.
    ifstream inStream;
    ofstream outStream;

    //Strings for file name cins.
    string input, output;

    //Main char for altering file.
    char fileContent;

    //Main message & input for file to alter.
    cout << " " << endl;
    cout << "Enter file name to Decrypt: ";
    cin >> input;

    //ifstream open.
    inStream.open(input);

        //ifstream fail check.
        if (inStream.fail()) {
            cout << " " << endl;
            cout << "Error we could not locate this file. Try again" << endl;
            exit (0);
        }

    //Main message & input for file to output.
    cout << " " << endl;
    cout << "Enter the new Decrypted file name:";
    cin >> output;

    //ofstream open.
    outStream.open(output);

        //ofstream fail check.
        if (outStream.fail()) {
            cout << " " << endl;
            cout << "Error we failed to create this new file. Try again" << endl;
            exit (0);
        }

    //Grabs first character from file before loop.
    inStream.get(fileContent);

        //While loop with sentinel at the end of the ifstream file.
        while (!inStream.eof()) {

            //Main math for decryption.
            fileContent = fileContent - key;

            //Outputs new decrypted character.
            outStream << fileContent;

            //Grabs rest of the characters in the file.
            inStream.get(fileContent);
        }

    //Main completed file message.
    cout << " " << endl;
    cout << "File: " << input << " has been decrypted into file: " << output << endl;

    //ifstream & ofstream close.
    inStream.close();
    outStream.close();
}