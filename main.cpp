#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include "ArgumentManager.h"
using namespace std;

//calling Node *var will create a Node with data and a pointer to next
struct Node {
  string data;
  Node *next;
};

class LinkedList {
private:
  //creating two node pointers;
  Node *head;
  Node *tail;
public:
  //initialize both head and taill to point to null since there are no nodes yet
  LinkedList() {head=tail=nullptr;} 

  //taking size and array
  void create(int size, string A[]) {
    //first number will be head and tail
    head = new Node;
    head->data = A[0];
    head->next = nullptr;
    tail = head;
    //start at 1 since you initialized A[0] already
    for(int i=1; i<size; i++) {
      Node *t= new Node;
      t->data = A[i];
      t->next = nullptr;
      
      //since tail = head, this will allow you to set next pointers
      tail->next = t;
      tail = t;
    }
  }

  string returnAtIndex(int pos) {
    Node *t = head;
    for(int i=0; i<pos; i++) {
      t=t->next;
    }
    if(t) {
      return t->data;
    } else {
      return "";
    }
  }

  bool checkAtIndex(int pos) {
    if(head == nullptr) {
      return false;
    }
    Node *t = head;
    for(int i=0; i<pos; i++) {
      t=t->next;
    }
    if(t) {
      return true;
    } else {
      return false;
    }
  }

  int addAtIndex(int pos, string x) {
    Node *t, *p;
    if(pos == 0) {
      addAtHead(x);
      return 1;
    } else if (pos > 0) {
      p = head;
      for(int i=1; i<pos && p; i++) {
        p = p->next;
      }
      if(p) {
        t = new Node;
        t->data = x;
        t->next = p->next;
        p->next = t;
        return 1;
      } else {
        return 0;
      }
    } else {
      return 0;
    }
  }

  void addAtHead(string x) {
    //create a new node and fill it with data and next will point to old head
    Node *t = new Node;
    t->data = x;
    t->next = head;
    //check if there are no nodes, if not head and tail = t
    if(head == nullptr) {
      tail = t;
    }
    //update head
    head = t;
  }

  void addAtTail(string x) {
    //create a new node and fill it with data and next will point to null
    Node *t = new Node;
    t->data = x;
    t->next = nullptr;
    //if no nodes, head and tail = t 
    if(head == nullptr) {
      head = t;
    }
    //set old tail to point to new node
    tail->next=t;
    //update tail
    tail=tail->next;
  }

  int removeAtIndex(int pos) {
    Node *t, *p;
    if(pos == 0) {
      if(head == nullptr) {
        return 0;
      } else {
        t = head;
        head = head->next;
        delete t;
        return 1;
      }
    } else if (pos > 0) {
      p = head;
      for(int i=0; i<pos && p; i++) {
        t=p;
        p = p->next;
      }
      t->next = p->next;
      delete p;
      return 1;
    } else {
      return 0;
    }
  }

  void removeFromTail() {
    //return if there are no nodes
    if(head == nullptr) {
      return;
    }
    //name head with a temp var
    Node *t = head;
    //move down the list until you're one off from tail
    while(t->next != tail) {
      t = t->next;
    }
    //make tail equal temp var
    tail = t;
    //move the temp var to old tail and delete it
    t = t->next;
    delete t;
    //set the new tail to point to null
    tail->next = nullptr;
  }

  void print() {
    //temp pointer
    Node* p = head;

    //continue until last node
    while (p != nullptr){
      //check if it is last node so you don't print the arrow
      if(p->next == nullptr) {
        cout << p->data << endl;
      } else {
        cout << p->data << " -> ";
      }
      //needed so while statement finishes
      p = p->next;
    }
  }
  
  void print(ofstream &out) {
    Node* p = head;

    while (p != nullptr) {
    out << p->data << endl;
    p = p->next;
  }
}

