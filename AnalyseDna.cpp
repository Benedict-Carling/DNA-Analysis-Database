
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <array>
#include <bits/stdc++.h>

#include <regex>
using namespace std;

class DNA_DB {
	public:

		string titleid;
		
		string GID;
		
		string Reference;
		
		string Name;
		
		vector<char> sequenceid;
		
		int identification;
	
		vector<char> UploadDNASequence(string filename);
		
		string UploadDNATitle(string filename);
		
		string UploadGID(string filename);
		
		string UploadReference(string filename);
		
		string UploadName(string filename);

		int Basepairnumber(vector<char> Sequence);
		
		int GapSummary(vector<char> Sequence);
		
		int Nregionnumber(vector<char> Sequence);
		
		int Cregionnumber(vector<char> Sequence);
		
		int basepairrange(vector<char> Sequence);
		
		int manualinput(vector<char> Sequence);
		
		int fileinput(vector<char> Sequence, vector<char> FileSequence);
		
		int Basehelp();
};

//External Function
//To split string into vector based on deliminater given
vector<string> split (const string &s, char delim) {
    vector<string> result;
    stringstream ss (s);
    string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}


//Function Definition
//UploadDNASequence
vector<char> DNA_DB :: UploadDNASequence(string filename)
		{
			vector<char>Sequence;
			string line;
			char myc;
			ifstream myfile(filename);
			if (myfile.is_open())
			{
			  getline (myfile,line);
			  while (!myfile.eof())
			  {
				myfile.get(myc);
				if(int(myc)!=10)
				{
					Sequence.push_back(myc);
				}
			  }
			  myfile.close();
			}
			return Sequence;
		}

//Function Definition
//UploadDNATitle
string DNA_DB :: UploadDNATitle(string filename) {
			string line;
			string title;
			ifstream myfile(filename);
			if (myfile.is_open())
			{
			  getline (myfile,line);
			  title = line;
			  myfile.close();
			}
			return title;
}

//Function Definition
//UploadGID
string DNA_DB::UploadGID(string filename) {
			string line;
			string GIDF;
			char delim = '|';
			ifstream myfile(filename);
			if (myfile.is_open())
			{
			  getline (myfile,line,delim);
			  getline (myfile,line,delim);
			  GIDF = line;
			  myfile.close();
			}
			return GIDF;
}

//Function Definition
//UploadReference
string DNA_DB::UploadReference(string filename){
			string line;
			string Reference;
			char delim = '|';
			ifstream myfile(filename);
			if (myfile.is_open())
			{
			  getline (myfile,line,delim);
			  getline (myfile,line,delim);
			  getline (myfile,line,delim);
			  getline (myfile,line,delim);
			  Reference = line;
			  myfile.close();
			}
			return Reference;
}

//Function Definition
//Uploadname
string DNA_DB::UploadName(string filename){
			string line;
			string Name;
			char delim = '|';
			char delim2 = 'N';
			ifstream myfile(filename);
			if (myfile.is_open())
			{
			  getline (myfile,line,delim);
			  getline (myfile,line,delim);
			  getline (myfile,line,delim);
			  getline (myfile,line,delim);
			  getline (myfile,line,delim2);
			  Name = line;
			  myfile.close();
			}
			return Name;
}

