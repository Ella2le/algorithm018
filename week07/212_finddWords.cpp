//
// Created by lewang on 12/6/20.
//
//----------------stander bfs--------------
class Solution {
private:
    unordered_set<string> wordList;
    vector<vector<string>> ans;
    unordered_set<string> visited;

    int level = 1;
    int minLevel = INT_MAX;

public:
    vector<vector<string>> findLadders(string beginWord, string endWord,vector<string> &words ) {

        //Putting all words in a set
        for(auto word: words)
            wordList.insert(word);
        //wordList.insert(endWord); Cant insert endWord now

        //Queue of Paths
        queue<vector<string>> q;
        q.push({beginWord});


        while (!q.empty())
        {
            vector<string> path = q.front(); q.pop();

            if (path.size() > level)
            {
                //reach a new level
                for (string w : visited)
                    wordList.erase(w);

                //visited.clear();
                if (path.size() > minLevel)
                    break;
                else
                    level = path.size();
            }


            string lastWord = path.back();

            addNeighboursToQ(lastWord,path,q,endWord);
        }

        return ans;
    }

    void addNeighboursToQ(string curr,vector<string> path,queue<vector<string>> &q,const string &endWord)
    {
        for(int i=0;i<curr.size();i++)
        {
            char originalChar = curr[i];

            for(int j=0;j<26;j++)
            {
                curr[i] = j + 'a';

                if(wordList.find(curr)!=wordList.end())
                {
                    //cout<<curr<<"   added"<<endl;
                    vector<string> newpath = path;
                    newpath.push_back(curr);

                    visited.insert(curr);


                    if (curr == endWord) {
                        minLevel = level;
                        ans.push_back(newpath);
                    }
                    else
                        q.push(newpath);

                }
            }

            curr[i] = originalChar;
        }//i
    }
};
//------------------ends-----------------

//------------two-end bfs------------------
class Solution {
public:
    std::vector<std::vector<std::string> > findLadders(std::string beginWord, std::string endWord, std::unordered_set<std::string> &dict) {
        std::vector<std::vector<std::string> > paths;
        std::vector<std::string> path(1, beginWord);
        if (beginWord == endWord) {
            paths.push_back(path);
            return paths;
        }
        std::unordered_set<std::string> words1, words2;
        words1.insert(beginWord);
        words2.insert(endWord);
        std::unordered_map<std::string, std::vector<std::string> > nexts;
        bool words1IsBegin = false;
        if (findLaddersHelper(words1, words2, dict, nexts, words1IsBegin))
            getPath(beginWord, endWord, nexts, path, paths);
        return paths;
    }
private:
    bool findLaddersHelper(
            std::unordered_set<std::string> &words1,
            std::unordered_set<std::string> &words2,
            std::unordered_set<std::string> &dict,
            std::unordered_map<std::string, std::vector<std::string> > &nexts,
            bool &words1IsBegin) {
        words1IsBegin = !words1IsBegin;
        if (words1.empty())
            return false;
        if (words1.size() > words2.size())
            return findLaddersHelper(words2, words1, dict, nexts, words1IsBegin);
        for (auto it = words1.begin(); it != words1.end(); ++it)
            dict.erase(*it);
        for (auto it = words2.begin(); it != words2.end(); ++it)
            dict.erase(*it);
        std::unordered_set<std::string> words3;
        bool reach = false;
        for (auto it = words1.begin(); it != words1.end(); ++it) {
            std::string word = *it;
            for (auto ch = word.begin(); ch != word.end(); ++ch) {
                char tmp = *ch;
                for (*ch = 'a'; *ch <= 'z'; ++(*ch))
                    if (*ch != tmp)
                        if (words2.find(word) != words2.end()) {
                            reach = true;
                            words1IsBegin ? nexts[*it].push_back(word) : nexts[word].push_back(*it);
                        }
                        else if (!reach && dict.find(word) != dict.end()) {
                            words3.insert(word);
                            words1IsBegin ? nexts[*it].push_back(word) : nexts[word].push_back(*it);
                        }
                *ch = tmp;
            }
        }
        return reach || findLaddersHelper(words2, words3, dict, nexts, words1IsBegin);
    }
    void getPath(
            std::string beginWord,
            std::string &endWord,
            std::unordered_map<std::string, std::vector<std::string> > &nexts,
            std::vector<std::string> &path,
            std::vector<std::vector<std::string> > &paths) {
        if (beginWord == endWord)
            paths.push_back(path);
        else
            for (auto it = nexts[beginWord].begin(); it != nexts[beginWord].end(); ++it) {
                path.push_back(*it);
                getPath(*it, endWord, nexts, path, paths);
                path.pop_back();
            }
    }
};
//---------------------end------------------

