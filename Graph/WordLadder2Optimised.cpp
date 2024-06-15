//https://leetcode.com/problems/word-ladder-ii/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
unordered_map(string,int)mp;//to store the word and its level
string b;//to store the beginning word
vector<vector<string>>ans;
void dfs(string word,vector<string>&seq)
{
    if(word==b)//if the target word has been formed
    {
        reverse(seq.begin(),seq.end());//reverse the sequence, remember we're in recursion=>we need to reverse the order
        ans.push_back(seq);//push back the sequence to answer(vector of vector of strings)
        reverse(seq.begin(),seq.end());//again reverse it since we need the original sequence to pop the last word and form a new 
        //valid sequence
        return;
    }
    int steps=mp[word];//stores the level of the current word
    for(int i=0;i<sz;i++)
    {
       char original=word[i];
       for(char ch='a';ch<='z';ch++)
       {
        word[i]=ch;
        if(mp.find(word)!=mp.end() && mp[word]+1==steps)
        {
            seq.push_back(word);
            dfs(word,seq);
            seq.pop_back();
        }
       }
       word[i]=original;
    }
}
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
{
    //First use the concept we used in WordLadder1 problem
    unordered_set<string>st(wordList.begin(),wordList.end());
    queue<string>q;
    b=beginWord;
    q.push({beginWord});
    mp[beginWord]=1;//stores the level of the first word
    int sz=beginWord.size();
    st.erase(beginWord);//erase it off from the set of words
    while(!q.empty())
    {
        string word=q.front();//take out the first word
        int steps=mp[word];//store its level
        q.pop();//pop it off from queue
        for(int i=0;i<sz;i++)
        {
            char original=word[i];
            for(char ch='a';ch<='z';ch++)
            {
                word[i]=ch;
                if(st.count(word))
                {
                    q.push(word);
                    st.erase(word);
                    mp[word]=steps+1;
                }
            }
            word[i]=original;
        }
    }
    if(mp.find(endWord)!=mp.end())//if endWord is formed
    {
      vector<string>seq;//store the sequence
      seq.push_back(endWord);
      dfs(endWord,seq);
    }
}