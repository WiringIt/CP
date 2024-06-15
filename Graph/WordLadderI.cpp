#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int wordLadderLength(string startWord, string targetWord, vector<string>& wordList)
{
    //storing the words in a set ds
    unordered_set<string>st(wordList.begin(),wordList.end());
    queue<pair<string,int>>q;
    q.push({startWord,1});
    while(!q.empty())
    {
        string word_now=q.front().first;
        int seq_len=q.front().second;
        if(word_now==targetWord) return seq_len;
        q.pop();
        for(int i=0;i<word_now.size();i++)
        {
            char ch=word_now[i];
            for(int j=0;j<26;j++)
            {
                word_now[i]='a'+j;
                if(word_list.find(word_now)!=word_list.end())
                {
                q.push({word_now,seq_len+1});
                st.erase(word_now);
                }
            }
            word_now[i]=ch;
        }
    }
    return 0;
}