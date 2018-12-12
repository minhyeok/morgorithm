#include <iostream>
#include <vector>

using namespace std;

struct stPartner{
	int partner[2];
}; 

struct problem{
	int nstudent;
	int npartner;
	vector <stPartner> partners;
	int answer;
};

int solveProblem(problem &pm);
int calcResult(problem &pm, int startnum, vector<stPartner> &result);
int isNumberExist(int num, vector<stPartner> &partList);

int main()
{
	int nocase;
	problem * prob;

	cin >> nocase;

	for(int i=0; i< nocase;i++) {
		prob= new problem;
		cin >> prob->nstudent >> prob->npartner;
		for(int j = 0; j< prob->npartner; j++){
			stPartner Pn;
			cin>>Pn.partner[0];
			cin>>Pn.partner[1];
			prob->partners.push_back(Pn);
		}
		cout << "student: " << prob->nstudent << endl;
		cout << "partner: " << prob->npartner << endl;
		for(int i = 0; i < prob->partners.size(); i++) {
			cout << "  partners: "<< prob->partners[i].partner[0] << " " << prob->partners[i].partner[1] << endl;
		}
		solveProblem(*prob);
		cout << prob->answer << endl;
		delete prob;
	}

	return 0;
}

int solveProblem(problem &pm){

	vector <stPartner> resultset;

	calcResult(pm, 0, resultset);

	return 0;
}

int calcResult(problem &pm, int startnum, vector<stPartner> & result){
	int matchflag = 0;
	if (startnum > pm.nstudent) return 0;
	if (result.size() == pm.nstudent / 2) {
		pm.answer++;
		return 0; /* terminated if result is all setted. **/
	}

	for (int i = startnum; i < pm.nstudent; i++){
		/* if i've already picked in  result set, continue.*/
		for (int j = 0; j < result.size(); j++){
			if(result[j].partner[1] == i ){
				matchflag = 1;
				break;
			}
		}
		if( matchflag ){ matchflag = 0; continue;}

		/* then I have to pick partner.*/
		for(int j = 0; j < pm.npartner ; j++){
			if(pm.partners[j].partner[0] == i
					&& isNumberExist(pm.partners[j].partner[1], result) == 0) {
				result.push_back(pm.partners[j]);	
				calcResult(pm, i+1, result);
				result.pop_back();
			}
		}
	}
	/* all of student have chosen.*/
	return 0;
}

int isNumberExist(int num, vector<stPartner> & partList){

	for(int i = 0; i<partList.size(); i++){
		if(partList[i].partner[0] == num || 
				partList[i].partner[1] == num)
			return 1;
	}

	/* notexist */
	return 0;
}
