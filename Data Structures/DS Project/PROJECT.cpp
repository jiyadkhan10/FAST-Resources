#include <iostream>
#include<fstream>
#include<cstdlib>
#include <iomanip>
#include<string>
#include<cstring>
#include<cctype>
using namespace std;

class linked_list;

//LINK LIST FOR LINKED LISTS
struct LINK_LIST_NODE
{
    LINK_LIST_NODE* next;
    linked_list* data;
};
class linkListOfLinkedLists
{
public:
    LINK_LIST_NODE* head, * tail, * temp;
public:
    linkListOfLinkedLists()
    {
        head = NULL;
        tail = NULL;
    }
    linkListOfLinkedLists* unique()
    {
        linkListOfLinkedLists* tmp;
        tmp = new linkListOfLinkedLists;
        linkListOfLinkedLists* newarr;
        newarr = new linkListOfLinkedLists;
        tmp->head = head;
    }
    void add_node(LINK_LIST_NODE* tmp)
    {
        if (head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }
};



//CLASS FOR QUEUE
// A class to store a queue
class queue
{
public:
    int* arr;       // array to store queue elements
    int capacity;   // maximum capacity of the queue
    int front;      // front points to the front element in the queue (if any)
    int rear;       // rear points to the last element in the queue
    int count;      // current size of the queue


    queue(int size);     // constructor
    ~queue();                   // destructor

