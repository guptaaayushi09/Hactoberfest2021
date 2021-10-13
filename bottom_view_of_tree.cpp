class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> v;
        if(!root) return v;
        map<int,int>m;
        queue<pair<Node*,int>>q;
        q.push(make_pair(root,0));
        while(!q.empty()){
            pair<Node*,int>p=q.front();
            q.pop();
            Node *temp=p.first;
            int hd=p.second;
           // if(!(m.find(hd)!=m.end())) 
           {m[hd]=temp->data;
           // v.push_back(temp->data);
            }
            if(temp->left) q.push(make_pair(temp->left,hd-1));
            if(temp->right) q.push(make_pair(temp->right,hd+1));
        }
       for(auto i=m.begin();i!=m.end();i++)
        {
            v.push_back(i->second);
        }
        return v;
    }
};