 int checkForWord(int start, string word) {
  Node *t = head;
  int counter = 0;
  if(start > 0) {
    for(int i = 0; i<start; i++) {
      if(t) {
        t = t->next;
      }
    }
  }
  if(t == nullptr) {
    return -1;
  }
  while(t->next != nullptr) {
    if(t->data == word) {
      return counter;
    }
    t=t->next;
    counter++;
  }
  if(t->data == word) {
    return counter;
  } else {
    return -1;
  }
}

int idCheck(string word) {
  Node *t = head;
  int counter = 0;
  if(head == nullptr) {
    return -1;
  }
  while(t->next != nullptr) {
    if(t->data == word) {
      return counter;
    }
    t=t->next;
    counter++;
  }
  if(t->data == word) {
    return counter;
  } else {
    return -1;
  }
}

Node* search(int pos) {
  Node *t = head;
  for(int i=0; i<pos; i++) {
    t=t->next;
    }
  if(t) {
    return t;
  } else {
    return nullptr;
  }
}

void sort(int size, string ad, LinkedList &cu, LinkedList &list1, LinkedList &list2, LinkedList &list3, LinkedList &list4, string is) {
  Node *t, *p, *p1, *t1, *p2, *t2, *p3, *t3, 
  *p4, *t4, *prev, *prev1, *prev2, *prev3, *prev4;
  bool check;
  if(head == nullptr || head->next == nullptr) {
    return;
  }
  p1 = list1.search(0);
  t1 = p1->next;
  p2 = list2.search(0);
  t2 = p2->next;
  p3 = list3.search(0);
  t3 = p3->next;
  p4 = list4.search(0);
  t4 = p4->next;

  for(int i = 0; i<size - 1; i++) {
    for(int j = 0; j<size - i - 1; j++) {
      check = false;
      if(ad == "a"){
        if(is == "int") {
          if(stoi(cu.returnAtIndex(j)) > stoi(cu.returnAtIndex(j+1))) {
            check = true;
          }
        } else if (is == "string") {
          if(strcmp(cu.returnAtIndex(j).c_str(), cu.returnAtIndex(j+1).c_str()) > 0) {
            check = true;
          }
        }
      } else if(ad == "d") {
        if(is == "int") {
          if(stoi(cu.returnAtIndex(j)) < stoi(cu.returnAtIndex(j+1))) {
            check = true;
          }
        } else if (is == "string") {
          if(strcmp(cu.returnAtIndex(j).c_str(), cu.returnAtIndex(j+1).c_str()) < 0) {
            check = true;
          }
        }
      }
      if(j>0) {
        prev = cu.search(j-1);
        prev1 = list1.search(j-1);
        prev2 = list2.search(j-1);
        prev3 = list3.search(j-1);
        prev4 = list4.search(j-1);
      }
      p = cu.search(j);
      p1 = list1.search(j);
      p2 = list2.search(j);
      p3 = list3.search(j);
      p4 = list4.search(j);
      t = p->next;
      t1 = p1->next;
      t2 = p2->next;
      t3 = p3->next;
      t4 = p4->next;
      
      if(check) {
        if(j==0) {
          p->next = t->next;
          p1->next = t1->next;
          p2->next = t2->next;
          p3->next = t3->next;
          p4->next = t4->next;
          t->next = p;
          t1->next = p1;
          t2->next = p2;
          t3->next = p3;
          t4->next = p4;
          cu.head = t;
          list1.head = t1;
          list2.head = t2;
          list3.head = t3;
          list4.head = t4;
        } else {
          p->next = t->next;
          p1->next = t1->next;
          p2->next = t2->next;
          p3->next = t3->next;
          p4->next = t4->next;
          t->next = p;
          t1->next = p1;
          t2->next = p2;
          t3->next = p3;
          t4->next = p4;
          prev->next = t;
          prev1->next = t1;
          prev2->next = t2;
          prev3->next = t3;
          prev4->next = t4;
        }
      } 
    }
  }
}
  
};