//Function Definition
//Basepairnumber
int DNA_DB :: Basepairnumber(vector<char> Sequence){
			long double Total = 0;
			long double Gn = 0;
			long double An = 0;
			long double Tn = 0;
			long double Cn = 0;
			long double Rn = 0;
			long double Yn = 0;
			long double Mn = 0;
			long double Kn = 0;
			long double Sn = 0;
			long double Wn = 0;
			long double Hn = 0;
			long double Bn = 0;
			long double Vn = 0;
			long double Dn = 0;
			long double Nn = 0;
			for(long double i = 0;i<Sequence.size();i++)
			{
				if (Sequence[i] == 'G'){
				  Gn++;
				}
				if (Sequence[i] == 'A'){
				  An++;
				}
				if (Sequence[i] == 'T'){
				  Tn++;
				}
				if (Sequence[i] == 'C'){
				  Cn++;
				}
				if (Sequence[i] == 'R'){
				  Rn++;
				}
				if (Sequence[i] == 'Y'){
				  Yn++;
				}
				if (Sequence[i] == 'M'){
				  Mn++;
				}
				if (Sequence[i] == 'K'){
				  Kn++;
				}
				if (Sequence[i] == 'S'){
				  Sn++;
				}
				if (Sequence[i] == 'W'){
				  Wn++;
				}
				if (Sequence[i] == 'H'){
				  Hn++;
				}
				if (Sequence[i] == 'B'){
				  Bn++;
				}
				if (Sequence[i] == 'V'){
				  Vn++;
				}
				if (Sequence[i] == 'D'){
				  Dn++;
				}
				if (Sequence[i] == 'N'){
				  Nn++;
				}
			}
			cout.precision(0);
			cout << fixed <<"\nBase pair characteristics:";
			cout << fixed <<"Total Number of bases :  "<< Sequence.size() <<"\n";
			cout << fixed <<"Number of G bases     :  "<< Gn <<"\n";
			cout << fixed <<"Number of A bases     :  "<< An <<"\n";
			cout << fixed <<"Number of T bases     :  "<< Tn <<"\n";
			cout << fixed <<"Number of C bases     :  "<< Cn <<"\n";
			cout << fixed <<"Number of R bases     :  "<< Rn <<"\n";
			cout << fixed <<"Number of Y bases     :  "<< Yn <<"\n";
			cout << fixed <<"Number of M bases     :  "<< Mn <<"\n";
			cout << fixed <<"Number of K bases     :  "<< Kn <<"\n";
			cout << fixed <<"Number of S bases     :  "<< Sn <<"\n";
			cout << fixed <<"Number of W bases     :  "<< Wn <<"\n";
			cout << fixed <<"Number of H bases     :  "<< Hn <<"\n";
			cout << fixed <<"Number of B bases     :  "<< Bn <<"\n";
			cout << fixed <<"Number of V bases     :  "<< Vn <<"\n";
			cout << fixed <<"Number of D bases     :  "<< Dn <<"\n";
			cout << fixed <<"Number of N bases     :  "<< Nn <<"\n";
			return 0;
}


int DNA_DB :: GapSummary(vector<char> Sequence)
{
	long double input_region=0;
			long double i= 0;
			long double counter= 0;
			long double counter2= 0;
			vector<long double>Starts;
			vector<long double>Lenghts;
			
			while(i<Sequence.size())
			{
				if((Sequence[i]==Sequence[i-1])&&(Sequence[i]=='N'))
				{
					counter++;
				}
				else 
				{
					if (counter>=10)
					{
						Starts.push_back(i-counter-1);
						Lenghts.push_back(counter+1);
						counter=0;
					}
					else
					{
						counter=0;
					}
				}
			i++;
			}
			if (counter>0)
			{
				Starts.push_back(i-counter-1);
				Lenghts.push_back(counter+1);
			}
			cout.precision(0);
			
			cout<<"\n\nRegion Characteristics\n";
			cout<<"# Regions        :"<<Starts.size()*2-1<<"\n";
			cout<<"# N Regions      :"<<Starts.size()<<"\n";
			cout<<"# C Regions      :"<<Starts.size()-1<<"\n";
			return 0;
}

//Function Definition
//Nregionnumber
int DNA_DB :: Nregionnumber(vector<char> Sequence){
			long double input_region=0;
			long double i= 0;
			long double counter= 0;
			long double counter2= 0;
			vector<long double>Starts;
			vector<long double>Lenghts;
			
			while(i<Sequence.size())
			{
				if((Sequence[i]==Sequence[i-1])&&(Sequence[i]=='N'))
				{
					counter++;
				}
				else 
				{
					if (counter>=10)
					{
						Starts.push_back(i-counter-1);
						Lenghts.push_back(counter+1);
						counter=0;
					}
					else
					{
						counter=0;
					}
				}
			i++;
			}
			if (counter>0)
			{
				Starts.push_back(i-counter-1);
				Lenghts.push_back(counter+1);
			}
			cout.precision(0);
			cout<<"There are "<<Starts.size()<<" N regions\n";
			cout<<"Enter gap region number between ( 0 , "<<Starts.size()-1<<" ) : ";
			cin>>input_region;
			
			cout<<"\n\nSelected sequence: ";
			cout<<fixed<<"\nBase pair range: ( "<<Starts[input_region]<<" , "<<Starts[input_region] + Lenghts[input_region]<<" )";
			cout<<fixed<<"\nGap region number :"<< input_region;
			
			cout<<"\n\nSequence :\n";
			
			for(long double j = 0;j<Sequence.size();j++)
			{
				if( (j >= Starts[input_region]) and (j < Starts[input_region] + Lenghts[input_region]))
				{
					cout<<Sequence[j];
				}
			}
			
			return 0;
}

