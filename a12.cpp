#include <iostream>
#include<bits/stdc++.h>
using namespace std;

map<int,int> keyMap;

void setPermutationOrder(string key) 
{              
    // Add the permutation order into map  
    for(int i=0; i < key.length(); i++) 
    { 
        keyMap[key[i]] = i; 
    } 
} 

string decryptMessage(string cipher, string key) 
{ 
    /* calculate row and column for cipher Matrix */
    int col = key.length(); 
  
    int row = cipher.length()/col; 
    char cipherMat[row][col]; 
  
    /* add character into matrix column wise */
    for (int j=0,k=0; j<col; j++) 
        for (int i=0; i<row; i++) 
            cipherMat[i][j] = cipher[k++]; 
  
    /* update the order of key for decryption */
    int index = 0; 
    for( map<int,int>::iterator ii=keyMap.begin(); ii!=keyMap.end(); ++ii) 
        ii->second = index++; 
  
    /* Arrange the matrix column wise according  
    to permutation order by adding into new matrix */
    char decCipher[row][col]; 
    map<int,int>::iterator ii=keyMap.begin(); 
    int k = 0; 
    for (int l=0,j; key[l]!='\0'; k++) 
    { 
        j = keyMap[key[l++]]; 
        for (int i=0; i<row; i++) 
        { 
            decCipher[i][k]=cipherMat[i][j]; 
        } 
    } 
  
    /* getting Message using matrix */
    string msg = ""; 
    for (int i=0; i<row; i++) 
    { 
        for(int j=0; j<col; j++) 
        { 
            if(decCipher[i][j] != '_') 
                msg += decCipher[i][j]; 
        } 
    } 
    return msg; 
} 


int main(void){
    string cipher = "DNAIOBUJDOHLAPAQUIHYNQAKIOEEWWPOHLDPIKXWWOOBWPJKUAUZEEUUIDJNGKOHAJXBKEPHDDKWW";

    for(int k= 0; k <1; k++){
        string const key = "AB";
        setPermutationOrder(key);
        cout<<"Decryption Message: " << decryptMessage(cipher, key) <<endl;
    }
}