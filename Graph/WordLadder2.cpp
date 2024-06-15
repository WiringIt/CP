#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList)
{
    unordered_set<string>st(wordList.begin(),wordList.end());
    queue<vector<string>>q;//queue stores a list of strings
    q.push({beginWord});//the first entry into the queue is the starting word
    vector<string> usedOnlevel;//stores a list of words at a particular level
    usedOnlevel.push_back(beginWord);//1st level contains initial word
    int level=0;//initialise level to 0, since we're outside queue now
    vector<vector<string>>ans;//We'll store our answer here, it'a a list of list of strings
    while(!q.empty())
    {
        vector<string>vec=q.front();
        q.pop(); 
        if(vec.size()>level) 
        {
            level++;
        //erase all the words that has already been use at a particular level
           for(auto it: usedOnlevel)
           st.erase(it);
        }
        //we need to change and check just the last word used on this current level
        string word=vec.back();
        if(word==endWord)
        {
            if(ans.size()==0) ans.push_back(vec);
            else if(ans[0].size()==vec.size()) ans.push_back(vec);
        }
        for(int i=0;i<word.size();i++)
        {
            char original=word[i];
            for(char c='a';c<='z';c++)
            {
                word[i]=c;//say "bat"
                if(st.find(word)!=st.end())
                {
                    vec.push_back(word);//say "bat,pat"
                    q.push(vec);//push this sequence into the queue
                    usedOnlevel.push_back(word);//TO MARK THAT THE WORD HAS BEEN USED ON THIS PARTICULAR LEVEL 
                    vec.pop_back();//you need to pop "pat" from "bat,pat"...since next time, 
                    //another word "bot" will get joined with bat="bat,bot"..so you need to delete
                    // the last word after pushing the sequence you made into the queue
                }
                word[i]=original;
            }
        }
    }
    return ans;
}