//Function Definition
//Cregionnumber
int DNA_DB :: Cregionnumber(vector<char> Sequence)
{
			long double input_region=0;
			long double i= 0;
			long double counter= 0;
			long double counter2= 0;
			vector<long double>Starts;
			vector<long double>Lenghts;
			
			while(i<Sequence.size())
			{
				if((Sequence[i]==Sequence[i-1])&&(Sequence[i]=='N'))
				{
					counter++;
				}
				else 
				{
					if (counter>=10)
					{
						Starts.push_back(i-counter-1);
						Lenghts.push_back(counter+1);
						counter=0;
					}
					else
					{
						counter=0;
					}
				}
			i++;
			}
			if (counter>0)
			{
				Starts.push_back(i-counter-1);
				Lenghts.push_back(counter+1);
			}
			
			cout<<"There are "<<Starts.size()-1<<" regions\n";
			cout<<"Enter coded region number between ( 0 , "<<Starts.size()-2<<" ) : ";
			cin>>input_region;
			
			cout.precision(0);
			cout<<"\n\nSelected sequence: ";
			cout<<fixed<<"\nBase pair range: ( "<<Starts[input_region] + Lenghts[input_region]<<" , "<<Starts[input_region+1]<<" )";
			cout<<"\nGap region number :"<< input_region;
			
			cout<<"\n\nSequence :\n";
			
			for(long double j = 0;j<Sequence.size();j++)
			{
				if( (j >= Starts[input_region] + Lenghts[input_region]) and (j < Starts[input_region+1]))
				{
					cout<<Sequence[j];
				}
			}
			
			return 0;
}

//Function Definition
//basepairrange
int DNA_DB :: basepairrange(vector<char> Sequence)
{
	string user_input;
	cout<<"Enter a comma"<<" '"<<" ,"<<"' "<<" separated base pair range:";
	cin>>user_input;
	
	vector<string>userinputs = split (user_input, ',');
	
	int start = stoi(userinputs[0]);
	int finish = stoi(userinputs[1]);
	
	cout<<"\n\nSequence :\n";
	for(long double j = 0;j<Sequence.size();j++)
	{
		if( (j >= start) and (j < finish))
		{
			cout<<Sequence[j];
		}
	}
	return 0;
}

//Function Definition
//manualinput
int DNA_DB :: manualinput(vector<char> Sequence)
{
	string nucleosequence;
	vector<char>nucleotide;
	vector<long double>samestart;
	bool similar;
	long double counter = 0;
	cout << "Specify the DNA sequence nucleotides you would like to find: ";
	cin >> nucleosequence;
	
	for (int i = 0; i<nucleosequence.length();i++)
	{
		nucleotide.push_back(nucleosequence[i]);
	}
	
	for(long double j = 0;j<Sequence.size();j++)
	{
		similar = true;
		for (int k = 0; k<nucleosequence.length();k++)
		{
			if (Sequence[j+k] != nucleosequence[k])
			{
				similar = false;
			}
		}
		if(similar == true)
		{
			samestart.push_back(j);
			counter++;
		}
	}
	
	for (long double i = 0; i<samestart.size();i++)
	{
		cout.precision(0);
		cout<<fixed<<i<<". Base pair range: ( "<<samestart[i]<<" , "<<samestart[i] + nucleosequence.length()<<" )\n";
		
		long double start = samestart[i];
		long double finish = samestart[i] + nucleosequence.length();
		
		for(long double j = 0;j<Sequence.size();j++)
		{
			if((j >=(start-20)) and (j < (finish+20)))
			{
				cout<<Sequence[j];
				if ((j==start-1)||j==(finish-1))
				{
					cout<<"\n";
				}
			}
		}
		cout<<"\n";
		
	}
	return 0;
}


