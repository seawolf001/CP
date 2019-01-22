#include <bits/stdc++.h>
using namespace std;
struct Book{
	string title;
	string author;

	inline bool operator <(const Book& other) const{
		if(author!=other.author){
			return author < other.author;
		}
		return title < other.title;
	}
};
enum Enum{
	availble,
	borrowed,
	returned
};
int main()
{	
	vector<Book> allBooks;
	string temp = "";
	Book curr;

	while(cin >> temp, temp != "END"){
		curr.title = ""; 
		bool first = true;
		while(*(temp.end()-1) != '"'){
			if(!first) curr.title += ' ';
			first = false;
			curr.title += temp;
			cin >> temp;
		}
		if(!first) curr.title += ' ';
		curr.title += temp;

		cin >> temp; // read by and infore the space after it
		cin.ignore();

		getline(cin, curr.author);
		allBooks.push_back(curr);
	}		
	int total = allBooks.size();
	/*for(int i=0;i<total;i++){
		cout << allBooks[i].title << " " << allBooks[i].author << endl;
	}*/
	sort(allBooks.begin(), allBooks.end());
	/*cout << "*****************************" << endl;
	for(int i=0;i<total;i++){
		cout << allBooks[i].title << " " << allBooks[i].author << endl;
	}*/
	vector<Enum> status(total, availble);

	map<string, int> position;
	for(int i=0; i<total; i++){
		position[allBooks[i].title]=i;
	}

	vector<bool> borrowed(total, false);
	vector<bool> returned(total, false);

	string command, name;
	while(cin >> command, command !="END"){
		if(command=="BORROW"){
			cin.ignore();
			getline(cin, name);
			int pos = position[name];
			borrowed[pos] = true;
		}else if(command=="RETURN"){
			cin.ignore();
			getline(cin, name);
			int pos = position[name];
			returned[pos]=true;
		}else {
			int prev=-1;
			for(int i=0;i<total;i++){
				if(!borrowed[i]){
					prev = i;
				} else if(returned[i]){
					if(prev == -1){
						cout << "Put " << allBooks[i].title << " first\n";
					} else{
						cout << "Put " << allBooks[i].title << " after " << allBooks[prev].title << "\n";
					}
					returned[i]=false;
					borrowed[i]=false;
					prev = i;
				}
			}
			cout << "END\n";
		}
	}
	return 0;
}