int main(int argc, char* argv[]) {
  ArgumentManager am(argc, argv);
  ifstream input(am.get("input"));
  ifstream command(am.get("command"));
  ofstream out(am.get("output"));

  //ifstream input("input9.txt");
  //ifstream command("command9.txt");
  //ofstream out("output9.txt");

  LinkedList credl, idl, userl, scorel, gradel;

  string cred = "";
  string id = "";
  string user = "";
  string score = "";
  string grade = "";
  
  int inSize = 0;
  int idCheck;
  int i;
  int j;

  while(getline(input, cred)) {
    // Clean up blank spaces, \n and \r, and skip blank lines
    cred.erase(remove(cred.begin(), cred.end(), '\n'), cred.end());
    cred.erase(remove(cred.begin(), cred.end(), '\r'), cred.end());
    cred.erase(remove(cred.begin(), cred.end(), ' '), cred.end());
    //dismiss non-entries
    if(cred.size() == 0)
      continue;

    //check if all items are in credential
    if(cred.find("id:") == string::npos || 
      cred.find("username:") == string::npos || 
      cred.find("score:") == string::npos || 
      cred.find("grade:") == string::npos)
      continue;
    
    //check if credentials are in right order
    if(cred.find("id:") < cred.find("username:") && 
      cred.find("username:") < cred.find("score:") && 
      cred.find("score:") < cred.find("grade:")) {

      id = cred.substr(cred.find("id:")+3, 4);
      user = cred.substr(cred.find("name:")+5, cred.find(";score") - cred.find("name:")-5);
      score = cred.substr(cred.find("score:")+6, cred.find(";grade") - cred.find("score:")-6);
      grade = cred.substr(cred.find("grade:")+6, 1);
      
      idCheck = idl.idCheck(id);
      
      if(idCheck >= 0) {
        if(userl.checkForWord(0, user) == -1 || 
          (userl.checkForWord(0, user) == idCheck && userl.checkForWord(idCheck+1, user) == -1)) {
          credl.removeAtIndex(idCheck);
          idl.removeAtIndex(idCheck);
          userl.removeAtIndex(idCheck);
          scorel.removeAtIndex(idCheck);
          gradel.removeAtIndex(idCheck);
          credl.addAtIndex(idCheck, cred);
          idl.addAtIndex(idCheck, id);
          userl.addAtIndex(idCheck, user);
          scorel.addAtIndex(idCheck, score);
          gradel.addAtIndex(idCheck, grade);
        }
      }
      if(userl.checkForWord(0, user) == -1) {
        idl.addAtIndex(inSize, id);
        userl.addAtIndex(inSize, user);
        scorel.addAtIndex(inSize, score);
        gradel.addAtIndex(inSize, grade);
        credl.addAtIndex(inSize, cred);
        inSize++;
      }
    }
  }

  //credl.print();
  
  string cmd = "";
  string word = "";
  string item = "";
  
  int index;

  LinkedList checkl;

  while(getline(command, cmd)) {
    // Clean up blank spaces, \n and \r, and skip blank lines
    cmd.erase(remove(cmd.begin(), cmd.end(), '\n'), cmd.end());
    cmd.erase(remove(cmd.begin(), cmd.end(), '\r'), cmd.end());
    cmd.erase(remove(cmd.begin(), cmd.end(), ' '), cmd.end());
    if(cmd.size() == 0)
      continue;

    if(cmd.substr(0,3) == "Add") {
      index = stoi(cmd.substr(4,cmd.find(")")-4));
      for(int i=0; i<index; i++) {
        if(credl.checkAtIndex(i) == false) {
          goto cnt;
        } 
      }
      
      cred = cmd.substr(cmd.find("["),cmd.find("grade:")+6 - cmd.find("id:")+3);
      
      if(cred.find("id:") == string::npos || 
      cred.find("username:") == string::npos || 
      cred.find("score:") == string::npos || 
      cred.find("grade:") == string::npos)
      continue;
    
    //check if credentials are in right order
      if(cred.find("id:") < cred.find("username:") && 
        cred.find("username:") < cred.find("score:") && 
        cred.find("score:") < cred.find("grade:")) {

        id = cred.substr(cred.find("id:")+3, 4);
        user = cred.substr(cred.find("name:")+5, cred.find(";score") - cred.find("name:")-5);
        score = cred.substr(cred.find("score:")+6, cred.find(";grade") - cred.find("score:")-6);
        grade = cred.substr(cred.find("grade:")+6, 1);
      
        idCheck = idl.idCheck(id);
      
        if(idCheck >= 0) {
          if(userl.checkForWord(0, user) == -1 || 
            (userl.checkForWord(0, user) == idCheck && userl.checkForWord(idCheck+1, user) == -1)) {
            credl.removeAtIndex(idCheck);
            idl.removeAtIndex(idCheck);
            userl.removeAtIndex(idCheck);
            scorel.removeAtIndex(idCheck);
            gradel.removeAtIndex(idCheck);
            credl.addAtIndex(idCheck, cred);
            idl.addAtIndex(idCheck, id);
            userl.addAtIndex(idCheck, user);
            scorel.addAtIndex(idCheck, score);
            gradel.addAtIndex(idCheck, grade);
          }
        }
        if(userl.checkForWord(0, user) == -1) {
          idl.addAtIndex(index, id);
          userl.addAtIndex(index, user);
          scorel.addAtIndex(index, score);
          gradel.addAtIndex(index, grade);
          credl.addAtIndex(index, cred);
          inSize++;
        }
      }
    }
    
    if(cmd.substr(0,6) == "Remove") {
      word = cmd.substr(7, cmd.find(":")-7);

      if(word == "id") {
        item = cmd.substr(10,4);
        checkl = idl;
      } else if (word == "username") {
        item = cmd.substr(16,cmd.find(")") - cmd.find(":")-1);
        checkl = userl;
      } else if (word == "score") {
        item = cmd.substr(13,cmd.find(")") - cmd.find(":")-1);
        checkl = scorel;
      } else if (word == "grade") {
        item = cmd.substr(13,1);
        checkl = gradel;
      }

      for(i=0; i<inSize; i++) {
        if(item == checkl.returnAtIndex(i)) {
          credl.removeAtIndex(i);
          idl.removeAtIndex(i);
          userl.removeAtIndex(i);
          scorel.removeAtIndex(i);
          gradel.removeAtIndex(i);
          inSize--;
          i--;
        }
        if(word == "id") {
          checkl = idl;
        } else if (word == "username") {
          checkl = userl;
        } else if (word == "score") {
          checkl = scorel;
        } else if (word == "grade") {
          checkl = gradel;
        }
      }
    }

    if(cmd.substr(0,4) == "Sort") {
      word = cmd.substr(5, cmd.find(")") - 5);
      if(word == "id") {
        idl.sort(inSize, "a", idl, credl, userl, scorel, gradel, "int");
      } else if (word == "username") {
        userl.sort(inSize, "a", userl, credl, idl, scorel, gradel, "string");
      } else if (word == "score") {
        scorel.sort(inSize, "d", scorel, credl, userl, idl, gradel, "int");
      } else if (word == "grade") {
        gradel.sort(inSize, "a", gradel, credl, userl, scorel, idl, "string");
      }
    }
    cnt:;
  }
  //credl.print();
  credl.print(out);
}