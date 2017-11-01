//
//  main.cpp
//  Playlist using objects
//
//  Created by Navroop Singh Bajwa on 01/11/17.
//  Copyright © 2017 Navroop Singh Bajwa. All rights reserved.
//


#include "Header.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    listofsongs l1;
    int n;
    cin>>n;
    cin.ignore();
    while(n--){
        char *t;
        t=new char[50];
        t[0]='S';
        //cin.get(t,50);
        //cin.ignore();
        
        l1.push(t);
    }
    
    cout<<"List : \n";
    l1.display();
    cout<<endl<<"Hashtable : "<<endl;
    l1.displayhashtable();
    
    cout<<"Enter no of deletions : ";
    cin>>n;
    while(n--){
        cout<<"Enter no : ";
        int t;
        cin>>t;
        songs *node=l1.getaddress(t);
        
        if(l1.getaddress(t)==NULL)cout<<"Fck\n";
        else {
            l1.notrequired(node);
            cout<<node->no<<" "<<endl;
            
        }
        
    }
    cout<<"New Modified list : \n";
    l1.display();
    
    cout<<endl<<"New Hashtable : "<<endl;
    l1.displayhashtable();
    return 1;
}
