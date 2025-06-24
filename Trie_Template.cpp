struct Node{
    Node*list[26];
    bool flag=false;
    bool containsKey(char ch){
        return list[ch-'a']!=NULL;
    }
    void put(char ch,Node*node){
        list[ch-'a']=node;
    }
    Node*get(char ch){
       return list[ch-'a'];
    }
    void setEnd(){
        flag=true;
    }
    bool getEnd(){
        return flag;
    }
};
class Trie{
public:
    Node*root;
public:
    Trie(){
        root=new Node();
    }
    void insert(string word){
        Node*node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    bool search(string word){
        Node*node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node=node->get(word[i]);
        }
        return node->getEnd();
    }
};
