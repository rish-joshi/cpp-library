#include "Library.hpp"
#import <iostream>
#define is_not !=



void Node::addNode(int number){
  if (data == -1){
    data = number;
    totalNodes += 1;
  }
  else {
    if (next == nullptr) {
      auto newNode = new Node();
      newNode->data = number;
      next = newNode;
      totalNodes += 1;
    }
    else{
      auto loc = next;
      while (loc->next is_not nullptr) {
        loc = loc->next;
      }
      auto newNode = new Node();
      loc->next = newNode;
      newNode->data = number;
      totalNodes += 1;
    }
  }
}

int Node::totalNodes = 0;  // Static variable has to be initiated manually.

// * add a new node to the head.
Node* Node::addHead(int number){
  auto newNode = new Node();
  newNode->data = number;
  newNode->next = this;
  totalNodes += 1;
  return newNode;
}

void Node::printNodes(){
  auto currentNode = this;
  std::cout << "\n\n";
  while (currentNode is_not nullptr) {
    std::cout << currentNode->data << '\n';
    currentNode = currentNode->next;
  }
  std::cout << "\n\n";  
}

void Node::printTotalNodes() {
  std::cout <<"Total Nodes →  " << totalNodes << "\n";
}

Node* Node::removeNode(int position){
  int countedNodes = 0;
  Node* location;
  location = this;
  if (position == 0){
    totalNodes -= 1;
    return location->next;
  }
  else {
    while(countedNodes is_not position - 2) {
      location = location->next;
      countedNodes += 1;
    }    
  }

  location->next = location->next->next;
  totalNodes -= 1;

  return this;
}




///////////////////////////////////////////////////////
/////////			BINARY TREE  			///////////
///////////////////////////////////////////////////////




void BinaryTree::addChild(int number){
	if (data == -1) {
		data = number;
		return;
	}
	else {

		if (number <= data and this->Left != nullptr){
			this->Left->addChild(number);
		}
		if (number >= data and this->Right != nullptr){
			this->Right->addChild(number);
		}
		else if (number <= data and this->Left == nullptr){
			Left = new BinaryTree();
			Left->data = number;
			return;
		}
		else if (number > data and this->Right == nullptr) {
			Right = new BinaryTree();
			Right->data = number;
			return;
		}

	}
	
}

/* 
* `INVaddChild` adds the logically opposite child
*/
void BinaryTree::INVaddChild(int number){
	if (data == -1) {
		data = number;
		return;
	}
	else {

		if (number >= data and this->Left is_not nullptr){
			this->Left->INVaddChild(number);
		}
		else if (number <= data and this->Right != nullptr){
			this->Right->INVaddChild(number);
		}
		else if (number >= data and this->Left == nullptr){
			Left = new BinaryTree();
			Left->data = number;
			return;
		}
		else if (number < data and this->Right == nullptr) {
			Right = new BinaryTree();
			Right->data = number;
			return;
		}

	}
	
}


void BinaryTree::PrintTree(int TraversalType){
	if (this and TraversalType == 0){
		std::cout << this->data << "\n";
		this->Left->PrintTree();
		this->Right->PrintTree();
	}
	else if (this and TraversalType == 1){
		this->Left->PrintTree();
		std::cout << this->data << "\n";
		this->Right->PrintTree();
	}
	else if (this and TraversalType == 2){
		this->Left->PrintTree();
		this->Right->PrintTree();
		std::cout << this->data << "\n";

	}
	else {
		std::cerr << "This value is NOT POSSIBLE\n";
	}
}

