//
//  Header.h
//  Playlist using objects
//
//  Created by Navroop Singh Bajwa on 01/11/17.
//  Copyright © 2017 Navroop Singh Bajwa. All rights reserved.
//

#ifndef Header_h
#define Header_h
#include <iostream>
using namespace std;
struct songs{
    char *name;
    int no;
    bool love;//up=true,down=false
    songs *next,*pre;
};
struct playlist{
    char *name;
    struct songs *songdata;
    struct playlist *nextsong;
};

class listofsongs{
    
private:
    
    songs *arrhasing[50];//50*50=2500 songs max
    int hashing_index=-1;//incremented aftre no%50
    songs *listhead,*listtail;
    int no;
    
public:
    listofsongs(){
        for(int i=0;i<50;i++){
            arrhasing[i]=NULL;
        }
        no=1;
        listhead=NULL;
        listtail=NULL;
    }
    
    void storeinhashtable(songs *t){
        int getindex=no/50;
        arrhasing[getindex]=t;
        cout<<"Index value "<<getindex<<" ";
        hashing_index=getindex;
    }
    
    void displayhashtable(){
        for(int i=0;i<=hashing_index;i++){
            cout<< *arrhasing[i]->name<<" "<< arrhasing[i]->no <<" "<<endl;
        }
    }
    
    void push(char *name){
        int l=(int)strlen(name);
        songs *t=new songs;
        if((no-1)%50==0)storeinhashtable(t);
        t->name=new char[l];
        t->no=no;
        t->name=name;
        t->next=NULL;
        if(listtail==NULL){
            t->pre=NULL;
            listtail=t;
            listhead=t;
        }else{
            listtail->next=t;
            t->pre=listtail;
            listtail=t;
        }
        no++;
    }
    songs *getaddress(int number){  //retreives the address of the required song
        if(number<0)return NULL;
        int flag=0;
        songs *tt=listtail,*hh=listhead;
        int max=tt->no,min=hh->no;
        
        if(number==max){
            return listtail;
        }
        if(number==min){
            return listhead;
        }
        
        if((number-1)%50==0){
            for(int i=0;i<hashing_index && flag==0;i++){
                if(arrhasing[i]->no==number){
                    return arrhasing[i];
                }
            }
        }
        
        if((number/50<=hashing_index) &&  arrhasing[number/50]!=NULL) hh=arrhasing[number/50];
        if(((number/50)+1<=hashing_index)&& arrhasing[(number/50)+1]!=NULL) tt=arrhasing[(number/50)+1];
        
        max=tt->no;
        min=hh->no;
        if(flag==0&&abs(number-max)<=abs(number-min)){
            while(tt!=NULL&&tt->no!=number){
                tt=tt->pre;
            }
            
        return tt;
            
            
            
        }else{
            while(hh!=NULL&&hh->no!=number){
                hh=hh->next;
            }
            
            
                return hh;
            
            
        }
        return NULL;
    }
    
    void pangawithhash(int no){  //hash table automatically updated if the song is deleted from the list
        for(int i=0;i<=hashing_index;i++){
            
            if(no==arrhasing[i]->no){
                songs *node =arrhasing[i];
                node =node->next;
                if(node ==NULL){
                    hashing_index--;
                }else{
                    arrhasing[i]=node;
                }
                break;
            }
        }
    }
    
    void notrequired(songs *tobedeleted){
        int number=tobedeleted->no,flag=0;
        if(listtail->no==tobedeleted->no){
            songs *back=listtail->pre;
            listtail=back;
            if(back!=NULL) {listtail->next=NULL;}
            flag=1;
        }
        if(flag==0&&listhead->no==tobedeleted->no){
            songs *agla=tobedeleted->next;
            listhead=agla;
            if(agla!=NULL)agla->pre=NULL;
            flag=1;
        }
        if(flag==0){songs *agla=tobedeleted->next,*back=tobedeleted->pre;
        agla->pre=back;
        back->next=agla;}
        pangawithhash(number); //update for hash table
    }
    
    
    
    void display(){
        songs *head=listhead;
        while(head!=NULL){
            cout<<head->name<<" "<<head->no<<"| ";
            head=head->next;
        }
        cout<<endl;
    }
    void rdisplay(){
        songs *head=listtail;
        while(head!=NULL){
            cout<<head->name<<" "<<head->no<<"| ";
            head=head->pre;
        }
        cout<<endl;
    }

    
};


class playlistofsongs :public  listofsongs{
private:
    playlist *phead,*ptail;
    
public:
    playlistofsongs(){
        phead=ptail=NULL;
    }
    void push(songs *son){
        playlist *t=new playlist;
        t->songdata=new songs;
        t->songdata=son;
        if(ptail==NULL){
            t->nextsong=NULL;
            ptail=t;
            phead=t;
        }
        else{
            t->nextsong=ptail;
            ptail=t;
        }
        
    }
};


class mediaplayer :public  playlistofsongs{
private:
    int mod,repeat;
public:
    mediaplayer(){
        mod=0;
        repeat=0;
    }
    void playmusic(playlist *phead){
        
    }
};
#endif /* Header_h */
