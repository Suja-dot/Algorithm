class ListNode {
    int key;
    int val;
    ListNode next;
    ListNode prev;
    
    public ListNode(int key, int val){
        this.key = key;
        this.val = val;
        this.next = null;
        this.prev = null;
    }
}
class LRUCache {
    private int capacity;
    private Map<Integer,ListNode> nodeMap;
    private ListNode head;
    private ListNode tail;
    
    public void removeNode(ListNode node){
        node.prev.next = node.next;
        node.next.prev = node.prev;
        nodeMap.remove(node.key);
    }
    
    public void insertNode(ListNode node){
        head.next.prev = node;
        node.next = head.next;
        node.prev = head;
        head.next = node;
        nodeMap.put(node.key,node);
    }
    
    public LRUCache(int capacity) {
        nodeMap = new HashMap<>();
        head = new ListNode(-1,-1);
        tail = new ListNode(-1,-1);
        head.next = tail;
        tail.prev = head;
        this.capacity = capacity;
    }
    
    public int get(int key) {
        if(!nodeMap.containsKey(key)){
            return -1;
        }
        ListNode targetNode = nodeMap.get(key);
        removeNode(targetNode);
        insertNode(targetNode);
        return targetNode.val;
    }
    
    public void put(int key, int value) {
        ListNode newNode = new ListNode(key,value);
        if(nodeMap.containsKey(key)){
            ListNode oldNode = nodeMap.get(key);
            removeNode(oldNode);
        }else{
            if(nodeMap.size()>=capacity){
                ListNode tailNode = tail.prev;
                removeNode(tailNode);
            }
        }
        insertNode(newNode);
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
