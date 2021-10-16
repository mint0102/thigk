#include <iostream>
#include <string>
using namespace std;
class Node{
public:
    int res;
    string data;
    Node* next;
    Node(): next(nullptr){};
    int stringtoint(string s){
        int count = 0;
        for (int i = 0; i < s.length(); ++i) {
            count = count *10 + (s[i] -'0');
        }
        return count;
    }
    bool kt(string s, char c){
        for (int i = 0; i < s.length(); ++i) {
            if(s[i] == c) return true;
        }
        return false;
    }
    Node(string data) {
        this->data = data;
        int temp;
        if(kt(data,'+')){
            int k = data.find('+');
            string s1 = data.substr(0, k);
            string s2 = data.substr(k+1, data.length());
            temp = stringtoint(s1) + stringtoint(s2);
        }
        if(kt(data,'-')){
            int k = data.find('-');
            string s1 = data.substr(0, k);
            string s2 = data.substr(k+1, data.length());
            temp = stringtoint(s1) - stringtoint(s2);
        }
        if(kt(data,'*')){
            int k = data.find('*');
            string s1 = data.substr(0, k);
            string s2 = data.substr(k+1, data.length());
            temp = stringtoint(s1) * stringtoint(s2);
        }
        if(kt(data,'/')){
            int k = data.find('%');
            string s1 = data.substr(0, k);
            string s2 = data.substr(k+1, data.length());
            temp = stringtoint(s1) % stringtoint(s2);
        }
        this->res = temp;
        this->next = nullptr;
    }
};

class Link{
public:
    Node* head;
    Link(): head(nullptr){};
    int count = 0;
    bool insert(string s){
        Node* ptr = new Node(s);
        if(head == nullptr)
            head = ptr;
        else{
            ptr->next = head;
            head = ptr;
        }
        count ++;
        return true;
    }
    void print_data(){
        Node* ptr = new Node();
        ptr = head;
        while(ptr->next){
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << ptr->data << endl;
    }
    void print_res(){
        Node* ptr = new Node();
        ptr = head;
        while(ptr->next){
            cout << ptr->res << " ";
            ptr = ptr->next;
        }
        cout << ptr->res << endl;
    }
};
int main() {
    Link* list = new Link();
    list->insert("1+2");
    list->insert("1-2");
    list->insert("1*2");
    list->insert("1/2");
    list->print_data();
    list->print_res();
    return 0;
}
