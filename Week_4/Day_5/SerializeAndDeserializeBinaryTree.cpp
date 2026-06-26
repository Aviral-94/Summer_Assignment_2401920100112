class Codec {
public:

    void serializeHelper(TreeNode* root, string &s)
    {
        if(root == NULL)
        {
            s += "N,";
            return;
        }

        s += to_string(root->val) + ",";
        serializeHelper(root->left, s);
        serializeHelper(root->right, s);
    }

    string serialize(TreeNode* root)
    {
        string s;
        serializeHelper(root, s);
        return s;
    }

    TreeNode* deserializeHelper(vector<string>& nodes, int &i)
    {
        if(nodes[i] == "N")
        {
            i++;
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(nodes[i++]));

        root->left = deserializeHelper(nodes, i);
        root->right = deserializeHelper(nodes, i);

        return root;
    }

    TreeNode* deserialize(string data)
    {
        vector<string> nodes;
        string temp;

        for(char c : data)
        {
            if(c == ',')
            {
                nodes.push_back(temp);
                temp.clear();
            }
            else
            {
                temp += c;
            }
        }

        int i = 0;
        return deserializeHelper(nodes, i);
    }
};