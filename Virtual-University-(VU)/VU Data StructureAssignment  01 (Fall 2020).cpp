#include<iostream>
#include<string>
using namespace std;
class node
{
private:
	string S_ID;
	string f_name;
	string l_name;
	int marks;
public:
	node*next;
	string get_id()
	{
		return S_ID;
	}
	string get_fname()
	{
		return f_name;
	}
	string get_lname()
	{
		return l_name;
	}
	int get_marks()
	{
		return marks;
	}
	void set_ID(string id)
	{
		S_ID=id;
	}
	void set_Fname(string fn)
	{
		f_name=fn;
	}
	void set_Lname(string ln)
	{
		l_name=ln;
	}
	void set_marks(int m)
	{
		marks=m;
	}
};

node*head = NULL, *tail= NULL;

void insert(string id,string fn, string ln, int m)
{
	node*obj = new node;
	obj->set_ID(id);
	obj->set_marks(m);
	obj->set_Lname(ln);
	obj->set_Fname(fn);
	obj->next = NULL;
	if (head == NULL)
	{
		head = obj;
		tail = obj;
	}
	else
	{
	    
	    node *temp = head , *prev=head;
	    
	    while(temp != NULL){
	        if(m < temp->get_marks()){
	            prev=temp;
	            temp= temp->next;
	        }
	        else{
	            break;
	        }
	    }
	    
	    if(head == tail){
	       if(m > head->get_marks()){
	           obj->next = head;
    	       head=obj;
    	       tail=obj->next;
	       } else{
    	       head->next=obj;
    	       tail=obj;
	       }
	    }
	    else{
	        prev->next=obj;
	        obj->next=temp;
	    }
	    
	}
}

void display()
{
	node*temp = head;
	if (head == NULL){
		cout << "list empty\n";
	}
	else
	{
		while (temp != NULL)
		{
			cout<<endl;
			cout<<"Student ID : "<<temp->get_id()<<endl;
			cout<<"First Name : "<<temp->get_fname()<<endl;
			cout<<"Last Name  : "<<temp->get_lname()<<endl;
			cout<<"Marks      : "<<temp->get_marks()<<endl;
			cout<<"\n--------------------------------------------------------------\n";
			temp=temp->next;
		}
		cout<<endl<<endl;
	}
}

int main()
{
	int ch;
	string Fn,Ln,id;
	int m;
	do{
		cout<<"\n\t\t Press 1 To Add New Student"<<endl;
		cout<<"\t\t Press 2 To Display"<<endl;
		cout<<"\t\t Press 3 To Exit"<<endl<<endl;
		cout<<"Enter Choice: ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout<<endl;
			getline(cin,id);
			cout << "Student ID : ";
			getline(cin,id);
			cout << "First Name : ";
			getline(cin,Fn);
			cout << "Last Name  : ";
			getline(cin,Ln);
			cout<<"Marks      : ";
			cin>>m;
			insert(id,Fn,Ln,m);
			break;
		case 2:
		    cout<<"\n\n-------------------------------------------------------------\n";
			display();
			break;
		case 3:
			break;
		default:
			cout << "invalid\n";
			break;
		}
	}while (ch != 0);
	system("pause");
	return 0;
}