int DNA_DB :: fileinput(vector<char> Sequence, vector<char> FileSequence)
{
	bool similar;
	long double counter = 0;
	vector<long double>samestartFILE;
	for(long double j = 0;j<Sequence.size();j++)
	{
		similar = true;
		for (int k = 0; k<FileSequence.size();k++)
		{
			if (Sequence[j+k] != FileSequence[k])
			{
				similar = false;
				break;
			}
		}
		if(similar == true)
		{
			samestartFILE.push_back(j);
			counter++;
		}
	}
	for (long double i = 0; i<samestartFILE.size();i++)
	{
		cout.precision(0);
		cout<<fixed<<i<<". Base pair range: ( "<<samestartFILE[i]<<" , "<<samestartFILE[i] + FileSequence.size()<<" )\n";
		
		long double start = samestartFILE[i];
		long double finish = samestartFILE[i] + FileSequence.size();
		
		for(long double j = 0;j<Sequence.size();j++)
		{
			if((j >=(start-20)) and (j < (finish+20)))
			{
				cout<<Sequence[j];
				if ((j==start-1)||j==(finish-1))
				{
					cout<<"\n";
				}
			}
		}
		cout<<"\n";
		
	}
	return 0;
}

//Function Definition
//Basehelp
int DNA_DB :: Basehelp()
{
	cout<<"\n\nCode Base Description\n";
	cout<<"G Guanine\n";
	cout<<"A Adenine\n";
	cout<<"T Thymine (Uracil in RNA)\n";
	cout<<"C Cytosine\n";
	cout<<"R Purine (A or G)\n";
	cout<<"Y Pyrimidine (C or T or U)\n";
	cout<<"M Amino (A or C)\n";
	cout<<"K Ketone (G or T)\n";
	cout<<"S Strong interaction (C or G)\n";
	cout<<"W Weak interaction (A or T)\n";
	cout<<"H Not-G (A or C or T) H follows G in the alphabet\n";
	cout<<"B Not-A (C or G or T) B follows A in the alphabet\n";
	cout<<"V Not-T (not-U) (A or C or G) V follows U in the alphabet\n";
	cout<<"D Not-C (A or G or T) D follows C in the alphabet\n";
	cout<<"D Not-C (A or G or T) D follows C in the alphabet\n";
	cout<<"N Any (A or C or G or T)\n";
	return 0;
}


