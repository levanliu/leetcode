//
// Created by le on 2/11/2022.
//

#ifndef LANGUAGEBASIC_SINGLELINKEDLIST_H
#define LANGUAGEBASIC_SINGLELINKEDLIST_H


class SingleLinkedList {


public:
    static const int N=1e5+10;
    int e[N],ne[N],cur=1,head,idx;
    void init(){
        head = -1;
        idx = 0;
    }

    //idx = 0
    void add_head(int x){
        e[idx] = x;
        ne[idx] = head;
        head = idx;
        idx++;
    }

    void add_k(int k,int x){
        e[cur] = x;
        ne[cur] = ne[k];
        ne[k] = cur;
        cur++;
    }

    //del index = k point.
    void del_k(int k,int x){
        ne[k] = ne[ne[k]];
    }



};


#endif //LANGUAGEBASIC_SINGLELINKEDLIST_H