//------------trie------------------
class Node;

typedef vector<string> Ladder;
typedef unordered_set<string> StringSet;
typedef bool (*NodeCmper) (Node*, Node*);
typedef set<Node*, NodeCmper> NodeSet;

class Node
{
public:
    string word;
    vector<Node*> parents;

    Node(string w) : word(w) {}
    void addparent(Node* parent) { parents.push_back(parent); }

    // Yield all children of this node, and:
    //   1) If the child is found in $targetlayer, which means we found ladders that
    //      connect BEGIN-WORD and END-WORD, then we get all paths through this node
    //      to its ROOT node, and all paths through the target child node to its ROOT
    //      node, and combine the two group of paths to a group of ladders, and append
    //      these ladders to $ladders.
    //   2) Elif the $ladders is empty:
    //       2.1) If the child is found in $nextlayer, then get that child, and add
    //            this node to its parents.
    //       2.2) Else, add the child to nextlayer, and add this node to its parents.
    //   3) Else, do nothing.
    void yieldchildren(NodeSet& nextlayer, StringSet& wordlist, NodeSet& targetlayer,
                       vector<Ladder>& ladders, bool forward)
    {
        string nextword = word;
        for (int i = 0, n = nextword.length(); i < n; i++) {
            char oldchar = nextword[i];
            for (nextword[i] = 'a'; nextword[i] <= 'z'; nextword[i]++) {
                if (wordlist.count(nextword)) {
                    // now we found a valid child-word, let's yield a child.
                    Node* child = new Node(nextword);
                    yield1(child, nextlayer, targetlayer, ladders, forward);
                }
            }
            nextword[i] = oldchar;
        }
    }

    // yield one child, see comment of function `yieldchildren`
    void yield1(Node* child, NodeSet& nextlayer, NodeSet& targetlayer,
                vector<Ladder>& ladders, bool forward) {
        auto itr = targetlayer.find(child);
        if (itr != targetlayer.end()) {
            for (Ladder path1 : this->getpaths()) {
                for (Ladder path2 : (*itr)->getpaths()) {
                    if (forward) {
                        ladders.push_back(path1);
                        ladders.back().insert(ladders.back().end(), path2.rbegin(), path2.rend());
                    } else {
                        ladders.push_back(path2);
                        ladders.back().insert(ladders.back().end(), path1.rbegin(), path1.rend());
                    }
                }
            }
        } else if (ladders.empty()) {
            auto itr = nextlayer.find(child);
            if (itr != nextlayer.end()) {
                (*itr)->addparent(this);
            } else {
                child->addparent(this);
                nextlayer.insert(child);
            }
        }
    }

    vector<Ladder> getpaths()
    {
        vector<Ladder> ladders;
        if (parents.empty()) {
            ladders.push_back(Ladder(1, word));
        } else {
            for (Node* parent : parents) {
                for (Ladder ladder : parent->getpaths()) {
                    ladders.push_back(ladder);
                    ladders.back().push_back(word);
                }
            }
        }
        return ladders;
    }
};

bool nodecmp(Node* pa, Node* pb)
{
    return pa->word < pb->word;
}

class Solution {
public:
    vector<Ladder> findLadders(string begin, string end, StringSet& wordlist) {
        vector<Ladder> ladders;
        Node headroot(begin), tailroot(end);
        NodeSet frontlayer(nodecmp), backlayer(nodecmp);
        NodeSet *ptr_layerA = &frontlayer, *ptr_layerB = &backlayer;
        bool forward = true;

        if (begin == end) {
            ladders.push_back(Ladder(1, begin));
            return ladders;
        }

        frontlayer.insert(&headroot);
        backlayer.insert(&tailroot);
        wordlist.insert(end);
        while (!ptr_layerA->empty() && !ptr_layerB->empty() && ladders.empty()) {
            NodeSet nextlayer(nodecmp);
            if (ptr_layerA->size() > ptr_layerB->size()) {
                swap(ptr_layerA, ptr_layerB);
                forward = ! forward;
            }
            for (Node* node : *ptr_layerA) {
                wordlist.erase(node->word);
            }
            for (Node* node : *ptr_layerA) {
                node->yieldchildren(nextlayer, wordlist, *ptr_layerB, ladders, forward);
            }
            swap(*ptr_layerA, nextlayer);
        }

        return ladders;
    }
};