main(){
	//////// INTODUCTION /////////////////////////////////////
	cout<<"DNA Sequence Database Software"<<"\n\n";
	cout<<"Specify the name of DNA sequence file names you would like to load. For multiple files, add a comma between each file name."<<"\n";
	string preinput;
	cout <<">";
	
	//////// SEPERATING INPUT STRING BY COMMA ////////////////
	getline(cin, preinput);
	string input;
	
    for (int i = 0; i<preinput.length(); i ++)
	  {
		if(preinput[i]!=' ')
		{
		  input.append(1,preinput[i]);
		}
	  }
	cout<<preinput<<"\n";
	
	
	cout<<input;
    vector<string> inputs = split (input, ',');
	cout<<"\n";

	
	
	//////// CREATING THE DATABASES  /////////////////////////
	DNA_DB *dna_db=new DNA_DB[inputs.size()];
	
	//////// LOADING DATABASES  //////////////////////////////
	for(int db_id=0;db_id<inputs.size();db_id++)
	{
		cout<<"Loading "<<inputs[db_id]<<"...\n";
		dna_db[db_id].identification = db_id;
		dna_db[db_id].Name = dna_db[db_id].UploadName(inputs[db_id]);
		dna_db[db_id].GID = dna_db[db_id].UploadGID(inputs[db_id]);
		dna_db[db_id].Reference = dna_db[db_id].UploadReference(inputs[db_id]);
		dna_db[db_id].titleid = dna_db[db_id].UploadDNATitle(inputs[db_id]);
		dna_db[db_id].sequenceid = dna_db[db_id].UploadDNASequence(inputs[db_id]);
		cout<<"Successful Loading of "<<inputs[db_id]<<"\n";
	}
	
	//////// HOME MENU  ///////////////////////////////////////
	bool return1 = true;
	bool return2 = true;
	char Decision1, Decision2;
	while(return1 == true)
	{
		cout<<"\n\nSelect one of the following options"<<"\n";
		cout<<"(S) Summary statistics of the DNA database"<<"\n";
		for(int index=0;index<inputs.size();index++)
		{
			cout<<"("<<1+index<<") Analyse DNA_sequence_"<<1+index<<"\n";
		}
		cout << "(Q) Quit"<<"\n";
		cout<<">";
		cin >> Decision1;
		if(Decision1 == 'S')
		{
			cout<<"\n\nThe DNA Sequence Database holds "<<inputs.size()<<" sequences.\n\n";
			for(int b=0;b<inputs.size();b++)
			{
				cout<<"Sequence "<<b+1<<" :\n";
				cout<<"Name      "<<" :"<<dna_db[b].Name;
				cout<<"GID       "<<" : "<<dna_db[b].GID<<"\n";
				cout<<"Reference "<<" : "<<dna_db[b].Reference<<"\n";
				cout<<"\n";
			}
		}
		else if(Decision1 == 'Q')
		{
			cout<<"\n\nProgram ended.";
			return 0;
		}
		else
		{
			return2 = true;
			while (return2 == true)
			{
				///////////////// ADVANCED MENU  /////////////////
				cout<<"\n\nSelect one of the following options"<<"\n";
				cout<<"(H) Help"<<"\n";
				cout<<"(S) Summary statistics of the DNA Sequence"<<"\n";
				cout<<"(1) Analyse gap region"<<"\n";
				cout<<"(2) Analyse coded region"<<"\n";
				cout<<"(3) Analyse base pair range"<<"\n";
				cout<<"(4) Find DNA Sequence by manual input"<<"\n";
				cout<<"(5) Find DNA Sequence by file input"<<"\n";
				cout<<"(R) Return to the previous Menu"<<"\n";
				cout<<"(Q) Quit"<<"\n";
				cout<<">";
				cin >> Decision2;
				
				if(Decision2 == 'H')
				{
					dna_db[Decision1-1].Basehelp();
				}
				else if(Decision2 == 'S')
				{
					cout<<"Sequence identifiers:";
					cout<<"\n";
					cout<<"Name      "<<" :"<<dna_db[int(Decision1)-49].Name;
					cout<<"GID       "<<" : "<<dna_db[int(Decision1)-49].GID<<"\n";
					cout<<"Reference "<<" : "<<dna_db[int(Decision1)-49].Reference<<"\n";
					cout<<"\n";
					dna_db[Decision1-1].Basepairnumber(dna_db[int(Decision1)-49].sequenceid);
					dna_db[Decision1-1].GapSummary(dna_db[int(Decision1)-49].sequenceid);
				}
				else if(Decision2 == '1')
				{
					dna_db[Decision1-1].Nregionnumber(dna_db[int(Decision1)-49].sequenceid);
				}
				else if(Decision2 == '2')
				{
					dna_db[Decision1-1].Cregionnumber(dna_db[int(Decision1)-49].sequenceid);
				}
				else if(Decision2 == '3')
				{
					dna_db[Decision1-1].basepairrange(dna_db[int(Decision1)-49].sequenceid);
				}
				else if(Decision2 == '4')
				{
					dna_db[Decision1-1].manualinput(dna_db[int(Decision1)-49].sequenceid);
				}
				else if(Decision2 == '5')
				{
					string targetfile;
					cout<<"Specify the DNA sequence file you would like to find:\n>";
					cin>>targetfile;
					DNA_DB target;
					
					cout<<"Loading "<<targetfile<<"...\n";
					target.Name = target.UploadName(targetfile);
					target.GID = target.UploadGID(targetfile);
					target.Reference = target.UploadReference(targetfile);
					target.titleid = target.UploadDNATitle(targetfile);
					target.sequenceid = target.UploadDNASequence(targetfile);
					cout<<"Successful Loading of "<<targetfile<<"\n";
					
					dna_db[Decision1-1].fileinput(dna_db[int(Decision1)-49].sequenceid, target.sequenceid);
					
				}
				else if(Decision2 == 'R')
				{
					return2 = false;
				}
				else if(Decision2 == 'Q')
				{
					cout<<"\n\nProgram ended.";
					return 0;
				}
			}
		}
	}
	
	//////// RETURN 0  ///////////////////////////////////////
	return 0;
}

