#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main(){
    //Переменные
    char e_message[1000]{};
    char d_message[1000]{};
    vector <int> e_message_ascii{};
    vector <int> d_message_ascii{};
    char selection{' '};
    int decrypt_size{1};
    do {
        cout << endl;
        //Меню программы
        cout << "=====Caesar's code decryptor====="<< endl << endl;
        cout << "What you want to do?"<< endl;
        cout << "E - Encrypt"<< endl;
        cout << "D - Decrypt"<< endl;
        cout << "Q - Quit"<< endl;
        cin >> selection;
        //Шифрование
        if(selection == 'e' or selection == 'E') {
            cout << "Enter message you want to encrypt: ";
            cin.getline(e_message,100);
            cin.getline(e_message,100);
            cout << "Enter decrypt size: ";
            cin >> decrypt_size;
            cout << "Your message: " << e_message << endl;
            //шифруем сообщение (переводим символы в ascii формат)
            for (int i {0} ; i < strlen(e_message) ; i++){
                e_message_ascii.push_back(e_message[i]);
            }
            //шифруем сообщение (добавляем ascii символам +1 к их значению)
            for (int i {0} ; i < strlen(e_message) ; i++) {
                e_message_ascii[i] += decrypt_size;
            }
            //Выводим зашифрованное сообщение
            cout << "Encrypted message: ";
            for (int i = 0; i < e_message_ascii.size(); i++){
                cout << (char)e_message_ascii[i];
            }
            cout << endl;
            //Очищаем вектор с зашифрованным сообщением
            e_message_ascii.clear();
        }

        else if(selection == 'D' or selection == 'd'){
            cout << "Enter a message you want to decrypt: ";
            cin.getline(d_message,100);
            cin.getline(d_message,100);
            cout << "Enter decrypt size: ";
            cin >> decrypt_size;
            cout << "Your message: " << d_message << endl;
            //расшифровываем  сообщение (переводим символы в ascii формат)
            for (int i {0} ; i < strlen(d_message) ; i++){
                d_message_ascii.push_back(d_message[i]);
            }
            //расшифровываем сообщение (добавляем ascii символам -1 к их значению)
            for (int i {0} ; i < strlen(d_message) ; i++) {
                d_message_ascii[i] -= decrypt_size;
            }
            //Выводим зашифрованное сообщение
            cout << "Decrypted message: ";
            for (int i = 0; i < d_message_ascii.size(); i++){
                cout << (char)d_message_ascii[i];
            }
            cout << endl;
            //Очищаем вектор с расшифрованымсообщением
            d_message_ascii.clear();
        } else{
            cout << "You entered inappropriate character. Try again" << endl;
        }
    } while (selection != 'Q' and selection != 'q');
}