#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
const int count_trees = 5;

class Branch{
private:
    Branch *parent = nullptr;
    vector <Branch*> children;
    string elfName = "None";

public:

    vector <Branch*> get_children(){
      return children;
    };

    void set_children(Branch* parent, string& name){
        children.push_back(new Branch(parent, name));
    };
    string get_elf_name(){
        return elfName;
    }
    //Branch (){};

    Branch* getTopBranch()
    {
        //Если это дерево
        if (parent == nullptr) return nullptr;
        //Если это средняя ветка
        if (parent->parent == nullptr) return nullptr;
        //Если это маленькая ветка
        return parent;
    }

    Branch(Branch* parent, string name) {
        elfName = name;
        this->parent = parent;
    }
};


void print(Branch* Tree){
    for (int i = 0; i < (Tree->get_children().size()); i++){
        if (Tree->get_children()[i]->get_elf_name() != "None")
        cout  << Tree->get_children()[i]->get_elf_name() << " ";
    }
    if (Tree->get_elf_name() != "None") cout << Tree->get_elf_name();
    cout << endl;
}

Branch* find(string& fnd, Branch* Tree){

    for (int i = 0; i < (Tree->get_children().size()); i++) {
        if (Tree->get_children()[i]->get_elf_name() == fnd ) {

            if (Tree->get_children()[i]->getTopBranch() != nullptr) return Tree->get_children()[i]->getTopBranch();
            else return Tree->get_children()[i];
        }
        if ( find(fnd, Tree->get_children()[i]) != nullptr){
            
            return find(fnd, Tree->get_children()[i]);
        }
    }
    return nullptr;
}

int main(){
    vector <Branch*> Trees;
    string name;

for (int i = 0; i < count_trees; i++) {
    int m = rand() % 3 + 2;  //кол-во средних веток
    Trees.push_back(new Branch(nullptr, "None"));
    cout << m << endl;

    for (int j = 0; j < m; j++) {
        int k =  rand() % 2 + 2; //кол-во маленьких веток
        cout << k << endl;
        cin >> name;
        Trees[i]->set_children(Trees[i], name); //создание средних веток
         for (int h = 0; h < k; h++){
            cin >> name;
            Trees[i]->get_children()[j]->set_children(Trees[i]->get_children()[j], name); // создание маленьких веток
        }

    }
}


    string fnd;
    cout << "Input: ";
    cin >> fnd;
    for(int i = 0; i < count_trees; i++) {
         print(find(fnd, Trees[i]));
    }

}
