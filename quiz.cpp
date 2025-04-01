#include<bits/stdc++.h>
using namespace std;

struct Question{
	string question;
	vector<string> options;
	char correctOpt;
};

vector<Question> loadQues(const string &fileName){
	vector<Question> questions;
	ifstream file(fileName);
	string line;
	
	while(getline(file, line)){
		if(line.empty())continue;
		Question q;
		q.question=line;
		
		for(int i=0; i<4; i++){
			getline(file,line);
			q.options.push_back(line);
		}
		
		getline(file,line);
		q.correctOpt=line[0];
		questions.push_back(q);
	}
	file.close();
	return questions;
}

void runQuiz(vector<Question> &questions, int n){
	int score=0;
	char answer;
	int totalQues=min(n,(int)questions.size());
	
	random_device rd;
    mt19937 g(rd());
    shuffle(questions.begin(), questions.end(), g);
	
	for(int i=0; i<totalQues; i++){	
		const auto &q = questions[i];
		cout<<q.question<<endl;
		for(int i=0; i<4; i++){
			cout<<char('A'+i)<<": "<<q.options[i]<<endl;
		}
		cout<<"Enter your answer: ";
		cin>>answer;
		if(toupper(answer)==toupper(q.correctOpt)){
			cout<<"Correct *_*"<<endl;
			score++;
		}else{
			cout<<"Wrong -_-"<<endl<<"Correct answer is: "<<q.correctOpt<<endl;
		}
		cout<<endl;
	}
	
	cout<<"Quiz completed! Your Score: "<<score<<"/"<<totalQues<<endl;
}

int main(){
	vector<Question> questions = loadQues("questions.txt");
    if (questions.empty()) {
        cout << "No questions found. Exiting.\n";
        return 0;
    }
	
	int n;
    cout << "Enter the number of questions you want to attempt: ";
    cin >> n;
	cout<<endl;
    runQuiz(questions, n);
    return 0;
}
