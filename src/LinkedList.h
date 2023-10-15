class LinkedList {
    public:
        LinkedList();
        ~LinkedList();
        void add(int value);
        void remove(int value);
        int getSingleNode(int value);
        void print();
    private:
        struct Node {
            int value;
            Node *next;
        };
        Node *head;
};
