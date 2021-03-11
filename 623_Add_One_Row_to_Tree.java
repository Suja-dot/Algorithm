/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int v, d;
    TreeNode ans;
    public void reAssignNode(TreeNode root){
        //check null pointer
        TreeNode newLeftNode = new TreeNode(this.v,root.left,null); // new left Node
        TreeNode newRightNode = new TreeNode(this.v,null,root.right); // new right Node
        root.left = newLeftNode;
        root.right = newRightNode;
    }
    
    public void findRootNode(TreeNode root,int curDepth){
        if(this.d == 1){
            TreeNode newRoot = new TreeNode(this.v,root,null);
            this.ans = newRoot;
        }else if(curDepth == this.d-1){
            reAssignNode(root);
        }else{
            if(root.left != null) findRootNode(root.left,curDepth+1);
            if(root.right != null) findRootNode(root.right,curDepth+1);
        }
    }
    
    public void Init(int v, int d, TreeNode root){
        this.v = v;
        this.d = d;
        this.ans = new TreeNode();
        ans = root;
    }
    
    public TreeNode addOneRow(TreeNode root, int v, int d) {
        int curDepth=1;
        TreeNode curNode = new TreeNode();
        Init(v,d,root);
        //1. find all depth root
        findRootNode(root,curDepth);
        //2. resigning address
        //new root->left = new TreeNode
        //new TreeNode->left = previouse left
        //new TreeNode->right = null;
        //new root->right = new TreeNode
        //new TreeNode->left = null;
        //new TreeNode->rigth = previouse right
        return this.ans;
    }
}