    int dequeue();
    void enqueue(int x);
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
};

// Constructor to initialize a queue
queue::queue(int size)
{
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

// Destructor to free memory allocated to the queue
queue::~queue() {
    delete[] arr;
}

// Utility function to dequeue the front element
int queue::dequeue()
{
    // check for queue underflow
    if (isEmpty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    //cout << "Removing " << arr[front] << endl;
    int val = arr[front];
    front = (front + 1) % capacity;
    count--;
    return val;
}

// Utility function to add an item to the queue
void queue::enqueue(int item)
{
    // check for queue overflow
    if (isFull())
    {
        cout << "Overflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    // cout << "Inserting " << item << endl;

    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
}

// Utility function to return the front element of the queue
int queue::peek()
{
    if (isEmpty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    return arr[front];
}

// Utility function to return the size of the queue
int queue::size() {
    return count;
}

// Utility function to check if the queue is empty or not
bool queue::isEmpty() {
    return (size() == 0);
}

// Utility function to check if the queue is full or not
bool queue::isFull() {
    return (size() == capacity);
}
//LINK LIST CLASS FOR ADJACENCY LIST
struct node
{
    int data;
    node* next;
};
class linked_list
{
private:
    node* head, * tail;
public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }
    void distruction()
    {
        head = NULL;
        tail = NULL;
    }
    int return_data(int number)
    {
        if (head == NULL)
        {
            return 0;
        }
        node* tmp = head;
        for (int i = 0; i < number; ++i)
        {
            tmp = tmp->next;
        }
        return tmp->data;
    }
    void sorting()
    {
        int swapped, i;
        node* ptr1;

        /* Checking for empty list */
        if (head == NULL)
            return;

        do
        {
            swapped = 0;
            ptr1 = head;

            while (ptr1->next != NULL)
            {
                if (ptr1->data > ptr1->next->data)
                {
                    swap(ptr1->data, ptr1->next->data);
                    swapped = 1;
                }
                ptr1 = ptr1->next;
            }
        } while (swapped);
    }
    void add_node(int n)
    {
        node* tmp = new node;
        tmp->data = n;
        tmp->next = NULL;
        if (head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }
    void display()
    {
        if (head == NULL)
        {
            cout << "THE LIST IS EMPTY";
        }
        else
        {
            node* tmp = head;
            while (tmp->next != NULL)
            {
                cout << tmp->data << ",";
                tmp = tmp->next;
            }
            cout << tmp->data << ",";
            tmp = tmp->next;
            cout << endl;
        }
    }
    bool search(int d)
    {
        if (head == NULL)
        {
            return 0;
        }
        else
        {
            node* tmp = head;
            while (tmp->next != NULL)
            {
                if (tmp->data == d)
                {
                    return 1;
                }
                tmp = tmp->next;
            }
            if (tmp->data == d)
            {
                return 1;
            }
        }
        return 0;
    }
    bool is_empty()
    {
        if (head == NULL)
        {
            return 1;
        }
        return 0;
    }
    int length()
    {
        int length = 1;
        if (head == NULL)
        {
            return 0;
        }
        else
        {
            node* tmp = head;
            while (tmp->next != NULL)
            {
                length++;
                tmp = tmp->next;
            }
        }
        return length;
    }
};
//Class for graph
struct graph_node
{
    int number;
    int data;
    graph_node* next;
    linked_list adj_list;
};

class Graph
{
private:
    graph_node* head, * tail;
public:
    Graph()
    {
        head = NULL;
        tail = NULL;
    }
    int CheckIsolatedNode()
    {
        int isolated_nodes = 0;
        int check = 0;
        graph_node* tmp = head;
        while (tmp->next != NULL)
        {
            if (tmp->adj_list.is_empty())
            {
                graph_node* tmp1 = head;
                while (tmp1->next != NULL)
                {
                    if (tmp1->adj_list.search(tmp->data) == 1)
                    {
                        check = 1;
                    }
                    tmp1 = tmp1->next;
                }
                if (tmp1->adj_list.search(tmp->data) == 1)
                {
                    check = 1;
                }
                if (check == 0)
                {
                    isolated_nodes++;
                }
            }
            tmp = tmp->next;
        }
        return isolated_nodes;
    }
    int CheckSinkNode()
    {
        int sink_nodes = 0;
        graph_node* tmp = head;
        while (tmp->next != NULL)
        {
            if (tmp->adj_list.is_empty() == 1)
            {
                sink_nodes++;
            }
            tmp = tmp->next;
        }
        if (tmp->adj_list.is_empty() == 1)
        {
            sink_nodes++;
        }
        return sink_nodes;
    }
    void outDegree()
    {
        graph_node* tmp = head;
        cout << "DATA      OUTDEGREE" << endl;
        while (tmp->next != NULL)
        {
            cout << "__" << endl;
            cout << tmp->data;
            cout << "            " << tmp->adj_list.length() << endl;
            tmp = tmp->next;
        }
        cout << "__" << endl;
        cout << tmp->data;
        cout << "            " << tmp->adj_list.length() << endl;
    }
    void inDegree()
    {
        int val = 0;
        graph_node* tmp = head;
        cout << "DATA      INDEGREE" << endl;
        while (tmp->next != NULL)
        {
            if (1)
            {
                graph_node* tmp1 = head;
                while (tmp1->next != NULL)
                {
                    if (tmp1->adj_list.search(tmp->data) == 1)
                    {
                        val++;
                    }
                    tmp1 = tmp1->next;
                }
                if (tmp1->adj_list.search(tmp->data) == 1)
                {
                    val++;
                }
                cout << tmp->data;
                cout << "         " << val << endl;
                tmp = tmp->next;
                val = 0;
            }
        }
        if (1)
        {
            graph_node* tmp1 = head;
            while (tmp1->next != NULL)
            {
                if (tmp1->adj_list.search(tmp->data) == 1)
                {
                    val++;
                }
                tmp1 = tmp1->next;
            }
            if (tmp1->adj_list.search(tmp->data) == 1)
            {
                val++;
            }
            cout << tmp->data;
            cout << "         " << val << endl;
            tmp = tmp->next;
            val = 0;
        }
    }
    void AddNode(int node_data)
    {
        graph_node* tmp = new graph_node;
        tmp->data = node_data;
        tmp->next = NULL;
        if (head == NULL)
        {
            tmp->number = 1;
            head = tmp;
            tail = tmp;
        }
        else
        {
            int n = tail->number;
            n++;;
            tmp->number = n;
            tail->next = tmp;
            tail = tail->next;
        }
    }
    void AddEdge(int source, int dest) {
        graph_node* tmp = head;
        while (tmp->data != source)
        {
            tmp = tmp->next;
        }
        tmp->adj_list.add_node(dest);
    }
    int return_number(int source)
    {
        graph_node* tmp = head;
        while (tmp->data != source)
        {
            tmp = tmp->next;
        }
        return tmp->number;
    }
    void display()
    {
        if (head == NULL)
        {
            cout << "GRAPH IS EMPTY" << endl;
        }
        else
        {
            graph_node* tmp = head;
            while (tmp->next != NULL)
            {
                cout << "THIS IS THE NODE DATA" << tmp->data << endl;
                tmp->adj_list.display();
                tmp = tmp->next;
            }
            cout << "THIS IS THE NODE DATA" << tmp->data << endl;
            tmp->adj_list.display();
        }
    }

    //SHORTEST PATH BETWEEN TWO NODES
    void shortest_path(int data, int dest, int no_of_nodes) {
        int* reachable;
        linked_list* my_reachable;
        my_reachable = new linked_list;
        reachable = new int[no_of_nodes];
        for (int i = 0; i < no_of_nodes; ++i)
        {
            reachable[i] = 0;
        }
        queue my_q(no_of_nodes);
        my_q.enqueue(data);
        reachable[data] = 1;
        my_reachable->add_node(data);
        while (!my_q.isEmpty())
        {
            int v = 0;
            v = my_q.dequeue();
            cout << v << "->";
            if (v == dest)
            {
                return;
            }
            //cout << v << " ";
            graph_node* tmp = head;
            while (tmp->next != NULL)
            {
                if (tmp->adj_list.search(dest) == 1)
                    return;
                if (tmp->data == v)
                {
                    for (int k = 0; k < tmp->adj_list.length(); ++k)
                    {
                        if (reachable[tmp->adj_list.return_data(k)] == 0)
                        {
                            reachable[tmp->adj_list.return_data(k)] = 1;
                            my_q.enqueue(tmp->adj_list.return_data(k));
                            my_reachable->add_node(tmp->adj_list.return_data(k));
                        }
                    }
                    break;
                }
                else
                {
                    tmp = tmp->next;
                }
            }
        }
    }
    //BFS ALGORITHM
    linked_list* bfs(int data, int no_of_nodes) {
        int* reachable;
        linked_list* my_reachable;
        my_reachable = new linked_list;
        reachable = new int[no_of_nodes];
        for (int i = 0; i < no_of_nodes; ++i)
        {
            reachable[i] = 0;
        }
        queue my_q(no_of_nodes);
        my_q.enqueue(data);
        reachable[data] = 1;
        my_reachable->add_node(data);
        while (!my_q.isEmpty())
        {
            int v = 0;
            v = my_q.dequeue();
            //cout << v << " ";
            graph_node* tmp = head;
            while (tmp->next != NULL)
            {
                if (tmp->data == v)
                {
                    for (int k = 0; k < tmp->adj_list.length(); ++k)
                    {
                        if (reachable[tmp->adj_list.return_data(k)] == 0)
                        {
                            reachable[tmp->adj_list.return_data(k)] = 1;
                            my_q.enqueue(tmp->adj_list.return_data(k));
                            my_reachable->add_node(tmp->adj_list.return_data(k));
                        }
                    }
                    break;
                }
                else
                {
                    tmp = tmp->next;
                }

            }
        }
        return my_reachable;
    }


    //FOR OUT ALGORITHM
    linked_list* OUT(int data, int no_of_nodes)
    {
        linked_list* out;
        out = new linked_list;
        out = bfs(data, no_of_nodes);
        return out;
    }

    //FOR IN ALGORITHM
    linked_list* IN(int data, int no_of_nodes)
    {
        linked_list* in;
        int i = 0;
        in = new linked_list;
        linked_list* temp;
        temp = new linked_list;
        graph_node* tmp = head;
        while (tmp->next != NULL)
        {
            temp = bfs(tmp->data, no_of_nodes);
            if (temp->search(data) == 1)
            {
                in->add_node(tmp->data);
            }
            tmp = tmp->next;
            temp->distruction();
        }
        temp = bfs(tmp->data, no_of_nodes);
        if (temp->search(data) == 1)
        {
            in->add_node(tmp->data);
        }
        return in;
    }


    //FOR WCC ALGORITHM
    linkListOfLinkedLists* WCC(int no_of_nodes)
    {
        LINK_LIST_NODE* obj;
        obj = new LINK_LIST_NODE;
        obj->next = NULL;
        linkListOfLinkedLists* my_list;
        my_list = new linkListOfLinkedLists;
        int j = 0;
        graph_node* tmp = head;
        int length = -1;
        while (tmp->next != NULL)
        {
            obj->data = bfs(tmp->data, no_of_nodes);
            obj->data->sorting();
            if (length != obj->data->length())
            {
                my_list->add_node(obj);
                length = obj->data->length();
                cout << j++ << "  ";
            }
            tmp = tmp->next;
        }
        int lar = 0;
        linkListOfLinkedLists* tmp4;
        tmp4 = new linkListOfLinkedLists;
        tmp4 = my_list;
        while (tmp4->head != tmp4->tail)
        {
            if (tmp4->head->data->length() > lar)
                lar = tmp4->head->data->length();
            tmp4->head = tmp4->head->next;
        }
        linkListOfLinkedLists* tmp5;
        tmp5 = new linkListOfLinkedLists;
        tmp5 = my_list;
        while (tmp5->head != tmp5->tail)
        {
            if (tmp5->head->data->length() == lar)
                tmp5->head->data->display();
        }
        cout << "THE LARGEST WCC IS OF LENGTH " << lar << endl;
        cout << "THE NUMBER OF WCC ARE " << j << endl;
        return my_list;
    }



    linkListOfLinkedLists* SCC(int no_of_nodes)
    {
        LINK_LIST_NODE* obj;
        obj = new LINK_LIST_NODE;
        obj->next = NULL;
        linkListOfLinkedLists* my_list;
        my_list = new linkListOfLinkedLists;
        int j = 0;
        graph_node* tmp = head;
        int length = -1;
        while (tmp->next != NULL)
        {
            obj->data = bfs(tmp->data, no_of_nodes);
            obj->data->sorting();
            if (length != obj->data->length())
            {
                my_list->add_node(obj);
                length = obj->data->length();
            }
            cout << j++;
            tmp = tmp->next;
        }
        int lar = 0;
        linkListOfLinkedLists* tmp4;
        tmp4 = new linkListOfLinkedLists;
        tmp4 = my_list;
        while (tmp4->head != tmp4->tail)
        {
            if (tmp4->head->data->length() > lar)
                lar = tmp4->head->data->length();
            tmp4->head = tmp4->head->next;
        }
        linkListOfLinkedLists* tmp5;
        tmp5 = new linkListOfLinkedLists;
        tmp5 = my_list;
        while (tmp5->head != tmp5->tail)
        {
            if (tmp5->head->data->length() == lar)
                tmp5->head->data->display();
        }
        cout << "THE LARGEST SCC IS OF LENGTH " << lar << endl;
        cout << "THE NUMBER OF SCC ARE " << j << endl;
        return my_list;
    }
};

int main()
{
    int numOfNodes = 0;
    int numOfEdges = 0;
    int numOfSourceNodes = 0;
    int largest = 0;
    ifstream myfile;
    Graph my_graph;
    int** adj_matrix;
    myfile.open("../PROJECT/Text.txt");
    if (myfile.is_open())
    {
        string line = "";
        string temp = "";
        string temp1 = "";
        int num = 0;

        while (getline(myfile, line))
        {
            numOfEdges++;
            for (int z = 0; z < line.length() - 1; ++z)
            {
                if (line[z] == ' ' && line[z + 1] != ' ')
                {
                    numOfSourceNodes++;
                }
            }
            for (int i = 0; i < line.length(); ++i)
            {
                int c = line[i];
                if (isspace(c))
                {
                    if (temp != temp1)
                    {
                        numOfNodes++;
                        int var = stoi(temp);
                        my_graph.AddNode(var);
                        temp1 = temp;
                    }
                    break;
                }

                temp = temp + line[i];
            }
            temp = "";
        }
    }
    adj_matrix = new int* [numOfNodes];
    for (int i = 0; i < numOfNodes; ++i)
    {
        adj_matrix[i] = new int[numOfNodes];
    }
    for (int i = 0; i < numOfNodes; ++i)
    {
        for (int k = 0; k < numOfNodes; ++k)
        {
            adj_matrix[i][k] = 0;
        }
    }
    int totalVertices = numOfNodes;
    ifstream file;
    file.open("text.txt");
    if (file.is_open())
    {
        string line = "";
        string temp = "";
        string temp1 = "";
        int num = 0;
        int check = 0;
        while (getline(file, line))
        {
            numOfEdges++;
            for (int i = 0; i < line.length(); ++i)
            {
                if (check == 0)
                {
                    int c = line[i];
                    if (!isspace(c))
                    {
                        temp = temp + line[i];
                    }
                    else
                    {
                        check = 2;
                    }
                }
                if (check == 2)
                {
                    int c = line[i];
                    if (!isspace(c))
                    {
                        temp1 = temp1 + line[i];
                    }
                }
            }
            int t = stoi(temp);
            int t1 = stoi(temp1);
            int n1 = 0;
            int n2 = 0;
            n1 = my_graph.return_number(t);
            n2 = my_graph.return_number(t1);
            //cout << "N1 " << n1;
            //cout << "N2 " << n2 << endl;
            adj_matrix[n1 - 1][n2 - 1] = 1;
            if (t > largest)
                largest = t;
            my_graph.AddEdge(t, t1);
            temp = "";
            temp1 = "";
            check = 0;
        }
    }
    int inp, opt;
    cout << "\n\n\n*** WELCOME TO HOME PAGE OF OUR PROJECT ***\n\n\n";
    cout << "Please Press 1 to proceed to our menu\nPress any other integer to exit the program" << endl;
    cin >> opt;
    if (opt == 1)
    {
        cout << "\n\n\n*** WELCOME TO THE MENU OF OUR PROJECT ***\n\n\n";
        cout << "Press 1 to run all tasks at once\nPress 2 to Display number of nodes\nPress 3 to Display number of edges\nPress 4 to Display number of source nodes\nPress 5 to Display number of sink nodes\nPress 6 to Display number of isolated nodes\nPress 7 to Display out degree of the graph\nPress 8 to Display in degree of the graph\nPress 9 to Display BFS of the graph\nPress 10 to Display shortest path between the nodes\nPress 11 to Display wcc of the graph\nPress 12 to Display scc of the graph\n";
        cout << "Enter input:" << endl;
        cin >> inp;
        while (1)
        {

            if (inp == 1) {
                cout << " No of Nodes " << numOfNodes << endl;
                cout << " No of Edges " << numOfEdges << endl;
                cout << " No of Source Nodes " << numOfSourceNodes << endl;
                cout << "NUMBER OF SINK NODES IN GRAPH " << my_graph.CheckSinkNode() << endl;
                cout << "NUMBER OF ISOLATED NODES IN GRAPH " << my_graph.CheckIsolatedNode() << endl;
                my_graph.outDegree();
                my_graph.inDegree();
                cout << "BFS in GRAPH " << my_graph.bfs(3466, largest) << endl;
                my_graph.shortest_path(3466, 4135, largest);
                cout << "NUMBER OF WCC's IN GRAPH " << my_graph.WCC(largest);
                break;
            }
            if (inp == 2) {
                cout << " No of Nodes " << numOfNodes << endl;
                break;
            }
            if (inp == 3) {
                cout << " No of Edges " << numOfEdges << endl;
                break;
            }
            if (inp == 4) {
                cout << " No of Source Nodes " << numOfSourceNodes << endl;
                break;
            }
            if (inp == 5) {
                cout << "NUMBER OF SINK NODES IN GRAPH " << my_graph.CheckSinkNode() << endl;
                break;
            }
            if (inp == 6) {
                cout << "NUMBER OF ISOLATED NODES IN GRAPH " << my_graph.CheckIsolatedNode() << endl;
                break;
            }
            if (inp == 7) {
                my_graph.outDegree();
                break;
            }
            if (inp == 8) {
                my_graph.inDegree();
                break;
            }
            if (inp == 9) {
                cout << "BFS in GRAPH " << my_graph.bfs(3466, largest) << endl;
                break;
            }
            if (inp == 10) {
                my_graph.shortest_path(3466, 4135, largest);
                break;
            }
            if (inp == 11) {
                cout << "NUMBER OF WCC's IN GRAPH " << my_graph.WCC(largest);
                break;
            }
            if (inp == 12) {
                cout << "NUMBER OF SCC's IN GRAPH " << my_graph.SCC(largest);
                break;
            }
        }
    }
    else
    {
        cout << "Program is terminating!" << endl;
        exit(1);
    }
    return 0;
}